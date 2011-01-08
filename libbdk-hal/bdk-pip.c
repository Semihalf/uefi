#include <bdk.h>

/**
 * Get the status counters for a port.
 *
 * @param port_num Port number to get statistics for.
 * @param clear    Set to 1 to clear the counters after they are read
 * @param status   Where to put the results.
 */
void bdk_pip_get_port_status(uint64_t port_num, uint64_t clear, bdk_pip_port_status_t *status)
{
    bdk_pip_stat_ctl_t pip_stat_ctl;
    bdk_pip_stat0_x_t stat0;
    bdk_pip_stat1_x_t stat1;
    bdk_pip_stat2_x_t stat2;
    bdk_pip_stat3_x_t stat3;
    bdk_pip_stat4_x_t stat4;
    bdk_pip_stat5_x_t stat5;
    bdk_pip_stat6_x_t stat6;
    bdk_pip_stat7_x_t stat7;
    bdk_pip_stat8_x_t stat8;
    bdk_pip_stat9_x_t stat9;
    bdk_pip_stat_inb_pkts_pkndx_t pip_stat_inb_pktsx;
    bdk_pip_stat_inb_octs_pkndx_t pip_stat_inb_octsx;
    bdk_pip_stat_inb_errs_pkndx_t pip_stat_inb_errsx;

    pip_stat_ctl.u64 = 0;
    pip_stat_ctl.s.rdclr = clear;
    BDK_CSR_WRITE(BDK_PIP_STAT_CTL, pip_stat_ctl.u64);

    if (port_num >= 40)
    {
        stat0.u64 = BDK_CSR_READ(BDK_PIP_XSTAT0_PRTX(port_num));
        stat1.u64 = BDK_CSR_READ(BDK_PIP_XSTAT1_PRTX(port_num));
        stat2.u64 = BDK_CSR_READ(BDK_PIP_XSTAT2_PRTX(port_num));
        stat3.u64 = BDK_CSR_READ(BDK_PIP_XSTAT3_PRTX(port_num));
        stat4.u64 = BDK_CSR_READ(BDK_PIP_XSTAT4_PRTX(port_num));
        stat5.u64 = BDK_CSR_READ(BDK_PIP_XSTAT5_PRTX(port_num));
        stat6.u64 = BDK_CSR_READ(BDK_PIP_XSTAT6_PRTX(port_num));
        stat7.u64 = BDK_CSR_READ(BDK_PIP_XSTAT7_PRTX(port_num));
        stat8.u64 = BDK_CSR_READ(BDK_PIP_XSTAT8_PRTX(port_num));
        stat9.u64 = BDK_CSR_READ(BDK_PIP_XSTAT9_PRTX(port_num));
    }
    else
    {
        stat0.u64 = BDK_CSR_READ(BDK_PIP_STAT0_X(port_num));
        stat1.u64 = BDK_CSR_READ(BDK_PIP_STAT1_X(port_num));
        stat2.u64 = BDK_CSR_READ(BDK_PIP_STAT2_X(port_num));
        stat3.u64 = BDK_CSR_READ(BDK_PIP_STAT3_X(port_num));
        stat4.u64 = BDK_CSR_READ(BDK_PIP_STAT4_X(port_num));
        stat5.u64 = BDK_CSR_READ(BDK_PIP_STAT5_X(port_num));
        stat6.u64 = BDK_CSR_READ(BDK_PIP_STAT6_X(port_num));
        stat7.u64 = BDK_CSR_READ(BDK_PIP_STAT7_X(port_num));
        stat8.u64 = BDK_CSR_READ(BDK_PIP_STAT8_X(port_num));
        stat9.u64 = BDK_CSR_READ(BDK_PIP_STAT9_X(port_num));
    }
    pip_stat_inb_pktsx.u64 = BDK_CSR_READ(BDK_PIP_STAT_INB_PKTS_PKNDX(port_num));
    pip_stat_inb_octsx.u64 = BDK_CSR_READ(BDK_PIP_STAT_INB_OCTS_PKNDX(port_num));
    pip_stat_inb_errsx.u64 = BDK_CSR_READ(BDK_PIP_STAT_INB_ERRS_PKNDX(port_num));

    status->dropped_octets          = stat0.s.drp_octs;
    status->dropped_packets         = stat0.s.drp_pkts;
    status->octets                  = stat1.s.octs;
    status->pci_raw_packets         = stat2.s.raw;
    status->packets                 = stat2.s.pkts;
    status->multicast_packets       = stat3.s.mcst;
    status->broadcast_packets       = stat3.s.bcst;
    status->len_64_packets          = stat4.s.h64;
    status->len_65_127_packets      = stat4.s.h65to127;
    status->len_128_255_packets     = stat5.s.h128to255;
    status->len_256_511_packets     = stat5.s.h256to511;
    status->len_512_1023_packets    = stat6.s.h512to1023;
    status->len_1024_1518_packets   = stat6.s.h1024to1518;
    status->len_1519_max_packets    = stat7.s.h1519;
    status->fcs_align_err_packets   = stat7.s.fcs;
    status->runt_packets            = stat8.s.undersz;
    status->runt_crc_packets        = stat8.s.frag;
    status->oversize_packets        = stat9.s.oversz;
    status->oversize_crc_packets    = stat9.s.jabber;
    status->inb_packets             = pip_stat_inb_pktsx.s.pkts;
    status->inb_octets              = pip_stat_inb_octsx.s.octs;
    status->inb_errors              = pip_stat_inb_errsx.s.errs;

}

