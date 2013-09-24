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
extern void bdk_dprintf(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
#define bdk_warn_if(expression, format, ...) if (bdk_unlikely(expression)) bdk_warn(format, ##__VA_ARGS__)

#ifndef BDK_DEBUG_TRACE
#define BDK_DEBUG_TRACE 0
#endif
#if BDK_DEBUG_TRACE
#define BDK_TRACE(format, ...) bdk_dprintf("[%s:%d] " format, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define BDK_TRACE(format, ...) do {} while (0)
#endif
/** @} */
