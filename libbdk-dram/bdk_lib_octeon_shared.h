
/* Uboot and lib_octeon_shared uses ulong for unsigned long */
#define ulong unsigned long

/* This is needed to make lib_octeon_shared build reasonably sanely */
#define unix 1
#define CONFIG_OCTEON_NAND_STAGE2 1

/* Use the BDKs warn function instead of cvmx_warn */
#define cvmx_warn bdk_warn
extern void bdk_warn(const char *format, ...) __attribute__ ((format(printf, 1, 2)));

/* Replace OCTEON_IS_MODEL with our version to avoid the feature nastiness */
#define OCTEON_IS_MODEL bdk_is_model_wrapper
#define USE_RUNTIME_MODEL_CHECKS 1
extern int bdk_is_model_wrapper(unsigned int arg_model) __attribute__ ((pure));

