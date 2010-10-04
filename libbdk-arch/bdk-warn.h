extern void bdk_warn(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
#define bdk_warn_if(expression, format, ...) if (expression) bdk_warn(format, ##__VA_ARGS__)

