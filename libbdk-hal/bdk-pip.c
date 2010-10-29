#include <bdk.h>

/**
 * Configure an ethernet input port
 *
 * @param port_num Port number to configure
 * @param port_cfg Port hardware configuration
 * @param port_tag_cfg
 *                 Port SSO tagging configuration
 */
void bdk_pip_config_port(uint64_t port_num,
                                        bdk_pip_prt_cfgx_t port_cfg,
                                        bdk_pip_prt_tagx_t port_tag_cfg)
{
    BDK_CSR_WRITE(BDK_PIP_PRT_CFGX(port_num), port_cfg.u64);
    BDK_CSR_WRITE(BDK_PIP_PRT_TAGX(port_num), port_tag_cfg.u64);
}


/**
 * Configure the VLAN priority to QoS queue mapping.
 *
 * @param vlan_priority
 *               VLAN priority (0-7)
 * @param qos    QoS queue for packets matching this watcher
 */
void bdk_pip_config_vlan_qos(uint64_t vlan_priority, uint64_t qos)
{
    bdk_pip_qos_vlanx_t pip_qos_vlanx;
    pip_qos_vlanx.u64 = 0;
    pip_qos_vlanx.s.qos = qos;
    BDK_CSR_WRITE(BDK_PIP_QOS_VLANX(vlan_priority), pip_qos_vlanx.u64);
}


/**
 * Configure the Diffserv to QoS queue mapping.
 *
 * @param diffserv Diffserv field value (0-63)
 * @param qos      QoS queue for packets matching this watcher
 */
void bdk_pip_config_diffserv_qos(uint64_t diffserv, uint64_t qos)
{
    bdk_pip_qos_diffx_t pip_qos_diffx;
    pip_qos_diffx.u64 = 0;
    pip_qos_diffx.s.qos = qos;
    BDK_CSR_WRITE(BDK_PIP_QOS_DIFFX(diffserv), pip_qos_diffx.u64);
}


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
    bdk_pip_stat0_pkndx_t stat0;
    bdk_pip_stat1_pkndx_t stat1;
    bdk_pip_stat2_pkndx_t stat2;
    bdk_pip_stat3_pkndx_t stat3;
    bdk_pip_stat4_pkndx_t stat4;
    bdk_pip_stat5_pkndx_t stat5;
    bdk_pip_stat6_pkndx_t stat6;
    bdk_pip_stat7_pkndx_t stat7;
    bdk_pip_stat8_pkndx_t stat8;
    bdk_pip_stat9_pkndx_t stat9;
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
        stat0.u64 = BDK_CSR_READ(BDK_PIP_STAT0_PKNDX(port_num));
        stat1.u64 = BDK_CSR_READ(BDK_PIP_STAT1_PKNDX(port_num));
        stat2.u64 = BDK_CSR_READ(BDK_PIP_STAT2_PKNDX(port_num));
        stat3.u64 = BDK_CSR_READ(BDK_PIP_STAT3_PKNDX(port_num));
        stat4.u64 = BDK_CSR_READ(BDK_PIP_STAT4_PKNDX(port_num));
        stat5.u64 = BDK_CSR_READ(BDK_PIP_STAT5_PKNDX(port_num));
        stat6.u64 = BDK_CSR_READ(BDK_PIP_STAT6_PKNDX(port_num));
        stat7.u64 = BDK_CSR_READ(BDK_PIP_STAT7_PKNDX(port_num));
        stat8.u64 = BDK_CSR_READ(BDK_PIP_STAT8_PKNDX(port_num));
        stat9.u64 = BDK_CSR_READ(BDK_PIP_STAT9_PKNDX(port_num));
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


/**
 * Clear all bits in a tag mask. This should be called on
 * startup before any calls to bdk_pip_tag_mask_set. Each bit
 * set in the final mask represent a byte used in the packet for
 * tag generation.
 *
 * @param mask_index Which tag mask to clear (0..3)
 */
void bdk_pip_tag_mask_clear(uint64_t mask_index)
{
    uint64_t index;
    bdk_pip_tag_incx_t pip_tag_incx;
    pip_tag_incx.u64 = 0;
    pip_tag_incx.s.en = 0;
    for (index=mask_index*16; index<(mask_index+1)*16; index++)
        BDK_CSR_WRITE(BDK_PIP_TAG_INCX(index), pip_tag_incx.u64);
}


/**
 * Sets a range of bits in the tag mask. The tag mask is used
 * when the bdk_pip_port_tag_cfg_t tag_mode is non zero.
 * There are four separate masks that can be configured.
 *
 * @param mask_index Which tag mask to modify (0..3)
 * @param offset     Offset into the bitmask to set bits at. Use the GCC macro
 *                   offsetof() to determine the offsets into packet headers.
 *                   For example, offsetof(ethhdr, protocol) returns the offset
 *                   of the ethernet protocol field.  The bitmask selects which bytes
 *                   to include the the tag, with bit offset X selecting byte at offset X
 *                   from the beginning of the packet data.
 * @param len        Number of bytes to include. Usually this is the sizeof()
 *                   the field.
 */
void bdk_pip_tag_mask_set(uint64_t mask_index, uint64_t offset, uint64_t len)
{
    while (len--)
    {
        bdk_pip_tag_incx_t pip_tag_incx;
        uint64_t index = mask_index*16 + offset/8;
        pip_tag_incx.u64 = BDK_CSR_READ(BDK_PIP_TAG_INCX(index));
        pip_tag_incx.s.en |= 0x80 >> (offset & 0x7);
        BDK_CSR_WRITE(BDK_PIP_TAG_INCX(index), pip_tag_incx.u64);
        offset++;
    }
}

