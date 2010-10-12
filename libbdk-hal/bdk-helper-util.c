#include <bdk.h>
#include <stdio.h>

/**
 * Convert a interface mode into a human readable string
 *
 * @param mode   Mode to convert
 *
 * @return String
 */
const char *bdk_helper_interface_mode_to_string(bdk_helper_interface_mode_t mode)
{
    switch (mode)
    {
        case BDK_HELPER_INTERFACE_MODE_DISABLED:   return "DISABLED";
        case BDK_HELPER_INTERFACE_MODE_PCIE:       return "PCIE";
        case BDK_HELPER_INTERFACE_MODE_XAUI:       return "XAUI";
        case BDK_HELPER_INTERFACE_MODE_SGMII:      return "SGMII";
        case BDK_HELPER_INTERFACE_MODE_PICMG:      return "PICMG";
        case BDK_HELPER_INTERFACE_MODE_NPI:        return "NPI";
        case BDK_HELPER_INTERFACE_MODE_LOOP:       return "LOOP";
        case BDK_HELPER_INTERFACE_MODE_SRIO:       return "SRIO";
    }
    return "UNKNOWN";
}


/**
 * Debug routine to dump the packet structure to the console
 *
 * @param work   Work queue entry containing the packet to dump
 * @return
 */
int bdk_helper_dump_packet(bdk_wqe_t *work)
{
    uint64_t        count;
    uint64_t        remaining_bytes;
    bdk_buf_ptr_t  buffer_ptr;
    uint64_t        start_of_buffer;
    uint8_t *       data_address;
    uint8_t *       end_of_data;

    printf("Packet Length:   %u\n", work->len);
    printf("    Input Port:  %u\n", work->ipprt);
    printf("    QoS:         %u\n", work->qos);
    printf("    Buffers:     %u\n", work->word2.s.bufs);

    if (work->word2.s.bufs == 0)
    {
        bdk_ipd_wqe_fpa_queue_t wqe_pool;
        wqe_pool.u64 = BDK_CSR_READ(BDK_IPD_WQE_FPA_QUEUE);
        buffer_ptr.u64 = 0;
        buffer_ptr.s.pool = wqe_pool.s.wqe_pool;
        buffer_ptr.s.size = 128;
        buffer_ptr.s.addr = bdk_ptr_to_phys(work->packet_data);
        if (bdk_likely(!work->word2.s.not_IP))
        {
            bdk_pip_ip_offset_t pip_ip_offset;
            pip_ip_offset.u64 = BDK_CSR_READ(BDK_PIP_IP_OFFSET);
            buffer_ptr.s.addr += (pip_ip_offset.s.offset<<3) - work->word2.s.ip_offset;
            buffer_ptr.s.addr += (work->word2.s.is_v6^1)<<2;
        }
        else
        {
            /* WARNING: This code assume that the packet is not RAW. If it was,
                we would use PIP_GBL_CFG[RAW_SHF] instead of
                PIP_GBL_CFG[NIP_SHF] */
            bdk_pip_gbl_cfg_t pip_gbl_cfg;
            pip_gbl_cfg.u64 = BDK_CSR_READ(BDK_PIP_GBL_CFG);
            buffer_ptr.s.addr += pip_gbl_cfg.s.nip_shf;
        }
    }
    else
        buffer_ptr = work->packet_ptr;
    remaining_bytes = work->len;

    while (remaining_bytes)
    {
        start_of_buffer = ((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
        printf("    Buffer Start:%llx\n", (unsigned long long)start_of_buffer);
        printf("    Buffer I   : %u\n", buffer_ptr.s.i);
        printf("    Buffer Back: %u\n", buffer_ptr.s.back);
        printf("    Buffer Pool: %u\n", buffer_ptr.s.pool);
        printf("    Buffer Data: %llx\n", (unsigned long long)buffer_ptr.s.addr);
        printf("    Buffer Size: %u\n", buffer_ptr.s.size);

        printf("\t\t");
        data_address = (uint8_t *)bdk_phys_to_ptr(buffer_ptr.s.addr);
        end_of_data = data_address + buffer_ptr.s.size;
        count = 0;
        while (data_address < end_of_data)
        {
            if (remaining_bytes == 0)
                break;
            else
                remaining_bytes--;
            printf("%02x", (unsigned int)*data_address);
            data_address++;
            if (remaining_bytes && (count == 7))
            {
                printf("\n\t\t");
                count = 0;
            }
            else
                count++;
        }
        printf("\n");

        if (remaining_bytes)
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }
    return 0;
}


/**
 * Setup Random Early Drop on a specific input queue
 *
 * @param queue  Input queue to setup RED on (0-7)
 * @param pass_thresh
 *               Packets will begin slowly dropping when there are less than
 *               this many packet buffers free in FPA 0.
 * @param drop_thresh
 *               All incomming packets will be dropped when there are less
 *               than this many free packet buffers in FPA 0.
 * @return Zero on success. Negative on failure
 */
int bdk_helper_setup_red_queue(int queue, int pass_thresh, int drop_thresh)
{
    bdk_ipd_qosx_red_marks_t red_marks;
    bdk_ipd_red_quex_param_t red_param;

    /* Set RED to begin dropping packets when there are pass_thresh buffers
        left. It will linearly drop more packets until reaching drop_thresh
        buffers */
    red_marks.u64 = 0;
    red_marks.s.drop = drop_thresh;
    red_marks.s.pass = pass_thresh;
    BDK_CSR_WRITE(BDK_IPD_QOSX_RED_MARKS(queue), red_marks.u64);

    /* Use the actual queue 0 counter, not the average */
    red_param.u64 = 0;
    red_param.s.prb_con = (255ul<<24) / (red_marks.s.pass - red_marks.s.drop);
    red_param.s.avg_con = 1;
    red_param.s.new_con = 255;
    red_param.s.use_pcnt = 1;
    BDK_CSR_WRITE(BDK_IPD_RED_QUEX_PARAM(queue), red_param.u64);
    return 0;
}


/**
 * Setup Random Early Drop to automatically begin dropping packets.
 *
 * @param pass_thresh
 *               Packets will begin slowly dropping when there are less than
 *               this many packet buffers free in FPA 0.
 * @param drop_thresh
 *               All incomming packets will be dropped when there are less
 *               than this many free packet buffers in FPA 0.
 * @return Zero on success. Negative on failure
 */
int bdk_helper_setup_red(int pass_thresh, int drop_thresh)
{
    bdk_ipd_portx_bp_page_cnt_t page_cnt;
    bdk_ipd_bp_prt_red_end_t ipd_bp_prt_red_end;
    bdk_ipd_red_port_enable_t red_port_enable;
    int queue;
    int interface;
    int port;

    /* Disable backpressure based on queued buffers. It needs SW support */
    page_cnt.u64 = 0;
    page_cnt.s.bp_enb = 0;
    page_cnt.s.page_cnt = 100;
    for (interface=0; interface<2; interface++)
    {
        for (port=bdk_helper_get_first_ipd_port(interface); port<bdk_helper_get_last_ipd_port(interface); port++)
            BDK_CSR_WRITE(BDK_IPD_PORTX_BP_PAGE_CNT(port), page_cnt.u64);
    }

    for (queue=0; queue<8; queue++)
        bdk_helper_setup_red_queue(queue, pass_thresh, drop_thresh);

    /* Shutoff the dropping based on the per port page count. SW isn't
        decrementing it right now */
    ipd_bp_prt_red_end.u64 = 0;
    ipd_bp_prt_red_end.s.prt_enb = 0;
    BDK_CSR_WRITE(BDK_IPD_BP_PRT_RED_END, ipd_bp_prt_red_end.u64);

    red_port_enable.u64 = 0;
    red_port_enable.s.prt_enb = 0xfffffffffull;
    red_port_enable.s.avg_dly = 10000;
    red_port_enable.s.prb_dly = 10000;
    BDK_CSR_WRITE(BDK_IPD_RED_PORT_ENABLE, red_port_enable.u64);

    /* Shutoff the dropping of packets based on RED for SRIO ports */
    if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
    {
        bdk_ipd_red_port_enable2_t red_port_enable2;
        red_port_enable2.u64 = 0;
        red_port_enable2.s.prt_enb = 0xf0;
        BDK_CSR_WRITE(BDK_IPD_RED_PORT_ENABLE2, red_port_enable2.u64);
    }

    return 0;
}


/**
 * @INTERNAL
 * Setup the common GMX settings that determine the number of
 * ports. These setting apply to almost all configurations of all
 * chips.
 *
 * @param interface Interface to configure
 * @param num_ports Number of ports on the interface
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_setup_gmx(int interface, int num_ports)
{
    bdk_gmxx_txx_thresh_t gmx_tx_thresh;
    int index;

    /* Tell GMX the number of TX ports on this interface */
    BDK_CSR_MODIFY(gmx_tx_prts, BDK_GMXX_TX_PRTS(interface),
        gmx_tx_prts.s.prts = num_ports);

    /* Tell GMX the number of RX ports on this interface.  This only
    ** applies to *GMII and XAUI ports */
    if (bdk_helper_interface_get_mode(interface) == BDK_HELPER_INTERFACE_MODE_SGMII
        || bdk_helper_interface_get_mode(interface) == BDK_HELPER_INTERFACE_MODE_XAUI)
    {
        if (num_ports > 4)
        {
            bdk_error("__bdk_helper_setup_gmx: Illegal num_ports\n");
            return(-1);
        }

        BDK_CSR_MODIFY(gmx_rx_prts, BDK_GMXX_RX_PRTS(interface),
            gmx_rx_prts.s.prts = num_ports);
    }

    {
        /* Tell PKO the number of ports on this interface */
        BDK_CSR_MODIFY(pko_mode, BDK_PKO_REG_GMX_PORT_MODE,
            if (interface == 0)
            {
                if (num_ports == 1)
                    pko_mode.s.mode0 = 4;
                else if (num_ports == 2)
                    pko_mode.s.mode0 = 3;
                else if (num_ports <= 4)
                    pko_mode.s.mode0 = 2;
                else if (num_ports <= 8)
                    pko_mode.s.mode0 = 1;
                else
                    pko_mode.s.mode0 = 0;
            }
            else
            {
                if (num_ports == 1)
                    pko_mode.s.mode1 = 4;
                else if (num_ports == 2)
                    pko_mode.s.mode1 = 3;
                else if (num_ports <= 4)
                    pko_mode.s.mode1 = 2;
                else if (num_ports <= 8)
                    pko_mode.s.mode1 = 1;
                else
                    pko_mode.s.mode1 = 0;
            });
    }

    /* Set GMX to buffer as much data as possible before starting transmit.
        This reduces the chances that we have a TX under run due to memory
        contention. Any packet that fits entirely in the GMX FIFO can never
        have an under run regardless of memory load */
    gmx_tx_thresh.u64 = BDK_CSR_READ(BDK_GMXX_TXX_THRESH(0, interface));
    {
        /* Choose the max value for the number of ports */
        if (num_ports <= 1)
            gmx_tx_thresh.s.cnt = 0x100 / 1;
        else if (num_ports == 2)
            gmx_tx_thresh.s.cnt = 0x100 / 2;
        else
            gmx_tx_thresh.s.cnt = 0x100 / 4;
    }
    /* SPI and XAUI can have lots of ports but the GMX hardware only ever has
        a max of 4 */
    if (num_ports > 4)
        num_ports = 4;
    for (index=0; index<num_ports; index++)
        BDK_CSR_WRITE(BDK_GMXX_TXX_THRESH(index, interface), gmx_tx_thresh.u64);

    return 0;
}


/**
 * Returns the IPD/PKO port number for a port on the given
 * interface.
 *
 * @param interface Interface to use
 * @param port      Port on the interface
 *
 * @return IPD/PKO port number
 */
int bdk_helper_get_ipd_port(int interface, int port)
{
    switch (interface)
    {
        case 0: return port;
        case 1: return port + 16;
        case 2: return port + 32;
        case 3: return port + 36;
        case 4: return port + 40;
        case 5: return port + 42;
    }
    return -1;
}


/**
 * Returns the interface number for an IPD/PKO port number.
 *
 * @param ipd_port IPD/PKO port number
 *
 * @return Interface number
 */
int bdk_helper_get_interface_num(int ipd_port)
{
    if (ipd_port < 16)
        return 0;
    else if (ipd_port < 32)
        return 1;
    else if (ipd_port < 36)
        return 2;
    else if (ipd_port < 40)
        return 3;
    else if (ipd_port < 42)
	return 4;
    else if (ipd_port < 44)
	return 5;
    else
        bdk_error("bdk_helper_get_interface_num: Illegal IPD port number\n");

    return -1;
}


/**
 * Returns the interface index number for an IPD/PKO port
 * number.
 *
 * @param ipd_port IPD/PKO port number
 *
 * @return Interface index number
 */
int bdk_helper_get_interface_index_num(int ipd_port)
{
    if (ipd_port < 32)
        return ipd_port & 15;
    else if (ipd_port < 40)
        return ipd_port & 3;
    else if (ipd_port < 44)
	return ipd_port & 1;
    else
        bdk_error("bdk_helper_get_interface_index_num: Illegal IPD port number\n");

    return -1;
}

