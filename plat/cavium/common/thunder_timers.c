#include <bl_common.h>
#include <hw_timers.h>
#include <interrupt_mgmt.h>
#include <stdio.h>
#include <thunder_private.h>

#ifndef DEBUG_TIMERS
#define DEBUG_TIMERS 0
#endif

#if DEBUG_TIMERS == 1
#define debug_printf(...) printf (__VA_ARGS__)
#else
#define debug_printf(...)
#endif

static hw_timer_isr_t timer_isr = NULL;

/* Secure architectural physical counter methods */

static void cntps_enable(int enable)
{
	volatile uint32_t ctl;

	__asm__ volatile ("mrs %0, cntps_ctl_el1" : "=r" (ctl));

	if (enable) {
		/* enable timer with masked interrupts */
		ctl = 0x1;
	} else {
		/* disable timer */
		ctl &= ~(1 << 0);
	}

	/* write ctl value */
	__asm__ volatile ("msr cntps_ctl_el1, %0" : "=r" (ctl));
}

void cntps_set_period(volatile uint64_t period)
{
	volatile uint64_t timer_status;

	/* read current timer counter value */
	__asm__ volatile ("mrs %0, cntpct_el0" : "=r" (timer_status));

	period += timer_status;

	__asm__ volatile ("msr cntps_cval_el1, %0" : "=r" (period));
}

uint64_t cntps_ms_to_ticks(uint32_t time)
{
	uint32_t cnt_freq; /* in Hz */

	/* gather counter frequency */
	__asm__ volatile("mrs %0, cntfrq_el0" : "=r" (cnt_freq));

	return((cnt_freq / 1000) * time);
}

/* Platform timers API */

uint64_t plat_timer_irq_handler(uint32_t id, uint32_t flags, void *cookie)
{
	int timer_id;

#ifdef DEBUG_TIMERS
	uint64_t cval1, cval2;

	__asm __volatile__("mrs %0, cntpct_el0" : "=r" (cval1));
#endif

	/* map GIC IRQ ID to proper timer ID */
	switch (id) {
	case THUNDER_IRQ_SEC_PHY_TIMER:
		timer_id = ARCH_SECURE_TIMER_ID;
		break;
	default:
		printf("Unknown timer IRQ ID!\n");
		return 0;
	}

	/* call registered handler */
	if (timer_isr != NULL)
		timer_isr(timer_id);

#ifdef DEBUG_TIMERS
	__asm __volatile__("mrs %0, cntpct_el0" : "=r" (cval2));
	printf("%s: COUNT diff  %ld\n", __func__, cval2 - cval1);
#endif

	return 0;
}

int plat_timer_register_irq(int timer_id, hw_timer_isr_t isr)
{
	uint32_t flags = 0;
	int rc = 0;

	switch (timer_id) {
	case ARCH_SECURE_TIMER_ID:
		timer_isr = isr;

		set_interrupt_rm_flag(flags, SECURE);
		rc = register_interrupt_handler(INTR_TYPE_EL3,
				THUNDER_IRQ_SEC_PHY_TIMER,
				plat_timer_irq_handler);
		if (rc) {
			printf("err %d while registering ARCH_PHYS_TIMER secure"
			       "interrupt handler\n", rc);
		return rc;
		}
		break;
	default:
		printf("timers: ERROR: timer with ID %d is not supported\n",
		       timer_id);
		rc = -1;
		break;
	}

	return rc;
}

void plat_timer_enable(int timer_id, int enable)
{
	debug_printf("%s(%d, %d)\n", __func__, timer_id, enable);

	switch (timer_id) {
	case ARCH_SECURE_TIMER_ID:
		cntps_enable(enable);
		break;
	default:
		printf("timers: ERROR: timer with ID %d is not supported\n",
		       timer_id);
		return;
	}
}

uint64_t plat_timer_ms_to_ticks(int timer_id, uint32_t time)
{
	switch (timer_id) {
	case ARCH_SECURE_TIMER_ID:
		return cntps_ms_to_ticks(time);
	default:
		printf("timers: ERROR: timer with ID %d is not supported\n",
		       timer_id);
		return -1;
	}
}

void plat_timer_set_period(int timer_id, volatile uint64_t period)
{
	switch (timer_id) {
	case ARCH_SECURE_TIMER_ID:
		cntps_set_period(period);
		break;
	default:
		printf("timers: ERROR: timer with ID %d is not supported\n",
		       timer_id);
		break;
	}
}

int plat_timers_init()
{
	plat_timer_enable(ARCH_SECURE_TIMER_ID, 0);

	/* return number of available hw counters */
	return 1;
}
