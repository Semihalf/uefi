/**
 * @file
 * Functions for accessing memory and CSRs on Octeon when we are compiling
 * natively.
 *
 * <hr>$Revision: 38306 $<hr>
*/

/**
 * Convert a memory pointer (void*) into a hardware compatable
 * memory address (uint64_t). Octeon hardware widgets don't
 * understand logical addresses.
 *
 * @param ptr    C style memory pointer
 * @return Hardware physical address
 */
static inline uint64_t bdk_ptr_to_phys(void *ptr)
{
    extern uint64_t __bdk_ptr_to_phys_slow(void *ptr);
    uint64_t address = (long)ptr;

    /* Kernel Unmapped */
    if (bdk_likely(address >> 62 == 2))
        return address & bdk_build_mask(49);
    else
        return __bdk_ptr_to_phys_slow(ptr);
}


/**
 * Convert a hardware physical address (uint64_t) into a
 * memory pointer (void *).
 *
 * @param physical_address
 *               Hardware physical address to memory
 * @return Pointer to memory
 */
static inline void *bdk_phys_to_ptr(uint64_t physical_address)
{
    bdk_warn_if(physical_address==0, "bdk_phys_to_ptr() passed a zero address\n");
    return (void*)(physical_address | (1ull<<63));
}


/* We have a full 64bit ABI. Writing to a 64bit address can be done with
    a simple volatile pointer */
#define BDK_BUILD_WRITE64(TYPE, ST)                                    \
static inline void bdk_write64_##TYPE(uint64_t addr, TYPE##_t val)     \
{                                                                       \
    *CASTPTR(volatile TYPE##_t, addr) = val;                            \
}

/* We have a full 64bit ABI. Writing to a 64bit address can be done with
    a simple volatile pointer */
#define BDK_BUILD_READ64(TYPE, LT)                                     \
static inline TYPE##_t bdk_read64_##TYPE(uint64_t addr)                \
{                                                                       \
    return *CASTPTR(volatile TYPE##_t, addr);                           \
}

/* The following defines 8 functions for writing to a 64bit address. Each
    takes two arguments, the address and the value to write.
    bdk_write64_int64      bdk_write64_uint64
    bdk_write64_int32      bdk_write64_uint32
    bdk_write64_int16      bdk_write64_uint16
    bdk_write64_int8       bdk_write64_uint8 */
BDK_BUILD_WRITE64(int64, "sd");
BDK_BUILD_WRITE64(int32, "sw");
BDK_BUILD_WRITE64(int16, "sh");
BDK_BUILD_WRITE64(int8, "sb");
BDK_BUILD_WRITE64(uint64, "sd");
BDK_BUILD_WRITE64(uint32, "sw");
BDK_BUILD_WRITE64(uint16, "sh");
BDK_BUILD_WRITE64(uint8, "sb");

/* The following defines 8 functions for reading from a 64bit address. Each
    takes the address as the only argument
    bdk_read64_int64       bdk_read64_uint64
    bdk_read64_int32       bdk_read64_uint32
    bdk_read64_int16       bdk_read64_uint16
    bdk_read64_int8        bdk_read64_uint8 */
BDK_BUILD_READ64(int64, "ld");
BDK_BUILD_READ64(int32, "lw");
BDK_BUILD_READ64(int16, "lh");
BDK_BUILD_READ64(int8, "lb");
BDK_BUILD_READ64(uint64, "ld");
BDK_BUILD_READ64(uint32, "lw");
BDK_BUILD_READ64(uint16, "lhu");
BDK_BUILD_READ64(uint8, "lbu");


/**
 * Number of the Core on which the program is currently running.
 *
 * @return Number of cores
 */
static inline unsigned int bdk_get_core_num(void)
{
    unsigned int core_num;
    BDK_RDHWRNV(core_num, 0);
    return core_num;
}


/**
 * Returns the number of bits set in the provided value.
 * Simple wrapper for POP instruction.
 *
 * @param val    32 bit value to count set bits in
 *
 * @return Number of bits set
 */
static inline uint32_t bdk_pop(uint32_t val)
{
    uint32_t pop;
    BDK_POP(pop, val);
    return pop;
}


/**
 * Returns the number of bits set in the provided value.
 * Simple wrapper for DPOP instruction.
 *
 * @param val    64 bit value to count set bits in
 *
 * @return Number of bits set
 */
static inline int bdk_dpop(uint64_t val)
{
    int pop;
    BDK_DPOP(pop, val);
    return pop;
}


/**
 * Wait for the specified number of core clock cycles
 *
 * @param cycles
 */
static inline void bdk_wait(uint64_t cycles)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + cycles;

    while (bdk_clock_get_count(BDK_CLOCK_CORE) < done)
    {
        /* Spin */
    }
}

