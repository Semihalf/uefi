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
