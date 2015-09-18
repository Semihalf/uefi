#ifndef __BDK_CSRS_PKI_H__
#define __BDK_CSRS_PKI_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2015  Cavium Inc. (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Inc. nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium PKI.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration pki_bar_e
 *
 * PKI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_PKI_BAR_E_PKI_PF_BAR0 (0x86c000000000ll) /**< Base address for standard registers. */
#define BDK_PKI_BAR_E_PKI_PF_BAR4 (0x86c001000000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration pki_beltype_e
 *
 * PKI Backend Layer Type Enumeration
 * Enumerates the values for  PKI_LTYPE()_MAP[BELTYPE].
 */
#define BDK_PKI_BELTYPE_E_IP4 (2) /**< IPv4-ish backend checking. */
#define BDK_PKI_BELTYPE_E_IP6 (3) /**< IPv6-ish backend checking. */
#define BDK_PKI_BELTYPE_E_MISC (1) /**< Miscellaneous type. This layer is present, but does not require backend checking. */
#define BDK_PKI_BELTYPE_E_NONE (0) /**< No backend checking. */
#define BDK_PKI_BELTYPE_E_SCTP (6) /**< SCTP-ish backend checking. */
#define BDK_PKI_BELTYPE_E_SNAP (7) /**< SNAP-ish backend checking. */
#define BDK_PKI_BELTYPE_E_TCP (4) /**< TCP-ish backend checking. */
#define BDK_PKI_BELTYPE_E_UDP (5) /**< UDP-ish backend checking. */

/**
 * Enumeration pki_chan_e
 *
 * PKI Channel Enumeration
 * Enumerates the values of WQE[CHAN].
 */
#define BDK_PKI_CHAN_E_BGXX_PORTX_CHX(a,b,c) (0x800 + 0x100 * (a) + 0x10 * (b) + (c)) /**< BGX {a} port {b} channel {c}. The channel is always 0 when used as a port
                                       number, then made non-zero as part of the conversion to a channel number. */
#define BDK_PKI_CHAN_E_DPI_CHX(a) (0x100 + (a)) /**< DPI ring {a}. */
#define BDK_PKI_CHAN_E_ILKX_CHX(a,b) (0x400 + 0x100 * (a) + (b)) /**< Reserved. INTERNAL: Interlaken RX/TX {a} channel {b}. */
#define BDK_PKI_CHAN_E_LOOPBACK_CHX(a) (0 + (a)) /**< Loopback pipe {a}. The channel number comes from the PKO pipe field. */
#define BDK_PKI_CHAN_E_NQM_CH (0x200) /**< NQM traffic.  NQM traffic does not pass through PKI, however NQM places this
                                       value into NQM_WQE_S[CHAN] field so that software may distinguish between
                                       PKI_WQE_S and NQM_WQE_S formatted structures. */
#define BDK_PKI_CHAN_E_SRIOX_CHX(a,b) (0x240 + 2 * (a) + (b)) /**< Reserved. INTERNAL: SRIO message unit mac {a} channel {b}. */

/**
 * Enumeration pki_errlev_e
 *
 * PKI Error Level Enumeration
 * Enumerates the values of WQE[ERRLEV].
 */
#define BDK_PKI_ERRLEV_E_LA (1) /**< Layer A error. */
#define BDK_PKI_ERRLEV_E_LB (2) /**< Layer B error. */
#define BDK_PKI_ERRLEV_E_LC (3) /**< Layer C error. */
#define BDK_PKI_ERRLEV_E_LD (4) /**< Layer D error. */
#define BDK_PKI_ERRLEV_E_LE (5) /**< Layer E error. */
#define BDK_PKI_ERRLEV_E_LF (6) /**< Layer F error. */
#define BDK_PKI_ERRLEV_E_LG (7) /**< Layer G error. */
#define BDK_PKI_ERRLEV_E_RE (0) /**< Receive error or no error. If WQE[OPCODE]=0x0 (PKI_OPCODE_E::RE_NONE) then no error. Else
                                       used for L1, MAC and PKI RAM parity errors. */

/**
 * Enumeration pki_ethertype_e
 *
 * PKI Ethertypes Enumeration
 * Enumerates the standard Ethertype values.
 */
#define BDK_PKI_ETHERTYPE_E_ARP (0x806) /**< Address Resolution Protocol. */
#define BDK_PKI_ETHERTYPE_E_CNM (0x22e9) /**< Congestion Notification Message. */
#define BDK_PKI_ETHERTYPE_E_ETAG (0x893f) /**< 802.1BR E-Tag. Informational only. */
#define BDK_PKI_ETHERTYPE_E_IP (0x800) /**< IP. */
#define BDK_PKI_ETHERTYPE_E_IP6 (0x86dd) /**< IPv6. */
#define BDK_PKI_ETHERTYPE_E_MPLS_8847 (0x8847) /**< MPLS. */
#define BDK_PKI_ETHERTYPE_E_MPLS_8848 (0x8848) /**< MPLS. */
#define BDK_PKI_ETHERTYPE_E_REVARP (0x8035) /**< Reverse Address Resolution Protocol. */
#define BDK_PKI_ETHERTYPE_E_ROCE (0x8915) /**< RDMA over Converged Ethernet. Informational only. */
#define BDK_PKI_ETHERTYPE_E_VLAN (0x8100) /**< Standard VLAN Ethertype. */
#define BDK_PKI_ETHERTYPE_E_VLAN_88A8 (0x88a8) /**< Alternative VLAN Ethertype. */
#define BDK_PKI_ETHERTYPE_E_VLAN_9100 (0x9100) /**< Alternative VLAN Ethertype. */
#define BDK_PKI_ETHERTYPE_E_VLAN_9200 (0x9200) /**< Alternative VLAN Ethertype. */
#define BDK_PKI_ETHERTYPE_E_VLAN_9300 (0x9300) /**< Alternative VLAN Ethertype. */

/**
 * Enumeration pki_ipproto_e
 *
 * PKI IP Protocol Enumeration
 * Enumerates the IPv4 protocol and IPv6 next-header values.
 */
#define BDK_PKI_IPPROTO_E_AH (0x33) /**< Authentication Header. */
#define BDK_PKI_IPPROTO_E_DEST (0x3c) /**< Destination Options. */
#define BDK_PKI_IPPROTO_E_ESP (0x32) /**< Encapsulating Security Payload. */
#define BDK_PKI_IPPROTO_E_FRAG (0x2c) /**< Fragment. */
#define BDK_PKI_IPPROTO_E_GRE (0x2f) /**< Generic Route Encapsulation Protocol. */
#define BDK_PKI_IPPROTO_E_HOP_BY_HOP (0) /**< Hop-by-hop Options. */
#define BDK_PKI_IPPROTO_E_IP4 (4) /**< IPv4 in IP. */
#define BDK_PKI_IPPROTO_E_IP6 (0x29) /**< IPv6 in IP. */
#define BDK_PKI_IPPROTO_E_IPCOMP (0x6c) /**< IP Payload Compression Protocol. */
#define BDK_PKI_IPPROTO_E_ROUTING (0x2b) /**< Routing. */
#define BDK_PKI_IPPROTO_E_SCTP (0x84) /**< Stream Control Transmission Protocol. */
#define BDK_PKI_IPPROTO_E_TCP (6) /**< TCP. */
#define BDK_PKI_IPPROTO_E_UDP (0x11) /**< UDP. */

/**
 * Enumeration pki_ltype_e
 *
 * PKI Layer Type Enumeration
 * Enumerates the values of WQE[LBTY], WQE[LCTY], WQE[LDTY], WQE[LETY], WQE[LFTY] and WQE[LGTY].
 *
 * Also shows the setting of PKI_LTYPE()_MAP[BELTYPE], which layers create this layer type,
 * and (in the description) the usage of PKI_CL()_PCAM()_ACTION()[SETTY].
 */
#define BDK_PKI_LTYPE_E_ARP (6) /**< ARP. The packet's L2 HDR TYPE field indicates ARP (i.e. equals 0x0835). */
#define BDK_PKI_LTYPE_E_ENET (1) /**< Reserved. */
#define BDK_PKI_LTYPE_E_GRE (0x14) /**< GRE, but not NVGRE. */
#define BDK_PKI_LTYPE_E_GTP (0x16) /**< GTP under UDP. */
#define BDK_PKI_LTYPE_E_IP4 (8) /**< IPv4 without options. The IP version field is 4, and the IP HLEN field is 5.
                                       Note IP4/IP4_OPT/IP6/IP6_OPT codes differ only in the lower two bits, so a AND mask may be
                                       applied to test for all of these encodings in parallel. */
#define BDK_PKI_LTYPE_E_IP4_OPT (9) /**< IPv4 with options. The IP version field is 4, and the IP HLEN field is not 5. (Note that
                                       the case where HLEN < 5 is flagged in the IP malformed-header check).
                                       Note IP4/IP4_OPT/IP6/IP6_OPT codes differ only in the lower two bits, so a AND mask may be
                                       applied to test for all of these encodings in parallel. */
#define BDK_PKI_LTYPE_E_IP6 (0xa) /**< IPv6 without options. The IP version field is 6, and IP6_OPT below does not apply.
                                       Note IP4/IP4_OPT/IP6/IP6_OPT codes differ only in the lower two bits, so a AND mask may be
                                       applied to test for all of these encodings in parallel. */
#define BDK_PKI_LTYPE_E_IP6_OPT (0xb) /**< IPv6 with options. The IP version field is 6, and the extension headers matching any of
                                       the following:
                                       * 0 (hop-by-hop).
                                       * 43 (routing).
                                       * 60 (destination).
                                       
                                       Also used when the final extension header is not one listed in PKI_IPPROTO_E.
                                       Note IP4/IP4_OPT/IP6/IP6_OPT codes differ only in the lower two bits, so a AND mask may be
                                       applied to test for all of these encodings in parallel. */
#define BDK_PKI_LTYPE_E_IPCOMP (0xe) /**< IP Compressed. Previous layer (L3/IL3) protocol value or IPv6 next header equals 108. */
#define BDK_PKI_LTYPE_E_IPFRAG (0xd) /**< Fragment. Previous layer (L3/IL3) indicated a fragment. */
#define BDK_PKI_LTYPE_E_IPSEC_ESP (0xc) /**< IPSEC (ESP/AH). The IP packet may require IPSEC decryption or tunnel handling:
                                       * The packet is IPSEC ESP (i.e. the IPv4 protocol value or the initial IPv6 next
                                       header equals 50).
                                       * The packet is IPSEC AH (i.e. the IPv4 protocol value or the initial IPv6 next
                                       header equals 51). */
#define BDK_PKI_LTYPE_E_NONE (0) /**< No parsing was attempted at this layer. For PCAM*_ACTION[SETTY] indicates the pointer
                                       should not be changed. */
#define BDK_PKI_LTYPE_E_NVGRE (0x15) /**< NVGRE with following inner Ethernet frame. */
#define BDK_PKI_LTYPE_E_RARP (7) /**< RARP. The packet's L2 HDR TYPE field indicates RARP (i.e. equals 0x0806). */
#define BDK_PKI_LTYPE_E_SCTP (0x12) /**< SCTP. */
#define BDK_PKI_LTYPE_E_SNAP_PAYLD (5) /**< L2 parsing detected the L3 beginning location, but it did not match any known protocols.
                                       Also used to indicate the beginning of a 802.3 SNAP payload. */
#define BDK_PKI_LTYPE_E_SW28 (0x1c) /**< Reserved for software use. No preassigned use by hardware; only created when a layer
                                       matches a PCAM entry with PKI_CL()_PCAM()_ACTION()[SETTY]==SW28. */
#define BDK_PKI_LTYPE_E_SW29 (0x1d) /**< Reserved for software use. Similar to SW28. */
#define BDK_PKI_LTYPE_E_SW30 (0x1e) /**< Reserved for software use. Similar to SW28. */
#define BDK_PKI_LTYPE_E_SW31 (0x1f) /**< Reserved for software use. Similar to SW28. */
#define BDK_PKI_LTYPE_E_TCP (0x10) /**< TCP. */
#define BDK_PKI_LTYPE_E_UDP (0x11) /**< UDP. */
#define BDK_PKI_LTYPE_E_UDP_GENEVE (0x17) /**< UDP+GENEVE. The layer points at a UDP header immediately followed by a GENEVE
                                       header and inner Ethernet frame or inner IP. */
#define BDK_PKI_LTYPE_E_UDP_VXLAN (0x13) /**< UDP+VXLAN. The layer points at a UDP header immediately followed by a VXLAN header and
                                       inner Ethernet frame or inner IP. */
#define BDK_PKI_LTYPE_E_VLAN (2) /**< VLAN. Not used in PKI_WQE_S[*TY], but only in PKI_CL()_PCAM()_ACTION()[SETTY] to
                                       indicate a VLAN behavior. */

/**
 * Enumeration pki_opcode_e
 *
 * PKI Error Opcode Enumeration
 * Enumerates the values of WQE[OPCODE].
 */
#define BDK_PKI_OPCODE_E_IP_CHK (0x42) /**< IPv4 header checksum error: the IPv4 header has a checksum violation. Note that the
                                       hardware checksum calculation complies with section 5 of RFC 1624.  Note that this
                                       can be set in the case of an IPV4 packet with less bytes then specified in the IHL */
#define BDK_PKI_OPCODE_E_IP_HOP (0x45) /**< IP TTL hop: the IPv4 TTL field or the IPv6 hop count field are zero. */
#define BDK_PKI_OPCODE_E_IP_MAL (0x43) /**< IP malformed header: the packet is not long enough to contain the IP header.
                                       
                                       IPv4 packet:
                                       
                                       _ received packet length - fcs_pres_size < WQE[LCPTR]+IPv4_parsed_header_length
                                       
                                       _ or ipv4_header_length < 5
                                       
                                       _ or ipv4_total_length < 20
                                       
                                       IPv6 packet:
                                       
                                       _ received packet length - fcs_pres_size < WQE[LCPTR]+IPv6_header(40 bytes)
                                       
                                       where fcs_pres_size = (PKI_CL()_PKIND()_CFG[FCS_PRES] ? 4:0). */
#define BDK_PKI_OPCODE_E_IP_MALD (0x44) /**< IP malformed payload: the packet is not long enough to contain the payload bytes indicated
                                       by the IP header.
                                       
                                       IPv4 packet:
                                       
                                       _ received packet length - fcs_strip_size <  WQE[LCPTR]+IPv4_total_length
                                       
                                       IPv6 packet:
                                       
                                       _ received packet length - fcs_strip_size
                                       < WQE[LCPTR] + IPv6_header(40) + ipv6_payload_length
                                       
                                       Note this check also covers IPv6 extension headers, as extension headers are included in
                                       the payload length field.
                                       
                                       where fcs_strip_size = (PKI_CL()_STYLE()_CFG[FCS_STRIP] ? 4:0). */
#define BDK_PKI_OPCODE_E_IP_NOT (0x41) /**< The IP version field is neither 4 nor 6. */
#define BDK_PKI_OPCODE_E_L2_FRAGMENT (0x20) /**< Fragment error: the packet is shorter than allowed and had an FCS error. */
#define BDK_PKI_OPCODE_E_L2_LENMISM (0x27) /**< Length mismatch error: the packet had a length that did not match the length field in the
                                       L2 header. */
#define BDK_PKI_OPCODE_E_L2_MAL (0x24) /**< L2 header malformed: the packet is not long enough to contain the skipped bytes or L2
                                       header. */
#define BDK_PKI_OPCODE_E_L2_OVERRUN (0x21) /**< Overrun error: the packet is longer than allowed and had an FCS error. */
#define BDK_PKI_OPCODE_E_L2_OVERSIZE (0x25) /**< Oversize error: the packet is longer than allowed. */
#define BDK_PKI_OPCODE_E_L2_PFCS (0x22) /**< FCS error: PKI detected an FCS error on a received packet. */
#define BDK_PKI_OPCODE_E_L2_PUNY (0x23) /**< PUNY error: the packet was 4B or less when FCS stripping is enabled. */
#define BDK_PKI_OPCODE_E_L2_UNDERSIZE (0x26) /**< Undersize error: the packet is shorter than allowed. */
#define BDK_PKI_OPCODE_E_L4_CHK (0x62) /**< L4 checksum error: the L4 checksum value is bad. The hardware checksum calculation
                                       complies with section 5 of RFC 1624. */
#define BDK_PKI_OPCODE_E_L4_LEN (0x63) /**< UDP length error: The UDP length field would make the UDP data longer than what remains in
                                       the IP packet (as defined by the IP header length field).
                                       
                                       IP/TCP, IP/SCTP: Will not assert.
                                       
                                       IPv4/UDP: ipv4_total_length < IP_header_len + UDP_length
                                       
                                       IPv6/UDP: ipv6_payload_length < IPv6_extension_len + UDP_length */
#define BDK_PKI_OPCODE_E_L4_MAL (0x61) /**< Malformed L4:
                                       TCP:
                                       
                                       _ received packet length - fcs_pres_size < WQE[LFPTR] + (TCP_data_offset * 4)
                                       
                                       _ or TCP_data_offset < 5
                                       
                                       UDP:
                                       
                                       _ received_packet_length - fcs_pres_size < WQE[LFPTR] + UDP_header_length (8B)
                                       
                                       where fcs_pres_size = (PKI_CL()_PKIND()_CFG[FCS_PRES] ? 4:0). */
#define BDK_PKI_OPCODE_E_L4_PORT (0x64) /**< Bad L4 Port: The packet is TCP, UDP or SCTP and the source or destination port is 0. */
#define BDK_PKI_OPCODE_E_RE_BUFS_OFLOW (0x16) /**< Packet exceeded the maxiumum of 255 FPA buffers. */
#define BDK_PKI_OPCODE_E_RE_DMAPKT (0xf) /**< DMA packet error: The packet experienced one or more errors during the DMA read operation.
                                       Applicable only to the DPI interface. */
#define BDK_PKI_OPCODE_E_RE_FCS (7) /**< FCS error: the packet was received with an error. If the packet arrived via a BGX
                                       interface, the packet had an FCS error. Not applicable when the packet arrived via the
                                       DPI interface. */
#define BDK_PKI_OPCODE_E_RE_FCS_RCV (8) /**< FCS receive error: the packet was received with an error. If the packet arrived via a BGX
                                       interface operating at data rates of >= 10 Gb/s, the packet had both an FCS and data
                                       reception error. Not applicable when the packet arrived via the DPI interface. */
#define BDK_PKI_OPCODE_E_RE_JABBER (2) /**< Jabber error: the packet was too large and is truncated. Applicable only to BGX
                                       interfaces. */
#define BDK_PKI_OPCODE_E_RE_MEMOUT (0x15) /**< PKI ran out of FPA buffers while receiving the packet. */
#define BDK_PKI_OPCODE_E_RE_NONE (0) /**< No error. */
#define BDK_PKI_OPCODE_E_RE_PARTIAL (1) /**< Partial error: the packet was partially received. If the packet arrived via a BGX
                                       interface, internal buffering/bandwidth was not adequate to receive the entire packet. Not
                                       applicable when the packet arrived via the DPI interface. */
#define BDK_PKI_OPCODE_E_RE_PKIPAR (0x13) /**< PKI parity error: Uncorrected PKI-internal parity error was detected during the reassembly
                                       or processing of this packet. PKI_CL()_ECC_INT[DMEM_PERR] or [RF_PERR] will indicate
                                       the RAM with the parity error. This error has highest priority over any other errors. */
#define BDK_PKI_OPCODE_E_RE_PKIPCAM (0x14) /**< PKI PCAM access error. Either:
                                       
                                       1) Internal port conflict, or,
                                       
                                       2) Soft error or programming conflict was detected during the processing of this packet.
                                       PKI_CL()_INT[PCAM_CONF] was also set. Once a conflict is detected, the PCAM state is
                                       unpredictable and is required to be fully reconfigured before further valid processing can
                                       take place.
                                       
                                       INTERNAL: Case 1 is where the sequencer had PCAM operations with overlapping accesses
                                       between two engines. */
#define BDK_PKI_OPCODE_E_RE_RX_CTL (0xb) /**< BGX RX error: the packet had one or more data reception errors in which a control byte was
                                       detected in the frame. Applicable only to BGX interface ports. */
#define BDK_PKI_OPCODE_E_RE_SKIP (0xc) /**< Skip error: packet was not large enough to accommodate MAC skip data. For BGX interfaces,
                                       the BGX()_SMU()_RX_UDD_SKP[LEN] exceeded the received packet byte count.  Not
                                       applicable when the packet arrived via the DPI interface. */
#define BDK_PKI_OPCODE_E_RE_TERMINATE (9) /**< Terminate error: the packet was terminated incorrectly. For BGX interfaces operating at
                                       data rates of >= 10 Gb/s, the packet was terminated with an idle cycle instead of a
                                       terminate control cycle. For BGX interfaces operating at data rates of <= 1 Gb/s, the
                                       packet had a CarrierExtendError before the slot time expired. Not applicable when the
                                       packet arrived via the DPI interface. */
#define BDK_PKI_OPCODE_E_TCP_FLAG (0x65) /**< The packet is TCP and has bad flags. Indicates any of the following conditions:
                                       
                                       <pre>
                                       {URG, ACK, PSH, RST, SYN, FIN}
                                       6'b000001 = (FIN only).
                                       6'b000000 = (0).
                                       6'bxxx1x1 = (RST+FIN+*).
                                       6'b1xxx1x = (URG+SYN+*).
                                       6'bxxx11x = (RST+SYN+*).
                                       6'bxxxx11 = (SYN+FIN+*).
                                       </pre> */

/**
 * Enumeration pki_pcam_term_e
 *
 * PKI PCAM Term Enumeration
 * Enumerates the virtual-CAM type for the PKI_CL()_PCAM()_TERM()[TERM] field.
 * In the table below:
 * * 'MATCH' refers to PKI_CL()_PCAM()_MATCH().
 * * 'ACTION' refers to PKI_CL()_PCAM()_ACTION() for the PCAM entry that matches.
 * * The 'Bank' column indicates which PCAM bank must contain the match data.
 * * The 'Adv' column indicates if PKI_CL()_PCAM()_ACTION()[ADVANCE] may be non-zero;
 *   'No' indicates it may not be non-zero; otherwise indicates the typical ADVANCE value.
 * * The 'PMC' column indicates if PKI_CL()_PCAM()_ACTION()[PMC] may be non-zero.
 *   The typical PMC value is zero.
 * * The 'SETTY' column indicates if PKI_CL()_PCAM()_ACTION()[SETTY] may be non-zero,
 * and if so either which values it may take or which WQE pointer
 * field and type field will be set to the SETTY value when SETTY!=NONE (0). For example, LFTY
 * indicates that if
 * PKI_CL()_PCAM()_ACTION()[SETTY]!=NONE then WQE[LFTY] will be set to
 * PKI_CL()_PCAM()_ACTION()[SETTY] and WQE[LFPTR] will be set to the
 * current parse point.
 *
 * INTERNAL: The PCAM is banked for alternating accesses, so the bank
 * must toggle between each sequencer access for maximum performance.
 */
#define BDK_PKI_PCAM_TERM_E_DMACH (0xa) /**< L2 Destination MAC address high. This match is only performed if L2 parsing was enabled.
                                       _ MATCH<31:16> = Reserved.
                                       _ MATCH<15:0> = First two bytes of DMAC. */
#define BDK_PKI_PCAM_TERM_E_DMACL (0xb) /**< L2 Destination MAC address low. This match is only performed if L2 parsing was enabled.
                                       _ MATCH<31:0> = Low four bytes of DMAC.
                                       
                                       The parser will add an offset of 12 in addition to any
                                       PKI_CL()_PCAM()_ACTION()[OFFSET]. */
#define BDK_PKI_PCAM_TERM_E_DSA (0x13) /**< DSA header. This match is only performed if DSA was enabled.
                                       
                                       _ MATCH<31:0> = First 32 bits of DSA header.
                                       
                                       ACTION[SETTY] has special behavior for DSA; if ACTION[SETTY]==VLAN, then the DSA data is
                                       treated as a VLAN and WQE[VV], WQE[VLPTR] and conditionally WQE[VS] will be set.
                                       If ACTION[SETTY]==NONE (0), the PCAM entry will not affect any of WQE[VV,VLPTR,VS]. */
#define BDK_PKI_PCAM_TERM_E_ETHTYPE0 (0x18) /**< L2 first custom Ethertype. This match is only performed if L2 parsing was enabled.
                                       _ MATCH<31:16> = Ethertype.
                                       _ MATCH<15:0> = Next 2 bytes following ethertype.
                                       
                                       ACTION[SETTY] has special behavior for ETHTYPE*; if ACTION[SETTY]==VLAN, then the
                                       Ethertype
                                       is treated as a VLAN and WQE[VV], WQE[VLPTR] and conditionally WQE[VS] will be set.
                                       If ACTION[SETTY] is neither NONE nor VLAN, then PKI will set WQE[LBTY] and WQE[LBPTR] on a
                                       match.
                                       If ACTION[SETTY]==NONE (0), the PCAM entry will not affect any of
                                       WQE[VV,VLPTR,VS,LBTY,LBPTR].
                                       
                                       NONE or VLAN may be the most common ACTION[SETTY] values used in these ETHTYPE cases.
                                       SW28,
                                       SW29, SW30, and SW31 may also be useful ACTION[SETTY]'s, as might others. */
#define BDK_PKI_PCAM_TERM_E_ETHTYPE1 (0x19) /**< L2 second custom Ethertype. Similar to ETHTYPE0. This match is only performed if the
                                       earlier ETHTYPE0 found a match. */
#define BDK_PKI_PCAM_TERM_E_ETHTYPE2 (0x1a) /**< L2 third custom Ethertype. Similar to ETHTYPE0. This match is only performed if the
                                       earlier ETHTYPE1 found a match. */
#define BDK_PKI_PCAM_TERM_E_ETHTYPE3 (0x1b) /**< L2 fourth custom Ethertype. Similar to ETHTYPE0. This match is only performed if the
                                       earlier ETHTYPE2 found a match. */
#define BDK_PKI_PCAM_TERM_E_GLORT (0x12) /**< Fulcrum routing address. This match is only performed if FULCRUM parsing was enabled.
                                       _ MATCH<31:16> = Fulcrum source GLORT.
                                       _ MATCH<15:0> = Fulcrum destination GLORT.
                                       
                                       ACTION[SETTY] has special behavior for GLORT; if ACTION[SETTY]==VLAN, then the glort is
                                       treated as a VLAN and WQE[VV], WQE[VLPTR] and conditionally WQE[VS] will be set.
                                       If ACTION[SETTY]==NONE (0), the PCAM entry will not affect any of WQE[VV,VLPTR,VS]. */
#define BDK_PKI_PCAM_TERM_E_HIGIG (5) /**< HiGig header. This match is only performed if HiGig parsing was enabled. If HiGig1:
                                       _ MATCH<31> = HiGig source module id <6>.
                                       _ MATCH<30> = HiGig source module id <5>.
                                       _ MATCH<29:16> = Reserved.
                                       _ MATCH<15:11> = HiGig source module id <5:0>.
                                       _ MATCH<10:8> = HiGig opcode.
                                       _ MATCH<7:6> = Reserved.
                                       _ MATCH<5:0> = HiGig source port/tgid <5:0>.
                                       
                                       If HiGig2:
                                       _ MATCH<31:30> = Reserved.
                                       _ MATCH<29> = HiGig2 multicast.
                                       _ MATCH<28:25> = HiGig2 header traffic class.
                                       _ MATCH<24:16> = Reserved.
                                       _ MATCH<15:8> = HiGig2 source module id.
                                       _ MATCH<7:0> = HiGig2 source port.
                                       
                                       INTERNAL: MATCH includes all bits from bytes 9,8,1,0 of the header but we do not commit to
                                       other bits from those bytes in the above specification to leave room for future
                                       extractions. */
#define BDK_PKI_PCAM_TERM_E_HIGIGD (4) /**< HiGig destination header. This match is only performed if HiGig parsing was enabled. If
                                       HiGig1:
                                       _ MATCH<31:30> = Reserved.
                                       _ MATCH<29:27> = HiGig opcode.
                                       _ MATCH<26> = Higig dest module id <6>.
                                       _ MATCH<25> = Higig dest module id <5>.
                                       _ MATCH<24:16> = Reserved.
                                       _ MATCH<15:11> = Higig dest port <4:0>.
                                       _ MATCH<10:5> = Reserved.
                                       _ MATCH<4:0> = Higig dest module id <4:0>.
                                       
                                       If HiGig2:
                                       _ MATCH<31:30> = Reserved.
                                       _ MATCH<29> = HiGig2 multicast.
                                       _ MATCH<28:25> = HiGig2 traffic class.
                                       _ MATCH<24:16> = Reserved.
                                       _ MATCH<15:8> = HiGig2 dest module id.
                                       _ MATCH<7:0> = HiGig2 dest port. */
#define BDK_PKI_PCAM_TERM_E_IL3_FLAGS (0x2b) /**< Inner L3 flags summary. This match is only performed if LE parsing was enabled and IP-in-
                                       IP was found (WQE[LETY]==IP*).
                                       _ MATCH<31:24> = DiffSrv (IPv4) or Flowclass (IPv6).
                                       _ MATCH<23:16> = Next header/ Protocol.
                                       _ MATCH<12:8> = WQE[LETY] as decoded up to this point.
                                       _ MATCH<0> = Fragment.
                                       
                                       NONE may be the most common ACTION[SETTY] value used in this case. SW28,
                                       SW29, SW30, and SW31 may also be useful ACTION[SETTY]'s, as might others.
                                       If ACTION[SETTY]!=NONE (0), then PKI will set WQE[LFTY] and WQE[LFPTR] on a match. */
#define BDK_PKI_PCAM_TERM_E_L2_CUSTOM (2) /**< Pre-L2 custom header.
                                       
                                       _ MATCH<31:0> = Custom extract controlled by PKI_CL()_PKIND()_L2_CUSTOM. */
#define BDK_PKI_PCAM_TERM_E_L3_FLAGS (0x23) /**< L3 flags summary. This match is only performed if LC parsing was enabled and IP was found
                                       (WQE[LCTY]==IP*).
                                       _ MATCH<31:24> = DiffSrv (IPv4) or Flowclass (IPv6).
                                       _ MATCH<23:16> = Next header/ Protocol.
                                       _ MATCH<12:8> = WQE[LCTY] as decoded up to this point.
                                       _ MATCH<0> = Fragment.
                                       
                                       NONE may be the most common ACTION[SETTY] value used in this case. SW28,
                                       SW29, SW30, and SW31 may also be useful ACTION[SETTY]'s, as might others.
                                       If ACTION[SETTY]!=NONE (0), then PKI will set WQE[LDTY] and WQE[LDPTR] on a match. */
#define BDK_PKI_PCAM_TERM_E_L4_PORT (0x30) /**< L4 destination port and flags. This match is only performed if LF parsing was enabled and
                                       IP was found (see algorithms).
                                       _ MATCH<23:16> = IPv4 proto or IPv6 next_header.
                                       (Use 6 to match TCP, 17 for UDP, 132 for SCTP.)
                                       
                                       _ MATCH<15:0> = TCP/UDP/SCTP destination port. (Specifically the 16 bits from packet bytes
                                       WQE[LFPTR]+2, as the packet need not be TCP/UDP/SCTP.)
                                       
                                       NONE may be the most common ACTION[SETTY] value used in this case. GTP, SW28,
                                       SW29, SW30, and SW31 may also be useful ACTION[SETTY]'s, as might others.
                                       If ACTION[SETTY]!=NONE (0), then ACTION[ADVANCE] may be non-zero (typically the
                                       TCP/UDP/SCTP header
                                       size), and PKI will set WQE[LGTY]=ACTION[SETTY] and WQE[LGPTR]=ACTION[ADVANCE]+WQE[LFPTR]
                                       on a match. */
#define BDK_PKI_PCAM_TERM_E_LD_VNI (0x28) /**< Virtualization tunnel identifier. This match is only performed if LD parsing was enabled
                                       and NVGRE/VXLAN/GENEVE was found (WQE[LDTY]==NVGRE/VXLAN/GENEVE).
                                       _ MATCH<31:8> = VNI (GENEVE) / VNI (VXLAN) / TNI (GRE).
                                       _ MATCH<7>   = OAM frame bit (GENEVE) / Reserved (VXLAN) / Reserved (GRE).
                                       _ MATCH<6:0> = Reserved. */
#define BDK_PKI_PCAM_TERM_E_LG_CUSTOM (0x39) /**< LG custom match. This match is only performed if LE and LG parsing was enabled.
                                       _ MATCH<31:0> = Custom extract controlled by PKI_CL()_PKIND()_LG_CUSTOM
                                       
                                       NONE may be the most common ACTION[SETTY] value used in this case. SW28,
                                       SW29, SW30, and SW31 may also be useful ACTION[SETTY]'s, as might others.
                                       If ACTION[SETTY]!=NONE (0), then PKI will set WQE[LGTY] and WQE[LGPTR] on a match. */
#define BDK_PKI_PCAM_TERM_E_MPLS0 (0x1e) /**< Top MPLS Label.
                                       _ MATCH<31:12> = Label
                                       _ MATCH<11:9> = QoS
                                       _ MATCH<8> = Last-Label indicator
                                       _ MATCH<7:0> = TTL */
#define BDK_PKI_PCAM_TERM_E_NONE (0) /**< CAM entry disabled, will never match. */

/**
 * Enumeration pki_pf_int_vec_e
 *
 * PKI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_PKI_PF_INT_VEC_E_CL_ECCX(a) (6 + (a)) /**< See interrupt clears PKI_CL(0..1)_ECC_INT, interrupt sets PKI_CL(0..1)_ECC_INT_W1S,
                                       enable clears PKI_CL(0..1)_ECC_INT_ENA_W1C, and enable sets PKI_CL(0..1)_ECC_INT_ENA_W1S. */
#define BDK_PKI_PF_INT_VEC_E_CL_INTX(a) (4 + (a)) /**< See interrupt clears PKI_CL(0..1)_INT, interrupt sets PKI_CL(0..1)_INT_W1S,
                                       enable clears PKI_CL(0..1)_INT_ENA_W1C, and enable sets PKI_CL(0..1)_INT_ENA_W1S. */
#define BDK_PKI_PF_INT_VEC_E_ECC0 (1) /**< See interrupt clears PKI_ECC_INT0, interrupt sets PKI_ECC_INT0_W1S,
                                       enable clears PKI_ECC_INT0_ENA_W1C, and enable sets PKI_ECC_INT0_ENA_W1S. */
#define BDK_PKI_PF_INT_VEC_E_ECC1 (2) /**< See interrupt clears PKI_ECC_INT1, interrupt sets PKI_ECC_INT1_W1S,
                                       enable clears PKI_ECC_INT1_ENA_W1C, and enable sets PKI_ECC_INT1_ENA_W1S. */
#define BDK_PKI_PF_INT_VEC_E_ECC2 (3) /**< See interrupt clears PKI_ECC_INT2, interrupt sets PKI_ECC_INT2_W1S,
                                       enable clears PKI_ECC_INT2_ENA_W1C, and enable sets PKI_ECC_INT2_ENA_W1S. */
#define BDK_PKI_PF_INT_VEC_E_GEN (0) /**< See interrupt clears PKI_GEN_INT, interrupt sets PKI_GEN_INT_W1S,
                                       enable clears PKI_GEN_INT_ENA_W1C, and enable sets PKI_GEN_INT_ENA_W1S. */

/**
 * Enumeration pki_qpgqos_e
 *
 * PKI QPG QoS Algorithm Enumeration
 * Enumerates the values of PKI_CL()_STYLE()_ALG.
 */
#define BDK_PKI_QPGQOS_E_DIFF (4) /**< If LC Diffsrv is parsed, use for QPG calculation. */
#define BDK_PKI_QPGQOS_E_DSA_SRC (3) /**< If DSA is parsed, use source port for QPG calculation. */
#define BDK_PKI_QPGQOS_E_HIGIG (5) /**< If HiGig is parsed, use for QPG calculation. */
#define BDK_PKI_QPGQOS_E_MPLS (2) /**< If MPLS is parsed, use for QPG calculation. */
#define BDK_PKI_QPGQOS_E_NONE (0) /**< No QoS field added in QPG calculation. */
#define BDK_PKI_QPGQOS_E_VLAN (1) /**< If VLAN is parsed, use for QPG calculation. This may not be used if Fulcrum/DSA has
                                       parsing enabled. */

/**
 * Enumeration pki_reasm_e
 *
 * PKI Reassembly Enumeration
 * Enumerates the values of the reassembly-ID map.
 */
#define BDK_PKI_REASM_E_DPI_REASM (2) /**< DPI reassembly-ID. */
#define BDK_PKI_REASM_E_LOOPBACK0_REASM (0) /**< Loopback reassembly-ID. */
#define BDK_PKI_REASM_E_LOOPBACK1_REASM (1) /**< Loopback reassembly-ID. */
#define BDK_PKI_REASM_E_MAC_REASMX(a) (0 + (a)) /**< Remaining reassembly-ID's shared by the packet interfaces. The following
                                       registers control the range for the various packet interfaces:
                                       BGX()_CMR()_RX_ID_MAP[RID]. */
#define BDK_PKI_REASM_E_NUM_REASM (0xe) /**< Total number of reassembly-IDs used in the system. */

/**
 * Structure pki_bewq_s
 *
 * INTERNAL: PKI Back End WQE Structure
 *
 * This structure describes the handoff structure between an IPE and PKI back end. The fields are
 * similar to the WQE.
 */
union bdk_pki_bewq_s
{
    uint64_t u[16];
    struct bdk_pki_bewq_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t node                  : 2;  /**< [ 63: 62] BE pass-through. */
        uint64_t reserved_60_61        : 2;
        uint64_t aura                  : 12; /**< [ 59: 48] BE optionally recomputes. */
        uint64_t reserved_47           : 1;
        uint64_t apad                  : 3;  /**< [ 46: 44] BE pass-through; used for data generation. */
        uint64_t port                  : 12; /**< [ 43: 32] BE uses to recompute WQE[CHAN]. */
        uint64_t fcsptr                : 8;  /**< [ 31: 24] Byte location at which to start FCS calculation. Sequencer loads from
                                                                 PKI_CL()_PKIND()_SKIP[FCS_SKIP]. */
        uint64_t style                 : 8;  /**< [ 23: 16] BE pass-through; used for CSR lookup. */
        uint64_t reserved_6_15         : 10;
        uint64_t pknd                  : 6;  /**< [  5:  0] BE ignores. */
#else /* Word 0 - Little Endian */
        uint64_t pknd                  : 6;  /**< [  5:  0] BE ignores. */
        uint64_t reserved_6_15         : 10;
        uint64_t style                 : 8;  /**< [ 23: 16] BE pass-through; used for CSR lookup. */
        uint64_t fcsptr                : 8;  /**< [ 31: 24] Byte location at which to start FCS calculation. Sequencer loads from
                                                                 PKI_CL()_PKIND()_SKIP[FCS_SKIP]. */
        uint64_t port                  : 12; /**< [ 43: 32] BE uses to recompute WQE[CHAN]. */
        uint64_t apad                  : 3;  /**< [ 46: 44] BE pass-through; used for data generation. */
        uint64_t reserved_47           : 1;
        uint64_t aura                  : 12; /**< [ 59: 48] BE optionally recomputes. */
        uint64_t reserved_60_61        : 2;
        uint64_t node                  : 2;  /**< [ 63: 62] BE pass-through. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t len                   : 16; /**< [127:112] BE replaces with complete packet length. */
        uint64_t reserved_108_111      : 4;
        uint64_t grp                   : 10; /**< [107: 98] BE optionally recomputes. */
        uint64_t tt                    : 2;  /**< [ 97: 96] BE optionally recomputes. */
        uint64_t tag                   : 32; /**< [ 95: 64] BE optionally recomputes. */
#else /* Word 1 - Little Endian */
        uint64_t tag                   : 32; /**< [ 95: 64] BE optionally recomputes. */
        uint64_t tt                    : 2;  /**< [ 97: 96] BE optionally recomputes. */
        uint64_t grp                   : 10; /**< [107: 98] BE optionally recomputes. */
        uint64_t reserved_108_111      : 4;
        uint64_t len                   : 16; /**< [127:112] BE replaces with complete packet length. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t sw                    : 1;  /**< [191:191] BE ignores. */
        uint64_t lgty                  : 5;  /**< [190:186] BE pass-through; used for tagging/checksum. */
        uint64_t lfty                  : 5;  /**< [185:181] BE pass-through; used for tagging/checksum. */
        uint64_t lety                  : 5;  /**< [180:176] BE pass-through; used for tagging/checksum. */
        uint64_t ldty                  : 5;  /**< [175:171] BE pass-through; used for tagging/checksum. */
        uint64_t lcty                  : 5;  /**< [170:166] BE pass-through; used for tagging/checksum. */
        uint64_t lbty                  : 5;  /**< [165:161] BE pass-through; used for tagging/checksum. */
        uint64_t lae                   : 1;  /**< [160:160] BE pass-through; used for tagging/checksum. */
        uint64_t reserved_152_159      : 8;
        uint64_t vv                    : 1;  /**< [151:151] BE ignores. */
        uint64_t vs                    : 1;  /**< [150:150] BE ignores. */
        uint64_t sh                    : 1;  /**< [149:149] BE pass-through; used for statistics. */
        uint64_t pf                    : 4;  /**< [148:145] BE ignores. */
        uint64_t l3fr                  : 1;  /**< [144:144] BE ignores. */
        uint64_t l3b                   : 1;  /**< [143:143] BE pass-through; used for statistics. */
        uint64_t l3m                   : 1;  /**< [142:142] BE pass-through; used for statistics. */
        uint64_t l2b                   : 1;  /**< [141:141] BE pass-through; used for statistics. */
        uint64_t l2m                   : 1;  /**< [140:140] BE pass-through; used for statistics. */
        uint64_t raw                   : 1;  /**< [139:139] BE pass-through; used for statistics. */
        uint64_t errlev                : 3;  /**< [138:136] BE recomputes on error. */
        uint64_t opcode                : 8;  /**< [135:128] BE recomputes on error. */
#else /* Word 2 - Little Endian */
        uint64_t opcode                : 8;  /**< [135:128] BE recomputes on error. */
        uint64_t errlev                : 3;  /**< [138:136] BE recomputes on error. */
        uint64_t raw                   : 1;  /**< [139:139] BE pass-through; used for statistics. */
        uint64_t l2m                   : 1;  /**< [140:140] BE pass-through; used for statistics. */
        uint64_t l2b                   : 1;  /**< [141:141] BE pass-through; used for statistics. */
        uint64_t l3m                   : 1;  /**< [142:142] BE pass-through; used for statistics. */
        uint64_t l3b                   : 1;  /**< [143:143] BE pass-through; used for statistics. */
        uint64_t l3fr                  : 1;  /**< [144:144] BE ignores. */
        uint64_t pf                    : 4;  /**< [148:145] BE ignores. */
        uint64_t sh                    : 1;  /**< [149:149] BE pass-through; used for statistics. */
        uint64_t vs                    : 1;  /**< [150:150] BE ignores. */
        uint64_t vv                    : 1;  /**< [151:151] BE ignores. */
        uint64_t reserved_152_159      : 8;
        uint64_t lae                   : 1;  /**< [160:160] BE pass-through; used for tagging/checksum. */
        uint64_t lbty                  : 5;  /**< [165:161] BE pass-through; used for tagging/checksum. */
        uint64_t lcty                  : 5;  /**< [170:166] BE pass-through; used for tagging/checksum. */
        uint64_t ldty                  : 5;  /**< [175:171] BE pass-through; used for tagging/checksum. */
        uint64_t lety                  : 5;  /**< [180:176] BE pass-through; used for tagging/checksum. */
        uint64_t lfty                  : 5;  /**< [185:181] BE pass-through; used for tagging/checksum. */
        uint64_t lgty                  : 5;  /**< [190:186] BE pass-through; used for tagging/checksum. */
        uint64_t sw                    : 1;  /**< [191:191] BE ignores. */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t cfg                   : 32; /**< [255:224] Value of PKI_CL()_STYLE()_CFG<31:0> for this packet. BE replaces with Size/Addr.. */
        uint64_t cfg2                  : 32; /**< [223:192] Value of PKI_CL()_STYLE()_CFG2<31:0> for this packet. BE replaces with Size/Addr. */
#else /* Word 3 - Little Endian */
        uint64_t cfg2                  : 32; /**< [223:192] Value of PKI_CL()_STYLE()_CFG2<31:0> for this packet. BE replaces with Size/Addr. */
        uint64_t cfg                   : 32; /**< [255:224] Value of PKI_CL()_STYLE()_CFG<31:0> for this packet. BE replaces with Size/Addr.. */
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t vlptr                 : 8;  /**< [319:312] BE pass-through; used for tagging. */
        uint64_t lgptr                 : 8;  /**< [311:304] BE pass-through; used for tagging/checksum. */
        uint64_t lfptr                 : 8;  /**< [303:296] BE pass-through; used for tagging/checksum. */
        uint64_t leptr                 : 8;  /**< [295:288] BE pass-through; used for tagging/checksum. */
        uint64_t ldptr                 : 8;  /**< [287:280] BE pass-through; used for tagging/checksum. */
        uint64_t lcptr                 : 8;  /**< [279:272] BE pass-through; used for tagging/checksum. */
        uint64_t lbptr                 : 8;  /**< [271:264] BE pass-through; used for tagging/checksum. */
        uint64_t laptr                 : 8;  /**< [263:256] BE pass-through; used for tagging/checksum. */
#else /* Word 4 - Little Endian */
        uint64_t laptr                 : 8;  /**< [263:256] BE pass-through; used for tagging/checksum. */
        uint64_t lbptr                 : 8;  /**< [271:264] BE pass-through; used for tagging/checksum. */
        uint64_t lcptr                 : 8;  /**< [279:272] BE pass-through; used for tagging/checksum. */
        uint64_t ldptr                 : 8;  /**< [287:280] BE pass-through; used for tagging/checksum. */
        uint64_t leptr                 : 8;  /**< [295:288] BE pass-through; used for tagging/checksum. */
        uint64_t lfptr                 : 8;  /**< [303:296] BE pass-through; used for tagging/checksum. */
        uint64_t lgptr                 : 8;  /**< [311:304] BE pass-through; used for tagging/checksum. */
        uint64_t vlptr                 : 8;  /**< [319:312] BE pass-through; used for tagging. */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t reserved_320_383      : 64;
#else /* Word 5 - Little Endian */
        uint64_t reserved_320_383      : 64;
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t reserved_384_447      : 64;
#else /* Word 6 - Little Endian */
        uint64_t reserved_384_447      : 64;
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t reserved_448_511      : 64;
#else /* Word 7 - Little Endian */
        uint64_t reserved_448_511      : 64;
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t reserved_512_575      : 64;
#else /* Word 8 - Little Endian */
        uint64_t reserved_512_575      : 64;
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t reserved_576_639      : 64;
#else /* Word 9 - Little Endian */
        uint64_t reserved_576_639      : 64;
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t reserved_640_703      : 64;
#else /* Word 10 - Little Endian */
        uint64_t reserved_640_703      : 64;
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t reserved_704_767      : 64;
#else /* Word 11 - Little Endian */
        uint64_t reserved_704_767      : 64;
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t reserved_768_831      : 64;
#else /* Word 12 - Little Endian */
        uint64_t reserved_768_831      : 64;
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t reserved_832_895      : 64;
#else /* Word 13 - Little Endian */
        uint64_t reserved_832_895      : 64;
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t reserved_896_959      : 64;
#else /* Word 14 - Little Endian */
        uint64_t reserved_896_959      : 64;
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t reserved_960_1023     : 64;
#else /* Word 15 - Little Endian */
        uint64_t reserved_960_1023     : 64;
#endif /* Word 15 - End */
    } s;
    /* struct bdk_pki_bewq_s_s cn; */
};

/**
 * Structure pki_buflink_s
 *
 * PKI Buffer Link Structure
 * PKI and PKO can link packet segments together with this PKI_BUFLINK_S. When multiple
 * packet segments are linked, a valid PKI_BUFLINK_S is present 8 bytes before the first
 * byte of any earlier segment. The last segment linked does not have a next segment,
 * and must be preceded by 16 bytes of valid L2/DRAM where the PKI_BUFLINK_S normally
 * exists, but need not have a valid PKI_BUFLINK_S in the space. CPU software
 * or PKO hardware may read, but effectively should not use, this "invalid
 * PKI_BUFLINK_S".
 *
 * PKI_BUFLINK_S's are not required be naturally aligned (to 128-bits) in L2/DRAM,
 * though the last segments and corresponding PKI_BUFLINK_S's
 * that PKI creates for packet input are naturally-aligned.
 */
union bdk_pki_buflink_s
{
    uint64_t u[2];
    struct bdk_pki_buflink_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t i                     : 1;  /**< [ 31: 31] Invert free. PKI writes zero to this bit. PKO optionally uses this bit to control FPA
                                                                 buffer returns. See PKO_SEND_HDR_S[DF,II].

                                                                 On a PKO SEND, PKO frees the surrounding buffer to FPA when:
                                                                    PKO_SEND_HDR_S[DF] XOR (PKO_SEND_HDR_S[II] AND [I])
                                                                 is zero.

                                                                 PKO naturally aligns [ADDR] to 128 bytes before sending it to FPA as part of
                                                                 the buffer free. An FPA naturally-aligned pool is recommended, though opaque
                                                                 pool mode may also be possible. Refer to the FPA Chapter.

                                                                 PKO frees the buffer to the last prior PKO_SEND_AURA_S[AURA] in the
                                                                 PKO SEND descriptor, or to PKO_SEND_HDR_S[AURA] if there is not a prior
                                                                 PKO_SEND_AURA_S in the descriptor.

                                                                 PKO will not free [ADDR] to FPA until after it has finished reading
                                                                 this segment (and the PKI_BUFLINK_S that precedes this segment in
                                                                 the buffer, if necessary) from the buffer.
                                                                 Provided the path of descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 other descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in any
                                                                 order with respect to any processing of any descriptor that is in a
                                                                 different DQ. PKO may create the FPA
                                                                 free for [ADDR] in any order relative to any other PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND. */
        uint64_t av                    : 1;  /**< [ 30: 30] Aura valid. PKI writes a one to this bit, indicating AURA is valid.

                                                                 On a PKO SEND, if AV is set, the [AURA] field will be used to free [ADDR]. */
        uint64_t reserved_25_29        : 5;
        uint64_t aura                  : 9;  /**< [ 24: 16] If [AV] is set, aura which [ADDR] was allocated from. */
        uint64_t size                  : 16; /**< [ 15:  0] Size of the buffer/segment.

                                                                 The [SIZE] created by PKI always indicates the number of bytes available
                                                                 in the buffer. Except for the last linked buffer, [SIZE] is also exactly
                                                                 the number of bytes of packet data in the segment and the buffer.
                                                                 For the last segment created by PKI, [SIZE] will be larger than the
                                                                 number of valid packet bytes in the segment/buffer unless the packet
                                                                 data ends exactly at the end of the buffer.

                                                                 In the PKO case, if more than [SIZE] bytes are needed to reach
                                                                 PKO_SEND_HDR_S[TOTAL] packet data bytes, PKO continues fetching packet
                                                                 data from the next segment described by the PKI_BUFLINK_S that must
                                                                 reside in the 8 L2/DRAM bytes prior to [ADDR]. Let priorbytes = the
                                                                 sum of PKO_SEND_LINK_S[SIZE], all PKO_SEND_GATHER_S[SIZE]'s, and all
                                                                 PKO_SEND_IMM_S[SIZE]'s in this descriptor, plus the sum of all prior
                                                                 PKI_BUFLINK_S[SIZE]'s linked by the PKO_SEND_LINK_S. PKO does not
                                                                 reference nor use this PKI_BUFLINK_S segment when
                                                                 priorbytes >= PKO_SEND_HDR_S[TOTAL]. Otherwise, the
                                                                 number of bytes PKO uses from this PKI_BUFLINK_S segment is:

                                                                 _    min(PKO_SEND_HDR_S[TOTAL]-priorbytes, [SIZE])

                                                                 The sum of any PKO_SEND_IMM_S[SIZE]'s, PKO_SEND_GATHER_S[SIZE]'s, and
                                                                 PKO_SEND_LINK_S[SIZE]'s in the PKO Send descriptor plus any
                                                                 PKI_BUFLINK_S[SIZE]'s linked by any PKO_SEND_LINK_S must equal or
                                                                 exceed PKO_SEND_HDR_S[TOTAL]. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 16; /**< [ 15:  0] Size of the buffer/segment.

                                                                 The [SIZE] created by PKI always indicates the number of bytes available
                                                                 in the buffer. Except for the last linked buffer, [SIZE] is also exactly
                                                                 the number of bytes of packet data in the segment and the buffer.
                                                                 For the last segment created by PKI, [SIZE] will be larger than the
                                                                 number of valid packet bytes in the segment/buffer unless the packet
                                                                 data ends exactly at the end of the buffer.

                                                                 In the PKO case, if more than [SIZE] bytes are needed to reach
                                                                 PKO_SEND_HDR_S[TOTAL] packet data bytes, PKO continues fetching packet
                                                                 data from the next segment described by the PKI_BUFLINK_S that must
                                                                 reside in the 8 L2/DRAM bytes prior to [ADDR]. Let priorbytes = the
                                                                 sum of PKO_SEND_LINK_S[SIZE], all PKO_SEND_GATHER_S[SIZE]'s, and all
                                                                 PKO_SEND_IMM_S[SIZE]'s in this descriptor, plus the sum of all prior
                                                                 PKI_BUFLINK_S[SIZE]'s linked by the PKO_SEND_LINK_S. PKO does not
                                                                 reference nor use this PKI_BUFLINK_S segment when
                                                                 priorbytes >= PKO_SEND_HDR_S[TOTAL]. Otherwise, the
                                                                 number of bytes PKO uses from this PKI_BUFLINK_S segment is:

                                                                 _    min(PKO_SEND_HDR_S[TOTAL]-priorbytes, [SIZE])

                                                                 The sum of any PKO_SEND_IMM_S[SIZE]'s, PKO_SEND_GATHER_S[SIZE]'s, and
                                                                 PKO_SEND_LINK_S[SIZE]'s in the PKO Send descriptor plus any
                                                                 PKI_BUFLINK_S[SIZE]'s linked by any PKO_SEND_LINK_S must equal or
                                                                 exceed PKO_SEND_HDR_S[TOTAL]. */
        uint64_t aura                  : 9;  /**< [ 24: 16] If [AV] is set, aura which [ADDR] was allocated from. */
        uint64_t reserved_25_29        : 5;
        uint64_t av                    : 1;  /**< [ 30: 30] Aura valid. PKI writes a one to this bit, indicating AURA is valid.

                                                                 On a PKO SEND, if AV is set, the [AURA] field will be used to free [ADDR]. */
        uint64_t i                     : 1;  /**< [ 31: 31] Invert free. PKI writes zero to this bit. PKO optionally uses this bit to control FPA
                                                                 buffer returns. See PKO_SEND_HDR_S[DF,II].

                                                                 On a PKO SEND, PKO frees the surrounding buffer to FPA when:
                                                                    PKO_SEND_HDR_S[DF] XOR (PKO_SEND_HDR_S[II] AND [I])
                                                                 is zero.

                                                                 PKO naturally aligns [ADDR] to 128 bytes before sending it to FPA as part of
                                                                 the buffer free. An FPA naturally-aligned pool is recommended, though opaque
                                                                 pool mode may also be possible. Refer to the FPA Chapter.

                                                                 PKO frees the buffer to the last prior PKO_SEND_AURA_S[AURA] in the
                                                                 PKO SEND descriptor, or to PKO_SEND_HDR_S[AURA] if there is not a prior
                                                                 PKO_SEND_AURA_S in the descriptor.

                                                                 PKO will not free [ADDR] to FPA until after it has finished reading
                                                                 this segment (and the PKI_BUFLINK_S that precedes this segment in
                                                                 the buffer, if necessary) from the buffer.
                                                                 Provided the path of descriptors from the DQ through PKO to an output FIFO is
                                                                 unmodified between the descriptors (as should normally be the case, but it is
                                                                 possible for software to change the path), PKO also will not free
                                                                 [ADDR] to FPA until after it has completed all L2/DRAM reads related
                                                                 to processing any PKO_SEND_GATHER_S and any PKO_SEND_LINK_S in any
                                                                 other descriptor enqueued earlier in the same DQ. PKO may free [ADDR] in any
                                                                 order with respect to any processing of any descriptor that is in a
                                                                 different DQ. PKO may create the FPA
                                                                 free for [ADDR] in any order relative to any other PKO FPA
                                                                 frees needed to process this or any other PKO SEND descriptor,
                                                                 and in any order relative to any FPA frees/allocates needed for DQ DRAM
                                                                 buffering, and in any order relative to any FPA aura count
                                                                 updates needed to process a PKO_SEND_AURA_S subdescriptor in this
                                                                 or any other PKO SEND. The FPA free may occur in any order relative to any
                                                                 L2/DRAM updates or any work queue add needed to process this or
                                                                 any other PKO SEND. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t reserved_113_127      : 15;
        uint64_t addr                  : 49; /**< [112: 64] Address. ADDR is the IOVA L2/DRAM address of the first byte of packet data in
                                                                 the buffer/segment. The 16 bytes prior to [ADDR] must always be valid readable L2/DRAM
                                                                 locations, and must contain a valid PKI_BUFLINK_S if the remaining packet bytes do
                                                                 not fit in the [SIZE] bytes available in this buffer/segment.

                                                                 All valid [ADDR]'s created by PKI are naturally-aligned (to 128-bits). */
#else /* Word 1 - Little Endian */
        uint64_t addr                  : 49; /**< [112: 64] Address. ADDR is the IOVA L2/DRAM address of the first byte of packet data in
                                                                 the buffer/segment. The 16 bytes prior to [ADDR] must always be valid readable L2/DRAM
                                                                 locations, and must contain a valid PKI_BUFLINK_S if the remaining packet bytes do
                                                                 not fit in the [SIZE] bytes available in this buffer/segment.

                                                                 All valid [ADDR]'s created by PKI are naturally-aligned (to 128-bits). */
        uint64_t reserved_113_127      : 15;
#endif /* Word 1 - End */
    } s;
    /* struct bdk_pki_buflink_s_s cn; */
};

/**
 * Structure pki_fewq_s
 *
 * INTERNAL: PKI Front End WQE Structure
 *
 * This structure describes the handoff structure between the PKI front end and an IPE. The
 * fields are similar to the WQE.
 */
union bdk_pki_fewq_s
{
    uint64_t u[3];
    struct bdk_pki_fewq_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t port                  : 12; /**< [ 43: 32] FE initializes to port packet was received from. */
        uint64_t reserved_6_31         : 26;
        uint64_t pknd                  : 6;  /**< [  5:  0] FE initializes to pkind packet was received on. */
#else /* Word 0 - Little Endian */
        uint64_t pknd                  : 6;  /**< [  5:  0] FE initializes to pkind packet was received on. */
        uint64_t reserved_6_31         : 26;
        uint64_t port                  : 12; /**< [ 43: 32] FE initializes to port packet was received from. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t len                   : 16; /**< [127:112] FE initializes with packet header length, values 0-256. */
        uint64_t reserved_64_111       : 48;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64_111       : 48;
        uint64_t len                   : 16; /**< [127:112] FE initializes with packet header length, values 0-256. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_139_191      : 53;
        uint64_t errlev                : 3;  /**< [138:136] FE sets if receive error. */
        uint64_t opcode                : 8;  /**< [135:128] FE sets if receive error. */
#else /* Word 2 - Little Endian */
        uint64_t opcode                : 8;  /**< [135:128] FE sets if receive error. */
        uint64_t errlev                : 3;  /**< [138:136] FE sets if receive error. */
        uint64_t reserved_139_191      : 53;
#endif /* Word 2 - End */
    } s;
    /* struct bdk_pki_fewq_s_s cn; */
};

/**
 * Structure pki_inst_hdr_s
 *
 * PKI Instruction Header Structure
 */
union bdk_pki_inst_hdr_s
{
    uint64_t u;
    struct bdk_pki_inst_hdr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t w                     : 1;  /**< [ 63: 63] Indicates wider PKI_INST_HDR_S.
                                                                 0 = The PKI_INST_HDR_S is two bytes.
                                                                 1 = The PKI_INST_HDR_S is four or eight bytes. */
        uint64_t raw                   : 1;  /**< [ 62: 62] When set, WQE[RAW] will be set and statistics will accumulate in PKI_STAT()_STAT2 and the
                                                                 packet will never be dropped due to RED unless PKI_STYLE()_BUF[RAWDRP] is set. */
        uint64_t utag                  : 1;  /**< [ 61: 61] When set, PKI will use PKI_INST_HDR_S [TAG] to compute WQE[TAG].

                                                                 Must be 0 when PKI_INST_HDR_S[W] = 0. */
        uint64_t uqpg                  : 1;  /**< [ 60: 60] When set, PKI will use PKI_INST_HDR_S [QPG] to compute the QPG and indirectly WQE[AURA]
                                                                 and WQE[GRP].

                                                                 Must be 0 when PKI_INST_HDR_S[W] = 0. */
        uint64_t reserved_59           : 1;
        uint64_t pm                    : 3;  /**< [ 58: 56] The mode used to parse the packet, as an encoded value. The legal values are:
                                                                   0x0 = Parse starting at LA (L2).
                                                                   0x1 = Parse starting at LB (Custom).
                                                                   0x2 = Parse starting at LC (L3).
                                                                   0x3 = Reserved; parse starting at LD not supported.
                                                                   0x4 = Reserved; parse starting at LE not supported.
                                                                   0x5 = Reserved; parse starting at LF not supported.
                                                                   0x6 = Parse starting at LG (Custom/Application).
                                                                   0x7 = Parse nothing, uninterpreted.
                                                                   _ else = reserved.

                                                                   If most or all parsing stages are skipped, then PKI will have little input in the
                                                                 scheduling information loaded into the WQE. PKI_INST_HDR_S[QPG], PKI_INST_HDR_S[TT], and
                                                                 PKI_INST_HDR_S[TAG] may be of use to specify this scheduling information. In this case
                                                                 PKI_STYLE()_WQ2 and PKI_STYLE()_WQ4 may be used to force the decoded information in WQE
                                                                 WORD 2 and WORD 4. */
        uint64_t sl                    : 8;  /**< [ 55: 48] The number of bytes in the PKI_INST_HDR_S and number of bytes to advance to find the next
                                                                 parse item.
                                                                 The following bullets describe the minimum PKI_INST_HDR_S size and, thus, the minimum SL
                                                                 values for a packet:
                                                                 * When PKI_INST_HDR_S [UTAG] = 1, the PKI_INST_HDR_S must be eight bytes, so SL must be
                                                                 eight or more.

                                                                 * When PKI_INST_HDR_S[W] = 1 and PKI_INST_HDR_S [UTAG] = 0, the PKI_INST_HDR_S must be
                                                                 four bytes or more, so SL must be four or more.

                                                                 * When PKI_INST_HDR_S[W] = 0, the PKI_INST_HDR_S may be as small as two bytes, so SL must
                                                                 be two or more.

                                                                 The sum of PKI_INST_HDR_S[SL] and other advances is subject to restrictions as described
                                                                 elsewhere. */
        uint64_t utt                   : 1;  /**< [ 47: 47] When set, PKI uses PKI_INST_HDR_S[TT] to compute WQE[TT].

                                                                 This field is not present unless PKI_INST_HDR_S[W] is set. */
        uint64_t tt                    : 2;  /**< [ 46: 45] When PKI_INST_HDR_S [UTT] and PKI_INST_HDR_S[W] are set, PKI_INST_HDR_S[TT] is used to
                                                                 compute WQE[TT].

                                                                 This field is not present unless PKI_INST_HDR_S[W] is set. */
        uint64_t reserved_43_44        : 2;
        uint64_t qpg                   : 11; /**< [ 42: 32] When PKI_INST_HDR_S[UQPG] and PKI_INST_HDR_S[W] are set, PKI_INST_HDR_S [QPG] is used to
                                                                 indirectly compute WQE[AURA] and WQE[GRP].

                                                                 This field is not present unless PKI_INST_HDR_S[W] is set.

                                                                 The QPG table is generally allocated by software. As the QPG index points into this
                                                                 software allocated table, it is recommended that external components allow the
                                                                 PKI_INST_HDR_S[QPG] values they send to based off a programmable base (perhaps from a CSR
                                                                 inside that component) instead of hard-coding the base. */
        uint64_t tag                   : 32; /**< [ 31:  0] When PKI_INST_HDR_S[UTAG] and PKI_INST_HDR_S[W] are set, PKI_INST_HDR_S[TAG] is used to
                                                                 compute WQE[TAG].

                                                                 This field is not present unless PKI_INST_HDR_S [UTAG] is set. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0] When PKI_INST_HDR_S[UTAG] and PKI_INST_HDR_S[W] are set, PKI_INST_HDR_S[TAG] is used to
                                                                 compute WQE[TAG].

                                                                 This field is not present unless PKI_INST_HDR_S [UTAG] is set. */
        uint64_t qpg                   : 11; /**< [ 42: 32] When PKI_INST_HDR_S[UQPG] and PKI_INST_HDR_S[W] are set, PKI_INST_HDR_S [QPG] is used to
                                                                 indirectly compute WQE[AURA] and WQE[GRP].

                                                                 This field is not present unless PKI_INST_HDR_S[W] is set.

                                                                 The QPG table is generally allocated by software. As the QPG index points into this
                                                                 software allocated table, it is recommended that external components allow the
                                                                 PKI_INST_HDR_S[QPG] values they send to based off a programmable base (perhaps from a CSR
                                                                 inside that component) instead of hard-coding the base. */
        uint64_t reserved_43_44        : 2;
        uint64_t tt                    : 2;  /**< [ 46: 45] When PKI_INST_HDR_S [UTT] and PKI_INST_HDR_S[W] are set, PKI_INST_HDR_S[TT] is used to
                                                                 compute WQE[TT].

                                                                 This field is not present unless PKI_INST_HDR_S[W] is set. */
        uint64_t utt                   : 1;  /**< [ 47: 47] When set, PKI uses PKI_INST_HDR_S[TT] to compute WQE[TT].

                                                                 This field is not present unless PKI_INST_HDR_S[W] is set. */
        uint64_t sl                    : 8;  /**< [ 55: 48] The number of bytes in the PKI_INST_HDR_S and number of bytes to advance to find the next
                                                                 parse item.
                                                                 The following bullets describe the minimum PKI_INST_HDR_S size and, thus, the minimum SL
                                                                 values for a packet:
                                                                 * When PKI_INST_HDR_S [UTAG] = 1, the PKI_INST_HDR_S must be eight bytes, so SL must be
                                                                 eight or more.

                                                                 * When PKI_INST_HDR_S[W] = 1 and PKI_INST_HDR_S [UTAG] = 0, the PKI_INST_HDR_S must be
                                                                 four bytes or more, so SL must be four or more.

                                                                 * When PKI_INST_HDR_S[W] = 0, the PKI_INST_HDR_S may be as small as two bytes, so SL must
                                                                 be two or more.

                                                                 The sum of PKI_INST_HDR_S[SL] and other advances is subject to restrictions as described
                                                                 elsewhere. */
        uint64_t pm                    : 3;  /**< [ 58: 56] The mode used to parse the packet, as an encoded value. The legal values are:
                                                                   0x0 = Parse starting at LA (L2).
                                                                   0x1 = Parse starting at LB (Custom).
                                                                   0x2 = Parse starting at LC (L3).
                                                                   0x3 = Reserved; parse starting at LD not supported.
                                                                   0x4 = Reserved; parse starting at LE not supported.
                                                                   0x5 = Reserved; parse starting at LF not supported.
                                                                   0x6 = Parse starting at LG (Custom/Application).
                                                                   0x7 = Parse nothing, uninterpreted.
                                                                   _ else = reserved.

                                                                   If most or all parsing stages are skipped, then PKI will have little input in the
                                                                 scheduling information loaded into the WQE. PKI_INST_HDR_S[QPG], PKI_INST_HDR_S[TT], and
                                                                 PKI_INST_HDR_S[TAG] may be of use to specify this scheduling information. In this case
                                                                 PKI_STYLE()_WQ2 and PKI_STYLE()_WQ4 may be used to force the decoded information in WQE
                                                                 WORD 2 and WORD 4. */
        uint64_t reserved_59           : 1;
        uint64_t uqpg                  : 1;  /**< [ 60: 60] When set, PKI will use PKI_INST_HDR_S [QPG] to compute the QPG and indirectly WQE[AURA]
                                                                 and WQE[GRP].

                                                                 Must be 0 when PKI_INST_HDR_S[W] = 0. */
        uint64_t utag                  : 1;  /**< [ 61: 61] When set, PKI will use PKI_INST_HDR_S [TAG] to compute WQE[TAG].

                                                                 Must be 0 when PKI_INST_HDR_S[W] = 0. */
        uint64_t raw                   : 1;  /**< [ 62: 62] When set, WQE[RAW] will be set and statistics will accumulate in PKI_STAT()_STAT2 and the
                                                                 packet will never be dropped due to RED unless PKI_STYLE()_BUF[RAWDRP] is set. */
        uint64_t w                     : 1;  /**< [ 63: 63] Indicates wider PKI_INST_HDR_S.
                                                                 0 = The PKI_INST_HDR_S is two bytes.
                                                                 1 = The PKI_INST_HDR_S is four or eight bytes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_inst_hdr_s_s cn; */
};

/**
 * Structure pki_wqe_s
 *
 * PKI Work-Queue Entry Structure
 * This section is a description of each field in WORD0 - WORD4 of the work-queue entry.
 */
union bdk_pki_wqe_s
{
    uint64_t u[16];
    struct bdk_pki_wqe_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t node                  : 2;  /**< [ 63: 62] Refer to PKI Hardware Work-Queue Entry, word0<63:62>. Contains the node number on which
                                                                 the packet arrived.
                                                                 ... */
        uint64_t reserved_60_61        : 2;
        uint64_t aura                  : 12; /**< [ 59: 48] Refer to PKI Hardware Work-Queue Entry, word0<59:48>. Contains the aura including the FPA
                                                                 node computed for the packet. See Auras for an overview on auras and QPG for the aura
                                                                 calculation. Note the high two bits (WQE[AURA]<11:10>) correspond to an CCPI node number,
                                                                 from PKI_QPG_TBL(0..2047)[AURA_NODE], and indicate the node on which the packet was
                                                                 received by PKI.
                                                                 ... */
        uint64_t reserved_47           : 1;
        uint64_t apad                  : 3;  /**< [ 46: 44] Refer to PKI Hardware Work-Queue Entry, word0<46:44>. Indicates the number of bytes of
                                                                 alignment padding that were applied; refer to Packet Buffering. The pad is assigned by the
                                                                 following algorithm:
                                                                 ... */
        uint64_t chan                  : 12; /**< [ 43: 32] Refer to PKI Hardware Work-Queue Entry, word0<43:32>. The logical channel that the packet
                                                                 arrived from, enumerated by PKI_CHAN_E. WQE[CHAN] is relative to the local node; the
                                                                 node is in WQE[AURA]<11:10>.
                                                                 ... */
        uint64_t bufs                  : 8;  /**< [ 31: 24] Refer to PKI Hardware Work-Queue Entry, word0<31:24>. Contains the number of data buffers
                                                                 used to store the packet data, never zero. For example, the value will be 1 if
                                                                 PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=0 and all of the data fit into a combined buffer
                                                                 comprising the work queue entry and first data buffer. BUFS will also be one if
                                                                 PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=1 and only a single data buffer was created.
                                                                 ... */
        uint64_t style                 : 8;  /**< [ 23: 16] Refer to PKI Hardware Work-Queue Entry, word0<23:16>. Contains the 8-bit style computed
                                                                 for the packet. The low 6 bits also indicate the final style. WQE[STYLE] is
                                                                 relative to the local node; the node is in WQE[AURA]<11:10>.
                                                                 ... */
        uint64_t reserved_6_15         : 10;
        uint64_t pknd                  : 6;  /**< [  5:  0] Refer to PKI Hardware Work-Queue Entry, word0<5:0>. Contains the pkind computed by each
                                                                 interface for the packet. WQE[PKND] is relative to the local node; the
                                                                 node is in WQE[AURA]<11:10>.
                                                                 ... */
#else /* Word 0 - Little Endian */
        uint64_t pknd                  : 6;  /**< [  5:  0] Refer to PKI Hardware Work-Queue Entry, word0<5:0>. Contains the pkind computed by each
                                                                 interface for the packet. WQE[PKND] is relative to the local node; the
                                                                 node is in WQE[AURA]<11:10>.
                                                                 ... */
        uint64_t reserved_6_15         : 10;
        uint64_t style                 : 8;  /**< [ 23: 16] Refer to PKI Hardware Work-Queue Entry, word0<23:16>. Contains the 8-bit style computed
                                                                 for the packet. The low 6 bits also indicate the final style. WQE[STYLE] is
                                                                 relative to the local node; the node is in WQE[AURA]<11:10>.
                                                                 ... */
        uint64_t bufs                  : 8;  /**< [ 31: 24] Refer to PKI Hardware Work-Queue Entry, word0<31:24>. Contains the number of data buffers
                                                                 used to store the packet data, never zero. For example, the value will be 1 if
                                                                 PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=0 and all of the data fit into a combined buffer
                                                                 comprising the work queue entry and first data buffer. BUFS will also be one if
                                                                 PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=1 and only a single data buffer was created.
                                                                 ... */
        uint64_t chan                  : 12; /**< [ 43: 32] Refer to PKI Hardware Work-Queue Entry, word0<43:32>. The logical channel that the packet
                                                                 arrived from, enumerated by PKI_CHAN_E. WQE[CHAN] is relative to the local node; the
                                                                 node is in WQE[AURA]<11:10>.
                                                                 ... */
        uint64_t apad                  : 3;  /**< [ 46: 44] Refer to PKI Hardware Work-Queue Entry, word0<46:44>. Indicates the number of bytes of
                                                                 alignment padding that were applied; refer to Packet Buffering. The pad is assigned by the
                                                                 following algorithm:
                                                                 ... */
        uint64_t reserved_47           : 1;
        uint64_t aura                  : 12; /**< [ 59: 48] Refer to PKI Hardware Work-Queue Entry, word0<59:48>. Contains the aura including the FPA
                                                                 node computed for the packet. See Auras for an overview on auras and QPG for the aura
                                                                 calculation. Note the high two bits (WQE[AURA]<11:10>) correspond to an CCPI node number,
                                                                 from PKI_QPG_TBL(0..2047)[AURA_NODE], and indicate the node on which the packet was
                                                                 received by PKI.
                                                                 ... */
        uint64_t reserved_60_61        : 2;
        uint64_t node                  : 2;  /**< [ 63: 62] Refer to PKI Hardware Work-Queue Entry, word0<63:62>. Contains the node number on which
                                                                 the packet arrived.
                                                                 ... */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t len                   : 16; /**< [127:112] Refer to PKI Hardware Work-Queue Entry, word1<63:48>. The total number of bytes of packet
                                                                 data, from 1 to 65535. The total packet length includes all the packet bytes shown in the
                                                                 formats in PKI Hardware Work-Queue Entry, except that the CRC field is discarded when
                                                                 PKI_CL(0..1)_STYLE(0..63)_CFG[FCS_STRIP] = 1. (If PKI_CL(0..1)_STYLE(0..63)_CFG[FCS_STRIP]
                                                                 = 0, both the LEN value and the stored packet (both the work-queue-entry copy and the
                                                                 ordinary copy) include the CRC bytes. See Packet Input FCS for more details on CRC
                                                                 processing.) If WQE[OPCODE] = RE_MEMOUT, this field will have the total number of
                                                                 packet bytes written to memory but some of these bytes wil have been overwritten to the
                                                                 same buffer.
                                                                 ... */
        uint64_t reserved_108_111      : 4;
        uint64_t grp                   : 10; /**< [107: 98] Refer to PKI Hardware Work-Queue Entry, word1<43:34>. The SSO group number used for the
                                                                 packet's ADD_WORK, with the two high bits correspond to an CCPI node number, from
                                                                 PKI_QPG_TBL(0..2047)[GRP_OK, GRP_BAD]. GRP is calculated as part of the QPG calculations,
                                                                 see QPG. Note that the GRP may be optionally selected differently if the packet has an
                                                                 error (WQE[ERRLEV]!=NONE).
                                                                 ... */
        uint64_t tt                    : 2;  /**< [ 97: 96] Refer to PKI Hardware Work-Queue Entry, word1<33:32>. The initial tag type, (UNTAGGED,
                                                                 ORDERED, or ATOMIC), for the packet's SSO ADD_WORK, and enumerated by SSO_TT_E.
                                                                 ... */
        uint64_t tag                   : 32; /**< [ 95: 64] Refer to PKI Hardware Work-Queue Entry, word1<31:0>. The initial tag for the work-queue
                                                                 entry.
                                                                 ... */
#else /* Word 1 - Little Endian */
        uint64_t tag                   : 32; /**< [ 95: 64] Refer to PKI Hardware Work-Queue Entry, word1<31:0>. The initial tag for the work-queue
                                                                 entry.
                                                                 ... */
        uint64_t tt                    : 2;  /**< [ 97: 96] Refer to PKI Hardware Work-Queue Entry, word1<33:32>. The initial tag type, (UNTAGGED,
                                                                 ORDERED, or ATOMIC), for the packet's SSO ADD_WORK, and enumerated by SSO_TT_E.
                                                                 ... */
        uint64_t grp                   : 10; /**< [107: 98] Refer to PKI Hardware Work-Queue Entry, word1<43:34>. The SSO group number used for the
                                                                 packet's ADD_WORK, with the two high bits correspond to an CCPI node number, from
                                                                 PKI_QPG_TBL(0..2047)[GRP_OK, GRP_BAD]. GRP is calculated as part of the QPG calculations,
                                                                 see QPG. Note that the GRP may be optionally selected differently if the packet has an
                                                                 error (WQE[ERRLEV]!=NONE).
                                                                 ... */
        uint64_t reserved_108_111      : 4;
        uint64_t len                   : 16; /**< [127:112] Refer to PKI Hardware Work-Queue Entry, word1<63:48>. The total number of bytes of packet
                                                                 data, from 1 to 65535. The total packet length includes all the packet bytes shown in the
                                                                 formats in PKI Hardware Work-Queue Entry, except that the CRC field is discarded when
                                                                 PKI_CL(0..1)_STYLE(0..63)_CFG[FCS_STRIP] = 1. (If PKI_CL(0..1)_STYLE(0..63)_CFG[FCS_STRIP]
                                                                 = 0, both the LEN value and the stored packet (both the work-queue-entry copy and the
                                                                 ordinary copy) include the CRC bytes. See Packet Input FCS for more details on CRC
                                                                 processing.) If WQE[OPCODE] = RE_MEMOUT, this field will have the total number of
                                                                 packet bytes written to memory but some of these bytes wil have been overwritten to the
                                                                 same buffer.
                                                                 ... */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t sw                    : 1;  /**< [191:191] Refer to Work-Queue Entry Format; Word 2 Cases, word2<63>. Reserved for software use.
                                                                 Hardware always writes a zero to this bit.
                                                                 ... */
        uint64_t lgty                  : 5;  /**< [190:186] Refer to Work-Queue Entry Format; Word 2 Cases, word2<62:58>. Indicates the Layer G header
                                                                 type parsed. The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lfty                  : 5;  /**< [185:181] Refer to Work-Queue Entry Format; Word 2 Cases, word2<57:53>. Indicates the Layer F header
                                                                 type parsed. The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lety                  : 5;  /**< [180:176] Refer to Work-Queue Entry Format; Word 2 Cases, word2<52:48>. Indicates the Layer E header
                                                                 type parsed, often corresponding to Layer 4 (see Work-Queue Layer Typical Usage.) The
                                                                 values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t ldty                  : 5;  /**< [175:171] Refer to Work-Queue Entry Format; Word 2 Cases, word2<47:43>. Indicates the Layer D header
                                                                 typed parsed, typically corresponding to Inner IP (see Work-Queue Layer Typical Usage.)
                                                                 The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lcty                  : 5;  /**< [170:166] Refer to Work-Queue Entry Format; Word 2 Cases, word2<42:38>. Indicates the Layer C header
                                                                 type parsed, typically corresponding to Outer IP (see Work-Queue Layer Typical Usage.).
                                                                 The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lbty                  : 5;  /**< [165:161] Refer to Work-Queue Entry Format; Word 2 Cases, word2<37:33>. Indicates the user Layer B
                                                                 protocol type parsed. The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lae                   : 1;  /**< [160:160] Refer to Work-Queue Entry Format; Word 2 Cases, word2<32>. Indicates that Layer A Ethernet
                                                                 was parsed, typically used to indicate Layer 2 parsing.
                                                                 ... */
        uint64_t reserved_152_159      : 8;
        uint64_t vv                    : 1;  /**< [151:151] Refer to Work-Queue Entry Format; Word 2 Cases, word2<23>. Indicates that one or more VLAN
                                                                 fields were found in the L2 HDR for the packet. This bit asserts when in skip-to-L2 mode
                                                                 and the PCAM lookup indicated a VLAN flow (PKI_CL(0..1)_PCAM(0..1)_TERM(0..191)[TERM] =
                                                                 ETHTYPE0..3 or DSA matched with the corresponding
                                                                 PKI_CL(0..1)_PCAM(0..1)_ACTION(0..191)[SETTY] = VLAN.
                                                                 ... */
        uint64_t vs                    : 1;  /**< [150:150] Refer to Work-Queue Entry Format; Word 2 Cases, word2<22>. Indicates that multiple VLAN
                                                                 fields were found in the L2 HDR for the packet, with 'found' as described under WQE[VV].
                                                                 Also see the VS definition in the pseudo-code in Layer A (Pre-Ethertype) Parsing
                                                                 Algorithm.
                                                                 ... */
        uint64_t sh                    : 1;  /**< [149:149] Refer to Work-Queue Entry Format; Word 2 Cases, word2<21>. Reserved for statistics
                                                                 hardware.
                                                                 ... */
        uint64_t pf4                   : 1;  /**< [148:148] Refer to Work-Queue Entry Format; Word 2 Cases, word2<20>. Indicates that a PCAM entry set
                                                                 flag 4. See PCAM.
                                                                 ... */
        uint64_t pf3                   : 1;  /**< [147:147] Refer to Work-Queue Entry Format; Word 2 Cases, word2<19>. Indicates a PCAM entry set flag
                                                                 3. See PCAM.
                                                                 ... */
        uint64_t pf2                   : 1;  /**< [146:146] Refer to Work-Queue Entry Format; Word 2 Cases, word2<18>. Indicates that a PCAM entry set
                                                                 flag 2. See PCAM. Software may wish to use this bit to indicate RARP. See ARP/RARP Header.
                                                                 ... */
        uint64_t pf1                   : 1;  /**< [145:145] Refer to Work-Queue Entry Format; Word 2 Cases, word2<17>. Indicates that a PCAM entry set
                                                                 flag 1. See PCAM. Software may wish to use this bit to indicate ARP. See ARP/RARP Header.
                                                                 ... */
        uint64_t l3fr                  : 1;  /**< [144:144] Refer to Work-Queue Entry Format; Word 2 Cases, word2<16>. Set when the outer IP indicates
                                                                 a fragment.
                                                                 ... */
        uint64_t l3b                   : 1;  /**< [143:143] Refer to Work-Queue Entry Format; Word 2 Cases, word2<15>. WQE[L3B] is set when the outer
                                                                 IP4 indicates broadcast, i.e. the destination address is all ones. Broadcast is not
                                                                 defined for IPv6.
                                                                 ... */
        uint64_t l3m                   : 1;  /**< [142:142] Refer to Work-Queue Entry Format; Word 2 Cases, word2<14>. WQE[L3M] is set when the outer
                                                                 IP indicates multicast, i.e. the IPv4 destination address <31:28> = 0xE, or the IPv6 MSB
                                                                 of the 128-bit destination address = 0xFF.
                                                                 ... */
        uint64_t l2b                   : 1;  /**< [141:141] Refer to Work-Queue Entry Format; Word 2 Cases, word2<13>. Set when the packet's
                                                                 destination MAC address field in the L2 HDR is the broadcast address (i.e. all 1s).
                                                                 ... */
        uint64_t l2m                   : 1;  /**< [140:140] Refer to Work-Queue Entry Format; Word 2 Cases, word2<12>. Set when the packet's
                                                                 destination MAC address field in the L2 HDR is a multicast address (i.e. the LSB of the
                                                                 first byte of the destination MAC is set, and at least one of the remaining bits is a
                                                                 zero).
                                                                 ... */
        uint64_t raw                   : 1;  /**< [139:139] Refer to Work-Queue Entry Format; Word 2 Cases, word2<11>. Set when PKI_INST_HDR_S [RAW]
                                                                 was set.
                                                                 ... */
        uint64_t errlev                : 3;  /**< [138:136] Refer to Work-Queue Entry Format; Word 2 Cases, word2<10:8>. Normally zero, but when
                                                                 errors are detected contains the lowest protocol layer containing an error, and
                                                                 WQE[OPCODE] will indicate the precise error reason. Enumerated by PKI_ERRLEV_E.
                                                                 ... */
        uint64_t opcode                : 8;  /**< [135:128] Refer to Work-Queue Entry Format; Word 2 Cases, word2<7:0>. Normally zero, but contains a
                                                                 (non-zero) exception opcode enumerated by PKI_OPCODE_E when WQE[ERRLEV] is non-zero.
                                                                 ... */
#else /* Word 2 - Little Endian */
        uint64_t opcode                : 8;  /**< [135:128] Refer to Work-Queue Entry Format; Word 2 Cases, word2<7:0>. Normally zero, but contains a
                                                                 (non-zero) exception opcode enumerated by PKI_OPCODE_E when WQE[ERRLEV] is non-zero.
                                                                 ... */
        uint64_t errlev                : 3;  /**< [138:136] Refer to Work-Queue Entry Format; Word 2 Cases, word2<10:8>. Normally zero, but when
                                                                 errors are detected contains the lowest protocol layer containing an error, and
                                                                 WQE[OPCODE] will indicate the precise error reason. Enumerated by PKI_ERRLEV_E.
                                                                 ... */
        uint64_t raw                   : 1;  /**< [139:139] Refer to Work-Queue Entry Format; Word 2 Cases, word2<11>. Set when PKI_INST_HDR_S [RAW]
                                                                 was set.
                                                                 ... */
        uint64_t l2m                   : 1;  /**< [140:140] Refer to Work-Queue Entry Format; Word 2 Cases, word2<12>. Set when the packet's
                                                                 destination MAC address field in the L2 HDR is a multicast address (i.e. the LSB of the
                                                                 first byte of the destination MAC is set, and at least one of the remaining bits is a
                                                                 zero).
                                                                 ... */
        uint64_t l2b                   : 1;  /**< [141:141] Refer to Work-Queue Entry Format; Word 2 Cases, word2<13>. Set when the packet's
                                                                 destination MAC address field in the L2 HDR is the broadcast address (i.e. all 1s).
                                                                 ... */
        uint64_t l3m                   : 1;  /**< [142:142] Refer to Work-Queue Entry Format; Word 2 Cases, word2<14>. WQE[L3M] is set when the outer
                                                                 IP indicates multicast, i.e. the IPv4 destination address <31:28> = 0xE, or the IPv6 MSB
                                                                 of the 128-bit destination address = 0xFF.
                                                                 ... */
        uint64_t l3b                   : 1;  /**< [143:143] Refer to Work-Queue Entry Format; Word 2 Cases, word2<15>. WQE[L3B] is set when the outer
                                                                 IP4 indicates broadcast, i.e. the destination address is all ones. Broadcast is not
                                                                 defined for IPv6.
                                                                 ... */
        uint64_t l3fr                  : 1;  /**< [144:144] Refer to Work-Queue Entry Format; Word 2 Cases, word2<16>. Set when the outer IP indicates
                                                                 a fragment.
                                                                 ... */
        uint64_t pf1                   : 1;  /**< [145:145] Refer to Work-Queue Entry Format; Word 2 Cases, word2<17>. Indicates that a PCAM entry set
                                                                 flag 1. See PCAM. Software may wish to use this bit to indicate ARP. See ARP/RARP Header.
                                                                 ... */
        uint64_t pf2                   : 1;  /**< [146:146] Refer to Work-Queue Entry Format; Word 2 Cases, word2<18>. Indicates that a PCAM entry set
                                                                 flag 2. See PCAM. Software may wish to use this bit to indicate RARP. See ARP/RARP Header.
                                                                 ... */
        uint64_t pf3                   : 1;  /**< [147:147] Refer to Work-Queue Entry Format; Word 2 Cases, word2<19>. Indicates a PCAM entry set flag
                                                                 3. See PCAM.
                                                                 ... */
        uint64_t pf4                   : 1;  /**< [148:148] Refer to Work-Queue Entry Format; Word 2 Cases, word2<20>. Indicates that a PCAM entry set
                                                                 flag 4. See PCAM.
                                                                 ... */
        uint64_t sh                    : 1;  /**< [149:149] Refer to Work-Queue Entry Format; Word 2 Cases, word2<21>. Reserved for statistics
                                                                 hardware.
                                                                 ... */
        uint64_t vs                    : 1;  /**< [150:150] Refer to Work-Queue Entry Format; Word 2 Cases, word2<22>. Indicates that multiple VLAN
                                                                 fields were found in the L2 HDR for the packet, with 'found' as described under WQE[VV].
                                                                 Also see the VS definition in the pseudo-code in Layer A (Pre-Ethertype) Parsing
                                                                 Algorithm.
                                                                 ... */
        uint64_t vv                    : 1;  /**< [151:151] Refer to Work-Queue Entry Format; Word 2 Cases, word2<23>. Indicates that one or more VLAN
                                                                 fields were found in the L2 HDR for the packet. This bit asserts when in skip-to-L2 mode
                                                                 and the PCAM lookup indicated a VLAN flow (PKI_CL(0..1)_PCAM(0..1)_TERM(0..191)[TERM] =
                                                                 ETHTYPE0..3 or DSA matched with the corresponding
                                                                 PKI_CL(0..1)_PCAM(0..1)_ACTION(0..191)[SETTY] = VLAN.
                                                                 ... */
        uint64_t reserved_152_159      : 8;
        uint64_t lae                   : 1;  /**< [160:160] Refer to Work-Queue Entry Format; Word 2 Cases, word2<32>. Indicates that Layer A Ethernet
                                                                 was parsed, typically used to indicate Layer 2 parsing.
                                                                 ... */
        uint64_t lbty                  : 5;  /**< [165:161] Refer to Work-Queue Entry Format; Word 2 Cases, word2<37:33>. Indicates the user Layer B
                                                                 protocol type parsed. The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lcty                  : 5;  /**< [170:166] Refer to Work-Queue Entry Format; Word 2 Cases, word2<42:38>. Indicates the Layer C header
                                                                 type parsed, typically corresponding to Outer IP (see Work-Queue Layer Typical Usage.).
                                                                 The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t ldty                  : 5;  /**< [175:171] Refer to Work-Queue Entry Format; Word 2 Cases, word2<47:43>. Indicates the Layer D header
                                                                 typed parsed, typically corresponding to Inner IP (see Work-Queue Layer Typical Usage.)
                                                                 The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lety                  : 5;  /**< [180:176] Refer to Work-Queue Entry Format; Word 2 Cases, word2<52:48>. Indicates the Layer E header
                                                                 type parsed, often corresponding to Layer 4 (see Work-Queue Layer Typical Usage.) The
                                                                 values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lfty                  : 5;  /**< [185:181] Refer to Work-Queue Entry Format; Word 2 Cases, word2<57:53>. Indicates the Layer F header
                                                                 type parsed. The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t lgty                  : 5;  /**< [190:186] Refer to Work-Queue Entry Format; Word 2 Cases, word2<62:58>. Indicates the Layer G header
                                                                 type parsed. The values are enumerated by PKI_LTYPE_E.
                                                                 ... */
        uint64_t sw                    : 1;  /**< [191:191] Refer to Work-Queue Entry Format; Word 2 Cases, word2<63>. Reserved for software use.
                                                                 Hardware always writes a zero to this bit.
                                                                 ... */
#endif /* Word 2 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 3 - Big Endian */
        uint64_t reserved_241_255      : 15;
        uint64_t addr                  : 49; /**< [240:192] Refer to PKI Hardware Work-Queue Entry, word3<48:0> and Buffer Link Structure. Address of
                                                                 the first buffer pointer. When PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=0, ADDR points to the
                                                                 first byte of packet data saved into the work queue entry's buffer. When
                                                                 PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=1, ADDR points to a the first data buffer.
                                                                 ... */
#else /* Word 3 - Little Endian */
        uint64_t addr                  : 49; /**< [240:192] Refer to PKI Hardware Work-Queue Entry, word3<48:0> and Buffer Link Structure. Address of
                                                                 the first buffer pointer. When PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=0, ADDR points to the
                                                                 first byte of packet data saved into the work queue entry's buffer. When
                                                                 PKI_STYLE(0..63)_BUF[DIS_WQ_DAT]=1, ADDR points to a the first data buffer.
                                                                 ... */
        uint64_t reserved_241_255      : 15;
#endif /* Word 3 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 4 - Big Endian */
        uint64_t vlptr                 : 8;  /**< [319:312] Refer to Work-Queue Entry Format; Word 2 Cases, word4<63:56>. Contains a byte pointer to
                                                                 the first byte of the VLAN ID field for the first or second VLAN.
                                                                 ... */
        uint64_t lgptr                 : 8;  /**< [311:304] Refer to PKI Hardware Work-Queue Entry, word4<55:48>. Contains a byte pointer to the start
                                                                 of Layer G. This field is zero when WQE[LGTY] == NONE, and unpredictable when WQE[ERRLEV]
                                                                 <= LG.
                                                                 ... */
        uint64_t lfptr                 : 8;  /**< [303:296] Refer to PKI Hardware Work-Queue Entry, word4<47:40>. Contains a byte pointer to the start
                                                                 of Layer F. This field is zero when WQE[LFTY] == NONE, and unpredictable when WQE[ERRLEV]
                                                                 <= LF.
                                                                 ... */
        uint64_t leptr                 : 8;  /**< [295:288] Refer to PKI Hardware Work-Queue Entry, word4<39:32>. Contains a byte pointer to the start
                                                                 of Layer E relative to the start of the packet.
                                                                 ... */
        uint64_t ldptr                 : 8;  /**< [287:280] Refer to PKI Hardware Work-Queue Entry, word4<31:24>. Contains a byte pointer to the start
                                                                 of Layer D relative to the start of the packet.
                                                                 ... */
        uint64_t lcptr                 : 8;  /**< [279:272] Refer to PKI Hardware Work-Queue Entry, word4<23:16>. Contains a byte pointer to the start
                                                                 of Layer C relative to the start of the packet.
                                                                 ... */
        uint64_t lbptr                 : 8;  /**< [271:264] Refer to PKI Hardware Work-Queue Entry, word4<15:8>. Contains a byte pointer to the start
                                                                 of Layer B relative to the start of the packet.
                                                                 ... */
        uint64_t laptr                 : 8;  /**< [263:256] Refer to PKI Hardware Work-Queue Entry, word4<7:0>. Contains a byte pointer to the start
                                                                 of Layer A relative to the start of the packet.
                                                                 ... */
#else /* Word 4 - Little Endian */
        uint64_t laptr                 : 8;  /**< [263:256] Refer to PKI Hardware Work-Queue Entry, word4<7:0>. Contains a byte pointer to the start
                                                                 of Layer A relative to the start of the packet.
                                                                 ... */
        uint64_t lbptr                 : 8;  /**< [271:264] Refer to PKI Hardware Work-Queue Entry, word4<15:8>. Contains a byte pointer to the start
                                                                 of Layer B relative to the start of the packet.
                                                                 ... */
        uint64_t lcptr                 : 8;  /**< [279:272] Refer to PKI Hardware Work-Queue Entry, word4<23:16>. Contains a byte pointer to the start
                                                                 of Layer C relative to the start of the packet.
                                                                 ... */
        uint64_t ldptr                 : 8;  /**< [287:280] Refer to PKI Hardware Work-Queue Entry, word4<31:24>. Contains a byte pointer to the start
                                                                 of Layer D relative to the start of the packet.
                                                                 ... */
        uint64_t leptr                 : 8;  /**< [295:288] Refer to PKI Hardware Work-Queue Entry, word4<39:32>. Contains a byte pointer to the start
                                                                 of Layer E relative to the start of the packet.
                                                                 ... */
        uint64_t lfptr                 : 8;  /**< [303:296] Refer to PKI Hardware Work-Queue Entry, word4<47:40>. Contains a byte pointer to the start
                                                                 of Layer F. This field is zero when WQE[LFTY] == NONE, and unpredictable when WQE[ERRLEV]
                                                                 <= LF.
                                                                 ... */
        uint64_t lgptr                 : 8;  /**< [311:304] Refer to PKI Hardware Work-Queue Entry, word4<55:48>. Contains a byte pointer to the start
                                                                 of Layer G. This field is zero when WQE[LGTY] == NONE, and unpredictable when WQE[ERRLEV]
                                                                 <= LG.
                                                                 ... */
        uint64_t vlptr                 : 8;  /**< [319:312] Refer to Work-Queue Entry Format; Word 2 Cases, word4<63:56>. Contains a byte pointer to
                                                                 the first byte of the VLAN ID field for the first or second VLAN.
                                                                 ... */
#endif /* Word 4 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 5 - Big Endian */
        uint64_t size                  : 16; /**< [383:368] Refer to PKI Hardware Work-Queue Entry, word3<63:48> and Buffer Link Structure. Size of
                                                                 the first buffer pointer. When the packet data fits in a single buffer, SIZE represents
                                                                 the number of bytes in the buffer, and maybe larger than WQE[LEN].
                                                                 ... */
        uint64_t dwd                   : 1;  /**< [367:367] Refer to PKI Hardware Work-Queue Entry, word3<47>. WQE[ADDR] points to a different buffer
                                                                 than the buffer containing the WQE, from value of PKI_STYLE(0..63)_BUF[DIS_WQ_DAT].
                                                                 ... */
        uint64_t reserved_320_366      : 47;
#else /* Word 5 - Little Endian */
        uint64_t reserved_320_366      : 47;
        uint64_t dwd                   : 1;  /**< [367:367] Refer to PKI Hardware Work-Queue Entry, word3<47>. WQE[ADDR] points to a different buffer
                                                                 than the buffer containing the WQE, from value of PKI_STYLE(0..63)_BUF[DIS_WQ_DAT].
                                                                 ... */
        uint64_t size                  : 16; /**< [383:368] Refer to PKI Hardware Work-Queue Entry, word3<63:48> and Buffer Link Structure. Size of
                                                                 the first buffer pointer. When the packet data fits in a single buffer, SIZE represents
                                                                 the number of bytes in the buffer, and maybe larger than WQE[LEN].
                                                                 ... */
#endif /* Word 5 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 6 - Big Endian */
        uint64_t w6                    : 64; /**< [447:384] Refer to PKI Hardware Work-Queue Entry, word6<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 6 - Little Endian */
        uint64_t w6                    : 64; /**< [447:384] Refer to PKI Hardware Work-Queue Entry, word6<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 6 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 7 - Big Endian */
        uint64_t w7                    : 64; /**< [511:448] Refer to PKI Hardware Work-Queue Entry, word7<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 7 - Little Endian */
        uint64_t w7                    : 64; /**< [511:448] Refer to PKI Hardware Work-Queue Entry, word7<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 7 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 8 - Big Endian */
        uint64_t w8                    : 64; /**< [575:512] Refer to PKI Hardware Work-Queue Entry, word8<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 8 - Little Endian */
        uint64_t w8                    : 64; /**< [575:512] Refer to PKI Hardware Work-Queue Entry, word8<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 8 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 9 - Big Endian */
        uint64_t w9                    : 64; /**< [639:576] Refer to PKI Hardware Work-Queue Entry, word9<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 9 - Little Endian */
        uint64_t w9                    : 64; /**< [639:576] Refer to PKI Hardware Work-Queue Entry, word9<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 9 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 10 - Big Endian */
        uint64_t w10                   : 64; /**< [703:640] Refer to PKI Hardware Work-Queue Entry, word10<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 10 - Little Endian */
        uint64_t w10                   : 64; /**< [703:640] Refer to PKI Hardware Work-Queue Entry, word10<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 10 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 11 - Big Endian */
        uint64_t w11                   : 64; /**< [767:704] Refer to PKI Hardware Work-Queue Entry, word11<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 11 - Little Endian */
        uint64_t w11                   : 64; /**< [767:704] Refer to PKI Hardware Work-Queue Entry, word11<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 11 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 12 - Big Endian */
        uint64_t w12                   : 64; /**< [831:768] Refer to PKI Hardware Work-Queue Entry, word12<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 12 - Little Endian */
        uint64_t w12                   : 64; /**< [831:768] Refer to PKI Hardware Work-Queue Entry, word12<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 12 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 13 - Big Endian */
        uint64_t w13                   : 64; /**< [895:832] Refer to PKI Hardware Work-Queue Entry, word13<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 13 - Little Endian */
        uint64_t w13                   : 64; /**< [895:832] Refer to PKI Hardware Work-Queue Entry, word13<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 13 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 14 - Big Endian */
        uint64_t w14                   : 64; /**< [959:896] Refer to PKI Hardware Work-Queue Entry, word14<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 14 - Little Endian */
        uint64_t w14                   : 64; /**< [959:896] Refer to PKI Hardware Work-Queue Entry, word14<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 14 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 15 - Big Endian */
        uint64_t w15                   : 64; /**< [1023:960] Refer to PKI Hardware Work-Queue Entry, word15<63:0>. Packet data may use this word.
                                                                 ... */
#else /* Word 15 - Little Endian */
        uint64_t w15                   : 64; /**< [1023:960] Refer to PKI Hardware Work-Queue Entry, word15<63:0>. Packet data may use this word.
                                                                 ... */
#endif /* Word 15 - End */
    } s;
    /* struct bdk_pki_wqe_s_s cn; */
};

/**
 * Register (NCB) pki_active0
 *
 * PKI Active 0 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_active0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pfe_active            : 1;  /**< [  0:  0](RO/H) PFE active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
#else /* Word 0 - Little Endian */
        uint64_t pfe_active            : 1;  /**< [  0:  0](RO/H) PFE active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_active0_s cn; */
} bdk_pki_active0_t;

#define BDK_PKI_ACTIVE0 BDK_PKI_ACTIVE0_FUNC()
static inline uint64_t BDK_PKI_ACTIVE0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ACTIVE0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000220ll;
    __bdk_csr_fatal("PKI_ACTIVE0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ACTIVE0 bdk_pki_active0_t
#define bustype_BDK_PKI_ACTIVE0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ACTIVE0 "PKI_ACTIVE0"
#define device_bar_BDK_PKI_ACTIVE0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ACTIVE0 0
#define arguments_BDK_PKI_ACTIVE0 -1,-1,-1,-1

/**
 * Register (NCB) pki_active1
 *
 * PKI Active 1 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_active1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t fpc_active            : 1;  /**< [  3:  3](RO/H) PBE FPC and FPA bus active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t iobp_active           : 1;  /**< [  2:  2](RO/H) PBE PMW and IOBP bus active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t sws_active            : 1;  /**< [  1:  1](RO/H) PBE SWS active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t pbtag_active          : 1;  /**< [  0:  0](RO/H) PBE pbtags active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
#else /* Word 0 - Little Endian */
        uint64_t pbtag_active          : 1;  /**< [  0:  0](RO/H) PBE pbtags active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t sws_active            : 1;  /**< [  1:  1](RO/H) PBE SWS active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t iobp_active           : 1;  /**< [  2:  2](RO/H) PBE PMW and IOBP bus active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t fpc_active            : 1;  /**< [  3:  3](RO/H) PBE FPC and FPA bus active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_active1_s cn; */
} bdk_pki_active1_t;

#define BDK_PKI_ACTIVE1 BDK_PKI_ACTIVE1_FUNC()
static inline uint64_t BDK_PKI_ACTIVE1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ACTIVE1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000230ll;
    __bdk_csr_fatal("PKI_ACTIVE1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ACTIVE1 bdk_pki_active1_t
#define bustype_BDK_PKI_ACTIVE1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ACTIVE1 "PKI_ACTIVE1"
#define device_bar_BDK_PKI_ACTIVE1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ACTIVE1 0
#define arguments_BDK_PKI_ACTIVE1 -1,-1,-1,-1

/**
 * Register (NCB) pki_active2
 *
 * PKI Active 2 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_active2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t pix_active            : 5;  /**< [  4:  0](RO/H) PIX control and ICG active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
#else /* Word 0 - Little Endian */
        uint64_t pix_active            : 5;  /**< [  4:  0](RO/H) PIX control and ICG active. For internal use; software should use PKI_SFT_RST[ACTIVE]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_active2_s cn; */
} bdk_pki_active2_t;

#define BDK_PKI_ACTIVE2 BDK_PKI_ACTIVE2_FUNC()
static inline uint64_t BDK_PKI_ACTIVE2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ACTIVE2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000240ll;
    __bdk_csr_fatal("PKI_ACTIVE2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ACTIVE2 bdk_pki_active2_t
#define bustype_BDK_PKI_ACTIVE2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ACTIVE2 "PKI_ACTIVE2"
#define device_bar_BDK_PKI_ACTIVE2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ACTIVE2 0
#define arguments_BDK_PKI_ACTIVE2 -1,-1,-1,-1

/**
 * Register (NCB) pki_aura#_cfg
 *
 * PKI Aura Configuration Register
 * This register configures aura backpressure, etc.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_aurax_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t pkt_add               : 2;  /**< [ 31: 30](R/W) Specifies what to add to FPA_AURA()_CNT when PKI enqueues a packet:
                                                                 0 = zero.
                                                                 1 = one.
                                                                 2 = The number of FPA buffers allocated; i.e. if PKI_STYLE()_BUF[DIS_WQ_DAT] is set,
                                                                 WQE[BUFS]+1, else WQE[BUFS].
                                                                 3 = WQE[LEN] (i.e. the packet length). */
        uint64_t reserved_19_29        : 11;
        uint64_t ena_red               : 1;  /**< [ 18: 18](R/W) Enable RED drop between PASS and DROP levels. See also
                                                                 FPA_AURA()_POOL_LEVELS[RED_ENA] and FPA_AURA()_CNT_LEVELS[RED_ENA]. */
        uint64_t ena_drop              : 1;  /**< [ 17: 17](R/W) Enable tail drop when maximum DROP level exceeded. See also
                                                                 FPA_AURA()_POOL_LEVELS[DROP] and FPA_AURA()_CNT_LEVELS[DROP]. */
        uint64_t ena_bp                : 1;  /**< [ 16: 16](R/W) Enable asserting backpressure on BPID when maximum DROP level exceeded. See also
                                                                 FPA_AURA()_POOL_LEVELS[RED_ENA] and FPA_AURA()_CNT_LEVELS[RED_ENA]. */
        uint64_t reserved_10_15        : 6;
        uint64_t bpid                  : 10; /**< [  9:  0](R/W) Bpid to assert backpressure on. Values must be 0 to 511. */
#else /* Word 0 - Little Endian */
        uint64_t bpid                  : 10; /**< [  9:  0](R/W) Bpid to assert backpressure on. Values must be 0 to 511. */
        uint64_t reserved_10_15        : 6;
        uint64_t ena_bp                : 1;  /**< [ 16: 16](R/W) Enable asserting backpressure on BPID when maximum DROP level exceeded. See also
                                                                 FPA_AURA()_POOL_LEVELS[RED_ENA] and FPA_AURA()_CNT_LEVELS[RED_ENA]. */
        uint64_t ena_drop              : 1;  /**< [ 17: 17](R/W) Enable tail drop when maximum DROP level exceeded. See also
                                                                 FPA_AURA()_POOL_LEVELS[DROP] and FPA_AURA()_CNT_LEVELS[DROP]. */
        uint64_t ena_red               : 1;  /**< [ 18: 18](R/W) Enable RED drop between PASS and DROP levels. See also
                                                                 FPA_AURA()_POOL_LEVELS[RED_ENA] and FPA_AURA()_CNT_LEVELS[RED_ENA]. */
        uint64_t reserved_19_29        : 11;
        uint64_t pkt_add               : 2;  /**< [ 31: 30](R/W) Specifies what to add to FPA_AURA()_CNT when PKI enqueues a packet:
                                                                 0 = zero.
                                                                 1 = one.
                                                                 2 = The number of FPA buffers allocated; i.e. if PKI_STYLE()_BUF[DIS_WQ_DAT] is set,
                                                                 WQE[BUFS]+1, else WQE[BUFS].
                                                                 3 = WQE[LEN] (i.e. the packet length). */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_aurax_cfg_s cn; */
} bdk_pki_aurax_cfg_t;

static inline uint64_t BDK_PKI_AURAX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_AURAX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=511))
        return 0x86c000900000ll + 8ll * ((a) & 0x1ff);
    __bdk_csr_fatal("PKI_AURAX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_AURAX_CFG(a) bdk_pki_aurax_cfg_t
#define bustype_BDK_PKI_AURAX_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_AURAX_CFG(a) "PKI_AURAX_CFG"
#define device_bar_BDK_PKI_AURAX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_AURAX_CFG(a) (a)
#define arguments_BDK_PKI_AURAX_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_bist_status0
 *
 * PKI BIST Results 0 Register
 * BIST status register.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bist_status0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t bist                  : 31; /**< [ 30:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails BIST. INTERNAL: This
                                                                 register collects status for PKI_PFE.
                                                                 <30> = INB_ERRS.
                                                                 <29> = INB OCTS.
                                                                 <28> = INB PKTS.
                                                                 <27> = LD FIF.
                                                                 <26> = PBE STATE.
                                                                 <25> = WADR STATE.
                                                                 <24> = NXT PTAG.
                                                                 <23> = CUR PTAG.
                                                                 <22> = X2P FIF.
                                                                 <21> = DROP FIF.
                                                                 <20> = NXT BLK.
                                                                 <19..16> = KMEM.
                                                                 <15..0> = ASM BUFF. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 31; /**< [ 30:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails BIST. INTERNAL: This
                                                                 register collects status for PKI_PFE.
                                                                 <30> = INB_ERRS.
                                                                 <29> = INB OCTS.
                                                                 <28> = INB PKTS.
                                                                 <27> = LD FIF.
                                                                 <26> = PBE STATE.
                                                                 <25> = WADR STATE.
                                                                 <24> = NXT PTAG.
                                                                 <23> = CUR PTAG.
                                                                 <22> = X2P FIF.
                                                                 <21> = DROP FIF.
                                                                 <20> = NXT BLK.
                                                                 <19..16> = KMEM.
                                                                 <15..0> = ASM BUFF. */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bist_status0_s cn; */
} bdk_pki_bist_status0_t;

#define BDK_PKI_BIST_STATUS0 BDK_PKI_BIST_STATUS0_FUNC()
static inline uint64_t BDK_PKI_BIST_STATUS0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BIST_STATUS0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000080ll;
    __bdk_csr_fatal("PKI_BIST_STATUS0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BIST_STATUS0 bdk_pki_bist_status0_t
#define bustype_BDK_PKI_BIST_STATUS0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BIST_STATUS0 "PKI_BIST_STATUS0"
#define device_bar_BDK_PKI_BIST_STATUS0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BIST_STATUS0 0
#define arguments_BDK_PKI_BIST_STATUS0 -1,-1,-1,-1

/**
 * Register (NCB) pki_bist_status1
 *
 * PKI BIST Results 1 Register
 * BIST status register.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bist_status1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t bist                  : 26; /**< [ 25:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails BIST. INTERNAL: This
                                                                 register collects status for PKI_PBE.
                                                                 <25> = DSTATS_MEM0.
                                                                 <24> = DSTATS_MEM1.
                                                                 <23> = DSTATS_MEM2.
                                                                 <22> = DSTATS_MEM3.
                                                                 <21> = DSTATS_MEM4.
                                                                 <20> = STATS_MEM0.
                                                                 <19> = STATS_MEM1.
                                                                 <18> = STATS_MEM2.
                                                                 <17> = STATS_MEM3.
                                                                 <16> = SWS.
                                                                 <15> = WQEOUT.
                                                                 <14> = DOA.
                                                                 <13> = BPID.
                                                                 <12 =10> = Reserved.
                                                                 <9> = PLC.
                                                                 <8> = PKTWQ.
                                                                 <7 =6> = Reserved.
                                                                 <5> = TAG.
                                                                 <4> = AURA.
                                                                 <3> = CHAN.
                                                                 <2> = PBTAG.
                                                                 <1> = STYLEWQ.
                                                                 <0> = QPG. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 26; /**< [ 25:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails BIST. INTERNAL: This
                                                                 register collects status for PKI_PBE.
                                                                 <25> = DSTATS_MEM0.
                                                                 <24> = DSTATS_MEM1.
                                                                 <23> = DSTATS_MEM2.
                                                                 <22> = DSTATS_MEM3.
                                                                 <21> = DSTATS_MEM4.
                                                                 <20> = STATS_MEM0.
                                                                 <19> = STATS_MEM1.
                                                                 <18> = STATS_MEM2.
                                                                 <17> = STATS_MEM3.
                                                                 <16> = SWS.
                                                                 <15> = WQEOUT.
                                                                 <14> = DOA.
                                                                 <13> = BPID.
                                                                 <12 =10> = Reserved.
                                                                 <9> = PLC.
                                                                 <8> = PKTWQ.
                                                                 <7 =6> = Reserved.
                                                                 <5> = TAG.
                                                                 <4> = AURA.
                                                                 <3> = CHAN.
                                                                 <2> = PBTAG.
                                                                 <1> = STYLEWQ.
                                                                 <0> = QPG. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bist_status1_s cn; */
} bdk_pki_bist_status1_t;

#define BDK_PKI_BIST_STATUS1 BDK_PKI_BIST_STATUS1_FUNC()
static inline uint64_t BDK_PKI_BIST_STATUS1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BIST_STATUS1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000088ll;
    __bdk_csr_fatal("PKI_BIST_STATUS1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BIST_STATUS1 bdk_pki_bist_status1_t
#define bustype_BDK_PKI_BIST_STATUS1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BIST_STATUS1 "PKI_BIST_STATUS1"
#define device_bar_BDK_PKI_BIST_STATUS1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BIST_STATUS1 0
#define arguments_BDK_PKI_BIST_STATUS1 -1,-1,-1,-1

/**
 * Register (NCB) pki_bist_status2
 *
 * PKI BIST Results 2 Register
 * BIST status register.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bist_status2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t bist                  : 25; /**< [ 24:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails BIST. INTERNAL: This
                                                                 register collects status for PKI_PIX (verif/vkits/pki/pki_mem_info_table.sv).
                                                                 24     = IMEM.
                                                                 23..20 = Reserved.
                                                                 19     = IPEC1 / IPEs 10 .. 19 (RegFile + DMEM).
                                                                 18     = IPEC1 / IPEs  0 ..  9 (RegFile + DMEM).
                                                                 17     = IPEC0 / IPEs 10 .. 19 (RegFile + DMEM).
                                                                 16     = IPEC0 / IPEs  0 ..  9 (RegFile + DMEM).
                                                                 15..13 = Reserved.
                                                                 14..12 = IPEC SMEM.
                                                                 11..10 = Reserved.
                                                                 9..8   = IPEC PCAM ECC.
                                                                 7..6   = Reserved.
                                                                 5..4   = IPEC PCAM RES.
                                                                 3..2   = Reserved.
                                                                 1..0   = IPEC PCAM CAM. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 25; /**< [ 24:  0](RO/H) BIST results. Hardware sets a bit in BIST for memory that fails BIST. INTERNAL: This
                                                                 register collects status for PKI_PIX (verif/vkits/pki/pki_mem_info_table.sv).
                                                                 24     = IMEM.
                                                                 23..20 = Reserved.
                                                                 19     = IPEC1 / IPEs 10 .. 19 (RegFile + DMEM).
                                                                 18     = IPEC1 / IPEs  0 ..  9 (RegFile + DMEM).
                                                                 17     = IPEC0 / IPEs 10 .. 19 (RegFile + DMEM).
                                                                 16     = IPEC0 / IPEs  0 ..  9 (RegFile + DMEM).
                                                                 15..13 = Reserved.
                                                                 14..12 = IPEC SMEM.
                                                                 11..10 = Reserved.
                                                                 9..8   = IPEC PCAM ECC.
                                                                 7..6   = Reserved.
                                                                 5..4   = IPEC PCAM RES.
                                                                 3..2   = Reserved.
                                                                 1..0   = IPEC PCAM CAM. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bist_status2_s cn; */
} bdk_pki_bist_status2_t;

#define BDK_PKI_BIST_STATUS2 BDK_PKI_BIST_STATUS2_FUNC()
static inline uint64_t BDK_PKI_BIST_STATUS2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BIST_STATUS2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000090ll;
    __bdk_csr_fatal("PKI_BIST_STATUS2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BIST_STATUS2 bdk_pki_bist_status2_t
#define bustype_BDK_PKI_BIST_STATUS2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BIST_STATUS2 "PKI_BIST_STATUS2"
#define device_bar_BDK_PKI_BIST_STATUS2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BIST_STATUS2 0
#define arguments_BDK_PKI_BIST_STATUS2 -1,-1,-1,-1

/**
 * Register (NCB) pki_bp_test0
 *
 * INTERNAL: PKI Backpressure Test Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bp_test0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bp_test0_s cn; */
} bdk_pki_bp_test0_t;

#define BDK_PKI_BP_TEST0 BDK_PKI_BP_TEST0_FUNC()
static inline uint64_t BDK_PKI_BP_TEST0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BP_TEST0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000250ll;
    __bdk_csr_fatal("PKI_BP_TEST0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BP_TEST0 bdk_pki_bp_test0_t
#define bustype_BDK_PKI_BP_TEST0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BP_TEST0 "PKI_BP_TEST0"
#define device_bar_BDK_PKI_BP_TEST0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BP_TEST0 0
#define arguments_BDK_PKI_BP_TEST0 -1,-1,-1,-1

/**
 * Register (NCB) pki_bp_test1
 *
 * INTERNAL: PKI Backpressure Test Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bp_test1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bp_test1_s cn; */
} bdk_pki_bp_test1_t;

#define BDK_PKI_BP_TEST1 BDK_PKI_BP_TEST1_FUNC()
static inline uint64_t BDK_PKI_BP_TEST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BP_TEST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000260ll;
    __bdk_csr_fatal("PKI_BP_TEST1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BP_TEST1 bdk_pki_bp_test1_t
#define bustype_BDK_PKI_BP_TEST1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BP_TEST1 "PKI_BP_TEST1"
#define device_bar_BDK_PKI_BP_TEST1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BP_TEST1 0
#define arguments_BDK_PKI_BP_TEST1 -1,-1,-1,-1

/**
 * Register (NCB) pki_bp_test2
 *
 * INTERNAL: PKI Backpressure Test Register 2
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bp_test2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bp_test2_s cn; */
} bdk_pki_bp_test2_t;

#define BDK_PKI_BP_TEST2 BDK_PKI_BP_TEST2_FUNC()
static inline uint64_t BDK_PKI_BP_TEST2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BP_TEST2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000270ll;
    __bdk_csr_fatal("PKI_BP_TEST2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BP_TEST2 bdk_pki_bp_test2_t
#define bustype_BDK_PKI_BP_TEST2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BP_TEST2 "PKI_BP_TEST2"
#define device_bar_BDK_PKI_BP_TEST2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BP_TEST2 0
#define arguments_BDK_PKI_BP_TEST2 -1,-1,-1,-1

/**
 * Register (NCB) pki_bpid#_state
 *
 * PKI Bpid State Register
 * This register shows the current bpid state for diagnostics.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_bpidx_state_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t xoff                  : 1;  /**< [  0:  0](RO/H) The corresponding bpid is being backpressured. */
#else /* Word 0 - Little Endian */
        uint64_t xoff                  : 1;  /**< [  0:  0](RO/H) The corresponding bpid is being backpressured. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_bpidx_state_s cn; */
} bdk_pki_bpidx_state_t;

static inline uint64_t BDK_PKI_BPIDX_STATE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BPIDX_STATE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=511))
        return 0x86c000b00000ll + 8ll * ((a) & 0x1ff);
    __bdk_csr_fatal("PKI_BPIDX_STATE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_BPIDX_STATE(a) bdk_pki_bpidx_state_t
#define bustype_BDK_PKI_BPIDX_STATE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BPIDX_STATE(a) "PKI_BPIDX_STATE"
#define device_bar_BDK_PKI_BPIDX_STATE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BPIDX_STATE(a) (a)
#define arguments_BDK_PKI_BPIDX_STATE(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_buf_ctl
 *
 * PKI Buffer Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_buf_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t fpa_wait              : 1;  /**< [ 10: 10](R/W) Policy when FPA runs out of buffers:
                                                                 0 = Drop the remainder of the packet requesting the buffer, and set WQE[OPCODE] to
                                                                 RE_MEMOUT.
                                                                 1 = Wait until buffers become available, only dropping packets if buffering ahead of PKI
                                                                 fills. This may lead to head-of-line blocking of packets on other Auras. */
        uint64_t fpa_cac_dis           : 1;  /**< [  9:  9](R/W) Reserved. */
        uint64_t reserved_6_8          : 3;
        uint64_t pkt_off               : 1;  /**< [  5:  5](R/W) Packet buffer off. When this bit is set to 1, the PKI does not buffer the received packet
                                                                 data; when it is clear to 0, the PKI works normally, buffering the received packet data. */
        uint64_t reserved_3_4          : 2;
        uint64_t pbp_en                : 1;  /**< [  2:  2](R/W) Bpid enable. When set, enables the sending of bpid level backpressure to the input
                                                                 interface.
                                                                 The application should not de-assert this bit after asserting it. The receivers of this
                                                                 bit may have been put into backpressure mode and can only be released by PKI informing
                                                                 them that the backpressure has been released.
                                                                 INTERNAL: Must be one for PKI HW to assert any output backpressure wires. */
        uint64_t reserved_1            : 1;
        uint64_t pki_en                : 1;  /**< [  0:  0](R/W) PKI enable. When set to 1, enables the operation of the PKI. When clear to 0, the PKI
                                                                 asserts backpressure on all ports. INTERNAL: Suppresses grants to X2P, not BPID
                                                                 backpressure. */
#else /* Word 0 - Little Endian */
        uint64_t pki_en                : 1;  /**< [  0:  0](R/W) PKI enable. When set to 1, enables the operation of the PKI. When clear to 0, the PKI
                                                                 asserts backpressure on all ports. INTERNAL: Suppresses grants to X2P, not BPID
                                                                 backpressure. */
        uint64_t reserved_1            : 1;
        uint64_t pbp_en                : 1;  /**< [  2:  2](R/W) Bpid enable. When set, enables the sending of bpid level backpressure to the input
                                                                 interface.
                                                                 The application should not de-assert this bit after asserting it. The receivers of this
                                                                 bit may have been put into backpressure mode and can only be released by PKI informing
                                                                 them that the backpressure has been released.
                                                                 INTERNAL: Must be one for PKI HW to assert any output backpressure wires. */
        uint64_t reserved_3_4          : 2;
        uint64_t pkt_off               : 1;  /**< [  5:  5](R/W) Packet buffer off. When this bit is set to 1, the PKI does not buffer the received packet
                                                                 data; when it is clear to 0, the PKI works normally, buffering the received packet data. */
        uint64_t reserved_6_8          : 3;
        uint64_t fpa_cac_dis           : 1;  /**< [  9:  9](R/W) Reserved. */
        uint64_t fpa_wait              : 1;  /**< [ 10: 10](R/W) Policy when FPA runs out of buffers:
                                                                 0 = Drop the remainder of the packet requesting the buffer, and set WQE[OPCODE] to
                                                                 RE_MEMOUT.
                                                                 1 = Wait until buffers become available, only dropping packets if buffering ahead of PKI
                                                                 fills. This may lead to head-of-line blocking of packets on other Auras. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_buf_ctl_s cn; */
} bdk_pki_buf_ctl_t;

#define BDK_PKI_BUF_CTL BDK_PKI_BUF_CTL_FUNC()
static inline uint64_t BDK_PKI_BUF_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_BUF_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000100ll;
    __bdk_csr_fatal("PKI_BUF_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_BUF_CTL bdk_pki_buf_ctl_t
#define bustype_BDK_PKI_BUF_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_BUF_CTL "PKI_BUF_CTL"
#define device_bar_BDK_PKI_BUF_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_BUF_CTL 0
#define arguments_BDK_PKI_BUF_CTL -1,-1,-1,-1

/**
 * Register (NCB) pki_chan#_cfg
 *
 * PKI Channel Configuration Register
 * This register configures each channel.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_chanx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t imp                   : 1;  /**< [ 16: 16](RO/H) Implemented. This register is sparse (only indexes with values in PKI_CHAN_E are
                                                                 implemented).
                                                                 0 = this index is read only.
                                                                 1 = this index is read-write.
                                                                 INTERNAL: Write to a non-implemented channel is ignored but returns write commit. Reading

                                                                 non-implemented channel returns all zero data. */
        uint64_t reserved_10_15        : 6;
        uint64_t bpid                  : 10; /**< [  9:  0](R/W) Bpid to receive backpressure from. Value must be 0 to 511. */
#else /* Word 0 - Little Endian */
        uint64_t bpid                  : 10; /**< [  9:  0](R/W) Bpid to receive backpressure from. Value must be 0 to 511. */
        uint64_t reserved_10_15        : 6;
        uint64_t imp                   : 1;  /**< [ 16: 16](RO/H) Implemented. This register is sparse (only indexes with values in PKI_CHAN_E are
                                                                 implemented).
                                                                 0 = this index is read only.
                                                                 1 = this index is read-write.
                                                                 INTERNAL: Write to a non-implemented channel is ignored but returns write commit. Reading

                                                                 non-implemented channel returns all zero data. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_chanx_cfg_s cn; */
} bdk_pki_chanx_cfg_t;

static inline uint64_t BDK_PKI_CHANX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CHANX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=4095))
        return 0x86c000a00000ll + 8ll * ((a) & 0xfff);
    __bdk_csr_fatal("PKI_CHANX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CHANX_CFG(a) bdk_pki_chanx_cfg_t
#define bustype_BDK_PKI_CHANX_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CHANX_CFG(a) "PKI_CHANX_CFG"
#define device_bar_BDK_PKI_CHANX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CHANX_CFG(a) (a)
#define arguments_BDK_PKI_CHANX_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_ecc_ctl
 *
 * PKI Cluster ECC/Parity Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_ecc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pcam_en               : 1;  /**< [ 63: 63](R/W) PCAM ECC checking enable. PCAM_EN must be clear when reading or writing the
                                                                 PKI_PCAM_RESULT registers. INTERNAL: This enables the PCAM scrubber. */
        uint64_t reserved_57_62        : 6;
        uint64_t spare                 : 1;  /**< [ 56: 56](R/W) Spare bit. */
        uint64_t reserved_24_55        : 32;
        uint64_t pcam1_flip            : 2;  /**< [ 23: 22](R/W) PCAM1 flip syndrome bits on write. */
        uint64_t pcam0_flip            : 2;  /**< [ 21: 20](R/W) PCAM  flip syndrome bits on write. */
        uint64_t smem_flip             : 2;  /**< [ 19: 18](R/W) SMEM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the KMEM ram to
                                                                 test single-bit or double-bit error handling. */
        uint64_t dmem_flip             : 1;  /**< [ 17: 17](R/W) DMEM flip parity. */
        uint64_t rf_flip               : 1;  /**< [ 16: 16](R/W) RF flip parity. */
        uint64_t reserved_5_15         : 11;
        uint64_t pcam1_cdis            : 1;  /**< [  4:  4](R/W) PCAM1 ECC correction disable. */
        uint64_t pcam0_cdis            : 1;  /**< [  3:  3](R/W) PCAM0 ECC correction disable. */
        uint64_t smem_cdis             : 1;  /**< [  2:  2](R/W) SMEM ECC correction disable. */
        uint64_t dmem_cdis             : 1;  /**< [  1:  1](R/W) DMEM parity poisoning disable. */
        uint64_t rf_cdis               : 1;  /**< [  0:  0](R/W) RF RAM parity poisoning disable. */
#else /* Word 0 - Little Endian */
        uint64_t rf_cdis               : 1;  /**< [  0:  0](R/W) RF RAM parity poisoning disable. */
        uint64_t dmem_cdis             : 1;  /**< [  1:  1](R/W) DMEM parity poisoning disable. */
        uint64_t smem_cdis             : 1;  /**< [  2:  2](R/W) SMEM ECC correction disable. */
        uint64_t pcam0_cdis            : 1;  /**< [  3:  3](R/W) PCAM0 ECC correction disable. */
        uint64_t pcam1_cdis            : 1;  /**< [  4:  4](R/W) PCAM1 ECC correction disable. */
        uint64_t reserved_5_15         : 11;
        uint64_t rf_flip               : 1;  /**< [ 16: 16](R/W) RF flip parity. */
        uint64_t dmem_flip             : 1;  /**< [ 17: 17](R/W) DMEM flip parity. */
        uint64_t smem_flip             : 2;  /**< [ 19: 18](R/W) SMEM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the KMEM ram to
                                                                 test single-bit or double-bit error handling. */
        uint64_t pcam0_flip            : 2;  /**< [ 21: 20](R/W) PCAM  flip syndrome bits on write. */
        uint64_t pcam1_flip            : 2;  /**< [ 23: 22](R/W) PCAM1 flip syndrome bits on write. */
        uint64_t reserved_24_55        : 32;
        uint64_t spare                 : 1;  /**< [ 56: 56](R/W) Spare bit. */
        uint64_t reserved_57_62        : 6;
        uint64_t pcam_en               : 1;  /**< [ 63: 63](R/W) PCAM ECC checking enable. PCAM_EN must be clear when reading or writing the
                                                                 PKI_PCAM_RESULT registers. INTERNAL: This enables the PCAM scrubber. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_ecc_ctl_s cn; */
} bdk_pki_clx_ecc_ctl_t;

static inline uint64_t BDK_PKI_CLX_ECC_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_ECC_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c320ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_ECC_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_ECC_CTL(a) bdk_pki_clx_ecc_ctl_t
#define bustype_BDK_PKI_CLX_ECC_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_ECC_CTL(a) "PKI_CLX_ECC_CTL"
#define device_bar_BDK_PKI_CLX_ECC_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_ECC_CTL(a) (a)
#define arguments_BDK_PKI_CLX_ECC_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_ecc_int
 *
 * PKI Cluster ECC/Parity Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_ecc_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1C/H) PCAM1 ECC double bit error. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1C/H) PCAM1 ECC single bit error. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1C/H) PCAM0 ECC double bit error. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1C/H) PCAM0 ECC single bit error. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1C/H) SMEM ECC double bit error. If
                                                                 SMEM_DBE is thrown, software may scrub the error by reloading PKI_CL()_SMEM(). */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1C/H) SMEM ECC single bit error. If
                                                                 SMEM_SBE is thrown, software may scrub the error by reloading PKI_CL()_SMEM(). */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1C/H) DMEM parity error. */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1C/H) RF RAM parity error. */
#else /* Word 0 - Little Endian */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1C/H) RF RAM parity error. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1C/H) DMEM parity error. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1C/H) SMEM ECC single bit error. If
                                                                 SMEM_SBE is thrown, software may scrub the error by reloading PKI_CL()_SMEM(). */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1C/H) SMEM ECC double bit error. If
                                                                 SMEM_DBE is thrown, software may scrub the error by reloading PKI_CL()_SMEM(). */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1C/H) PCAM0 ECC single bit error. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1C/H) PCAM0 ECC double bit error. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1C/H) PCAM1 ECC single bit error. */
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1C/H) PCAM1 ECC double bit error. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_ecc_int_s cn; */
} bdk_pki_clx_ecc_int_t;

static inline uint64_t BDK_PKI_CLX_ECC_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_ECC_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c200ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_ECC_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_ECC_INT(a) bdk_pki_clx_ecc_int_t
#define bustype_BDK_PKI_CLX_ECC_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_ECC_INT(a) "PKI_CLX_ECC_INT"
#define device_bar_BDK_PKI_CLX_ECC_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_ECC_INT(a) (a)
#define arguments_BDK_PKI_CLX_ECC_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_ecc_int_ena_w1c
 *
 * PKI Cluster ECC/Parity Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_ecc_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM1_DBE]. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM1_SBE]. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM0_DBE]. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM0_SBE]. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[SMEM_DBE]. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[SMEM_SBE]. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[DMEM_PERR]. */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[RF_PERR]. */
#else /* Word 0 - Little Endian */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[RF_PERR]. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[DMEM_PERR]. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[SMEM_SBE]. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[SMEM_DBE]. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM0_SBE]. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM0_DBE]. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM1_SBE]. */
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_ECC_INT[PCAM1_DBE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_ecc_int_ena_w1c_s cn; */
} bdk_pki_clx_ecc_int_ena_w1c_t;

static inline uint64_t BDK_PKI_CLX_ECC_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_ECC_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c220ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_ECC_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_ECC_INT_ENA_W1C(a) bdk_pki_clx_ecc_int_ena_w1c_t
#define bustype_BDK_PKI_CLX_ECC_INT_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_ECC_INT_ENA_W1C(a) "PKI_CLX_ECC_INT_ENA_W1C"
#define device_bar_BDK_PKI_CLX_ECC_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_ECC_INT_ENA_W1C(a) (a)
#define arguments_BDK_PKI_CLX_ECC_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_ecc_int_ena_w1s
 *
 * PKI Cluster ECC/Parity Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_ecc_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM1_DBE]. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM1_SBE]. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM0_DBE]. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM0_SBE]. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[SMEM_DBE]. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[SMEM_SBE]. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[DMEM_PERR]. */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[RF_PERR]. */
#else /* Word 0 - Little Endian */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[RF_PERR]. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[DMEM_PERR]. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[SMEM_SBE]. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[SMEM_DBE]. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM0_SBE]. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM0_DBE]. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM1_SBE]. */
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_ECC_INT[PCAM1_DBE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_ecc_int_ena_w1s_s cn; */
} bdk_pki_clx_ecc_int_ena_w1s_t;

static inline uint64_t BDK_PKI_CLX_ECC_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_ECC_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c230ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_ECC_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_ECC_INT_ENA_W1S(a) bdk_pki_clx_ecc_int_ena_w1s_t
#define bustype_BDK_PKI_CLX_ECC_INT_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_ECC_INT_ENA_W1S(a) "PKI_CLX_ECC_INT_ENA_W1S"
#define device_bar_BDK_PKI_CLX_ECC_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_ECC_INT_ENA_W1S(a) (a)
#define arguments_BDK_PKI_CLX_ECC_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_ecc_int_w1s
 *
 * PKI Cluster ECC/Parity Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_ecc_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM1_DBE]. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM1_SBE]. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM0_DBE]. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM0_SBE]. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[SMEM_DBE]. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[SMEM_SBE]. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[DMEM_PERR]. */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[RF_PERR]. */
#else /* Word 0 - Little Endian */
        uint64_t rf_perr               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[RF_PERR]. */
        uint64_t dmem_perr             : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[DMEM_PERR]. */
        uint64_t smem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[SMEM_SBE]. */
        uint64_t smem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[SMEM_DBE]. */
        uint64_t pcam0_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM0_SBE]. */
        uint64_t pcam0_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM0_DBE]. */
        uint64_t pcam1_sbe             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM1_SBE]. */
        uint64_t pcam1_dbe             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_CL(0..1)_ECC_INT[PCAM1_DBE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_ecc_int_w1s_s cn; */
} bdk_pki_clx_ecc_int_w1s_t;

static inline uint64_t BDK_PKI_CLX_ECC_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_ECC_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c210ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_ECC_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_ECC_INT_W1S(a) bdk_pki_clx_ecc_int_w1s_t
#define bustype_BDK_PKI_CLX_ECC_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_ECC_INT_W1S(a) "PKI_CLX_ECC_INT_W1S"
#define device_bar_BDK_PKI_CLX_ECC_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_ECC_INT_W1S(a) (a)
#define arguments_BDK_PKI_CLX_ECC_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_int
 *
 * PKI Cluster Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1C/H) PCAM sequencer debug interrupt. INTERNAL:
                                                                 Caused by TRAP or INTR sequence state. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1C/H) PCAM/SMEM internal port conflict. Internal error, should not occur.
                                                                 INTERNAL: Sequencer mis-scheduled PCAM or SMEM
                                                                 ops with overlapping accesses. */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1C/H) PCAM() match hit multiple rows, indicating either a soft error in the PCAM or a
                                                                 programming error in PKI_CL()_PCAM()_MATCH() or related registers.
                                                                 Once a conflict is detected, the PCAM state
                                                                 is unpredictable and is required to be fully reconfigured before further valid processing
                                                                 can take place. */
#else /* Word 0 - Little Endian */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1C/H) PCAM() match hit multiple rows, indicating either a soft error in the PCAM or a
                                                                 programming error in PKI_CL()_PCAM()_MATCH() or related registers.
                                                                 Once a conflict is detected, the PCAM state
                                                                 is unpredictable and is required to be fully reconfigured before further valid processing
                                                                 can take place. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1C/H) PCAM/SMEM internal port conflict. Internal error, should not occur.
                                                                 INTERNAL: Sequencer mis-scheduled PCAM or SMEM
                                                                 ops with overlapping accesses. */
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1C/H) PCAM sequencer debug interrupt. INTERNAL:
                                                                 Caused by TRAP or INTR sequence state. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_int_s cn; */
} bdk_pki_clx_int_t;

static inline uint64_t BDK_PKI_CLX_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c100ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_INT(a) bdk_pki_clx_int_t
#define bustype_BDK_PKI_CLX_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_INT(a) "PKI_CLX_INT"
#define device_bar_BDK_PKI_CLX_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_INT(a) (a)
#define arguments_BDK_PKI_CLX_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_int_ena_w1c
 *
 * PKI Cluster Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_INT[IPTINT]. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_INT[SCHED_CONF]. */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_INT[PCAM_CONF]. */
#else /* Word 0 - Little Endian */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_INT[PCAM_CONF]. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_INT[SCHED_CONF]. */
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_CL(0..1)_INT[IPTINT]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_int_ena_w1c_s cn; */
} bdk_pki_clx_int_ena_w1c_t;

static inline uint64_t BDK_PKI_CLX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c120ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_INT_ENA_W1C(a) bdk_pki_clx_int_ena_w1c_t
#define bustype_BDK_PKI_CLX_INT_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_INT_ENA_W1C(a) "PKI_CLX_INT_ENA_W1C"
#define device_bar_BDK_PKI_CLX_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_INT_ENA_W1C(a) (a)
#define arguments_BDK_PKI_CLX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_int_ena_w1s
 *
 * PKI Cluster Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_INT[IPTINT]. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_INT[SCHED_CONF]. */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_INT[PCAM_CONF]. */
#else /* Word 0 - Little Endian */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_INT[PCAM_CONF]. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_INT[SCHED_CONF]. */
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_CL(0..1)_INT[IPTINT]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_int_ena_w1s_s cn; */
} bdk_pki_clx_int_ena_w1s_t;

static inline uint64_t BDK_PKI_CLX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c130ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_INT_ENA_W1S(a) bdk_pki_clx_int_ena_w1s_t
#define bustype_BDK_PKI_CLX_INT_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_INT_ENA_W1S(a) "PKI_CLX_INT_ENA_W1S"
#define device_bar_BDK_PKI_CLX_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_INT_ENA_W1S(a) (a)
#define arguments_BDK_PKI_CLX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_int_w1s
 *
 * PKI Cluster Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_CL(0..1)_INT[IPTINT]. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_CL(0..1)_INT[SCHED_CONF]. */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1S/H) Reads or sets PKI_CL(0..1)_INT[PCAM_CONF]. */
#else /* Word 0 - Little Endian */
        uint64_t pcam_conf             : 2;  /**< [  1:  0](R/W1S/H) Reads or sets PKI_CL(0..1)_INT[PCAM_CONF]. */
        uint64_t sched_conf            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_CL(0..1)_INT[SCHED_CONF]. */
        uint64_t iptint                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_CL(0..1)_INT[IPTINT]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_int_w1s_s cn; */
} bdk_pki_clx_int_w1s_t;

static inline uint64_t BDK_PKI_CLX_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c110ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_INT_W1S(a) bdk_pki_clx_int_w1s_t
#define bustype_BDK_PKI_CLX_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_INT_W1S(a) "PKI_CLX_INT_W1S"
#define device_bar_BDK_PKI_CLX_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_INT_W1S(a) (a)
#define arguments_BDK_PKI_CLX_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_pcam#_action#
 *
 * PKI PCAM Entry Action Registers
 * Action performed based on PCAM lookup using the PKI_CL()_PCAM()_TERM() and
 * PKI_CL()_PCAM()_MATCH() registers.
 *
 * If lookup data matches no PCAM entries, then no action takes place. No matches indicates
 * normal parsing will continue.
 *
 * If data matches multiple PCAM entries, PKI_WQE_S[OPCODE] of the processed packet may be set to
 * PKI_OPCODE_E::RE_PKIPCAM and the PKI_CL()_INT[PCAM_CONF] error interrupt is signaled.  Once a
 * conflict is detected, the PCAM state is unpredictable and is required to be fully reconfigured
 * before further valid processing can take place.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pcamx_actionx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rsvdrw31              : 1;  /**< [ 31: 31](R/W) Reserved. Must be zero. */
        uint64_t pmc                   : 7;  /**< [ 30: 24](R/W) Parse mode change. Where to resume parsing after applying the scan offset (if any) as bit
                                                                 mask of which sequence steps to no longer process:

                                                                 _ <0> = LA (L2)
                                                                 _ <1> = LB (Custom)
                                                                 _ <2> = LC (L3)
                                                                 _ <3> = LD (Virt)
                                                                 _ <4> = LE (IL3)
                                                                 _ <5> = LF (L4)
                                                                 _ <6> = LG (Custom/Application)

                                                                 The legal values are:
                                                                 0x0 = no change in parsing.
                                                                 0x1 = Skip further LA parsing; start LB parsing. For TERM==L2_CUSTOM only).
                                                                 0x3 = Skip further LA/LB parsing; start LC parsing. For TERMs through Ethertypes only).
                                                                 0x7 = Skip further LA-LC parsing; start LD parsing. For TERMs through L3FLAGS only).
                                                                 0x7F = Skip all parsing; no further packet inspection. For TERMs through L3FLAGS only).

                                                                 For example an Ethertype match action that wishes to resume with additional Ethertype
                                                                 matches would use a zero PMC to indicate no parse mode change. An Ethertype match action
                                                                 that wishes to not parse any additional Ethertypes and resume at LC would use 0x3.

                                                                 Must be zero for invalid entries, or for TERMs that do not allow a parse mode change as
                                                                 specified in the PKI_PCAM_TERM_E table. */
        uint64_t style_add             : 8;  /**< [ 23: 16](R/W) Resulting interim style adder. If this CAM entry matches, the value to add to the current
                                                                 style (may wrap around through 256). Must be zero for invalid entries. */
        uint64_t pf                    : 3;  /**< [ 15: 13](R/W) Parse flag to set. Specifies the parse flag to set when entry matches, see PCAM actions
                                                                 may also specify setting one of four user flags in the generated work queue entry,
                                                                 WQE[PF1] through WQE[PF4]. These flags are not used by hardware; they are intended to
                                                                 indicate to software that exceptional handling may be required, such as the presence of an
                                                                 encrypted packet:

                                                                 _ 0x0 = no change.
                                                                 _ 0x1 = Set WQE[PF1].
                                                                 _ 0x2 = Set WQE[PF2].
                                                                 _ 0x3 = Set WQE[PF3].
                                                                 _ 0x4 = Set WQE[PF4].
                                                                 _ else = reserved.

                                                                 Must be zero for invalid entries. */
        uint64_t setty                 : 5;  /**< [ 12:  8](R/W) Set pointer type. If non-zero, indicates the layer type to be set as described under
                                                                 PKI_PCAM_TERM_E. Values are enumerated by PKI_LTYPE_E. Must be zero for invalid entries.
                                                                 The PKI_PCAM_TERM_E table enumerates legal/common SETTY values. */
        uint64_t advance               : 8;  /**< [  7:  0](R/W) Relative number of bytes to advance scan pointer when entry matches.
                                                                 Must be even. Must be zero for invalid entries and for TERMs that do not allow
                                                                 an advance as specified in the PKI_PCAM_TERM_E table. */
#else /* Word 0 - Little Endian */
        uint64_t advance               : 8;  /**< [  7:  0](R/W) Relative number of bytes to advance scan pointer when entry matches.
                                                                 Must be even. Must be zero for invalid entries and for TERMs that do not allow
                                                                 an advance as specified in the PKI_PCAM_TERM_E table. */
        uint64_t setty                 : 5;  /**< [ 12:  8](R/W) Set pointer type. If non-zero, indicates the layer type to be set as described under
                                                                 PKI_PCAM_TERM_E. Values are enumerated by PKI_LTYPE_E. Must be zero for invalid entries.
                                                                 The PKI_PCAM_TERM_E table enumerates legal/common SETTY values. */
        uint64_t pf                    : 3;  /**< [ 15: 13](R/W) Parse flag to set. Specifies the parse flag to set when entry matches, see PCAM actions
                                                                 may also specify setting one of four user flags in the generated work queue entry,
                                                                 WQE[PF1] through WQE[PF4]. These flags are not used by hardware; they are intended to
                                                                 indicate to software that exceptional handling may be required, such as the presence of an
                                                                 encrypted packet:

                                                                 _ 0x0 = no change.
                                                                 _ 0x1 = Set WQE[PF1].
                                                                 _ 0x2 = Set WQE[PF2].
                                                                 _ 0x3 = Set WQE[PF3].
                                                                 _ 0x4 = Set WQE[PF4].
                                                                 _ else = reserved.

                                                                 Must be zero for invalid entries. */
        uint64_t style_add             : 8;  /**< [ 23: 16](R/W) Resulting interim style adder. If this CAM entry matches, the value to add to the current
                                                                 style (may wrap around through 256). Must be zero for invalid entries. */
        uint64_t pmc                   : 7;  /**< [ 30: 24](R/W) Parse mode change. Where to resume parsing after applying the scan offset (if any) as bit
                                                                 mask of which sequence steps to no longer process:

                                                                 _ <0> = LA (L2)
                                                                 _ <1> = LB (Custom)
                                                                 _ <2> = LC (L3)
                                                                 _ <3> = LD (Virt)
                                                                 _ <4> = LE (IL3)
                                                                 _ <5> = LF (L4)
                                                                 _ <6> = LG (Custom/Application)

                                                                 The legal values are:
                                                                 0x0 = no change in parsing.
                                                                 0x1 = Skip further LA parsing; start LB parsing. For TERM==L2_CUSTOM only).
                                                                 0x3 = Skip further LA/LB parsing; start LC parsing. For TERMs through Ethertypes only).
                                                                 0x7 = Skip further LA-LC parsing; start LD parsing. For TERMs through L3FLAGS only).
                                                                 0x7F = Skip all parsing; no further packet inspection. For TERMs through L3FLAGS only).

                                                                 For example an Ethertype match action that wishes to resume with additional Ethertype
                                                                 matches would use a zero PMC to indicate no parse mode change. An Ethertype match action
                                                                 that wishes to not parse any additional Ethertypes and resume at LC would use 0x3.

                                                                 Must be zero for invalid entries, or for TERMs that do not allow a parse mode change as
                                                                 specified in the PKI_PCAM_TERM_E table. */
        uint64_t rsvdrw31              : 1;  /**< [ 31: 31](R/W) Reserved. Must be zero. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pcamx_actionx_s cn; */
} bdk_pki_clx_pcamx_actionx_t;

static inline uint64_t BDK_PKI_CLX_PCAMX_ACTIONX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PCAMX_ACTIONX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1) && (c<=191)))
        return 0x86c000708000ll + 0x10000ll * ((a) & 0x1) + 0x1000ll * ((b) & 0x1) + 8ll * ((c) & 0xff);
    __bdk_csr_fatal("PKI_CLX_PCAMX_ACTIONX", 3, a, b, c, 0);
}

#define typedef_BDK_PKI_CLX_PCAMX_ACTIONX(a,b,c) bdk_pki_clx_pcamx_actionx_t
#define bustype_BDK_PKI_CLX_PCAMX_ACTIONX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PCAMX_ACTIONX(a,b,c) "PKI_CLX_PCAMX_ACTIONX"
#define device_bar_BDK_PKI_CLX_PCAMX_ACTIONX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PCAMX_ACTIONX(a,b,c) (a)
#define arguments_BDK_PKI_CLX_PCAMX_ACTIONX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pki_cl#_pcam#_match#
 *
 * PKI PCAM Entry Data Match Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pcamx_matchx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data1                 : 32; /**< [ 63: 32](R/W) See [DATA0]. */
        uint64_t data0                 : 32; /**< [ 31:  0](R/W) The packet data to compare against. Bits may be ignored in comparison based on [DATA0] and
                                                                 [DATA1]. If the entry matches, PKI_CL()_PCAM()_ACTION() will determine the
                                                                 action to be taken. See PKI_PCAM_TERM_E for comparison bit definitions.
                                                                 The field value is ternary, where each bit matches as follows:

                                                                 _ DATA1<n>=0, DATA0<n>=0: Always match; data<n> don't care.
                                                                 _ DATA1<n>=0, DATA0<n>=1: Match when data<n> == 0.
                                                                 _ DATA1<n>=1, DATA0<n>=0: Match when data<n> == 1.
                                                                 _ DATA1<n>=1, DATA0<n>=1: Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t data0                 : 32; /**< [ 31:  0](R/W) The packet data to compare against. Bits may be ignored in comparison based on [DATA0] and
                                                                 [DATA1]. If the entry matches, PKI_CL()_PCAM()_ACTION() will determine the
                                                                 action to be taken. See PKI_PCAM_TERM_E for comparison bit definitions.
                                                                 The field value is ternary, where each bit matches as follows:

                                                                 _ DATA1<n>=0, DATA0<n>=0: Always match; data<n> don't care.
                                                                 _ DATA1<n>=0, DATA0<n>=1: Match when data<n> == 0.
                                                                 _ DATA1<n>=1, DATA0<n>=0: Match when data<n> == 1.
                                                                 _ DATA1<n>=1, DATA0<n>=1: Reserved. */
        uint64_t data1                 : 32; /**< [ 63: 32](R/W) See [DATA0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pcamx_matchx_s cn; */
} bdk_pki_clx_pcamx_matchx_t;

static inline uint64_t BDK_PKI_CLX_PCAMX_MATCHX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PCAMX_MATCHX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1) && (c<=191)))
        return 0x86c000704000ll + 0x10000ll * ((a) & 0x1) + 0x1000ll * ((b) & 0x1) + 8ll * ((c) & 0xff);
    __bdk_csr_fatal("PKI_CLX_PCAMX_MATCHX", 3, a, b, c, 0);
}

#define typedef_BDK_PKI_CLX_PCAMX_MATCHX(a,b,c) bdk_pki_clx_pcamx_matchx_t
#define bustype_BDK_PKI_CLX_PCAMX_MATCHX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PCAMX_MATCHX(a,b,c) "PKI_CLX_PCAMX_MATCHX"
#define device_bar_BDK_PKI_CLX_PCAMX_MATCHX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PCAMX_MATCHX(a,b,c) (a)
#define arguments_BDK_PKI_CLX_PCAMX_MATCHX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pki_cl#_pcam#_term#
 *
 * PKI PCAM Entry Term Match Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pcamx_termx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t valid                 : 1;  /**< [ 63: 63](R/W) Valid. */
        uint64_t reserved_48_62        : 15;
        uint64_t term1                 : 8;  /**< [ 47: 40](R/W) See [TERM0]. */
        uint64_t style1                : 8;  /**< [ 39: 32](R/W) See [STYLE0]. */
        uint64_t reserved_16_31        : 16;
        uint64_t term0                 : 8;  /**< [ 15:  8](R/W) Comparison type. Enumerated by PKI_PCAM_TERM_E. The field value is ternary, where each
                                                                 bit matches as follows:

                                                                 _ TERM1<n>=0, TERM0<n>=0: Always match; data<n> don't care.
                                                                 _ TERM1<n>=0, TERM0<n>=1: Match when data<n> == 0.
                                                                 _ TERM1<n>=1, TERM0<n>=0: Match when data<n> == 1.
                                                                 _ TERM1<n>=1, TERM0<n>=1: Reserved. */
        uint64_t style0                : 8;  /**< [  7:  0](R/W) Previous interim style. The style that must have been calculated by the port
                                                                 PKI_CL()_PKIND()_STYLE[STYLE] or as modified by previous CAM hits's
                                                                 PKI_CL()_PCAM()_ACTION()[STYLE]. This is used to form AND style matches.

                                                                 The field value is ternary, where each bit matches as follows:

                                                                 _ STYLE1<n>=0, STYLE0<n>=0: Always match; data<n> don't care.
                                                                 _ STYLE1<n>=0, STYLE0<n>=1: Match when data<n> == 0.
                                                                 _ STYLE1<n>=1, STYLE0<n>=0: Match when data<n> == 1.
                                                                 _ STYLE1<n>=1, STYLE0<n>=1: Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t style0                : 8;  /**< [  7:  0](R/W) Previous interim style. The style that must have been calculated by the port
                                                                 PKI_CL()_PKIND()_STYLE[STYLE] or as modified by previous CAM hits's
                                                                 PKI_CL()_PCAM()_ACTION()[STYLE]. This is used to form AND style matches.

                                                                 The field value is ternary, where each bit matches as follows:

                                                                 _ STYLE1<n>=0, STYLE0<n>=0: Always match; data<n> don't care.
                                                                 _ STYLE1<n>=0, STYLE0<n>=1: Match when data<n> == 0.
                                                                 _ STYLE1<n>=1, STYLE0<n>=0: Match when data<n> == 1.
                                                                 _ STYLE1<n>=1, STYLE0<n>=1: Reserved. */
        uint64_t term0                 : 8;  /**< [ 15:  8](R/W) Comparison type. Enumerated by PKI_PCAM_TERM_E. The field value is ternary, where each
                                                                 bit matches as follows:

                                                                 _ TERM1<n>=0, TERM0<n>=0: Always match; data<n> don't care.
                                                                 _ TERM1<n>=0, TERM0<n>=1: Match when data<n> == 0.
                                                                 _ TERM1<n>=1, TERM0<n>=0: Match when data<n> == 1.
                                                                 _ TERM1<n>=1, TERM0<n>=1: Reserved. */
        uint64_t reserved_16_31        : 16;
        uint64_t style1                : 8;  /**< [ 39: 32](R/W) See [STYLE0]. */
        uint64_t term1                 : 8;  /**< [ 47: 40](R/W) See [TERM0]. */
        uint64_t reserved_48_62        : 15;
        uint64_t valid                 : 1;  /**< [ 63: 63](R/W) Valid. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pcamx_termx_s cn; */
} bdk_pki_clx_pcamx_termx_t;

static inline uint64_t BDK_PKI_CLX_PCAMX_TERMX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PCAMX_TERMX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1) && (c<=191)))
        return 0x86c000700000ll + 0x10000ll * ((a) & 0x1) + 0x1000ll * ((b) & 0x1) + 8ll * ((c) & 0xff);
    __bdk_csr_fatal("PKI_CLX_PCAMX_TERMX", 3, a, b, c, 0);
}

#define typedef_BDK_PKI_CLX_PCAMX_TERMX(a,b,c) bdk_pki_clx_pcamx_termx_t
#define bustype_BDK_PKI_CLX_PCAMX_TERMX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PCAMX_TERMX(a,b,c) "PKI_CLX_PCAMX_TERMX"
#define device_bar_BDK_PKI_CLX_PCAMX_TERMX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PCAMX_TERMX(a,b,c) (a)
#define arguments_BDK_PKI_CLX_PCAMX_TERMX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pki_cl#_pkind#_cfg
 *
 * PKI Per-Pkind Configuration Registers
 * Internal:
 * This register contains per-pkind tag configuration information. INTERNAL: This register is not
 * passed through to PBE. Information that does need to be passed to PBE is instead in one of the
 * STYLE registers.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pkindx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t rsvdrw15              : 8;  /**< [ 15:  8](R/W) Reserved. */
        uint64_t fcs_pres              : 1;  /**< [  7:  7](R/W) FCS present.
                                                                 0 = FCS not present. FCS may not be checked nor stripped.
                                                                 1 = FCS present; the last four bytes of the packet are part of the FCS and may not be
                                                                 considered part of a IP, TCP or other header for length error checks.
                                                                 PKI_CL()_STYLE()_CFG[FCS_CHK or FCS_STRIP] may optionally be set. */
        uint64_t mpls_en               : 1;  /**< [  6:  6](R/W) Enable MPLS parsing.
                                                                 0 = Any MPLS labels are ignored, but may be handled by custom Ethertype PCAM matchers.
                                                                 1 = MPLS label stacks are parsed and skipped over. PKI_GBL_PEN[MPLS_PEN] must be set. */
        uint64_t inst_hdr              : 1;  /**< [  5:  5](R/W) INST header. When set, the eight-byte INST_HDR is present on all packets (except incoming
                                                                 packets on the DPI ports). */
        uint64_t lg_custom             : 1;  /**< [  4:  4](R/W) Layer G Custom Match Enable.
                                                                 0 = Disable custom LG header extraction.
                                                                 1 = Enable custom LG header extraction.
                                                                 PKI_GBL_PEN[CLG_PEN] must be set. */
        uint64_t fulc_en               : 1;  /**< [  3:  3](R/W) Enable Fulcrum tag parsing.
                                                                 0 = Any Fulcrum header is ignored.
                                                                 1 = Fulcrum header is parsed. PKI_GBL_PEN[FULC_PEN] must be set.
                                                                 At most one of FULC_EN, DSA_EN or HG_EN may be set. */
        uint64_t dsa_en                : 1;  /**< [  2:  2](R/W) Enable DSA parsing. This field should not be set for DPI ports.
                                                                 0 = Any DSA header is ignored.
                                                                 1 = DSA is parsed. PKI_GBL_PEN[DSA_PEN] must be set.
                                                                 At most one of FULC_EN, DSA_EN or HG_EN may be set. */
        uint64_t hg2_en                : 1;  /**< [  1:  1](R/W) Enable HiGig 2 parsing. This field should not be set for DPI ports.
                                                                 0 = Any HiGig2 header is ignored.
                                                                 1 = HiGig2 is parsed. PKI_GBL_PEN[HG_PEN] must be set. */
        uint64_t hg_en                 : 1;  /**< [  0:  0](R/W) Enable HiGig parsing. This field should not be set for DPI ports.
                                                                 0 = Any HiGig header is ignored.
                                                                 1 = HiGig is parsed. PKI_GBL_PEN[HG_PEN] must be set.
                                                                 At most one of FULC_EN, DSA_EN or HG_EN may be set. */
#else /* Word 0 - Little Endian */
        uint64_t hg_en                 : 1;  /**< [  0:  0](R/W) Enable HiGig parsing. This field should not be set for DPI ports.
                                                                 0 = Any HiGig header is ignored.
                                                                 1 = HiGig is parsed. PKI_GBL_PEN[HG_PEN] must be set.
                                                                 At most one of FULC_EN, DSA_EN or HG_EN may be set. */
        uint64_t hg2_en                : 1;  /**< [  1:  1](R/W) Enable HiGig 2 parsing. This field should not be set for DPI ports.
                                                                 0 = Any HiGig2 header is ignored.
                                                                 1 = HiGig2 is parsed. PKI_GBL_PEN[HG_PEN] must be set. */
        uint64_t dsa_en                : 1;  /**< [  2:  2](R/W) Enable DSA parsing. This field should not be set for DPI ports.
                                                                 0 = Any DSA header is ignored.
                                                                 1 = DSA is parsed. PKI_GBL_PEN[DSA_PEN] must be set.
                                                                 At most one of FULC_EN, DSA_EN or HG_EN may be set. */
        uint64_t fulc_en               : 1;  /**< [  3:  3](R/W) Enable Fulcrum tag parsing.
                                                                 0 = Any Fulcrum header is ignored.
                                                                 1 = Fulcrum header is parsed. PKI_GBL_PEN[FULC_PEN] must be set.
                                                                 At most one of FULC_EN, DSA_EN or HG_EN may be set. */
        uint64_t lg_custom             : 1;  /**< [  4:  4](R/W) Layer G Custom Match Enable.
                                                                 0 = Disable custom LG header extraction.
                                                                 1 = Enable custom LG header extraction.
                                                                 PKI_GBL_PEN[CLG_PEN] must be set. */
        uint64_t inst_hdr              : 1;  /**< [  5:  5](R/W) INST header. When set, the eight-byte INST_HDR is present on all packets (except incoming
                                                                 packets on the DPI ports). */
        uint64_t mpls_en               : 1;  /**< [  6:  6](R/W) Enable MPLS parsing.
                                                                 0 = Any MPLS labels are ignored, but may be handled by custom Ethertype PCAM matchers.
                                                                 1 = MPLS label stacks are parsed and skipped over. PKI_GBL_PEN[MPLS_PEN] must be set. */
        uint64_t fcs_pres              : 1;  /**< [  7:  7](R/W) FCS present.
                                                                 0 = FCS not present. FCS may not be checked nor stripped.
                                                                 1 = FCS present; the last four bytes of the packet are part of the FCS and may not be
                                                                 considered part of a IP, TCP or other header for length error checks.
                                                                 PKI_CL()_STYLE()_CFG[FCS_CHK or FCS_STRIP] may optionally be set. */
        uint64_t rsvdrw15              : 8;  /**< [ 15:  8](R/W) Reserved. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pkindx_cfg_s cn; */
} bdk_pki_clx_pkindx_cfg_t;

static inline uint64_t BDK_PKI_CLX_PKINDX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PKINDX_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000300040ll + 0x10000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_PKINDX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_PKINDX_CFG(a,b) bdk_pki_clx_pkindx_cfg_t
#define bustype_BDK_PKI_CLX_PKINDX_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PKINDX_CFG(a,b) "PKI_CLX_PKINDX_CFG"
#define device_bar_BDK_PKI_CLX_PKINDX_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PKINDX_CFG(a,b) (a)
#define arguments_BDK_PKI_CLX_PKINDX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_pkind#_kmem#
 *
 * PKI KMEM Registers
 * A convenient alias block for the following registers:
 * * PKI_CL()_PKIND()_CFG
 * * PKI_CL()_PKIND()_STYLE
 * * PKI_CL()_PKIND()_SKIP
 * * PKI_CL()_PKIND()_L2_CUSTOM
 * * PKI_CL()_PKIND()_LG_CUSTOM
 *
 * The PKI_CL(0..1)_PKIND* registers listed above are the preferred access method.
 *
 * Software should reload the PKI_CL()_PKIND()_KMEM() registers upon the
 * detection of KMEM_SBE or KMEM_DBE.
 *
 * INTERNAL: The register initialization value for each PKIND and register number (plus 32 or 48
 * based on
 * PKI_ICG()_CFG[MLO]). The other PKI_PKND* registers alias inside regions of
 * PKI_CL()_PKIND()_KMEM(). To avoid confusing tools, these aliases have address
 * bit 20 set; the PKI address decoder ignores bit 20 when accessing
 * PKI_CL()_PKIND()_KMEM().
 *
 * In terms of ECC processing, PFE will unload the entire PKND KMEM register set
 * potentially introducing an ECC error from an unaliased register.  Therefore the
 * entire KMEM must be exposed to software to be scrubbed in such an event.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pkindx_kmemx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t data                  : 16; /**< [ 15:  0](R/W) RAM data at given address. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 16; /**< [ 15:  0](R/W) RAM data at given address. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pkindx_kmemx_s cn; */
} bdk_pki_clx_pkindx_kmemx_t;

static inline uint64_t BDK_PKI_CLX_PKINDX_KMEMX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PKINDX_KMEMX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63) && (c<=15)))
        return 0x86c000200000ll + 0x10000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3f) + 8ll * ((c) & 0xf);
    __bdk_csr_fatal("PKI_CLX_PKINDX_KMEMX", 3, a, b, c, 0);
}

#define typedef_BDK_PKI_CLX_PKINDX_KMEMX(a,b,c) bdk_pki_clx_pkindx_kmemx_t
#define bustype_BDK_PKI_CLX_PKINDX_KMEMX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PKINDX_KMEMX(a,b,c) "PKI_CLX_PKINDX_KMEMX"
#define device_bar_BDK_PKI_CLX_PKINDX_KMEMX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PKINDX_KMEMX(a,b,c) (a)
#define arguments_BDK_PKI_CLX_PKINDX_KMEMX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) pki_cl#_pkind#_l2_custom
 *
 * PKI Per-Pkind L2 Custom Extract Registers
 * Internal:
 * INTERNAL: This register is not passed through to PBE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pkindx_l2_custom_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t valid                 : 1;  /**< [ 15: 15](R/W) Valid.
                                                                 0 = Disable custom L2 header extraction.
                                                                 1 = Enable custom L2 header extraction.
                                                                 PKI_GBL_PEN[CLG_PEN] must be set. */
        uint64_t rsvdrw14              : 7;  /**< [ 14:  8](R/W) Reserved. */
        uint64_t offset                : 8;  /**< [  7:  0](R/W) Scan offset. Pointer to first byte of 32-bit custom extraction header, as absolute number
                                                                 of bytes from beginning of packet. If PTP_MODE, the 8-byte timestamp is prepended to the
                                                                 packet, and must be included in counting offset bytes. */
#else /* Word 0 - Little Endian */
        uint64_t offset                : 8;  /**< [  7:  0](R/W) Scan offset. Pointer to first byte of 32-bit custom extraction header, as absolute number
                                                                 of bytes from beginning of packet. If PTP_MODE, the 8-byte timestamp is prepended to the
                                                                 packet, and must be included in counting offset bytes. */
        uint64_t rsvdrw14              : 7;  /**< [ 14:  8](R/W) Reserved. */
        uint64_t valid                 : 1;  /**< [ 15: 15](R/W) Valid.
                                                                 0 = Disable custom L2 header extraction.
                                                                 1 = Enable custom L2 header extraction.
                                                                 PKI_GBL_PEN[CLG_PEN] must be set. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pkindx_l2_custom_s cn; */
} bdk_pki_clx_pkindx_l2_custom_t;

static inline uint64_t BDK_PKI_CLX_PKINDX_L2_CUSTOM(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PKINDX_L2_CUSTOM(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000300058ll + 0x10000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_PKINDX_L2_CUSTOM", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_PKINDX_L2_CUSTOM(a,b) bdk_pki_clx_pkindx_l2_custom_t
#define bustype_BDK_PKI_CLX_PKINDX_L2_CUSTOM(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PKINDX_L2_CUSTOM(a,b) "PKI_CLX_PKINDX_L2_CUSTOM"
#define device_bar_BDK_PKI_CLX_PKINDX_L2_CUSTOM(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PKINDX_L2_CUSTOM(a,b) (a)
#define arguments_BDK_PKI_CLX_PKINDX_L2_CUSTOM(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_pkind#_lg_custom
 *
 * PKI Per-Pkind LG Custom Extract Registers
 * Internal:
 * INTERNAL: This register is not passed through to PBE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pkindx_lg_custom_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t offset                : 8;  /**< [  7:  0](R/W) Scan offset. Pointer to first byte of 32-bit custom extraction header, as relative number
                                                                 of bytes from WQE[LFPTR]. */
#else /* Word 0 - Little Endian */
        uint64_t offset                : 8;  /**< [  7:  0](R/W) Scan offset. Pointer to first byte of 32-bit custom extraction header, as relative number
                                                                 of bytes from WQE[LFPTR]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pkindx_lg_custom_s cn; */
} bdk_pki_clx_pkindx_lg_custom_t;

static inline uint64_t BDK_PKI_CLX_PKINDX_LG_CUSTOM(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PKINDX_LG_CUSTOM(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000300060ll + 0x10000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_PKINDX_LG_CUSTOM", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_PKINDX_LG_CUSTOM(a,b) bdk_pki_clx_pkindx_lg_custom_t
#define bustype_BDK_PKI_CLX_PKINDX_LG_CUSTOM(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PKINDX_LG_CUSTOM(a,b) "PKI_CLX_PKINDX_LG_CUSTOM"
#define device_bar_BDK_PKI_CLX_PKINDX_LG_CUSTOM(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PKINDX_LG_CUSTOM(a,b) (a)
#define arguments_BDK_PKI_CLX_PKINDX_LG_CUSTOM(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_pkind#_skip
 *
 * PKI Per-Pkind L2 Skip Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pkindx_skip_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t fcs_skip              : 8;  /**< [ 15:  8](R/W) Skip amount from front of packet to first byte covered by FCS start. The skip must be
                                                                 even. If PTP_MODE, the 8-byte timestamp is prepended to the packet, and FCS_SKIP must be
                                                                 at least 8. */
        uint64_t inst_skip             : 8;  /**< [  7:  0](R/W) Skip amount from front of packet to begin parsing at. If
                                                                 PKI_CL()_PKIND()_CFG[INST_HDR] is set, points at the first byte of the
                                                                 instruction header. If INST_HDR is clear, points at the first byte to begin parsing at.
                                                                 The skip must be even. If PTP_MODE, the 8-byte timestamp is prepended to the packet, and
                                                                 INST_SKIP must be at least 8. */
#else /* Word 0 - Little Endian */
        uint64_t inst_skip             : 8;  /**< [  7:  0](R/W) Skip amount from front of packet to begin parsing at. If
                                                                 PKI_CL()_PKIND()_CFG[INST_HDR] is set, points at the first byte of the
                                                                 instruction header. If INST_HDR is clear, points at the first byte to begin parsing at.
                                                                 The skip must be even. If PTP_MODE, the 8-byte timestamp is prepended to the packet, and
                                                                 INST_SKIP must be at least 8. */
        uint64_t fcs_skip              : 8;  /**< [ 15:  8](R/W) Skip amount from front of packet to first byte covered by FCS start. The skip must be
                                                                 even. If PTP_MODE, the 8-byte timestamp is prepended to the packet, and FCS_SKIP must be
                                                                 at least 8. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pkindx_skip_s cn; */
} bdk_pki_clx_pkindx_skip_t;

static inline uint64_t BDK_PKI_CLX_PKINDX_SKIP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PKINDX_SKIP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000300050ll + 0x10000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_PKINDX_SKIP", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_PKINDX_SKIP(a,b) bdk_pki_clx_pkindx_skip_t
#define bustype_BDK_PKI_CLX_PKINDX_SKIP(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PKINDX_SKIP(a,b) "PKI_CLX_PKINDX_SKIP"
#define device_bar_BDK_PKI_CLX_PKINDX_SKIP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PKINDX_SKIP(a,b) (a)
#define arguments_BDK_PKI_CLX_PKINDX_SKIP(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_pkind#_style
 *
 * PKI Per-Pkind Initial Style Registers
 * Internal:
 * INTERNAL: This register is not passed through to PBE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_pkindx_style_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t rsvdrw15              : 1;  /**< [ 15: 15](R/W) Reserved. */
        uint64_t pm                    : 7;  /**< [ 14:  8](R/W) Initial parse mode. Bit mask of which sequence steps to perform, refer to Parse Mode:
                                                                 _ <0> = LA (L2)
                                                                 _ <1> = LB (Custom)
                                                                 _ <2> = LC (L3)
                                                                 _ <3> = LD (L4 Virt)
                                                                 _ <4> = LE (IL3)
                                                                 _ <5> = LF (L4)
                                                                 _ <6> = LG (Custom/Application)

                                                                 The legal values are:

                                                                 _ 0x0 = Parse LA..LG
                                                                 _ 0x1 = Parse LB..LG
                                                                 _ 0x3 = Parse LC..LG
                                                                 _ 0x3F = Parse LG
                                                                 _ 0x7F = Parse nothing
                                                                 _ else = Reserved */
        uint64_t style                 : 8;  /**< [  7:  0](R/W) Initial style. Initial style number for packets on this port, will remain as final style
                                                                 if no PCAM entries match the packet. Note only 64 final styles exist, the upper two bits
                                                                 will only be used for PCAM matching. */
#else /* Word 0 - Little Endian */
        uint64_t style                 : 8;  /**< [  7:  0](R/W) Initial style. Initial style number for packets on this port, will remain as final style
                                                                 if no PCAM entries match the packet. Note only 64 final styles exist, the upper two bits
                                                                 will only be used for PCAM matching. */
        uint64_t pm                    : 7;  /**< [ 14:  8](R/W) Initial parse mode. Bit mask of which sequence steps to perform, refer to Parse Mode:
                                                                 _ <0> = LA (L2)
                                                                 _ <1> = LB (Custom)
                                                                 _ <2> = LC (L3)
                                                                 _ <3> = LD (L4 Virt)
                                                                 _ <4> = LE (IL3)
                                                                 _ <5> = LF (L4)
                                                                 _ <6> = LG (Custom/Application)

                                                                 The legal values are:

                                                                 _ 0x0 = Parse LA..LG
                                                                 _ 0x1 = Parse LB..LG
                                                                 _ 0x3 = Parse LC..LG
                                                                 _ 0x3F = Parse LG
                                                                 _ 0x7F = Parse nothing
                                                                 _ else = Reserved */
        uint64_t rsvdrw15              : 1;  /**< [ 15: 15](R/W) Reserved. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_pkindx_style_s cn; */
} bdk_pki_clx_pkindx_style_t;

static inline uint64_t BDK_PKI_CLX_PKINDX_STYLE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_PKINDX_STYLE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000300048ll + 0x10000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_PKINDX_STYLE", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_PKINDX_STYLE(a,b) bdk_pki_clx_pkindx_style_t
#define bustype_BDK_PKI_CLX_PKINDX_STYLE(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_PKINDX_STYLE(a,b) "PKI_CLX_PKINDX_STYLE"
#define device_bar_BDK_PKI_CLX_PKINDX_STYLE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_PKINDX_STYLE(a,b) (a)
#define arguments_BDK_PKI_CLX_PKINDX_STYLE(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_smem#
 *
 * PKI SMEM Registers
 * A convenient alias block for the following registers:
 * * PKI_CL()_STYLE()_CFG
 * * PKI_CL()_STYLE()_CFG2
 * * PKI_CL()_STYLE()_ALG
 *
 * The PKI_CL(0..1)_STYLE* registers listed above are the preferred access method.
 *
 * Software should reload the PKI_CL()_SMEM() registers upon the
 * detection of SMEM_SBE or SMEM_DBE.
 *
 * INTERNAL: PKI_STYLE* registers alias inside regions of PKI_CL()_SMEM(). To avoid confusing
 * tools, these aliases have address bit 20 set; the PKI address decoder ignores bit 20 when
 * accessing PKI_CL()_SMEM().
 *
 * In terms of ECC processing, ucode will only touch SMEM registers based on the
 * program so we can limit which SMEM addresses are actually used.  ECC faults to
 * unused entries will not create a problem but we will expose for symmetry.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_smemx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t data                  : 32; /**< [ 31:  0](R/W) RAM data at given address. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) RAM data at given address. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_smemx_s cn; */
} bdk_pki_clx_smemx_t;

static inline uint64_t BDK_PKI_CLX_SMEMX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_SMEMX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=2047)))
        return 0x86c000400000ll + 0x10000ll * ((a) & 0x1) + 8ll * ((b) & 0x7ff);
    __bdk_csr_fatal("PKI_CLX_SMEMX", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_SMEMX(a,b) bdk_pki_clx_smemx_t
#define bustype_BDK_PKI_CLX_SMEMX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_SMEMX(a,b) "PKI_CLX_SMEMX"
#define device_bar_BDK_PKI_CLX_SMEMX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_SMEMX(a,b) (a)
#define arguments_BDK_PKI_CLX_SMEMX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_start
 *
 * PKI Cluster Start Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t start                 : 11; /**< [ 10:  0](R/W) Cluster start offset. <1:0> must be zero. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t start                 : 11; /**< [ 10:  0](R/W) Cluster start offset. <1:0> must be zero. For diagnostic use only. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_start_s cn; */
} bdk_pki_clx_start_t;

static inline uint64_t BDK_PKI_CLX_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_START(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c00000c330ll + 0x10000ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_CLX_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_CLX_START(a) bdk_pki_clx_start_t
#define bustype_BDK_PKI_CLX_START(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_START(a) "PKI_CLX_START"
#define device_bar_BDK_PKI_CLX_START(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_START(a) (a)
#define arguments_BDK_PKI_CLX_START(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_cl#_style#_alg
 *
 * PKI Per-Style Algorithm Configuration Registers
 * Internal:
 * INTERNAL: This register is inside the SMEM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_stylex_alg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tt                    : 2;  /**< [ 31: 30](R/W) SSO tag type to schedule to, enumerated by SSO_TT_E. */
        uint64_t apad_nip              : 3;  /**< [ 29: 27](R/W) Value for WQE[APAD] when packet is not IP. */
        uint64_t qpg_qos               : 3;  /**< [ 26: 24](R/W) Algorithm to select QoS field in QPG calculation. Enumerated by PKI_QPGQOS_E. */
        uint64_t qpg_port_sh           : 3;  /**< [ 23: 21](R/W) Number of bits to shift port number in QPG calculation. */
        uint64_t qpg_port_msb          : 4;  /**< [ 20: 17](R/W) MSB to take from port number in QPG calculation.
                                                                 0 = Exclude port number from QPG.
                                                                 4 = Include port<3:0>.
                                                                 8 = Include port<7:0>.
                                                                 else Reserved. */
        uint64_t rsvdrw16              : 6;  /**< [ 16: 11](R/W) Reserved. */
        uint64_t tag_vni               : 1;  /**< [ 10: 10](R/W) When NVGRE/VXLAN/GENEVE is found, include VNI in tag generation. When NVGRE is found, include TNI. */
        uint64_t tag_gtp               : 1;  /**< [  9:  9](R/W) When GTP is parsed, include GTP's TEID in tag generation. */
        uint64_t tag_spi               : 1;  /**< [  8:  8](R/W) Include AH/ESP/GRE in tag generation.
                                                                 0 = Exclude AH/ESP/GRE in tag generation.
                                                                 1 = If IP SEC is parsed, include AH/ESP SPI field in tag generation, or if GRE
                                                                 found, include GRE call number in tag generation. */
        uint64_t tag_syn               : 1;  /**< [  7:  7](R/W) Exclude source address for TCP SYN packets.
                                                                 0 = Include source address if TAG_SRC_* used.
                                                                 1 = Exclude source address for TCP packets with SYN & !ACK, even if TAG_SRC_* set. */
        uint64_t tag_pctl              : 1;  /**< [  6:  6](R/W) Include final IPv4 protocol or IPv6 next header in tag generation. */
        uint64_t tag_vs1               : 1;  /**< [  5:  5](R/W) When VLAN stacking is parsed, include second (network order) VLAN in tuple tag generation. */
        uint64_t tag_vs0               : 1;  /**< [  4:  4](R/W) When VLAN stacking is parsed, include first (network order) VLAN in tuple tag generation. */
        uint64_t tag_vlan              : 1;  /**< [  3:  3](R/W) Reserved. */
        uint64_t tag_mpls0             : 1;  /**< [  2:  2](R/W) Reserved. */
        uint64_t tag_prt               : 1;  /**< [  1:  1](R/W) Include interface port in tag hash. */
        uint64_t wqe_vs                : 1;  /**< [  0:  0](R/W) Which VLAN to put into WQE[VLPTR] when VLAN stacking.
                                                                 0 = Use the first (in network order) VLAN or DSA VID.
                                                                 1 = Use the second (in network order) VLAN. */
#else /* Word 0 - Little Endian */
        uint64_t wqe_vs                : 1;  /**< [  0:  0](R/W) Which VLAN to put into WQE[VLPTR] when VLAN stacking.
                                                                 0 = Use the first (in network order) VLAN or DSA VID.
                                                                 1 = Use the second (in network order) VLAN. */
        uint64_t tag_prt               : 1;  /**< [  1:  1](R/W) Include interface port in tag hash. */
        uint64_t tag_mpls0             : 1;  /**< [  2:  2](R/W) Reserved. */
        uint64_t tag_vlan              : 1;  /**< [  3:  3](R/W) Reserved. */
        uint64_t tag_vs0               : 1;  /**< [  4:  4](R/W) When VLAN stacking is parsed, include first (network order) VLAN in tuple tag generation. */
        uint64_t tag_vs1               : 1;  /**< [  5:  5](R/W) When VLAN stacking is parsed, include second (network order) VLAN in tuple tag generation. */
        uint64_t tag_pctl              : 1;  /**< [  6:  6](R/W) Include final IPv4 protocol or IPv6 next header in tag generation. */
        uint64_t tag_syn               : 1;  /**< [  7:  7](R/W) Exclude source address for TCP SYN packets.
                                                                 0 = Include source address if TAG_SRC_* used.
                                                                 1 = Exclude source address for TCP packets with SYN & !ACK, even if TAG_SRC_* set. */
        uint64_t tag_spi               : 1;  /**< [  8:  8](R/W) Include AH/ESP/GRE in tag generation.
                                                                 0 = Exclude AH/ESP/GRE in tag generation.
                                                                 1 = If IP SEC is parsed, include AH/ESP SPI field in tag generation, or if GRE
                                                                 found, include GRE call number in tag generation. */
        uint64_t tag_gtp               : 1;  /**< [  9:  9](R/W) When GTP is parsed, include GTP's TEID in tag generation. */
        uint64_t tag_vni               : 1;  /**< [ 10: 10](R/W) When NVGRE/VXLAN/GENEVE is found, include VNI in tag generation. When NVGRE is found, include TNI. */
        uint64_t rsvdrw16              : 6;  /**< [ 16: 11](R/W) Reserved. */
        uint64_t qpg_port_msb          : 4;  /**< [ 20: 17](R/W) MSB to take from port number in QPG calculation.
                                                                 0 = Exclude port number from QPG.
                                                                 4 = Include port<3:0>.
                                                                 8 = Include port<7:0>.
                                                                 else Reserved. */
        uint64_t qpg_port_sh           : 3;  /**< [ 23: 21](R/W) Number of bits to shift port number in QPG calculation. */
        uint64_t qpg_qos               : 3;  /**< [ 26: 24](R/W) Algorithm to select QoS field in QPG calculation. Enumerated by PKI_QPGQOS_E. */
        uint64_t apad_nip              : 3;  /**< [ 29: 27](R/W) Value for WQE[APAD] when packet is not IP. */
        uint64_t tt                    : 2;  /**< [ 31: 30](R/W) SSO tag type to schedule to, enumerated by SSO_TT_E. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_stylex_alg_s cn; */
} bdk_pki_clx_stylex_alg_t;

static inline uint64_t BDK_PKI_CLX_STYLEX_ALG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_STYLEX_ALG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000501000ll + 0x10000ll * ((a) & 0x1) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_STYLEX_ALG", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_STYLEX_ALG(a,b) bdk_pki_clx_stylex_alg_t
#define bustype_BDK_PKI_CLX_STYLEX_ALG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_STYLEX_ALG(a,b) "PKI_CLX_STYLEX_ALG"
#define device_bar_BDK_PKI_CLX_STYLEX_ALG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_STYLEX_ALG(a,b) (a)
#define arguments_BDK_PKI_CLX_STYLEX_ALG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_style#_cfg
 *
 * PKI Per-Style Configuration Registers
 * Internal:
 * INTERNAL: This register is inside SMEM and passed to PKI BE via PKI_BEWQ_S[CFG]. All bits are
 * used by PKI BE calculations.
 * This register contains per-pkind configuration information.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_stylex_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rsvdrw31              : 1;  /**< [ 31: 31](R/W) Reserved. */
        uint64_t ip6_udp_opt           : 1;  /**< [ 30: 30](R/W) IPv6/UDP checksum is optional. IPv4 allows an optional UDP checksum by sending the all-0s
                                                                 patterns. IPv6 outlaws this and the spec says to always check UDP checksum.
                                                                 0 = Spec compliant, do not allow optional code.
                                                                 1 = Treat IPv6 as IPv4; the all-0s pattern will cause a UDP checksum pass. */
        uint64_t lenerr_en             : 1;  /**< [ 29: 29](R/W) L2 length error check enable. Check if frame was received with L2 length error. This check
                                                                 is typically not enabled for incoming packets on the DPI ports. INTERNAL: Sequencer clears
                                                                 this bit for PKI_BE when SNAP length checks are not appropriate. */
        uint64_t lenerr_eqpad          : 1;  /**< [ 28: 28](R/W) L2 length checks exact pad size.
                                                                 0 = Length check uses greater then or equal comparison. Packets must have at least minimum
                                                                 padding, but may have more. This mode must be used when there may be extra Etherypes
                                                                 including VLAN tags.
                                                                 1 = Length check uses equal comparison. Packets must have the exact padding necessary to
                                                                 insure a minimum frame size and no more. */
        uint64_t minmax_sel            : 1;  /**< [ 27: 27](R/W) Selects which PKI_FRM_LEN_CHK() register is used for this pkind for MINERR and MAXERR
                                                                 checks.
                                                                 0 = use PKI_FRM_LEN_CHK0.
                                                                 1 = use PKI_FRM_LEN_CHK1. */
        uint64_t maxerr_en             : 1;  /**< [ 26: 26](R/W) Max frame error check enable. */
        uint64_t minerr_en             : 1;  /**< [ 25: 25](R/W) Min frame error check enable. This check is typically not enabled for incoming packets on
                                                                 the DPI ports. */
        uint64_t qpg_dis_grptag        : 1;  /**< [ 24: 24](R/W) Disable computing group using WQE[TAG]. */
        uint64_t fcs_strip             : 1;  /**< [ 23: 23](R/W) Strip L2 FCS bytes from packet, decrease WQE[LEN] by 4 bytes.
                                                                 PKI_CL()_PKIND()_CFG[FCS_PRES] must be set. */
        uint64_t fcs_chk               : 1;  /**< [ 22: 22](R/W) FCS checking enabled. PKI_CL()_PKIND()_CFG[FCS_PRES] must be set. */
        uint64_t rawdrp                : 1;  /**< [ 21: 21](R/W) Allow RAW packet drop.
                                                                 0 = Never drop packets with WQE[RAW] set.
                                                                 1 = Allow the PKI to drop RAW packets based on PKI_AURA()_CFG[ENA_RED/ENA_DROP]. */
        uint64_t drop                  : 1;  /**< [ 20: 20](R/W) Force packet dropping.
                                                                 0 = Drop packet based on PKI_AURA()_CFG[ENA_RED/ENA_DROP].
                                                                 1 = Always drop the packet. Overrides [NODROP], [RAWDRP]. */
        uint64_t nodrop                : 1;  /**< [ 19: 19](R/W) Disable QoS packet drop.
                                                                 0 = Allowed to drop packet based on PKI_AURA()_CFG[ENA_RED/ENA_DROP].
                                                                 1 = Never drop the packet. Overrides [RAWDRP]. */
        uint64_t qpg_dis_padd          : 1;  /**< [ 18: 18](R/W) Disable computing port adder by QPG algorithm. */
        uint64_t qpg_dis_grp           : 1;  /**< [ 17: 17](R/W) Disable computing group by QPG algorithm. */
        uint64_t qpg_dis_aura          : 1;  /**< [ 16: 16](R/W) Disable computing aura by QPG algorithm. */
        uint64_t rsvdrw15              : 5;  /**< [ 15: 11](R/W) Reserved. INTERNAL: Sequencer may generate a carry-out when adding to QPG_BASE for
                                                                 PKI_BEWQ_S, therefore bit <11> here is unpredictable. */
        uint64_t qpg_base              : 11; /**< [ 10:  0](R/W) Base index into PKI_QPG_TBL(). INTERNAL: Sequencer starts with QPG_BASE, performs
                                                                 the QPG calculation and packs the resulting QPG index back into this field for PKI_BE_S. */
#else /* Word 0 - Little Endian */
        uint64_t qpg_base              : 11; /**< [ 10:  0](R/W) Base index into PKI_QPG_TBL(). INTERNAL: Sequencer starts with QPG_BASE, performs
                                                                 the QPG calculation and packs the resulting QPG index back into this field for PKI_BE_S. */
        uint64_t rsvdrw15              : 5;  /**< [ 15: 11](R/W) Reserved. INTERNAL: Sequencer may generate a carry-out when adding to QPG_BASE for
                                                                 PKI_BEWQ_S, therefore bit <11> here is unpredictable. */
        uint64_t qpg_dis_aura          : 1;  /**< [ 16: 16](R/W) Disable computing aura by QPG algorithm. */
        uint64_t qpg_dis_grp           : 1;  /**< [ 17: 17](R/W) Disable computing group by QPG algorithm. */
        uint64_t qpg_dis_padd          : 1;  /**< [ 18: 18](R/W) Disable computing port adder by QPG algorithm. */
        uint64_t nodrop                : 1;  /**< [ 19: 19](R/W) Disable QoS packet drop.
                                                                 0 = Allowed to drop packet based on PKI_AURA()_CFG[ENA_RED/ENA_DROP].
                                                                 1 = Never drop the packet. Overrides [RAWDRP]. */
        uint64_t drop                  : 1;  /**< [ 20: 20](R/W) Force packet dropping.
                                                                 0 = Drop packet based on PKI_AURA()_CFG[ENA_RED/ENA_DROP].
                                                                 1 = Always drop the packet. Overrides [NODROP], [RAWDRP]. */
        uint64_t rawdrp                : 1;  /**< [ 21: 21](R/W) Allow RAW packet drop.
                                                                 0 = Never drop packets with WQE[RAW] set.
                                                                 1 = Allow the PKI to drop RAW packets based on PKI_AURA()_CFG[ENA_RED/ENA_DROP]. */
        uint64_t fcs_chk               : 1;  /**< [ 22: 22](R/W) FCS checking enabled. PKI_CL()_PKIND()_CFG[FCS_PRES] must be set. */
        uint64_t fcs_strip             : 1;  /**< [ 23: 23](R/W) Strip L2 FCS bytes from packet, decrease WQE[LEN] by 4 bytes.
                                                                 PKI_CL()_PKIND()_CFG[FCS_PRES] must be set. */
        uint64_t qpg_dis_grptag        : 1;  /**< [ 24: 24](R/W) Disable computing group using WQE[TAG]. */
        uint64_t minerr_en             : 1;  /**< [ 25: 25](R/W) Min frame error check enable. This check is typically not enabled for incoming packets on
                                                                 the DPI ports. */
        uint64_t maxerr_en             : 1;  /**< [ 26: 26](R/W) Max frame error check enable. */
        uint64_t minmax_sel            : 1;  /**< [ 27: 27](R/W) Selects which PKI_FRM_LEN_CHK() register is used for this pkind for MINERR and MAXERR
                                                                 checks.
                                                                 0 = use PKI_FRM_LEN_CHK0.
                                                                 1 = use PKI_FRM_LEN_CHK1. */
        uint64_t lenerr_eqpad          : 1;  /**< [ 28: 28](R/W) L2 length checks exact pad size.
                                                                 0 = Length check uses greater then or equal comparison. Packets must have at least minimum
                                                                 padding, but may have more. This mode must be used when there may be extra Etherypes
                                                                 including VLAN tags.
                                                                 1 = Length check uses equal comparison. Packets must have the exact padding necessary to
                                                                 insure a minimum frame size and no more. */
        uint64_t lenerr_en             : 1;  /**< [ 29: 29](R/W) L2 length error check enable. Check if frame was received with L2 length error. This check
                                                                 is typically not enabled for incoming packets on the DPI ports. INTERNAL: Sequencer clears
                                                                 this bit for PKI_BE when SNAP length checks are not appropriate. */
        uint64_t ip6_udp_opt           : 1;  /**< [ 30: 30](R/W) IPv6/UDP checksum is optional. IPv4 allows an optional UDP checksum by sending the all-0s
                                                                 patterns. IPv6 outlaws this and the spec says to always check UDP checksum.
                                                                 0 = Spec compliant, do not allow optional code.
                                                                 1 = Treat IPv6 as IPv4; the all-0s pattern will cause a UDP checksum pass. */
        uint64_t rsvdrw31              : 1;  /**< [ 31: 31](R/W) Reserved. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_stylex_cfg_s cn; */
} bdk_pki_clx_stylex_cfg_t;

static inline uint64_t BDK_PKI_CLX_STYLEX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_STYLEX_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000500000ll + 0x10000ll * ((a) & 0x1) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_STYLEX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_STYLEX_CFG(a,b) bdk_pki_clx_stylex_cfg_t
#define bustype_BDK_PKI_CLX_STYLEX_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_STYLEX_CFG(a,b) "PKI_CLX_STYLEX_CFG"
#define device_bar_BDK_PKI_CLX_STYLEX_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_STYLEX_CFG(a,b) (a)
#define arguments_BDK_PKI_CLX_STYLEX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_cl#_style#_cfg2
 *
 * PKI Per-Style Configuration 2 Registers
 * Internal:
 * INTERNAL: This register is inside SMEM and passed to PKI BE via PKI_BEWQ_S[CFG2]. All bits are
 * used by PKI BE calculations.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clx_stylex_cfg2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t tag_inc               : 4;  /**< [ 31: 28](R/W) Include masked tags using PKI_TAG_INC()_MASK. Each bit indicates to include the
                                                                 corresponding PKI_TAG_INC_MASK range, see PKI_INST_HDR_S. */
        uint64_t rsvdrw27              : 3;  /**< [ 27: 25](R/W) Reserved. */
        uint64_t tag_masken            : 1;  /**< [ 24: 24](R/W) Apply PKI_STYLE()_TAG_MASK to computed tag. INTERNAL: Sequencer must clear for PKI BE
                                                                 when the tag comes from the PKI_INST_HDR_S. */
        uint64_t tag_src_lg            : 1;  /**< [ 23: 23](R/W) Include Layer G source address in tuple tag generation. */
        uint64_t tag_src_lf            : 1;  /**< [ 22: 22](R/W) Include Layer F source address in tuple tag generation. */
        uint64_t tag_src_le            : 1;  /**< [ 21: 21](R/W) Include Layer E source address in tuple tag generation. */
        uint64_t tag_src_ld            : 1;  /**< [ 20: 20](R/W) Include Layer D source address in tuple tag generation. */
        uint64_t tag_src_lc            : 1;  /**< [ 19: 19](R/W) Include Layer C source address in tuple tag generation. */
        uint64_t tag_src_lb            : 1;  /**< [ 18: 18](R/W) Include Layer B source address in tuple tag generation. INTERNAL: Sequencer must clear
                                                                 TAG_SRC_L* for PKI BE when TCP SYNs are not tagged, or when the tag comes from the
                                                                 PKI_INST_HDR_S. */
        uint64_t tag_dst_lg            : 1;  /**< [ 17: 17](R/W) Include Layer G destination address in tuple tag generation. */
        uint64_t tag_dst_lf            : 1;  /**< [ 16: 16](R/W) Include Layer F destination address in tuple tag generation. */
        uint64_t tag_dst_le            : 1;  /**< [ 15: 15](R/W) Include Layer E destination address in tuple tag generation. */
        uint64_t tag_dst_ld            : 1;  /**< [ 14: 14](R/W) Include Layer D destination address in tuple tag generation. */
        uint64_t tag_dst_lc            : 1;  /**< [ 13: 13](R/W) Include Layer C destination address in tuple tag generation. */
        uint64_t tag_dst_lb            : 1;  /**< [ 12: 12](R/W) Include Layer B destination address in tuple tag generation. INTERNAL: Sequencer must
                                                                 clear TAG_SRC_L* for PKI BE when the tag comes from the PKI_INST_HDR_S. */
        uint64_t len_lg                : 1;  /**< [ 11: 11](R/W) Check length of Layer G. */
        uint64_t len_lf                : 1;  /**< [ 10: 10](R/W) Check length of Layer F. */
        uint64_t len_le                : 1;  /**< [  9:  9](R/W) Check length of Layer E. */
        uint64_t len_ld                : 1;  /**< [  8:  8](R/W) Check length of Layer D. */
        uint64_t len_lc                : 1;  /**< [  7:  7](R/W) Check length of Layer C. */
        uint64_t len_lb                : 1;  /**< [  6:  6](R/W) Check length of Layer B. */
        uint64_t csum_lg               : 1;  /**< [  5:  5](R/W) Compute checksum on Layer G. */
        uint64_t csum_lf               : 1;  /**< [  4:  4](R/W) Compute checksum on Layer F. */
        uint64_t csum_le               : 1;  /**< [  3:  3](R/W) Compute checksum on Layer E. */
        uint64_t csum_ld               : 1;  /**< [  2:  2](R/W) Compute checksum on Layer D. */
        uint64_t csum_lc               : 1;  /**< [  1:  1](R/W) Compute checksum on Layer C. */
        uint64_t csum_lb               : 1;  /**< [  0:  0](R/W) Compute checksum on Layer B. */
#else /* Word 0 - Little Endian */
        uint64_t csum_lb               : 1;  /**< [  0:  0](R/W) Compute checksum on Layer B. */
        uint64_t csum_lc               : 1;  /**< [  1:  1](R/W) Compute checksum on Layer C. */
        uint64_t csum_ld               : 1;  /**< [  2:  2](R/W) Compute checksum on Layer D. */
        uint64_t csum_le               : 1;  /**< [  3:  3](R/W) Compute checksum on Layer E. */
        uint64_t csum_lf               : 1;  /**< [  4:  4](R/W) Compute checksum on Layer F. */
        uint64_t csum_lg               : 1;  /**< [  5:  5](R/W) Compute checksum on Layer G. */
        uint64_t len_lb                : 1;  /**< [  6:  6](R/W) Check length of Layer B. */
        uint64_t len_lc                : 1;  /**< [  7:  7](R/W) Check length of Layer C. */
        uint64_t len_ld                : 1;  /**< [  8:  8](R/W) Check length of Layer D. */
        uint64_t len_le                : 1;  /**< [  9:  9](R/W) Check length of Layer E. */
        uint64_t len_lf                : 1;  /**< [ 10: 10](R/W) Check length of Layer F. */
        uint64_t len_lg                : 1;  /**< [ 11: 11](R/W) Check length of Layer G. */
        uint64_t tag_dst_lb            : 1;  /**< [ 12: 12](R/W) Include Layer B destination address in tuple tag generation. INTERNAL: Sequencer must
                                                                 clear TAG_SRC_L* for PKI BE when the tag comes from the PKI_INST_HDR_S. */
        uint64_t tag_dst_lc            : 1;  /**< [ 13: 13](R/W) Include Layer C destination address in tuple tag generation. */
        uint64_t tag_dst_ld            : 1;  /**< [ 14: 14](R/W) Include Layer D destination address in tuple tag generation. */
        uint64_t tag_dst_le            : 1;  /**< [ 15: 15](R/W) Include Layer E destination address in tuple tag generation. */
        uint64_t tag_dst_lf            : 1;  /**< [ 16: 16](R/W) Include Layer F destination address in tuple tag generation. */
        uint64_t tag_dst_lg            : 1;  /**< [ 17: 17](R/W) Include Layer G destination address in tuple tag generation. */
        uint64_t tag_src_lb            : 1;  /**< [ 18: 18](R/W) Include Layer B source address in tuple tag generation. INTERNAL: Sequencer must clear
                                                                 TAG_SRC_L* for PKI BE when TCP SYNs are not tagged, or when the tag comes from the
                                                                 PKI_INST_HDR_S. */
        uint64_t tag_src_lc            : 1;  /**< [ 19: 19](R/W) Include Layer C source address in tuple tag generation. */
        uint64_t tag_src_ld            : 1;  /**< [ 20: 20](R/W) Include Layer D source address in tuple tag generation. */
        uint64_t tag_src_le            : 1;  /**< [ 21: 21](R/W) Include Layer E source address in tuple tag generation. */
        uint64_t tag_src_lf            : 1;  /**< [ 22: 22](R/W) Include Layer F source address in tuple tag generation. */
        uint64_t tag_src_lg            : 1;  /**< [ 23: 23](R/W) Include Layer G source address in tuple tag generation. */
        uint64_t tag_masken            : 1;  /**< [ 24: 24](R/W) Apply PKI_STYLE()_TAG_MASK to computed tag. INTERNAL: Sequencer must clear for PKI BE
                                                                 when the tag comes from the PKI_INST_HDR_S. */
        uint64_t rsvdrw27              : 3;  /**< [ 27: 25](R/W) Reserved. */
        uint64_t tag_inc               : 4;  /**< [ 31: 28](R/W) Include masked tags using PKI_TAG_INC()_MASK. Each bit indicates to include the
                                                                 corresponding PKI_TAG_INC_MASK range, see PKI_INST_HDR_S. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clx_stylex_cfg2_s cn; */
} bdk_pki_clx_stylex_cfg2_t;

static inline uint64_t BDK_PKI_CLX_STYLEX_CFG2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLX_STYLEX_CFG2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=63)))
        return 0x86c000500800ll + 0x10000ll * ((a) & 0x1) + 8ll * ((b) & 0x3f);
    __bdk_csr_fatal("PKI_CLX_STYLEX_CFG2", 2, a, b, 0, 0);
}

#define typedef_BDK_PKI_CLX_STYLEX_CFG2(a,b) bdk_pki_clx_stylex_cfg2_t
#define bustype_BDK_PKI_CLX_STYLEX_CFG2(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLX_STYLEX_CFG2(a,b) "PKI_CLX_STYLEX_CFG2"
#define device_bar_BDK_PKI_CLX_STYLEX_CFG2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLX_STYLEX_CFG2(a,b) (a)
#define arguments_BDK_PKI_CLX_STYLEX_CFG2(a,b) (a),(b),-1,-1

/**
 * Register (NCB) pki_clken
 *
 * PKI Clock Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_clken_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t clken                 : 1;  /**< [  0:  0](R/W) Controls the conditional clocking within PKI.
                                                                 0 = Allow hardware to control the clocks.
                                                                 1 = Force the clocks to be always on. */
#else /* Word 0 - Little Endian */
        uint64_t clken                 : 1;  /**< [  0:  0](R/W) Controls the conditional clocking within PKI.
                                                                 0 = Allow hardware to control the clocks.
                                                                 1 = Force the clocks to be always on. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_clken_s cn; */
} bdk_pki_clken_t;

#define BDK_PKI_CLKEN BDK_PKI_CLKEN_FUNC()
static inline uint64_t BDK_PKI_CLKEN_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CLKEN_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000410ll;
    __bdk_csr_fatal("PKI_CLKEN", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_CLKEN bdk_pki_clken_t
#define bustype_BDK_PKI_CLKEN BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CLKEN "PKI_CLKEN"
#define device_bar_BDK_PKI_CLKEN 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CLKEN 0
#define arguments_BDK_PKI_CLKEN -1,-1,-1,-1

/**
 * Register (NCB) pki_const
 *
 * PKI Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t fstyles               : 16; /**< [ 63: 48](RO) Number of final styles implemented. E.g. depth of PKI_STYLE()_WQ2. */
        uint64_t pknds                 : 16; /**< [ 47: 32](RO) Number of PKINDs implemented. */
        uint64_t bpid                  : 16; /**< [ 31: 16](RO) Number of BPIDs implemented. */
        uint64_t auras                 : 16; /**< [ 15:  0](RO) Number of auras implemented. */
#else /* Word 0 - Little Endian */
        uint64_t auras                 : 16; /**< [ 15:  0](RO) Number of auras implemented. */
        uint64_t bpid                  : 16; /**< [ 31: 16](RO) Number of BPIDs implemented. */
        uint64_t pknds                 : 16; /**< [ 47: 32](RO) Number of PKINDs implemented. */
        uint64_t fstyles               : 16; /**< [ 63: 48](RO) Number of final styles implemented. E.g. depth of PKI_STYLE()_WQ2. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_const_s cn; */
} bdk_pki_const_t;

#define BDK_PKI_CONST BDK_PKI_CONST_FUNC()
static inline uint64_t BDK_PKI_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000000ll;
    __bdk_csr_fatal("PKI_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_CONST bdk_pki_const_t
#define bustype_BDK_PKI_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CONST "PKI_CONST"
#define device_bar_BDK_PKI_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CONST 0
#define arguments_BDK_PKI_CONST -1,-1,-1,-1

/**
 * Register (NCB) pki_const1
 *
 * PKI Constants Register 1
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t pcams                 : 8;  /**< [ 23: 16](RO) Number of PCAMs per clusters. */
        uint64_t ipes                  : 8;  /**< [ 15:  8](RO) Number of IPEs per clusters. */
        uint64_t cls                   : 8;  /**< [  7:  0](RO) Number of clusters. */
#else /* Word 0 - Little Endian */
        uint64_t cls                   : 8;  /**< [  7:  0](RO) Number of clusters. */
        uint64_t ipes                  : 8;  /**< [ 15:  8](RO) Number of IPEs per clusters. */
        uint64_t pcams                 : 8;  /**< [ 23: 16](RO) Number of PCAMs per clusters. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_const1_s cn; */
} bdk_pki_const1_t;

#define BDK_PKI_CONST1 BDK_PKI_CONST1_FUNC()
static inline uint64_t BDK_PKI_CONST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CONST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000008ll;
    __bdk_csr_fatal("PKI_CONST1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_CONST1 bdk_pki_const1_t
#define bustype_BDK_PKI_CONST1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CONST1 "PKI_CONST1"
#define device_bar_BDK_PKI_CONST1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CONST1 0
#define arguments_BDK_PKI_CONST1 -1,-1,-1,-1

/**
 * Register (NCB) pki_const2
 *
 * PKI Constants Register 2
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_const2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t stats                 : 16; /**< [ 63: 48](RO) Number of wide statistics. E.g. depth of PKI_STAT()_HIST0. */
        uint64_t dstats                : 16; /**< [ 47: 32](RO) Number of deep statistics. E.g. depth of PKI_DSTAT()_STAT0. */
        uint64_t qpgs                  : 16; /**< [ 31: 16](RO) Number of QPGs. E.g. depth of PKI_QPG_TBL(). */
        uint64_t pcam_ents             : 16; /**< [ 15:  0](RO) Number of PCAM entries per PCAM. E.g. depth of final index of PKI_CL()_PCAM()_MATCH(). */
#else /* Word 0 - Little Endian */
        uint64_t pcam_ents             : 16; /**< [ 15:  0](RO) Number of PCAM entries per PCAM. E.g. depth of final index of PKI_CL()_PCAM()_MATCH(). */
        uint64_t qpgs                  : 16; /**< [ 31: 16](RO) Number of QPGs. E.g. depth of PKI_QPG_TBL(). */
        uint64_t dstats                : 16; /**< [ 47: 32](RO) Number of deep statistics. E.g. depth of PKI_DSTAT()_STAT0. */
        uint64_t stats                 : 16; /**< [ 63: 48](RO) Number of wide statistics. E.g. depth of PKI_STAT()_HIST0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_const2_s cn; */
} bdk_pki_const2_t;

#define BDK_PKI_CONST2 BDK_PKI_CONST2_FUNC()
static inline uint64_t BDK_PKI_CONST2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CONST2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000010ll;
    __bdk_csr_fatal("PKI_CONST2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_CONST2 bdk_pki_const2_t
#define bustype_BDK_PKI_CONST2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CONST2 "PKI_CONST2"
#define device_bar_BDK_PKI_CONST2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CONST2 0
#define arguments_BDK_PKI_CONST2 -1,-1,-1,-1

/**
 * Register (NCB) pki_const3
 *
 * PKI Constants Register 3
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_const3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_const3_s cn; */
} bdk_pki_const3_t;

#define BDK_PKI_CONST3 BDK_PKI_CONST3_FUNC()
static inline uint64_t BDK_PKI_CONST3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_CONST3_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000018ll;
    __bdk_csr_fatal("PKI_CONST3", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_CONST3 bdk_pki_const3_t
#define bustype_BDK_PKI_CONST3 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_CONST3 "PKI_CONST3"
#define device_bar_BDK_PKI_CONST3 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_CONST3 0
#define arguments_BDK_PKI_CONST3 -1,-1,-1,-1

/**
 * Register (NCB) pki_dstat#_stat0
 *
 * PKI Packets Deep Statistic Registers
 * This register contains statistics indexed by PKI_QPG_TBLB()[DSTAT_ID].
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_dstatx_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t pkts                  : 32; /**< [ 31:  0](R/W/H) Number of non-dropped packets processed by PKI.
                                                                 The corresponding wide statistic is PKI_STAT()_STAT0. */
#else /* Word 0 - Little Endian */
        uint64_t pkts                  : 32; /**< [ 31:  0](R/W/H) Number of non-dropped packets processed by PKI.
                                                                 The corresponding wide statistic is PKI_STAT()_STAT0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_dstatx_stat0_s cn; */
} bdk_pki_dstatx_stat0_t;

static inline uint64_t BDK_PKI_DSTATX_STAT0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_DSTATX_STAT0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x86c000c00000ll + 0x40ll * ((a) & 0x3ff);
    __bdk_csr_fatal("PKI_DSTATX_STAT0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_DSTATX_STAT0(a) bdk_pki_dstatx_stat0_t
#define bustype_BDK_PKI_DSTATX_STAT0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_DSTATX_STAT0(a) "PKI_DSTATX_STAT0"
#define device_bar_BDK_PKI_DSTATX_STAT0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_DSTATX_STAT0(a) (a)
#define arguments_BDK_PKI_DSTATX_STAT0(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_dstat#_stat1
 *
 * PKI Octects Deep Statistic Registers
 * This register contains statistics indexed by PKI_QPG_TBLB()[DSTAT_ID].
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_dstatx_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t octs                  : 40; /**< [ 39:  0](R/W/H) Number of non-dropped octets received by PKI (good and bad).
                                                                 The corresponding wide statistic is PKI_STAT()_STAT1. */
#else /* Word 0 - Little Endian */
        uint64_t octs                  : 40; /**< [ 39:  0](R/W/H) Number of non-dropped octets received by PKI (good and bad).
                                                                 The corresponding wide statistic is PKI_STAT()_STAT1. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_dstatx_stat1_s cn; */
} bdk_pki_dstatx_stat1_t;

static inline uint64_t BDK_PKI_DSTATX_STAT1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_DSTATX_STAT1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x86c000c00008ll + 0x40ll * ((a) & 0x3ff);
    __bdk_csr_fatal("PKI_DSTATX_STAT1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_DSTATX_STAT1(a) bdk_pki_dstatx_stat1_t
#define bustype_BDK_PKI_DSTATX_STAT1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_DSTATX_STAT1(a) "PKI_DSTATX_STAT1"
#define device_bar_BDK_PKI_DSTATX_STAT1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_DSTATX_STAT1(a) (a)
#define arguments_BDK_PKI_DSTATX_STAT1(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_dstat#_stat2
 *
 * PKI Error Packets Deep Statistic Registers
 * This register contains statistics indexed by PKI_QPG_TBLB()[DSTAT_ID].
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_dstatx_stat2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t err_pkts              : 32; /**< [ 31:  0](R/W/H) Number of packets with errors, including length < minimum, length > maximum, FCS
                                                                 errors, or WQE[ERRLEV]==RE or L2.
                                                                 This corresponds to a sum across the wide statistics PKI_STAT()_STAT7, PKI_STAT()_STAT7,
                                                                 PKI_STAT()_STAT8, PKI_STAT()_STAT9, PKI_STAT()_STAT10, PKI_STAT()_STAT11, and
                                                                 PKI_STAT()_STAT12. */
#else /* Word 0 - Little Endian */
        uint64_t err_pkts              : 32; /**< [ 31:  0](R/W/H) Number of packets with errors, including length < minimum, length > maximum, FCS
                                                                 errors, or WQE[ERRLEV]==RE or L2.
                                                                 This corresponds to a sum across the wide statistics PKI_STAT()_STAT7, PKI_STAT()_STAT7,
                                                                 PKI_STAT()_STAT8, PKI_STAT()_STAT9, PKI_STAT()_STAT10, PKI_STAT()_STAT11, and
                                                                 PKI_STAT()_STAT12. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_dstatx_stat2_s cn; */
} bdk_pki_dstatx_stat2_t;

static inline uint64_t BDK_PKI_DSTATX_STAT2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_DSTATX_STAT2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x86c000c00010ll + 0x40ll * ((a) & 0x3ff);
    __bdk_csr_fatal("PKI_DSTATX_STAT2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_DSTATX_STAT2(a) bdk_pki_dstatx_stat2_t
#define bustype_BDK_PKI_DSTATX_STAT2(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_DSTATX_STAT2(a) "PKI_DSTATX_STAT2"
#define device_bar_BDK_PKI_DSTATX_STAT2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_DSTATX_STAT2(a) (a)
#define arguments_BDK_PKI_DSTATX_STAT2(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_dstat#_stat3
 *
 * PKI Dropped Packets Deep Statistic Registers
 * This register contains statistics indexed by PKI_QPG_TBLB()[DSTAT_ID].
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_dstatx_stat3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t drp_pkts              : 32; /**< [ 31:  0](R/W/H) Inbound packets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP].
                                                                 The corresponding wide statistic is PKI_STAT()_STAT3. */
#else /* Word 0 - Little Endian */
        uint64_t drp_pkts              : 32; /**< [ 31:  0](R/W/H) Inbound packets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP].
                                                                 The corresponding wide statistic is PKI_STAT()_STAT3. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_dstatx_stat3_s cn; */
} bdk_pki_dstatx_stat3_t;

static inline uint64_t BDK_PKI_DSTATX_STAT3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_DSTATX_STAT3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x86c000c00018ll + 0x40ll * ((a) & 0x3ff);
    __bdk_csr_fatal("PKI_DSTATX_STAT3", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_DSTATX_STAT3(a) bdk_pki_dstatx_stat3_t
#define bustype_BDK_PKI_DSTATX_STAT3(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_DSTATX_STAT3(a) "PKI_DSTATX_STAT3"
#define device_bar_BDK_PKI_DSTATX_STAT3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_DSTATX_STAT3(a) (a)
#define arguments_BDK_PKI_DSTATX_STAT3(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_dstat#_stat4
 *
 * PKI Dropped Octets Deep Statistic Registers
 * This register contains statistics indexed by PKI_QPG_TBLB()[DSTAT_ID].
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_dstatx_stat4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t drp_octs              : 40; /**< [ 39:  0](R/W/H) Inbound octets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP].
                                                                 The corresponding wide statistic is PKI_STAT()_STAT4. */
#else /* Word 0 - Little Endian */
        uint64_t drp_octs              : 40; /**< [ 39:  0](R/W/H) Inbound octets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP].
                                                                 The corresponding wide statistic is PKI_STAT()_STAT4. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_dstatx_stat4_s cn; */
} bdk_pki_dstatx_stat4_t;

static inline uint64_t BDK_PKI_DSTATX_STAT4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_DSTATX_STAT4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x86c000c00020ll + 0x40ll * ((a) & 0x3ff);
    __bdk_csr_fatal("PKI_DSTATX_STAT4", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_DSTATX_STAT4(a) bdk_pki_dstatx_stat4_t
#define bustype_BDK_PKI_DSTATX_STAT4(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_DSTATX_STAT4(a) "PKI_DSTATX_STAT4"
#define device_bar_BDK_PKI_DSTATX_STAT4(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_DSTATX_STAT4(a) (a)
#define arguments_BDK_PKI_DSTATX_STAT4(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_ecc_ctl0
 *
 * PKI ECC Control 0 Register
 * This register allows inserting ECC errors for testing.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t ldfif_flip            : 2;  /**< [ 23: 22](R/W) LDFIF RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the LDFIF ram
                                                                 to test single-bit or double-bit error handling. */
        uint64_t ldfif_cdis            : 1;  /**< [ 21: 21](R/W) LDFIF RAM ECC correction disable. */
        uint64_t pbe_flip              : 2;  /**< [ 20: 19](R/W) PBE state RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the PBE
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t pbe_cdis              : 1;  /**< [ 18: 18](R/W) PBE state RAM ECC correction disable. */
        uint64_t wadr_flip             : 2;  /**< [ 17: 16](R/W) WADR RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the WADR ram
                                                                 to test single-bit or double-bit error handling. */
        uint64_t wadr_cdis             : 1;  /**< [ 15: 15](R/W) WADR RAM ECC correction disable. */
        uint64_t nxtptag_flip          : 2;  /**< [ 14: 13](R/W) NXTPTAG RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the NXTPTAG
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t nxtptag_cdis          : 1;  /**< [ 12: 12](R/W) NXTPTAG RAM ECC correction disable. */
        uint64_t curptag_flip          : 2;  /**< [ 11: 10](R/W) CURPTAG RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the CURPTAG
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t curptag_cdis          : 1;  /**< [  9:  9](R/W) CURPTAG RAM ECC correction disable. */
        uint64_t nxtblk_flip           : 2;  /**< [  8:  7](R/W) NXTBLK RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the NXTBLK
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t nxtblk_cdis           : 1;  /**< [  6:  6](R/W) NXTBLK RAM ECC correction disable. */
        uint64_t kmem_flip             : 2;  /**< [  5:  4](R/W) KMEM RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the KMEM ram
                                                                 to test single-bit or double-bit error handling. */
        uint64_t kmem_cdis             : 1;  /**< [  3:  3](R/W) KMEM RAM ECC correction disable. */
        uint64_t asm_flip              : 2;  /**< [  2:  1](R/W) ASM RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ASM ram to
                                                                 test single-bit or double-bit error handling. */
        uint64_t asm_cdis              : 1;  /**< [  0:  0](R/W) ASM RAM ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t asm_cdis              : 1;  /**< [  0:  0](R/W) ASM RAM ECC correction disable. */
        uint64_t asm_flip              : 2;  /**< [  2:  1](R/W) ASM RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ASM ram to
                                                                 test single-bit or double-bit error handling. */
        uint64_t kmem_cdis             : 1;  /**< [  3:  3](R/W) KMEM RAM ECC correction disable. */
        uint64_t kmem_flip             : 2;  /**< [  5:  4](R/W) KMEM RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the KMEM ram
                                                                 to test single-bit or double-bit error handling. */
        uint64_t nxtblk_cdis           : 1;  /**< [  6:  6](R/W) NXTBLK RAM ECC correction disable. */
        uint64_t nxtblk_flip           : 2;  /**< [  8:  7](R/W) NXTBLK RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the NXTBLK
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t curptag_cdis          : 1;  /**< [  9:  9](R/W) CURPTAG RAM ECC correction disable. */
        uint64_t curptag_flip          : 2;  /**< [ 11: 10](R/W) CURPTAG RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the CURPTAG
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t nxtptag_cdis          : 1;  /**< [ 12: 12](R/W) NXTPTAG RAM ECC correction disable. */
        uint64_t nxtptag_flip          : 2;  /**< [ 14: 13](R/W) NXTPTAG RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the NXTPTAG
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t wadr_cdis             : 1;  /**< [ 15: 15](R/W) WADR RAM ECC correction disable. */
        uint64_t wadr_flip             : 2;  /**< [ 17: 16](R/W) WADR RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the WADR ram
                                                                 to test single-bit or double-bit error handling. */
        uint64_t pbe_cdis              : 1;  /**< [ 18: 18](R/W) PBE state RAM ECC correction disable. */
        uint64_t pbe_flip              : 2;  /**< [ 20: 19](R/W) PBE state RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the PBE
                                                                 ram to test single-bit or double-bit error handling. */
        uint64_t ldfif_cdis            : 1;  /**< [ 21: 21](R/W) LDFIF RAM ECC correction disable. */
        uint64_t ldfif_flip            : 2;  /**< [ 23: 22](R/W) LDFIF RAM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the LDFIF ram
                                                                 to test single-bit or double-bit error handling. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_ctl0_s cn; */
} bdk_pki_ecc_ctl0_t;

#define BDK_PKI_ECC_CTL0 BDK_PKI_ECC_CTL0_FUNC()
static inline uint64_t BDK_PKI_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000060ll;
    __bdk_csr_fatal("PKI_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_CTL0 bdk_pki_ecc_ctl0_t
#define bustype_BDK_PKI_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_CTL0 "PKI_ECC_CTL0"
#define device_bar_BDK_PKI_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_CTL0 0
#define arguments_BDK_PKI_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_ctl1
 *
 * PKI ECC Control 1 Register
 * This register allows inserting ECC errors for testing.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t sws_flip              : 2;  /**< [ 50: 49](R/W) SWS flip syndrome bits on write. */
        uint64_t sws_cdis              : 1;  /**< [ 48: 48](R/W) SWS ECC correction disable. */
        uint64_t wqeout_flip           : 2;  /**< [ 47: 46](R/W) WQEOUT flip syndrome bits on write. */
        uint64_t wqeout_cdis           : 1;  /**< [ 45: 45](R/W) WQEOUT ECC correction disable. */
        uint64_t doa_flip              : 2;  /**< [ 44: 43](R/W) DOA flip syndrome bits on write. */
        uint64_t doa_cdis              : 1;  /**< [ 42: 42](R/W) DOA ECC correction disable. */
        uint64_t bpid_flip             : 2;  /**< [ 41: 40](R/W) BPID flip syndrome bits on write. */
        uint64_t bpid_cdis             : 1;  /**< [ 39: 39](R/W) BPID ECC correction disable. */
        uint64_t reserved_30_38        : 9;
        uint64_t plc_flip              : 2;  /**< [ 29: 28](R/W) PLC flip syndrome bits on write. */
        uint64_t plc_cdis              : 1;  /**< [ 27: 27](R/W) PLC ECC correction disable. */
        uint64_t pktwq_flip            : 2;  /**< [ 26: 25](R/W) PKTWQ flip syndrome bits on write. */
        uint64_t pktwq_cdis            : 1;  /**< [ 24: 24](R/W) PKTWQ ECC correction disable. */
        uint64_t reserved_21_23        : 3;
        uint64_t stylewq2_flip         : 2;  /**< [ 20: 19](R/W) STYLEWQ2 flip syndrome bits on write. */
        uint64_t stylewq2_cdis         : 1;  /**< [ 18: 18](R/W) STYLEWQ2 ECC correction disable. */
        uint64_t tag_flip              : 2;  /**< [ 17: 16](R/W) TAG flip syndrome bits on write. */
        uint64_t tag_cdis              : 1;  /**< [ 15: 15](R/W) TAG ECC correction disable. */
        uint64_t aura_flip             : 2;  /**< [ 14: 13](R/W) AURA flip syndrome bits on write. */
        uint64_t aura_cdis             : 1;  /**< [ 12: 12](R/W) AURA ECC correction disable. */
        uint64_t chan_flip             : 2;  /**< [ 11: 10](R/W) CHAN flip syndrome bits on write. */
        uint64_t chan_cdis             : 1;  /**< [  9:  9](R/W) CHAN ECC correction disable. */
        uint64_t pbtag_flip            : 2;  /**< [  8:  7](R/W) PBTAG flip syndrome bits on write. */
        uint64_t pbtag_cdis            : 1;  /**< [  6:  6](R/W) PBTAG ECC correction disable. */
        uint64_t stylewq_flip          : 2;  /**< [  5:  4](R/W) STYLEWQ flip syndrome bits on write. */
        uint64_t stylewq_cdis          : 1;  /**< [  3:  3](R/W) STYLEWQ ECC correction disable. */
        uint64_t qpg_flip              : 2;  /**< [  2:  1](R/W) QPG flip syndrome bits on write. */
        uint64_t qpg_cdis              : 1;  /**< [  0:  0](R/W) QPG ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t qpg_cdis              : 1;  /**< [  0:  0](R/W) QPG ECC correction disable. */
        uint64_t qpg_flip              : 2;  /**< [  2:  1](R/W) QPG flip syndrome bits on write. */
        uint64_t stylewq_cdis          : 1;  /**< [  3:  3](R/W) STYLEWQ ECC correction disable. */
        uint64_t stylewq_flip          : 2;  /**< [  5:  4](R/W) STYLEWQ flip syndrome bits on write. */
        uint64_t pbtag_cdis            : 1;  /**< [  6:  6](R/W) PBTAG ECC correction disable. */
        uint64_t pbtag_flip            : 2;  /**< [  8:  7](R/W) PBTAG flip syndrome bits on write. */
        uint64_t chan_cdis             : 1;  /**< [  9:  9](R/W) CHAN ECC correction disable. */
        uint64_t chan_flip             : 2;  /**< [ 11: 10](R/W) CHAN flip syndrome bits on write. */
        uint64_t aura_cdis             : 1;  /**< [ 12: 12](R/W) AURA ECC correction disable. */
        uint64_t aura_flip             : 2;  /**< [ 14: 13](R/W) AURA flip syndrome bits on write. */
        uint64_t tag_cdis              : 1;  /**< [ 15: 15](R/W) TAG ECC correction disable. */
        uint64_t tag_flip              : 2;  /**< [ 17: 16](R/W) TAG flip syndrome bits on write. */
        uint64_t stylewq2_cdis         : 1;  /**< [ 18: 18](R/W) STYLEWQ2 ECC correction disable. */
        uint64_t stylewq2_flip         : 2;  /**< [ 20: 19](R/W) STYLEWQ2 flip syndrome bits on write. */
        uint64_t reserved_21_23        : 3;
        uint64_t pktwq_cdis            : 1;  /**< [ 24: 24](R/W) PKTWQ ECC correction disable. */
        uint64_t pktwq_flip            : 2;  /**< [ 26: 25](R/W) PKTWQ flip syndrome bits on write. */
        uint64_t plc_cdis              : 1;  /**< [ 27: 27](R/W) PLC ECC correction disable. */
        uint64_t plc_flip              : 2;  /**< [ 29: 28](R/W) PLC flip syndrome bits on write. */
        uint64_t reserved_30_38        : 9;
        uint64_t bpid_cdis             : 1;  /**< [ 39: 39](R/W) BPID ECC correction disable. */
        uint64_t bpid_flip             : 2;  /**< [ 41: 40](R/W) BPID flip syndrome bits on write. */
        uint64_t doa_cdis              : 1;  /**< [ 42: 42](R/W) DOA ECC correction disable. */
        uint64_t doa_flip              : 2;  /**< [ 44: 43](R/W) DOA flip syndrome bits on write. */
        uint64_t wqeout_cdis           : 1;  /**< [ 45: 45](R/W) WQEOUT ECC correction disable. */
        uint64_t wqeout_flip           : 2;  /**< [ 47: 46](R/W) WQEOUT flip syndrome bits on write. */
        uint64_t sws_cdis              : 1;  /**< [ 48: 48](R/W) SWS ECC correction disable. */
        uint64_t sws_flip              : 2;  /**< [ 50: 49](R/W) SWS flip syndrome bits on write. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_ctl1_s cn; */
} bdk_pki_ecc_ctl1_t;

#define BDK_PKI_ECC_CTL1 BDK_PKI_ECC_CTL1_FUNC()
static inline uint64_t BDK_PKI_ECC_CTL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_CTL1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000068ll;
    __bdk_csr_fatal("PKI_ECC_CTL1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_CTL1 bdk_pki_ecc_ctl1_t
#define bustype_BDK_PKI_ECC_CTL1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_CTL1 "PKI_ECC_CTL1"
#define device_bar_BDK_PKI_ECC_CTL1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_CTL1 0
#define arguments_BDK_PKI_ECC_CTL1 -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_ctl2
 *
 * PKI ECC Control 2 Register
 * This register allows inserting ECC errors for testing.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t imem_flip             : 2;  /**< [  2:  1](R/W) KMEM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the KMEM ram to
                                                                 test single-bit or double-bit error handling. */
        uint64_t imem_cdis             : 1;  /**< [  0:  0](R/W) IMEM ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t imem_cdis             : 1;  /**< [  0:  0](R/W) IMEM ECC correction disable. */
        uint64_t imem_flip             : 2;  /**< [  2:  1](R/W) KMEM flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the KMEM ram to
                                                                 test single-bit or double-bit error handling. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_ctl2_s cn; */
} bdk_pki_ecc_ctl2_t;

#define BDK_PKI_ECC_CTL2 BDK_PKI_ECC_CTL2_FUNC()
static inline uint64_t BDK_PKI_ECC_CTL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_CTL2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000070ll;
    __bdk_csr_fatal("PKI_ECC_CTL2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_CTL2 bdk_pki_ecc_ctl2_t
#define bustype_BDK_PKI_ECC_CTL2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_CTL2 "PKI_ECC_CTL2"
#define device_bar_BDK_PKI_ECC_CTL2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_CTL2 0
#define arguments_BDK_PKI_ECC_CTL2 -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int0
 *
 * PKI ECC Interrupt 0 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1C/H) LDFIF ECC double bit error. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1C/H) LDFIF ECC single bit error. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1C/H) PBE ECC double bit error. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1C/H) PBE ECC single bit error. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1C/H) WADR ECC double bit error. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1C/H) WADR ECC single bit error. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1C/H) NXTPTAG ECC double bit error. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1C/H) NXTPTAG ECC single bit error. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1C/H) CURPTAG ECC double bit error. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1C/H) CURPTAG ECC single bit error. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1C/H) NXTBLK ECC double bit error. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1C/H) NXTBLK ECC single bit error. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1C/H) KMEM ECC double bit error. If KMEM_DBE is
                                                                 thrown, software may scrub the error by reloading PKI_CL()_PKIND()_KMEM(). */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1C/H) KMEM ECC single bit error. If KMEM_SBE is
                                                                 thrown, software may scrub the error by reloading PKI_CL()_PKIND()_KMEM(). */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1C/H) ASM ECC double bit error. */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1C/H) ASM ECC single bit error. */
#else /* Word 0 - Little Endian */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1C/H) ASM ECC single bit error. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1C/H) ASM ECC double bit error. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1C/H) KMEM ECC single bit error. If KMEM_SBE is
                                                                 thrown, software may scrub the error by reloading PKI_CL()_PKIND()_KMEM(). */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1C/H) KMEM ECC double bit error. If KMEM_DBE is
                                                                 thrown, software may scrub the error by reloading PKI_CL()_PKIND()_KMEM(). */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1C/H) NXTBLK ECC single bit error. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1C/H) NXTBLK ECC double bit error. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1C/H) CURPTAG ECC single bit error. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1C/H) CURPTAG ECC double bit error. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1C/H) NXTPTAG ECC single bit error. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1C/H) NXTPTAG ECC double bit error. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1C/H) WADR ECC single bit error. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1C/H) WADR ECC double bit error. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1C/H) PBE ECC single bit error. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1C/H) PBE ECC double bit error. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1C/H) LDFIF ECC single bit error. */
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1C/H) LDFIF ECC double bit error. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int0_s cn; */
} bdk_pki_ecc_int0_t;

#define BDK_PKI_ECC_INT0 BDK_PKI_ECC_INT0_FUNC()
static inline uint64_t BDK_PKI_ECC_INT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000840ll;
    __bdk_csr_fatal("PKI_ECC_INT0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT0 bdk_pki_ecc_int0_t
#define bustype_BDK_PKI_ECC_INT0 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT0 "PKI_ECC_INT0"
#define device_bar_BDK_PKI_ECC_INT0 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT0 0
#define arguments_BDK_PKI_ECC_INT0 -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int0_ena_w1c
 *
 * PKI ECC 0 Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int0_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[LDFIF_DBE]. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[LDFIF_SBE]. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[PBE_DBE]. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[PBE_SBE]. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[WADR_DBE]. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[WADR_SBE]. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTPTAG_DBE]. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTPTAG_SBE]. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[CURPTAG_DBE]. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[CURPTAG_SBE]. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTBLK_DBE]. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTBLK_SBE]. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[KMEM_DBE]. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[KMEM_SBE]. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[ASM_DBE]. */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[ASM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[ASM_SBE]. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[ASM_DBE]. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[KMEM_SBE]. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[KMEM_DBE]. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTBLK_SBE]. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTBLK_DBE]. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[CURPTAG_SBE]. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[CURPTAG_DBE]. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTPTAG_SBE]. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[NXTPTAG_DBE]. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[WADR_SBE]. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[WADR_DBE]. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[PBE_SBE]. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[PBE_DBE]. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[LDFIF_SBE]. */
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PKI_ECC_INT0[LDFIF_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int0_ena_w1c_s cn; */
} bdk_pki_ecc_int0_ena_w1c_t;

#define BDK_PKI_ECC_INT0_ENA_W1C BDK_PKI_ECC_INT0_ENA_W1C_FUNC()
static inline uint64_t BDK_PKI_ECC_INT0_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT0_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000860ll;
    __bdk_csr_fatal("PKI_ECC_INT0_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT0_ENA_W1C bdk_pki_ecc_int0_ena_w1c_t
#define bustype_BDK_PKI_ECC_INT0_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT0_ENA_W1C "PKI_ECC_INT0_ENA_W1C"
#define device_bar_BDK_PKI_ECC_INT0_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT0_ENA_W1C 0
#define arguments_BDK_PKI_ECC_INT0_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int0_ena_w1s
 *
 * PKI ECC 0 Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int0_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[LDFIF_DBE]. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[LDFIF_SBE]. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[PBE_DBE]. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[PBE_SBE]. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[WADR_DBE]. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[WADR_SBE]. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTPTAG_DBE]. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTPTAG_SBE]. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[CURPTAG_DBE]. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[CURPTAG_SBE]. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTBLK_DBE]. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTBLK_SBE]. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[KMEM_DBE]. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[KMEM_SBE]. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[ASM_DBE]. */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[ASM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[ASM_SBE]. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[ASM_DBE]. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[KMEM_SBE]. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[KMEM_DBE]. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTBLK_SBE]. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTBLK_DBE]. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[CURPTAG_SBE]. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[CURPTAG_DBE]. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTPTAG_SBE]. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[NXTPTAG_DBE]. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[WADR_SBE]. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[WADR_DBE]. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[PBE_SBE]. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[PBE_DBE]. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[LDFIF_SBE]. */
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PKI_ECC_INT0[LDFIF_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int0_ena_w1s_s cn; */
} bdk_pki_ecc_int0_ena_w1s_t;

#define BDK_PKI_ECC_INT0_ENA_W1S BDK_PKI_ECC_INT0_ENA_W1S_FUNC()
static inline uint64_t BDK_PKI_ECC_INT0_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT0_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000870ll;
    __bdk_csr_fatal("PKI_ECC_INT0_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT0_ENA_W1S bdk_pki_ecc_int0_ena_w1s_t
#define bustype_BDK_PKI_ECC_INT0_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT0_ENA_W1S "PKI_ECC_INT0_ENA_W1S"
#define device_bar_BDK_PKI_ECC_INT0_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT0_ENA_W1S 0
#define arguments_BDK_PKI_ECC_INT0_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int0_w1s
 *
 * PKI ECC 0 Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int0_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PKI_ECC_INT0[LDFIF_DBE]. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PKI_ECC_INT0[LDFIF_SBE]. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PKI_ECC_INT0[PBE_DBE]. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PKI_ECC_INT0[PBE_SBE]. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PKI_ECC_INT0[WADR_DBE]. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PKI_ECC_INT0[WADR_SBE]. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTPTAG_DBE]. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTPTAG_SBE]. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_ECC_INT0[CURPTAG_DBE]. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_ECC_INT0[CURPTAG_SBE]. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTBLK_DBE]. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTBLK_SBE]. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_ECC_INT0[KMEM_DBE]. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_ECC_INT0[KMEM_SBE]. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_ECC_INT0[ASM_DBE]. */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_ECC_INT0[ASM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t asm_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_ECC_INT0[ASM_SBE]. */
        uint64_t asm_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_ECC_INT0[ASM_DBE]. */
        uint64_t kmem_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_ECC_INT0[KMEM_SBE]. */
        uint64_t kmem_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_ECC_INT0[KMEM_DBE]. */
        uint64_t nxtblk_sbe            : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTBLK_SBE]. */
        uint64_t nxtblk_dbe            : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTBLK_DBE]. */
        uint64_t curptag_sbe           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_ECC_INT0[CURPTAG_SBE]. */
        uint64_t curptag_dbe           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_ECC_INT0[CURPTAG_DBE]. */
        uint64_t nxtptag_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTPTAG_SBE]. */
        uint64_t nxtptag_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PKI_ECC_INT0[NXTPTAG_DBE]. */
        uint64_t wadr_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PKI_ECC_INT0[WADR_SBE]. */
        uint64_t wadr_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PKI_ECC_INT0[WADR_DBE]. */
        uint64_t pbe_sbe               : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PKI_ECC_INT0[PBE_SBE]. */
        uint64_t pbe_dbe               : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PKI_ECC_INT0[PBE_DBE]. */
        uint64_t ldfif_sbe             : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PKI_ECC_INT0[LDFIF_SBE]. */
        uint64_t ldfif_dbe             : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PKI_ECC_INT0[LDFIF_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int0_w1s_s cn; */
} bdk_pki_ecc_int0_w1s_t;

#define BDK_PKI_ECC_INT0_W1S BDK_PKI_ECC_INT0_W1S_FUNC()
static inline uint64_t BDK_PKI_ECC_INT0_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT0_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000850ll;
    __bdk_csr_fatal("PKI_ECC_INT0_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT0_W1S bdk_pki_ecc_int0_w1s_t
#define bustype_BDK_PKI_ECC_INT0_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT0_W1S "PKI_ECC_INT0_W1S"
#define device_bar_BDK_PKI_ECC_INT0_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT0_W1S 0
#define arguments_BDK_PKI_ECC_INT0_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int1
 *
 * PKI ECC Interrupt 1 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1C/H) PLC ECC double bit error. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1C/H) PLC ECC single bit error. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1C/H) PLC ECC double bit error. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1C/H) PLC ECC single bit error. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1C/H) PLC ECC double bit error. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1C/H) PLC ECC single bit error. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1C/H) PLC ECC double bit error. */
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1C/H) PLC ECC single bit error. */
        uint64_t reserved_20_25        : 6;
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1C/H) PLC ECC double bit error. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1C/H) PLC ECC single bit error. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1C/H) PKTWQ ECC double bit error. */
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1C/H) PKTWQ ECC single bit error. */
        uint64_t reserved_12_15        : 4;
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1C/H) TAG ECC double bit error. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1C/H) TAG ECC single bit error. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1C/H) AURA ECC double bit error. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1C/H) AURA ECC single bit error. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1C/H) CHAN ECC double bit error. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1C/H) CHAN ECC single bit error. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1C/H) PBTAG ECC double bit error. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1C/H) PBTAG ECC single bit error. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1C/H) STYLEWQ ECC double bit error. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1C/H) STYLEWQ ECC single bit error. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1C/H) QPG ECC double bit error. */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1C/H) QPG ECC single bit error. */
#else /* Word 0 - Little Endian */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1C/H) QPG ECC single bit error. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1C/H) QPG ECC double bit error. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1C/H) STYLEWQ ECC single bit error. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1C/H) STYLEWQ ECC double bit error. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1C/H) PBTAG ECC single bit error. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1C/H) PBTAG ECC double bit error. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1C/H) CHAN ECC single bit error. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1C/H) CHAN ECC double bit error. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1C/H) AURA ECC single bit error. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1C/H) AURA ECC double bit error. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1C/H) TAG ECC single bit error. */
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1C/H) TAG ECC double bit error. */
        uint64_t reserved_12_15        : 4;
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1C/H) PKTWQ ECC single bit error. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1C/H) PKTWQ ECC double bit error. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1C/H) PLC ECC single bit error. */
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1C/H) PLC ECC double bit error. */
        uint64_t reserved_20_25        : 6;
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1C/H) PLC ECC single bit error. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1C/H) PLC ECC double bit error. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1C/H) PLC ECC single bit error. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1C/H) PLC ECC double bit error. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1C/H) PLC ECC single bit error. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1C/H) PLC ECC double bit error. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1C/H) PLC ECC single bit error. */
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1C/H) PLC ECC double bit error. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int1_s cn; */
} bdk_pki_ecc_int1_t;

#define BDK_PKI_ECC_INT1 BDK_PKI_ECC_INT1_FUNC()
static inline uint64_t BDK_PKI_ECC_INT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000880ll;
    __bdk_csr_fatal("PKI_ECC_INT1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT1 bdk_pki_ecc_int1_t
#define bustype_BDK_PKI_ECC_INT1 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT1 "PKI_ECC_INT1"
#define device_bar_BDK_PKI_ECC_INT1 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT1 0
#define arguments_BDK_PKI_ECC_INT1 -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int1_ena_w1c
 *
 * PKI ECC 1 Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int1_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[SWS_DBE]. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[SWS_SBE]. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[WQEOUT_DBE]. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[WQEOUT_SBE]. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[DOA_DBE]. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[DOA_SBE]. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[BPID_DBE]. */
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[BPID_SBE]. */
        uint64_t reserved_20_25        : 6;
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PLC_DBE]. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PLC_SBE]. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PKTWQ_DBE]. */
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PKTWQ_SBE]. */
        uint64_t reserved_12_15        : 4;
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[TAG_DBE]. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[TAG_SBE]. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[AURA_DBE]. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[AURA_SBE]. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[CHAN_DBE]. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[CHAN_SBE]. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PBTAG_DBE]. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PBTAG_SBE]. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[STYLEWQ_DBE]. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[STYLEWQ_SBE]. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[QPG_DBE]. */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[QPG_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[QPG_SBE]. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[QPG_DBE]. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[STYLEWQ_SBE]. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[STYLEWQ_DBE]. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PBTAG_SBE]. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PBTAG_DBE]. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[CHAN_SBE]. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[CHAN_DBE]. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[AURA_SBE]. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[AURA_DBE]. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[TAG_SBE]. */
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[TAG_DBE]. */
        uint64_t reserved_12_15        : 4;
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PKTWQ_SBE]. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PKTWQ_DBE]. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PLC_SBE]. */
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[PLC_DBE]. */
        uint64_t reserved_20_25        : 6;
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[BPID_SBE]. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[BPID_DBE]. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[DOA_SBE]. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[DOA_DBE]. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[WQEOUT_SBE]. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[WQEOUT_DBE]. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[SWS_SBE]. */
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PKI_ECC_INT1[SWS_DBE]. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int1_ena_w1c_s cn; */
} bdk_pki_ecc_int1_ena_w1c_t;

#define BDK_PKI_ECC_INT1_ENA_W1C BDK_PKI_ECC_INT1_ENA_W1C_FUNC()
static inline uint64_t BDK_PKI_ECC_INT1_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT1_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c0000008a0ll;
    __bdk_csr_fatal("PKI_ECC_INT1_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT1_ENA_W1C bdk_pki_ecc_int1_ena_w1c_t
#define bustype_BDK_PKI_ECC_INT1_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT1_ENA_W1C "PKI_ECC_INT1_ENA_W1C"
#define device_bar_BDK_PKI_ECC_INT1_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT1_ENA_W1C 0
#define arguments_BDK_PKI_ECC_INT1_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int1_ena_w1s
 *
 * PKI ECC 1 Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int1_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[SWS_DBE]. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[SWS_SBE]. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[WQEOUT_DBE]. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[WQEOUT_SBE]. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[DOA_DBE]. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[DOA_SBE]. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[BPID_DBE]. */
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[BPID_SBE]. */
        uint64_t reserved_20_25        : 6;
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PLC_DBE]. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PLC_SBE]. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PKTWQ_DBE]. */
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PKTWQ_SBE]. */
        uint64_t reserved_12_15        : 4;
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[TAG_DBE]. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[TAG_SBE]. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[AURA_DBE]. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[AURA_SBE]. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[CHAN_DBE]. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[CHAN_SBE]. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PBTAG_DBE]. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PBTAG_SBE]. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[STYLEWQ_DBE]. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[STYLEWQ_SBE]. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[QPG_DBE]. */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[QPG_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[QPG_SBE]. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[QPG_DBE]. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[STYLEWQ_SBE]. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[STYLEWQ_DBE]. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PBTAG_SBE]. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PBTAG_DBE]. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[CHAN_SBE]. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[CHAN_DBE]. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[AURA_SBE]. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[AURA_DBE]. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[TAG_SBE]. */
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[TAG_DBE]. */
        uint64_t reserved_12_15        : 4;
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PKTWQ_SBE]. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PKTWQ_DBE]. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PLC_SBE]. */
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[PLC_DBE]. */
        uint64_t reserved_20_25        : 6;
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[BPID_SBE]. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[BPID_DBE]. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[DOA_SBE]. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[DOA_DBE]. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[WQEOUT_SBE]. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[WQEOUT_DBE]. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[SWS_SBE]. */
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PKI_ECC_INT1[SWS_DBE]. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int1_ena_w1s_s cn; */
} bdk_pki_ecc_int1_ena_w1s_t;

#define BDK_PKI_ECC_INT1_ENA_W1S BDK_PKI_ECC_INT1_ENA_W1S_FUNC()
static inline uint64_t BDK_PKI_ECC_INT1_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT1_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c0000008b0ll;
    __bdk_csr_fatal("PKI_ECC_INT1_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT1_ENA_W1S bdk_pki_ecc_int1_ena_w1s_t
#define bustype_BDK_PKI_ECC_INT1_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT1_ENA_W1S "PKI_ECC_INT1_ENA_W1S"
#define device_bar_BDK_PKI_ECC_INT1_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT1_ENA_W1S 0
#define arguments_BDK_PKI_ECC_INT1_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int1_w1s
 *
 * PKI ECC 1 Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int1_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PKI_ECC_INT1[SWS_DBE]. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PKI_ECC_INT1[SWS_SBE]. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PKI_ECC_INT1[WQEOUT_DBE]. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PKI_ECC_INT1[WQEOUT_SBE]. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PKI_ECC_INT1[DOA_DBE]. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PKI_ECC_INT1[DOA_SBE]. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PKI_ECC_INT1[BPID_DBE]. */
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PKI_ECC_INT1[BPID_SBE]. */
        uint64_t reserved_20_25        : 6;
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PKI_ECC_INT1[PLC_DBE]. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PKI_ECC_INT1[PLC_SBE]. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PKI_ECC_INT1[PKTWQ_DBE]. */
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PKI_ECC_INT1[PKTWQ_SBE]. */
        uint64_t reserved_12_15        : 4;
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PKI_ECC_INT1[TAG_DBE]. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PKI_ECC_INT1[TAG_SBE]. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PKI_ECC_INT1[AURA_DBE]. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PKI_ECC_INT1[AURA_SBE]. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_ECC_INT1[CHAN_DBE]. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_ECC_INT1[CHAN_SBE]. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_ECC_INT1[PBTAG_DBE]. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_ECC_INT1[PBTAG_SBE]. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_ECC_INT1[STYLEWQ_DBE]. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_ECC_INT1[STYLEWQ_SBE]. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_ECC_INT1[QPG_DBE]. */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_ECC_INT1[QPG_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t qpg_sbe               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_ECC_INT1[QPG_SBE]. */
        uint64_t qpg_dbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_ECC_INT1[QPG_DBE]. */
        uint64_t stylewq_sbe           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_ECC_INT1[STYLEWQ_SBE]. */
        uint64_t stylewq_dbe           : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_ECC_INT1[STYLEWQ_DBE]. */
        uint64_t pbtag_sbe             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_ECC_INT1[PBTAG_SBE]. */
        uint64_t pbtag_dbe             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_ECC_INT1[PBTAG_DBE]. */
        uint64_t chan_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_ECC_INT1[CHAN_SBE]. */
        uint64_t chan_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_ECC_INT1[CHAN_DBE]. */
        uint64_t aura_sbe              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PKI_ECC_INT1[AURA_SBE]. */
        uint64_t aura_dbe              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PKI_ECC_INT1[AURA_DBE]. */
        uint64_t tag_sbe               : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PKI_ECC_INT1[TAG_SBE]. */
        uint64_t tag_dbe               : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PKI_ECC_INT1[TAG_DBE]. */
        uint64_t reserved_12_15        : 4;
        uint64_t pktwq_sbe             : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PKI_ECC_INT1[PKTWQ_SBE]. */
        uint64_t pktwq_dbe             : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PKI_ECC_INT1[PKTWQ_DBE]. */
        uint64_t plc_sbe               : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PKI_ECC_INT1[PLC_SBE]. */
        uint64_t plc_dbe               : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PKI_ECC_INT1[PLC_DBE]. */
        uint64_t reserved_20_25        : 6;
        uint64_t bpid_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PKI_ECC_INT1[BPID_SBE]. */
        uint64_t bpid_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PKI_ECC_INT1[BPID_DBE]. */
        uint64_t doa_sbe               : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PKI_ECC_INT1[DOA_SBE]. */
        uint64_t doa_dbe               : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PKI_ECC_INT1[DOA_DBE]. */
        uint64_t wqeout_sbe            : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PKI_ECC_INT1[WQEOUT_SBE]. */
        uint64_t wqeout_dbe            : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PKI_ECC_INT1[WQEOUT_DBE]. */
        uint64_t sws_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PKI_ECC_INT1[SWS_SBE]. */
        uint64_t sws_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PKI_ECC_INT1[SWS_DBE]. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int1_w1s_s cn; */
} bdk_pki_ecc_int1_w1s_t;

#define BDK_PKI_ECC_INT1_W1S BDK_PKI_ECC_INT1_W1S_FUNC()
static inline uint64_t BDK_PKI_ECC_INT1_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT1_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000890ll;
    __bdk_csr_fatal("PKI_ECC_INT1_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT1_W1S bdk_pki_ecc_int1_w1s_t
#define bustype_BDK_PKI_ECC_INT1_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT1_W1S "PKI_ECC_INT1_W1S"
#define device_bar_BDK_PKI_ECC_INT1_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT1_W1S 0
#define arguments_BDK_PKI_ECC_INT1_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int2
 *
 * PKI ECC Interrupt 2 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1C/H) IMEM ECC double bit error. If IMEM_DBE is
                                                                 thrown, software may scrub the error by reloading PKI_IMEM(). */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1C/H) IMEM ECC single bit error. If IMEM_SBE is
                                                                 thrown, software may scrub the error by reloading PKI_IMEM(). */
#else /* Word 0 - Little Endian */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1C/H) IMEM ECC single bit error. If IMEM_SBE is
                                                                 thrown, software may scrub the error by reloading PKI_IMEM(). */
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1C/H) IMEM ECC double bit error. If IMEM_DBE is
                                                                 thrown, software may scrub the error by reloading PKI_IMEM(). */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int2_s cn; */
} bdk_pki_ecc_int2_t;

#define BDK_PKI_ECC_INT2 BDK_PKI_ECC_INT2_FUNC()
static inline uint64_t BDK_PKI_ECC_INT2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c0000008c0ll;
    __bdk_csr_fatal("PKI_ECC_INT2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT2 bdk_pki_ecc_int2_t
#define bustype_BDK_PKI_ECC_INT2 BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT2 "PKI_ECC_INT2"
#define device_bar_BDK_PKI_ECC_INT2 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT2 0
#define arguments_BDK_PKI_ECC_INT2 -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int2_ena_w1c
 *
 * PKI ECC 2 Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int2_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_ECC_INT2[IMEM_DBE]. */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_ECC_INT2[IMEM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_ECC_INT2[IMEM_SBE]. */
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_ECC_INT2[IMEM_DBE]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int2_ena_w1c_s cn; */
} bdk_pki_ecc_int2_ena_w1c_t;

#define BDK_PKI_ECC_INT2_ENA_W1C BDK_PKI_ECC_INT2_ENA_W1C_FUNC()
static inline uint64_t BDK_PKI_ECC_INT2_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT2_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c0000008e0ll;
    __bdk_csr_fatal("PKI_ECC_INT2_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT2_ENA_W1C bdk_pki_ecc_int2_ena_w1c_t
#define bustype_BDK_PKI_ECC_INT2_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT2_ENA_W1C "PKI_ECC_INT2_ENA_W1C"
#define device_bar_BDK_PKI_ECC_INT2_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT2_ENA_W1C 0
#define arguments_BDK_PKI_ECC_INT2_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int2_ena_w1s
 *
 * PKI ECC 2 Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int2_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_ECC_INT2[IMEM_DBE]. */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_ECC_INT2[IMEM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_ECC_INT2[IMEM_SBE]. */
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_ECC_INT2[IMEM_DBE]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int2_ena_w1s_s cn; */
} bdk_pki_ecc_int2_ena_w1s_t;

#define BDK_PKI_ECC_INT2_ENA_W1S BDK_PKI_ECC_INT2_ENA_W1S_FUNC()
static inline uint64_t BDK_PKI_ECC_INT2_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT2_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c0000008f0ll;
    __bdk_csr_fatal("PKI_ECC_INT2_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT2_ENA_W1S bdk_pki_ecc_int2_ena_w1s_t
#define bustype_BDK_PKI_ECC_INT2_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT2_ENA_W1S "PKI_ECC_INT2_ENA_W1S"
#define device_bar_BDK_PKI_ECC_INT2_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT2_ENA_W1S 0
#define arguments_BDK_PKI_ECC_INT2_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_ecc_int2_w1s
 *
 * PKI ECC 2 Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ecc_int2_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_ECC_INT2[IMEM_DBE]. */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_ECC_INT2[IMEM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t imem_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_ECC_INT2[IMEM_SBE]. */
        uint64_t imem_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_ECC_INT2[IMEM_DBE]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ecc_int2_w1s_s cn; */
} bdk_pki_ecc_int2_w1s_t;

#define BDK_PKI_ECC_INT2_W1S BDK_PKI_ECC_INT2_W1S_FUNC()
static inline uint64_t BDK_PKI_ECC_INT2_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ECC_INT2_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c0000008d0ll;
    __bdk_csr_fatal("PKI_ECC_INT2_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_ECC_INT2_W1S bdk_pki_ecc_int2_w1s_t
#define bustype_BDK_PKI_ECC_INT2_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ECC_INT2_W1S "PKI_ECC_INT2_W1S"
#define device_bar_BDK_PKI_ECC_INT2_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ECC_INT2_W1S 0
#define arguments_BDK_PKI_ECC_INT2_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_frm_len_chk#
 *
 * PKI Frame Length Check Registers
 * Internal:
 * INTERNAL: This doesn't virtualize well, but we don't anticipate many sizes.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_frm_len_chkx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t maxlen                : 16; /**< [ 31: 16](R/W) Byte count for max-sized frame check. */
        uint64_t minlen                : 16; /**< [ 15:  0](R/W) Byte count for min-sized frame check. */
#else /* Word 0 - Little Endian */
        uint64_t minlen                : 16; /**< [ 15:  0](R/W) Byte count for min-sized frame check. */
        uint64_t maxlen                : 16; /**< [ 31: 16](R/W) Byte count for max-sized frame check. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_frm_len_chkx_s cn; */
} bdk_pki_frm_len_chkx_t;

static inline uint64_t BDK_PKI_FRM_LEN_CHKX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_FRM_LEN_CHKX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c000004000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_FRM_LEN_CHKX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_FRM_LEN_CHKX(a) bdk_pki_frm_len_chkx_t
#define bustype_BDK_PKI_FRM_LEN_CHKX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_FRM_LEN_CHKX(a) "PKI_FRM_LEN_CHKX"
#define device_bar_BDK_PKI_FRM_LEN_CHKX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_FRM_LEN_CHKX(a) (a)
#define arguments_BDK_PKI_FRM_LEN_CHKX(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_gbl_pen
 *
 * PKI Global Parser Enable Register
 * Internal:
 * INTERNAL: Changes in these bits should cause the SDK to reload appropriate versions of the
 * sequencer code, with appropriate segments disabled.
 * Global configuration information that applies to all pkinds.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_gbl_pen_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t rsvdrw63              : 54; /**< [ 63: 10](R/W) Reserved.
                                                                 INTERNAL: This register is used to communicate with the SDK, and therefore reserved bits
                                                                 should all be R/W. */
        uint64_t virt_pen              : 1;  /**< [  9:  9](R/W) Virtualization parsing enable.
                                                                 0 = VXLAN/NVGRE/GENEVE is never used in any style. This enables internal power
                                                                 and latency reductions.
                                                                 1 = VXLAN/NVGRE/GENEVE parsing may be used. */
        uint64_t clg_pen               : 1;  /**< [  8:  8](R/W) Custom LG parsing enable.
                                                                 0 = Custom LG is never used in any style; i.e. PKI_CL()_PKIND()_CFG[LG_CUSTOM] is
                                                                 zero for all indices. This enables internal power and latency reductions.
                                                                 1 = Custom LG parsing may be used. */
        uint64_t cl2_pen               : 1;  /**< [  7:  7](R/W) Custom L2 parsing enable.
                                                                 0 = Custom L2 is never used in any style; i.e. PKI_CL()_PKIND()_L2_CUSTOM[VALID]
                                                                 is zero for all indices. This enables internal power and latency reductions.
                                                                 1 = Custom L2 parsing may be used. */
        uint64_t l4_pen                : 1;  /**< [  6:  6](R/W) L4 parsing enable.
                                                                 0 = L4 parsing is never used in any style. This enables internal power and latency
                                                                 reductions.
                                                                 1 = L4 parsing may be used. */
        uint64_t il3_pen               : 1;  /**< [  5:  5](R/W) L3 inner parsing enable. Must be zero if L3_PEN is zero.
                                                                 0 = L3 inner parsing is never used in any style. This enables internal power and latency
                                                                 reductions.
                                                                 1 = L3 inner (IP-in-IP) parsing may be used. */
        uint64_t l3_pen                : 1;  /**< [  4:  4](R/W) L3 parsing enable.
                                                                 0 = L3 parsing is never used in any style. This enables internal power and latency
                                                                 reductions.
                                                                 1 = L3 parsing may be used. */
        uint64_t mpls_pen              : 1;  /**< [  3:  3](R/W) MPLS parsing enable.
                                                                 0 = MPLS parsing is never used in any style; i.e. PKI_CL()_PKIND()_CFG[MPLS_EN]
                                                                 is zero for all indices. This enables internal power and latency reductions.
                                                                 1 = MPLS parsing may be used. */
        uint64_t fulc_pen              : 1;  /**< [  2:  2](R/W) Fulcrum parsing enable.
                                                                 0 = Fulcrum parsing is never used in any style; i.e.
                                                                 PKI_CL()_PKIND()_CFG[FULC_EN] is zero for all indices. This enables internal
                                                                 power and latency reductions.
                                                                 1 = Fulcrum parsing may be used. */
        uint64_t dsa_pen               : 1;  /**< [  1:  1](R/W) DSA parsing enable. Must be zero if HG_PEN is set.
                                                                 0 = DSA parsing is never used in any style; i.e. PKI_CL()_PKIND()_CFG[DSA_EN] is
                                                                 zero for all indices. This enables internal power and latency reductions.
                                                                 1 = DSA parsing may be used. */
        uint64_t hg_pen                : 1;  /**< [  0:  0](R/W) HiGig parsing enable. Must be zero if DSA_PEN is set.
                                                                 0 = HiGig parsing is never used in any style; i.e. PKI_CL()_PKIND()_CFG[HG2_EN,
                                                                 HG_EN] are zero for all indices. This enables internal power and latency reductions.
                                                                 1 = HiGig parsing may be used. */
#else /* Word 0 - Little Endian */
        uint64_t hg_pen                : 1;  /**< [  0:  0](R/W) HiGig parsing enable. Must be zero if DSA_PEN is set.
                                                                 0 = HiGig parsing is never used in any style; i.e. PKI_CL()_PKIND()_CFG[HG2_EN,
                                                                 HG_EN] are zero for all indices. This enables internal power and latency reductions.
                                                                 1 = HiGig parsing may be used. */
        uint64_t dsa_pen               : 1;  /**< [  1:  1](R/W) DSA parsing enable. Must be zero if HG_PEN is set.
                                                                 0 = DSA parsing is never used in any style; i.e. PKI_CL()_PKIND()_CFG[DSA_EN] is
                                                                 zero for all indices. This enables internal power and latency reductions.
                                                                 1 = DSA parsing may be used. */
        uint64_t fulc_pen              : 1;  /**< [  2:  2](R/W) Fulcrum parsing enable.
                                                                 0 = Fulcrum parsing is never used in any style; i.e.
                                                                 PKI_CL()_PKIND()_CFG[FULC_EN] is zero for all indices. This enables internal
                                                                 power and latency reductions.
                                                                 1 = Fulcrum parsing may be used. */
        uint64_t mpls_pen              : 1;  /**< [  3:  3](R/W) MPLS parsing enable.
                                                                 0 = MPLS parsing is never used in any style; i.e. PKI_CL()_PKIND()_CFG[MPLS_EN]
                                                                 is zero for all indices. This enables internal power and latency reductions.
                                                                 1 = MPLS parsing may be used. */
        uint64_t l3_pen                : 1;  /**< [  4:  4](R/W) L3 parsing enable.
                                                                 0 = L3 parsing is never used in any style. This enables internal power and latency
                                                                 reductions.
                                                                 1 = L3 parsing may be used. */
        uint64_t il3_pen               : 1;  /**< [  5:  5](R/W) L3 inner parsing enable. Must be zero if L3_PEN is zero.
                                                                 0 = L3 inner parsing is never used in any style. This enables internal power and latency
                                                                 reductions.
                                                                 1 = L3 inner (IP-in-IP) parsing may be used. */
        uint64_t l4_pen                : 1;  /**< [  6:  6](R/W) L4 parsing enable.
                                                                 0 = L4 parsing is never used in any style. This enables internal power and latency
                                                                 reductions.
                                                                 1 = L4 parsing may be used. */
        uint64_t cl2_pen               : 1;  /**< [  7:  7](R/W) Custom L2 parsing enable.
                                                                 0 = Custom L2 is never used in any style; i.e. PKI_CL()_PKIND()_L2_CUSTOM[VALID]
                                                                 is zero for all indices. This enables internal power and latency reductions.
                                                                 1 = Custom L2 parsing may be used. */
        uint64_t clg_pen               : 1;  /**< [  8:  8](R/W) Custom LG parsing enable.
                                                                 0 = Custom LG is never used in any style; i.e. PKI_CL()_PKIND()_CFG[LG_CUSTOM] is
                                                                 zero for all indices. This enables internal power and latency reductions.
                                                                 1 = Custom LG parsing may be used. */
        uint64_t virt_pen              : 1;  /**< [  9:  9](R/W) Virtualization parsing enable.
                                                                 0 = VXLAN/NVGRE/GENEVE is never used in any style. This enables internal power
                                                                 and latency reductions.
                                                                 1 = VXLAN/NVGRE/GENEVE parsing may be used. */
        uint64_t rsvdrw63              : 54; /**< [ 63: 10](R/W) Reserved.
                                                                 INTERNAL: This register is used to communicate with the SDK, and therefore reserved bits
                                                                 should all be R/W. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_gbl_pen_s cn; */
} bdk_pki_gbl_pen_t;

#define BDK_PKI_GBL_PEN BDK_PKI_GBL_PEN_FUNC()
static inline uint64_t BDK_PKI_GBL_PEN_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_GBL_PEN_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000200ll;
    __bdk_csr_fatal("PKI_GBL_PEN", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_GBL_PEN bdk_pki_gbl_pen_t
#define bustype_BDK_PKI_GBL_PEN BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_GBL_PEN "PKI_GBL_PEN"
#define device_bar_BDK_PKI_GBL_PEN 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_GBL_PEN 0
#define arguments_BDK_PKI_GBL_PEN -1,-1,-1,-1

/**
 * Register (NCB) pki_gen_int
 *
 * PKI General Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_gen_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1C/H) Set when PKI receives a packet that exceeds 256 buffers. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1C/H) Set when PKI receives a packet that exceeds 64 KB. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1C/H) Set when a device attempts to have more than the allocated requests outstanding to PKI. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1C/H) Set when packet dropped due to no FPA pointers available for the aura the packet
                                                                 requested. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1C/H) Set when data arrives before a SOP for the same reasm-id for a packet. The first detected
                                                                 error associated with bits [DAT,SOP,EOP] of this register is only set here. A new bit can
                                                                 be set when the previous reported bit is cleared. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1C/H) Set when an EOP is followed by an EOP for the same reasm-id for a packet. The first
                                                                 detected error associated with bits [DAT,EOP,SOP] of this register is only set here. A new
                                                                 bit can be set when the previous reported bit is cleared. Also see PKI_PKT_ERR. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1C/H) Set when a SOP is followed by an SOP for the same reasm-id for a packet. The first
                                                                 detected error associated with bits [DAT,EOP,SOP] of this register is only set here. A new
                                                                 bit can be set when the previous reported bit is cleared. Also see PKI_PKT_ERR. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1C/H) PKI asserted backpressure. Set when PKI was unable to accept the next valid data from
                                                                 BGX/DPI/ILK etc. over X2P due to all internal resources being used up, and PKI will
                                                                 backpressure X2P. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1C/H) PKI calculated bad CRC in the L2 frame. */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1C/H) Packet dropped due to QOS. If the QOS algorithm decides to drop a packet, PKI asserts this
                                                                 interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1C/H) Packet dropped due to QOS. If the QOS algorithm decides to drop a packet, PKI asserts this
                                                                 interrupt. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1C/H) PKI calculated bad CRC in the L2 frame. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1C/H) PKI asserted backpressure. Set when PKI was unable to accept the next valid data from
                                                                 BGX/DPI/ILK etc. over X2P due to all internal resources being used up, and PKI will
                                                                 backpressure X2P. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1C/H) Set when a SOP is followed by an SOP for the same reasm-id for a packet. The first
                                                                 detected error associated with bits [DAT,EOP,SOP] of this register is only set here. A new
                                                                 bit can be set when the previous reported bit is cleared. Also see PKI_PKT_ERR. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1C/H) Set when an EOP is followed by an EOP for the same reasm-id for a packet. The first
                                                                 detected error associated with bits [DAT,EOP,SOP] of this register is only set here. A new
                                                                 bit can be set when the previous reported bit is cleared. Also see PKI_PKT_ERR. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1C/H) Set when data arrives before a SOP for the same reasm-id for a packet. The first detected
                                                                 error associated with bits [DAT,SOP,EOP] of this register is only set here. A new bit can
                                                                 be set when the previous reported bit is cleared. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1C/H) Set when packet dropped due to no FPA pointers available for the aura the packet
                                                                 requested. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1C/H) Set when a device attempts to have more than the allocated requests outstanding to PKI. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1C/H) Set when PKI receives a packet that exceeds 64 KB. */
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1C/H) Set when PKI receives a packet that exceeds 256 buffers. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_gen_int_s cn; */
} bdk_pki_gen_int_t;

#define BDK_PKI_GEN_INT BDK_PKI_GEN_INT_FUNC()
static inline uint64_t BDK_PKI_GEN_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_GEN_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000800ll;
    __bdk_csr_fatal("PKI_GEN_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_GEN_INT bdk_pki_gen_int_t
#define bustype_BDK_PKI_GEN_INT BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_GEN_INT "PKI_GEN_INT"
#define device_bar_BDK_PKI_GEN_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_GEN_INT 0
#define arguments_BDK_PKI_GEN_INT -1,-1,-1,-1

/**
 * Register (NCB) pki_gen_int_ena_w1c
 *
 * PKI General Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_gen_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PKI_GEN_INT[BUFS_OFLOW]. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PKI_GEN_INT[PKT_SIZE_OFLOW]. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_GEN_INT[X2P_REQ_OFL]. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_GEN_INT[DRP_NOAVAIL]. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_GEN_INT[DAT]. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_GEN_INT[EOP]. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_GEN_INT[SOP]. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_GEN_INT[BCKPRS]. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_GEN_INT[CRCERR]. */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_GEN_INT[PKTDRP]. */
#else /* Word 0 - Little Endian */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PKI_GEN_INT[PKTDRP]. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PKI_GEN_INT[CRCERR]. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PKI_GEN_INT[BCKPRS]. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PKI_GEN_INT[SOP]. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PKI_GEN_INT[EOP]. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PKI_GEN_INT[DAT]. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PKI_GEN_INT[DRP_NOAVAIL]. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PKI_GEN_INT[X2P_REQ_OFL]. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PKI_GEN_INT[PKT_SIZE_OFLOW]. */
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PKI_GEN_INT[BUFS_OFLOW]. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_gen_int_ena_w1c_s cn; */
} bdk_pki_gen_int_ena_w1c_t;

#define BDK_PKI_GEN_INT_ENA_W1C BDK_PKI_GEN_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_PKI_GEN_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_GEN_INT_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000820ll;
    __bdk_csr_fatal("PKI_GEN_INT_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_GEN_INT_ENA_W1C bdk_pki_gen_int_ena_w1c_t
#define bustype_BDK_PKI_GEN_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_GEN_INT_ENA_W1C "PKI_GEN_INT_ENA_W1C"
#define device_bar_BDK_PKI_GEN_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_GEN_INT_ENA_W1C 0
#define arguments_BDK_PKI_GEN_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) pki_gen_int_ena_w1s
 *
 * PKI General Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_gen_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PKI_GEN_INT[BUFS_OFLOW]. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PKI_GEN_INT[PKT_SIZE_OFLOW]. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_GEN_INT[X2P_REQ_OFL]. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_GEN_INT[DRP_NOAVAIL]. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_GEN_INT[DAT]. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_GEN_INT[EOP]. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_GEN_INT[SOP]. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_GEN_INT[BCKPRS]. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_GEN_INT[CRCERR]. */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_GEN_INT[PKTDRP]. */
#else /* Word 0 - Little Endian */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PKI_GEN_INT[PKTDRP]. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PKI_GEN_INT[CRCERR]. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PKI_GEN_INT[BCKPRS]. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PKI_GEN_INT[SOP]. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PKI_GEN_INT[EOP]. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PKI_GEN_INT[DAT]. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PKI_GEN_INT[DRP_NOAVAIL]. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PKI_GEN_INT[X2P_REQ_OFL]. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PKI_GEN_INT[PKT_SIZE_OFLOW]. */
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PKI_GEN_INT[BUFS_OFLOW]. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_gen_int_ena_w1s_s cn; */
} bdk_pki_gen_int_ena_w1s_t;

#define BDK_PKI_GEN_INT_ENA_W1S BDK_PKI_GEN_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_PKI_GEN_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_GEN_INT_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000830ll;
    __bdk_csr_fatal("PKI_GEN_INT_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_GEN_INT_ENA_W1S bdk_pki_gen_int_ena_w1s_t
#define bustype_BDK_PKI_GEN_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_GEN_INT_ENA_W1S "PKI_GEN_INT_ENA_W1S"
#define device_bar_BDK_PKI_GEN_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_GEN_INT_ENA_W1S 0
#define arguments_BDK_PKI_GEN_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_gen_int_w1s
 *
 * PKI General Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_gen_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PKI_GEN_INT[BUFS_OFLOW]. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PKI_GEN_INT[PKT_SIZE_OFLOW]. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_GEN_INT[X2P_REQ_OFL]. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_GEN_INT[DRP_NOAVAIL]. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_GEN_INT[DAT]. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_GEN_INT[EOP]. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_GEN_INT[SOP]. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_GEN_INT[BCKPRS]. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_GEN_INT[CRCERR]. */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_GEN_INT[PKTDRP]. */
#else /* Word 0 - Little Endian */
        uint64_t pktdrp                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PKI_GEN_INT[PKTDRP]. */
        uint64_t crcerr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PKI_GEN_INT[CRCERR]. */
        uint64_t bckprs                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PKI_GEN_INT[BCKPRS]. */
        uint64_t sop                   : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PKI_GEN_INT[SOP]. */
        uint64_t eop                   : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PKI_GEN_INT[EOP]. */
        uint64_t dat                   : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PKI_GEN_INT[DAT]. */
        uint64_t drp_noavail           : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PKI_GEN_INT[DRP_NOAVAIL]. */
        uint64_t x2p_req_ofl           : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PKI_GEN_INT[X2P_REQ_OFL]. */
        uint64_t pkt_size_oflow        : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PKI_GEN_INT[PKT_SIZE_OFLOW]. */
        uint64_t bufs_oflow            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PKI_GEN_INT[BUFS_OFLOW]. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_gen_int_w1s_s cn; */
} bdk_pki_gen_int_w1s_t;

#define BDK_PKI_GEN_INT_W1S BDK_PKI_GEN_INT_W1S_FUNC()
static inline uint64_t BDK_PKI_GEN_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_GEN_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000810ll;
    __bdk_csr_fatal("PKI_GEN_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_GEN_INT_W1S bdk_pki_gen_int_w1s_t
#define bustype_BDK_PKI_GEN_INT_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_GEN_INT_W1S "PKI_GEN_INT_W1S"
#define device_bar_BDK_PKI_GEN_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_GEN_INT_W1S 0
#define arguments_BDK_PKI_GEN_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) pki_icg#_cfg
 *
 * PKI Cluster Group Control Register
 * Configures a cluster group.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_icgx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t maxipe_use            : 5;  /**< [ 52: 48](R/W) Maximum number of IPEs to use in each cluster for this ICG. For diagnostic use
                                                                 only. INTERNAL: Allows reducing the number of IPEs available for debug,
                                                                 characterization, repair, etc. Must be between 1 and PKI_CONST1[IPES]
                                                                 (20). Normally, PKI will have all 20 IPEs available in a cluster for packet
                                                                 processing, other values will decrease performance. */
        uint64_t reserved_36_47        : 12;
        uint64_t clusters              : 4;  /**< [ 35: 32](R/W) Bit-mask of clusters in this cluster group. A given cluster can only be enabled
                                                                 in a single cluster group. Behavior is undefined for an ICG which receives
                                                                 traffic with a [CLUSTERS] of 0x0. ICG(0)'s entry resets to 0x3, all other
                                                                 entries to 0x0. Valid values of CLUSTERS is: 0..3 */
        uint64_t reserved_27_31        : 5;
        uint64_t release_rqd           : 1;  /**< [ 26: 26](R/W) Release required. For diagnostic use only. INTERNAL:
                                                                 0 = Release of r64 to r95 will occur immediately, no release microop is needed.
                                                                 1 = Release will wait until release microop executes. */
        uint64_t mlo                   : 1;  /**< [ 25: 25](R/W) Memory low bypass enable. For diagnostic use only. INTERNAL:
                                                                 0 = KMEM specifies contents of r48 to r63. The sequencer code expects this setting.
                                                                 1 = KMEM specifies contents of r32 to r47. This may be desirable when PKIENA=0 to allow
                                                                 direct control over the back end. */
        uint64_t pena                  : 1;  /**< [ 24: 24](R/W) Parse enable. Must be set after PKI has been initialized.
                                                                 INTERNAL: Software should set after the IMEM and associated state is initialized.
                                                                 0 = IPT transitions from start directly to done without executing a sequence, and the KMEM
                                                                 bits effectively are copied through to the WQ.
                                                                 1 = Normal sequencer operation. */
        uint64_t timer                 : 12; /**< [ 23: 12](RO/H) Current hold-off timer. Enables even spreading of cluster utilization over time; while
                                                                 TIMER is non-zero, a cluster in this group will not start parsing. When a cluster in this
                                                                 group starts parsing, TIMER is set to DELAY, and decrements every coprocessor-clock. TIMER
                                                                 is zeroed if all clusters in this group are idle. */
        uint64_t delay                 : 12; /**< [ 11:  0](R/W) Delay between cluster starts, as described under TIMER. If 0x0, a cluster can
                                                                 start at any time relative to other clusters. DELAY should be typically selected
                                                                 to minimize the average observed parser latency by loading with the parsing
                                                                 delay divided by the number of clusters in this cluster group which will
                                                                 typically be 800 divided by the population count of CLUSTERS
                                                                 (800/pop_cnt(CLUSTERS)). The smallest useful non-zero value is 0xA0,
                                                                 corresponding to the minimum number of cycles needed to fill one cluster with
                                                                 packets.
                                                                 INTERNAL: The number 800 above was chosen as a typical production ucode
                                                                 length with some additional instruction growth. */
#else /* Word 0 - Little Endian */
        uint64_t delay                 : 12; /**< [ 11:  0](R/W) Delay between cluster starts, as described under TIMER. If 0x0, a cluster can
                                                                 start at any time relative to other clusters. DELAY should be typically selected
                                                                 to minimize the average observed parser latency by loading with the parsing
                                                                 delay divided by the number of clusters in this cluster group which will
                                                                 typically be 800 divided by the population count of CLUSTERS
                                                                 (800/pop_cnt(CLUSTERS)). The smallest useful non-zero value is 0xA0,
                                                                 corresponding to the minimum number of cycles needed to fill one cluster with
                                                                 packets.
                                                                 INTERNAL: The number 800 above was chosen as a typical production ucode
                                                                 length with some additional instruction growth. */
        uint64_t timer                 : 12; /**< [ 23: 12](RO/H) Current hold-off timer. Enables even spreading of cluster utilization over time; while
                                                                 TIMER is non-zero, a cluster in this group will not start parsing. When a cluster in this
                                                                 group starts parsing, TIMER is set to DELAY, and decrements every coprocessor-clock. TIMER
                                                                 is zeroed if all clusters in this group are idle. */
        uint64_t pena                  : 1;  /**< [ 24: 24](R/W) Parse enable. Must be set after PKI has been initialized.
                                                                 INTERNAL: Software should set after the IMEM and associated state is initialized.
                                                                 0 = IPT transitions from start directly to done without executing a sequence, and the KMEM
                                                                 bits effectively are copied through to the WQ.
                                                                 1 = Normal sequencer operation. */
        uint64_t mlo                   : 1;  /**< [ 25: 25](R/W) Memory low bypass enable. For diagnostic use only. INTERNAL:
                                                                 0 = KMEM specifies contents of r48 to r63. The sequencer code expects this setting.
                                                                 1 = KMEM specifies contents of r32 to r47. This may be desirable when PKIENA=0 to allow
                                                                 direct control over the back end. */
        uint64_t release_rqd           : 1;  /**< [ 26: 26](R/W) Release required. For diagnostic use only. INTERNAL:
                                                                 0 = Release of r64 to r95 will occur immediately, no release microop is needed.
                                                                 1 = Release will wait until release microop executes. */
        uint64_t reserved_27_31        : 5;
        uint64_t clusters              : 4;  /**< [ 35: 32](R/W) Bit-mask of clusters in this cluster group. A given cluster can only be enabled
                                                                 in a single cluster group. Behavior is undefined for an ICG which receives
                                                                 traffic with a [CLUSTERS] of 0x0. ICG(0)'s entry resets to 0x3, all other
                                                                 entries to 0x0. Valid values of CLUSTERS is: 0..3 */
        uint64_t reserved_36_47        : 12;
        uint64_t maxipe_use            : 5;  /**< [ 52: 48](R/W) Maximum number of IPEs to use in each cluster for this ICG. For diagnostic use
                                                                 only. INTERNAL: Allows reducing the number of IPEs available for debug,
                                                                 characterization, repair, etc. Must be between 1 and PKI_CONST1[IPES]
                                                                 (20). Normally, PKI will have all 20 IPEs available in a cluster for packet
                                                                 processing, other values will decrease performance. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_icgx_cfg_s cn; */
} bdk_pki_icgx_cfg_t;

static inline uint64_t BDK_PKI_ICGX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_ICGX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86c00000a000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("PKI_ICGX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_ICGX_CFG(a) bdk_pki_icgx_cfg_t
#define bustype_BDK_PKI_ICGX_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_ICGX_CFG(a) "PKI_ICGX_CFG"
#define device_bar_BDK_PKI_ICGX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_ICGX_CFG(a) (a)
#define arguments_BDK_PKI_ICGX_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_imem#
 *
 * PKI Cluster IMEM Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_imemx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Instruction word at given address. Software should reload PKI_IMEM() upon the
                                                                 detection of IMEM_SBE or IMEM_DBE errors. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Instruction word at given address. Software should reload PKI_IMEM() upon the
                                                                 detection of IMEM_SBE or IMEM_DBE errors. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_imemx_s cn; */
} bdk_pki_imemx_t;

static inline uint64_t BDK_PKI_IMEMX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_IMEMX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=2047))
        return 0x86c000100000ll + 8ll * ((a) & 0x7ff);
    __bdk_csr_fatal("PKI_IMEMX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_IMEMX(a) bdk_pki_imemx_t
#define bustype_BDK_PKI_IMEMX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_IMEMX(a) "PKI_IMEMX"
#define device_bar_BDK_PKI_IMEMX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_IMEMX(a) (a)
#define arguments_BDK_PKI_IMEMX(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_ltype#_map
 *
 * PKI Backend Layer Map Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ltypex_map_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t beltype               : 3;  /**< [  2:  0](R/W) For each given PKI_LTYPE_E, the protocol type backend hardware should assume this layer
                                                                 type corresponds to. Enumerated by PKI_BELTYPE_E. The recommended settings for each
                                                                 PKI_LTYPE_E are shown in the PKI_LTYPE_E table. */
#else /* Word 0 - Little Endian */
        uint64_t beltype               : 3;  /**< [  2:  0](R/W) For each given PKI_LTYPE_E, the protocol type backend hardware should assume this layer
                                                                 type corresponds to. Enumerated by PKI_BELTYPE_E. The recommended settings for each
                                                                 PKI_LTYPE_E are shown in the PKI_LTYPE_E table. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ltypex_map_s cn; */
} bdk_pki_ltypex_map_t;

static inline uint64_t BDK_PKI_LTYPEX_MAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_LTYPEX_MAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x86c000005000ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKI_LTYPEX_MAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_LTYPEX_MAP(a) bdk_pki_ltypex_map_t
#define bustype_BDK_PKI_LTYPEX_MAP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_LTYPEX_MAP(a) "PKI_LTYPEX_MAP"
#define device_bar_BDK_PKI_LTYPEX_MAP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_LTYPEX_MAP(a) (a)
#define arguments_BDK_PKI_LTYPEX_MAP(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pbe_eco
 *
 * INTERNAL: PKI PBE ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pbe_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pbe_eco_s cn; */
} bdk_pki_pbe_eco_t;

#define BDK_PKI_PBE_ECO BDK_PKI_PBE_ECO_FUNC()
static inline uint64_t BDK_PKI_PBE_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PBE_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000710ll;
    __bdk_csr_fatal("PKI_PBE_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PBE_ECO bdk_pki_pbe_eco_t
#define bustype_BDK_PKI_PBE_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PBE_ECO "PKI_PBE_ECO"
#define device_bar_BDK_PKI_PBE_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PBE_ECO 0
#define arguments_BDK_PKI_PBE_ECO -1,-1,-1,-1

/**
 * Register (NCB) pki_pcam_lookup
 *
 * PKI PCAM Lookup Register
 * For diagnostic use only, perform a PCAM lookup against the provided cluster and PCAM instance
 * and loads results into PKI_PCAM_RESULT.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pcam_lookup_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t cl                    : 2;  /**< [ 53: 52](R/W) Cluster number to lookup within. */
        uint64_t reserved_49_51        : 3;
        uint64_t pcam                  : 1;  /**< [ 48: 48](R/W) PCAM number to lookup within. */
        uint64_t term                  : 8;  /**< [ 47: 40](R/W) Term value to lookup. */
        uint64_t style                 : 8;  /**< [ 39: 32](R/W) Style value to lookup. */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Data to lookup. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Data to lookup. */
        uint64_t style                 : 8;  /**< [ 39: 32](R/W) Style value to lookup. */
        uint64_t term                  : 8;  /**< [ 47: 40](R/W) Term value to lookup. */
        uint64_t pcam                  : 1;  /**< [ 48: 48](R/W) PCAM number to lookup within. */
        uint64_t reserved_49_51        : 3;
        uint64_t cl                    : 2;  /**< [ 53: 52](R/W) Cluster number to lookup within. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pcam_lookup_s cn; */
} bdk_pki_pcam_lookup_t;

#define BDK_PKI_PCAM_LOOKUP BDK_PKI_PCAM_LOOKUP_FUNC()
static inline uint64_t BDK_PKI_PCAM_LOOKUP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PCAM_LOOKUP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000500ll;
    __bdk_csr_fatal("PKI_PCAM_LOOKUP", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PCAM_LOOKUP bdk_pki_pcam_lookup_t
#define bustype_BDK_PKI_PCAM_LOOKUP BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PCAM_LOOKUP "PKI_PCAM_LOOKUP"
#define device_bar_BDK_PKI_PCAM_LOOKUP 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PCAM_LOOKUP 0
#define arguments_BDK_PKI_PCAM_LOOKUP -1,-1,-1,-1

/**
 * Register (NCB) pki_pcam_result
 *
 * PKI PCAM Result Register
 * Internal:
 * For diagnostic use only, return PCAM results for the most recent write to PKI_PCAM_LOOKUP. The
 * read will stall until the lookup is completed. PKI_CL(0..1)_ECC_CTL[PCAM_EN] must be clear
 * before accessing this register.  INTERNAL: Read stall is implemented by delaying the
 * PKI_PCAM_LOOKUP write acknowledge until the PCAM is free and the lookup can be issued.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pcam_result_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t conflict              : 1;  /**< [ 63: 63](RO/H) Conflict. The lookup resulted in multiple entries matching PKI_PCAM_LOOKUP[DATA], [TERM]
                                                                 and [STYLE], or zero if no conflict. */
        uint64_t reserved_41_62        : 22;
        uint64_t match                 : 1;  /**< [ 40: 40](RO/H) Resulting match. */
        uint64_t entry                 : 8;  /**< [ 39: 32](RO/H) Resulting matching entry number, unpredictable unless [MATCH] set and [CONFLICT] is clear. */
        uint64_t result                : 32; /**< [ 31:  0](RO/H) Resulting data from matching line's PKI_CL()_PCAM()_ACTION(), or zero if no
                                                                 match. Unpredictable unless [CONFLICT] is clear. */
#else /* Word 0 - Little Endian */
        uint64_t result                : 32; /**< [ 31:  0](RO/H) Resulting data from matching line's PKI_CL()_PCAM()_ACTION(), or zero if no
                                                                 match. Unpredictable unless [CONFLICT] is clear. */
        uint64_t entry                 : 8;  /**< [ 39: 32](RO/H) Resulting matching entry number, unpredictable unless [MATCH] set and [CONFLICT] is clear. */
        uint64_t match                 : 1;  /**< [ 40: 40](RO/H) Resulting match. */
        uint64_t reserved_41_62        : 22;
        uint64_t conflict              : 1;  /**< [ 63: 63](RO/H) Conflict. The lookup resulted in multiple entries matching PKI_PCAM_LOOKUP[DATA], [TERM]
                                                                 and [STYLE], or zero if no conflict. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pcam_result_s cn; */
} bdk_pki_pcam_result_t;

#define BDK_PKI_PCAM_RESULT BDK_PKI_PCAM_RESULT_FUNC()
static inline uint64_t BDK_PKI_PCAM_RESULT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PCAM_RESULT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000510ll;
    __bdk_csr_fatal("PKI_PCAM_RESULT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PCAM_RESULT bdk_pki_pcam_result_t
#define bustype_BDK_PKI_PCAM_RESULT BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PCAM_RESULT "PKI_PCAM_RESULT"
#define device_bar_BDK_PKI_PCAM_RESULT 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PCAM_RESULT 0
#define arguments_BDK_PKI_PCAM_RESULT -1,-1,-1,-1

/**
 * Register (NCB) pki_pf_msix_pba#
 *
 * PKI MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the PKI_PF_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated PKI_PF_MSIX_VEC()_CTL, enumerated by
                                                                 PKI_PF_INT_VEC_E. Bits that have no associated PKI_PF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated PKI_PF_MSIX_VEC()_CTL, enumerated by
                                                                 PKI_PF_INT_VEC_E. Bits that have no associated PKI_PF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pf_msix_pbax_s cn; */
} bdk_pki_pf_msix_pbax_t;

static inline uint64_t BDK_PKI_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x86c0010f0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("PKI_PF_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PF_MSIX_PBAX(a) bdk_pki_pf_msix_pbax_t
#define bustype_BDK_PKI_PF_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PF_MSIX_PBAX(a) "PKI_PF_MSIX_PBAX"
#define device_bar_BDK_PKI_PF_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_PKI_PF_MSIX_PBAX(a) (a)
#define arguments_BDK_PKI_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pf_msix_vec#_addr
 *
 * PKI MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the PKI_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PKI_PF_MSIX_VEC()_ADDR, PKI_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of PKI_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_PKI_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PKI_PF_MSIX_VEC()_ADDR, PKI_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of PKI_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_PKI_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pf_msix_vecx_addr_s cn; */
} bdk_pki_pf_msix_vecx_addr_t;

static inline uint64_t BDK_PKI_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x86c001000000ll + 0x10ll * ((a) & 0x7);
    __bdk_csr_fatal("PKI_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PF_MSIX_VECX_ADDR(a) bdk_pki_pf_msix_vecx_addr_t
#define bustype_BDK_PKI_PF_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PF_MSIX_VECX_ADDR(a) "PKI_PF_MSIX_VECX_ADDR"
#define device_bar_BDK_PKI_PF_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_PKI_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_PKI_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pf_msix_vec#_ctl
 *
 * PKI MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the PKI_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pf_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pf_msix_vecx_ctl_s cn; */
} bdk_pki_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_PKI_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x86c001000008ll + 0x10ll * ((a) & 0x7);
    __bdk_csr_fatal("PKI_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PF_MSIX_VECX_CTL(a) bdk_pki_pf_msix_vecx_ctl_t
#define bustype_BDK_PKI_PF_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PF_MSIX_VECX_CTL(a) "PKI_PF_MSIX_VECX_CTL"
#define device_bar_BDK_PKI_PF_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_PKI_PF_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_PKI_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pfe_diag
 *
 * INTERNAL: PKI PFE Diagnostic Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pfe_diag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t bad_rid               : 1;  /**< [  0:  0](R/W1C/H) Asserted when PFE sees and drops an X2P transaction with a RID > 95. */
#else /* Word 0 - Little Endian */
        uint64_t bad_rid               : 1;  /**< [  0:  0](R/W1C/H) Asserted when PFE sees and drops an X2P transaction with a RID > 95. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pfe_diag_s cn; */
} bdk_pki_pfe_diag_t;

#define BDK_PKI_PFE_DIAG BDK_PKI_PFE_DIAG_FUNC()
static inline uint64_t BDK_PKI_PFE_DIAG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PFE_DIAG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000560ll;
    __bdk_csr_fatal("PKI_PFE_DIAG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PFE_DIAG bdk_pki_pfe_diag_t
#define bustype_BDK_PKI_PFE_DIAG BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PFE_DIAG "PKI_PFE_DIAG"
#define device_bar_BDK_PKI_PFE_DIAG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PFE_DIAG 0
#define arguments_BDK_PKI_PFE_DIAG -1,-1,-1,-1

/**
 * Register (NCB) pki_pfe_eco
 *
 * INTERNAL: PKI PFE ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pfe_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pfe_eco_s cn; */
} bdk_pki_pfe_eco_t;

#define BDK_PKI_PFE_ECO BDK_PKI_PFE_ECO_FUNC()
static inline uint64_t BDK_PKI_PFE_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PFE_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000720ll;
    __bdk_csr_fatal("PKI_PFE_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PFE_ECO bdk_pki_pfe_eco_t
#define bustype_BDK_PKI_PFE_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PFE_ECO "PKI_PFE_ECO"
#define device_bar_BDK_PKI_PFE_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PFE_ECO 0
#define arguments_BDK_PKI_PFE_ECO -1,-1,-1,-1

/**
 * Register (NCB) pki_pix_clken
 *
 * INTERNAL: PKI PIX Conditional Clock Enable Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pix_clken_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t mech                  : 1;  /**< [ 16: 16](R/W) When set, force the conditional clocks on for mech. */
        uint64_t reserved_4_15         : 12;
        uint64_t cls                   : 4;  /**< [  3:  0](R/W) When set, force the conditional clocks on for this cluster. */
#else /* Word 0 - Little Endian */
        uint64_t cls                   : 4;  /**< [  3:  0](R/W) When set, force the conditional clocks on for this cluster. */
        uint64_t reserved_4_15         : 12;
        uint64_t mech                  : 1;  /**< [ 16: 16](R/W) When set, force the conditional clocks on for mech. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pix_clken_s cn; */
} bdk_pki_pix_clken_t;

#define BDK_PKI_PIX_CLKEN BDK_PKI_PIX_CLKEN_FUNC()
static inline uint64_t BDK_PKI_PIX_CLKEN_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PIX_CLKEN_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000600ll;
    __bdk_csr_fatal("PKI_PIX_CLKEN", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PIX_CLKEN bdk_pki_pix_clken_t
#define bustype_BDK_PKI_PIX_CLKEN BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PIX_CLKEN "PKI_PIX_CLKEN"
#define device_bar_BDK_PKI_PIX_CLKEN 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PIX_CLKEN 0
#define arguments_BDK_PKI_PIX_CLKEN -1,-1,-1,-1

/**
 * Register (NCB) pki_pix_diag
 *
 * INTERNAL: PKI PIX Diagnostic Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pix_diag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nosched               : 4;  /**< [  3:  0](R/W1C/H) Asserted when PFE requests an ICG with no enabled CLUSTERS. */
#else /* Word 0 - Little Endian */
        uint64_t nosched               : 4;  /**< [  3:  0](R/W1C/H) Asserted when PFE requests an ICG with no enabled CLUSTERS. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pix_diag_s cn; */
} bdk_pki_pix_diag_t;

#define BDK_PKI_PIX_DIAG BDK_PKI_PIX_DIAG_FUNC()
static inline uint64_t BDK_PKI_PIX_DIAG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PIX_DIAG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000580ll;
    __bdk_csr_fatal("PKI_PIX_DIAG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PIX_DIAG bdk_pki_pix_diag_t
#define bustype_BDK_PKI_PIX_DIAG BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PIX_DIAG "PKI_PIX_DIAG"
#define device_bar_BDK_PKI_PIX_DIAG 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PIX_DIAG 0
#define arguments_BDK_PKI_PIX_DIAG -1,-1,-1,-1

/**
 * Register (NCB) pki_pix_eco
 *
 * INTERNAL: PKI PIX ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pix_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pix_eco_s cn; */
} bdk_pki_pix_eco_t;

#define BDK_PKI_PIX_ECO BDK_PKI_PIX_ECO_FUNC()
static inline uint64_t BDK_PKI_PIX_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PIX_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000700ll;
    __bdk_csr_fatal("PKI_PIX_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PIX_ECO bdk_pki_pix_eco_t
#define bustype_BDK_PKI_PIX_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PIX_ECO "PKI_PIX_ECO"
#define device_bar_BDK_PKI_PIX_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PIX_ECO 0
#define arguments_BDK_PKI_PIX_ECO -1,-1,-1,-1

/**
 * Register (NCB) pki_pkind#_icgsel
 *
 * PKI Per-Pkind Cluster Group Select Register
 * Internal:
 * INTERNAL: In HW, pre-sequencer.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pkindx_icgsel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t icg                   : 2;  /**< [  1:  0](R/W) Cluster group that will service traffic on this pkind. See also PKI_ICG()_CFG, the
                                                                 register to which this field indexes. */
#else /* Word 0 - Little Endian */
        uint64_t icg                   : 2;  /**< [  1:  0](R/W) Cluster group that will service traffic on this pkind. See also PKI_ICG()_CFG, the
                                                                 register to which this field indexes. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pkindx_icgsel_s cn; */
} bdk_pki_pkindx_icgsel_t;

static inline uint64_t BDK_PKI_PKINDX_ICGSEL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PKINDX_ICGSEL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000010000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_PKINDX_ICGSEL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PKINDX_ICGSEL(a) bdk_pki_pkindx_icgsel_t
#define bustype_BDK_PKI_PKINDX_ICGSEL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PKINDX_ICGSEL(a) "PKI_PKINDX_ICGSEL"
#define device_bar_BDK_PKI_PKINDX_ICGSEL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PKINDX_ICGSEL(a) (a)
#define arguments_BDK_PKI_PKINDX_ICGSEL(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pknd#_inb_stat0
 *
 * PKI Inbound Packets Statistic Registers
 * Inbound packets received by PKI per pkind.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pkndx_inb_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pkts                  : 48; /**< [ 47:  0](R/W/H) Number of packets without errors received by PKI. */
#else /* Word 0 - Little Endian */
        uint64_t pkts                  : 48; /**< [ 47:  0](R/W/H) Number of packets without errors received by PKI. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pkndx_inb_stat0_s cn; */
} bdk_pki_pkndx_inb_stat0_t;

static inline uint64_t BDK_PKI_PKNDX_INB_STAT0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PKNDX_INB_STAT0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000f00000ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_PKNDX_INB_STAT0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PKNDX_INB_STAT0(a) bdk_pki_pkndx_inb_stat0_t
#define bustype_BDK_PKI_PKNDX_INB_STAT0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PKNDX_INB_STAT0(a) "PKI_PKNDX_INB_STAT0"
#define device_bar_BDK_PKI_PKNDX_INB_STAT0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PKNDX_INB_STAT0(a) (a)
#define arguments_BDK_PKI_PKNDX_INB_STAT0(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pknd#_inb_stat1
 *
 * PKI Inbound Octets Statistic Registers
 * Inbound octets received by PKI per pkind.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pkndx_inb_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t octs                  : 48; /**< [ 47:  0](R/W/H) Total number of octets from all packets received by PKI. */
#else /* Word 0 - Little Endian */
        uint64_t octs                  : 48; /**< [ 47:  0](R/W/H) Total number of octets from all packets received by PKI. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pkndx_inb_stat1_s cn; */
} bdk_pki_pkndx_inb_stat1_t;

static inline uint64_t BDK_PKI_PKNDX_INB_STAT1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PKNDX_INB_STAT1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000f00008ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_PKNDX_INB_STAT1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PKNDX_INB_STAT1(a) bdk_pki_pkndx_inb_stat1_t
#define bustype_BDK_PKI_PKNDX_INB_STAT1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PKNDX_INB_STAT1(a) "PKI_PKNDX_INB_STAT1"
#define device_bar_BDK_PKI_PKNDX_INB_STAT1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PKNDX_INB_STAT1(a) (a)
#define arguments_BDK_PKI_PKNDX_INB_STAT1(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pknd#_inb_stat2
 *
 * PKI Inbound Errors Statistic Registers
 * Inbound error packets received by PKI per pkind.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pkndx_inb_stat2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t errs                  : 48; /**< [ 47:  0](R/W/H) Number of packets with errors received by PKI. */
#else /* Word 0 - Little Endian */
        uint64_t errs                  : 48; /**< [ 47:  0](R/W/H) Number of packets with errors received by PKI. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pkndx_inb_stat2_s cn; */
} bdk_pki_pkndx_inb_stat2_t;

static inline uint64_t BDK_PKI_PKNDX_INB_STAT2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PKNDX_INB_STAT2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000f00010ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_PKNDX_INB_STAT2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_PKNDX_INB_STAT2(a) bdk_pki_pkndx_inb_stat2_t
#define bustype_BDK_PKI_PKNDX_INB_STAT2(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PKNDX_INB_STAT2(a) "PKI_PKNDX_INB_STAT2"
#define device_bar_BDK_PKI_PKNDX_INB_STAT2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PKNDX_INB_STAT2(a) (a)
#define arguments_BDK_PKI_PKNDX_INB_STAT2(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_pkt_err
 *
 * PKI Packet Error Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_pkt_err_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t reasm                 : 7;  /**< [  6:  0](RO/H) When PKI_GEN_INT[DAT,SOP,EOP] is set, this field latches the failing reassembly number
                                                                 associated with the error. */
#else /* Word 0 - Little Endian */
        uint64_t reasm                 : 7;  /**< [  6:  0](RO/H) When PKI_GEN_INT[DAT,SOP,EOP] is set, this field latches the failing reassembly number
                                                                 associated with the error. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_pkt_err_s cn; */
} bdk_pki_pkt_err_t;

#define BDK_PKI_PKT_ERR BDK_PKI_PKT_ERR_FUNC()
static inline uint64_t BDK_PKI_PKT_ERR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PKT_ERR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000030ll;
    __bdk_csr_fatal("PKI_PKT_ERR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PKT_ERR bdk_pki_pkt_err_t
#define bustype_BDK_PKI_PKT_ERR BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PKT_ERR "PKI_PKT_ERR"
#define device_bar_BDK_PKI_PKT_ERR 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PKT_ERR 0
#define arguments_BDK_PKI_PKT_ERR -1,-1,-1,-1

/**
 * Register (NCB) pki_ptag_avail
 *
 * PKI PTAG Available Register
 * For diagnostic use. INTERNAL: This register configures tag management. It is
 * suggested that this register only be written when PKI_BUF_CTL[PKI_EN] is clear and
 * must not be reconfigured without soft resetting PKI. While PKI is tolerant of
 * changes to this register and programing restrictions are not necessary for the
 * general case, the suggestion is to simplify verification. Therefore do not put other
 * fields into this register unless the same constraint applies. When the number of
 * tags available increases, PKI will simply have more resources. When the number of
 * tags available decreases, PKI will use less resources and may begin to assert BP if
 * the current tags in use exceeds the programmed value.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_ptag_avail_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t avail                 : 8;  /**< [  7:  0](R/W) Number of ptags available for use. Decreasing the number of ptags will reduce
                                                                 the number of packets waiting for parsing, which will lead to sooner
                                                                 backpressure/packet drop, but will decrease the small-packet latency of PKI by
                                                                 reducing buffer-bloat. AVAIL must be at least as great as the number of
                                                                 reassembly-IDs used by the system intends to use or the PTAGS can be exhausted
                                                                 and PKI will hang. */
#else /* Word 0 - Little Endian */
        uint64_t avail                 : 8;  /**< [  7:  0](R/W) Number of ptags available for use. Decreasing the number of ptags will reduce
                                                                 the number of packets waiting for parsing, which will lead to sooner
                                                                 backpressure/packet drop, but will decrease the small-packet latency of PKI by
                                                                 reducing buffer-bloat. AVAIL must be at least as great as the number of
                                                                 reassembly-IDs used by the system intends to use or the PTAGS can be exhausted
                                                                 and PKI will hang. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_ptag_avail_s cn; */
} bdk_pki_ptag_avail_t;

#define BDK_PKI_PTAG_AVAIL BDK_PKI_PTAG_AVAIL_FUNC()
static inline uint64_t BDK_PKI_PTAG_AVAIL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_PTAG_AVAIL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000130ll;
    __bdk_csr_fatal("PKI_PTAG_AVAIL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_PTAG_AVAIL bdk_pki_ptag_avail_t
#define bustype_BDK_PKI_PTAG_AVAIL BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_PTAG_AVAIL "PKI_PTAG_AVAIL"
#define device_bar_BDK_PKI_PTAG_AVAIL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_PTAG_AVAIL 0
#define arguments_BDK_PKI_PTAG_AVAIL -1,-1,-1,-1

/**
 * Register (NCB) pki_qpg_tbl#
 *
 * PKI QPG Table Registers
 * The QPG table is used to indirectly calculate the Portadd/Aura/Group from the Diffsrv, HiGig
 * or VLAN information as described in QPG.
 * See also PKI_QPG_TBLB().
 * INTERNAL: This register is outside SMEM due to opcode detection.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_qpg_tblx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t padd                  : 12; /**< [ 59: 48](R/W) Port to channel adder for calculating WQE[CHAN]. */
        uint64_t grptag_ok             : 3;  /**< [ 47: 45](R/W) Number of WQE[TAG] bits to add into WQE[GRP] if no error is detected. */
        uint64_t reserved_42_44        : 3;
        uint64_t grp_ok                : 10; /**< [ 41: 32](R/W) SSO group to schedule packet to and to load WQE[GRP] with if no error is detected. */
        uint64_t grptag_bad            : 3;  /**< [ 31: 29](R/W) Number of WQE[TAG] bits to add into WQE[GRP] if an error is detected. */
        uint64_t reserved_26_28        : 3;
        uint64_t grp_bad               : 10; /**< [ 25: 16](R/W) SSO group to schedule packet to and to load WQE[GRP] with if an error is detected. */
        uint64_t reserved_12_15        : 4;
        uint64_t aura_node             : 2;  /**< [ 11: 10](RO) Aura node number. The node number is part of the upper aura bits, however PKI can only
                                                                 allocate from auras on the local node, therefore these bits are hardcoded to the node
                                                                 number. */
        uint64_t laura                 : 10; /**< [  9:  0](R/W) Aura on local node for QOS calculations and loading into WQE[AURA]. */
#else /* Word 0 - Little Endian */
        uint64_t laura                 : 10; /**< [  9:  0](R/W) Aura on local node for QOS calculations and loading into WQE[AURA]. */
        uint64_t aura_node             : 2;  /**< [ 11: 10](RO) Aura node number. The node number is part of the upper aura bits, however PKI can only
                                                                 allocate from auras on the local node, therefore these bits are hardcoded to the node
                                                                 number. */
        uint64_t reserved_12_15        : 4;
        uint64_t grp_bad               : 10; /**< [ 25: 16](R/W) SSO group to schedule packet to and to load WQE[GRP] with if an error is detected. */
        uint64_t reserved_26_28        : 3;
        uint64_t grptag_bad            : 3;  /**< [ 31: 29](R/W) Number of WQE[TAG] bits to add into WQE[GRP] if an error is detected. */
        uint64_t grp_ok                : 10; /**< [ 41: 32](R/W) SSO group to schedule packet to and to load WQE[GRP] with if no error is detected. */
        uint64_t reserved_42_44        : 3;
        uint64_t grptag_ok             : 3;  /**< [ 47: 45](R/W) Number of WQE[TAG] bits to add into WQE[GRP] if no error is detected. */
        uint64_t padd                  : 12; /**< [ 59: 48](R/W) Port to channel adder for calculating WQE[CHAN]. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_qpg_tblx_s cn; */
} bdk_pki_qpg_tblx_t;

static inline uint64_t BDK_PKI_QPG_TBLX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_QPG_TBLX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=2047))
        return 0x86c000800000ll + 8ll * ((a) & 0x7ff);
    __bdk_csr_fatal("PKI_QPG_TBLX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_QPG_TBLX(a) bdk_pki_qpg_tblx_t
#define bustype_BDK_PKI_QPG_TBLX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_QPG_TBLX(a) "PKI_QPG_TBLX"
#define device_bar_BDK_PKI_QPG_TBLX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_QPG_TBLX(a) (a)
#define arguments_BDK_PKI_QPG_TBLX(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_qpg_tblb#
 *
 * PKI QPG Table Registers 2
 * This register configures the QPG table. See also PKI_QPG_TBL().
 * Internal:
 * INTERNAL: This register is outside SMEM due to opcode detection.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_qpg_tblbx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t gmid                  : 16; /**< [ 47: 32](R/W) Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer allocations/frees, or to SSO for all submit work operations related to
                                                                 PKI_QPG_TBL()[AURA]/[GRP_OK]/[GRP_BAD].
                                                                 Must be non-zero or requests will be dropped by FPA/SSO. */
        uint64_t reserved_24_31        : 8;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Stream identifier bits <7:0>. */
        uint64_t reserved_10_15        : 6;
        uint64_t dstat_id              : 10; /**< [  9:  0](R/W) Deep statistic bucket to use for traffic to this QPG. This determines which
                                                                 index of PKI_DSTAT()_STAT0..PKI_DSTAT()_STAT4 will increment. Additionally, if
                                                                 PKI_STAT_CTL[MODE] = 0x2, then DSTAT_ID values 0-63 will increment
                                                                 PKI_STAT()_STAT0..PKI_STAT()_STAT18 and PKI_STAT()_HIST0..PKI_STAT()_HIST6. */
#else /* Word 0 - Little Endian */
        uint64_t dstat_id              : 10; /**< [  9:  0](R/W) Deep statistic bucket to use for traffic to this QPG. This determines which
                                                                 index of PKI_DSTAT()_STAT0..PKI_DSTAT()_STAT4 will increment. Additionally, if
                                                                 PKI_STAT_CTL[MODE] = 0x2, then DSTAT_ID values 0-63 will increment
                                                                 PKI_STAT()_STAT0..PKI_STAT()_STAT18 and PKI_STAT()_HIST0..PKI_STAT()_HIST6. */
        uint64_t reserved_10_15        : 6;
        uint64_t strm                  : 8;  /**< [ 23: 16](R/W) Stream identifier bits <7:0>. */
        uint64_t reserved_24_31        : 8;
        uint64_t gmid                  : 16; /**< [ 47: 32](R/W) Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer allocations/frees, or to SSO for all submit work operations related to
                                                                 PKI_QPG_TBL()[AURA]/[GRP_OK]/[GRP_BAD].
                                                                 Must be non-zero or requests will be dropped by FPA/SSO. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_qpg_tblbx_s cn; */
} bdk_pki_qpg_tblbx_t;

static inline uint64_t BDK_PKI_QPG_TBLBX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_QPG_TBLBX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=2047))
        return 0x86c000820000ll + 8ll * ((a) & 0x7ff);
    __bdk_csr_fatal("PKI_QPG_TBLBX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_QPG_TBLBX(a) bdk_pki_qpg_tblbx_t
#define bustype_BDK_PKI_QPG_TBLBX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_QPG_TBLBX(a) "PKI_QPG_TBLBX"
#define device_bar_BDK_PKI_QPG_TBLBX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_QPG_TBLBX(a) (a)
#define arguments_BDK_PKI_QPG_TBLBX(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_reasm_sop#
 *
 * PKI Reasm-Id SOP Register
 * Set when a SOP is detected on a Reasm-Id, where the Reasm-ID value sets the bit vector of this
 * register.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_reasm_sopx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t sop                   : 64; /**< [ 63:  0](RO/H) When set, a SOP was detected on a reasm-Id. When clear, a SOP has not yet been
                                                                 received, or an EOP was received on the Reasm-Id. The total number of available
                                                                 reassembly IDs is described with the PKI_REASM_E[NUM_REASM] enumeration. Not all
                                                                 bits are implemented. Only PKI_REASM_SOP(0)[SOP<13:0>] are present in this
                                                                 implementation. */
#else /* Word 0 - Little Endian */
        uint64_t sop                   : 64; /**< [ 63:  0](RO/H) When set, a SOP was detected on a reasm-Id. When clear, a SOP has not yet been
                                                                 received, or an EOP was received on the Reasm-Id. The total number of available
                                                                 reassembly IDs is described with the PKI_REASM_E[NUM_REASM] enumeration. Not all
                                                                 bits are implemented. Only PKI_REASM_SOP(0)[SOP<13:0>] are present in this
                                                                 implementation. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_reasm_sopx_s cn; */
} bdk_pki_reasm_sopx_t;

static inline uint64_t BDK_PKI_REASM_SOPX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_REASM_SOPX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86c000006000ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PKI_REASM_SOPX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_REASM_SOPX(a) bdk_pki_reasm_sopx_t
#define bustype_BDK_PKI_REASM_SOPX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_REASM_SOPX(a) "PKI_REASM_SOPX"
#define device_bar_BDK_PKI_REASM_SOPX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_REASM_SOPX(a) (a)
#define arguments_BDK_PKI_REASM_SOPX(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_req_wgt
 *
 * PKI Request Weight Register
 * Controls the round-robin weights between each PKI requestor. Intended for diagnostic tuning only.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_req_wgt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t wgt8                  : 4;  /**< [ 35: 32](R/W) Weight for ILK0. */
        uint64_t wgt7                  : 4;  /**< [ 31: 28](R/W) Weight for LBK. */
        uint64_t wgt6                  : 4;  /**< [ 27: 24](R/W) Weight for DPI. */
        uint64_t wgt5                  : 4;  /**< [ 23: 20](R/W) Weight for BGX5. */
        uint64_t wgt4                  : 4;  /**< [ 19: 16](R/W) Weight for BGX4. */
        uint64_t wgt3                  : 4;  /**< [ 15: 12](R/W) Weight for BGX3. */
        uint64_t wgt2                  : 4;  /**< [ 11:  8](R/W) Weight for BGX2. */
        uint64_t wgt1                  : 4;  /**< [  7:  4](R/W) Weight for BGX1. */
        uint64_t wgt0                  : 4;  /**< [  3:  0](R/W) Weight for BGX0. */
#else /* Word 0 - Little Endian */
        uint64_t wgt0                  : 4;  /**< [  3:  0](R/W) Weight for BGX0. */
        uint64_t wgt1                  : 4;  /**< [  7:  4](R/W) Weight for BGX1. */
        uint64_t wgt2                  : 4;  /**< [ 11:  8](R/W) Weight for BGX2. */
        uint64_t wgt3                  : 4;  /**< [ 15: 12](R/W) Weight for BGX3. */
        uint64_t wgt4                  : 4;  /**< [ 19: 16](R/W) Weight for BGX4. */
        uint64_t wgt5                  : 4;  /**< [ 23: 20](R/W) Weight for BGX5. */
        uint64_t wgt6                  : 4;  /**< [ 27: 24](R/W) Weight for DPI. */
        uint64_t wgt7                  : 4;  /**< [ 31: 28](R/W) Weight for LBK. */
        uint64_t wgt8                  : 4;  /**< [ 35: 32](R/W) Weight for ILK0. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_req_wgt_s cn; */
} bdk_pki_req_wgt_t;

#define BDK_PKI_REQ_WGT BDK_PKI_REQ_WGT_FUNC()
static inline uint64_t BDK_PKI_REQ_WGT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_REQ_WGT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000120ll;
    __bdk_csr_fatal("PKI_REQ_WGT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_REQ_WGT bdk_pki_req_wgt_t
#define bustype_BDK_PKI_REQ_WGT BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_REQ_WGT "PKI_REQ_WGT"
#define device_bar_BDK_PKI_REQ_WGT 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_REQ_WGT 0
#define arguments_BDK_PKI_REQ_WGT -1,-1,-1,-1

/**
 * Register (NCB) pki_sft_rst
 *
 * PKI Soft Reset Register
 * Internal:
 * Allows soft reset.  INTERNAL: See bug18607, PKI_SFT_RST definition, for further definition
 * (http://mcbuggin.caveonetworks.com/bug/18607).
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_sft_rst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) When set, PKI is busy completing reset. No access except the reading of this bit should
                                                                 occur to the PKI until this is clear. INTERNAL: The BUSY bit for this implementation is a
                                                                 placeholder and is not required to be implemented in HW. The soft reset pulse is short
                                                                 enough that we can guarantee that reset will complete below a subsequent RSL reference can
                                                                 be made. It is still useful for this bit to exist in case that property every changes and
                                                                 the reset requires a longer duration. For this implementation, SW will check the bit which
                                                                 will always report not BUSY allowing SW to proceed with its flow. */
        uint64_t reserved_33_62        : 30;
        uint64_t active                : 1;  /**< [ 32: 32](RO/H) When set, PKI is actively processing packet traffic. It is recommenced that software wait
                                                                 until ACTIVE is clear before setting RST. INTERNAL: ACTIVE is an OR of PKI_ACTIVE0..2. */
        uint64_t reserved_1_31         : 31;
        uint64_t rst                   : 1;  /**< [  0:  0](R/W1/H) Reset. When set to 1 by software, PKI will produce an internal reset pulse. */
#else /* Word 0 - Little Endian */
        uint64_t rst                   : 1;  /**< [  0:  0](R/W1/H) Reset. When set to 1 by software, PKI will produce an internal reset pulse. */
        uint64_t reserved_1_31         : 31;
        uint64_t active                : 1;  /**< [ 32: 32](RO/H) When set, PKI is actively processing packet traffic. It is recommenced that software wait
                                                                 until ACTIVE is clear before setting RST. INTERNAL: ACTIVE is an OR of PKI_ACTIVE0..2. */
        uint64_t reserved_33_62        : 30;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) When set, PKI is busy completing reset. No access except the reading of this bit should
                                                                 occur to the PKI until this is clear. INTERNAL: The BUSY bit for this implementation is a
                                                                 placeholder and is not required to be implemented in HW. The soft reset pulse is short
                                                                 enough that we can guarantee that reset will complete below a subsequent RSL reference can
                                                                 be made. It is still useful for this bit to exist in case that property every changes and
                                                                 the reset requires a longer duration. For this implementation, SW will check the bit which
                                                                 will always report not BUSY allowing SW to proceed with its flow. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_sft_rst_s cn; */
} bdk_pki_sft_rst_t;

#define BDK_PKI_SFT_RST BDK_PKI_SFT_RST_FUNC()
static inline uint64_t BDK_PKI_SFT_RST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_SFT_RST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000020ll;
    __bdk_csr_fatal("PKI_SFT_RST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_SFT_RST bdk_pki_sft_rst_t
#define bustype_BDK_PKI_SFT_RST BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_SFT_RST "PKI_SFT_RST"
#define device_bar_BDK_PKI_SFT_RST 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_SFT_RST 0
#define arguments_BDK_PKI_SFT_RST -1,-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist0
 *
 * PKI Histogram 0 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h1to63                : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 1 to 63 byte packets. Packet length includes FCS and any prepended
                                                                 PTP timestamp. */
#else /* Word 0 - Little Endian */
        uint64_t h1to63                : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 1 to 63 byte packets. Packet length includes FCS and any prepended
                                                                 PTP timestamp. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist0_s cn; */
} bdk_pki_statx_hist0_t;

static inline uint64_t BDK_PKI_STATX_HIST0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00000ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST0(a) bdk_pki_statx_hist0_t
#define bustype_BDK_PKI_STATX_HIST0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST0(a) "PKI_STATX_HIST0"
#define device_bar_BDK_PKI_STATX_HIST0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST0(a) (a)
#define arguments_BDK_PKI_STATX_HIST0(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist1
 *
 * PKI Histogram 1 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h64to127              : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 64 to 127 byte packets. */
#else /* Word 0 - Little Endian */
        uint64_t h64to127              : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 64 to 127 byte packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist1_s cn; */
} bdk_pki_statx_hist1_t;

static inline uint64_t BDK_PKI_STATX_HIST1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00008ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST1(a) bdk_pki_statx_hist1_t
#define bustype_BDK_PKI_STATX_HIST1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST1(a) "PKI_STATX_HIST1"
#define device_bar_BDK_PKI_STATX_HIST1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST1(a) (a)
#define arguments_BDK_PKI_STATX_HIST1(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist2
 *
 * PKI Histogram 2 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h128to255             : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 128 to 255 byte packets. */
#else /* Word 0 - Little Endian */
        uint64_t h128to255             : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 128 to 255 byte packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist2_s cn; */
} bdk_pki_statx_hist2_t;

static inline uint64_t BDK_PKI_STATX_HIST2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00010ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST2(a) bdk_pki_statx_hist2_t
#define bustype_BDK_PKI_STATX_HIST2(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST2(a) "PKI_STATX_HIST2"
#define device_bar_BDK_PKI_STATX_HIST2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST2(a) (a)
#define arguments_BDK_PKI_STATX_HIST2(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist3
 *
 * PKI Histogram 3 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h256to511             : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 256 to 511 byte packets. */
#else /* Word 0 - Little Endian */
        uint64_t h256to511             : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 256 to 511 byte packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist3_s cn; */
} bdk_pki_statx_hist3_t;

static inline uint64_t BDK_PKI_STATX_HIST3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00018ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST3", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST3(a) bdk_pki_statx_hist3_t
#define bustype_BDK_PKI_STATX_HIST3(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST3(a) "PKI_STATX_HIST3"
#define device_bar_BDK_PKI_STATX_HIST3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST3(a) (a)
#define arguments_BDK_PKI_STATX_HIST3(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist4
 *
 * PKI Histogram 4 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h512to1023            : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 512 to 1023 byte packets. */
#else /* Word 0 - Little Endian */
        uint64_t h512to1023            : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 512 to 1023 byte packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist4_s cn; */
} bdk_pki_statx_hist4_t;

static inline uint64_t BDK_PKI_STATX_HIST4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00020ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST4", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST4(a) bdk_pki_statx_hist4_t
#define bustype_BDK_PKI_STATX_HIST4(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST4(a) "PKI_STATX_HIST4"
#define device_bar_BDK_PKI_STATX_HIST4(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST4(a) (a)
#define arguments_BDK_PKI_STATX_HIST4(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist5
 *
 * PKI Histogram 5 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h1024to1518           : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 1024 to 1518 byte packets. */
#else /* Word 0 - Little Endian */
        uint64_t h1024to1518           : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 1024 to 1518 byte packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist5_s cn; */
} bdk_pki_statx_hist5_t;

static inline uint64_t BDK_PKI_STATX_HIST5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST5(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00028ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST5", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST5(a) bdk_pki_statx_hist5_t
#define bustype_BDK_PKI_STATX_HIST5(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST5(a) "PKI_STATX_HIST5"
#define device_bar_BDK_PKI_STATX_HIST5(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST5(a) (a)
#define arguments_BDK_PKI_STATX_HIST5(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_hist6
 *
 * PKI Histogram 6 Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_hist6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t h1519                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 1519 byte and above packets. */
#else /* Word 0 - Little Endian */
        uint64_t h1519                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped 1519 byte and above packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_hist6_s cn; */
} bdk_pki_statx_hist6_t;

static inline uint64_t BDK_PKI_STATX_HIST6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_HIST6(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00030ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_HIST6", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_HIST6(a) bdk_pki_statx_hist6_t
#define bustype_BDK_PKI_STATX_HIST6(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_HIST6(a) "PKI_STATX_HIST6"
#define device_bar_BDK_PKI_STATX_HIST6(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_HIST6(a) (a)
#define arguments_BDK_PKI_STATX_HIST6(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat0
 *
 * PKI Packets Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pkts                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets processed by PKI. */
#else /* Word 0 - Little Endian */
        uint64_t pkts                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets processed by PKI. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat0_s cn; */
} bdk_pki_statx_stat0_t;

static inline uint64_t BDK_PKI_STATX_STAT0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00038ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT0(a) bdk_pki_statx_stat0_t
#define bustype_BDK_PKI_STATX_STAT0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT0(a) "PKI_STATX_STAT0"
#define device_bar_BDK_PKI_STATX_STAT0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT0(a) (a)
#define arguments_BDK_PKI_STATX_STAT0(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat1
 *
 * PKI Octets Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t octs                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped octets received by PKI (good and bad). */
#else /* Word 0 - Little Endian */
        uint64_t octs                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped octets received by PKI (good and bad). */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat1_s cn; */
} bdk_pki_statx_stat1_t;

static inline uint64_t BDK_PKI_STATX_STAT1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00040ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT1(a) bdk_pki_statx_stat1_t
#define bustype_BDK_PKI_STATX_STAT1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT1(a) "PKI_STATX_STAT1"
#define device_bar_BDK_PKI_STATX_STAT1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT1(a) (a)
#define arguments_BDK_PKI_STATX_STAT1(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat10
 *
 * PKI Jabber Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t jabber                : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length > maximum and FCS error. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length > maximum and FCS error. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat10_s cn; */
} bdk_pki_statx_stat10_t;

static inline uint64_t BDK_PKI_STATX_STAT10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT10(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00088ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT10", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT10(a) bdk_pki_statx_stat10_t
#define bustype_BDK_PKI_STATX_STAT10(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT10(a) "PKI_STATX_STAT10"
#define device_bar_BDK_PKI_STATX_STAT10(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT10(a) (a)
#define arguments_BDK_PKI_STATX_STAT10(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat11
 *
 * PKI Oversize Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t oversz                : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length > maximum and no FCS error. */
#else /* Word 0 - Little Endian */
        uint64_t oversz                : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length > maximum and no FCS error. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat11_s cn; */
} bdk_pki_statx_stat11_t;

static inline uint64_t BDK_PKI_STATX_STAT11(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT11(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00090ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT11", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT11(a) bdk_pki_statx_stat11_t
#define bustype_BDK_PKI_STATX_STAT11(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT11(a) "PKI_STATX_STAT11"
#define device_bar_BDK_PKI_STATX_STAT11(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT11(a) (a)
#define arguments_BDK_PKI_STATX_STAT11(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat12
 *
 * PKI L2 Error Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t l2err                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with receive errors (WQE[ERRLEV]==RE or L2) not covered by
                                                                 more specific length or FCS statistic error registers. */
#else /* Word 0 - Little Endian */
        uint64_t l2err                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with receive errors (WQE[ERRLEV]==RE or L2) not covered by
                                                                 more specific length or FCS statistic error registers. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat12_s cn; */
} bdk_pki_statx_stat12_t;

static inline uint64_t BDK_PKI_STATX_STAT12(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT12(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00098ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT12", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT12(a) bdk_pki_statx_stat12_t
#define bustype_BDK_PKI_STATX_STAT12(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT12(a) "PKI_STATX_STAT12"
#define device_bar_BDK_PKI_STATX_STAT12(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT12(a) (a)
#define arguments_BDK_PKI_STATX_STAT12(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat13
 *
 * PKI Special Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t spec                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with special handling. For profiling and diagnostic use
                                                                 only.
                                                                 INTERNAL: Counts packets completing IPE processing with WQE[SH] set. */
#else /* Word 0 - Little Endian */
        uint64_t spec                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with special handling. For profiling and diagnostic use
                                                                 only.
                                                                 INTERNAL: Counts packets completing IPE processing with WQE[SH] set. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat13_s cn; */
} bdk_pki_statx_stat13_t;

static inline uint64_t BDK_PKI_STATX_STAT13(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT13(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e000a0ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT13", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT13(a) bdk_pki_statx_stat13_t
#define bustype_BDK_PKI_STATX_STAT13(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT13(a) "PKI_STATX_STAT13"
#define device_bar_BDK_PKI_STATX_STAT13(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT13(a) (a)
#define arguments_BDK_PKI_STATX_STAT13(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat14
 *
 * PKI Dropped L2 Broadcast Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_bcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with L2 broadcast DMAC that were dropped by RED, buffer exhaustion, or
                                                                 PKI_CL()_STYLE()_CFG[DROP]. See WQE[L2B] for the definition of L2 broadcast. */
#else /* Word 0 - Little Endian */
        uint64_t drp_bcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with L2 broadcast DMAC that were dropped by RED, buffer exhaustion, or
                                                                 PKI_CL()_STYLE()_CFG[DROP]. See WQE[L2B] for the definition of L2 broadcast. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat14_s cn; */
} bdk_pki_statx_stat14_t;

static inline uint64_t BDK_PKI_STATX_STAT14(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT14(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e000a8ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT14", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT14(a) bdk_pki_statx_stat14_t
#define bustype_BDK_PKI_STATX_STAT14(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT14(a) "PKI_STATX_STAT14"
#define device_bar_BDK_PKI_STATX_STAT14(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT14(a) (a)
#define arguments_BDK_PKI_STATX_STAT14(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat15
 *
 * PKI Dropped L2 Multicast Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_mcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with L2 multicast DMAC that were dropped by RED, buffer exhaustion, or
                                                                 PKI_CL()_STYLE()_CFG[DROP]. See WQE[L2M] for the definition of L2 multicast. */
#else /* Word 0 - Little Endian */
        uint64_t drp_mcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with L2 multicast DMAC that were dropped by RED, buffer exhaustion, or
                                                                 PKI_CL()_STYLE()_CFG[DROP]. See WQE[L2M] for the definition of L2 multicast. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat15_s cn; */
} bdk_pki_statx_stat15_t;

static inline uint64_t BDK_PKI_STATX_STAT15(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT15(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e000b0ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT15", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT15(a) bdk_pki_statx_stat15_t
#define bustype_BDK_PKI_STATX_STAT15(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT15(a) "PKI_STATX_STAT15"
#define device_bar_BDK_PKI_STATX_STAT15(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT15(a) (a)
#define arguments_BDK_PKI_STATX_STAT15(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat16
 *
 * PKI Dropped L3 Broadcast Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_bcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with IPv4 L3 broadcast destination address that were dropped due to RED
                                                                 or buffer exhaustion. See WQE[L3B] for the definition of L2 multicast. */
#else /* Word 0 - Little Endian */
        uint64_t drp_bcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with IPv4 L3 broadcast destination address that were dropped due to RED
                                                                 or buffer exhaustion. See WQE[L3B] for the definition of L2 multicast. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat16_s cn; */
} bdk_pki_statx_stat16_t;

static inline uint64_t BDK_PKI_STATX_STAT16(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT16(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e000b8ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT16", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT16(a) bdk_pki_statx_stat16_t
#define bustype_BDK_PKI_STATX_STAT16(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT16(a) "PKI_STATX_STAT16"
#define device_bar_BDK_PKI_STATX_STAT16(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT16(a) (a)
#define arguments_BDK_PKI_STATX_STAT16(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat17
 *
 * PKI Dropped L3 Multicast Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_mcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with IPv4 or IPv6 L3 multicast destination address that were dropped due
                                                                 to RED or buffer exhaustion. See WQE[L3M] for the definition of L3 multicast. */
#else /* Word 0 - Little Endian */
        uint64_t drp_mcast             : 48; /**< [ 47:  0](R/W/H) Number of packets with IPv4 or IPv6 L3 multicast destination address that were dropped due
                                                                 to RED or buffer exhaustion. See WQE[L3M] for the definition of L3 multicast. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat17_s cn; */
} bdk_pki_statx_stat17_t;

static inline uint64_t BDK_PKI_STATX_STAT17(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT17(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e000c0ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT17", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT17(a) bdk_pki_statx_stat17_t
#define bustype_BDK_PKI_STATX_STAT17(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT17(a) "PKI_STATX_STAT17"
#define device_bar_BDK_PKI_STATX_STAT17(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT17(a) (a)
#define arguments_BDK_PKI_STATX_STAT17(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat18
 *
 * PKI Dropped Special Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat18_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_spec              : 48; /**< [ 47:  0](R/W/H) Number of packets dropped with special handling. For profiling and diagnostic use only.
                                                                 INTERNAL: Counts packets with dropped after completing IPE processing with WQE[SH] set. */
#else /* Word 0 - Little Endian */
        uint64_t drp_spec              : 48; /**< [ 47:  0](R/W/H) Number of packets dropped with special handling. For profiling and diagnostic use only.
                                                                 INTERNAL: Counts packets with dropped after completing IPE processing with WQE[SH] set. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat18_s cn; */
} bdk_pki_statx_stat18_t;

static inline uint64_t BDK_PKI_STATX_STAT18(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT18(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e000c8ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT18", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT18(a) bdk_pki_statx_stat18_t
#define bustype_BDK_PKI_STATX_STAT18(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT18(a) "PKI_STATX_STAT18"
#define device_bar_BDK_PKI_STATX_STAT18(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT18(a) (a)
#define arguments_BDK_PKI_STATX_STAT18(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat2
 *
 * PKI Raw Packets Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t raw                   : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with WQE[RAW] set. */
#else /* Word 0 - Little Endian */
        uint64_t raw                   : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with WQE[RAW] set. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat2_s cn; */
} bdk_pki_statx_stat2_t;

static inline uint64_t BDK_PKI_STATX_STAT2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00048ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT2(a) bdk_pki_statx_stat2_t
#define bustype_BDK_PKI_STATX_STAT2(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT2(a) "PKI_STATX_STAT2"
#define device_bar_BDK_PKI_STATX_STAT2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT2(a) (a)
#define arguments_BDK_PKI_STATX_STAT2(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat3
 *
 * PKI Dropped Packets Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_pkts              : 48; /**< [ 47:  0](R/W/H) Inbound packets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP]. */
#else /* Word 0 - Little Endian */
        uint64_t drp_pkts              : 48; /**< [ 47:  0](R/W/H) Inbound packets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat3_s cn; */
} bdk_pki_statx_stat3_t;

static inline uint64_t BDK_PKI_STATX_STAT3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00050ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT3", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT3(a) bdk_pki_statx_stat3_t
#define bustype_BDK_PKI_STATX_STAT3(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT3(a) "PKI_STATX_STAT3"
#define device_bar_BDK_PKI_STATX_STAT3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT3(a) (a)
#define arguments_BDK_PKI_STATX_STAT3(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat4
 *
 * PKI Dropped Octets Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t drp_octs              : 48; /**< [ 47:  0](R/W/H) Inbound octets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP]. */
#else /* Word 0 - Little Endian */
        uint64_t drp_octs              : 48; /**< [ 47:  0](R/W/H) Inbound octets dropped by RED, buffer exhaustion, or PKI_CL()_STYLE()_CFG[DROP]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat4_s cn; */
} bdk_pki_statx_stat4_t;

static inline uint64_t BDK_PKI_STATX_STAT4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00058ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT4", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT4(a) bdk_pki_statx_stat4_t
#define bustype_BDK_PKI_STATX_STAT4(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT4(a) "PKI_STATX_STAT4"
#define device_bar_BDK_PKI_STATX_STAT4(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT4(a) (a)
#define arguments_BDK_PKI_STATX_STAT4(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat5
 *
 * PKI L2 Broadcast Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t bcast                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped L2 broadcast packets. Does not include multicast packets. See
                                                                 WQE[L2B] for the definition of L2 broadcast. */
#else /* Word 0 - Little Endian */
        uint64_t bcast                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped L2 broadcast packets. Does not include multicast packets. See
                                                                 WQE[L2B] for the definition of L2 broadcast. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat5_s cn; */
} bdk_pki_statx_stat5_t;

static inline uint64_t BDK_PKI_STATX_STAT5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT5(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00060ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT5", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT5(a) bdk_pki_statx_stat5_t
#define bustype_BDK_PKI_STATX_STAT5(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT5(a) "PKI_STATX_STAT5"
#define device_bar_BDK_PKI_STATX_STAT5(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT5(a) (a)
#define arguments_BDK_PKI_STATX_STAT5(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat6
 *
 * PKI L2 Multicast Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t mcast                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped L2 multicast packets. Does not include broadcast packets. See
                                                                 WQE[L2M] for the definition of L2 multicast. */
#else /* Word 0 - Little Endian */
        uint64_t mcast                 : 48; /**< [ 47:  0](R/W/H) Number of non-dropped L2 multicast packets. Does not include broadcast packets. See
                                                                 WQE[L2M] for the definition of L2 multicast. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat6_s cn; */
} bdk_pki_statx_stat6_t;

static inline uint64_t BDK_PKI_STATX_STAT6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT6(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00068ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT6", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT6(a) bdk_pki_statx_stat6_t
#define bustype_BDK_PKI_STATX_STAT6(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT6(a) "PKI_STATX_STAT6"
#define device_bar_BDK_PKI_STATX_STAT6(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT6(a) (a)
#define arguments_BDK_PKI_STATX_STAT6(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat7
 *
 * PKI FCS Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t fcs                   : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with an FCS opcode error, excluding fragments or overruns. */
#else /* Word 0 - Little Endian */
        uint64_t fcs                   : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with an FCS opcode error, excluding fragments or overruns. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat7_s cn; */
} bdk_pki_statx_stat7_t;

static inline uint64_t BDK_PKI_STATX_STAT7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT7(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00070ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT7", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT7(a) bdk_pki_statx_stat7_t
#define bustype_BDK_PKI_STATX_STAT7(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT7(a) "PKI_STATX_STAT7"
#define device_bar_BDK_PKI_STATX_STAT7(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT7(a) (a)
#define arguments_BDK_PKI_STATX_STAT7(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat8
 *
 * PKI Frac Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t frag                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length < minimum and FCS error */
#else /* Word 0 - Little Endian */
        uint64_t frag                  : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length < minimum and FCS error */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat8_s cn; */
} bdk_pki_statx_stat8_t;

static inline uint64_t BDK_PKI_STATX_STAT8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT8(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00078ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT8", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT8(a) bdk_pki_statx_stat8_t
#define bustype_BDK_PKI_STATX_STAT8(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT8(a) "PKI_STATX_STAT8"
#define device_bar_BDK_PKI_STATX_STAT8(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT8(a) (a)
#define arguments_BDK_PKI_STATX_STAT8(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat#_stat9
 *
 * PKI Undersize Statistic Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_statx_stat9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t undersz               : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length < minimum and no FCS error. */
#else /* Word 0 - Little Endian */
        uint64_t undersz               : 48; /**< [ 47:  0](R/W/H) Number of non-dropped packets with length < minimum and no FCS error. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_statx_stat9_s cn; */
} bdk_pki_statx_stat9_t;

static inline uint64_t BDK_PKI_STATX_STAT9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STATX_STAT9(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000e00080ll + 0x100ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STATX_STAT9", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STATX_STAT9(a) bdk_pki_statx_stat9_t
#define bustype_BDK_PKI_STATX_STAT9(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STATX_STAT9(a) "PKI_STATX_STAT9"
#define device_bar_BDK_PKI_STATX_STAT9(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STATX_STAT9(a) (a)
#define arguments_BDK_PKI_STATX_STAT9(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_stat_ctl
 *
 * PKI Stat Control Register
 * Controls how the PKI statistics counters are handled.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_stat_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t mode                  : 2;  /**< [  1:  0](R/W) The PKI_STAT*_X registers can be indexed either by port kind (pkind), or final style.
                                                                 (Does not apply to the PKI_STAT_INB* nor PKI_DSTAT_* registers.)

                                                                 _ 0x0 = X represents the packet's pkind.
                                                                 _ 0x1 = X represents the low 6-bits of packet's final style.
                                                                 _ 0x2 = X represents the packet's PKI_QPG_TBLB()[DSTAT_ID].
                                                                   PKI_STAT()_STAT0..PKI_STAT()_STAT18 and PKI_STAT()_HIST0..PKI_STAT()_HIST6 will only
                                                                   be incremented if the DSTAT_ID is less than 64; i.e. fits in the index of the
                                                                   PKI_STAT()_STAT0 etc.
                                                                 _ 0x3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t mode                  : 2;  /**< [  1:  0](R/W) The PKI_STAT*_X registers can be indexed either by port kind (pkind), or final style.
                                                                 (Does not apply to the PKI_STAT_INB* nor PKI_DSTAT_* registers.)

                                                                 _ 0x0 = X represents the packet's pkind.
                                                                 _ 0x1 = X represents the low 6-bits of packet's final style.
                                                                 _ 0x2 = X represents the packet's PKI_QPG_TBLB()[DSTAT_ID].
                                                                   PKI_STAT()_STAT0..PKI_STAT()_STAT18 and PKI_STAT()_HIST0..PKI_STAT()_HIST6 will only
                                                                   be incremented if the DSTAT_ID is less than 64; i.e. fits in the index of the
                                                                   PKI_STAT()_STAT0 etc.
                                                                 _ 0x3 = Reserved. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_stat_ctl_s cn; */
} bdk_pki_stat_ctl_t;

#define BDK_PKI_STAT_CTL BDK_PKI_STAT_CTL_FUNC()
static inline uint64_t BDK_PKI_STAT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STAT_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000110ll;
    __bdk_csr_fatal("PKI_STAT_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_STAT_CTL bdk_pki_stat_ctl_t
#define bustype_BDK_PKI_STAT_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STAT_CTL "PKI_STAT_CTL"
#define device_bar_BDK_PKI_STAT_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STAT_CTL 0
#define arguments_BDK_PKI_STAT_CTL -1,-1,-1,-1

/**
 * Register (NCB) pki_style#_buf
 *
 * PKI Per-Style Buffer Configuration Register
 * Internal:
 * INTERNAL: This register is in BE.
 * Configures skip amounts and other information based on the final style, stored in
 * WQE[STYLE].
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_stylex_buf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t wqe_bend              : 1;  /**< [ 32: 32](R/W) WQE header big-endian. Changes write operations of WQE to L2C to be big-endian.
                                                                 Does not change the data, which is properly endian neutral. */
        uint64_t wqe_hsz               : 2;  /**< [ 31: 30](R/W) Work queue header size:
                                                                 0x0 = WORD0..4, standard WQE_S. Note FIRST_SKIP may be set to not include WORD4 in memory.
                                                                 0x1 = WORD0..5.
                                                                 0x2 = Reserved.
                                                                 0x3 = Reserved.

                                                                 INTERNAL: Selects which PIX words are transferred to the PKI BE. If a word is not
                                                                 transferred and the word will reach memory (FIRST_SKIP is greater than that word number),
                                                                 then the final WQE memory word will be zero, not the PIX register contents. */
        uint64_t wqe_skip              : 2;  /**< [ 29: 28](R/W) WQE start offset. The number of 128-byte cache lines to skip between the buffer pointer
                                                                 and WORD0 of the work-queue entry.

                                                                 If [DIS_WQ_DAT]=1, legal values must satisfy:
                                                                   * [MB_SIZE] >= (PKI_STYLE()_BUF[WQE_SKIP] * (128/8)) + 18

                                                                 If [DIS_WQ_DAT]=0, legal values must satisfy:
                                                                   * ([WQE_SKIP] * (128/8)) + 4 <= [FIRST_SKIP], to insure the minimum of four
                                                                     work-queue entry words will fit within [FIRST_SKIP]. */
        uint64_t first_skip            : 6;  /**< [ 27: 22](R/W) The number of eight-byte words from the top of the first MBUF that the PKI stores the next
                                                                 pointer.

                                                                 If [DIS_WQ_DAT]=1, legal values must satisfy:
                                                                   * [FIRST_SKIP] <= PKI_STYLE()_BUF[MB_SIZE] - 18.

                                                                 If [DIS_WQ_DAT]=0, legal values must satisfy:
                                                                   * [FIRST_SKIP] <= PKI_STYLE()_BUF[MB_SIZE] - 18.
                                                                   * ([WQE_SKIP] * (128/8)) + X <= [FIRST_SKIP].
                                                                   _ X must be at least 0x4 to insure the minimum of four work-queue entry,
                                                                     but 0x5 is recommended minimum. X = 0x4 will drop WQE WORD4, for use in
                                                                     backward compatible applications. */
        uint64_t later_skip            : 6;  /**< [ 21: 16](R/W) The number of eight-byte words from the top of any MBUF that is not the first MBUF that
                                                                 PKI writes the next-pointer to. Legal values are 0 to PKI_STYLE()_BUF[MB_SIZE] - 18. */
        uint64_t opc_mode              : 2;  /**< [ 15: 14](R/W) Select the style of write to the L2C.
                                                                 0x0 = all packet data and next-buffer pointers are written through to memory.
                                                                 0x1 = all packet data and next-buffer pointers are written into the cache.
                                                                 0x2 = the first aligned cache block holding the WQE and/or front packet data are written
                                                                 to
                                                                 the L2 cache. All remaining cache blocks are not written to the L2 cache.
                                                                 0x3 = the first two aligned cache blocks holding the WQE and front packet data are written
                                                                 to the L2 cache. All remaining cache blocks are not written to the L2 cache. */
        uint64_t dis_wq_dat            : 1;  /**< [ 13: 13](R/W) Separate first data buffer from the work queue entry.
                                                                 0 = The packet link pointer will be at word [FIRST_SKIP] immediately followed by packet
                                                                 data, in the same buffer as the work queue entry.
                                                                 1 = The packet link pointer will be at word [FIRST_SKIP] in a new buffer separate from the
                                                                 work queue entry. Words following the WQE in the same cache line will be zeroed, other
                                                                 lines in the buffer will not be modified and will retain stale data (from the buffer's
                                                                 previous use). This setting may decrease the peak PKI performance by up to half on small
                                                                 packets. */
        uint64_t mb_size               : 13; /**< [ 12:  0](R/W) The number of eight-byte words between the start of a buffer and the last word
                                                                 that PKI may write into that buffer. The total amount of data stored by PKI into
                                                                 the buffer will be MB_SIZE minus FIRST_SKIP or LATER_SKIP.
                                                                 This must be even, in the range of 32 to 4096. This must be less than or equal
                                                                 to the maximum size of every free page in every FPA pool this style may use.

                                                                 If [DIS_WQ_DAT]=1, legal values must satisfy:
                                                                   * MB_SIZE >= (PKI_STYLE()_BUF[WQE_SKIP] * (128/8)) + 18
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[FIRST_SKIP] + 18.
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[LATER_SKIP] + 18.

                                                                 If [DIS_WQ_DAT]=0, legal values must satisfy:
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[FIRST_SKIP] + 18.
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[LATER_SKIP] + 18. */
#else /* Word 0 - Little Endian */
        uint64_t mb_size               : 13; /**< [ 12:  0](R/W) The number of eight-byte words between the start of a buffer and the last word
                                                                 that PKI may write into that buffer. The total amount of data stored by PKI into
                                                                 the buffer will be MB_SIZE minus FIRST_SKIP or LATER_SKIP.
                                                                 This must be even, in the range of 32 to 4096. This must be less than or equal
                                                                 to the maximum size of every free page in every FPA pool this style may use.

                                                                 If [DIS_WQ_DAT]=1, legal values must satisfy:
                                                                   * MB_SIZE >= (PKI_STYLE()_BUF[WQE_SKIP] * (128/8)) + 18
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[FIRST_SKIP] + 18.
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[LATER_SKIP] + 18.

                                                                 If [DIS_WQ_DAT]=0, legal values must satisfy:
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[FIRST_SKIP] + 18.
                                                                   * MB_SIZE >= PKI_STYLE()_BUF[LATER_SKIP] + 18. */
        uint64_t dis_wq_dat            : 1;  /**< [ 13: 13](R/W) Separate first data buffer from the work queue entry.
                                                                 0 = The packet link pointer will be at word [FIRST_SKIP] immediately followed by packet
                                                                 data, in the same buffer as the work queue entry.
                                                                 1 = The packet link pointer will be at word [FIRST_SKIP] in a new buffer separate from the
                                                                 work queue entry. Words following the WQE in the same cache line will be zeroed, other
                                                                 lines in the buffer will not be modified and will retain stale data (from the buffer's
                                                                 previous use). This setting may decrease the peak PKI performance by up to half on small
                                                                 packets. */
        uint64_t opc_mode              : 2;  /**< [ 15: 14](R/W) Select the style of write to the L2C.
                                                                 0x0 = all packet data and next-buffer pointers are written through to memory.
                                                                 0x1 = all packet data and next-buffer pointers are written into the cache.
                                                                 0x2 = the first aligned cache block holding the WQE and/or front packet data are written
                                                                 to
                                                                 the L2 cache. All remaining cache blocks are not written to the L2 cache.
                                                                 0x3 = the first two aligned cache blocks holding the WQE and front packet data are written
                                                                 to the L2 cache. All remaining cache blocks are not written to the L2 cache. */
        uint64_t later_skip            : 6;  /**< [ 21: 16](R/W) The number of eight-byte words from the top of any MBUF that is not the first MBUF that
                                                                 PKI writes the next-pointer to. Legal values are 0 to PKI_STYLE()_BUF[MB_SIZE] - 18. */
        uint64_t first_skip            : 6;  /**< [ 27: 22](R/W) The number of eight-byte words from the top of the first MBUF that the PKI stores the next
                                                                 pointer.

                                                                 If [DIS_WQ_DAT]=1, legal values must satisfy:
                                                                   * [FIRST_SKIP] <= PKI_STYLE()_BUF[MB_SIZE] - 18.

                                                                 If [DIS_WQ_DAT]=0, legal values must satisfy:
                                                                   * [FIRST_SKIP] <= PKI_STYLE()_BUF[MB_SIZE] - 18.
                                                                   * ([WQE_SKIP] * (128/8)) + X <= [FIRST_SKIP].
                                                                   _ X must be at least 0x4 to insure the minimum of four work-queue entry,
                                                                     but 0x5 is recommended minimum. X = 0x4 will drop WQE WORD4, for use in
                                                                     backward compatible applications. */
        uint64_t wqe_skip              : 2;  /**< [ 29: 28](R/W) WQE start offset. The number of 128-byte cache lines to skip between the buffer pointer
                                                                 and WORD0 of the work-queue entry.

                                                                 If [DIS_WQ_DAT]=1, legal values must satisfy:
                                                                   * [MB_SIZE] >= (PKI_STYLE()_BUF[WQE_SKIP] * (128/8)) + 18

                                                                 If [DIS_WQ_DAT]=0, legal values must satisfy:
                                                                   * ([WQE_SKIP] * (128/8)) + 4 <= [FIRST_SKIP], to insure the minimum of four
                                                                     work-queue entry words will fit within [FIRST_SKIP]. */
        uint64_t wqe_hsz               : 2;  /**< [ 31: 30](R/W) Work queue header size:
                                                                 0x0 = WORD0..4, standard WQE_S. Note FIRST_SKIP may be set to not include WORD4 in memory.
                                                                 0x1 = WORD0..5.
                                                                 0x2 = Reserved.
                                                                 0x3 = Reserved.

                                                                 INTERNAL: Selects which PIX words are transferred to the PKI BE. If a word is not
                                                                 transferred and the word will reach memory (FIRST_SKIP is greater than that word number),
                                                                 then the final WQE memory word will be zero, not the PIX register contents. */
        uint64_t wqe_bend              : 1;  /**< [ 32: 32](R/W) WQE header big-endian. Changes write operations of WQE to L2C to be big-endian.
                                                                 Does not change the data, which is properly endian neutral. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_stylex_buf_s cn; */
} bdk_pki_stylex_buf_t;

static inline uint64_t BDK_PKI_STYLEX_BUF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STYLEX_BUF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000024000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STYLEX_BUF", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STYLEX_BUF(a) bdk_pki_stylex_buf_t
#define bustype_BDK_PKI_STYLEX_BUF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STYLEX_BUF(a) "PKI_STYLEX_BUF"
#define device_bar_BDK_PKI_STYLEX_BUF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STYLEX_BUF(a) (a)
#define arguments_BDK_PKI_STYLEX_BUF(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_style#_tag_mask
 *
 * PKI Per-Style Tag Generation Mask Registers
 * Internal:
 * INTERNAL: This register is in BE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_stylex_tag_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mask                  : 16; /**< [ 15:  0](R/W) When set, each bit excludes corresponding bit of the tuple computed tag from being
                                                                 included in the final tag. PKI_CL()_STYLE()_CFG2 [TAG_MASKEN] must be set. Does
                                                                 not affect tags from packets with a PKI_INST_HDR_S when PKI_INST_HDR_S[UTAG] is set. */
#else /* Word 0 - Little Endian */
        uint64_t mask                  : 16; /**< [ 15:  0](R/W) When set, each bit excludes corresponding bit of the tuple computed tag from being
                                                                 included in the final tag. PKI_CL()_STYLE()_CFG2 [TAG_MASKEN] must be set. Does
                                                                 not affect tags from packets with a PKI_INST_HDR_S when PKI_INST_HDR_S[UTAG] is set. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_stylex_tag_mask_s cn; */
} bdk_pki_stylex_tag_mask_t;

static inline uint64_t BDK_PKI_STYLEX_TAG_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STYLEX_TAG_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000021000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STYLEX_TAG_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STYLEX_TAG_MASK(a) bdk_pki_stylex_tag_mask_t
#define bustype_BDK_PKI_STYLEX_TAG_MASK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STYLEX_TAG_MASK(a) "PKI_STYLEX_TAG_MASK"
#define device_bar_BDK_PKI_STYLEX_TAG_MASK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STYLEX_TAG_MASK(a) (a)
#define arguments_BDK_PKI_STYLEX_TAG_MASK(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_style#_tag_sel
 *
 * PKI Per-Style Configuration 2 Registers
 * Internal:
 * INTERNAL: This register is in BE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_stylex_tag_sel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t tag_idx3              : 3;  /**< [ 26: 24](R/W) Index for TAG_INC<3>. */
        uint64_t reserved_19_23        : 5;
        uint64_t tag_idx2              : 3;  /**< [ 18: 16](R/W) Index for TAG_INC<2>. */
        uint64_t reserved_11_15        : 5;
        uint64_t tag_idx1              : 3;  /**< [ 10:  8](R/W) Index for TAG_INC<1>. */
        uint64_t reserved_3_7          : 5;
        uint64_t tag_idx0              : 3;  /**< [  2:  0](R/W) Index for TAG_INC<0>. This value is multipled by 4 to index into PKI_TAG_INC()_MASK.
                                                                 See WQE[TAG]. */
#else /* Word 0 - Little Endian */
        uint64_t tag_idx0              : 3;  /**< [  2:  0](R/W) Index for TAG_INC<0>. This value is multipled by 4 to index into PKI_TAG_INC()_MASK.
                                                                 See WQE[TAG]. */
        uint64_t reserved_3_7          : 5;
        uint64_t tag_idx1              : 3;  /**< [ 10:  8](R/W) Index for TAG_INC<1>. */
        uint64_t reserved_11_15        : 5;
        uint64_t tag_idx2              : 3;  /**< [ 18: 16](R/W) Index for TAG_INC<2>. */
        uint64_t reserved_19_23        : 5;
        uint64_t tag_idx3              : 3;  /**< [ 26: 24](R/W) Index for TAG_INC<3>. */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_stylex_tag_sel_s cn; */
} bdk_pki_stylex_tag_sel_t;

static inline uint64_t BDK_PKI_STYLEX_TAG_SEL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STYLEX_TAG_SEL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000020000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STYLEX_TAG_SEL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STYLEX_TAG_SEL(a) bdk_pki_stylex_tag_sel_t
#define bustype_BDK_PKI_STYLEX_TAG_SEL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STYLEX_TAG_SEL(a) "PKI_STYLEX_TAG_SEL"
#define device_bar_BDK_PKI_STYLEX_TAG_SEL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STYLEX_TAG_SEL(a) (a)
#define arguments_BDK_PKI_STYLEX_TAG_SEL(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_style#_wq2
 *
 * PKI Per-Style WQ Word 2 Registers
 * Internal:
 * INTERNAL: This register is in BE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_stylex_wq2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Data for WQ2<63:0>. This is ORed over any parser calculated WQ2<63:0> fields, and is used
                                                                 to emulate as if the parser set a WQ field such as WQE[PF1]. PKI_INST_HDR_S packets may
                                                                 also want to use this mode to set WQE[LCTY] to IP when PKI parsing IP is disabled. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Data for WQ2<63:0>. This is ORed over any parser calculated WQ2<63:0> fields, and is used
                                                                 to emulate as if the parser set a WQ field such as WQE[PF1]. PKI_INST_HDR_S packets may
                                                                 also want to use this mode to set WQE[LCTY] to IP when PKI parsing IP is disabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_stylex_wq2_s cn; */
} bdk_pki_stylex_wq2_t;

static inline uint64_t BDK_PKI_STYLEX_WQ2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STYLEX_WQ2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000022000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STYLEX_WQ2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STYLEX_WQ2(a) bdk_pki_stylex_wq2_t
#define bustype_BDK_PKI_STYLEX_WQ2(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STYLEX_WQ2(a) "PKI_STYLEX_WQ2"
#define device_bar_BDK_PKI_STYLEX_WQ2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STYLEX_WQ2(a) (a)
#define arguments_BDK_PKI_STYLEX_WQ2(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_style#_wq4
 *
 * PKI Per-Style WQ Word 4 Registers
 * Internal:
 * INTERNAL: This register is in BE.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_stylex_wq4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Data for WQ4<63:0>. This is ORed over any parser calculated WQ4<63:0> fields, and is used
                                                                 to emulate as if the parser set a WQ pointer field. PKI_INST_HDR_S packets may also want
                                                                 to use this mode to set WQE[LCPTR] to the start of IP when PKI parsing IP is disabled. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Data for WQ4<63:0>. This is ORed over any parser calculated WQ4<63:0> fields, and is used
                                                                 to emulate as if the parser set a WQ pointer field. PKI_INST_HDR_S packets may also want
                                                                 to use this mode to set WQE[LCPTR] to the start of IP when PKI parsing IP is disabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_stylex_wq4_s cn; */
} bdk_pki_stylex_wq4_t;

static inline uint64_t BDK_PKI_STYLEX_WQ4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_STYLEX_WQ4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x86c000023000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("PKI_STYLEX_WQ4", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_STYLEX_WQ4(a) bdk_pki_stylex_wq4_t
#define bustype_BDK_PKI_STYLEX_WQ4(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_STYLEX_WQ4(a) "PKI_STYLEX_WQ4"
#define device_bar_BDK_PKI_STYLEX_WQ4(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_STYLEX_WQ4(a) (a)
#define arguments_BDK_PKI_STYLEX_WQ4(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_tag_inc#_ctl
 *
 * PKI Tag Inclusion Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_tag_incx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t ptr_sel               : 4;  /**< [ 11:  8](R/W) Which pointer to use for the bitmask in PKI_TAG_INC()_MASK.
                                                                 0 = Absolute from start of packet.
                                                                 1-7 = Reserved.
                                                                 8 = Relative to start of WQE[LAPTR]. LAPTR must be valid (see WQE[LAPTR]) or mask is
                                                                 ignored.
                                                                 9 = Relative to start of WQE[LBPTR]. LBPTR must be valid (see WQE[LBPTR]) or mask is
                                                                 ignored.
                                                                 10 = Relative to start of WQE[LCPTR]. LCPTR must be valid (see WQE[LCPTR]) or mask is
                                                                 ignored.
                                                                 11 = Relative to start of WQE[LDPTR]. LDPTR must be valid (see WQE[LDPTR]) or mask is
                                                                 ignored.
                                                                 12 = Relative to start of WQE[LEPTR]. LEPTR must be valid (see WQE[LEPTR]) or mask is
                                                                 ignored.
                                                                 13 = Relative to start of WQE[LFPTR]. LFPTR must be valid (see WQE[LFPTR]) or mask is
                                                                 ignored.
                                                                 14 = Relative to start of WQE[LGPTR]. LGPTR must be valid (see WQE[LGPTR]) or mask is
                                                                 ignored.
                                                                 15 = Relative to start of WQE[VLPTR]. VLPTR must be valid (see WQE[VLPTR]) or mask is
                                                                 ignored.
                                                                 INTERNAL: Note excluding 0, the encoding matches the byte number to read from WQE WORD4. */
        uint64_t offset                : 8;  /**< [  7:  0](R/W) Offset for PKI_TAG_INC()_MASK. Number of bytes to add to the selected pointer before
                                                                 applying the mask. */
#else /* Word 0 - Little Endian */
        uint64_t offset                : 8;  /**< [  7:  0](R/W) Offset for PKI_TAG_INC()_MASK. Number of bytes to add to the selected pointer before
                                                                 applying the mask. */
        uint64_t ptr_sel               : 4;  /**< [ 11:  8](R/W) Which pointer to use for the bitmask in PKI_TAG_INC()_MASK.
                                                                 0 = Absolute from start of packet.
                                                                 1-7 = Reserved.
                                                                 8 = Relative to start of WQE[LAPTR]. LAPTR must be valid (see WQE[LAPTR]) or mask is
                                                                 ignored.
                                                                 9 = Relative to start of WQE[LBPTR]. LBPTR must be valid (see WQE[LBPTR]) or mask is
                                                                 ignored.
                                                                 10 = Relative to start of WQE[LCPTR]. LCPTR must be valid (see WQE[LCPTR]) or mask is
                                                                 ignored.
                                                                 11 = Relative to start of WQE[LDPTR]. LDPTR must be valid (see WQE[LDPTR]) or mask is
                                                                 ignored.
                                                                 12 = Relative to start of WQE[LEPTR]. LEPTR must be valid (see WQE[LEPTR]) or mask is
                                                                 ignored.
                                                                 13 = Relative to start of WQE[LFPTR]. LFPTR must be valid (see WQE[LFPTR]) or mask is
                                                                 ignored.
                                                                 14 = Relative to start of WQE[LGPTR]. LGPTR must be valid (see WQE[LGPTR]) or mask is
                                                                 ignored.
                                                                 15 = Relative to start of WQE[VLPTR]. VLPTR must be valid (see WQE[VLPTR]) or mask is
                                                                 ignored.
                                                                 INTERNAL: Note excluding 0, the encoding matches the byte number to read from WQE WORD4. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_tag_incx_ctl_s cn; */
} bdk_pki_tag_incx_ctl_t;

static inline uint64_t BDK_PKI_TAG_INCX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_TAG_INCX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x86c000007000ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKI_TAG_INCX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_TAG_INCX_CTL(a) bdk_pki_tag_incx_ctl_t
#define bustype_BDK_PKI_TAG_INCX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_TAG_INCX_CTL(a) "PKI_TAG_INCX_CTL"
#define device_bar_BDK_PKI_TAG_INCX_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_TAG_INCX_CTL(a) (a)
#define arguments_BDK_PKI_TAG_INCX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_tag_inc#_mask
 *
 * PKI Tag Inclusion Mask Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_tag_incx_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t en                    : 64; /**< [ 63:  0](R/W) Include byte in mask-tag algorithm. Each EN bit corresponds to 64 consecutive bytes in the
                                                                 data stream, as controlled by PKI_TAG_INC()_CTL as described in WQE[TAG]. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 64; /**< [ 63:  0](R/W) Include byte in mask-tag algorithm. Each EN bit corresponds to 64 consecutive bytes in the
                                                                 data stream, as controlled by PKI_TAG_INC()_CTL as described in WQE[TAG]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_tag_incx_mask_s cn; */
} bdk_pki_tag_incx_mask_t;

static inline uint64_t BDK_PKI_TAG_INCX_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_TAG_INCX_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x86c000008000ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("PKI_TAG_INCX_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PKI_TAG_INCX_MASK(a) bdk_pki_tag_incx_mask_t
#define bustype_BDK_PKI_TAG_INCX_MASK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_TAG_INCX_MASK(a) "PKI_TAG_INCX_MASK"
#define device_bar_BDK_PKI_TAG_INCX_MASK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_TAG_INCX_MASK(a) (a)
#define arguments_BDK_PKI_TAG_INCX_MASK(a) (a),-1,-1,-1

/**
 * Register (NCB) pki_tag_secret
 *
 * PKI Initial-Value Register
 * The source and destination initial values (IVs) in tag generation provide a mechanism for
 * seeding with a random initialization value to reduce cache collision attacks.
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_tag_secret_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dst6                  : 16; /**< [ 63: 48](R/W) Secret for the destination tuple IPv6 tag CRC calculation. Typically identical to SRC6 to
                                                                 insure tagging is symmetric between source/destination flows. Typically different from DST
                                                                 for maximum security. */
        uint64_t src6                  : 16; /**< [ 47: 32](R/W) Secret for the source tuple IPv6 tag CRC calculation. Typically different from SRC for
                                                                 maximum security. */
        uint64_t dst                   : 16; /**< [ 31: 16](R/W) Secret for the destination tuple tag CRC calculation. Typically identical to DST6 to
                                                                 insure tagging is symmetric between source/destination flows. */
        uint64_t src                   : 16; /**< [ 15:  0](R/W) Secret for the source tuple tag CRC calculation. */
#else /* Word 0 - Little Endian */
        uint64_t src                   : 16; /**< [ 15:  0](R/W) Secret for the source tuple tag CRC calculation. */
        uint64_t dst                   : 16; /**< [ 31: 16](R/W) Secret for the destination tuple tag CRC calculation. Typically identical to DST6 to
                                                                 insure tagging is symmetric between source/destination flows. */
        uint64_t src6                  : 16; /**< [ 47: 32](R/W) Secret for the source tuple IPv6 tag CRC calculation. Typically different from SRC for
                                                                 maximum security. */
        uint64_t dst6                  : 16; /**< [ 63: 48](R/W) Secret for the destination tuple IPv6 tag CRC calculation. Typically identical to SRC6 to
                                                                 insure tagging is symmetric between source/destination flows. Typically different from DST
                                                                 for maximum security. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_tag_secret_s cn; */
} bdk_pki_tag_secret_t;

#define BDK_PKI_TAG_SECRET BDK_PKI_TAG_SECRET_FUNC()
static inline uint64_t BDK_PKI_TAG_SECRET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_TAG_SECRET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000430ll;
    __bdk_csr_fatal("PKI_TAG_SECRET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_TAG_SECRET bdk_pki_tag_secret_t
#define bustype_BDK_PKI_TAG_SECRET BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_TAG_SECRET "PKI_TAG_SECRET"
#define device_bar_BDK_PKI_TAG_SECRET 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_TAG_SECRET 0
#define arguments_BDK_PKI_TAG_SECRET -1,-1,-1,-1

/**
 * Register (NCB) pki_x2p_req_ofl
 *
 * PKI X2P Request Overflow Error Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pki_x2p_req_ofl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t x2p_did               : 4;  /**< [  3:  0](RO/H) When PKI_GEN_INT[X2P_REQ_OFL] is set, this field latches the X2P device id number which
                                                                 attempted to overflow the allowed outstanding requests to PKI. */
#else /* Word 0 - Little Endian */
        uint64_t x2p_did               : 4;  /**< [  3:  0](RO/H) When PKI_GEN_INT[X2P_REQ_OFL] is set, this field latches the X2P device id number which
                                                                 attempted to overflow the allowed outstanding requests to PKI. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pki_x2p_req_ofl_s cn; */
} bdk_pki_x2p_req_ofl_t;

#define BDK_PKI_X2P_REQ_OFL BDK_PKI_X2P_REQ_OFL_FUNC()
static inline uint64_t BDK_PKI_X2P_REQ_OFL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PKI_X2P_REQ_OFL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x86c000000038ll;
    __bdk_csr_fatal("PKI_X2P_REQ_OFL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PKI_X2P_REQ_OFL bdk_pki_x2p_req_ofl_t
#define bustype_BDK_PKI_X2P_REQ_OFL BDK_CSR_TYPE_NCB
#define basename_BDK_PKI_X2P_REQ_OFL "PKI_X2P_REQ_OFL"
#define device_bar_BDK_PKI_X2P_REQ_OFL 0x0 /* PF_BAR0 */
#define busnum_BDK_PKI_X2P_REQ_OFL 0
#define arguments_BDK_PKI_X2P_REQ_OFL -1,-1,-1,-1

#endif /* __BDK_CSRS_PKI_H__ */
