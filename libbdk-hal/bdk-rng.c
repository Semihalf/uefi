#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(RNG);

/**
 * Structure describing the data format used for IOBDMA stores to the RNG.
 */
typedef union
{
    uint64_t        u64;
    struct {
        uint64_t    scraddr : 8;    /**< the (64-bit word) location in scratchpad to write to (if len != 0) */
        uint64_t    len     : 8;    /**< the number of words in the response (0 => no response) */
        uint64_t    did     : 8;    /**< the ID of the device on the non-coherent bus */
        uint64_t    reserved_38_39 : 2;
        uint64_t    node    : 2;    /**< Numa node number */
        uint64_t    addr    :40;    /**< the address that will appear in the first tick on the NCB bus */
    } s;
} bdk_rng_iobdma_data_t;


/**
 * Enables the random number generator. Must be called before RNG is used
 */
void bdk_rng_enable(bdk_node_t node)
{
    bdk_rnm_ctl_status_t rnm_ctl_status;
    rnm_ctl_status.u64 = BDK_CSR_READ(node, BDK_RNM_CTL_STATUS);
    if (!rnm_ctl_status.s.rng_en)
    {
        rnm_ctl_status.s.ent_en = 1;
        rnm_ctl_status.s.rng_en = 1;
        BDK_CSR_WRITE(node, BDK_RNM_CTL_STATUS, rnm_ctl_status.u64);
    }
}

static inline uint64_t bdk_rng_load_address()
{
    uint64_t result = 0x800140ull << 40;
    result |= (uint64_t)bdk_numa_local() << 36;
    return result;
}

/**
 * Reads 8 bits of random data from Random number generator
 *
 * @return random data
 */
uint8_t bdk_rng_get_random8(void)
{
    return bdk_read64_uint8(bdk_rng_load_address());
}

/**
 * Reads 16 bits of random data from Random number generator
 *
 * @return random data
 */
uint16_t bdk_rng_get_random16(void)
{
    return bdk_read64_uint16(bdk_rng_load_address());
}

/**
 * Reads 32 bits of random data from Random number generator
 *
 * @return random data
 */
uint32_t bdk_rng_get_random32(void)
{
    return bdk_read64_uint32(bdk_rng_load_address());
}

/**
 * Reads 64 bits of random data from Random number generator
 *
 * @return random data
 */
uint64_t bdk_rng_get_random64(void)
{
    return bdk_read64_uint64(bdk_rng_load_address());
}

/**
 * Requests random data from the RNG block asynchronously using and IOBDMA operation.
 * The random data will be written into the cores
 * local memory at the specified address.  A SYNCIOBDMA
 * operation should be issued to stall for completion of the write.
 *
 * @param scr_addr  Address in scratch memory to put the result
 *                  MUST be a multiple of 8 bytes
 * @param num_bytes Number of bytes of random data to write at
 *                  scr_addr
 *                  MUST be a multiple of 8 bytes
 *
 * @return 0 on success
 *         1 on error
 */
int bdk_rng_request_random_async(uint64_t scr_addr, uint64_t num_bytes)
{
    bdk_rng_iobdma_data_t data;

    if (num_bytes & 0x7 || scr_addr & 0x7)
        return(1);

    /* scr_addr must be 8 byte aligned */
    data.s.scraddr = scr_addr >> 3;
    data.s.len = num_bytes >> 3;
    data.s.did = 0x40;
    data.s.node = bdk_numa_local();
    bdk_send_single(data.u64);
    return(0);
}

