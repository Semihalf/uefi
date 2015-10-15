/**
 * @file
 *
 * Interface to report boot status
 *
 * @addtogroup boot
 * @{
 */

/**
 * Possible boot statuses that can be reported
 */
typedef enum
{
    BDK_BOOT_STATUS_BOOT_STUB_STARTING              = 0x000,
    BDK_BOOT_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE   = 0x001,
    BDK_BOOT_STATUS_BOOT_STUB_CCPI_COMPLETE         = 0x002,
    BDK_BOOT_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE   = 0x003,
    BDK_BOOT_STATUS_BOOT_STUB_QLM_COMPLETE          = 0x004,
    BDK_BOOT_STATUS_BOOT_STUB_LOADING_ATF           = 0x005,
    BDK_BOOT_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS   = 0x006,
    BDK_BOOT_STATUS_BOOT_STUB_COMPLETE              = 0x007,
    BDK_BOOT_STATUS_REQUEST_POWER_CYCLE             = 0x0f2, /* Don't continue, power cycle */
} bdk_boot_status_t;

/**
 * Report boot status to the BMC or whomever might care. This function
 * will return quickly except for a status of "power cycle". In the power cycle
 * case it is assumed the board is in a bad state and should not continue until
 * a power cycle restarts us.
 *
 * @param status Status to report. Enumerated in bdk_boot_status_t
 */
extern void bdk_boot_status(bdk_boot_status_t status);

/**
 * Set the boot status OK for the BMC. This menas any watchdog the BMC is using
 * to track boot should be shutoff as the system has successfully booted. Note
 * that this doesn't change the reported status from
 * bdk_boot_status(), it just sets the complete bit.
 */
extern void bdk_boot_status_ok(void);

/** @} */
