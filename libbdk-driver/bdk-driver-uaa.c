#include <bdk.h>

BDK_REQUIRE_DEFINE(DRIVER_UAA);

/**
 * The UAA probe function doesn't need to do anything with the hardware
 *
 * @param device UAA uart to probe
 *
 * @return Zero on success, negative on failure
 */
static int probe(bdk_device_t *device)
{
    /* Change the device name */
    bdk_device_rename(device, "N%d.UAA%d", device->node, device->instance);
    return 0;
}

/**
 * UAA init() registers the uart as a devcie and connects it to the BDK console
 *
 * @param device UAA uart to initialize
 *
 * @return Zero on success, negative on failure
 */
static int init(bdk_device_t *device)
{
    /* The first two uarts are setup very early during init, so this driver only needs to
       cover uarts 2 and above on the master node */
    if ((device->node == bdk_numa_master()) && (device->instance < 2))
        return 0;

    /* Set the baud rate */
    bdk_set_baudrate(device->node, device->instance, 115200, false);

    /* Register the device */
    extern const __bdk_fs_dev_ops_t bdk_fs_uart_ops;
    if (bdk_fs_register_dev("uart", device->instance, &bdk_fs_uart_ops))
        return -1;

    /* Connect the console to the uart */
    char filename[16];
    snprintf(filename, sizeof(filename), "/dev/n%d.uart%d", device->node, device->instance);
    return bdk_console_open_file(filename);
}

bdk_driver_t __bdk_driver_uaa = {
    .id = (BDK_PCC_PROD_E_GEN << 24) | BDK_PCC_VENDOR_E_CAVIUM | (BDK_PCC_DEV_IDL_E_UAA << 16),
    .probe = probe,
    .init = init,
};
