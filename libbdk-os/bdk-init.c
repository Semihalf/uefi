#include <bdk.h>
#include <stdio.h>
#include <unistd.h>

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
    /* Setup the UART */
    BDK_CSR_MODIFY(u, node, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 1; /* Divisor Latch Address bit */
        u.s.eps = 0; /* Even Parity Select bit */
        u.s.pen = 0; /* Parity Enable bit */
        u.s.stop = 0; /* Stop Control bit */
        u.s.cls = 3); /* Character Length Select */

    /* FCR is a write only register */
    BDK_CSR_WRITE(node, BDK_MIO_UARTX_FCR(uart), 7);

    int divisor = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / baudrate / 16;
    if (bdk_is_simulation())
        divisor = 1;

    BDK_CSR_WRITE(node, BDK_MIO_UARTX_DLH(uart), divisor>>8);
    BDK_CSR_WRITE(node, BDK_MIO_UARTX_DLL(uart), divisor & 0xff);

    BDK_CSR_MODIFY(u, node, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 0); /* Divisor Latch Address bit */
    BDK_CSR_READ(node, BDK_MIO_UARTX_LCR(uart));
    bdk_wait(1000);

    use_flow_control = !!use_flow_control;
    BDK_CSR_MODIFY(mcr, node, BDK_MIO_UARTX_MCR(uart),
        mcr.s.afce = use_flow_control;
        mcr.s.rts = use_flow_control);
}

static void __bdk_init_exception(bdk_node_t node)
{
    extern void __bdk_exception(void);

    /* Install exception vectors */
    void *ebase = (void*)0xffffffff80000000l;
    BDK_MT_COP0(ebase, COP0_EBASE);
    memcpy(ebase, &__bdk_exception, 0x80); /* TLB */
    memcpy(ebase + 0x80, &__bdk_exception, 0x80); /* XTLB */
    memcpy(ebase + 0x100, &__bdk_exception, 0x80); /* Cache Error */
    memcpy(ebase + 0x180, &__bdk_exception, 0x80); /* General Exception */
    memcpy(ebase + 0x200, &__bdk_exception, 0x80); /* Interrupt */
    BDK_SYNC;
    BDK_ICACHE_INVALIDATE;
}

void __bdk_init(long base_address) __attribute((noreturn));
void __bdk_init(long base_address)
{
    /* Enable RDHWR */
    BDK_MT_COP0(0xe000000f, COP0_HWRENA);

    /* Clear cause */
    BDK_MT_COP0(0, COP0_CAUSE);

    /* Clear ENTRYHI[ASID] to keep simulator happy */
    BDK_MT_COP0(0, COP0_ENTRYHI);

    /* Disable ERL, EXL, and IE */
    uint32_t status;
    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(0xff<<8);   /* Clear IM enables */
    status |= 1<<23;        /* Enable 64bit user opcodes */
    status |= 7<<5;         /* Enable 64bit in Kernel, super, and user */
    status &= ~(3<<3);      /* Set kernel mode */
    status &= ~(1<<2);      /* Disable ERL */
    status &= ~(1<<1);      /* Disable EXL */
    status &= ~(1<<0);      /* Disable IE */
    BDK_MT_COP0(status, COP0_STATUS);

    /* Use unaligned instructions */
    uint64_t cvmctl;
    BDK_MF_COP0(cvmctl, COP0_CVMCTL);
    cvmctl |= 1<<12;    /* Use unaligned instructions */
    cvmctl |= 1<<14;    /* Fix unaligned accesses */
    BDK_MT_COP0(cvmctl, COP0_CVMCTL);

    bdk_node_t node = bdk_numa_local();
    bdk_numa_set_running(node);

    /* Sync cycle counter */
    uint64_t core_rate = bdk_clock_get_rate(node, BDK_CLOCK_CORE) / 1000000;
    uint64_t sclk_rate = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000;
    BDK_SYNC;
    uint64_t core_cycle = bdk_clock_get_count(BDK_CLOCK_SCLK) * core_rate / sclk_rate;
    BDK_MT_COP0(core_cycle, COP0_CVMCOUNT);

    static const char BANNER_1[] = "Bringup and Diagnostic Kit (BDK)\n";
    static const char BANNER_2[] = "Locking L2 cache\n";
    static const char BANNER_3[] = "Transferring to thread scheduler\n";

    BDK_MT_COP0(0, COP0_USERLOCAL);

    /* Initialize async WQE area with no work */
    bdk_scratch_write64(BDK_IF_SCR_WORK, 1ull<<63);

    if (bdk_is_boot_core())
    {
        /* Shut off cores in reset to save power. This is a new feature in
            Octeon 3. It is optional, but probably good practice. When taking
            cores out of reset, it will be necessary t oclear the correct bit
            that was set here */
        if (OCTEON_IS_MODEL(OCTEON_CN70XX) || OCTEON_IS_MODEL(OCTEON_CN78XX))
        {
            /* Get a list of cores in reset */
            uint64_t reset = BDK_CSR_READ(node, BDK_CIU_PP_RST);
            /* Power off the core in reset */
            BDK_CSR_WRITE(node, BDK_RST_PP_POWER, reset);
        }

        /* Initialize the is_simulation flag */
        BDK_CSR_INIT(c, node, BDK_OCLAX_CONST(0));
        __bdk_is_simulation = (c.u == 0);

        bdk_set_baudrate(node, 0, BDK_UART_BAUDRATE, 0);
        bdk_set_baudrate(node, 1, BDK_UART_BAUDRATE, 0);
        bdk_fs_set_uart_node(node);

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_1, sizeof(BANNER_1)-1);
        __bdk_init_exception(node);

        /* Only lock L2 if DDR3 isn't initialized */
        BDK_CSR_INIT(lmcx_ddr_pll_ctl, node, BDK_LMCX_DDR_PLL_CTL(0));
        if ((lmcx_ddr_pll_ctl.s.reset_n == 0) && !bdk_is_simulation())
        {
            if (BDK_SHOW_BOOT_BANNERS)
                write(1, BANNER_2, sizeof(BANNER_2)-1);
            bdk_l2c_lock_mem_region(node, 0, bdk_l2c_get_cache_size_bytes(node));
            /* The above locking will cause L2 to load zeros without DRAM setup.
                This will cause L2C_TADX_INT[rddislmc], which we suppress below */
            if (OCTEON_IS_MODEL(OCTEON_CN70XX))
            {
                BDK_CSR_DEFINE(ciu_cib_l2c_rawx, BDK_CIU_CIB_L2C_RAWX(0));
                ciu_cib_l2c_rawx.u64 = 0;
                ciu_cib_l2c_rawx.s.tadx_int_rddislmc = 1;
                BDK_CSR_WRITE(node, BDK_CIU_CIB_L2C_RAWX(0), ciu_cib_l2c_rawx.u64);
            }
            BDK_CSR_DEFINE(l2c_tadx_int, BDK_L2C_TADX_INT(0));
            l2c_tadx_int.u64 = 0;
            l2c_tadx_int.s.rddislmc = 1;
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(0), l2c_tadx_int.u64);
            if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            {
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(1), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(2), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(3), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(4), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(5), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(6), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(7), l2c_tadx_int.u64);
            }
            /* The locked region isn't considered dirty by L2. Do read
               read/write of each cache line to force each to be dirty */
            volatile uint8_t *ptr = bdk_phys_to_ptr(1);
            uint8_t *end = bdk_phys_to_ptr(bdk_l2c_get_cache_size_bytes(node));
            while (ptr < end)
            {
                *ptr = *ptr;
                ptr += 128;
            }
        }

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_3, sizeof(BANNER_3)-1);
        bdk_thread_initialize();
    }

    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(1<<22); // Clear BEV
    BDK_MT_COP0(status, COP0_STATUS);

    bdk_atomic_add64(&__bdk_alive_coremask[node], bdk_core_to_mask());
    bdk_thread_first(__bdk_init_main, 0, NULL, 0);
}

int bdk_init_cores(bdk_node_t node, uint64_t coremask)
{
    extern void __bdk_reset_vector(void);
    extern void __bdk_reset_vector_data(void);

    BDK_TRACE("Install reset vector node %d\n", node);
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_ADR, 0);
    int length = (__bdk_reset_vector_data - __bdk_reset_vector)/8;
    if (length > 16)
    {
        bdk_error("Reset vector too large. No secondary cores can boot\n");
        return -1;
    }
    const uint64_t *src = (const uint64_t *)__bdk_reset_vector;
    while (length--)
        BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_DAT, *src++);
    /* We will now be at __bdk_reset_vector_data. Write the jump address
        and KSEGNODE */
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_DAT, 0xffffffff80002000);
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_DAT, bdk_numa_master());
    /* Now set the address and enable it */
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_CFGX(0), 0x81fc0000ull);
    BDK_CSR_READ(node, BDK_MIO_BOOT_LOC_CFGX(0));
    BDK_TRACE("Reset vector installed");

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
    coremask &= (1ull<<bdk_octeon_num_cores(node)) - 1;

    if (OCTEON_IS_MODEL(OCTEON_CN70XX) || OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        /* We may also need to turn power on (new in Octeon 3) */
        uint64_t power = BDK_CSR_READ(node, BDK_RST_PP_POWER);
        if (power & coremask)
        {
            power &= ~coremask;
            BDK_TRACE("Enabling RST_PP_POWER\n");
            BDK_CSR_WRITE(node, BDK_RST_PP_POWER, power);
            bdk_wait_usec(1000); /* A delay seems to be needed here */
        }
    }

    BDK_TRACE("First send a NMI\n");
    BDK_CSR_WRITE(node, BDK_CIU_NMI, coremask);

    BDK_TRACE("Then take cores out of reset\n");
    uint64_t reset = BDK_CSR_READ(node, BDK_CIU_PP_RST);
    if (reset & coremask)
    {
        reset &= ~coremask;
        BDK_CSR_WRITE(node, BDK_CIU_PP_RST, reset);
    }

    BDK_TRACE("Wait up to 100us for the cores to boot\n");
    uint64_t timeout = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 10000 + bdk_clock_get_count(BDK_CLOCK_CORE);
    while ((bdk_clock_get_count(BDK_CLOCK_CORE) < timeout) && ((bdk_atomic_get64(&__bdk_alive_coremask[node]) & coremask) != coremask))
    {
        /* Tight spin */
    }

    if ((bdk_atomic_get64(&__bdk_alive_coremask[node]) & coremask) != coremask)
    {
        bdk_error("Node %d: Some cores failed to start. Alive mask 0x%lx, requested 0x%lx\n",
            node, __bdk_alive_coremask[node], coremask);
        return -1;
    }
    BDK_TRACE("All cores booted\n");
    return 0;
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
    address |= (uint64_t)node << 36;

    if (node == bdk_numa_local())
    {
        address |= 1ull << 63;
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

        uint64_t data = -1;
        while (data == (uint64_t)-1)
        {
            bdk_thread_yield();
            data = BDK_CSR_READ(bdk_numa_local(), BDK_OCX_PP_RD_DATA);
        }
        return data;
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
    address |= (uint64_t)node << 36;

    if (node == bdk_numa_local())
    {
        address |= 1ull << 63;
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

/**
 * Call this function to take secondary nodes and cores out of
 * reset and have them start running threads
 *
 * @return Zero on success, negative on failure.
 */
int bdk_init_nodes(void)
{
    const int MAX_LINKS = 3;
    bdk_ocx_com_node_t node_id[MAX_LINKS];

    /* Only one node should be up (the one I'm on). Set its ID to be fixed. As
       part of booting the BDK we've already added it to both the exists and
       running node masks */
    BDK_TRACE("Marking the current node ID %d as fixed\n", bdk_numa_local());
    BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_OCX_COM_NODE,
        c.s.fixed = 1);

    BDK_TRACE("Loop through links looking for nodes\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        /* Read the ID the local link thinks is on its other side */
        BDK_CSR_INIT(link_ctl, bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link));
        if (link_ctl.s.valid && link_ctl.s.up)
        {
            BDK_TRACE("    Local OCX link %d is valid and up\n", link);
            /* Issue a OCX_COM_NODE to the ID to find out what the node on the
               other side thinks its ID is */
            node_id[link].u = ocx_pp_read(link_ctl.s.id, BDK_OCX_COM_NODE);
            BDK_TRACE("        Remote node has ID %d, fixed=%d\n", node_id[link].s.id, node_id[link].s.fixed);
            /* If the Node ID is already fixed, add it to our existing nodes */
            if (node_id[link].s.fixed)
            {
                if (bdk_numa_exists(node_id[link].s.id))
                    bdk_fatal("Duplicate node ID %d with fixed bit\n", node_id[link].s.id);
                bdk_numa_set_exists(node_id[link].s.id);
            }
        }
        else
        {
            BDK_TRACE("    Local OCX link %d is down\n", link);
            /* Link has a problem, make sure it stays down */
            BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_OCX_LNKX_CFG(link),
                c.s.qlm_select = 0);
            node_id[link].u = -1;
        }
    }

    /* We now have a complete list of the possible nodes. Loop through
       assigning node IDs */
    BDK_TRACE("Assigning IDs\n");
    for (int link = 0; link < MAX_LINKS; link++)
    {
        /* Skip invalid links */
        BDK_CSR_INIT(local_link_ctl, bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link));
        if (!local_link_ctl.s.valid || !local_link_ctl.s.up)
            continue;

        /* We use a temporary node ID to communicate while assigning the real ID */
        const int tmp_node = local_link_ctl.s.id;

        /* If node ID isn't fixed then find an ID for it */
        if (!node_id[link].s.fixed)
        {
            /* Find a clear exists bit */
            bdk_node_t node;
            for (node = 0; node < BDK_NUMA_MAX_NODES; node++)
            {
                if (!bdk_numa_exists(node))
                    break;
            }
            if (node > BDK_NUMA_MAX_NODES)
            {
                bdk_error("Somehow we found more nodes than we support. Skipping new node");
                continue;
            }
            /* Store the node ID in our local array for later adding */
            node_id[link].s.id = node;
            node_id[link].s.fixed = 1;
            BDK_TRACE("    Local OCX link %d could be assigned node ID %d\n", link, node_id[link].s.id);
        }
        /* Its possible that multiple links point to the same node. If this
           is the case then the links after the first one will see OCX_COM_NODE
           change to a fixed value. In this case we need to use the fixed value
           to update our array */
        bdk_ocx_com_node_t current_id;
        current_id.u = ocx_pp_read(tmp_node, BDK_OCX_COM_NODE);
        if (current_id.s.fixed)
        {
            node_id[link] = current_id;
            BDK_TRACE("    Local OCX link %d assigned node ID %d due to fixed being set\n", link, node_id[link].s.id);
        }
        /* Determine which OCX link the remote node is connected to us with */
        int rlink;
        for (rlink = 0; rlink < MAX_LINKS; rlink++)
        {
            bdk_ocx_com_linkx_ctl_t linkx_ctl;
            bdk_ocx_lnkx_cfg_t lnkx_cfg;
            linkx_ctl.u = ocx_pp_read(tmp_node, BDK_OCX_COM_LINKX_CTL(rlink));
            lnkx_cfg.u = ocx_pp_read(tmp_node, BDK_OCX_LNKX_CFG(rlink));
            if (linkx_ctl.s.valid && linkx_ctl.s.up)
            {
                int lne;
                if (lnkx_cfg.s.qlm_select & 1)
                    lne = 0;
                else if (lnkx_cfg.s.qlm_select & 2)
                    lne = 4;
                else if (lnkx_cfg.s.qlm_select & 4)
                    lne = 8;
                else if (lnkx_cfg.s.qlm_select & 8)
                    lne = 12;
                else if (lnkx_cfg.s.qlm_select & 0x10)
                    lne = 16;
                else
                    lne = 20;
                bdk_ocx_lnex_sts_msg_t sts_msg;
                sts_msg.u = ocx_pp_read(tmp_node, BDK_OCX_LNEX_STS_MSG(lne));
                bdk_node_t connect_node = sts_msg.s.rx_meta_dat & 0x3;
                int connect_fixed = (sts_msg.s.rx_meta_dat & 0x4) >> 2;
                BDK_TRACE("        Remote link %d (lane %d) connects to Node ID %d, fixed = %d\n", rlink, lne, connect_node, connect_fixed);
                if (connect_fixed && (connect_node == bdk_numa_local()))
                    break;
            }
        }
        if (rlink == MAX_LINKS)
            bdk_fatal("Unable to determine which remote link node ID %d used to connect to local node", node_id[link].s.id);

        /* Change all other remote links to not have our node ID or the same node */
        for (int rlink2 = 0; rlink2 < MAX_LINKS; rlink2++)
        {
            bdk_node_t node = (node_id[link].s.id + 1) & 3;
            if (node == bdk_numa_local())
                node++;
            if (rlink2 != rlink)
            {
                bdk_ocx_com_linkx_ctl_t rlinkx_ctl;
                rlinkx_ctl.u = ocx_pp_read(tmp_node, BDK_OCX_COM_LINKX_CTL(rlink2));
                rlinkx_ctl.s.id = node;
                ocx_pp_write(tmp_node, BDK_OCX_COM_LINKX_CTL(rlink2), rlinkx_ctl.u);
            }
        }

        /* Write the final ID to the remote node */
        BDK_TRACE("    Programming OCX link %d for node ID %d\n", link, node_id[link].s.id);
        bdk_ocx_com_linkx_ctl_t rlinkx_ctl;
        rlinkx_ctl.u = ocx_pp_read(tmp_node, BDK_OCX_COM_LINKX_CTL(rlink));
        rlinkx_ctl.s.id = bdk_numa_local();
        rlinkx_ctl.s.auto_clr = 0;
        local_link_ctl.s.id = node_id[link].s.id;
        local_link_ctl.s.auto_clr = 0;
        ocx_pp_write(tmp_node, BDK_OCX_COM_NODE, node_id[link].u);
        ocx_pp_write(tmp_node, BDK_OCX_COM_LINKX_CTL(rlink), rlinkx_ctl.u);
        BDK_CSR_WRITE(bdk_numa_local(), BDK_OCX_COM_LINKX_CTL(link), local_link_ctl.u);
        /* Make sure reads still work */
        ocx_pp_read(node_id[link].s.id, BDK_OCX_COM_NODE);

        /* Record the node as existing. This will be a duplicate add for any
           fixed nodes, but that is harmless */
        bdk_numa_set_exists(node_id[link].s.id);
    }

    const uint64_t exists_mask = bdk_numa_get_exists_mask();

    /* We've setup the OCX links, but the remote ends may have the incorrect
       node number for the local end. Since we don't know which link connects
       to each node, we need to read over the link from the remote node */
    BDK_TRACE("Configuring remaining node links\n");
    for (bdk_node_t node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        /* For every node except this one */
        if (bdk_numa_exists(node) && (node != bdk_numa_local()))
        {
            for (int link = 0; link < MAX_LINKS; link++)
            {
                BDK_TRACE("    Checking node ID %d, link %d\n", node, link);
                bdk_ocx_com_linkx_ctl_t linkx_ctl;
                bdk_ocx_lnkx_cfg_t lnkx_cfg;
                linkx_ctl.u = ocx_pp_read(node, BDK_OCX_COM_LINKX_CTL(link));
                lnkx_cfg.u = ocx_pp_read(node, BDK_OCX_LNKX_CFG(link));
                if (linkx_ctl.s.valid && linkx_ctl.s.up)
                {
                    int lne;
                    if (lnkx_cfg.s.qlm_select & 1)
                        lne = 0;
                    else if (lnkx_cfg.s.qlm_select & 2)
                        lne = 4;
                    else if (lnkx_cfg.s.qlm_select & 4)
                        lne = 8;
                    else if (lnkx_cfg.s.qlm_select & 8)
                        lne = 12;
                    else if (lnkx_cfg.s.qlm_select & 0x10)
                        lne = 16;
                    else
                        lne = 20;
                    bdk_ocx_lnex_sts_msg_t sts_msg;
                    sts_msg.u = ocx_pp_read(node, BDK_OCX_LNEX_STS_MSG(lne));
                    int connect_node = sts_msg.s.rx_meta_dat & 0x3;
                    linkx_ctl.s.id = connect_node;
                    linkx_ctl.s.auto_clr = 0;
                    ocx_pp_write(node, BDK_OCX_COM_LINKX_CTL(link), linkx_ctl.u);
                    BDK_TRACE("        Node %d, OCX link %d points to node ID %d\n", node, link, connect_node);
                }
                else
                {
                    /* Link has a problem, make sure it stays down */
                    lnkx_cfg.s.qlm_select = 0;
                    ocx_pp_write(node, BDK_OCX_LNKX_CFG(link), lnkx_cfg.u);
                    BDK_TRACE("        Node %d, OCX link %d is down\n", node, link);
                }
            }
        }
    }

    /* All OCX links are up and running. Now tell local L2 that OCX is good */
    BDK_TRACE("Configuring L2 for OCX on all nodes\n");
    for (bdk_node_t node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (node == bdk_numa_local())
        {
            BDK_CSR_MODIFY(l2c_oci_ctl, node, BDK_L2C_OCI_CTL,
                l2c_oci_ctl.s.iofrcl = 0;
                l2c_oci_ctl.s.gksegnode = bdk_numa_local();
                l2c_oci_ctl.s.enaoci = exists_mask);
        }
        else if (bdk_numa_exists(node))
        {
            bdk_l2c_oci_ctl_t l2c_oci_ctl;
            l2c_oci_ctl.u = ocx_pp_read(node, BDK_L2C_OCI_CTL);
            l2c_oci_ctl.s.iofrcl = 0;
            l2c_oci_ctl.s.gksegnode = node;
            l2c_oci_ctl.s.enaoci = exists_mask;
            ocx_pp_write(node, BDK_L2C_OCI_CTL, l2c_oci_ctl.u);
        }
    }

    BDK_TRACE("OCX is functional, starting to boot nodes\n");
    int result = 0;
    for (bdk_node_t node=0; node<BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
            result |= bdk_init_cores(node, 0);
    }
    return result;
}

