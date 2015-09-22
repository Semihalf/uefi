#include <bdk.h>

BDK_REQUIRE_DEFINE(RNM);

/**
 * Reads 8 bits of random data from Random number generator
 *
 * @return random data
 */
uint8_t bdk_rng_get_random8(void)
{

    return bdk_read64_uint8(bdk_numa_get_address(bdk_numa_local(), BDK_RNM_RANDOM));
}

/**
 * Reads 16 bits of random data from Random number generator
 *
 * @return random data
 */
uint16_t bdk_rng_get_random16(void)
{
    return bdk_read64_uint16(bdk_numa_get_address(bdk_numa_local(), BDK_RNM_RANDOM));
}

/**
 * Reads 32 bits of random data from Random number generator
 *
 * @return random data
 */
uint32_t bdk_rng_get_random32(void)
{
    return bdk_read64_uint32(bdk_numa_get_address(bdk_numa_local(), BDK_RNM_RANDOM));
}

/**
 * Reads 64 bits of random data from Random number generator
 *
 * @return random data
 */
uint64_t bdk_rng_get_random64(void)
{
    return bdk_read64_uint64(bdk_numa_get_address(bdk_numa_local(), BDK_RNM_RANDOM));
}

/**
 * The RNM probe function
 *
 * @param device RNM to probe
 *
 * @return Zero on success, negative on failure
 */
static int probe(bdk_device_t *device)
{
    bdk_device_rename(device, "N%d.RNM%d", device->node, device->instance);
    return 0;
}

/**
 * RNM init() function
 *
 * @param device RNM to initialize
 *
 * @return Zero on success, negative on failure
 */
static int init(bdk_device_t *device)
{
    BDK_BAR_MODIFY(c, device, BDK_RNM_CTL_STATUS,
        c.s.ent_en = 1;
        c.s.rng_en = 1);
    /* Read back after enable so we know it is done. Needed on t88 pass 2.0 emulator */
    BDK_BAR_READ(device, BDK_RNM_CTL_STATUS);
    /* Errata (RNM-22528) First consecutive reads to RNM_RANDOM return same
       value. Before using the random entropy, read RNM_RANDOM at least once
       and discard the data */
    bdk_rng_get_random64();
    return 0;
}

bdk_driver_t __bdk_driver_rnm = {
    .id = 0xa000177d | (BDK_PCC_DEV_IDL_E_RNM << 16),
    .probe = probe,
    .init = init,
};
