/**
 * @file
 *
 * Interface to the hardware Packet Input Processing unit.
 *
 * <hr>$Revision: 49504 $<hr>
 */

#define BDK_PIP_NUM_INPUT_PORTS                44


/**
 * Enumeration representing the amount of packet processing
 * and validation performed by the input hardware.
 */
typedef enum
{
    BDK_PIP_PORT_CFG_MODE_NONE = 0ull,  /**< Packet input doesn't perform any
                                            processing of the input packet. */
    BDK_PIP_PORT_CFG_MODE_SKIPL2 = 1ull,/**< Full packet processing is performed
                                            with pointer starting at the L2
                                            (ethernet MAC) header. */
    BDK_PIP_PORT_CFG_MODE_SKIPIP = 2ull /**< Input packets are assumed to be IP.
                                            Results from non IP packets is
                                            undefined. Pointers reference the
                                            beginning of the IP header. */
} bdk_pip_port_parse_mode_t;

/**
 * This enumeration is used in PIP tag config to control how
 * SSO tags are generated by the hardware.
 */
typedef enum
{
    BDK_PIP_TAG_MODE_TUPLE = 0ull,         /**< Always use tuple tag algorithm. This is the only mode supported on Pass 1 */
    BDK_PIP_TAG_MODE_MASK = 1ull,          /**< Always use mask tag algorithm */
    BDK_PIP_TAG_MODE_IP_OR_MASK = 2ull,    /**< If packet is IP, use tuple else use mask */
    BDK_PIP_TAG_MODE_TUPLE_XOR_MASK = 3ull /**< tuple XOR mask */
} bdk_pip_tag_mode_t;

/*
 * Encodes the different error and exception codes
 */
typedef enum
{
    BDK_PIP_L4_NO_ERR       = 0ull,
    /*        1  = TCP (UDP) packet not long enough to cover TCP (UDP) header */
    BDK_PIP_L4_MAL_ERR     = 1ull,
    /*        2  = TCP/UDP checksum failure */
    BDK_PIP_CHK_ERR        = 2ull,
    /*        3  = TCP/UDP length check (TCP/UDP length does not match IP length) */
    BDK_PIP_L4_LENGTH_ERR  = 3ull,
    /*        4  = illegal TCP/UDP port (either source or dest port is zero) */
    BDK_PIP_BAD_PRT_ERR    = 4ull,
    /*        8  = TCP flags = FIN only */
    BDK_PIP_TCP_FLG8_ERR   = 8ull,
    /*        9  = TCP flags = 0 */
    BDK_PIP_TCP_FLG9_ERR   = 9ull,
    /*        10 = TCP flags = FIN+RST+* */
    BDK_PIP_TCP_FLG10_ERR  = 10ull,
    /*        11 = TCP flags = SYN+URG+* */
    BDK_PIP_TCP_FLG11_ERR  = 11ull,
    /*        12 = TCP flags = SYN+RST+* */
    BDK_PIP_TCP_FLG12_ERR  = 12ull,
    /*        13 = TCP flags = SYN+FIN+* */
    BDK_PIP_TCP_FLG13_ERR  = 13ull
} bdk_pip_l4_err_t;

typedef enum
{

    BDK_PIP_IP_NO_ERR      = 0ull,
    /*        1 = not IPv4 or IPv6 */
    BDK_PIP_NOT_IP        = 1ull,
    /*        2 = IPv4 header checksum violation */
    BDK_PIP_IPV4_HDR_CHK  = 2ull,
    /*        3 = malformed (packet not long enough to cover IP hdr) */
    BDK_PIP_IP_MAL_HDR    = 3ull,
    /*        4 = malformed (packet not long enough to cover len in IP hdr) */
    BDK_PIP_IP_MAL_PKT    = 4ull,
    /*        5 = TTL / hop count equal zero */
    BDK_PIP_TTL_HOP       = 5ull,
    /*        6 = IPv4 options / IPv6 early extension headers */
    BDK_PIP_OPTS          = 6ull
} bdk_pip_ip_exc_t;


/**
 * NOTES
 *       late collision (data received before collision)
 *            late collisions cannot be detected by the receiver
 *            they would appear as JAM bits which would appear as bad FCS
 *            or carrier extend error which is BDK_PIP_EXTEND_ERR
 */
typedef enum
{
    /**
     * No error
     */
    BDK_PIP_RX_NO_ERR      = 0ull,

    BDK_PIP_PARTIAL_ERR   = 1ull,  /* RGM+SPI            1 = partially received packet (buffering/bandwidth not adequate) */
    BDK_PIP_JABBER_ERR    = 2ull,  /* RGM+SPI            2 = receive packet too large and truncated */
    BDK_PIP_OVER_FCS_ERR  = 3ull,  /* RGM                3 = max frame error (pkt len > max frame len) (with FCS error) */
    BDK_PIP_OVER_ERR      = 4ull,  /* RGM+SPI            4 = max frame error (pkt len > max frame len) */
    BDK_PIP_ALIGN_ERR     = 5ull,  /* RGM                5 = nibble error (data not byte multiple - 100M and 10M only) */
    BDK_PIP_UNDER_FCS_ERR = 6ull,  /* RGM                6 = min frame error (pkt len < min frame len) (with FCS error) */
    BDK_PIP_GMX_FCS_ERR   = 7ull,  /* RGM                7 = FCS error */
    BDK_PIP_UNDER_ERR     = 8ull,  /* RGM+SPI            8 = min frame error (pkt len < min frame len) */
    BDK_PIP_EXTEND_ERR    = 9ull,  /* RGM                9 = Frame carrier extend error */
    BDK_PIP_TERMINATE_ERR = 9ull,  /* XAUI               9 = Packet was terminated with an idle cycle */
    BDK_PIP_LENGTH_ERR    = 10ull, /* RGM               10 = length mismatch (len did not match len in L2 length/type) */
    BDK_PIP_DAT_ERR       = 11ull, /* RGM               11 = Frame error (some or all data bits marked err) */
    BDK_PIP_DIP_ERR       = 11ull, /*     SPI           11 = DIP4 error */
    BDK_PIP_SKIP_ERR      = 12ull, /* RGM               12 = packet was not large enough to pass the skipper - no inspection could occur */
    BDK_PIP_NIBBLE_ERR    = 13ull, /* RGM               13 = studder error (data not repeated - 100M and 10M only) */
    BDK_PIP_PIP_FCS       = 16L, /* RGM+SPI           16 = FCS error */
    BDK_PIP_PIP_SKIP_ERR  = 17L, /* RGM+SPI+PCI       17 = packet was not large enough to pass the skipper - no inspection could occur */
    BDK_PIP_PIP_L2_MAL_HDR= 18L, /* RGM+SPI+PCI       18 = malformed l2 (packet not long enough to cover L2 hdr) */
    BDK_PIP_PUNY_ERR      = 47L  /* SGMII             47 = PUNY error (packet was 4B or less when FCS stripping is enabled) */
    /* NOTES
     *       xx = late collision (data received before collision)
     *            late collisions cannot be detected by the receiver
     *            they would appear as JAM bits which would appear as bad FCS
     *            or carrier extend error which is BDK_PIP_EXTEND_ERR
     */
} bdk_pip_rcv_err_t;

/**
 * This defines the err_code field errors in the work Q entry
 */
typedef union
{
    bdk_pip_l4_err_t  l4_err;
    bdk_pip_ip_exc_t  ip_exc;
    bdk_pip_rcv_err_t rcv_err;
} bdk_pip_err_t;


/**
 * Status statistics for a port
 */
typedef struct
{
    uint32_t    dropped_octets;         /**< Inbound octets marked to be dropped by the IPD */
    uint32_t    dropped_packets;        /**< Inbound packets marked to be dropped by the IPD */
    uint32_t    pci_raw_packets;        /**< RAW PCI Packets received by PIP per port */
    uint32_t    octets;                 /**< Number of octets processed by PIP */
    uint32_t    packets;                /**< Number of packets processed by PIP */
    uint32_t    multicast_packets;      /**< Number of indentified L2 multicast packets.
                                            Does not include broadcast packets.
                                            Only includes packets whose parse mode is
                                            SKIP_TO_L2 */
    uint32_t    broadcast_packets;      /**< Number of indentified L2 broadcast packets.
                                            Does not include multicast packets.
                                            Only includes packets whose parse mode is
                                            SKIP_TO_L2 */
    uint32_t    len_64_packets;         /**< Number of 64B packets */
    uint32_t    len_65_127_packets;     /**< Number of 65-127B packets */
    uint32_t    len_128_255_packets;    /**< Number of 128-255B packets */
    uint32_t    len_256_511_packets;    /**< Number of 256-511B packets */
    uint32_t    len_512_1023_packets;   /**< Number of 512-1023B packets */
    uint32_t    len_1024_1518_packets;  /**< Number of 1024-1518B packets */
    uint32_t    len_1519_max_packets;   /**< Number of 1519-max packets */
    uint32_t    fcs_align_err_packets;  /**< Number of packets with FCS or Align opcode errors */
    uint32_t    runt_packets;           /**< Number of packets with length < min */
    uint32_t    runt_crc_packets;       /**< Number of packets with length < min and FCS error */
    uint32_t    oversize_packets;       /**< Number of packets with length > max */
    uint32_t    oversize_crc_packets;   /**< Number of packets with length > max and FCS error */
    uint32_t    inb_packets;            /**< Number of packets without GMX/SPX/PCI errors received by PIP */
    uint64_t    inb_octets;             /**< Total number of octets from all packets received by PIP, including CRC */
    uint16_t    inb_errors;             /**< Number of packets with GMX/SPX/PCI errors received by PIP */
} bdk_pip_port_status_t;


/**
 * Definition of the PIP custom header that can be prepended
 * to a packet by external hardware.
 */
typedef union
{
    uint64_t    u64;
    struct
    {
        uint64_t                    rawfull     : 1;    /**< Documented as R - Set if the Packet is RAWFULL. If set,
                                                            this header must be the full 8 bytes */
        uint64_t                    reserved0   : 5;    /**< Must be zero */
        bdk_pip_port_parse_mode_t  parse_mode  : 2;    /**< PIP parse mode for this packet */
        uint64_t                    reserved1   : 1;    /**< Must be zero */
        uint64_t                    skip_len    : 7;    /**< Skip amount, including this header, to the beginning of the packet */
        uint64_t                    reserved2   : 2;    /**< Must be zero */
        uint64_t                    nqos        : 1;    /**< Must be 0 when PKT_INST_HDR[R] = 0.
                                                             When set to 1, NQOS prevents PIP from directly using
                                                             PKT_INST_HDR[QOS] for the QOS value in WQE.
                                                             When PIP_GBL_CTL[IHMSK_DIS] = 1, Octeon2 does not use NQOS */
        uint64_t                    ngrp        : 1;    /**< Must be 0 when PKT_INST_HDR[R] = 0.
                                                             When set to 1, NGPR prevents PIP from directly using
                                                             PKT_INST_HDR[GPR] for the GPR value in WQE.
                                                             When PIP_GBL_CTL[IHMSK_DIS] = 1, Octeon2 does not use NGRP */
        uint64_t                    ntt         : 1;    /**< Must be 0 when PKT_INST_HDR[R] = 0.
                                                             When set to 1, NTT prevents PIP from directly using
                                                             PKT_INST_HDR[TT] for the TT value in WQE.
                                                             When PIP_GBL_CTL[IHMSK_DIS] = 1, Octeon2 does not use NTT */
        uint64_t                    ntag        : 1;    /**< Must be 0 when PKT_INST_HDR[R] = 0.
                                                             When set to 1, NTAG prevents PIP from directly using
                                                             PKT_INST_HDR[TAG] for the TAG value in WQE.
                                                             When PIP_GBL_CTL[IHMSK_DIS] = 1, Octeon2 does not use NTAG */
        uint64_t                    qos         : 3;    /**< SSO input queue for this packet */
        uint64_t                    grp         : 4;    /**< SSO input group for this packet */
        uint64_t                    rs          : 1;    /**< Flag to store this packet in the work queue entry, if possible */
        bdk_sso_tag_type_t         tag_type    : 2;    /**< SSO input tag type */
        uint64_t                    tag         : 32;   /**< SSO input tag */
    } s;
} bdk_pip_pkt_inst_hdr_t;

/**
 * Configure an ethernet input port
 *
 * @param port_num Port number to configure
 * @param port_cfg Port hardware configuration
 * @param port_tag_cfg
 *                 Port SSO tagging configuration
 */
static inline void bdk_pip_config_port(uint64_t port_num,
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
static inline void bdk_pip_config_vlan_qos(uint64_t vlan_priority, uint64_t qos)
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
static inline void bdk_pip_config_diffserv_qos(uint64_t diffserv, uint64_t qos)
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
static inline void bdk_pip_get_port_status(uint64_t port_num, uint64_t clear, bdk_pip_port_status_t *status)
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
static inline void bdk_pip_tag_mask_clear(uint64_t mask_index)
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
static inline void bdk_pip_tag_mask_set(uint64_t mask_index, uint64_t offset, uint64_t len)
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

