#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <spinlock.h>
#include <timers.h>
#include <hw_timers.h>

#define TM_MAX_TIMERS 10

#ifndef DEBUG_TIMERS
#define DEBUG_TIMERS 0
#endif

#if DEBUG_TIMERS == 1
#define debug_printf(...) printf (__VA_ARGS__)
#else
#define debug_printf(...)
#endif

typedef struct _timer_t {
	int is_created;
	int is_started;
	uint32_t period; // in Ms
	uint32_t fire_in;
	timer_kind_t type;
	timer_callback_t cb;
} timer_t;

/* array of timers */
timer_t timers[TM_MAX_TIMERS];

/* HW timer period in ticks */
uint64_t hw_timer_period = UINT64_MAX;

/* global spinlock to protect timer structures */
spinlock_t tm_lock;

static int num_started_timers = 0;

void hw_timer_set_period(int timer_id, uint32_t ticks) {
	hw_timer_period = ticks;
	plat_timer_set_period(timer_id, ticks);
}

static void hw_timer_isr(void)
{
	uint64_t min_time = UINT64_MAX;
	debug_printf("timer ISR:\n");
	spin_lock(&tm_lock);
	for(int i = 0; i < TM_MAX_TIMERS;i ++) {
		if(timers[i].is_started) {
			if(timers[i].fire_in <= hw_timer_period) {
				// Disable before calling callback function, 
				// timer may be reenabled
				if(timers[i].type == TM_ONE_SHOT) {
					timers[i].is_started = 0;
					num_started_timers--;
					if(num_started_timers == 0) {
						plat_timer_enable(TIMER_PER_CORE_WD, 0);
					}
				}

				spin_unlock(&tm_lock);
				timers[i].cb(i);
				spin_lock(&tm_lock);
				// timer can be modified in callback, but only set_timer_period
				// and timer_start are allowed, even delete will not hirt
				// if a timer is deleted or stopped and it has minimal
				// time... we just get extra ISR
				timers[i].fire_in = timers[i].period;
			} else {
				timers[i].fire_in -= hw_timer_period;
			}

			/* calculate time for the next ISR */
			if( timers[i].is_started && (min_time > timers[i].fire_in )) {
					min_time = timers[i].fire_in;
			}
		}
	}
	spin_unlock(&tm_lock);
	if(min_time != UINT64_MAX) {
		hw_timer_set_period(TIMER_PER_CORE_WD, min_time);
	}
}

/*
 * This function creates a timer with specified period in Ms and kind 
 * defined by timer_kind_t. It reruns timer handle whcih can be passed 
 * to other timer related functions. Timer is not started after this 
 * function returs
 */
int timer_create(timer_kind_t type, uint32_t period, timer_callback_t cb)
{
	assert(cb != NULL);

	debug_printf("TIMER: timer_create() type=%d period=%d\n", type, period);

	spin_lock(&tm_lock);
	for(int i = 0; i < TM_MAX_TIMERS; i++) {
		if (timers[i].is_created)
			continue;
		timers[i].is_created = 1;
		timers[i].is_started = 0;
		timers[i].period = plat_timer_ms_to_ticks(TIMER_PER_CORE_WD, period);
		timers[i].type = type;
		timers[i].cb =cb;
		debug_printf("TIMER: timer_create() hd=%d\n", i);
		spin_unlock(&tm_lock);
		return i;
	}
	printf("TIMER: ERROR: No more handles available\n");
	spin_unlock(&tm_lock);
	return -1;
}

int timer_start(int hd)
{
	assert(hd >= 0 && hd < TM_MAX_TIMERS);
	assert(timers[hd].is_started == 0);

	debug_printf("TIMER: timer_start(%d)\n", hd);
	spin_lock(&tm_lock);

	if (timers[hd].is_created == 0) {
		spin_unlock(&tm_lock);
		return -1;
	}

	timers[hd].is_started = 1;
	num_started_timers++;

	/* need shorter timeout or HW timer is not running at all */
	if (plat_timer_get_remainig(TIMER_PER_CORE_WD) > timers[hd].period) {
		timers[hd].fire_in = timers[hd].period;
		hw_timer_set_period(TIMER_PER_CORE_WD, timers[hd].period);
	} else {
		timers[hd].fire_in = timers[hd].period - plat_timer_get_remainig(TIMER_PER_CORE_WD);
	}
	if (num_started_timers == 1) {
		plat_timer_enable(TIMER_PER_CORE_WD, 1);
	}
	spin_unlock(&tm_lock);

	return 0;
}

int timer_stop(int hd)
{
	assert(hd >= 0 && hd < TM_MAX_TIMERS);
	spin_lock(&tm_lock);
	if(timers[hd].is_started) {
		timers[hd].is_started = 0;
		num_started_timers--;
		if(num_started_timers == 0) {
			plat_timer_enable(TIMER_PER_CORE_WD, 0);
		}
		spin_unlock(&tm_lock);
		return 0;
	}
	spin_unlock(&tm_lock);
	return -1;
}

/* set timer interval in Ms */
int timer_set_period(int hd, uint32_t period) {
	assert(hd >= 0 && hd < TM_MAX_TIMERS);

	spin_lock(&tm_lock);
	debug_printf("TIMER: timer_set_period(%d, %d ms)\n", hd, period);

	if(!timers[hd].is_created) {
		spin_unlock(&tm_lock);
		return -1;
	}

	//can modify only stopped one-shot timer
	if(!timers[hd].is_started && timers[hd].type == TM_ONE_SHOT) {
	timers[hd].period = plat_timer_ms_to_ticks(TIMER_PER_CORE_WD, period);
	} else {
		spin_unlock(&tm_lock);
		return -1;
	}

	spin_unlock(&tm_lock);
	return 0;
}

int timers_init()
{
  debug_printf("TIMER: timers_init()\n");
  plat_timers_init();
  return plat_timer_register_irq(TIMER_PER_CORE_WD, hw_timer_isr);
}

