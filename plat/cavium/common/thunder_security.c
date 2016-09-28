#include <arch.h>
#include <platform_def.h>
#include <thunder_private.h>
#include <stdio.h>
#include <debug.h>

void thunder_security_setup(void)
{
	int region;
	unsigned node;
	unsigned node_count = thunder_get_node_count();
	union cavm_l2c_asc_regionx_attr l2c_asc_attr;

	uint64_t dram_size;

	for(node = 0; node < node_count; node++) {
		/* Mark the region from 0x0 to 1MB as secure, Boot ROM has done this for
		 * region 1MB to 2MB
		 */
		region = 0;
		CSR_WRITE_PA(node, CAVM_L2C_ASC_REGIONX_START(region), TZDRAM_BASE);
		CSR_WRITE_PA(node, CAVM_L2C_ASC_REGIONX_END(region), TZDRAM_BASE + TZDRAM_SIZE - 1);
		l2c_asc_attr.u = CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_ATTR(region));
		l2c_asc_attr.s.s_en = 1;
		l2c_asc_attr.s.ns_en = 0;
		CSR_WRITE_PA(node, CAVM_L2C_ASC_REGIONX_ATTR(region), l2c_asc_attr.u );


		WARN("Mark memory region %d:: %lx to %lx as secure (%lx)\n",region,
			CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_START(region)),
			CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_END(region)) + 0xfffff,
			CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_ATTR(region)));

		dram_size = thunder_dram_size_node(node);

		/* Mark the rest of DRAM as non-secure */
		region = 1;
		CSR_WRITE_PA(node, CAVM_L2C_ASC_REGIONX_START(region), TZDRAM_BASE + TZDRAM_SIZE);
		CSR_WRITE_PA(node, CAVM_L2C_ASC_REGIONX_END(region), dram_size - 1);
		l2c_asc_attr.u = CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_ATTR(region));
		l2c_asc_attr.s.s_en = 0;
		l2c_asc_attr.s.ns_en = 1;
		CSR_WRITE_PA(node, CAVM_L2C_ASC_REGIONX_ATTR(region), l2c_asc_attr.u );


		WARN("Mark memory region %d:: %lx to %lx as non-secure (%lx)\n",region,
			CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_START(region)),
			CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_END(region)) + 0xfffff,
			CSR_READ_PA(node, CAVM_L2C_ASC_REGIONX_ATTR(region)));
	}
}
