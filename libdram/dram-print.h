/**
 * Functions for diplaying output in libdram. Internal use only.
 */

typedef enum {
    // low 4 bits are verbosity level
    VBL_OFF       =   0,
    VBL_NORM      =   1,
    VBL_FAE       =   2,
    VBL_TME       =   3,
    VBL_DEV       =   4,
    VBL_DEV2      =   5,
    VBL_DEV3      =   6,
    VBL_DEV4      =   7,
    // upper 4 bits are special verbosities
    VBL_SEQ       =  16,
    VBL_CSRS      =  32,
    // force at least 8 bits for enum
    VBL_MAX       = 255
} dram_verbosity_t;

extern dram_verbosity_t dram_verbosity;
// "level" should be 1-7, or only one of the special bits
// let the compiler optimize the test for verbosity
#define is_verbosity_level(level)   (((level) != 0) && ((int)(dram_verbosity & 0x0f) >= (level)))
#define is_verbosity_special(level) ((dram_verbosity & (level)) != 0)
#define dram_is_verbose(level)      (((level) >= VBL_SEQ) ? is_verbosity_special(level) : is_verbosity_level(level))

#define VB_PRT(level, format, ...)         \
    do {                                    \
        if (dram_is_verbose(level))         \
            printf(format, ##__VA_ARGS__);  \
    } while (0)

// keep temporarily for compatibility; may/should go away some day...
#define OFF               VBL_OFF
#define NORMAL            VBL_NORM
#define TRACE_CSR_WRITES  VBL_CSRS
#define TRACE_SEQUENCES   VBL_SEQ

#define ddr_print(format, ...) VB_PRT(VBL_NORM, format, ##__VA_ARGS__)

#define error_print(format, ...) printf(format, ##__VA_ARGS__)

#ifdef DEBUG_DEBUG_PRINT
    #define debug_print(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define debug_print(format, ...) do {} while (0)
#endif
