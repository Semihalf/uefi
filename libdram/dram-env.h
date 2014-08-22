/**
 * Functions for access the environment for DRAM tweaking.
 * Intenral use only.
 */


extern const char *lookup_env_parameter(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
extern const char *lookup_env_parameter_ull(const char *format, ...) __attribute__ ((format(printf, 1, 2)));

