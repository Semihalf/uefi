#include <bdk.h>
#include <stdio.h>

/**
 * Wait for the specified number of micro seconds
 *
 * @param usec   micro seconds to wait
 */
void bdk_wait_usec(uint64_t usec)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + usec * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 1000000;
    do
    {
        bdk_thread_yield();
    } while (bdk_clock_get_count(BDK_CLOCK_CORE) < done);
}

/**
 * Perform a soft reset of Octeon
 *
 * @return
 */
void bdk_reset_octeon(bdk_node_t node)
{
    fflush(NULL);

    /* Wait for TX fifo to empty */
    while (1)
    {
        BDK_CSR_INIT(fr, node, BDK_UAAX_FR(0));
        if (fr.s.txfe)
            break;
        bdk_thread_yield();
    }

    bdk_rst_soft_rst_t rst_soft_rst;
    rst_soft_rst.u64 = 0;
    rst_soft_rst.s.soft_rst = 1;
    BDK_CSR_WRITE(node, BDK_RST_SOFT_RST, rst_soft_rst.u64);
}


/**
 * Convert a memory pointer (void*) into a hardware compatible
 * memory address (uint64_t). Octeon hardware widgets don't
 * understand logical addresses.
 *
 * @param ptr    C style memory pointer
 * @return Hardware physical address
 */
uint64_t __bdk_ptr_to_phys_slow(void *ptr)
{
    uint64_t address = (long)ptr;

    switch (address >> 62)
    {
        case 0: /* Userspace address */
        case 1: /* Supervisor address */
            goto fail;
        case 2: /* Kernel Unmapped */
            return address & bdk_build_mask(49);
        case 3: /* Kernel Mapped */
            switch (address & 0xffffffffe0000000ull)
            {
                case 0xffffffff80000000ull: /* Kernel Unmapped */
                case 0xffffffffa0000000ull: /* Kernel Unmapped, Uncached */
                    address &= bdk_build_mask(30);
                    if (CAVIUM_IS_MODEL(OCTEON_CN78XX))
                    {
                        uint64_t cvmmemctl2;
                        BDK_MF_COP0(cvmmemctl2, COP0_CVMMEMCTL2);
                        cvmmemctl2 >>= 12; /* Extract KSEGNODE */
                        cvmmemctl2 &= 0x3;
                        /* Insert the node number into the address */
                        address |= cvmmemctl2 << 40;
                    }
                    return address;
                case 0xffffffffc0000000ull: /* Supervisor Mapped */
                case 0xffffffffe0000000ull: /* Kernel Mapped */
                {
                    uint64_t entryhi = address;
                    entryhi &= ~bdk_build_mask(13);
                    BDK_MT_COP0(entryhi, COP0_ENTRYHI);
                    BDK_TLBP;
                    uint32_t index;
                    BDK_MF_COP0(index, COP0_INDEX);
                    if (bdk_unlikely(index & (1<<31)))
                        goto fail;
                    BDK_TLBR;
                    uint32_t pagemask;
                    BDK_MF_COP0(pagemask, COP0_PAGEMASK);
                    pagemask |= bdk_build_mask(13);
                    pagemask >>= 1;
                    uint32_t select = address & (pagemask+1);
                    uint64_t entrylo;
                    if (bdk_unlikely(select))
                    {
                        BDK_MF_COP0(entrylo, COP0_ENTRYLO1);
                    }
                    else
                    {
                        BDK_MF_COP0(entrylo, COP0_ENTRYLO0);
                    }
                    if (bdk_unlikely(!(entrylo & 2))) /* Not valid */
                        goto fail;
                    entrylo >>= 6;
                    entrylo <<= 12;
                    entrylo |= select;
                    entrylo |= address & pagemask;
                    return entrylo;
                }
                default:
                    goto fail;
            }
    }
fail:
    bdk_fatal("bdk_ptr_to_phys() passed an invalid pointer %p\n", ptr);
}

