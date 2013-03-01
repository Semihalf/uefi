/**
 * @file
 *
 * Functions for determining which Octeon chip you are running on.
 *
 * <hr>$Revision: 49448 $<hr>
 * @addtogroup octeon
 * @{
 */


/* Flag bits in top byte */
#define __OM_IGNORE_REVISION        0x01000000
#define __OM_IGNORE_MINOR_REVISION  0x08000000
#define __OM_FLAG_MASK              0xff000000

/*
 * CN6XXX models with new revision encoding
 */
#define OCTEON_CN63XX_PASS1_0   0x000d9000
#define OCTEON_CN63XX_PASS1_1   0x000d9001
#define OCTEON_CN63XX_PASS1_2   0x000d9002
#define OCTEON_CN63XX_PASS2_0   0x000d9008
#define OCTEON_CN63XX_PASS2_1   0x000d9009
#define OCTEON_CN63XX_PASS2_2   0x000d900a

#define OCTEON_CN63XX           (OCTEON_CN63XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CN63XX_PASS1_X   (OCTEON_CN63XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN63XX_PASS2_X   (OCTEON_CN63XX_PASS2_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN68XX_PASS1_0   0x000d9100
#define OCTEON_CN68XX_PASS1_1   0x000d9101
#define OCTEON_CN68XX_PASS2_0   0x000d9108
#define OCTEON_CN68XX_PASS2_1   0x000d9109

#define OCTEON_CN68XX           (OCTEON_CN68XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CN68XX_PASS1_X   (OCTEON_CN68XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN68XX_PASS2_X   (OCTEON_CN68XX_PASS2_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN66XX_PASS1_0   0x000d9200
#define OCTEON_CN66XX_PASS1_1   0x000d9201
#define OCTEON_CN66XX_PASS1_2   0x000d9202

#define OCTEON_CN66XX           (OCTEON_CN66XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CN66XX_PASS1_X   (OCTEON_CN66XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN61XX_PASS1_0   0x000d9300
#define OCTEON_CN61XX_PASS1_1   0x000d9301

#define OCTEON_CN61XX           (OCTEON_CN61XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CN61XX_PASS1_X   (OCTEON_CN61XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEON_CNF71XX_PASS1_0   0x000d9400
#define OCTEON_CNF71XX_PASS1_1   0x000d9401

#define OCTEON_CNF71XX           (OCTEON_CNF71XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CNF71XX_PASS1_X   (OCTEON_CNF71XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN78XX_PASS1_0   0x000d9500

#define OCTEON_CN78XX           (OCTEON_CN78XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CN78XX_PASS1_X   (OCTEON_CN78XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN70XX_PASS1_0   0x000d9600

#define OCTEON_CN70XX           (OCTEON_CN70XX_PASS1_0 | __OM_IGNORE_REVISION)
#define OCTEON_CN70XX_PASS1_X   (OCTEON_CN70XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

static inline int __OCTEON_MATCH_MASK__(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) == (y & z);
}

static inline int OCTEON_IS_MODEL(uint32_t arg_model) __attribute__ ((pure, always_inline));
static inline int OCTEON_IS_MODEL(uint32_t arg_model)
{
    /* The revision byte (low byte) has two different encodings.
    **     <7>:   reserved (0)
    **     <6>:   alternate package
    **     <5:3>: major revision
    **     <2:0>: minor revision
    */
    const uint32_t OCTEON_FAMILY_MASK = 0x00ffff00;
    const uint32_t OCTEON_FAMILY_MAJOR_REV_MASK = 0x00000038;
    const uint32_t OCTEON_FAMILY_MINOR_REV_MASK = 0x00000007;
    uint32_t chip_model;

#ifdef __linux__
    extern uint32_t octeon_remote_get_model(void) __attribute__ ((pure));
    chip_model = octeon_remote_get_model();
#else
    asm ("mfc0 %0, $15,0" : "=r" (chip_model));
#endif

    switch (arg_model & __OM_FLAG_MASK)
    {
        case __OM_IGNORE_REVISION:
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_FAMILY_MASK);
        case __OM_IGNORE_MINOR_REVISION:
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_FAMILY_MASK | OCTEON_FAMILY_MAJOR_REV_MASK);
        case 0:
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_FAMILY_MASK | OCTEON_FAMILY_MAJOR_REV_MASK | OCTEON_FAMILY_MINOR_REV_MASK);
        case 0x40000000: /* FIXME: Match all cn6XXX Octeon models from SDK. Needed for lib_octeon_shared */
            return 1;
        default:
            //bdk_error("OCTEON_IS_MODEL: Unexpected flags 0x%08x\n", arg_model & __OM_FLAG_MASK);
            return 0;
    }
    return 0;
}

/** @} */
