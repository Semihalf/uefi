#include <bdk.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_LINKS 3
typedef struct
{
    bdk_ocx_com_node_t      node;                    /* Node ID at end of link */
    bdk_ocx_com_linkx_ctl_t ctl[MAX_LINKS];          /* Remote node link info */
    uint64_t                unique_value[MAX_LINKS]; /* Unique values received over links */
} lk_info_t;

static int64_t __bdk_alive_coremask[BDK_NUMA_MAX_NODES];
int __bdk_is_simulation;

/**
 * Set the baud rate on a UART
 *
 * @param uart     uart to set
 * @param baudrate Baud rate (9600, 19200, 115200, etc)
 * @param use_flow_control
 *                 Non zero if hardware flow control should be enabled
 */
void bdk_set_baudrate(bdk_node_t node, int uart, int baudrate, int use_flow_control)
{
    /* 1.2.1 Initialization Sequence (Power-On/Hard/Cold Reset) */
    /* 1. Wait for IOI reset (srst_n) to deassert. */
    /* 2. Assert all resets:
        a. UAA reset: UCTL_CTL[UAA_RST] = 1
        b. UCTL reset: UCTL_CTL[UCTL_RST] = 1  */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart),
        c.s.uaa_rst = 1;
        c.s.uctl_rst = 1);

    /* 3. Configure the HCLK:
        a. Reset the clock dividers: UCTL_CTL[H_CLKDIV_RST] = 1.
        b. Select the HCLK frequency
            i. UCTL_CTL[H_CLKDIV] = desired value,
            ii. UCTL_CTL[H_CLKDIV_EN] = 1 to enable the HCLK.
            iii. Readback UCTL_CTL to ensure the values take effect.
        c. Deassert the HCLK clock divider reset: UCTL_CTL[H_CLKDIV_RST] = 0. */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart),
        c.s.h_clkdiv_sel = 3; /* Run at SCLK / 6, matches emulator */
        c.s.h_clk_byp_sel = 0;
        c.s.h_clk_en = 1);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart),
        c.s.h_clkdiv_rst = 0);

    /* 4. Wait 20 HCLK cycles from step 3 for HCLK to start and async fifo
       to properly reset. */
    bdk_wait(200); /* Overkill */

    /* 5. Deassert UCTL and UAHC resets:
        a. UCTL_CTL[UCTL_RST] = 0
        b. Wait 10 HCLK cycles.
        c. UCTL_CTL[UAHC_RST] = 0
        d. You will have to wait 10 HCLK cycles before accessing any
            HCLK-only registers. */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart), c.s.uctl_rst = 0);
    bdk_wait(100); /* Overkill */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart), c.s.uaa_rst = 0);
    bdk_wait(100); /* Overkill */

    /* 6. Enable conditional SCLK of UCTL by writing UCTL_CTL[CSCLK_EN] = 1. */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart), c.s.csclk_en = 1);

    /* 7. Initialize the integer and fractional baud rate divider registers
        UARTIBRD and UARTFBRD as follows:
        a. Baud Rate Divisor = UARTCLK/(16xBaud Rate) = BRDI + BRDF
        b. The fractional register BRDF, m is calculated as integer(BRDF x 64 + 0.5)
        Example calculation:
            If the required baud rate is 230400 and hclk = 4MHz then:
                Baud Rate Divisor = (4x10^6)/(16x230400) = 1.085
                This means BRDI = 1 and BRDF = 0.085.
                Therefore, fractional part, BRDF = integer((0.085x64)+0.5) = 5
                Generated baud rate divider = 1+5/64 = 1.078 */
#ifdef HW_EMULATOR
    #warning Configured for the hardware emulator
    /* The hardware emulator currently fixes the uart at a fixed rate */
    uint64_t divisor_x_64 = 64;
#else
    uint64_t divisor_x_64 = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / (baudrate * 16 * 6 / 64);
#endif
    BDK_CSR_MODIFY(c, node, BDK_UAAX_IBRD(uart),
        c.s.baud_divint = divisor_x_64 >> 6);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_FBRD(uart),
        c.s.baud_divfrac = divisor_x_64 & 0x3f);

    /* 8. Program the line control register UAA(0..1)_LCR_H and the control
       register UAA(0..1)_CR */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_LCR_H(uart),
        c.s.sps = 0; /* No parity */
        c.s.wlen = 3; /* 8 bits */
        c.s.fen = 1; /* FIFOs enabled */
        c.s.stp2 = 0; /* Use one stop bit, not two */
        c.s.eps = 0; /* No parity */
        c.s.pen = 0; /* No parity */
        c.s.brk = 0); /* Don't send a break */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_CR(uart),
        c.s.ctsen = use_flow_control;
        c.s.rtsen = use_flow_control;
        c.s.out1 = 1; /* Drive data carrier detect */
        c.s.rts = 0; /* Don't override RTS */
        c.s.dtr = 0; /* Don't override DTR */
        c.s.rxe = 1; /* Enable receive */
        c.s.txe = 1; /* Enable transmit */
        c.s.lbe = 0; /* Disable loopback */
        c.s.uarten = 1); /* Enable uart */
}

void __bdk_init(uint32_t image_crc) __attribute((noreturn));
void __bdk_init(uint32_t image_crc)
{
    extern void __bdk_exception_current_el_sync_sp0();
    BDK_MSR(VBAR_EL3, __bdk_exception_current_el_sync_sp0);
    BDK_MSR(VBAR_EL2, __bdk_exception_current_el_sync_sp0);
    BDK_MSR(VBAR_EL1, __bdk_exception_current_el_sync_sp0);

    /* Use Cavium specific function to change memory to normal instead of
       device attributes */
    bdk_sys_cvmmemctl0_el1_t cvmmemctl0_el1;
    BDK_MRS(s3_0_c11_c0_4, cvmmemctl0_el1.u);
    cvmmemctl0_el1.s.dcva47 = 1;
    BDK_MSR(s3_0_c11_c0_4, cvmmemctl0_el1.u);


    /* Setup running with no mmu */
    bdk_sys_sctlr_elx_t sctlr_el3;
    BDK_MRS(SCTLR_EL3, sctlr_el3.u);
    sctlr_el3.s.ee = 0; /* Little endian */
    sctlr_el3.s.wxn = 0; /* No write perm changes */
    sctlr_el3.s.i = 1;  /* Enable Icache */
    sctlr_el3.s.sa = 1; /* Enable stack alignment checking */
    sctlr_el3.s.c = 1; /* Enable Dcache */
    sctlr_el3.s.a = 0; /* Allow unaligned accesses */
    sctlr_el3.s.m = 0; /* Disable MMU */
    BDK_MSR(SCTLR_EL3, sctlr_el3.u);

    bdk_node_t node = bdk_numa_local();
    bdk_numa_set_running(node);

    static const char BANNER_1[] = "Cavium THUNDERX\n";
    static const char BANNER_2[] = "Locking L2 cache\n";
    static const char BANNER_CRC_RIGHT[] = "PASS: CRC32 verification\n";
    static const char BANNER_CRC_WRONG[] = "FAIL: CRC32 verification\n";
    static const char BANNER_3[] = "Transferring to thread scheduler\n";

    BDK_MSR(TPIDR_EL3, 0);

    if (bdk_is_boot_core())
    {
        /* Shut off cores in reset to save power. It is optional, but probably
            good practice */
        // FIXME: Core power control disabled as it causes issues with JTAG
        //BDK_CSR_WRITE(node, BDK_RST_PP_POWER, -1);

        /* Initialize the is_simulation flag */
        BDK_CSR_INIT(c, node, BDK_OCLAX_CONST(0));
        __bdk_is_simulation = (c.u == 0);

        /* Enable the timer */
        BDK_MSR(CNTFRQ_EL0, BDK_GTI_RATE); /* Needed for Asim */
        bdk_clock_setup(node);

        /* Only setup the uarts if they haven't been already setup */
        BDK_CSR_INIT(uctl_ctl0, node, BDK_UAAX_UCTL_CTL(0));
        if (!uctl_ctl0.s.h_clk_en)
            bdk_set_baudrate(node, 0, BDK_UART_BAUDRATE, 0);
        BDK_CSR_INIT(uctl_ctl1, node, BDK_UAAX_UCTL_CTL(1));
        if (!uctl_ctl1.s.h_clk_en)
            bdk_set_baudrate(node, 1, BDK_UART_BAUDRATE, 0);

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_1, sizeof(BANNER_1)-1);

        /* Only lock L2 if DDR3 isn't initialized */
        if (!__bdk_is_dram_enabled(node) && !bdk_is_simulation())
        {
            if (BDK_TRACE_ENABLE_INIT)
                write(1, BANNER_2, sizeof(BANNER_2)-1);
            bdk_l2c_lock_mem_region(node, bdk_numa_get_address(node, 0), bdk_l2c_get_cache_size_bytes(node) * 3 / 4);
            /* The locked region isn't considered dirty by L2. Do read
               read/write of each cache line to force each to be dirty */
            volatile uint8_t *ptr = bdk_phys_to_ptr(bdk_numa_get_address(node, 1));
            uint8_t *end = bdk_phys_to_ptr(bdk_numa_get_address(node, bdk_l2c_get_cache_size_bytes(node)));
            while (ptr < end)
            {
                *ptr = *ptr;
                ptr += 128;
            }
            /* The above locking will cause L2 to load zeros without DRAM setup.
                This will cause L2C_TADX_INT[rddislmc], which we suppress below */
            BDK_CSR_DEFINE(l2c_tadx_int, BDK_L2C_TADX_INT_W1C(0));
            l2c_tadx_int.u = 0;
            l2c_tadx_int.s.rddislmc = 1;
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(0), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(1), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(2), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(3), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(4), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(5), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(6), l2c_tadx_int.u);
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(7), l2c_tadx_int.u);
        }

        /* Validate the image CRC */
        extern void _start();
        uint32_t *ptr_crc32 = (uint32_t *)(_start + 16);
        uint32_t correct_crc = *ptr_crc32;
        if (correct_crc == image_crc)
            write(1, BANNER_CRC_RIGHT, sizeof(BANNER_CRC_RIGHT) - 1);
        else
            write(1, BANNER_CRC_WRONG, sizeof(BANNER_CRC_WRONG) - 1);

        if (BDK_TRACE_ENABLE_INIT)
            write(1, BANNER_3, sizeof(BANNER_3)-1);
        bdk_thread_initialize();
    }

    /* Enable the core timer */
    BDK_MSR(CNTFRQ_EL0, BDK_GTI_RATE); /* Needed for Asim */
    bdk_sys_cntps_ctl_el1_t cntps_ctl_el1;
    cntps_ctl_el1.u = 0;
    cntps_ctl_el1.s.imask = 1;
    cntps_ctl_el1.s.enable = 1;
    BDK_MSR(CNTPS_CTL_EL1, cntps_ctl_el1.u);

    /* Setup an exception stack in case we crash */
    int EX_STACK_SIZE = 16384;
    void *exception_stack = malloc(EX_STACK_SIZE);
    extern void __bdk_init_exception_stack(void *ptr);
    __bdk_init_exception_stack(exception_stack + EX_STACK_SIZE);

    bdk_atomic_add64(&__bdk_alive_coremask[node], bdk_core_to_mask());
    bdk_thread_first(__bdk_init_main, 0, NULL, 0);
}

int bdk_init_cores(bdk_node_t node, uint64_t coremask)
{
    extern void __bdk_start_cores();
    /* Write the address of the main entry point */
    BDK_TRACE(INIT, "N%d: Setting address for boot jump\n", node);
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_AP_JUMP, (uint64_t)__bdk_start_cores);

    /* Choose all cores by default */
    if (coremask == 0)
        coremask = -1;

    /* Limit to the cores that aren't already running */
    coremask &= ~__bdk_alive_coremask[node];

    /* Limit to the cores that are specified in configuration menu */
    uint64_t config_coremask = bdk_config_get(BDK_CONFIG_COREMASK);
    if (config_coremask)
        coremask &= config_coremask;

    /* Limit to the cores that exist */
    coremask &= (1ull<<bdk_get_num_cores(node)) - 1;

    uint64_t reset = BDK_CSR_READ(node, BDK_RST_PP_RESET);
    BDK_TRACE(INIT, "N%d: Cores currently in reset: 0x%lx\n", node, reset);
    uint64_t need_reset_off = reset & coremask;
    if (need_reset_off)
    {
        BDK_TRACE(INIT, "N%d: Taking cores out of reset (0x%lx)\n", node, need_reset_off);
        BDK_CSR_WRITE(node, BDK_RST_PP_RESET, reset & ~need_reset_off);
    }

    BDK_TRACE(INIT, "N%d: Wait up to 1s for the cores to boot\n", node);
    uint64_t timeout = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME) + bdk_clock_get_count(BDK_CLOCK_TIME);
    while ((bdk_clock_get_count(BDK_CLOCK_TIME) < timeout) && ((bdk_atomic_get64(&__bdk_alive_coremask[node]) & coremask) != coremask))
    {
        /* Tight spin, no thread schedules */
    }

    if ((bdk_atomic_get64(&__bdk_alive_coremask[node]) & coremask) != coremask)
    {
        bdk_error("Node %d: Some cores failed to start. Alive mask 0x%lx, requested 0x%lx\n",
            node, __bdk_alive_coremask[node], coremask);
        return -1;
    }
    BDK_TRACE(INIT, "N%d: All cores booted\n", node);
    return 0;
}

/**
 * Put cores back in reset and power them down
 *
 * @param node     Node to update
 * @param coremask Each bit will be a core put in reset. Cores already in reset are unaffected
 *
 * @return Zero on success, negative on failure
 */
int bdk_reset_cores(bdk_node_t node, uint64_t coremask)
{
    extern void __bdk_reset_thread(int arg1, void *arg2);

    /* Limit to the cores that exist */
    coremask &= (1ull<<bdk_get_num_cores(node)) - 1;

    /* Update which cores are in reset */
    uint64_t reset = BDK_CSR_READ(node, BDK_RST_PP_RESET);
    BDK_TRACE(INIT, "N%d: Cores currently in reset: 0x%lx\n", node, reset);
    coremask &= ~reset;
    BDK_TRACE(INIT, "N%d: Cores to put into reset: 0x%lx\n", node, coremask);

    /* Check if everything is already done */
    if (coremask == 0)
        return 0;

    int num_cores = bdk_get_num_cores(node);
    for (int core = 0; core < num_cores; core++)
    {
        uint64_t my_mask = 1ull << core;
        /* Skip cores not in mask */
        if ((coremask & my_mask) == 0)
            continue;
        BDK_TRACE(INIT, "N%d: Telling core %d to go into reset\n", node, core);
        if (bdk_thread_create(node, my_mask, __bdk_reset_thread, 0, NULL, 0))
        {
            bdk_error("Failed to create thread for putting core in reset");
            continue;
        }
        /* Clear the core in the alive mask */
        __atomic_fetch_and(&__bdk_alive_coremask[node], ~my_mask, __ATOMIC_ACQ_REL);
    }

    BDK_TRACE(INIT, "N%d: Waiting for all reset bits to be set\n", node);
    uint64_t timeout = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME) + bdk_clock_get_count(BDK_CLOCK_TIME);
    while (bdk_clock_get_count(BDK_CLOCK_TIME) < timeout)
    {
        reset = BDK_CSR_READ(node, BDK_RST_PP_RESET);
        if ((reset & coremask) == coremask)
            break;
        bdk_thread_yield();
    }

    BDK_TRACE(INIT, "N%d: Cores now in reset: 0x%lx\n", node, reset);

    return ((reset & coremask) == coremask) ? 0 : -1;
}

/**
 * During OCX link enumeration, we need to write unique values to
 * OCX_TLKX_LNK_DATA so that we can determine which links connects
 * to which node. This function creates these unique values. When
 * making values for the local node, use local_link as -1.
 *
 * @param local_link The node where we write the value is connected to "local_link". If we're
 *                   working on the local node, use -1.
 * @param remote_link
 *                   Which link on the remote node is this value for (0-3)
 *
 * @return Unique value that can be sent using OCX_TLKX_LNK_DATA, then received with
 *         OCX_RLKX_LNK_DATA.
 */
static inline uint64_t ocx_unique_key(int local_link, int remote_link)
{
    uint64_t result = 0xabcdull << 32;
    result |= (local_link & 0xff) << 16;
    result |= remote_link & 0xff;
    return result;
}

/**
 * Return if the link at the suplied index points to a node that we've already
 * discovered. This happens if two links connect to the same node for more
 * bandwidth.
 *
 * @param unique_value
 *               Conenction data for finding nodes
 * @param index  Index into unique_value that we are seeing if its a duplicate
 *
 * @return Index of the duplicate or -1 if its not a duplicate
 */
static int ocx_duplicate_node(lk_info_t *lk_info, int index)
{
    for (int link = 0; link < index; link++)
    {
        if ((lk_info[link].unique_value[0] == lk_info[index].unique_value[0]) &&
            (lk_info[link].unique_value[1] == lk_info[index].unique_value[1]) &&
            (lk_info[link].unique_value[2] == lk_info[index].unique_value[2]))
            return link;
    }
    return -1;
}

/**
 * This function reads CSRs for a remote node before OCX is completely
 * setup. It should be used during node bringup, but not after L2 is aware of
 * the other nodes.
 *
 * @param node    Node ID to read from
 * @param address CSR address to read
 *
 * @return Value read
 */
static uint64_t ocx_pp_read(bdk_node_t node, uint64_t address)
{
    address = bdk_numa_get_address(node, address);

    if (node == bdk_numa_local())
    {
        return bdk_read64_uint64(address);
    }
    else
    {
        BDK_CSR_DEFINE(pp_cmd, BDK_OCX_PP_CMD);
        pp_cmd.u = 0;
        pp_cmd.s.ld_cmd = 3; /* 8 byte load */
        pp_cmd.s.ld_op = 1;
        pp_cmd.s.addr = address;
        BDK_CSR_WRITE(bdk_numa_local(), BDK_OCX_PP_RD_DATA, -1);
        BDK_CSR_WRITE(bdk_numa_local(), BDK_OCX_PP_CMD, pp_cmd.u);

        /* Wait for 1ms for read ot complete */
        if (BDK_CSR_WAIT_FOR_FIELD(bdk_numa_local(), BDK_OCX_PP_RD_DATA, data, !=, 0xffffffffffffffffull, 1000))
            return -1;
        return BDK_CSR_READ(bdk_numa_local(), BDK_OCX_PP_RD_DATA);
    }
}

/**
 * This function writes CSRs for a remote node before OCX is completely
 * setup. It should be used during node bringup, but not after L2 is aware of
 * the other nodes.
 *
 * @param node    Node ID to write to
 * @param address CSR address to write
 * @param data    Data to write
 */
static void ocx_pp_write(bdk_node_t node, uint64_t address, uint64_t data)
{
    address = bdk_numa_get_address(node, address);

    if (node == bdk_numa_local())
    {
        bdk_write64_uint64(address, data);
    }
    else
    {
        BDK_CSR_DEFINE(pp_cmd, BDK_OCX_PP_CMD);
        pp_cmd.u = 0;
        pp_cmd.s.wr_mask = 0xff;
        pp_cmd.s.addr = address;
        BDK_CSR_WRITE(bdk_numa_local(), BDK_OCX_PP_WR_DATA, data);
        BDK_CSR_WRITE(bdk_numa_local(), BDK_OCX_PP_CMD, pp_cmd.u);
    }
}

static void clear_oci_error(bdk_node_t node)
{
    /* Clear all link error counts */
    for (int link=0; link<3; link++)
        BDK_CSR_WRITE(node, BDK_OCX_TLKX_STAT_ERR_CNT(link), 0);

    /* Clear all local OCI error status bits */
    BDK_CSR_WRITE(node, BDK_OCX_COM_INT, BDK_CSR_READ(node, BDK_OCX_COM_INT));

    /* Clear all local OCI link error status bits */
    for (int link=0; link<3; link++)
        BDK_CSR_WRITE(node, BDK_OCX_COM_LINKX_INT(link), BDK_CSR_READ(node, BDK_OCX_COM_LINKX_INT(link)));

    /* Enable the OCX lane counters across all lanes. This way they count
       errors that happen during our init */
    /* Clear all OCI lane error status bits */
    for (int lane=0; lane<24; lane++)
    {
        BDK_CSR_MODIFY(c, node, BDK_OCX_LNEX_CFG(lane),
            c.s.rx_stat_wrap_dis = 1;
            c.s.rx_stat_ena = 1);
        BDK_CSR_WRITE(node, BDK_OCX_LNEX_INT(lane), BDK_CSR_READ(node, BDK_OCX_LNEX_INT(lane)));
    }
}

/**
 * Report the OCI/CCPI lane status for all lanes
 *
 * @param node   Node to report for
 */
static int oci_report_lane(bdk_node_t node)
{
    int num_good = 0;
    printf("N%d.CCPI Lanes([] is good):", node);
    for (int lane=0; lane<24; lane++)
    {
        BDK_CSR_INIT(lne_status, node, BDK_OCX_LNEX_STATUS(lane));
        int good = lne_status.s.rx_bdry_sync && lne_status.s.rx_scrm_sync;
        num_good += good;
        if (good)
            printf("[%d]", lane);
        else
            printf(" %d", lane);
    }
    printf("\n");
    return num_good;
}

/**
 * Initialize the OCI so all Nodes are ready to be used
 *
 * @return Zero on success, negative on failure.
 */
static int init_oci(void)
{
#ifdef HW_EMULATOR
    return 0; /* Emulator doesn't seem to have CCPI registers */
#endif

    /* Don't bringup CCPI if there are no valid lanes */
    int good_lanes = oci_report_lane(bdk_numa_master());
    if (good_lanes == 0)
        return 0;
    /* Don't bringup CCPI if there are less than 8 lanes */
    if (good_lanes < 8)
    {
        printf("N%d.CCPI Less than 8 good lanes, not initializing multi-node\n", bdk_numa_master());
        return 0;
    }

    /* Index MAX_LINKS is used for the local node */
    const int LOCAL_NODE = MAX_LINKS;
    lk_info_t lk_info[MAX_LINKS + 1];
    memset(lk_info, 0, sizeof(lk_info));

    /* Only one node should be up (the one I'm on). Set its ID to be fixed. As
       part of booting the BDK we've already added it to both the exists and
       running node masks */
    BDK_CSR_INIT(ocx_com_node, bdk_numa_local(), BDK_OCX_COM_NODE);
    if (ocx_com_node.s.fixed)
    {
        BDK_TRACE(INIT, "Current node ID %d is already marked fixed\n", bdk_numa_local());
    }
    else
    {
        BDK_TRACE(INIT, "Marking the current node ID %d as fixed\n", bdk_numa_local());
        BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_OCX_COM_NODE,
            c.s.fixed = 1);
    }

    /* Reset if any link goes down */
    BDK_CSR_WRITE(bdk_numa_local(), BDK_RST_OCX, bdk_build_mask(MAX_LINKS));

    /* Write a unique value to OCX_TLKX_LNK_DATA for every possible link. This
        allows us to later figure out which link goes where. Also mark all
        link as unrecoverable so its state can't change later */
    BDK_TRACE(INIT, "Loop through local links sending unique values over OCX_TLKX_LNK_DATA\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        /* Errata (OCX-22951) OCX AUTO_CLR of DROP fails to work on error */
        /* Don't allow this link to recover if it goes down. Once up links
           should stay up */
        BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link),
            c.s.auto_clr = 0);
        /* Get the link state again. It could have changed during the
           modification of AUTO_CLR */
        lk_info[LOCAL_NODE].ctl[link].u = BDK_CSR_READ(bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link));
        /* Skip invalid links */
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
        {
            BDK_TRACE(INIT, "    Local link %d: Down, skipping\n", link);
            continue;
        }
        /* Write a unique value so we can see where this link connects to */
        uint64_t local_unique = ocx_unique_key(-1, link);
        BDK_CSR_WRITE(bdk_numa_local(), BDK_OCX_TLKX_LNK_DATA(link), local_unique);
        BDK_TRACE(INIT, "    Local link %d: Write link data 0x%lx\n", link, local_unique);
        const int rid = lk_info[LOCAL_NODE].ctl[link].s.id;
        /* Loop through possible remote links */
        for (int rlink = 0; rlink < MAX_LINKS; rlink++)
        {
            bdk_ocx_com_linkx_ctl_t *lnk = &lk_info[link].ctl[rlink];
            /* Read the links state and make sure it doesn't auto recover from
               errors*/
            lnk->u = ocx_pp_read(rid, BDK_OCX_COM_LINKX_CTL(rlink));
            if (lnk->u == (uint64_t)-1)
            {
                BDK_TRACE(INIT, "        Remote link %d: Timeout, skipping\n", rlink);
                continue;
            }
            lnk->s.auto_clr = 0;
            ocx_pp_write(rid, BDK_OCX_COM_LINKX_CTL(rlink), lnk->u);
            /* Skip invalid links */
            if (!lnk->s.valid || !lnk->s.up || lnk->s.drop)
            {
                BDK_TRACE(INIT, "        Remote link %d: Down, skipping\n", rlink);
                continue;
            }
            /* Write a unique value so we can see where the remote link
               connects to */
            uint64_t remote_unique = ocx_unique_key(link, rlink);
            BDK_TRACE(INIT, "        Remote link %d: Write link data 0x%lx\n", rlink, remote_unique);
            ocx_pp_write(rid, BDK_OCX_TLKX_LNK_DATA(rlink), remote_unique);
        }
    }

    BDK_TRACE(INIT, "Reading link data for all links\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
            continue;
        lk_info[LOCAL_NODE].unique_value[link] = BDK_CSR_READ(bdk_numa_local(), BDK_OCX_RLKX_LNK_DATA(link));
        BDK_TRACE(INIT, "    Local link %d: Read link data 0x%lx\n", link, lk_info[LOCAL_NODE].unique_value[link]);
        const int rid = lk_info[LOCAL_NODE].ctl[link].s.id;
        for (int rlink = 0; rlink < MAX_LINKS; rlink++)
        {
            lk_info[link].unique_value[rlink] = ocx_pp_read(rid, BDK_OCX_RLKX_LNK_DATA(rlink));
            BDK_TRACE(INIT, "        Remote link %d: Read link data 0x%lx\n", rlink, lk_info[link].unique_value[rlink]);
            if (lk_info[link].unique_value[rlink] == 0xffffffffffffffffull)
            {
                BDK_TRACE(INIT, "            Invalid link data, marking link invalid\n");
                lk_info[LOCAL_NODE].ctl[link].s.valid = 0;
                continue;
            }
        }
        lk_info[link].node.u = ocx_pp_read(rid, BDK_OCX_COM_NODE);
    }

    BDK_TRACE(INIT, "Finding fixed node IDs\n");
    /* Loop through once reserving all fixed node IDs */
    for (int link = 0; link < MAX_LINKS; link++)
    {
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
            continue;
        if (ocx_duplicate_node(lk_info, link) != -1)
        {
            BDK_TRACE(INIT, "    Local link %d: Duplicate node, skipping\n", link);
            continue;
        }
        if (lk_info[link].node.s.fixed)
        {
            int rid = lk_info[link].node.s.id;
            /* Mark fixed nodes as existing so we don't reuse their node ID */
            if (bdk_numa_exists(rid))
            {
                bdk_error("Fixed ID %d conflicts with existing node, not starting OCI\n", rid);
                return -1;
            }
            bdk_numa_set_exists(rid);
            BDK_TRACE(INIT, "    Local link %d: Fixed node ID %d\n", link, rid);
        }
    }

    BDK_TRACE(INIT, "Assigning node IDs\n");
    /* Loop through again finding node IDs for unassigned nodes */
    for (int link = 0; link < MAX_LINKS; link++)
    {
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
            continue;
        int dup = ocx_duplicate_node(lk_info, link);
        if (dup != -1)
        {
            BDK_TRACE(INIT, "    Local link %d: Duplicate node, skipping\n", link);
            lk_info[link].node = lk_info[dup].node;
            continue;
        }
        if (!lk_info[link].node.s.fixed)
        {
            /* Find a clear exists bit */
            bdk_node_t node;
            for (node = 0; node < BDK_NUMA_MAX_NODES; node++)
            {
                if (!bdk_numa_exists(node))
                    break;
            }
            if (node >= BDK_NUMA_MAX_NODES)
                bdk_fatal("Somehow we found more nodes than we support. Skipping new node");
            bdk_numa_set_exists(node);
            lk_info[link].node.s.fixed = 1;
            lk_info[link].node.s.id = node;
            BDK_TRACE(INIT, "    Local link %d: Assigned node ID %d\n", link, node);
        }
    }

    /* Find an unused node number. This will be used for links that are down */
    bdk_node_t unused_node;
    for (unused_node = 0; unused_node < BDK_NUMA_MAX_NODES; unused_node++)
    {
        if (!bdk_numa_exists(unused_node))
            break;
    }

    BDK_TRACE(INIT, "Determining which node each link connects to\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
        {
            lk_info[link].node.s.id = unused_node;
            continue;
        }
        BDK_TRACE(INIT, "    Local link %d: Searching remote links\n", link);
        for (int rlink = 0; rlink < MAX_LINKS; rlink++)
        {
            if (!lk_info[link].ctl[rlink].s.valid || !lk_info[link].ctl[rlink].s.up)
            {
                lk_info[link].ctl[rlink].s.id = unused_node;
                continue;
            }
            uint64_t search = lk_info[link].unique_value[rlink] & 0xfffffffffffffffull;
            //BDK_TRACE(INIT, "        Remote link %d: Looking for 0x%lx\n", rlink, search);
            int found = 0;
            for (int ll = -1; ll < MAX_LINKS; ll++)
            {
                for (int rl = 0; rl < MAX_LINKS; rl++)
                {
                    uint64_t runique = ocx_unique_key(ll, rl);
                    //BDK_TRACE(INIT, "        Checking [%d][%d] 0x%lx\n", ll, rl, runique);
                    if (search == runique)
                    {
                        int node2 = (ll==-1) ? bdk_numa_local() : lk_info[ll].node.s.id;
                        BDK_TRACE(INIT, "        Node ID %d, link %d => Node ID %d, link %d\n",
                            lk_info[link].node.s.id, rlink, node2, rl);
                        lk_info[link].ctl[rlink].s.id = node2;
                        found = 1;
                    }
                }
            }
            if (!found)
            {
                BDK_TRACE(INIT, "        Node ID %d, link %d => Unknown\n",
                    lk_info[link].node.s.id, rlink);
            }
        }
    }

    BDK_TRACE(INIT, "Programming remote links and node IDs\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
            continue;
        if (ocx_duplicate_node(lk_info, link) != -1)
        {
            BDK_TRACE(INIT, "    Local link %d: Duplicate node, skipping\n", link);
            continue;
        }
        BDK_TRACE(INIT, "    Local link %d: Assign node ID %d\n", link, lk_info[link].node.s.id);
        const int rid = lk_info[LOCAL_NODE].ctl[link].s.id;
        ocx_pp_write(rid, BDK_OCX_COM_NODE, lk_info[link].node.u);
        for (int rlink = 0; rlink < MAX_LINKS; rlink++)
        {
            if (!lk_info[link].ctl[rlink].s.valid || !lk_info[link].ctl[rlink].s.up)
                BDK_TRACE(INIT, "        Remote link %d: Down\n", rlink);
            else
                BDK_TRACE(INIT, "        Remote link %d: Connects to node ID %d\n", rlink, lk_info[link].ctl[rlink].s.id);
            ocx_pp_write(rid, BDK_OCX_COM_LINKX_CTL(rlink), lk_info[link].ctl[rlink].u);
            /* Reset if link goes down */
            bdk_rst_ocx_t rst_ocx;
            rst_ocx.u = ocx_pp_read(rid, BDK_RST_OCX);
            rst_ocx.s.rst_link |= 1 << rlink;
            ocx_pp_write(rid, BDK_RST_OCX, rst_ocx.u);
        }
    }

    BDK_TRACE(INIT, "Programming local links\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        if (!lk_info[LOCAL_NODE].ctl[link].s.valid || !lk_info[LOCAL_NODE].ctl[link].s.up)
            BDK_TRACE(INIT, "    Local link %d: Down\n", link);
        else
            BDK_TRACE(INIT, "    Local link %d: Connects to node ID %d\n", link, lk_info[link].node.s.id);
        BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link),
            c.s.id = lk_info[link].node.s.id);
    }

    BDK_TRACE(INIT, "Checking the PP_CMD still works\n");
    int failures = 0;
    for (int link = 0; link < MAX_LINKS; link++)
    {
        BDK_CSR_INIT(local_link_ctl, bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link));
        if (!local_link_ctl.s.valid || !local_link_ctl.s.up)
            continue;
        BDK_TRACE(INIT, "    Local link %d: Checking\n", link);
        if (local_link_ctl.s.id != lk_info[link].node.s.id)
        {
            BDK_TRACE(INIT, "        Failed: Local link ID doesn't match expect node ID\n");
            failures++;
        }
        bdk_ocx_com_node_t com_node;
        com_node.u = ocx_pp_read(local_link_ctl.s.id, BDK_OCX_COM_NODE);
        if (com_node.s.fixed &&
            (com_node.s.id == lk_info[link].node.s.id) &&
            local_link_ctl.s.id == lk_info[link].node.s.id)
        {
            BDK_TRACE(INIT, "        Passed\n");
        }
        else
        {
            BDK_TRACE(INIT, "        Failed\n");
            failures++;
        }
    }
    if (failures)
    {
        BDK_TRACE(INIT, "Not enabling OCX due to errors\n");
        const uint64_t exists_mask = bdk_numa_get_exists_mask();
        BDK_CSR_MODIFY(l2c_oci_ctl, bdk_numa_local(), BDK_L2C_OCI_CTL,
            l2c_oci_ctl.s.iofrcl = 1;
            l2c_oci_ctl.s.enaoci = exists_mask);
        return -1;
    }

    /* All OCX links are up and running. Now tell local L2 that OCX is good */
    BDK_TRACE(INIT, "Configuring L2 for OCX on all nodes\n");
    const uint64_t exists_mask = bdk_numa_get_exists_mask();
    for (bdk_node_t node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (node == bdk_numa_local())
        {
            BDK_CSR_MODIFY(l2c_oci_ctl, node, BDK_L2C_OCI_CTL,
                l2c_oci_ctl.s.iofrcl = 0;
                l2c_oci_ctl.s.enaoci = exists_mask);
        }
        else if (bdk_numa_exists(node))
        {
            bdk_l2c_oci_ctl_t l2c_oci_ctl;
            l2c_oci_ctl.u = ocx_pp_read(node, BDK_L2C_OCI_CTL);
            l2c_oci_ctl.s.iofrcl = 0;
            l2c_oci_ctl.s.enaoci = exists_mask;
            ocx_pp_write(node, BDK_L2C_OCI_CTL, l2c_oci_ctl.u);
        }
    }
    BDK_TRACE(INIT, "OCX is functional, starting to boot nodes\n");

    /* Make sure all cores on remote nodes are in reset. The L2 will
       have invalid aliases for memory if we changed the node ID while
       a core was running */
    for (bdk_node_t node=0; node<BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node) && (node != bdk_numa_master()))
        {
            BDK_CSR_INIT(rst_pp_available, node, BDK_RST_PP_AVAILABLE);
            BDK_CSR_INIT(rst_pp_reset, node, BDK_RST_PP_RESET);
            if (rst_pp_available.u & ~rst_pp_reset.u)
            {
                bdk_warn("*****************************************************\n");
                bdk_warn("Cores booted on remote node %d before OCI setup. L2\n", node);
                bdk_warn("aliases will make software unstable. Configure remote\n");
                bdk_warn("nodes for remote boot using pin REMOTE_BOOT.\n");
                bdk_warn("*****************************************************\n");
            }
        }
    }

    return 0;
}

static void setup_node(bdk_node_t node)
{
    if (bdk_is_simulation())
        return; // FIXME: OCX not modelled in Asim
#ifdef HW_EMULATOR
    return; /* Emulator doesn't seem to have CCPI registers */
#endif

    clear_oci_error(node);
    /* Lanes for master were reported before CCPI was brought up */
    if (node != bdk_numa_master())
        oci_report_lane(node);

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
    {
        /* Errata: (OCX-22153) OCX data rate issues with slower rclks */
        uint64_t rclk = bdk_clock_get_rate(node, BDK_CLOCK_RCLK);
        for (int link = 0; link < 3; link++)
        {
            uint64_t gbaud = bdk_qlm_get_gbaud_mhz(node, 8 + link * 2);
            if (gbaud)
            {
                /* TX_DAT_RATE=roundup((67*RCLK / GBAUD)*32) */
                gbaud *= 1000000;
                uint64_t data_rate = 67 * rclk;
                data_rate *= 32;
                data_rate += gbaud - 1;
                data_rate /= gbaud;
                BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
                    c.s.data_rate = data_rate);
            }
        }

        /* Errata:(SMMU-22267) SMMU not propagating Global Sync completion */
        for (int smmu=0; smmu<4; smmu++)
            BDK_CSR_MODIFY(c, node, BDK_SMMUX_DIAG_CTL(smmu),
                c.s.force_clks_active = 1);
    }

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        /* Split across two links as HW currently only support 2 node */
        BDK_CSR_MODIFY(c, node, BDK_OCX_COM_DUAL_SORT,
            c.s.sort = 1);
    }

    /* Enable secure access to all of memory */
    BDK_CSR_WRITE(node, BDK_L2C_ASC_REGIONX_START(0), 0);
    BDK_CSR_WRITE(node, BDK_L2C_ASC_REGIONX_END(0), -1);
    BDK_CSR_WRITE(node, BDK_L2C_ASC_REGIONX_ATTR(0), 2);

    /* Update way partition to allow core 0 to write to L2 */
    BDK_CSR_WRITE(node, BDK_L2C_WPAR_PPX(0), 0);
    BDK_CSR_READ(node, BDK_L2C_WPAR_PPX(0));
}

/**
 * Call this function to take secondary nodes and cores out of
 * reset and have them start running threads
 *
 * @param skip_cores If non-zero, cores are not started. Only the nodes are setup
 *
 * @return Zero on success, negative on failure.
 */
int bdk_init_nodes(int skip_cores)
{
    int result = 0;
    int do_oci_init = 0;

    /* Only init OCI/CCPI on chips that support it */
    do_oci_init = CAVIUM_IS_MODEL(CAVIUM_CN88XX);

    /* Simulation under Asim is a special case. Multi-node is simulaoted, but
       not the details of the low level link */
    if (do_oci_init && bdk_is_simulation())
    {
        bdk_numa_set_exists(0);
        bdk_numa_set_exists(1);
        /* Skip the rest in simulation */
        do_oci_init = 0;
    }

    if (do_oci_init)
    {
        /* Don't run OCI link init if L2C_OCI_CTL shows that it has already
           been done */
        BDK_CSR_INIT(l2c_oci_ctl, bdk_numa_local(), BDK_L2C_OCI_CTL);
        if (l2c_oci_ctl.s.enaoci == 0)
        {
            result |= init_oci();
            for (bdk_node_t node=0; node<BDK_NUMA_MAX_NODES; node++)
            {
                if (bdk_numa_exists(node))
                {
                    setup_node(node);
                    if (node != bdk_numa_master())
                        __bdk_init_node(node);
                }
            }
        }
    }

    /* Start cores on all node unless it was disabled */
    if (!skip_cores)
    {
        for (bdk_node_t node=0; node<BDK_NUMA_MAX_NODES; node++)
        {
            if (bdk_numa_exists(node))
                result |= bdk_init_cores(node, 0);
        }
    }
    return result;
}

/**
 * Get the coremask of the cores actively running the BDK. Doesn't count cores
 * that aren't booted.
 *
 * @param node   Node to coremask the count for
 *
 * @return 64bit bitmask
 */
uint64_t bdk_get_running_coremask(bdk_node_t node)
{
    return __bdk_alive_coremask[node];
}
