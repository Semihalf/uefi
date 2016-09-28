#include <arch.h>
#include <platform_def.h>
#include <thunder_private.h>

#undef GICD_SETSPI_NSR
#undef GICD_CLRSPI_NSR
#undef GICD_SETSPI_SR
#undef GICD_CLRSPI_SR
#undef GICD_TYPER
#undef GICD_IIDR

#include <gic_common.h>
#include <gicv3.h>
#include <platform.h>
#include "../../../drivers/arm/gic/v3/gicv3_private.h"

/* The GICv3 driver only needs to be initialized in EL3 */
uintptr_t rdistif_base_addrs[PLATFORM_CORE_COUNT];

/* Array of Group1 secure interrupts to be configured by the gic driver */
static const unsigned int g1s_interrupt_array[] = {
	THUNDER_IRQ_SEC_PHY_TIMER,
};

/* Array of Group0 interrupts to be configured by the gic driver */
static const unsigned int g0_interrupt_array[] = {
//	PLAT_ARM_G0_IRQS
	THUNDER_IRQ_GPIO_PWR_S,
	THUNDER_IRQ_GTI_WDOG,
};

static gicv3_driver_data_t thunder_gic_data = {
	/* gicd_base and gicr_base are setup later */
	.g0_interrupt_num = ARRAY_SIZE(g0_interrupt_array),
	.g1s_interrupt_num = ARRAY_SIZE(g1s_interrupt_array),
	.g0_interrupt_array = g0_interrupt_array,
	.g1s_interrupt_array = g1s_interrupt_array,
	.rdistif_num = PLATFORM_CORE_COUNT,
	.rdistif_base_addrs = rdistif_base_addrs,
	.mpidr_to_core_pos = thunder_calc_core_pos,
};

void thunder_gic_driver_init(void)
{
	/*
	 * The GICv3 driver is initialized in EL3 and does not need
	 * to be initialized again in SEL1. This is because the S-EL1
	 * can use GIC system registers to manage interrupts and does
	 * not need GIC interface base addresses to be configured.
	 */
#if IMAGE_BL31
	unsigned node, node_count;

	node_count = thunder_get_node_count();

	for (node = node_count - 1; node < node_count; node --) {
		union cavm_gic_cfg_ctlr cfg_ctlr;

		cfg_ctlr.u = 0;
		cfg_ctlr.s.om = 2; /* Multi-node, Single-root */
		cfg_ctlr.s.root_dist = (node == 0) ? 1 : 0;
		CSR_WRITE_PA(node, CAVM_GIC_CFG_CTLR, cfg_ctlr.u);
	}

	thunder_gic_data.gicd_base = CSR_PA(0, CAVM_GIC_PF_BAR0);
	thunder_gic_data.gicr_base = CSR_PA(0, CAVM_GIC_PF_BAR4);
	gicv3_driver_init(&thunder_gic_data);

	/* Init GIC redistributors for other nodes */

	for (node = 1; node < node_count; node++)
		gicv3_rdistif_base_addrs_probe(
				thunder_gic_data.rdistif_base_addrs,
				thunder_gic_data.rdistif_num,
				CSR_PA(node, CAVM_GIC_PF_BAR4),
				thunder_gic_data.mpidr_to_core_pos);
#endif
}

/******************************************************************************
 * ARM common helper to initialize the GIC. Only invoked by BL31
 *****************************************************************************/
void thunder_gic_init(void)
{
	gicv3_distif_init();
	gicv3_rdistif_init(plat_my_core_pos());
	gicv3_cpuif_enable(plat_my_core_pos());
}

