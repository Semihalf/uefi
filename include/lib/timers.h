#ifndef __TIMERS_H__
#define __TIMERS_H__

typedef enum {
	TM_ONE_SHOT,
	TM_PERIODIC
} timer_kind_t;

typedef int (*timer_callback_t)(int hd);

typedef struct _timer_t {
	int is_created;
	int is_started;
	uint64_t period; // in ticks
	timer_kind_t type;
	timer_callback_t cb;
} timer_data;

int timers_init();

int timer_stop(int hd);
int timer_set_period(int hd, uint32_t period);
int timer_start(int hd);
int timer_create(timer_kind_t type, uint32_t period, timer_callback_t cb);

#endif

