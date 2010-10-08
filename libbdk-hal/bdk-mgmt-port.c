#include <bdk.h>

/**
 * Enum of MIX interface modes
 */
typedef enum
{
    BDK_MGMT_PORT_NONE = 0,
    BDK_MGMT_PORT_MII_MODE,
    BDK_MGMT_PORT_RGMII_MODE,
} bdk_mgmt_port_mode_t;

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
} bdk_mgmt_port_ring_entry_t;

/**
 * Per port state required for each mgmt port
 */
typedef struct
{
    bdk_spinlock_t             lock;           /* Used for exclusive access to this structure */
    int                         tx_write_index; /* Where the next TX will write in the tx_ring and tx_buffers */
    int                         rx_read_index;  /* Where the next RX will be in the rx_ring and rx_buffers */
    uint64_t                    mac;            /* Our MAC address */
    bdk_mgmt_port_ring_entry_t tx_ring[BDK_MGMT_PORT_NUM_TX_BUFFERS];
    bdk_mgmt_port_ring_entry_t rx_ring[BDK_MGMT_PORT_NUM_RX_BUFFERS];
    char                        tx_buffers[BDK_MGMT_PORT_NUM_TX_BUFFERS][BDK_MGMT_PORT_TX_BUFFER_SIZE];
    char                        rx_buffers[BDK_MGMT_PORT_NUM_RX_BUFFERS][BDK_MGMT_PORT_RX_BUFFER_SIZE];
    bdk_mgmt_port_mode_t       mode;          /* Mode of the interface */
} bdk_mgmt_port_state_t;

/**
 * Pointers to each mgmt port's state
 */
static bdk_mgmt_port_state_t *bdk_mgmt_port_state_ptr;


/**
 * Return the number of management ports supported by this chip
 *
 * @return Number of ports
 */
int __bdk_mgmt_port_num_ports(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN56XX))
        return 1;
    else if (OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 2;
    else
        return 0;
}


/**
 * Called to initialize a management port for use. Multiple calls
 * to this function across applications is safe.
 *
 * @param port   Port to initialize
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
bdk_mgmt_port_result_t bdk_mgmt_port_initialize(int port)
{
    bdk_mixx_oring1_t oring1;
    bdk_mixx_ctl_t mix_ctl;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    if (!bdk_mgmt_port_state_ptr)
    {
        bdk_mgmt_port_state_ptr = calloc(BDK_MGMT_PORT_NUM_PORTS, sizeof(bdk_mgmt_port_state_t));
        if (!bdk_mgmt_port_state_ptr)
            return BDK_MGMT_PORT_NO_MEMORY;
    }

    /* Reset the MIX block if the previous user had a different TX ring size, or if
    ** we allocated a new (and blank) state structure. */
    mix_ctl.u64 = BDK_CSR_READ(BDK_MIXX_CTL(port));
    if (!mix_ctl.s.reset)
    {
        oring1.u64 = BDK_CSR_READ(BDK_MIXX_ORING1(port));
        if (oring1.s.osize != BDK_MGMT_PORT_NUM_TX_BUFFERS || bdk_mgmt_port_state_ptr[port].tx_ring[0].u64 == 0)
        {
            mix_ctl.u64 = BDK_CSR_READ(BDK_MIXX_CTL(port));
            mix_ctl.s.en = 0;
            BDK_CSR_WRITE(BDK_MIXX_CTL(port), mix_ctl.u64);
            do
            {
                mix_ctl.u64 = BDK_CSR_READ(BDK_MIXX_CTL(port));
            } while (mix_ctl.s.busy);
            mix_ctl.s.reset = 1;
            BDK_CSR_WRITE(BDK_MIXX_CTL(port), mix_ctl.u64);
            BDK_CSR_READ(BDK_MIXX_CTL(port));
            memset(bdk_mgmt_port_state_ptr + port, 0, sizeof(bdk_mgmt_port_state_t));
        }
    }

    if (bdk_mgmt_port_state_ptr[port].tx_ring[0].u64 == 0)
    {
        bdk_mgmt_port_state_t *state = bdk_mgmt_port_state_ptr + port;
        int i;
        bdk_mixx_bist_t mix_bist;
        bdk_agl_gmx_bist_t agl_gmx_bist;
        bdk_mixx_oring1_t oring1;
        bdk_mixx_iring1_t iring1;
        bdk_mixx_ctl_t mix_ctl;
        bdk_agl_prtx_ctl_t agl_prtx_ctl;

        /* Make sure BIST passed */
        mix_bist.u64 = BDK_CSR_READ(BDK_MIXX_BIST(port));
        if (mix_bist.u64)
            bdk_dprintf("WARNING: bdk_mgmt_port_initialize: Managment port MIX failed BIST (0x%016llx) on MIX%d\n", CAST64(mix_bist.u64), port);

        agl_gmx_bist.u64 = BDK_CSR_READ(BDK_AGL_GMX_BIST);
        if (agl_gmx_bist.u64)
            bdk_dprintf("WARNING: bdk_mgmt_port_initialize: Managment port AGL failed BIST (0x%016llx) on MIX%d\n", CAST64(agl_gmx_bist.u64), port);

        /* Clear all state information */
        memset(state, 0, sizeof(*state));

        /* Take the control logic out of reset */
        mix_ctl.u64 = BDK_CSR_READ(BDK_MIXX_CTL(port));
        mix_ctl.s.reset = 0;
        BDK_CSR_WRITE(BDK_MIXX_CTL(port), mix_ctl.u64);

        /* Read until reset == 0.  Timeout should never happen... */
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_MIXX_CTL(port), reset, ==, 0, 300000000))
        {
            bdk_dprintf("ERROR: bdk_mgmt_port_initialize: Timeout waiting for MIX(%d) reset.\n", port);
            return BDK_MGMT_PORT_INIT_ERROR;
        }

        /* Set the PHY address and mode of the interface (RGMII/MII mode). */
        {
            int phy_addr = port; //FIXME
            if (phy_addr != -1)
            {
                bdk_mdio_phy_reg_status_t phy_status;
                /* Read PHY status register to find the mode of the interface. */
                phy_status.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_STATUS);
                if (phy_status.s.capable_extended_status == 0) // MII mode
                    state->mode = BDK_MGMT_PORT_MII_MODE;
                else if (OCTEON_IS_MODEL(OCTEON_CN6XXX)
                         && phy_status.s.capable_extended_status) // RGMII mode
                    state->mode = BDK_MGMT_PORT_RGMII_MODE;
                else
                    state->mode = BDK_MGMT_PORT_NONE;
            }
            else
            {
                bdk_dprintf("ERROR: bdk_mgmt_port_initialize: Not able to read the PHY on MIX%d\n", port);
                return BDK_MGMT_PORT_INVALID_PARAM;
            }
        }

        /* All interfaces should be configured in same mode */
        for (i = 0; i < __bdk_mgmt_port_num_ports(); i++)
        {
            if (i != port
                && bdk_mgmt_port_state_ptr[i].mode != BDK_MGMT_PORT_NONE
                && bdk_mgmt_port_state_ptr[i].mode != state->mode)
            {
                bdk_dprintf("ERROR: bdk_mgmt_port_initialize: All ports in MIX interface are not configured in same mode.\n \
	Port %d is configured as %d\n \
	And Port %d is configured as %d\n", port, state->mode, i, bdk_mgmt_port_state_ptr[i].mode);
                return BDK_MGMT_PORT_INVALID_PARAM;
            }
        }

        /* Create a default MAC address */
        state->mac = 0x000000dead000000ull;
        state->mac += 0xffffff & CAST64(state);

        /* Setup the TX ring */
        for (i=0; i<BDK_MGMT_PORT_NUM_TX_BUFFERS; i++)
        {
            state->tx_ring[i].s.len = BDK_MGMT_PORT_TX_BUFFER_SIZE;
            state->tx_ring[i].s.addr = bdk_ptr_to_phys(state->tx_buffers[i]);
        }

        /* Tell the HW where the TX ring is */
        oring1.u64 = 0;
        oring1.s.obase = bdk_ptr_to_phys(state->tx_ring)>>3;
        oring1.s.osize = BDK_MGMT_PORT_NUM_TX_BUFFERS;
        BDK_SYNCW;
        BDK_CSR_WRITE(BDK_MIXX_ORING1(port), oring1.u64);

        /* Setup the RX ring */
        for (i=0; i<BDK_MGMT_PORT_NUM_RX_BUFFERS; i++)
        {
            /* This size is -8 due to an errata for CN56XX pass 1 */
            state->rx_ring[i].s.len = BDK_MGMT_PORT_RX_BUFFER_SIZE - 8;
            state->rx_ring[i].s.addr = bdk_ptr_to_phys(state->rx_buffers[i]);
        }

        /* Tell the HW where the RX ring is */
        iring1.u64 = 0;
        iring1.s.ibase = bdk_ptr_to_phys(state->rx_ring)>>3;
        iring1.s.isize = BDK_MGMT_PORT_NUM_RX_BUFFERS;
        BDK_SYNCW;
        BDK_CSR_WRITE(BDK_MIXX_IRING1(port), iring1.u64);
        BDK_CSR_WRITE(BDK_MIXX_IRING2(port), BDK_MGMT_PORT_NUM_RX_BUFFERS);

        /* Disable the external input/output */
        bdk_mgmt_port_disable(port);

        /* Set the MAC address filtering up */
        bdk_mgmt_port_set_mac(port, state->mac);

        /* Set the default max size to an MTU of 1500 with L2 and VLAN */
        bdk_mgmt_port_set_max_packet_size(port, 1518);

        /* Enable the port HW. Packets are not allowed until bdk_mgmt_port_enable() is called */
        mix_ctl.u64 = 0;
        mix_ctl.s.crc_strip = 1;    /* Strip the ending CRC */
        mix_ctl.s.en = 1;           /* Enable the port */
        mix_ctl.s.nbtarb = 0;       /* Arbitration mode */
        mix_ctl.s.mrq_hwm = 1;      /* MII CB-request FIFO programmable high watermark */
        BDK_CSR_WRITE(BDK_MIXX_CTL(port), mix_ctl.u64);

        /* Select the mode of operation for the interface. */
        if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
        {
            agl_prtx_ctl.u64 = BDK_CSR_READ(BDK_AGL_PRTX_CTL(port));

            if (state->mode == BDK_MGMT_PORT_RGMII_MODE)
                agl_prtx_ctl.s.mode = 0;
            else if (state->mode == BDK_MGMT_PORT_MII_MODE)
                agl_prtx_ctl.s.mode = 1;
            else
            {
                bdk_dprintf("ERROR: bdk_mgmt_port_initialize: Invalid mode for MIX(%d)\n", port);
                return BDK_MGMT_PORT_INVALID_PARAM;
            }

            BDK_CSR_WRITE(BDK_AGL_PRTX_CTL(port), agl_prtx_ctl.u64);
	}

        /* Initialize the physical layer. */
        if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
        {
            /* MII clocks counts are based on the 125Mhz reference, so our
                delays need to be scaled to match the core clock rate. The
                "+1" is to make sure rounding always waits a little too
                long. */
            uint64_t clock_scale = bdk_clock_get_rate(BDK_CLOCK_CORE) / 125000000 + 1;

            /* Take the DLL and clock tree out of reset */
            agl_prtx_ctl.u64 = BDK_CSR_READ(BDK_AGL_PRTX_CTL(port));
            agl_prtx_ctl.s.clkrst = 0;
            if (state->mode == BDK_MGMT_PORT_RGMII_MODE) // RGMII Initialization
            {
                agl_prtx_ctl.s.dllrst = 0;
                agl_prtx_ctl.s.clktx_byp = 0;
            }
            BDK_CSR_WRITE(BDK_AGL_PRTX_CTL(port), agl_prtx_ctl.u64);
            BDK_CSR_READ(BDK_AGL_PRTX_CTL(port));  /* Force write out before wait */

            /* Wait for the DLL to lock.  External 125 MHz reference clock must be stable at this point. */
            bdk_wait(256 * clock_scale);

            /* The rest of the config is common between RGMII/MII */

            /* Enable the interface */
            agl_prtx_ctl.u64 = BDK_CSR_READ(BDK_AGL_PRTX_CTL(port));
            agl_prtx_ctl.s.enable = 1;
            BDK_CSR_WRITE(BDK_AGL_PRTX_CTL(port), agl_prtx_ctl.u64);

            /* Read the value back to force the previous write */
            agl_prtx_ctl.u64 = BDK_CSR_READ(BDK_AGL_PRTX_CTL(port));

            /* Enable the componsation controller */
            agl_prtx_ctl.s.comp = 1;
            BDK_CSR_WRITE(BDK_AGL_PRTX_CTL(port), agl_prtx_ctl.u64);
            BDK_CSR_READ(BDK_AGL_PRTX_CTL(port));  /* Force write out before wait */
            bdk_wait(1024 * clock_scale); // for componsation state to lock.
        }
        else if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X) || OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
        {
            /* Force compensation values, as they are not determined properly by HW */
            bdk_agl_gmx_drv_ctl_t drv_ctl;

            drv_ctl.u64 = BDK_CSR_READ(BDK_AGL_GMX_DRV_CTL);
            if (port)
            {
                drv_ctl.s.byp_en1 = 1;
                drv_ctl.s.nctl1 = 6;
                drv_ctl.s.pctl1 = 6;
            }
            else
            {
                drv_ctl.s.byp_en = 1;
                drv_ctl.s.nctl = 6;
                drv_ctl.s.pctl = 6;
            }
            BDK_CSR_WRITE(BDK_AGL_GMX_DRV_CTL, drv_ctl.u64);
        }
    }
    return BDK_MGMT_PORT_SUCCESS;
}


/**
 * Shutdown a management port. This currently disables packet IO
 * but leaves all hardware and buffers. Another application can then
 * call initialize() without redoing the hardware setup.
 *
 * @param port   Management port
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
bdk_mgmt_port_result_t bdk_mgmt_port_shutdown(int port)
{
    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    /* Stop packets from comming in */
    bdk_mgmt_port_disable(port);

    /* We don't free any memory so the next intialize can reuse the HW setup */
    return BDK_MGMT_PORT_SUCCESS;
}


/**
 * Enable packet IO on a management port
 *
 * @param port   Management port
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
bdk_mgmt_port_result_t bdk_mgmt_port_enable(int port)
{
    bdk_mgmt_port_state_t *state;
    bdk_agl_gmx_inf_mode_t agl_gmx_inf_mode;
    bdk_agl_gmx_rxx_frm_ctl_t rxx_frm_ctl;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);

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
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_FRM_CTL(port), rxx_frm_ctl.u64);

    /* Enable the AGL block */
    if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
    {
        agl_gmx_inf_mode.u64 = 0;
        agl_gmx_inf_mode.s.en = 1;
        BDK_CSR_WRITE(BDK_AGL_GMX_INF_MODE, agl_gmx_inf_mode.u64);
    }

    /* Configure the port duplex and enables */
    bdk_mgmt_port_link_set(port, bdk_mgmt_port_link_get(port));

    bdk_spinlock_unlock(&state->lock);
    return BDK_MGMT_PORT_SUCCESS;
}


/**
 * Disable packet IO on a management port
 *
 * @param port   Management port
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
bdk_mgmt_port_result_t bdk_mgmt_port_disable(int port)
{
    bdk_mgmt_port_state_t *state;
    bdk_agl_gmx_prtx_cfg_t agl_gmx_prtx;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);

    agl_gmx_prtx.u64 = BDK_CSR_READ(BDK_AGL_GMX_PRTX_CFG(port));
    agl_gmx_prtx.s.en = 0;
    BDK_CSR_WRITE(BDK_AGL_GMX_PRTX_CFG(port), agl_gmx_prtx.u64);

    bdk_spinlock_unlock(&state->lock);
    return BDK_MGMT_PORT_SUCCESS;
}


/**
 * Send a packet out the management port. The packet is copied so
 * the input buffer isn't used after this call.
 *
 * @param port       Management port
 * @param packet_len Length of the packet to send. It does not include the final CRC
 * @param buffer     Packet data
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
bdk_mgmt_port_result_t bdk_mgmt_port_send(int port, int packet_len, const void *buffer)
{
    bdk_mgmt_port_state_t *state;
    bdk_mixx_oring2_t mix_oring2;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    /* Max sure the packet size is valid */
    if ((packet_len < 1) || (packet_len > BDK_MGMT_PORT_TX_BUFFER_SIZE))
        return BDK_MGMT_PORT_INVALID_PARAM;

    if (buffer == NULL)
        return BDK_MGMT_PORT_INVALID_PARAM;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);

    mix_oring2.u64 = BDK_CSR_READ(BDK_MIXX_ORING2(port));
    if (mix_oring2.s.odbell >= BDK_MGMT_PORT_NUM_TX_BUFFERS - 1)
    {
        /* No room for another packet */
        bdk_spinlock_unlock(&state->lock);
        return BDK_MGMT_PORT_NO_MEMORY;
    }
    else
    {
        /* Copy the packet into the output buffer */
        memcpy(state->tx_buffers[state->tx_write_index], buffer, packet_len);
        /* Insert the source MAC */
        memcpy(state->tx_buffers[state->tx_write_index] + 6, ((char*)&state->mac) + 2, 6);
        /* Update the TX ring buffer entry size */
        state->tx_ring[state->tx_write_index].s.len = packet_len;
        /* This code doesn't support TX timestamps */
        state->tx_ring[state->tx_write_index].s.tstamp = 0;
        /* Increment our TX index */
        state->tx_write_index = (state->tx_write_index + 1) % BDK_MGMT_PORT_NUM_TX_BUFFERS;
        /* Ring the doorbell, sending the packet */
        BDK_SYNCW;
        BDK_CSR_WRITE(BDK_MIXX_ORING2(port), 1);
        if (BDK_CSR_READ(BDK_MIXX_ORCNT(port)))
            BDK_CSR_WRITE(BDK_MIXX_ORCNT(port), BDK_CSR_READ(BDK_MIXX_ORCNT(port)));

        bdk_spinlock_unlock(&state->lock);
        return BDK_MGMT_PORT_SUCCESS;
    }
}


/**
 * Receive a packet from the management port.
 *
 * @param port       Management port
 * @param buffer_len Size of the buffer to receive the packet into
 * @param buffer     Buffer to receive the packet into
 *
 * @return The size of the packet, or a negative erorr code on failure. Zero
 *         means that no packets were available.
 */
int bdk_mgmt_port_receive(int port, int buffer_len, void *buffer)
{
    bdk_mixx_ircnt_t mix_ircnt;
    bdk_mgmt_port_state_t *state;
    int result;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    /* Max sure the buffer size is valid */
    if (buffer_len < 1)
        return BDK_MGMT_PORT_INVALID_PARAM;

    if (buffer == NULL)
        return BDK_MGMT_PORT_INVALID_PARAM;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);

    /* Find out how many RX packets are pending */
    mix_ircnt.u64 = BDK_CSR_READ(BDK_MIXX_IRCNT(port));
    if (mix_ircnt.s.ircnt)
    {
        void *source = state->rx_buffers[state->rx_read_index];
        uint64_t *zero_check = source;
        /* CN56XX pass 1 has an errata where packets might start 8 bytes
            into the buffer instead of at their correct lcoation. If the
            first 8 bytes is zero we assume this has happened */
        if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X) && (*zero_check == 0))
            source += 8;
        /* Start off with zero bytes received */
        result = 0;
        /* While the completion code signals more data, copy the buffers
            into the user's data */
        while (state->rx_ring[state->rx_read_index].s.code == 16)
        {
            /* Only copy what will fit in the user's buffer */
            int length = state->rx_ring[state->rx_read_index].s.len;
            if (length > buffer_len)
                length = buffer_len;
            memcpy(buffer, source, length);
            /* Reduce the size of the buffer to the remaining space. If we run
                out we will signal an error when the code 15 buffer doesn't fit */
            buffer += length;
            buffer_len -= length;
            result += length;
            /* Update this buffer for reuse in future receives. This size is
                -8 due to an errata for CN56XX pass 1 */
            state->rx_ring[state->rx_read_index].s.code = 0;
            state->rx_ring[state->rx_read_index].s.len = BDK_MGMT_PORT_RX_BUFFER_SIZE - 8;
            state->rx_read_index = (state->rx_read_index + 1) % BDK_MGMT_PORT_NUM_RX_BUFFERS;
            /* Zero the beginning of the buffer for use by the errata check */
            *zero_check = 0;
            BDK_SYNCW;
            /* Increment the number of RX buffers */
            BDK_CSR_WRITE(BDK_MIXX_IRING2(port), 1);
            source = state->rx_buffers[state->rx_read_index];
            zero_check = source;
        }

        /* Check for the final good completion code */
        if (state->rx_ring[state->rx_read_index].s.code == 15)
        {
            if (buffer_len >= state->rx_ring[state->rx_read_index].s.len)
            {
                int length = state->rx_ring[state->rx_read_index].s.len;
                memcpy(buffer, source, length);
                result += length;
            }
            else
            {
                /* Not enough room for the packet */
                bdk_dprintf("ERROR: bdk_mgmt_port_receive: Packet (%d) larger than supplied buffer (%d)\n", state->rx_ring[state->rx_read_index].s.len, buffer_len);
                result = BDK_MGMT_PORT_NO_MEMORY;
            }
        }
        else
        {
            bdk_dprintf("ERROR: bdk_mgmt_port_receive: Receive error code %d. Packet dropped(Len %d), \n",
                         state->rx_ring[state->rx_read_index].s.code, state->rx_ring[state->rx_read_index].s.len + result);
            result = -state->rx_ring[state->rx_read_index].s.code;


            /* Check to see if we need to change the duplex. */
            bdk_mgmt_port_link_set(port, bdk_mgmt_port_link_get(port));
        }

        /* Clean out the ring buffer entry. This size is -8 due to an errata
            for CN56XX pass 1 */
        state->rx_ring[state->rx_read_index].s.code = 0;
        state->rx_ring[state->rx_read_index].s.len = BDK_MGMT_PORT_RX_BUFFER_SIZE - 8;
        state->rx_read_index = (state->rx_read_index + 1) % BDK_MGMT_PORT_NUM_RX_BUFFERS;
        /* Zero the beginning of the buffer for use by the errata check */
        *zero_check = 0;
        BDK_SYNCW;
        /* Increment the number of RX buffers */
        BDK_CSR_WRITE(BDK_MIXX_IRING2(port), 1);
        /* Decrement the pending RX count */
        BDK_CSR_WRITE(BDK_MIXX_IRCNT(port), 1);
    }
    else
    {
        /* No packets available */
        result = 0;
    }
    bdk_spinlock_unlock(&state->lock);
    return result;
}

/**
 * Set the MAC address for a management port
 *
 * @param port   Management port
 * @param mac    New MAC address. The lower 6 bytes are used.
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
bdk_mgmt_port_result_t bdk_mgmt_port_set_mac(int port, uint64_t mac)
{
    bdk_mgmt_port_state_t *state;
    bdk_agl_gmx_rxx_adr_ctl_t agl_gmx_rxx_adr_ctl;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);

    agl_gmx_rxx_adr_ctl.u64 = 0;
    agl_gmx_rxx_adr_ctl.s.cam_mode = 1; /* Only accept matching MAC addresses */
    agl_gmx_rxx_adr_ctl.s.mcst = 0;     /* Drop multicast */
    agl_gmx_rxx_adr_ctl.s.bcst = 1;     /* Allow broadcast */
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CTL(port), agl_gmx_rxx_adr_ctl.u64);

    /* Only using one of the CAMs */
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM0(port), (mac >> 40) & 0xff);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM1(port), (mac >> 32) & 0xff);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM2(port), (mac >> 24) & 0xff);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM3(port), (mac >> 16) & 0xff);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM4(port), (mac >> 8) & 0xff);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM5(port), (mac >> 0) & 0xff);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM_EN(port), 1);
    state->mac = mac;

    bdk_spinlock_unlock(&state->lock);
    return BDK_MGMT_PORT_SUCCESS;
}


/**
 * Get the MAC address for a management port
 *
 * @param port   Management port
 *
 * @return MAC address
 */
uint64_t bdk_mgmt_port_get_mac(int port)
{
    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return BDK_MGMT_PORT_INVALID_PARAM;

    return bdk_mgmt_port_state_ptr[port].mac;
}

/**
 * Set the multicast list.
 *
 * @param port   Management port
 * @param flags  Interface flags
 *
 * @return
 */
void bdk_mgmt_port_set_multicast_list(int port, int flags)
{
    bdk_mgmt_port_state_t *state;
    bdk_agl_gmx_rxx_adr_ctl_t agl_gmx_rxx_adr_ctl;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);

    agl_gmx_rxx_adr_ctl.u64 = BDK_CSR_READ(BDK_AGL_GMX_RXX_ADR_CTL(port));

    /* Allow broadcast MAC addresses */
    if (!agl_gmx_rxx_adr_ctl.s.bcst)
	agl_gmx_rxx_adr_ctl.s.bcst = 1;

    if ((flags & BDK_IFF_ALLMULTI) || (flags & BDK_IFF_PROMISC))
	agl_gmx_rxx_adr_ctl.s.mcst = 2; /* Force accept multicast packets */
    else
	agl_gmx_rxx_adr_ctl.s.mcst = 1; /* Force reject multicast packets */

    if (flags & BDK_IFF_PROMISC)
	agl_gmx_rxx_adr_ctl.s.cam_mode = 0; /* Reject matches if promisc. Since CAM is shut off, should accept everything */
    else
	agl_gmx_rxx_adr_ctl.s.cam_mode = 1; /* Filter packets based on the CAM */

    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CTL(port), agl_gmx_rxx_adr_ctl.u64);

    if (flags & BDK_IFF_PROMISC)
	BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM_EN(port), 0);
    else
	BDK_CSR_WRITE(BDK_AGL_GMX_RXX_ADR_CAM_EN(port), 1);

    bdk_spinlock_unlock(&state->lock);
}


/**
 * Set the maximum packet allowed in. Size is specified
 * including L2 but without FCS. A normal MTU would corespond
 * to 1514 assuming the standard 14 byte L2 header.
 *
 * @param port   Management port
 * @param size_without_fcs
 *               Size in bytes without FCS
 */
void bdk_mgmt_port_set_max_packet_size(int port, int size_without_fcs)
{
    bdk_mgmt_port_state_t *state;

    if ((port < 0) || (port >= __bdk_mgmt_port_num_ports()))
        return;

    state = bdk_mgmt_port_state_ptr + port;

    bdk_spinlock_lock(&state->lock);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_FRM_MAX(port), size_without_fcs);
    BDK_CSR_WRITE(BDK_AGL_GMX_RXX_JABBER(port), (size_without_fcs+7) & 0xfff8);
    bdk_spinlock_unlock(&state->lock);
}

/**
 * Return the link state of an RGMII/MII port as returned by
 * auto negotiation. The result of this function may not match
 * Octeon's link config if auto negotiation has changed since
 * the last call to bdk_mgmt_port_link_set().
 *
 * @param port     The RGMII/MII interface port to query
 *
 * @return Link state
 */
bdk_helper_link_info_t bdk_mgmt_port_link_get(int port)
{
    bdk_mgmt_port_state_t *state;
    bdk_helper_link_info_t result;

    state = bdk_mgmt_port_state_ptr + port;
    result.u64 = 0;

    if (port > __bdk_mgmt_port_num_ports())
    {
        bdk_dprintf("WARNING: Invalid port %d\n", port);
        return result;
    }

    if (0) // FIXME PHY
        return result;
    else // Simulator does not have PHY, use some defaults.
    {
        result.s.full_duplex = 1;
        result.s.link_up = 1;
        result.s.speed = 1000;
        return result;
    }
    return result;
}

/**
 * Configure RGMII/MII port for the specified link state. This
 * function does not influence auto negotiation at the PHY level.
 *
 * @param port      RGMII/MII interface port
 * @param link_info The new link state
 *
 * @return Zero on success, negative on failure
 */
int bdk_mgmt_port_link_set(int port, bdk_helper_link_info_t link_info)
{
    bdk_agl_gmx_prtx_cfg_t agl_gmx_prtx;

    /* Disable GMX before we make any changes. */
    agl_gmx_prtx.u64 = BDK_CSR_READ(BDK_AGL_GMX_PRTX_CFG(port));
    agl_gmx_prtx.s.en = 0;
    agl_gmx_prtx.s.tx_en = 0;
    agl_gmx_prtx.s.rx_en = 0;
    BDK_CSR_WRITE(BDK_AGL_GMX_PRTX_CFG(port), agl_gmx_prtx.u64);

    if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
    {
        uint64_t one_second = bdk_clock_get_rate(BDK_CLOCK_CORE);
        /* Wait for GMX to be idle */
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_AGL_GMX_PRTX_CFG(port), rx_idle, ==, 1, one_second)
            || BDK_CSR_WAIT_FOR_FIELD(BDK_AGL_GMX_PRTX_CFG(port), tx_idle, ==, 1, one_second))
        {
            bdk_dprintf("MIX%d: Timeout waiting for GMX to be idle\n", port);
            return -1;
        }
    }

    agl_gmx_prtx.u64 = BDK_CSR_READ(BDK_AGL_GMX_PRTX_CFG(port));

    /* Set duplex mode */
    if (!link_info.s.link_up)
        agl_gmx_prtx.s.duplex = 1;   /* Force full duplex on down links */
    else
        agl_gmx_prtx.s.duplex = link_info.s.full_duplex;

   switch(link_info.s.speed)
    {
        case 10:
            agl_gmx_prtx.s.speed = 0;
            agl_gmx_prtx.s.slottime = 0;
            if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
            {
                agl_gmx_prtx.s.speed_msb = 1;
                agl_gmx_prtx.s.burst = 1;
            }
         break;

        case 100:
            agl_gmx_prtx.s.speed = 0;
            agl_gmx_prtx.s.slottime = 0;
            if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
            {
                agl_gmx_prtx.s.speed_msb = 0;
                agl_gmx_prtx.s.burst = 1;
            }
            break;

        case 1000:
            /* 1000 MBits is only supported on 6XXX chips */
            if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
            {
                agl_gmx_prtx.s.speed_msb = 0;
                agl_gmx_prtx.s.speed = 1;
                agl_gmx_prtx.s.slottime = 1;  /* Only matters for half-duplex */
                agl_gmx_prtx.s.burst = agl_gmx_prtx.s.duplex;
            }
            break;

        /* No link */
        case 0:
        default:
            break;
    }

    /* Write the new GMX setting with the port still disabled. */
    BDK_CSR_WRITE(BDK_AGL_GMX_PRTX_CFG(port), agl_gmx_prtx.u64);

    /* Read GMX CFG again to make sure the config is completed. */
    agl_gmx_prtx.u64 = BDK_CSR_READ(BDK_AGL_GMX_PRTX_CFG(port));


    if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
    {
        bdk_mgmt_port_state_t *state = bdk_mgmt_port_state_ptr + port;
        bdk_agl_gmx_txx_clk_t agl_clk;
        agl_clk.u64 = BDK_CSR_READ(BDK_AGL_GMX_TXX_CLK(port));
        agl_clk.s.clk_cnt = 1;    /* MII (both speeds) and RGMII 1000 setting */
        if (state->mode == BDK_MGMT_PORT_RGMII_MODE)
        {
            if (link_info.s.speed == 10)
                agl_clk.s.clk_cnt = 50;
            else if (link_info.s.speed == 100)
                agl_clk.s.clk_cnt = 5;
        }
        BDK_CSR_WRITE(BDK_AGL_GMX_TXX_CLK(port), agl_clk.u64);
    }

    /* Enable transmit and receive ports */
    agl_gmx_prtx.s.tx_en = 1;
    agl_gmx_prtx.s.rx_en = 1;
    BDK_CSR_WRITE(BDK_AGL_GMX_PRTX_CFG(port), agl_gmx_prtx.u64);

    /* Enable the link. */
    agl_gmx_prtx.s.en = 1;
    BDK_CSR_WRITE(BDK_AGL_GMX_PRTX_CFG(port), agl_gmx_prtx.u64);
    return 0;
}
