#ifndef __THUNDER_COMMON_H__
#define __THUNDER_COMMON_H__

#include <stdint.h>
#include <xlat_tables.h>

#define MIDR_REVISION_MASK      0xf
#define MIDR_REVISION(midr)     ((midr) & MIDR_REVISION_MASK)
#define MIDR_PARTNUM_SHIFT      4
#define MIDR_PARTNUM_MASK       (0xfff << MIDR_PARTNUM_SHIFT)
#define MIDR_PARTNUM(midr)      \
        (((midr) & MIDR_PARTNUM_MASK) >> MIDR_PARTNUM_SHIFT)

#define T81PARTNUM 0xA2
#define T83PARTNUM 0xA3
#define T98PARTNUM 0xB1

int thunder_get_lmc_per_node(void);

int thunder_get_num_ecams_per_node(void);

void add_map_record(unsigned long addr, unsigned long size, mmap_attr_t attr);

#endif /* __THUDNER_COMMON_H__ */
