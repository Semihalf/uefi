/**
 * @file
 *
 * Functions and typedefs for using Octeon in HiGig/HiGig+/HiGig2 mode over
 * XAUI.
 *
 * <hr>$Revision: 50048 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef struct
{
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t start          : 8; /**< 8-bits of Preamble indicating start of frame */
            uint32_t hgi            : 2; /**< HiGig interface format indicator
                                            00 = Reserved
                                            01 = Pure preamble - IEEE standard framing of 10GE
                                            10 = XGS header - framing based on XGS family definition In this
                                                format, the default length of the header is 12 bytes and additional
                                                bytes are indicated by the HDR_EXT_LEN field
                                            11 = Reserved */
            uint32_t cng_high       : 1; /**< Congestion Bit High flag */
            uint32_t hdr_ext_len    : 3; /**< This field is valid only if the HGI field is a b'10' and it indicates the extension
                                            to the standard 12-bytes of XGS HiGig header. Each unit represents 4
                                            bytes, giving a total of 16 additional extension bytes. Value of b'101', b'110'
                                            and b'111' are reserved. For HGI field value of b'01' this field should be
                                            b'01'. For all other values of HGI it is don't care. */
            uint32_t src_modid_6    : 1; /**< This field is valid only if the HGI field is a b'10' and it represents Bit 6 of
                                            SRC_MODID (bits 4:0 are in Byte 4 and bit 5 is in Byte 9). For HGI field
                                            value of b'01' this field should be b'0'. For all other values of HGI it is don't
                                            care. */
            uint32_t dst_modid_6    : 1; /**< This field is valid only if the HGI field is a b'10' and it represents Bit 6 of
                                            DST_MODID (bits 4:0 are in Byte 7 and bit 5 is in Byte 9). ). For HGI field
                                            value of b'01' this field should be b'1'. For all other values of HGI it is don't
                                            care. */
            uint32_t vid_high       : 8; /**< 8-bits of the VLAN tag information */
            uint32_t vid_low        : 8; /**< 8 bits LSB of the VLAN tag information */
        } s;
    } dw0;
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t src_modid_low  : 5; /**< Bits 4:0 of Module ID of the source module on which the packet ingress (bit
                                            5 is in Byte 9 and bit 6 Is in Byte 1) */
            uint32_t opcode         : 3; /**< XGS HiGig op-code, indicating the type of packet
                                            000 =     Control frames used for CPU to CPU communications
                                            001 =     Unicast packet with destination resolved; The packet can be
                                                      either Layer 2 unicast packet or L3 unicast packet that was
                                                      routed in the ingress chip.
                                            010 =     Broadcast or unknown Unicast packet or unknown multicast,
                                                      destined to all members of the VLAN
                                            011 =     L2 Multicast packet, destined to all ports of the group indicated
                                                      in the L2MC_INDEX which is overlayed on DST_PORT/DST_MODID fields
                                            100 =     IP Multicast packet, destined to all ports of the group indicated
                                                      in the IPMC_INDEX which is overlayed on DST_PORT/DST_MODID fields
                                            101 =     Reserved
                                            110 =     Reserved
                                            111 =     Reserved */
            uint32_t pfm            : 2; /**< Three Port Filtering Modes (0, 1, 2) used in handling registed/unregistered
                                            multicast (unknown L2 multicast and IPMC) packets. This field is used
                                            when OPCODE is 011 or 100 Semantics of PFM bits are as follows;
                                            For registered L2 multicast packets:
                                                PFM= 0 ­ Flood to VLAN
                                                PFM= 1 or 2 ­ Send to group members in the L2MC table
                                            For unregistered L2 multicast packets:
                                                PFM= 0 or 1 ­ Flood to VLAN
                                                PFM= 2 ­ Drop the packet */
            uint32_t src_port_tgid  : 6; /**< If the MSB of this field is set, then it indicates the LAG the packet ingressed
                                            on, else it represents the physical port the packet ingressed on. */
            uint32_t dst_port       : 5; /**< Port number of destination port on which the packet needs to egress. */
            uint32_t priority       : 3; /**< This is the internal priority of the packet. This internal priority will go through
                                            COS_SEL mapping registers to map to the actual MMU queues. */
            uint32_t header_type    : 2; /**< Indicates the format of the next 4 bytes of the XGS HiGig header
                                            00 = Overlay 1 (default)
                                            01 = Overlay 2 (Classification Tag)
                                            10 = Reserved
                                            11 = Reserved */
            uint32_t cng_low        : 1; /**< Semantics of CNG_HIGH and CNG_LOW are as follows: The following
                                            encodings are to make it backward compatible:
                                            [CNG_HIGH, CNG_LOW] - COLOR
                                            [0, 0] ­ Packet is green
                                            [0, 1] ­ Packet is red
                                            [1, 1] ­ Packet is yellow
                                            [1, 0] ­ Undefined */
            uint32_t dst_modid_low  : 5; /**< Bits [4-: 0] of Module ID of the destination port on which the packet needs to egress. */
        } s;
    } dw1;
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t dst_t          : 1; /**< Destination Trunk: Indicates that the destination port is a member of a trunk
                                            group. */
            uint32_t dst_tgid       : 3; /**< Destination Trunk Group ID: Trunk group ID of the destination port. The
                                            DO_NOT_LEARN bit is overlaid on the second bit of this field. */
            uint32_t ingress_tagged : 1; /**< Ingress Tagged: Indicates whether the packet was tagged when it originally
                                            ingressed the system. */
            uint32_t mirror_only    : 1; /**< Mirror Only: XGS 1/2 mode: Indicates that the packet was switched and only
                                            needs to be mirrored. */
            uint32_t mirror_done    : 1; /**< Mirroring Done: XGS1/2 mode: Indicates that the packet was mirrored and
                                            may still need to be switched. */
            uint32_t mirror         : 1; /**< Mirror: XGS3 mode: a mirror copy packet. XGS1/2 mode: Indicates that the
                                            packet was switched and only needs to be mirrored. */

            uint32_t src_modid_5    : 1; /**< Source Module ID: Bit 5 of Src_ModID (bits 4:0 are in byte 4 and bit 6 is in
                                            byte 1) */
            uint32_t dst_modid_5    : 1; /**< Destination Module ID: Bit 5 of Dst_ModID (bits 4:0 are in byte 7 and bit 6
                                            is in byte 1) */
            uint32_t l3             : 1; /**< L3: Indicates that the packet is L3 switched */
            uint32_t label_present  : 1; /**< Label Present: Indicates that header contains a 20-bit VC label: HiGig+
                                            added field. */
            uint32_t vc_label_16_19 : 4; /**< VC Label: Bits 19:16 of VC label: HiGig+ added field */
            uint32_t vc_label_0_15  : 16;/**< VC Label: Bits 15:0 of VC label: HiGig+ added field */
        } o1;
        struct
        {
            uint32_t classification : 16; /**< Classification tag information from the HiGig device FFP */
            uint32_t reserved_0_15  : 16;

        } o2;
    } dw2;
} bdk_higig_header_t;

typedef struct
{
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t k_sop          : 8;  /**< The delimiter indicating the start of a packet transmission */
            uint32_t reserved_21_23 : 3;
            uint32_t mcst           : 1;  /**< MCST indicates whether the packet should be unicast or
                                            multicast forwarded through the XGS switching fabric
                                            - 0: Unicast
                                            - 1: Mulitcast */
            uint32_t tc             : 4;  /**< Traffic Class [3:0] indicates the distinctive Quality of Service (QoS)
                                            the switching fabric will provide when forwarding the packet
                                            through the fabric */
            uint32_t dst_modid_mgid : 8;  /**< When MCST=0, this field indicates the destination XGS module to
                                            which the packet will be delivered. When MCST=1, this field indicates
                                            higher order bits of the Multicast Group ID. */
            uint32_t dst_pid_mgid   : 8;  /**< When MCST=0, this field indicates a port associated with the
                                            module indicated by the DST_MODID, through which the packet
                                            will exit the system. When MCST=1, this field indicates lower order
                                            bits of the Multicast Group ID */
        } s;
    } dw0;
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t src_modid      : 8;  /**< Source Module ID indicates the source XGS module from which
                                            the packet is originated. (It can also be used for the fabric multicast
                                            load balancing purpose.) */
            uint32_t src_pid        : 8;  /**< Source Port ID indicates a port associated with the module
                                            indicated by the SRC_MODID, through which the packet has
                                            entered the system */
            uint32_t lbid           : 8;  /**< Load Balancing ID indicates a packet flow hashing index
                                            computed by the ingress XGS module for statistical distribution of
                                            packet flows through a multipath fabric */
            uint32_t dp             : 2;  /**< Drop Precedence indicates the traffic rate violation status of the
                                            packet measured by the ingress module.
                                            - 00: GREEN
                                            - 01: RED
                                            - 10: Reserved
                                            - 11: Yellow */
            uint32_t reserved_3_5   : 3;
            uint32_t ppd_type       : 3;  /**< Packet Processing Descriptor Type
                                            - 000: PPD Overlay1
                                            - 001: PPD Overlay2
                                            - 010~111: Reserved */
        } s;
    } dw1;
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t dst_t          : 1;  /**< Destination Trunk: Indicates that the destination port is a member of a trunk
                                            group. */
            uint32_t dst_tgid       : 3;  /**< Destination Trunk Group ID: Trunk group ID of the destination port. The
                                            DO_NOT_LEARN bit is overlaid on the second bit of this field. */
            uint32_t ingress_tagged : 1;  /**< Ingress Tagged: Indicates whether the packet was tagged when it originally
                                            ingressed the system. */
            uint32_t mirror_only    : 1;  /**< Mirror Only: XGS 1/2 mode: Indicates that the packet was switched and only
                                            needs to be mirrored. */
            uint32_t mirror_done    : 1;  /**< Mirroring Done: XGS1/2 mode: Indicates that the packet was mirrored and
                                            may still need to be switched. */
            uint32_t mirror         : 1;  /**< Mirror: XGS3 mode: a mirror copy packet. XGS1/2 mode: Indicates that the
                                            packet was switched and only needs to be mirrored. */
            uint32_t reserved_22_23 : 2;
            uint32_t l3             : 1;  /**< L3: Indicates that the packet is L3 switched */
            uint32_t label_present  : 1;  /**< Label Present: Indicates that header contains a 20-bit VC label: HiGig+
                                            added field. */
            uint32_t vc_label       : 20; /**< Refer to the HiGig+ Architecture Specification */
        } o1;
        struct
        {
            uint32_t classification : 16; /**< Classification tag information from the HiGig device FFP */
            uint32_t reserved_0_15  : 16;
        } o2;
    } dw2;
    union
    {
        uint32_t u32;
        struct
        {
            uint32_t vid            : 16; /**< VLAN tag information */
            uint32_t pfm            : 2;  /**< Three Port Filtering Modes (0, 1, 2) used in handling registed/unregistered
                                            multicast (unknown L2 multicast and IPMC) packets. This field is used
                                            when OPCODE is 011 or 100 Semantics of PFM bits are as follows;
                                            For registered L2 multicast packets:
                                                PFM= 0 - Flood to VLAN
                                                PFM= 1 or 2 - Send to group members in the L2MC table
                                            For unregistered L2 multicast packets:
                                                PFM= 0 or 1 - Flood to VLAN
                                                PFM= 2 - Drop the packet */
            uint32_t src_t          : 1;  /**< If the MSB of this field is set, then it indicates the LAG the packet ingressed
                                            on, else it represents the physical port the packet ingressed on. */
            uint32_t reserved_11_12 : 2;
            uint32_t opcode         : 3;  /**< XGS HiGig op-code, indicating the type of packet
                                            000 =     Control frames used for CPU to CPU communications
                                            001 =     Unicast packet with destination resolved; The packet can be
                                                      either Layer 2 unicast packet or L3 unicast packet that was
                                                      routed in the ingress chip.
                                            010 =     Broadcast or unknown Unicast packet or unknown multicast,
                                                      destined to all members of the VLAN
                                            011 =     L2 Multicast packet, destined to all ports of the group indicated
                                                      in the L2MC_INDEX which is overlayed on DST_PORT/DST_MODID fields
                                            100 =     IP Multicast packet, destined to all ports of the group indicated
                                                      in the IPMC_INDEX which is overlayed on DST_PORT/DST_MODID fields
                                            101 =     Reserved
                                            110 =     Reserved
                                            111 =     Reserved */
            uint32_t hdr_ext_len    : 3;  /**< This field is valid only if the HGI field is a b'10' and it indicates the extension
                                            to the standard 12-bytes of XGS HiGig header. Each unit represents 4
                                            bytes, giving a total of 16 additional extension bytes. Value of b'101', b'110'
                                            and b'111' are reserved. For HGI field value of b'01' this field should be
                                            b'01'. For all other values of HGI it is don't care. */
            uint32_t reserved_0_4   : 5;
        } s;
    } dw3;
} bdk_higig2_header_t;

/** @} */
