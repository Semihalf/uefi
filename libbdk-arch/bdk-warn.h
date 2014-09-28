/**
 * @file
 *
 * Functions for reporting errors and warnings.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup stdio Standard IO related functions
 * @{
 */

extern void __bdk_die(void) __attribute__ ((noreturn));
extern void bdk_fatal(const char *format, ...) __attribute__ ((noreturn, format(printf, 1, 2)));
extern void bdk_error(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
extern void bdk_warn(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
#define bdk_warn_if(expression, format, ...) if (bdk_unlikely(expression)) bdk_warn(format, ##__VA_ARGS__)
#define static_assert(a) _Static_assert(a, #a)

/* The following defines control detailed tracing of various parts of the
   BDK. Each one can be enabled(1) or disabled(0) independently. These
   should be disabled unless you are trying to debug something specific */

#define BDK_TRACE_ENABLE_BGX        0   /* BGX networking block */
#define BDK_TRACE_ENABLE_DRAM       0   /* DRAM initialzation */
#define BDK_TRACE_ENABLE_DRAM_TEST  0   /* DRAM test code */
#define BDK_TRACE_ENABLE_INIT       0   /* Early initalization, before main() */
#define BDK_TRACE_ENABLE_QLM        0   /* QLM related debug */
#define BDK_TRACE_ENABLE_EMMC       0   /* eMMC related debug */

/**
 * Macro for low level tracing of BDK functions. When enabled,
 * these translate to printf() calls. If disabled, they are
 * removed by the compiler. The "area" is a string that is
 * appended to "BDK_TRACE_ENABLE_" to figure out which enable
 * macro to use. The macro expects a ';' after it.
 */
#define BDK_TRACE(area, format, ...) do {       \
    if (BDK_TRACE_ENABLE_##area)                \
        printf("[%s:%d]" #area ": " format,     \
            __FILE__, __LINE__, ##__VA_ARGS__); \
} while (0)

/** @} */
