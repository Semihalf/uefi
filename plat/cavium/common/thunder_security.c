#include <arch.h>
#include <platform_def.h>
#include <thunder_private.h>
#include <stdio.h>
#include <debug.h>

struct l2c_region {
	unsigned int  node;
	unsigned int  number;
	unsigned long start;
	unsigned long end;
	unsigned int  secure;
};

struct l2c_region l2c_map [] = {
	{
		.node    = 0,
		.number  = 0,
		.start   = TZDRAM_BASE,
		.end     = TZDRAM_BASE + TZDRAM_SIZE,
		.secure  = 1,
	},
	{
		.node    = 0,
		.number  = 1,
		.start   = TZDRAM_BASE + TZDRAM_SIZE,
		.end     = ~0UL,
		.secure  = 0,
	},
	{
		.node    = 1,
		.number  = 0,
		.start   = 0,
		.end     = ~0UL,
		.secure  = 0,
	},
	{
		.node    = ~0U,
	},
};

void thunder_security_setup(void)
{
	unsigned node_count = thunder_get_node_count();
	union cavm_l2c_asc_regionx_attr l2c_asc_attr;
	struct l2c_region *region = l2c_map;

	uint64_t dram_end;

	while (region->node < node_count) {
		dram_end = thunder_dram_size_node(region->node) - 1;

		if (region->end > dram_end)
			region->end = dram_end;

		CSR_WRITE_PA(region->node, CAVM_L2C_ASC_REGIONX_START(region->number), region->start);
		CSR_WRITE_PA(region->node, CAVM_L2C_ASC_REGIONX_END(region->number), region->end);

		l2c_asc_attr.u = CSR_READ_PA(region->node, CAVM_L2C_ASC_REGIONX_ATTR(region->number));
		l2c_asc_attr.s.s_en  = region->secure;
		l2c_asc_attr.s.ns_en = !region->secure;

		CSR_WRITE_PA(region->node, CAVM_L2C_ASC_REGIONX_ATTR(region->number), l2c_asc_attr.u);

		printf("Mark memory region %d at node %d:: %lx to %lx as %ssecure (%lx)\n",
			region->number, region->node,
			CSR_READ_PA(region->node, CAVM_L2C_ASC_REGIONX_START(region->number)),
			CSR_READ_PA(region->node, CAVM_L2C_ASC_REGIONX_END(region->number)),
			region->secure ? "" : "non-",
			CSR_READ_PA(region->node, CAVM_L2C_ASC_REGIONX_ATTR(region->number)));

		region++;
	}
}
