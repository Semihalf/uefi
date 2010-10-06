/**
 * @file
 * Functions for accessing memory and CSRs on Octeon when we are compiling
 * natively.
 *
 * <hr>$Revision: 38306 $<hr>
*/

/**
 * Returns the Octeon processor ID.
 *
 * @return Octeon processor ID from COP0
 */
static inline uint32_t bdk_get_proc_id(void)
{
    uint32_t id;
    asm ("mfc0 %0, $15,0" : "=r" (id));
    return id;
}

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
    if (BDK_ENABLE_PARAMETER_CHECKING)
        bdk_warn_if(ptr==NULL, "bdk_ptr_to_phys() passed a NULL pointer\n");
    if (sizeof(void*) == 8)
    {
        /* We're running in 64 bit mode. Normally this means that we can use
            40 bits of address space (the hardware limit). Unfortunately there
            is one case were we need to limit this to 30 bits, sign extended
            32 bit. Although these are 64 bits wide, only 30 bits can be used */
        if ((CAST64(ptr) >> 62) == 3)
            return CAST64(ptr) & bdk_build_mask(30);
        else
            return CAST64(ptr) & bdk_build_mask(40);
    }
    else
	return (long)(ptr) & 0x7fffffff;
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
    if (BDK_ENABLE_PARAMETER_CHECKING)
        bdk_warn_if(physical_address==0, "bdk_phys_to_ptr() passed a zero address\n");

    /* Set the XKPHYS/KSEG0 bit as appropriate based on ABI */
    if (sizeof(void*) == 8)
        return CASTPTR(void, BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, physical_address));
    else
	return CASTPTR(void, BDK_ADD_SEG32(BDK_MIPS32_SPACE_KSEG0, physical_address));
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


/**
 * Wait for the specified number of micro seconds
 *
 * @param usec   micro seconds to wait
 */
static inline void bdk_wait_usec(uint64_t usec)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + usec * bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000000;
    while (bdk_clock_get_count(BDK_CLOCK_CORE) < done)
    {
        /* Spin */
    }
}


/**
 * Wait for the specified number of io clock cycles
 *
 * @param cycles
 */
static inline void bdk_wait_io(uint64_t cycles)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_SCLK) + cycles;

    while (bdk_clock_get_count(BDK_CLOCK_SCLK) < done)
    {
        /* Spin */
    }
}


/**
 * Perform a soft reset of Octeon
 *
 * @return
 */
static inline void bdk_reset_octeon(void)
{
    bdk_ciu_soft_rst_t ciu_soft_rst;
    ciu_soft_rst.u64 = 0;
    ciu_soft_rst.s.soft_rst = 1;
    BDK_CSR_WRITE(BDK_CIU_SOFT_RST, ciu_soft_rst.u64);
}

