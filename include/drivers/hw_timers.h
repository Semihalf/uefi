#ifndef __HW_TIMERS_H__
#define __HW_TIMERS_H__

#include <stdint.h>

#define TIMER_SECURE_WD 0
#define TIMER_PER_CORE_WD 1

typedef void (*hw_timer_isr_t)(void);

int timers_init(void);
void plat_timers_init();
int plat_timer_register_irq(int timer_id, hw_timer_isr_t isr);
void plat_timer_enable(int timer_id, int enable);
void plat_timer_set_period(int timer_id, uint64_t period);
uint64_t plat_timer_ms_to_ticks(int timer_id, uint32_t time);
uint64_t plat_timer_get_remainig(int timer_id);


#endif
