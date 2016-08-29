#ifndef __THUNDER_COMMON_H__
#define __THUNDER_COMMON_H__

#define MIDR_REVISION_MASK      0xf
#define MIDR_REVISION(midr)     ((midr) & MIDR_REVISION_MASK)
#define MIDR_PARTNUM_SHIFT      4
#define MIDR_PARTNUM_MASK       (0xfff << MIDR_PARTNUM_SHIFT)
#define MIDR_PARTNUM(midr)      \
        (((midr) & MIDR_PARTNUM_MASK) >> MIDR_PARTNUM_SHIFT)

#define T81PARTNUM 0xA2

static inline int CAVIUM_SOC_TYPE(void)
{
        uint32_t midr;
        __asm__ __volatile__ ("mrs %0, s3_0_c0_c0_0" : "=r" (midr));
        return MIDR_PARTNUM(midr);
}

int thunder_get_lmc_per_node(void)
{

	switch (CAVIUM_SOC_TYPE()) {
        case T81PARTNUM :
		return 1;
	default:
		return -1;
	}
}

#endif /* __THUDNER_COMMON_H__ */
