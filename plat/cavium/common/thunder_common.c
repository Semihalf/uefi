#include <arch.h>
#include <platform_def.h>
#include <xlat_tables.h>
#include <thunder_private.h>

void *fdt_ptr = (void *)~0;

unsigned long plat_get_ns_image_entrypoint(void)
{
	return NS_IMAGE_BASE;
}


uint64_t plat_get_syscnt_freq(void)
{
	return THUNDER_SYSCNT_FREQ * 1000 * 1000;
}

#define ROUND_DOWN(val, align)	((val) / (align) * (align))
#define ROUND_UP(val, align)	(((val) + (align) - 1) / (align) * (align))

static void add_map_record(unsigned long addr, unsigned long size, mmap_attr_t attr)
{
	/* Round up to sensible boundry */
	mmap_add_region(ROUND_DOWN(addr, 2*1024*1024),
			ROUND_DOWN(addr, 2*1024*1024),
			ROUND_UP(size, 2*1024*1024),
			attr);
}

static void plat_add_mmio_common(void)
{
	unsigned long attr;

	/* Shared Memory */
	/* Do not use add_map_record here, it will round size up */
	attr = MT_MEMORY | MT_RO | MT_SECURE;

	mmap_add_region((unsigned long)fdt_ptr, (unsigned long)fdt_ptr,
			TZDRAM_SIZE - (unsigned long)fdt_ptr,
			attr);

	attr = MT_MEMORY | MT_RW | MT_NS;
	mmap_add_region(NS_IMAGE_BASE, NS_IMAGE_BASE, NS_IMAGE_MAX_SIZE, attr);
}

static void plat_add_mmio_node(unsigned long node)
{
	unsigned long attr;
	int i;

	attr = MT_DEVICE | MT_RW | MT_SECURE;
	add_map_record(CSR_PA(node, CAVM_RST_PF_BAR0), CAVM_RST_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_L2C_PF_BAR0), CAVM_L2C_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_BOOT_PF_BAR0), CAVM_MIO_BOOT_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MIO_EMM_PF_BAR0), CAVM_MIO_EMM_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_MPI_PF_BAR0), CAVM_MPI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR0), CAVM_GIC_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR2), CAVM_GIC_PF_BAR2_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GIC_PF_BAR4), CAVM_GIC_PF_BAR4_SIZE, attr);
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_SMMUX_PF_BAR0(i)), CAVM_SMMUX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_SMMU_BAR_E_SMMUX_PF_BAR4(i)),
CAVM_SMMU_BAR_E_SMMUX_PF_BAR4_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR0), CAVM_GTI_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GTI_PF_BAR4), CAVM_GTI_PF_BAR4_SIZE, attr);

	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_LMCX_PF_BAR0(i)), CAVM_LMCX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 6; i++)
		add_map_record(CSR_PA(node, CAVM_MIO_TWSX_PF_BAR0(i)), CAVM_MIO_TWSX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 6; i++)
		add_map_record(CSR_PA(node, CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4(i)), CAVM_MIO_TWS_BAR_E_MIO_TWSX_PF_BAR4_SIZE, attr);
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_L2C_CBCX_PF_BAR0(i)), CAVM_L2C_CBCX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_L2C_MCIX_PF_BAR0(i)), CAVM_L2C_MCIX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 8; i++)
		add_map_record(CSR_PA(node, CAVM_L2C_TADX_PF_BAR0(i)), CAVM_L2C_TADX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 6; i++)
		add_map_record(CSR_PA(node, CAVM_PEM_BAR_E_PEMX_PF_BAR4(i)),
CAVM_PEM_BAR_E_PEMX_PF_BAR4_SIZE, attr);
	for (i = 0; i < 13; i++)
		add_map_record(CSR_PA(node, CAVM_GSERX_PF_BAR0(i)), CAVM_GSERX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_BGXX_PF_BAR0(i)), CAVM_BGXX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_DAP_PF_BAR0), CAVM_DAP_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_CIM_CSR_BASE), CAVM_CIM_CSR_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_OCX_PF_BAR0), CAVM_OCX_PF_BAR0_SIZE, attr);

	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR0), CAVM_GPIO_PF_BAR0_SIZE, attr);
	add_map_record(CSR_PA(node, CAVM_GPIO_PF_BAR4), CAVM_GPIO_PF_BAR4_SIZE, attr);

	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_UAAX_PF_BAR0(i)), CAVM_UAAX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_UAA_BAR_E_UAAX_PF_BAR4_CN81XX(i)),
CAVM_UAA_BAR_E_UAAX_PF_BAR4_CN81XX_SIZE, attr);
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_ECAM_BAR_E_ECAMX_PF_BAR0(i)),
CAVM_ECAM_BAR_E_ECAMX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 4; i++)
		add_map_record(CSR_PA(node, CAVM_ECAMX_PF_BAR2(i)), CAVM_ECAMX_PF_BAR2_SIZE, attr);
	for (i = 0; i < 6; i++)
		add_map_record(CSR_PA(node, CAVM_PEMX_PF_BAR0(i)), CAVM_PEMX_PF_BAR0_SIZE, attr);
	for (i = 0; i < 2; i++)
		add_map_record(CSR_PA(node, CAVM_SLIX_PF_BAR0(i)), CAVM_SLIX_PF_BAR0_SIZE, attr);
}

unsigned thunder_get_node_count(void)
{
	unsigned long node = cavm_numa_local();
	union cavm_l2c_oci_ctl l2c_oci_ctl;

	l2c_oci_ctl.u = CSR_READ_PA(node, CAVM_L2C_OCI_CTL);

	return (l2c_oci_ctl.s.enaoci > 1) ? 2 : 1;
}

/*******************************************************************************
 * Setup secondary CPU JUMP address from RESET
 ******************************************************************************/

void  set_secondary_cpu_jump_addr(unsigned int bl1_base)
{
       CSR_WRITE_PA(0, CAVM_MIO_BOOT_AP_JUMP, bl1_base);
}

void plat_add_mmio_map()
{
	unsigned long node, node_count;

	plat_add_mmio_common();

	node_count = thunder_get_node_count();
	for (node = 0; node < node_count; node++)
		plat_add_mmio_node(node);
}

#define set_bit(reg, bit) reg |= (1ULL<<(bit))
#define unset_bit(reg, bit) reg &= ~(1ULL<<(bit))

void thunder_errata_fixes(void)
{
	uint64_t cvmctl_el1, cvmmemctl0_el1;
	uint64_t midr;

	midr = read_midr();
	cvmctl_el1 = read_cvmctl_el1();
	cvmmemctl0_el1 = read_cvmmemctl0_el1();

	if (IS_THUNDER_PASS(midr, 1, 0) || IS_THUNDER_PASS(midr, 1, 1)) {
		/* Disable CAS and CASP which disables LSE */
		set_bit(cvmctl_el1, 36);  /* Disable CAS */
		set_bit(cvmctl_el1, 37);  /* Disable CASP */

		set_bit(cvmctl_el1, 34);    /* Force WFE to nop */
		unset_bit(cvmctl_el1, 33);  /* Disable v8.1 */
	} else {
		/*  All other chips we want to enable CAS/CASP and enable v8.1 support. */
		unset_bit(cvmctl_el1, 36);  /* Enable CAS */
		unset_bit(cvmctl_el1, 37);  /* Enable CASP */
		set_bit(cvmctl_el1, 33);    /* Enable v8.1 */
	}

	if (IS_THUNDER_PASS(midr, 1, 0)) {
		set_bit(cvmctl_el1, 5); /* force issue clock */
	}

	if (IS_THUNDER_PASS(midr, 2, 0)) {
		set_bit (cvmmemctl0_el1, 55); /* Force DMB to wait for flushed write-buffer entries to be ACKed */
	}

	if (IS_THUNDER_PASS(midr, 1, 0) || IS_THUNDER_PASS(midr, 1, 1) || IS_THUNDER_PASS(midr, 2, 0)) {
		set_bit (cvmctl_el1, 32);	/* Enable isb hazard so it always flushes the pipeline. */
	}

	/* Fix up defaults from the BDK which is broken and violates the ARM ARM. */
	unset_bit (cvmmemctl0_el1, 17); /* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit (cvmmemctl0_el1, 18); /* Set Write-buffer timeout for NSH entries to 218 cycles. */

	write_cvmctl_el1(cvmctl_el1);
	write_cvmmemctl0_el1(cvmmemctl0_el1);
}
