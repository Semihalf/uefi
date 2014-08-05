
static inline int dram_is_verbose()
{
    return 1; // FIXME: dram_is_verbose()
}

#define dram_printf(format, ...) printf(format, ##__VA_ARGS__)
#define error_print(format, ...) printf(format, ##__VA_ARGS__)
#ifdef DEBUG
    #define debug_print(format, ...) printf(format, ##__VA_ARGS__)
    #define DEBUG_DEFINED 1
#else
    #define debug_print(format, ...) do {} while (0)
    #define DEBUG_DEFINED 0
#endif

static inline void ddr_print(const char *format, ...)
{
	if (dram_is_verbose() || (DEBUG_DEFINED)) {
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
	}
}

