#include <bdk.h>

#define MGMT_PORT_NUM_TX_BUFFERS   8 /* Number of TX ring buffer entries and buffers */
#define MGMT_PORT_NUM_RX_BUFFERS   16 /* Number of RX ring buffer entries and buffers */

/**
 * Format of the TX/RX ring buffer entries
 */
typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    reserved_62_63  : 2;
        uint64_t    len             : 14;   /* Length of the buffer/packet in bytes */
        uint64_t    tstamp          : 1;    /* For TX, signals that the packet should be timestamped */
        uint64_t    code            : 7;    /* The RX error code */
        uint64_t    addr            : 40;   /* Physical address of the buffer */
    } s;
} mgmt_port_ring_entry_t;

/**
 * Per port state required for each mgmt port
 */
typedef struct
{
    bdk_spinlock_t  rx_lock;        /* Used for exclusive access to this structure */
    int             is_rgmii;       /* RGMII vs MII flag */
    int             rx_read_index;  /* Where the next RX will be in the rx_ring */
    mgmt_port_ring_entry_t rx_ring[MGMT_PORT_NUM_RX_BUFFERS];
    mgmt_port_ring_entry_t tx_ring[MGMT_PORT_NUM_TX_BUFFERS];
    bdk_buf_ptr_t          tx_buf[MGMT_PORT_NUM_TX_BUFFERS];
    bdk_spinlock_t  tx_lock;        /* Used for exclusive access to this structure */
    int             tx_free_index;  /* Where the next TX will be freed */
    int             tx_write_index; /* Where the next TX will write in the tx_ring */
} mgmt_port_state_t;


/**
 * Return the number of MGMT interfaces
 *
 * @return One for all current chips
 */
static int if_num_interfaces(bdk_node_t node)
{
    return 1;
}


/**
 * Return the number of mgmt ports on an interface
 *
 * @param interface Interface number
 *
 * @return Number of ports
 */
static int if_num_ports(bdk_node_t node, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN61XX))
        return 2;
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 1;
    else if (OCTEON_IS_MODEL(OCTEON_CN70XX))
        return 1;
    else
        return 0;
}


/**
 * Probe a single mgmt port
 *
 * @param handle Handle to port
 *
 * @return Zero on success, negative on failure
 */
static int if_probe(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        /* Change name to be "RGMII%d" */
        snprintf(handle->name, sizeof(handle->name), "RGMII%d", handle->index);
        handle->name[sizeof(handle->name)-1] = 0;
        handle->ipd_port = 24; /* New for CN70XX */
        /* The default values in PKO_MEM_PORT_PTRS are wrong. Fix them */
        BDK_CSR_DEFINE(index, BDK_PKO_REG_READ_IDX);
        index.u = 0;
        index.s.index = handle->ipd_port;
        BDK_CSR_WRITE(handle->node, BDK_PKO_REG_READ_IDX, index.u);
        BDK_CSR_MODIFY(ptrs, handle->node, BDK_PKO_MEM_PORT_PTRS,
            ptrs.s.bp_port = 40; /* RGMII0 special value, BP disabled */
            ptrs.s.eid = 10; /* Engine for RGMII */
            ptrs.s.pid = handle->ipd_port);
    }
    else
    {
        /* Change name to be "MGMT%d" */
        snprintf(handle->name, sizeof(handle->name), "MGMT%d", handle->index);
        handle->name[sizeof(handle->name)-1] = 0;
        handle->ipd_port = -1;
    }
    handle->flags |= BDK_IF_FLAGS_HAS_FCS;
    return 0;
}


/**
 * Initialize a single mgmt port
 *
 * @param handle Handle to port
 *
 * @return Zero on success, negative on failure
 */
static int if_init(bdk_if_handle_t handle)
{
    int is_rgmii = 1;

    /* Chips other than CN70XX feed this with MIX. CN70XX uses the
        normal IPD/PKO paths */
    if (handle->ipd_port == -1)
    {
        handle->priv = calloc(1, sizeof(mgmt_port_state_t));
        if (!handle->priv)
            return -1;

        mgmt_port_state_t *state = handle->priv;

        bdk_spinlock_init(&state->tx_lock);
        bdk_spinlock_init(&state->rx_lock);

        /* Read PHY status register to find the mode of the interface. */
        int phy_id = bdk_config_get(BDK_CONFIG_PHY_MGMT_PORT0 + handle->index);
        if (phy_id >= 0x1000)
        {
            /* A PHY address with the special value 0x1000 represents a PHY we can't
                connect to through MDIO which is assumed to be at 1Gbps */
            /* A PHY address with the special value 0x1001 represents a PHY we can't
                connect to through MDIO which is assumed to be at 100Mbps */
            state->is_rgmii = (phy_id == 0x1000);
        }
        else if (phy_id != -1)
        {
            bdk_mdio_phy_reg_status_t phy_status;
            phy_status.u16 = bdk_mdio_read(handle->node, phy_id >> 8, phy_id & 0xff, BDK_MDIO_PHY_REG_STATUS);
            state->is_rgmii = (phy_status.s.capable_extended_status == 1);
        }
        else
            state->is_rgmii = 1;

        /* Reset the MIX block if it is already running. */
        BDK_CSR_INIT(mix_ctl, handle->node, BDK_MIXX_CTL(handle->index));
        if (!mix_ctl.s.reset)
        {
            mix_ctl.s.en = 0;
            BDK_CSR_WRITE(handle->node, BDK_MIXX_CTL(handle->index), mix_ctl.u64);
            if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_MIXX_CTL(handle->index), busy, ==, 0, 1000000))
            {
                bdk_error("Timeout waiting for MIX idle\n");
                free(handle->priv);
                handle->priv = NULL;
                return -1;
            }
            mix_ctl.s.reset = 1;
            BDK_CSR_WRITE(handle->node, BDK_MIXX_CTL(handle->index), mix_ctl.u64);
            BDK_CSR_READ(handle->node, BDK_MIXX_CTL(handle->index));
        }

        /* Make sure BIST passed */
        BDK_CSR_INIT(mix_bist, handle->node, BDK_MIXX_BIST(handle->index));
        if (mix_bist.u64)
            bdk_warn("Management port MIX failed BIST (0x%016lx)\n", mix_bist.u64);

        /* Take the control logic out of reset */
        BDK_CSR_MODIFY(mix_ctl, handle->node, BDK_MIXX_CTL(handle->index),
            mix_ctl.s.reset = 0);

        /* Read until reset == 0.  Timeout should never happen... */
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_MIXX_CTL(handle->index), reset, ==, 0, 1000000))
        {
            bdk_error("Timeout waiting for MIX reset.\n");
            return -1;
        }

        /* Tell the HW where the TX ring is */
        if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            BDK_CSR_MODIFY(oring1, handle->node, BDK_MIXX_ORING1(handle->index),
                oring1.cn78xx.obase = bdk_ptr_to_phys(state->tx_ring)>>3;
                oring1.cn78xx.osize = MGMT_PORT_NUM_TX_BUFFERS);
        else
            BDK_CSR_MODIFY(oring1, handle->node, BDK_MIXX_ORING1(handle->index),
                oring1.cn68xx.obase = bdk_ptr_to_phys(state->tx_ring)>>3;
                oring1.cn68xx.osize = MGMT_PORT_NUM_TX_BUFFERS);

        /* Setup the RX ring */
        for (int i=0; i<MGMT_PORT_NUM_RX_BUFFERS; i++)
        {
            void *fpa = bdk_fpa_alloc(handle->node, BDK_FPA_PACKET_POOL);
            if (!fpa)
            {
                bdk_error("Failed to allocate buffer.\n");
                return -1;
            }
            state->rx_ring[i].s.len = bdk_fpa_get_block_size(handle->node, BDK_FPA_PACKET_POOL);
            state->rx_ring[i].s.addr = bdk_ptr_to_phys(fpa);
        }
        BDK_SYNCW;

        /* Tell the HW where the RX ring is */
        if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            BDK_CSR_MODIFY(iring1, handle->node, BDK_MIXX_IRING1(handle->index),
                iring1.cn78xx.ibase = bdk_ptr_to_phys(state->rx_ring)>>3;
                iring1.cn78xx.isize = MGMT_PORT_NUM_RX_BUFFERS);
        else
            BDK_CSR_MODIFY(iring1, handle->node, BDK_MIXX_IRING1(handle->index),
                iring1.cn68xx.ibase = bdk_ptr_to_phys(state->rx_ring)>>3;
                iring1.cn68xx.isize = MGMT_PORT_NUM_RX_BUFFERS);
        BDK_CSR_WRITE(handle->node, BDK_MIXX_IRING2(handle->index), MGMT_PORT_NUM_RX_BUFFERS);

        /* Enable the port HW. Packets are not allowed until bdk_mgmt_port_enable() is called */
        BDK_CSR_MODIFY(mix_ctl, handle->node, BDK_MIXX_CTL(handle->index),
            mix_ctl.s.crc_strip = 0;    /* Don't strip the ending CRC */
            mix_ctl.s.en = 1;           /* Enable the port */
            mix_ctl.s.nbtarb = 0;       /* Arbitration mode */
            mix_ctl.s.mrq_hwm = 1);     /* MII CB-request FIFO programmable high watermark */
        is_rgmii = state->is_rgmii;
    }

    BDK_CSR_INIT(agl_gmx_bist, handle->node, BDK_AGL_GMX_BIST);
    if (agl_gmx_bist.u64)
        bdk_warn("Management port AGL failed BIST (0x%016lx)\n", agl_gmx_bist.u64);

    /* Disable the external input/output */
    BDK_CSR_MODIFY(agl_gmx_prtx, handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index),
        agl_gmx_prtx.s.en = 0);

    /* Set the max incomming packet size */
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_RXX_FRM_MAX(handle->index), 16384 + 4 - 1);
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_RXX_JABBER(handle->index), 16384 + 8);

    /* Select the mode of operation for the interface. */
    BDK_CSR_MODIFY(agl_prtx_ctl, handle->node, BDK_AGL_PRTX_CTL(handle->index),
        agl_prtx_ctl.s.mode = !is_rgmii);

    /* MII clocks counts are based on the 125Mhz reference, so our
        delays need to be scaled to match the core clock rate. The
        "+1" is to make sure rounding always waits a little too
        long. */
    uint64_t clock_scale = bdk_clock_get_rate(handle->node, BDK_CLOCK_CORE) / 125000000 + 1;

    /* Take the DLL and clock tree out of reset */
    BDK_CSR_INIT(agl_prtx_ctl, handle->node, BDK_AGL_PRTX_CTL(handle->index));
    agl_prtx_ctl.s.clkrst = 0;
    if (is_rgmii) // RGMII Initialization
    {
        agl_prtx_ctl.s.dllrst = 0;
        agl_prtx_ctl.s.clktx_byp = 0;
    }
    BDK_CSR_WRITE(handle->node, BDK_AGL_PRTX_CTL(handle->index), agl_prtx_ctl.u64);
    BDK_CSR_READ(handle->node, BDK_AGL_PRTX_CTL(handle->index));  /* Force write out before wait */

    /* Wait for the DLL to lock.  External 125 MHz reference clock must be stable at this point. */
    bdk_wait(256 * clock_scale);

    /* The rest of the config is common between RGMII/MII */

    /* Enable the interface */
    BDK_CSR_MODIFY(agl_prtx_ctl, handle->node, BDK_AGL_PRTX_CTL(handle->index),
        agl_prtx_ctl.s.enable = 1);

    /* Read the value back to force the previous write */
    /* Enable the componsation controller */
    BDK_CSR_MODIFY(agl_prtx_ctl, handle->node, BDK_AGL_PRTX_CTL(handle->index),
        agl_prtx_ctl.s.comp = 1;
        agl_prtx_ctl.s.drv_byp = 0);

    /* Clear stats on read */
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_RXX_STATS_CTL(handle->index), 1);
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_TXX_STATS_CTL(handle->index), 1);

    return 0;
}


/**
 * Enable packet IO on a mgmt port
 *
 * @param handle Handle for port
 *
 * @return Zero on success, negative on failure
 */
static int if_enable(bdk_if_handle_t handle)
{
    /* Return immediately if the port is already enabled */
    BDK_CSR_INIT(agl_gmx_prtx, handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index));
    if (agl_gmx_prtx.s.en)
        return 0;

    bdk_agl_gmx_rxx_frm_ctl_t rxx_frm_ctl;
    rxx_frm_ctl.u64 = 0;
    rxx_frm_ctl.s.pre_align = 1;
    rxx_frm_ctl.s.pad_len = 1;  /* When set, disables the length check for non-min sized pkts with padding in the client data */
    rxx_frm_ctl.s.vlan_len = 1; /* When set, disables the length check for VLAN pkts */
    rxx_frm_ctl.s.pre_free = 1; /* When set, PREAMBLE checking is  less strict */
    rxx_frm_ctl.s.ctl_smac = 0; /* Control Pause Frames can match station SMAC */
    rxx_frm_ctl.s.ctl_mcst = 1; /* Control Pause Frames can match globally assign Multicast address */
    rxx_frm_ctl.s.ctl_bck = 1;  /* Forward pause information to TX block */
    rxx_frm_ctl.s.ctl_drp = 1;  /* Drop Control Pause Frames */
    rxx_frm_ctl.s.pre_strp = 1; /* Strip off the preamble */
    rxx_frm_ctl.s.pre_chk = 1;  /* This port is configured to send PREAMBLE+SFD to begin every frame.  GMX checks that the PREAMBLE is sent correctly */
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_RXX_FRM_CTL(handle->index), rxx_frm_ctl.u64);
    BDK_CSR_MODIFY(agl_gmx_prtx, handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index),
        agl_gmx_prtx.s.en = 1);

    return 0;
}


/**
 * Disable packet IO on a mgmt port
 *
 * @param handle Handle for port
 *
 * @return Zero on success, negative on failure
 */
static int if_disable(bdk_if_handle_t handle)
{
    BDK_CSR_MODIFY(agl_gmx_prtx, handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index),
        agl_gmx_prtx.s.en = 0);
    return 0;
}


/**
 * Get the current link state
 *
 * @param handle Handle for port
 *
 * @return Link state
 */
static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    int phy_id = bdk_config_get(BDK_CONFIG_PHY_MGMT_PORT0 + handle->index);
    bdk_if_link_t result;

    if (phy_id != -1)
        result = __bdk_if_phy_get(phy_id);
    else
    {
        result.u64 = 0;
        result.s.full_duplex = 1;
        result.s.up = 1;
        result.s.speed = 100;
    }
    return result;
}


/**
 * Get and configure the current link state
 *
 * @param handle Handle for port
 *
 * @return Link state
 */
static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    /* Disable GMX before we make any changes. */
    BDK_CSR_MODIFY(agl_gmx_prtx, handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index),
        agl_gmx_prtx.s.en = 0;
        agl_gmx_prtx.s.tx_en = 0;
        agl_gmx_prtx.s.rx_en = 0);

    /* Wait for GMX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index), rx_idle, ==, 1, 10000)
        || BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index), tx_idle, ==, 1, 10000))
    {
        bdk_dprintf("MIX%d: Timeout waiting for GMX to be idle\n", handle->index);
        return;
    }

    BDK_CSR_INIT(agl_gmx_prtx, handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index));

    /* Set duplex mode */
    if (!link_info.s.up)
        agl_gmx_prtx.s.duplex = 1;   /* Force full duplex on down links */
    else
        agl_gmx_prtx.s.duplex = link_info.s.full_duplex;

   switch(link_info.s.speed)
    {
        case 10:
            agl_gmx_prtx.s.speed = 0;
            agl_gmx_prtx.s.slottime = 0;
            agl_gmx_prtx.s.speed_msb = 1;
            agl_gmx_prtx.s.burst = 1;
            /* Due to errata (AGL-16930) 100/10 transmit IFGs are too small,
                we must program the inter frame gap. Note this might cause
                issues if there are two MGMT ports configured for different
                speeds */
            BDK_CSR_MODIFY(c, handle->node, BDK_AGL_GMX_TX_IFG,
                c.s.ifg1 = 14;
                c.s.ifg2 = 10);
         break;

        case 100:
            agl_gmx_prtx.s.speed = 0;
            agl_gmx_prtx.s.slottime = 0;
            agl_gmx_prtx.s.speed_msb = 0;
            agl_gmx_prtx.s.burst = 1;
            /* Due to errata (AGL-16930) 100/10 transmit IFGs are too small,
                we must program the inter frame gap. Note this might cause
                issues if there are two MGMT ports configured for different
                speeds */
            BDK_CSR_MODIFY(c, handle->node, BDK_AGL_GMX_TX_IFG,
                c.s.ifg1 = 14;
                c.s.ifg2 = 10);
            break;

        case 1000:
            /* 1000 MBits is only supported on 6XXX chips */
            agl_gmx_prtx.s.speed_msb = 0;
            agl_gmx_prtx.s.speed = 1;
            agl_gmx_prtx.s.slottime = 1;  /* Only matters for half-duplex */
            agl_gmx_prtx.s.burst = agl_gmx_prtx.s.duplex;
            /* Due to errata (AGL-16930) 100/10 transmit IFGs are too small,
                we must program the inter frame gap. Note this might cause
                issues if there are two MGMT ports configured for different
                speeds */
            BDK_CSR_MODIFY(c, handle->node, BDK_AGL_GMX_TX_IFG,
                c.s.ifg1 = 8;
                c.s.ifg2 = 4);
            break;

        /* No link */
        case 0:
        default:
            break;
    }

    /* Write the new GMX setting with the port still disabled. */
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index), agl_gmx_prtx.u64);

    /* Read GMX CFG again to make sure the config is completed. */
    agl_gmx_prtx.u64 = BDK_CSR_READ(handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index));

    BDK_CSR_INIT(agl_prtx_ctl, handle->node, BDK_AGL_PRTX_CTL(handle->index));
    BDK_CSR_INIT(agl_clk, handle->node, BDK_AGL_GMX_TXX_CLK(handle->index));
    agl_clk.s.clk_cnt = 1;    /* MII (both speeds) and RGMII 1000 setting */
    if (agl_prtx_ctl.s.mode == 0)
    {
        if (link_info.s.speed == 10)
            agl_clk.s.clk_cnt = 50;
        else if (link_info.s.speed == 100)
            agl_clk.s.clk_cnt = 5;
    }
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_TXX_CLK(handle->index), agl_clk.u64);

    /* Enable transmit and receive ports */
    agl_gmx_prtx.s.tx_en = 1;
    agl_gmx_prtx.s.rx_en = 1;
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index), agl_gmx_prtx.u64);

    /* Enable the link. */
    agl_gmx_prtx.s.en = 1;
    BDK_CSR_WRITE(handle->node, BDK_AGL_GMX_PRTX_CFG(handle->index), agl_gmx_prtx.u64);

    /* Enable error reporting */
    BDK_CSR_MODIFY(c, handle->node, BDK_AGL_GMX_RXX_INT_EN(handle->index),
        c.s.ovrerr = -1;
        c.s.skperr = -1;
    );
    BDK_CSR_MODIFY(c, handle->node, BDK_AGL_GMX_TX_INT_EN,
        c.s.pko_nxa = -1;
        c.s.undflw = -1;
    );

    if (handle->ipd_port == -1)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_MIXX_INTENA(handle->index),
            c.s.data_drpena = -1;
            c.s.ivfena = -1;
            c.s.irunena = -1;
            c.s.ovfena = -1;
            c.s.orunena = -1;
        );
    }
}


/**
 * Get port statisitcs
 *
 * @param handle Handle to port
 *
 * @return Port statistics
 */
static const bdk_if_stats_t *if_get_stats(bdk_if_handle_t handle)
{
    BDK_CSR_INIT(pkts_drp, handle->node, BDK_AGL_GMX_RXX_STATS_PKTS_DRP(handle->index));
    BDK_CSR_INIT(octs_drp, handle->node, BDK_AGL_GMX_RXX_STATS_OCTS_DRP(handle->index));
    BDK_CSR_INIT(pkts, handle->node, BDK_AGL_GMX_RXX_STATS_PKTS(handle->index));
    BDK_CSR_INIT(octs, handle->node, BDK_AGL_GMX_RXX_STATS_OCTS(handle->index));
    BDK_CSR_INIT(pkts_bad, handle->node, BDK_AGL_GMX_RXX_STATS_PKTS_BAD(handle->index));

    handle->stats.rx.dropped_octets += octs_drp.s.cnt;
    handle->stats.rx.dropped_packets += pkts_drp.s.cnt;
    handle->stats.rx.octets += octs.s.cnt;
    handle->stats.rx.packets += pkts.s.cnt;
    handle->stats.rx.errors += pkts_bad.s.cnt;

    BDK_CSR_INIT(stat2, handle->node, BDK_AGL_GMX_TXX_STAT2(handle->index));
    BDK_CSR_INIT(stat3, handle->node, BDK_AGL_GMX_TXX_STAT3(handle->index));
    BDK_CSR_INIT(stat9, handle->node, BDK_AGL_GMX_TXX_STAT9(handle->index));

    handle->stats.tx.octets += stat2.s.octs - stat9.s.ctl*64;
    handle->stats.tx.packets += stat3.s.pkts - stat9.s.ctl;

    return &handle->stats;
}


/**
 * Check for transmit complete and free TX packets
 *
 * @param handle Handle for port
 */
static void poll_tx_complete(bdk_if_handle_t handle)
{
    mgmt_port_state_t *state = handle->priv;
    int orcnt = BDK_CSR_READ(handle->node, BDK_MIXX_ORCNT(handle->index));
    int to_free = orcnt;

    BDK_SYNCW;
    while (to_free--)
    {
        int tfi = state->tx_free_index;
        if (state->tx_buf[tfi].v1.i == 0)
        {
            __bdk_fpa_raw_free(handle->node, state->tx_buf[tfi].v1.addr - state->tx_buf[tfi].v1.back*128,
                state->tx_buf[tfi].v1.pool, 0);
        }
        state->tx_ring[tfi].u64 = 0;
        state->tx_buf[tfi].u64 = 0;
        state->tx_free_index = (tfi + 1) % MGMT_PORT_NUM_TX_BUFFERS;
    }
    BDK_SYNCW;

    if (orcnt)
        BDK_CSR_WRITE(handle->node, BDK_MIXX_ORCNT(handle->index), orcnt);
}


/**
 * Transmit a packet
 *
 * @param handle Handle for port
 * @param packet The packet
 *
 * @return Zero on success, negative on failure
 */
static int if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    /* Note that this will never be called on CN70XX since the IPD port number
        isn't -1 */
    mgmt_port_state_t *state = handle->priv;

    if (bdk_unlikely(packet->segments != 1))
    {
        bdk_error("MGMT port doesn't support segmented packets yet\n");
        return -1;
    }

    if (bdk_unlikely(packet->length > 16383))
    {
        bdk_error("MGMT port doesn't support packets larger than 16383\n");
        return -1;
    }

    bdk_spinlock_lock(&state->tx_lock);

    poll_tx_complete(handle);

    BDK_CSR_INIT(mix_oring2, handle->node, BDK_MIXX_ORING2(handle->index));
    if (bdk_unlikely(mix_oring2.s.odbell >= MGMT_PORT_NUM_TX_BUFFERS - 1))
    {
        /* No room for another packet */
        bdk_spinlock_unlock(&state->tx_lock);
        return -1;
    }

    int twi = state->tx_write_index;
    state->tx_ring[twi].u64 = 0;
    state->tx_ring[twi].s.len = packet->length;
    state->tx_ring[twi].s.addr = packet->packet.v1.addr;
    state->tx_buf[twi] = packet->packet;
    /* Increment our TX index */
    state->tx_write_index = (twi + 1) % MGMT_PORT_NUM_TX_BUFFERS;
    /* Ring the doorbell, sending the packet */
    BDK_SYNCW;
    BDK_CSR_WRITE(handle->node, BDK_MIXX_ORING2(handle->index), 1);

    bdk_spinlock_unlock(&state->tx_lock);
    return 0;
}


/**
 * Receive a packet
 *
 * @param handle Handle for port
 * @param packet Packet to receive
 *
 * @return Zero on success, negative on failure
 */
static int if_receive(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    if (handle->ipd_port != -1)
        return -1;

    /* Find out how many RX packets are pending. As an optimization we
        check this before getting the lock */
    BDK_CSR_INIT(mix_ircnt, handle->node, BDK_MIXX_IRCNT(handle->index));
    if (mix_ircnt.s.ircnt == 0)
        return -1;

    const int FPA_SIZE = bdk_fpa_get_block_size(handle->node, BDK_FPA_PACKET_POOL);
    mgmt_port_state_t *state = handle->priv;

    bdk_spinlock_lock(&state->rx_lock);

    /* Find out how many RX packets are pending now that we have the lock */
    mix_ircnt.u64 = BDK_CSR_READ(handle->node, BDK_MIXX_IRCNT(handle->index));
    if (mix_ircnt.s.ircnt == 0)
    {
        bdk_spinlock_unlock(&state->rx_lock);
        return -1;
    }

    packet->if_handle = handle;
    packet->segments = 0;
    packet->length = 0;

    int buffers_freed = 0;
    mgmt_port_ring_entry_t entry;
    bdk_buf_ptr_t *buffer = &packet->packet;

    do
    {
        int rxi = state->rx_read_index;
        entry = state->rx_ring[rxi];

        packet->segments++;
        packet->length += entry.s.len;
        if ((entry.s.code != 15) && (entry.s.code != 16))
            packet->rx_error = entry.s.code;
        else
            packet->rx_error = 0;

        buffer->u64 = 0;
        buffer->v1.pool = BDK_FPA_PACKET_POOL;
        buffer->v1.size = FPA_SIZE - 8;
        buffer->v1.addr = entry.s.addr;
        buffer = bdk_phys_to_ptr(buffer->v1.addr-8);

        /* Update this buffer for reuse in future receives. This size is
            -8 as we need space for buffer chains */
        void *newbuf = bdk_fpa_alloc(handle->node, BDK_FPA_PACKET_POOL);
        if (newbuf == NULL)
        {
            bdk_error("Failed to allocate buffer for management port\n");
            break;
        }
        state->rx_ring[rxi].s.code = 0;
        state->rx_ring[rxi].s.len = FPA_SIZE - 8;
        state->rx_ring[rxi].s.addr = bdk_ptr_to_phys(newbuf) + 8;

        state->rx_read_index = (rxi + 1) % MGMT_PORT_NUM_RX_BUFFERS;
        buffers_freed++;
    } while (entry.s.code == 16); /* While the completion code signals more data */

    BDK_SYNCW;
    /* Increment the number of RX buffers */
    BDK_CSR_WRITE(handle->node, BDK_MIXX_IRING2(handle->index), buffers_freed);
    /* Decrement the pending RX count */
    BDK_CSR_WRITE(handle->node, BDK_MIXX_IRCNT(handle->index), 1);
    bdk_spinlock_unlock(&state->rx_lock);
    return 0;
}


/**
 * The OPs structure for bdk_if
 */
const __bdk_if_ops_t __bdk_if_ops_mgmt = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_set = if_link_set,
    .if_get_stats = if_get_stats,
    .if_transmit = if_transmit,
    .if_receive = if_receive,
};

