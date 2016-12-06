#include <hw_timers.h>
//#include "../../drivers/arm/gic_v3.h"
#include "thunder_io.h"
#include "../bl31/interrupt_mgmt.h"
#include "../common/bl_common.h"
#include <stdio.h>

#ifndef DEBUG_TIMERS
#define DEBUG_TIMERS 1
#endif

#if DEBUG_TIMERS == 1
#define debug_printf(...) printf (__VA_ARGS__)
#else
#define debug_printf(...)
#endif

#define THUNDER_IRQ_SEC_PHY_TIMER 0x1d

static uint64_t timer_cnt; /* timeout to be programmed on next interrupt */

#define PLL_REF_CLK		50000000	/* 50 MHz */
static int ref_clock;
static hw_timer_isr_t timer_isr = NULL;

uint64_t gti_irq_handler(uint32_t id, uint32_t flags, void *cookie) {
#ifdef GTI_IRQ_DEBUG
  uint64_t cval1, cval2;

  __asm __volatile__("mrs %0, cntpct_el0" : "=r" (cval1));
#endif

	/* Clear interrupt */
	
	printf ("Interrupt handling\n");
  /* Clear interrupt */
//  CSR_WRITE(gti_base, GTI_CWD_INT, (1ull << cpu));
//  CSR_WRITE(gicd_base, GICD_CLRSPI_SR, GTI_IRQ0);

  /* call registered handler */
  if (timer_isr != NULL) {
    timer_isr();
  }

  //program new value. no need to poke here
//  CSR_WRITE(gti_base, GTI_CWD_WDOGX(cpu), gti_wdog.u);

#ifdef GTI_IRQ_DEBUG
  __asm __volatile__("mrs %0, cntpct_el0" : "=r" (cval2));
  printf("%s: COUNT diff  %lld\n", __func__, cval2 - cval1);
#endif

  return 0;
}

int plat_timer_register_irq(int timer_id, hw_timer_isr_t isr) {
  uint32_t flags = 0;
  int rc = 0;

  switch (timer_id) {
  case TIMER_PER_CORE_WD:
    {
      timer_isr = isr;

      set_interrupt_rm_flag(flags, SECURE);
      rc = register_interrupt_handler(INTR_TYPE_EL3, THUNDER_IRQ_SEC_PHY_TIMER,
                                      gti_irq_handler);
      if (rc) {
        printf("err %d while registering GTI secure interrupt handler;\n", rc);
        return rc;
      }

    }
    break;
  default:
    printf("timers: ERROR: timer with ID %d is not supported\n", timer_id);
    rc = -1;
    break;
  }
  return rc;
}

void plat_timer_enable(int timer_id, int enable) {
  debug_printf("plat_timer_enable(%d, %d)\n", timer_id, enable);

	uint64_t ctl;

	__asm__ volatile ("mrs %0, cntps_ctl_el1" : "=r" (ctl));

	if (enable) {
		/* set new period */
		__asm__ volatile ("msr cntps_cval_el1, %0" : "=r" (timer_cnt));

		/* enable interrupt */
		ctl |= 0x3;
	} else {
		/* disable interrupt */
		ctl &= ~(1 << 0);
  	}

	/* Write ctl value */
	__asm__ volatile ("msr cntps_ctl_el1, %0" : "=r" (ctl));
	
}

uint64_t plat_timer_ms_to_ticks(int timer_id, uint32_t time) {
	return(ref_clock / 1000) * time;
}

uint64_t plat_timer_get_remainig(int timer_id) {
	uint64_t val;
	__asm__ volatile("mrs %0, cntps_tval_el1" : "=r" (val)); 
	return val;
}


void plat_timer_set_period(int timer_id, uint64_t period) {
  debug_printf("plat_timer_set_period(%d, %lu)\n", timer_id, period);

  switch (timer_id) {
  case TIMER_PER_CORE_WD:
    {
      /* program new period. get current DW settings first */
      timer_cnt = ((period >> 8) & 0xFFFF) + 1;
      timer_cnt = timer_cnt << 8;

      /* set new period */
      __asm__ volatile("msr cntps_cval_el1, %0" : "=r" (timer_cnt));
    }
    break;
  default:
    printf("timers: ERROR: timer with ID %d is not supported\n", timer_id);
    break;
  }
}

void plat_timers_init() {
  /* read reference clock once */
//  rst_boot_t rst_boot;
//  int node = cavm_node_id();
//  int cpu = cavm_core_id();
//
//  gti_base = pa_to_va(CSR_PA(node, GTI_PF_BAR0));
//  gicd_base = pa_to_va(CSR_PA(node, GIC_PF_BAR0));
//
//  /* pre-calculate reference clock and tick count for timer */
//  u64 rst_base = pa_to_va(CSR_PA(node, RST_PF_BAR0));
//  rst_boot.u = CSR_READ(rst_base, RST_BOOT);
//  ref_clock = rst_boot.s.pnr_mul * PLL_REF_CLK;
//  /* WD ticks per second */
//  ref_clock = ref_clock / 1024;
  plat_timer_enable(TIMER_PER_CORE_WD, 0);
  /* initialize the structure. make sure mode and state are set correctly */
//  gti_wdog.u = CSR_READ(gti_base, GTI_CWD_WDOGX(cpu));
//  gti_wdog.s.state = 0;
//  gti_wdog.s.mode = 1;
}
