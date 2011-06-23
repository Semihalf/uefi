#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

#define ULL unsigned long long

#define RETURN_ON_FAIL(a)                           \
    do {                                            \
        int r = a;                                  \
        if (r) {                                    \
            printf("%s failed with %d\n", #a, r);   \
            return -1;                              \
        }                                           \
    } while (0)

uint64_t physical_map[2];

void hex_dump(const char *message,  uint8_t *buffer,  int size)
{
    printf("%8s:", message);
    while (size--)
        printf(" %02x", 0xff & *buffer++);
    printf("\n");
}

void hex_compare(const char *title1, const char *title2,
                 uint8_t *buffer1, uint8_t *buffer2, int size)
{
    int offset = 0;
    printf("      %-36s %s\n",  title1,  title2);
    while (offset < size)
    {
        int i;
        printf("%04x:",  offset);
        for (i=0; i<16; i++)
        {
            if ((i&3) == 0)
                printf(" ");
            if (offset+i < size)
                printf("%02x", 0xff & buffer1[offset+i]);
            else
                printf("  ");
        }
        printf(" ");
        for (i=0; i<16; i++)
        {
            if ((i&3) == 0)
                printf(" ");
            if (offset+i < size)
            {
                if (buffer1[offset+i] != buffer2[offset+i])
                    printf("\033[7m");
                printf("%02x", 0xff & buffer2[offset+i]);
                printf("\033[0m");
            }
            else
                printf("  ");
        }
        printf("\n");
        offset += 16;
    }
}

static int setup_pcie(int pcie_port)
{
    if (bdk_pcie_ep_initialize(pcie_port))
    {
        RETURN_ON_FAIL(bdk_pcie_rc_initialize(pcie_port));
    }
    else
    {
        #define BAR0_SIZE 16386ull
        #define BAR1_SIZE (64ull<<20)
        #define BAR2_SIZE (1ull<<41)
        #define BAR2_BASE 0ull
        #define BAR1_BASE (BAR2_BASE + BAR2_SIZE)
        #define BAR0_BASE (BAR1_BASE + BAR1_SIZE)

        /* Enable bus master and memory */
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG001(pcie_port), 0x6);

        /* Set BAR0 address */
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG004(pcie_port), 0xc | (uint32_t)BAR0_BASE);
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG005(pcie_port),  BAR0_BASE >> 32);

        /* Set BAR1 address */
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG006(pcie_port), 0xc | (uint32_t)BAR1_BASE);
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG007(pcie_port), BAR1_BASE>>32);
#if 0
        int i;
        /* Configure BAR1 to linearly map the first 64MB */
        for (i=0;i<16;i++)
        {
            bdk_pemx_bar1_indexx_t bar1;
            bar1.u64 = 0;
            bar1.s.end_swp = 1;
            bar1.s.addr_v = 1;
            bar1.s.addr_idx = i;
            BDK_CSR_WRITE(BDK_PEMX_BAR1_INDEXX(i, pcie_port), bar1.u64);
        }
#endif

        /* Enable BAR2 */
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG008_MASK(pcie_port), 0x1);
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG008(pcie_port), 0xc);
        BDK_CSR_READ(BDK_PCIEEPX_CFG008(pcie_port));
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG008_MASK(pcie_port), 0xffffffff & (BAR2_SIZE-1));
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG009_MASK(pcie_port), (BAR2_SIZE-1) >> 32);
        BDK_CSR_READ(BDK_PCIEEPX_CFG009(pcie_port));

        bdk_pemx_bar_ctl_t pemx_bar_ctl;
        pemx_bar_ctl.u64 = BDK_CSR_READ(BDK_PEMX_BAR_CTL(pcie_port));
        pemx_bar_ctl.s.bar2_enb = 1;
        pemx_bar_ctl.s.bar2_cax = 0;
        pemx_bar_ctl.s.bar2_esx = 1;
        BDK_CSR_WRITE(BDK_PEMX_BAR_CTL(pcie_port), pemx_bar_ctl.u64);

        /* Set BAR2 address */
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG008(pcie_port), 0xc | (uint32_t)BAR2_BASE);
        BDK_CSR_WRITE(BDK_PCIEEPX_CFG009(pcie_port), BAR2_BASE>>32);
        BDK_CSR_READ(BDK_PCIEEPX_CFG009(pcie_port));

        bdk_dprintf("BAR0 %#08lx  %08lx\n",
            BDK_CSR_READ(BDK_PCIEEPX_CFG005(pcie_port)),
            BDK_CSR_READ(BDK_PCIEEPX_CFG004(pcie_port)));
        bdk_dprintf("BAR1 %#08lx  %08lx\n",
            BDK_CSR_READ(BDK_PCIEEPX_CFG007(pcie_port)),
            BDK_CSR_READ(BDK_PCIEEPX_CFG006(pcie_port)));
        bdk_dprintf("BAR2 %#08lx  %08lx\n",
            BDK_CSR_READ(BDK_PCIEEPX_CFG009(pcie_port)),
            BDK_CSR_READ(BDK_PCIEEPX_CFG008(pcie_port)));
    }


    BDK_CSR_MODIFY(c, BDK_PEMX_BAR_CTL(pcie_port),
        c.s.bar2_enb = 1;
        c.s.bar2_cax = 0;
        c.s.bar2_esx = 1);

    physical_map[pcie_port] = BAR2_BASE;

    return 0;
}

static uint64_t ptr_to_sli(int pcie_port, void *ptr)
{
    return physical_map[pcie_port] + bdk_ptr_to_phys(ptr);
}


#define MAX_SIZE 4096
#define PER_BUFFER_SIZE (MAX_SIZE * 2)
#define PER_CORE_SIZE (PER_BUFFER_SIZE * 4)
static bdk_spinlock_t lock;

static int wait_for_zero(int engine, const char *label, volatile uint8_t *zero_loc)
{
    uint64_t timeout = bdk_clock_get_count(BDK_CLOCK_CORE) + bdk_clock_get_rate(BDK_CLOCK_CORE) * 8;
    //printf("Waiting for DMA %d\n", engine);
    while (*zero_loc)
    {
        if (bdk_clock_get_count(BDK_CLOCK_CORE) > timeout)
        {
            bdk_spinlock_lock(&lock);
            printf("DMA engine %d %s not complete after 8 seconds\n", engine, label);
            return -1;
        }
    }
    return 0;
}

static int dma_test(int unused1, void *unused2)
{
    volatile uint8_t zero_loc[3];

    srand(bdk_clock_get_count(BDK_CLOCK_CORE) + bdk_get_core_num() * 500);

    void *memory_block = memalign(128, PER_CORE_SIZE);
    if (!memory_block)
    {
        printf("Failed to alloc dma area\n");
        return -1;
    }

    uint8_t *starting_buffer = memory_block;
    uint8_t *dma_out_buffer = starting_buffer + PER_BUFFER_SIZE;
    uint8_t *dma_external_buffer = dma_out_buffer + PER_BUFFER_SIZE;
    uint8_t *dma_in_buffer = dma_external_buffer + PER_BUFFER_SIZE;
    uint64_t zero_base = bdk_ptr_to_phys((void*)&zero_loc);

    int engine = bdk_get_core_num() % bdk_dma_engine_get_num();

    int size;
    int local_align;
    int remote_align;
    for (size=1; size<=MAX_SIZE; size++)
    {
        bdk_spinlock_lock(&lock);
        printf("Core%2d: DMA test %4d bytes\n", bdk_get_core_num(), size);
        bdk_spinlock_unlock(&lock);
        for (local_align=0; local_align<=128; local_align++)
        {
            /* Loop through all possible alignments */
            for (remote_align=0; remote_align<=MAX_SIZE; remote_align++)
            {
                /* Clear all buffers with unique patterns */
                memset(starting_buffer, 0xaa, PER_BUFFER_SIZE);
                memset(dma_out_buffer, 0xbb, PER_BUFFER_SIZE);
                memset(dma_external_buffer, 0xcc, PER_BUFFER_SIZE);
                memset(dma_in_buffer, 0xdd, PER_BUFFER_SIZE);

                /* Fill source block with random data */
                for (int i=0;i<size;i++)
                    starting_buffer[i + local_align] = rand();

                zero_loc[0] = -1;
                zero_loc[1] = -1;
                zero_loc[2] = -1;

                /* DMA the starting_buffer to dma_out_buffer */
                bdk_dma_engine_header_t dma_header;
                dma_header.u64 = 0;
                dma_header.s.fport = 0;
                dma_header.s.lport = 0;
                dma_header.s.type = BDK_DMA_ENGINE_TRANSFER_OUTBOUND;
                dma_header.s.addr = zero_base + 0;
                if (bdk_unlikely(bdk_dma_engine_transfer(engine, dma_header,
                                         bdk_ptr_to_phys(starting_buffer + local_align),
                                         ptr_to_sli(dma_header.s.lport, dma_out_buffer + remote_align), size)))
                {
                    bdk_spinlock_lock(&lock);
                    printf("DMA OUTBOUND submit failed\n");
                    return -1;
                }

                if (wait_for_zero(engine, "OUTBOUND", &zero_loc[0]))
                    goto fail;

                /* DMA dma_out_buffer to dma_external_buffer */
                dma_header.s.type = BDK_DMA_ENGINE_TRANSFER_EXTERNAL;
                dma_header.s.fport = 0;
                dma_header.s.lport = 1;
                dma_header.s.addr = zero_base + 1;
                if (bdk_unlikely(bdk_dma_engine_transfer(engine, dma_header,
                    ptr_to_sli(dma_header.s.fport, dma_out_buffer + remote_align),
                    ptr_to_sli(dma_header.s.lport, dma_external_buffer + remote_align), size)))
                {
                    bdk_spinlock_lock(&lock);
                    printf("DMA EXTERNAL submit failed\n");
                    return -1;
                }

                if (wait_for_zero(engine, "EXTERNAL", &zero_loc[1]))
                    goto fail;

                /* DMA dma_external_buffer to dma_in_buffer */
                dma_header.s.type = BDK_DMA_ENGINE_TRANSFER_INBOUND;
                dma_header.s.fport = 0;
                dma_header.s.lport = 1;
                dma_header.s.addr = zero_base + 2;
                if (bdk_unlikely(bdk_dma_engine_transfer(engine, dma_header,
                    bdk_ptr_to_phys(dma_in_buffer + local_align),
                    ptr_to_sli(dma_header.s.lport, dma_external_buffer + remote_align), size)))
                {
                    bdk_spinlock_lock(&lock);
                    printf("DMA INBOUND submit failed\n");
                    return -1;
                }

                if (wait_for_zero(engine, "INBOUND", &zero_loc[2]))
                    goto fail;

                /* Check that none of the bytes before the transfer were changed */
                for (int i=0; i<local_align; i++)
                {
                    if (bdk_unlikely(starting_buffer[i] != 0xaa))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("starting_buffer prefix not 0xaa\n");
                        goto fail;
                    }
                    if (bdk_unlikely(dma_in_buffer[i] != 0xdd))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("dma_in_buffer prefix not 0xaa\n");
                        goto fail;
                    }
                }
                for (int i=0; i<remote_align; i++)
                {
                    if (bdk_unlikely(dma_out_buffer[i] != 0xbb))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("dma_out_buffer prefix not 0xbb\n");
                        goto fail;
                    }
                    if (bdk_unlikely(dma_external_buffer[i] != 0xcc))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("dma_external_buffer prefix not 0xcc\n");
                        goto fail;
                    }
                }

                /* Check that none of the bytes after the transfer were changed */
                for (int i=local_align+size; i<PER_BUFFER_SIZE; i++)
                {
                    if (bdk_unlikely(starting_buffer[i] != 0xaa))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("starting_buffer end not 0xaa\n");
                        goto fail;
                    }
                    if (bdk_unlikely(dma_in_buffer[i] != 0xdd))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("dma_in_buffer end not 0xaa\n");
                        goto fail;
                    }
                }
                for (int i=remote_align+size; i<PER_BUFFER_SIZE; i++)
                {
                    if (bdk_unlikely(dma_out_buffer[i] != 0xbb))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("dma_out_buffer end not 0xbb\n");
                        goto fail;
                    }
                    if (bdk_unlikely(dma_external_buffer[i] != 0xcc))
                    {
                        bdk_spinlock_lock(&lock);
                        printf("dma_external_buffer end not 0xcc\n");
                        goto fail;
                    }
                }

                /* Check that the source and dest 2 match */
                if (bdk_unlikely(memcmp(starting_buffer + local_align, dma_in_buffer + local_align, size)))
                {
                    bdk_spinlock_lock(&lock);
                    printf("local_source != local_dest2\n");
                    goto fail;
                }
            }
        }
    }
    bdk_spinlock_lock(&lock);
    printf("Done\n");
    bdk_spinlock_unlock(&lock);
    return 0;

fail:
    printf("DMA test %d bytes, local=%d, remote=%d\n", size, local_align, remote_align);
    if (bdk_unlikely(memcmp(starting_buffer + local_align, dma_out_buffer + remote_align, size)))
        hex_compare("Original", "After OUTBOUND", starting_buffer + local_align, dma_out_buffer + remote_align, size);
    if (bdk_unlikely(memcmp(starting_buffer + local_align, dma_external_buffer + remote_align, size)))
        hex_compare("Original", "After EXTERNAL", starting_buffer + local_align, dma_external_buffer + remote_align, size);
    if (bdk_unlikely(memcmp(starting_buffer + local_align, dma_in_buffer + local_align, size)))
        hex_compare("Original", "After INBOUND", starting_buffer + local_align, dma_in_buffer + local_align, size);
    //bdk_spinlock_unlock(&lock);
    return -1;
}

int main()
{
    /* Disable reset on loss of link or prst*/
    BDK_CSR_MODIFY(c, BDK_MIO_RST_CTLX(0),
        c.s.rst_link = 0;
        c.s.rst_chip = 0);
    BDK_CSR_MODIFY(c, BDK_MIO_RST_CTLX(1),
        c.s.rst_link = 0;
        c.s.rst_chip = 0);

    bdk_fpa_enable();
    RETURN_ON_FAIL(bdk_fpa_fill_pool(BDK_FPA_OUTPUT_BUFFER_POOL, 16));
    RETURN_ON_FAIL(bdk_dma_engine_initialize());

    //bdk_qlm_cn6xxx_force_link(0);
    //bdk_qlm_cn6xxx_force_link(1);

    RETURN_ON_FAIL(setup_pcie(0));
    RETURN_ON_FAIL(setup_pcie(1));

    printf("Setup complete\n");
    printf("Starting all cores\n");
    bdk_init_cores(0);
    int num_cores = bdk_octeon_num_cores();
    for (int core=0; core<num_cores; core++)
    {
        if (bdk_thread_create(1ull<<core, (bdk_thread_func_t)dma_test, 0, NULL, 0))
            bdk_error("Failed to create thread for core %d\n", core);
    }
}
