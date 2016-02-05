/**
 * @file
 *
 * bdk_driver_t represents drivers for devices connected using
 * ECAMs. This are discover by scanning the ECAMs and
 * instantiating devices for what is found.
 *
 * @defgroup driver ECAM Attached Drivers
 * @addtogroup driver
 * @{
 */
#include "bdk-driver-sgpio.h"

/**
 * Defines the main entry points for a device driver
 */
typedef struct bdk_driver_s
{
    struct bdk_driver_s *next; /* Used by bdk-device to maintian list */
    uint32_t id; /* ECAM device ID */
    int (*probe)(bdk_device_t *device);
    int (*init)(bdk_device_t *device);
} bdk_driver_t;

/**
 * Called by the BDK to register all loaded drivers with bdk-device.
 *
 * @return Zero on success, negative on failure
 */
extern int __bdk_driver_register_all(void) BDK_WEAK;

/** @} */
