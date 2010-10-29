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
#define OM_IGNORE_REVISION        0x01000000      /* Ignores revision in model checks */
#define OM_IGNORE_MINOR_REVISION  0x08000000      /* Ignores the minor revison on newer parts */
#define OM_FLAG_MASK              0xff000000

/*
 * CN6XXX models with new revision encoding
 */
#define OCTEON_CN63XX_PASS1_0   0x000d9000
#define OCTEON_CN63XX_PASS1_1   0x000d9001
#define OCTEON_CN63XX_PASS1_2   0x000d9002
#define OCTEON_CN63XX_PASS2_0   0x000d9008

#define OCTEON_CN63XX           (OCTEON_CN63XX_PASS1_0 | OM_IGNORE_REVISION)
#define OCTEON_CN63XX_PASS1_X   (OCTEON_CN63XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN63XX_PASS2_X   (OCTEON_CN63XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN68XX_PASS1_0   0x000d9100

#define OCTEON_CN68XX           (OCTEON_CN68XX_PASS1_0 | OM_IGNORE_REVISION)
#define OCTEON_CN68XX_PASS1_X   (OCTEON_CN68XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)

static inline int __OCTEON_MATCH_MASK__(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) == (y & z);
}

static inline int OCTEON_IS_MODEL(uint32_t arg_model) __attribute__ ((pure));
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

    asm ("mfc0 %0, $15,0" : "=r" (chip_model));

    switch (arg_model & OM_FLAG_MASK)
    {
        case OM_IGNORE_REVISION:
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_FAMILY_MASK);
        case OM_IGNORE_MINOR_REVISION:
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_FAMILY_MASK | OCTEON_FAMILY_MAJOR_REV_MASK);
        default:
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_FAMILY_MASK | OCTEON_FAMILY_MAJOR_REV_MASK | OCTEON_FAMILY_MINOR_REV_MASK);
    }
    return 0;
}

/** @} */
