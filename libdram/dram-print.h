
static inline int dram_is_verbose()
{
    extern int dram_verbose_on;
    return dram_verbose_on;
}

#define ddr_print(format, ...)              \
    do {                                    \
        if (dram_is_verbose())              \
            printf(format, ##__VA_ARGS__);  \
    } while (0)

#define error_print(format, ...) printf(format, ##__VA_ARGS__)

#ifdef DEBUG
    #define debug_print(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define debug_print(format, ...) do {} while (0)
#endif

