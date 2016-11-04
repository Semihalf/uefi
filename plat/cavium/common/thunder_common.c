#include <arch.h>
#include <platform_def.h>
#include <xlat_tables.h>
#include <thunder_private.h>
#include <thunder_common.h>

extern void plat_add_mmio_node(unsigned long node);

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

void add_map_record(unsigned long addr, unsigned long size, mmap_attr_t attr)
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
	uint64_t cvmctl_el1;
	uint64_t cvmmemctl0_el1;
	uint32_t midr;

	__asm__ __volatile__ ("mrs %0, s3_0_c0_c0_0" : "=r" (midr));
	__asm__ __volatile__ ("mrs %0, s3_0_c11_c0_0" : "=r" (cvmctl_el1));
	__asm__ __volatile__ ("mrs %0, s3_0_c11_c0_4" : "=r" (cvmmemctl0_el1));

	/* All other chips we want to enable CAS/CASP and enable v8.1 support. */
	unset_bit(cvmctl_el1, 36);  /* Enable CAS */
	unset_bit(cvmctl_el1, 37);  /* Enable CASP */
	set_bit(cvmctl_el1, 33);    /* Enable v8.1 */

	/* Fix up defaults from the BDK which is broken and violates the ARM ARM. */
	unset_bit (cvmmemctl0_el1, 17); /* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit (cvmmemctl0_el1, 18); /* Set Write-buffer timeout for NSH entries to 218 cycles. */

	if (MIDR_PARTNUM (midr) == T81PARTNUM) {
		set_bit (cvmctl_el1, 40);
		set_bit (cvmctl_el1, 41);
		set_bit (cvmctl_el1, 42);
		set_bit (cvmctl_el1, 43);
	}

	/* Fix up defaults from the BDK which is broken and violates the ARM ARM. */
	unset_bit (cvmmemctl0_el1, 17); /* Don't reset timer on merge as that violates the ARM ARM. */
	unset_bit (cvmmemctl0_el1, 18); /* Set Write-buffer timeout for NSH entries to 218 cycles. */
	__asm__ __volatile__("msr s3_0_c11_c0_0, %0\n" : : "r" (cvmctl_el1));

	__asm__ __volatile__("msr s3_0_c11_c0_4, %0\n" : : "r" (cvmmemctl0_el1));

	/* Allow CVM CACHE instructions from EL1/EL2 */
	write_cvm_access_el1(read_cvm_access_el1() & ~(1 << 8));
	write_cvm_access_el2(read_cvm_access_el2() & ~(1 << 8));
	write_cvm_access_el3(read_cvm_access_el3() & ~(1 << 8));
}
