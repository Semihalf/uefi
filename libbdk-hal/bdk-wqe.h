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
    struct
    {
        uint64_t    len         :16;    /**< HW sets to the total number of bytes in the packet */
        uint64_t    reserved_34_47 :14;
        bdk_wqe_tag_type_t tt   : 2;    /**< the type of the tag (ORDERED, ATOMIC, NULL) */
        uint64_t    tag         :32;    /**< the synchronization/ordering tag */
    } s;                                /**< All chips up and including CN63XX */
    struct
    {
        uint64_t    len         :16;    /**< HW sets to the total number of bytes in the packet */
        uint64_t    ipprt       : 6;    /**< HW sets this to input physical port */
        uint64_t    qos         : 3;    /**< HW sets this to what it thought the priority of the input packet was */
        uint64_t    grp         : 4;    /**< the group that the work queue entry will be scheduled to */
        uint64_t    reserved_34 : 1;
        bdk_wqe_tag_type_t tt   : 2;    /**< the type of the tag (ORDERED, ATOMIC, NULL) */
        uint64_t    tag         :32;    /**< the synchronization/ordering tag */
    } v1;                               /**< All chips up and including CN63XX */
    struct
    {
        uint64_t    len         :16;    /**< HW sets to the total number of bytes in the packet */
        uint64_t    reserved_47 : 1;
        uint64_t    qos         : 3;    /**< HW sets this to what it thought the priority of the input packet was */
        uint64_t    reserved_43 : 1;
        uint64_t    grp         : 6;    /**< the group that the work queue entry will be scheduled to */
        uint64_t    reserved_34_36 : 2;
        bdk_wqe_tag_type_t tt   : 2;    /**< the type of the tag (ORDERED, ATOMIC, NULL) */
        uint64_t    tag         :32;    /**< the synchronization/ordering tag */
    } v2;                               /**< CN68XX and higher */
} __bdk_wqe_word1_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t bufs           : 8;
        uint64_t reserved_32_55 : 24;
        uint64_t port           : 12;
        uint64_t reserved_10_19 : 11;
        uint64_t ni             : 1;
        uint64_t re             : 1;
        uint64_t opcode         : 8;
    } s;
    struct
    {
        uint64_t bufs           : 8;
        uint64_t ip_offset      : 8; /**< L2 bytes prior to the IP */
        uint64_t vv             : 1; /**< Found DSA/VLAN in the L2 */
        uint64_t vs             : 1; /**< DSA/VLAN tag is stacked */
        uint64_t reserved_45    : 1;
        uint64_t vc             : 1; /**< DSA/VLAN CFI (valid when vlan_valid) */
        uint64_t vlan_id        :12; /**< DSA/VLAN_ID (valid when vlan_valid) */
        uint64_t port           :12;
        uint64_t co             : 1; /**< IPCOMP */
        uint64_t tu             : 1; /**< TCP or UDP */
        uint64_t se             : 1; /**< IPSEC */
        uint64_t v6             : 1; /**< IPv6 */
        uint64_t reserved_15    : 1;
        uint64_t le             : 1; /**< L4 error */
        uint64_t fr             : 1; /**< fragment */
        uint64_t ie             : 1; /**< IP error / exception */
        uint64_t b              : 1; /**< broadcast */
        uint64_t m              : 1; /**< multi-cast */
        uint64_t ni             : 1;
        uint64_t re             : 1;
        uint64_t opcode         : 8;
    } ip;
    struct
    {
        uint64_t bufs           : 8;
        uint64_t reserved_48_55 : 8;
        uint64_t vv             : 1; /**< Found DSA/VLAN in the L2 */
        uint64_t vs             : 1; /**< DSA/VLAN tag is stacked */
        uint64_t reserved_45    : 1;
        uint64_t vc             : 1; /**< DSA/VLAN CFI (valid when vlan_valid) */
        uint64_t vlan_id        :12; /**< DSA/VLAN_ID (valid when vlan_valid) */
        uint64_t port           :12;
        uint64_t reserved_14_19 : 6;
        uint64_t ir             : 1; /**< set if the hardware determined that the packet is rarp */
        uint64_t ia             : 1; /**< set if the hardware determined that the packet is arp */
        uint64_t b              : 1; /**< broadcast */
        uint64_t m              : 1; /**< multi-cast */
        uint64_t ni             : 1;
        uint64_t re             : 1;
        uint64_t opcode         : 8;
    } noip;
} __bdk_wqe_word2_t;

/**
 * Work queue entry format
 */
typedef struct
{
    uint64_t            word0;
    __bdk_wqe_word1_t   word1;
    __bdk_wqe_word2_t   word2;
    bdk_buf_ptr_t       packet_ptr;     /**< First segment of the packet. */
    uint8_t             packet_data[96];
} bdk_wqe_t;

/** @} */
