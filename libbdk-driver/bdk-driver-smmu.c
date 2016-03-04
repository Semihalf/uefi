#include <bdk.h>

BDK_REQUIRE_DEFINE(DRIVER_SMMU);

/**
 * The SMMU probe function does all initialization so that other devices may do
 * DMAs in their init() functions. The assumption is that no DMAs will be needed
 * until the SMMU probe() is complete.
 *
 * @param device SMMU to probe
 *
 * @return Zero on success, negative on failure
 */
static int probe(bdk_device_t *device)
{
    /* Change the device name */
    bdk_device_rename(device, "N%d.SMMU%d", device->node, device->instance);

    /* Allow all IO units to access secure memory */
    for (int i = 0; i < 2048; i++)
        BDK_BAR_WRITE(device, BDK_SMMUX_SSDRX(device->instance, i), 0);
    return 0;
}

/**
 * SMMU init() function
 *
 * @param device SMMU to initialize
 *
 * @return Zero on success, negative on failure
 */
static int init(bdk_device_t *device)
{
    /* Nothing to do here */
    return 0;
}

bdk_driver_t __bdk_driver_smmu = {
    .id = (BDK_PCC_PROD_E_GEN << 24) | BDK_PCC_VENDOR_E_CAVIUM | (BDK_PCC_DEV_IDL_E_SMMU << 16),
    .probe = probe,
    .init = init,
};
