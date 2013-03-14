/**
 * @file
 *
 * This header file defines the work queue entry (wqe) data structure.
 * Since this is a commonly used structure that depends on structures
 * from several hardware blocks, those definitions have been placed
 * in this file to create a single point of definition of the wqe
 * format.
 * Data structures are still named according to the block that they
 * relate to.
 *
 * This file must not depend on any other header files, except for cvmx.h!!!
 *
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum
{
    BDK_WQE_TAG_TYPE_ORDERED   = 0,
    BDK_WQE_TAG_TYPE_ATOMIC    = 1,
    BDK_WQE_TAG_TYPE_NULL      = 2,
    BDK_WQE_TAG_TYPE_NULL_NULL = 3
} bdk_wqe_tag_type_t;

typedef union
{
    uint64_t u64;
    /* BDK doesn't use this word on CN6XXX chips */
    struct
    {
        uint64_t    reserved_60_63  :  4;
        uint64_t    aura            : 12;   /**< Backpressure aura */
        uint64_t    reserved_47     :  1;
        uint64_t    apad            :  3;   /**< Alignment padding bytes */
        uint64_t    chan            : 12;   /**< MAC channel number */
        uint64_t    bufs            :  8;   /**< Number of buffers used to store the packet */
        uint64_t    style           :  8;   /**< Final style */
        uint64_t    reserved_6_15   : 10;
        uint64_t    pknd            :  6;   /**< Port kind */
    } v3; /* CN78XX */
} __bdk_wqe_word0_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    len             :16;    /**< HW sets to the total number of bytes in the packet */
        uint64_t    ipprt           : 6;    /**< HW sets this to input physical port */
        uint64_t    qos             : 3;    /**< HW sets this to what it thought the priority of the input packet was */
        uint64_t    grp             : 4;    /**< the group that the work queue entry will be scheduled to */
        uint64_t    reserved_34     : 1;
        bdk_wqe_tag_type_t tt       : 2;    /**< the type of the tag (ORDERED, ATOMIC, NULL) */
        uint64_t    tag             :32;    /**< the synchronization/ordering tag */
    } v1;                                   /**< All chips excluding CN68XX and CN78XX */
    struct
    {
        uint64_t    len             :16;    /**< HW sets to the total number of bytes in the packet */
        uint64_t    reserved_47     : 1;
        uint64_t    qos             : 3;    /**< HW sets this to what it thought the priority of the input packet was */
        uint64_t    reserved_43     : 1;
        uint64_t    grp             : 6;    /**< the group that the work queue entry will be scheduled to */
        uint64_t    reserved_34_36  : 2;
        bdk_wqe_tag_type_t tt       : 2;    /**< the type of the tag (ORDERED, ATOMIC, NULL) */
        uint64_t    tag             :32;    /**< the synchronization/ordering tag */
    } v2;                                   /**< CN68XX */
    struct
    {
        uint64_t    len             : 16;   /**< HW sets to the total number of bytes in the packet */
        uint64_t    reserved_44_47  :  4;
        uint64_t    grp             : 10;   /**< the group that the work queue entry will be scheduled to */
        bdk_wqe_tag_type_t tt       :  2;   /**< the type of the tag (ORDERED, ATOMIC, NULL) */
        uint64_t    tag             : 32;   /**< the synchronization/ordering tag */
    } v3;                                   /**< CN78XX */
} __bdk_wqe_word1_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    bufs            :  8;   /**< Number of buffers used to store the packet */
        uint64_t    ip_offset       :  8;   /**< Number of bytes from start-of-packet to the start of IP */
        uint64_t    reserved_32_55  : 16;
        uint64_t    port            : 12;   /**< HW sets this to input physical port */
        uint64_t    reserved_17_19  :  3;
        uint64_t    v6              :  1;   /**< IPv6 packet */
        uint64_t    reserved_10_15  :  6;
        uint64_t    ni              :  1;   /**< Not IP */
        uint64_t    re              :  1;   /**< Receive error */
        uint64_t    opcode          :  8;   /**< Error code */
    } v1;
    struct
    {
        uint64_t    sw              :  1;   /**< Reserved for SW use */
        uint64_t    lgty            :  5;   /**< Layer G header type. Enumerated in PKI_LTYPE_E */
        uint64_t    lfty            :  5;   /**< Layer F header type. Enumerated in PKI_LTYPE_E */
        uint64_t    lety            :  5;   /**< Layer E header type. Enumerated in PKI_LTYPE_E */
        uint64_t    ldty            :  5;   /**< Layer D header type. Enumerated in PKI_LTYPE_E */
        uint64_t    lcty            :  5;   /**< Layer C header type. Enumerated in PKI_LTYPE_E */
        uint64_t    lbty            :  5;   /**< Layer B header type. Enumerated in PKI_LTYPE_E */
        uint64_t    lae             :  1;   /**< Layer A Ethernet present */
        uint64_t    reserved_24_31  :  8;
        uint64_t    vv              :  1;   /**< VLAN is found in L2 HDR */
        uint64_t    vs              :  1;   /**< Stacked VLAN is present */
        uint64_t    sh              :  1;   /**< Stat Increment */
        uint64_t    pf4             :  1;   /**< User PCAM flag 4 */
        uint64_t    pf3             :  1;   /**< User PCAM flag 3. (Optionally IPCOMP) */
        uint64_t    pf2             :  1;   /**< User PCAM flag 2. (Optionally RARP) */
        uint64_t    pf1             :  1;   /**< User PCAM flag 1. (Optionally ARP) */
        uint64_t    l3fr            :  1;   /**< Outer IP fragment */
        uint64_t    l3b             :  1;   /**< Outer IP broadcast */
        uint64_t    l3m             :  1;   /**< Outer IP multicast */
        uint64_t    l2b             :  1;   /**< L2 DMAC is broadcast */
        uint64_t    l2m             :  1;   /**< L2 DMAC is multicast */
        uint64_t    raw             :  1;   /**< Packet had PKI_INST_HDR[RAW] set */
        uint64_t    errlev          :  3;   /**< Error level. Enumerated in PKI_OPCODE_E */
        uint64_t    opcode          :  8;   /**< Error opcode. Enumerated in PKI_OPCODE_E */
    } v3;
} __bdk_wqe_word2_t;

/**
 * This structure defines a buffer pointer on Octeon
 */
typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    i               : 1;    /**< if set, invert the "free" pick of the overall packet. HW always sets this bit to 0 on inbound packet */
        uint64_t    back            : 4;    /**< Indicates the amount to back up to get to the buffer start in cache lines. In most cases
                                                this is less than one complete cache line, so the value is zero */
        uint64_t    pool            : 3;    /**< The pool that the buffer came from / goes to */
        uint64_t    size            :16;    /**< The size of the segment pointed to by addr (in bytes) */
        uint64_t    addr            :40;    /**< Pointer to the first byte of the data, NOT buffer */
    } v1;
    struct
    {
        uint64_t    size            : 16;   /**< The size of the segment pointed to by addr (in bytes) */
        uint64_t    dwd             :  1;   /**< Start-of-packet data is outside WQE */
        uint64_t    reserved_45_46  :  2;
        uint64_t    i               :  1;   /**< if set, invert the "free" pick of the overall packet. HW always sets this bit to 0 on inbound packet */
        uint64_t    reserved_42_43  :  2;
        uint64_t    addr            : 42;   /**< Pointer to the first byte of the data, NOT buffer */
    } v3;
} bdk_buf_ptr_t; /* __bdk_wqe_word3_t */

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    vlptr           :  8;   /**< Pointer to VLAN */
        uint64_t    lgptr           :  8;   /**< Pointer to Layer G starting byte */
        uint64_t    lfptr           :  8;   /**< Pointer to Layer F starting byte */
        uint64_t    leptr           :  8;   /**< Pointer to Layer E starting byte */
        uint64_t    ldptr           :  8;   /**< Pointer to Layer D starting byte */
        uint64_t    lcptr           :  8;   /**< Pointer to Layer C starting byte */
        uint64_t    lbptr           :  8;   /**< Pointer to Layer B starting byte */
        uint64_t    laptr           :  8;   /**< Pointer to Layer A starting byte */
    } v3;
} __bdk_wqe_word4_t;

/**
 * Work queue entry format
 */
typedef struct
{
    __bdk_wqe_word0_t   word0;
    __bdk_wqe_word1_t   word1;
    __bdk_wqe_word2_t   word2;
    bdk_buf_ptr_t       packet_ptr;
    __bdk_wqe_word4_t   word4;      /* This is packet_data on cn6xxx */
    uint64_t            unused[11]; /* This doesn't exist in 78, is pakcet data on 68 */
} bdk_wqe_t;

/** @} */
