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

extern void bdk_fatal(const char *format, ...) __attribute__ ((noreturn, format(printf, 1, 2)));
extern void bdk_error(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
extern void bdk_warn(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
extern void bdk_dprintf(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
#define bdk_warn_if(expression, format, ...) if (expression) bdk_warn(format, ##__VA_ARGS__)

/** @} */
