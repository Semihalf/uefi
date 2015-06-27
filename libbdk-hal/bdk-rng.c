#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(RNG);

/**
 * Enables the random number generator. Must be called before RNG is used
 */
void bdk_rng_enable(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_RNM_CTL_STATUS,
        c.s.ent_en = 1;
        c.s.rng_en = 1);
    /* Read back after enable so we know it is done. Needed on t88 pass 2.0 emulator */
    BDK_CSR_READ(node, BDK_RNM_CTL_STATUS);
    /* Errata (RNM-22528) First consecutive reads to RNM_RANDOM return same
       value. Before using the random entropy, read RNM_RANDOM at least once
       and discard the data */
    bdk_rng_get_random64();
}

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

