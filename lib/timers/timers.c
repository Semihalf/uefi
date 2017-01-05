#include <stdint.h>
#include <assert.h>
#include <debug.h>
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

/* array of timers */
timer_data timers[TM_MAX_TIMERS];

/* number of timers registerd by platform */
unsigned int timer_cnt;

/* global spinlock to protect timer structures */
spinlock_t tm_lock;

static void hw_timer_isr(int id)
{
	debug_printf("timer ISR:\n");

	spin_lock(&tm_lock);

	plat_timer_enable(id, 0);

	/*
	 * Disable before calling callback function, 
	 * because timer may be reenabled
	 */
	if(timers[id].type == TM_ONE_SHOT) {
		timers[id].is_started = 0;
	}

	spin_unlock(&tm_lock);

	/* call registered function */
	timers[id].cb(id);

	/* set new period */
	if(timers[id].type == TM_PERIODIC) {
		plat_timer_set_period(id, timers[id].period);
	}

	/* reenable timer */
	if (timers[id].is_started == 1)
		plat_timer_enable(id, 1);
}

/*
 * This function creates a timer with specified period in ms and kind 
 * defined by timer_kind_t. It returns timer handle which can be passed 
 * to other timer related functions. Timer is not started after this 
 * function returns, it's necessary to call timer_start explicitly.
 */
int timer_create(timer_kind_t type, uint32_t period, timer_callback_t cb)
{
	int i;

	assert(cb != NULL);

	debug_printf("TIMER: %s type=%d period=%d\n", __func__, type, period);

	spin_lock(&tm_lock);

	for(i = 0; i < timer_cnt; i++) {
		if (timers[i].is_created)
			continue;
		timers[i].is_created = 1;
		timers[i].is_started = 0;
		timers[i].period = plat_timer_ms_to_ticks(i, period);
		timers[i].type = type;
		timers[i].cb = cb;
		plat_timer_register_irq(i, hw_timer_isr);

		debug_printf("TIMER: %s hd=%d\n", __func__, i);

		spin_unlock(&tm_lock);
		return i;
	}
	ERROR("TIMER: No timers available!\n");

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
		WARN("TIMER: timer with hd =%d isn't created!", hd);
		return -1;
	}

	timers[hd].is_started = 1;

	/* Set calculated period */
	plat_timer_set_period(hd, timers[hd].period);

	/* Enable timer */
	plat_timer_enable(hd, 1);

	spin_unlock(&tm_lock);

	return 0;
}

int timer_stop(int hd)
{
	assert(hd >= 0 && hd < TM_MAX_TIMERS);

	spin_lock(&tm_lock);

	if(timers[hd].is_started) {
		timers[hd].is_started = 0;
		plat_timer_enable(hd, 0);
		spin_unlock(&tm_lock);
		return 0;
	}

	spin_unlock(&tm_lock);
	return -1;
}

/* set timer interval in ms */
int timer_set_period(int hd, uint32_t period) {
	assert(hd >= 0 && hd < TM_MAX_TIMERS);

	spin_lock(&tm_lock);
	debug_printf("TIMER: timer_set_period(%d, %d ms)\n", hd, period);

	if(!timers[hd].is_created) {
		spin_unlock(&tm_lock);
		return -1;
	}

	/* can modify only stopped one-shot timer */
	if (!timers[hd].is_started && timers[hd].type == TM_ONE_SHOT) {
		timers[hd].period = plat_timer_ms_to_ticks(hd, period);
	} else {
		spin_unlock(&tm_lock);
		return -1;
	}

	spin_unlock(&tm_lock);
	return 0;
}

/*
 * Perform basic initialization of hardware and gather
 * number of available HW timers on platform
 */
int timers_init()
{
	timer_cnt = plat_timers_init();
	if (timer_cnt == 0) {
		WARN("No timers available on platform!\n");
		return -1;
	}
	if (timer_cnt > TM_MAX_TIMERS)
		timer_cnt = TM_MAX_TIMERS;

	debug_printf("TIMER: %s registered %d timers\n", __func__, timer_cnt);

	return 0;
}

