/**
 * Functions for diplaying output in libdram. Internal use only.
 */

typedef enum {
    OFF               = 0,
    NORMAL            = 1,
    TRACE_SEQUENCES   = 2,
    TRACE_CSR_WRITES  = 3
} dram_verbosity_t;

static inline int dram_is_verbose(dram_verbosity_t level)
{
    extern dram_verbosity_t dram_verbosity;
    return (dram_verbosity >= level);
}

#define ddr_print(format, ...)              \
    do {                                    \
        if (dram_is_verbose(NORMAL))             \
            printf(format, ##__VA_ARGS__);  \
    } while (0)

#define error_print(format, ...) printf(format, ##__VA_ARGS__)

#ifdef DEBUG
    #define debug_print(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define debug_print(format, ...) do {} while (0)
#endif

/**
 * Port some enhanced DDR3 printing from a recent O78 SDK
 *
 * define this to identify the ported code/data
 * and do it before any of the other headers,
 * just to be sure...
 */
//#define DDR3_ENHANCE_PRINT
#undef DDR3_ENHANCE_PRINT

