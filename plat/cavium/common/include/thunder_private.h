#ifndef __THUNDER_PRIVATE_H
#define __THUNDER_PRIVATE_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-pedantic"
#include "cavm-arch.h"
#pragma GCC diagnostic pop

#include <arch_helpers.h>

#undef AP_CVMCTL_EL1
#undef AP_CVM_ACCESS_EL1
#undef AP_CVMMEMCTL0_EL1
#undef AP_CVM_ACCESS_EL2
#undef AP_CVM_ACCESS_EL3

#define AP_CVMCTL_EL1		S3_0_C11_C0_0
#define AP_CVM_ACCESS_EL1	S3_0_C11_C0_3
#define AP_CVMMEMCTL0_EL1	S3_0_C11_C0_4
#define AP_CVM_ACCESS_EL2	S3_4_C11_C0_3
#define AP_CVM_ACCESS_EL3	S3_6_C11_C0_3

DEFINE_RENAME_SYSREG_RW_FUNCS(cvmctl_el1, AP_CVMCTL_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvmmemctl0_el1, AP_CVMMEMCTL0_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el1, AP_CVM_ACCESS_EL1)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el2, AP_CVM_ACCESS_EL2)
DEFINE_RENAME_SYSREG_RW_FUNCS(cvm_access_el3, AP_CVM_ACCESS_EL3)

#define T88_PN			0xa1

#define IS_THUNDER_PASS(midr, hi, low)					\
	((((midr) >> MIDR_PN_SHIFT & MIDR_PN_MASK) == T88_PN) &&	\
	 (((midr) >> MIDR_VAR_SHIFT & MIDR_VAR_MASK) == (hi) - 1) &&	\
	 (((midr) >> MIDR_REV_SHIFT & MIDR_REV_MASK) == (low)))

/* In Mhz */
#define THUNDER_SYSCNT_FREQ	100ull

void plat_add_mmio_map(void);
void thunder_io_setup(void);
void thunder_security_setup(void);
unsigned thunder_get_node_count(void);
int thunder_dram_is_lmc_enabled(unsigned node, unsigned lmc);
uint64_t thunder_dram_size_node(unsigned node);
void thunder_errata_fixes(void);
extern void *fdt_ptr;
void thunder_gic_driver_init(void);
void thunder_gic_init(void);
unsigned int thunder_calc_core_pos(unsigned long mpidr);
void thunder_pci_init(void);
void thunder_gti_init(void);
void thunder_signal_shutdown(void);
int thunder_pwrc_setup(void);

#define THUNDER_IRQ_MASKED	(1ull << 32)

/* Secure timer IRQ */
#define THUNDER_IRQ_SEC_PHY_TIMER 0x1d

/* GPIO IRQs. ATF receives S_IRQ and then sends NS_IRQ to NS world. */
#define THUNDER_IRQ_GPIO_PWR_NS		0x20
#define THUNDER_IRQ_GPIO_PWR_S		0x21

/* TWSI Secure interrupt for BMC events */
#define THUNDER_IRQ_TWSI_BMC_S		0x22

/*
 * 1 IRQs per UAA
 * 4 UAAs (2 per node)
 * 0x2 (2) IRQs used (shared between nodes)
 */
#define THUNDER_IRQ_UAA0	0x25
#define THUNDER_IRQ_UAA1	0x26

/*
 * 4 IRQs per PEM (INTA, INTB, INTC, INTD)
 * 12 PEMs (6 per node)
 * 0x30 (48) IRQs used
 * Next spare IRQ = 0x60
 */
#define THUNDER_IRQ_PEM_BASE	0x30

/*
 * 2 IRQs per SMMU (GLOBAL, CONTEXT)
 * 8 SMMUS (4 per node)
 * 0x10 (16) IRQs used
 * Next spare IRQ = 0x74
 */
#define THUNDER_IRQ_SMMU_BASE	0x64


/*
 * watchdog GTI irqs assigned from here
 */
#define THUNDER_IRQ_GTI_WDOG	0x74

#endif
