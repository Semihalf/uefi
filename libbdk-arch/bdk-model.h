/**
 * @file
 *
 * Functions for determining which Cavium chip you are running
 * on.
 *
 * <hr>$Revision: 49448 $<hr>
 * @addtogroup chips
 * @{
 */


/* Flag bits in top byte */
#define __OM_IGNORE_REVISION        0x80000000
#define __OM_IGNORE_MINOR_REVISION  0x40000000

#define CAVIUM_CN88XX_PASS1_0   0x430f0a10
#define CAVIUM_CN88XX           (CAVIUM_CN88XX_PASS1_0 | __OM_IGNORE_REVISION)
#define CAVIUM_CN88XX_PASS1_X   (CAVIUM_CN88XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define CAVIUM_CN85XX_PASS1_0   0x430f0a20
#define CAVIUM_CN85XX           (CAVIUM_CN85XX_PASS1_0 | __OM_IGNORE_REVISION)
#define CAVIUM_CN85XX_PASS1_X   (CAVIUM_CN85XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

static inline uint64_t cavium_get_model() __attribute__ ((pure, always_inline));
static inline uint64_t cavium_get_model()
{
    uint64_t result;
    asm ("mrs %[rd],MIDR_EL1" : [rd] "=r" (result));
    return result;
}

static inline int CAVIUM_IS_MODEL(uint32_t arg_model) __attribute__ ((pure, always_inline));
static inline int CAVIUM_IS_MODEL(uint32_t arg_model)
{
    bdk_sys_midr_el1_t arg_midr_el1;
    bdk_sys_midr_el1_t midr_el1;

    arg_midr_el1.u = arg_model;
    midr_el1.u = cavium_get_model();

    if (arg_model & __OM_IGNORE_REVISION)
    {
        return (arg_midr_el1.s.variant == midr_el1.s.variant);
    }
    else if (arg_model & __OM_IGNORE_MINOR_REVISION)
    {
        return ((arg_midr_el1.s.variant == midr_el1.s.variant) &&
                (arg_midr_el1.s.partnum == midr_el1.s.partnum));
    }
    else
    {
        return ((arg_midr_el1.s.variant == midr_el1.s.variant) &&
                (arg_midr_el1.s.partnum == midr_el1.s.partnum) &&
                (arg_midr_el1.s.revision == midr_el1.s.revision));
    }
}

/** @} */
