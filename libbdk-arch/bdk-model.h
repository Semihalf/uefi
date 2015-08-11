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


/* Flag bits in top byte. The top byte of MIDR_EL1 is defined
   as ox43, the Cavium implementer code. In this number, bit 7
   and bit 5 are defiend as zero. We use these bits to signal
   that revision numbers should be ignored. It isn't ideal
   that these are in the middle of an already defined field,
   but this keeps the model numbers as 32 bits */
#define __OM_IGNORE_REVISION        0x80000000
#define __OM_IGNORE_MINOR_REVISION  0x20000000

#define CAVIUM_CN88XX_PASS1_0   0x430f0a10
#define CAVIUM_CN88XX_PASS1_1   0x430f0a11
#define CAVIUM_CN88XX_PASS2_0   0x431f0a10
#define CAVIUM_CN88XX           (CAVIUM_CN88XX_PASS1_0 | __OM_IGNORE_REVISION)
#define CAVIUM_CN88XX_PASS1_X   (CAVIUM_CN88XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)
#define CAVIUM_CN88XX_PASS2_X   (CAVIUM_CN88XX_PASS2_0 | __OM_IGNORE_MINOR_REVISION)

#define CAVIUM_CN83XX_PASS1_0   0x430f0a30
#define CAVIUM_CN83XX           (CAVIUM_CN83XX_PASS1_0 | __OM_IGNORE_REVISION)
#define CAVIUM_CN83XX_PASS1_X   (CAVIUM_CN83XX_PASS1_0 | __OM_IGNORE_MINOR_REVISION)

static inline uint64_t cavium_get_model() __attribute__ ((pure, always_inline));
static inline uint64_t cavium_get_model()
{
#ifdef BDK_BUILD_HOST
    extern uint32_t octeon_remote_get_model(void) __attribute__ ((pure));
    return octeon_remote_get_model();
#else
    uint64_t result;
    asm ("mrs %[rd],MIDR_EL1" : [rd] "=r" (result));
    return result;
#endif
}

static inline int CAVIUM_IS_MODEL(uint32_t arg_model) __attribute__ ((pure, always_inline));
static inline int CAVIUM_IS_MODEL(uint32_t arg_model)
{
    const uint32_t PARTNUM = 0xfff0;    /* Bits 15:4 */
    const uint32_t VARIANT = 0xf00000;  /* Bits 23:20 */
    const uint32_t REVISION = 0xf;      /* Bits 3:0 */

    uint32_t my_model = cavium_get_model();
    uint32_t mask;

    if (arg_model & __OM_IGNORE_REVISION)
        mask = PARTNUM;
    else if (arg_model & __OM_IGNORE_MINOR_REVISION)
        mask = PARTNUM | VARIANT;
    else
        mask = PARTNUM | VARIANT | REVISION;
    return ((arg_model & mask) == (my_model & mask));
}

/** @} */
