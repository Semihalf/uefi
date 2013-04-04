/**
 * @file
 *
 * Interface to the PCI / PCIe DMA engines. These are only avialable
 * on chips with PCI / PCIe.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum
{
    BDK_DMA_ENGINE_TRANSFER_OUTBOUND = 0,  /**< OUTBOUND (read from L2/DRAM, write into PCI / PCIe memory space) */
    BDK_DMA_ENGINE_TRANSFER_INBOUND = 1,   /**< INBOUND (read from PCI / PCIe memory space, write into L2/DRAM) */
    BDK_DMA_ENGINE_TRANSFER_INTERNAL = 2,  /**< INTERNAL-ONLY (read from L2/DRAM, write into L2/DRAM). Only available on chips with PCIe */
    BDK_DMA_ENGINE_TRANSFER_EXTERNAL = 3,  /**< EXTERNAL-ONLY (read from PCIe memory space, write into PCIe memory space). Only available on chips with PCIe */
} bdk_dma_engine_transfer_t;

typedef struct
{
    union
    {
        uint64_t u64;
        struct
        {
            uint64_t    reserved_60_63 :   4;   /**< Must be zero */
            uint64_t    fport           :  2;   /**< First port. FPort indicates the physical PCIe port used for the
                                                    PCIe memory space pointers in the FIRST POINTERS block in the
                                                    EXTERNAL-ONLY case. Must be zero in the OUTBOUND, INBOUND and
                                                    INTERNAL-ONLY cases. Must be zero on chips with PCI */
            uint64_t    lport           :  2;   /**< Last port. LPort indicates the physical PCIe port used for the
                                                    PCIe memory space pointers in the LAST POINTERS block in the
                                                    OUTBOUND, INBOUND, and EXTERNAL-ONLY cases. Must be zero in the
                                                    INTERNAL-ONLY case. Must be zero on chips with PCI */
            bdk_dma_engine_transfer_t type :  2; /**< Type - A given PCI DMA transfer is either OUTBOUND (read from L2/DRAM,
                                                    write into PCI / PCIe memory space), INBOUND (read from PCI / PCIe memory space, write
                                                    into L2/DRAM), INTERNAL-ONLY (read from L2/DRAM, write into L2/DRAM), or
                                                    EXTERNAL-ONLY (read from PCIe memory space, write into PCIe memory space). */
            uint64_t    wqp             :  1;   /**< Work-queue pointer. When WQP = 1, PTR (if non-zero) is a pointer to a
                                                    work-queue entry that is submitted by the hardware after completing the DMA;
                                                    when WQP = 0, PTR (if non-zero) is a pointer to a byte in local memory that
                                                    is written to 0 by the hardware after completing the DMA. */
            uint64_t    c               :  1;   /**< C - Counter. 1 = use counter 1, 0 = use counter 0.
                                                    The C bit selects between the two counters (NPEI_DMA_CNTS[DMA0,DMA1])
                                                    that can optionally be updated after an OUTBOUND or EXTERNAL-ONLY
                                                    transfer, and also selects between the two forced-interrupt bits
                                                    (NPEI_INT_SUMn[DMA0_FI, DMA1_FI]) that can optionally be set after an
                                                    OUTBOUND or EXTERNAL-ONLY transfer. C must be zero for INBOUND or
                                                    INTERNAL-ONLY transfers. */
            uint64_t    ca              :  1;   /**< CA - Counter add.
                                                    When CA = 1, the hardware updates the selected counter after it completes the
                                                    PCI DMA OUTBOUND or EXTERNAL-ONLY Instruction.
                                                        - If C = 0, PCIE_DMA_CNT0 is updated
                                                        - If C = 1, PCIE_DMA_CNT1 is updated.
                                                    Note that this update may indirectly cause
                                                    NPEI_INT_SUM[DCNT0,DCNT1,DTIME0,DTIME1] to become set (depending
                                                    on the NPEI_DMA*_INT_LEVEL settings), so may cause interrupts to occur on a
                                                    remote PCI host.
                                                        - If NPEI_DMA_CONTROL[O_ADD1] = 1, the counter is updated by 1.
                                                        - If NPEI_DMA_CONTROL[O_ADD1] = 0, the counter is updated by the total
                                                        bytes in the transfer.
                                                    When CA = 0, the hardware does not update any counters.
                                                    For an INBOUND or INTERNAL-ONLY PCI DMA transfer, CA must never be
                                                    set, and the hardware never adds to the counters. */
            uint64_t    fi              :  1;   /**< FI - Force interrupt.
                                                    When FI is set for an OUTBOUND or EXTERNAL-ONLY transfer, the hardware
                                                    sets a forced interrupt bit after it completes the PCI DMA Instruction. If C = 0,
                                                    NPEI_INT_SUMn[DMA0_FI] is set, else NPEI_INT_SUMn[DMA1_FI] is set. For
                                                    an INBOUND or INTERNAL-ONLY PCI DMA operation, FI must never be set,
                                                    and the hardware never generates interrupts. */
            uint64_t    ii              :  1;   /**< II- Ignore the I bit (i.e. the I bit of the PCI DMA instruction local pointer).
                                                    For OUTBOUND transfers when II = 1, ignore the I bit and the FL bit in the
                                                    DMA HDR alone determines whether the hardware frees any/all of the local
                                                    buffers in the FIRST POINTERS area:
                                                        - when FL = 1, the hardware frees the local buffer when II=1.
                                                        - when FL = 0, the hardware does not free the local buffer when II=1.
                                                    For OUTBOUND transfers when II = 0, the I bit in the local pointer selects
                                                    whether local buffers are freed on a pointer-by-pointer basis:
                                                        - when (FL  I) is true, the hardware frees the local buffer when II=0.
                                                    For INBOUND, INTERNAL-ONLY, and EXTERNAL-ONLY PCI DMA transfers,
                                                    II must never be set, and local buffers are never freed. */
            uint64_t    fl              :  1;   /**< FL - Free local buffer.
                                                    When FL = 1, for an OUTBOUND operation, it indicates that the local buffers in
                                                    the FIRST BUFFERS area should be freed.
                                                    If II = 1, the FL bit alone indicates whether the local buffer should be freed:
                                                        - when FL = 1, the hardware frees the local buffer when II=1.
                                                        - when FL = 0, the hardware does not free the local buffer when II=1.
                                                    If II = 0, the I bit in the local pointer (refer to Section 9.5.2) determines whether
                                                    the local buffer is freed:
                                                        - when (FL  I) is true, the hardware frees the local buffer when II=0.
                                                    For an INBOUND, INTERNAL-ONLY, or EXTERNAL-ONLY PCI DMA transfer,
                                                    FL must never be set, and local buffers are never freed. */
            uint64_t    nlst            :  4;   /**< NLST - Number Last pointers.
                                                    The number of pointers in the LAST POINTERS area.
                                                    In the INBOUND, OUTBOUND, and EXTERNAL-ONLY cases, the LAST
                                                    POINTERS area contains PCI components, and the number of 64-bit words
                                                    required in the LAST POINTERS area is:
                                                        - HDR.NLST + ((HDR.NLST + 3)/4) where the division removes the fraction.
                                                    In the INTERNAL-ONLY case, the LAST POINTERS area contains local
                                                    pointers, and the number of 64-bit words required in the LAST POINTERS area is:
                                                        - HDR.NLST
                                                    Note that the sum of the number of 64-bit words in the LAST POINTERS and
                                                    FIRST POINTERS area must never exceed 31. */
            uint64_t    nfst            :  4;   /**< NFST - Number First pointers.
                                                    The number of pointers in the FIRST POINTERS area.
                                                    In the INBOUND, OUTBOUND, and INTERNAL-ONLY cases, the FIRST
                                                    POINTERS area contains local pointers, and the number of 64-bit words required
                                                    in the FIRST POINTERS area is:
                                                        - HDR.NFST
                                                    In the EXTERNAL-ONLY case, the FIRST POINTERS area contains PCI
                                                    components, and the number of 64-bit words required in the FIRST POINTERS
                                                    area is:
                                                        - HDR.NFST + ((HDR.NFST + 3)/4) where the division removes the fraction. */
            uint64_t    addr            : 40;   /**< PTR - Pointer, either a work-queue-entry pointer (when WQP = 1) or a local
                                                    memory pointer (WQP = 0).
                                                    When WQP = 1 and PTR  0x0, the hardware inserts the work-queue entry
                                                    indicated by PTR into a SSO input queue after the PCI DMA operation is
                                                    complete. (Section 5.4 describes the work queue entry requirements in this
                                                    case.) When WQP = 1, PTR<2:0> must be 0x0.
                                                    When WQP = 0 and PTR  0x0, the hardware writes the single byte in local
                                                    memory indicated by PTR to 0x0 after the PCI DMA operation is complete.
                                                    NPEI_DMA_CONTROL[B0_LEND] selects the endian-ness of PTR in this
                                                    case.
                                                    When PTR = 0x0, the hardware performs no operation after the PCI DMA
                                                    operation is complete. */
        } v1;
        struct
        {
            uint64_t    reserved_62_63 :   2;   /**< Must be zero */
            uint64_t    lport           :  2;   /**< Last port. LPort indicates the physical PCIe port used for the
                                                    PCIe memory space pointers in the LAST POINTERS block in the
                                                    OUTBOUND, INBOUND, and EXTERNAL-ONLY cases. Must be zero in the
                                                    INTERNAL-ONLY case. Must be zero on chips with PCI */
            uint64_t    reserved_58_59 :   2;   /**< Must be zero */
            uint64_t    fport           :  2;   /**< First port. FPort indicates the physical PCIe port used for the
                                                    PCIe memory space pointers in the FIRST POINTERS block in the
                                                    EXTERNAL-ONLY case. Must be zero in the OUTBOUND, INBOUND and
                                                    INTERNAL-ONLY cases. Must be zero on chips with PCI */
            uint64_t    reserved_54_55 :   2;   /**< Must be zero */
            bdk_dma_engine_transfer_t type :  2; /**< Type - A given PCI DMA transfer is either OUTBOUND (read from L2/DRAM,
                                                    write into PCI / PCIe memory space), INBOUND (read from PCI / PCIe memory space, write
                                                    into L2/DRAM), INTERNAL-ONLY (read from L2/DRAM, write into L2/DRAM), or
                                                    EXTERNAL-ONLY (read from PCIe memory space, write into PCIe memory space). */
            uint64_t    c               :  1;   /**< C - Counter. 1 = use counter 1, 0 = use counter 0.
                                                    The C bit selects between the two counters (NPEI_DMA_CNTS[DMA0,DMA1])
                                                    that can optionally be updated after an OUTBOUND or EXTERNAL-ONLY
                                                    transfer, and also selects between the two forced-interrupt bits
                                                    (NPEI_INT_SUMn[DMA0_FI, DMA1_FI]) that can optionally be set after an
                                                    OUTBOUND or EXTERNAL-ONLY transfer. C must be zero for INBOUND or
                                                    INTERNAL-ONLY transfers. */
            uint64_t    ca              :  1;   /**< CA - Counter add.
                                                    When CA = 1, the hardware updates the selected counter after it completes the
                                                    PCI DMA OUTBOUND or EXTERNAL-ONLY Instruction.
                                                        - If C = 0, PCIE_DMA_CNT0 is updated
                                                        - If C = 1, PCIE_DMA_CNT1 is updated.
                                                    Note that this update may indirectly cause
                                                    NPEI_INT_SUM[DCNT0,DCNT1,DTIME0,DTIME1] to become set (depending
                                                    on the NPEI_DMA*_INT_LEVEL settings), so may cause interrupts to occur on a
                                                    remote PCI host.
                                                        - If NPEI_DMA_CONTROL[O_ADD1] = 1, the counter is updated by 1.
                                                        - If NPEI_DMA_CONTROL[O_ADD1] = 0, the counter is updated by the total
                                                        bytes in the transfer.
                                                    When CA = 0, the hardware does not update any counters.
                                                    For an INBOUND or INTERNAL-ONLY PCI DMA transfer, CA must never be
                                                    set, and the hardware never adds to the counters. */
            uint64_t    fi              :  1;   /**< FI - Force interrupt.
                                                    When FI is set for an OUTBOUND or EXTERNAL-ONLY transfer, the hardware
                                                    sets a forced interrupt bit after it completes the PCI DMA Instruction. If C = 0,
                                                    NPEI_INT_SUMn[DMA0_FI] is set, else NPEI_INT_SUMn[DMA1_FI] is set. For
                                                    an INBOUND or INTERNAL-ONLY PCI DMA operation, FI must never be set,
                                                    and the hardware never generates interrupts. */
            uint64_t    ii              :  1;   /**< II- Ignore the I bit (i.e. the I bit of the PCI DMA instruction local pointer).
                                                    For OUTBOUND transfers when II = 1, ignore the I bit and the FL bit in the
                                                    DMA HDR alone determines whether the hardware frees any/all of the local
                                                    buffers in the FIRST POINTERS area:
                                                        - when FL = 1, the hardware frees the local buffer when II=1.
                                                        - when FL = 0, the hardware does not free the local buffer when II=1.
                                                    For OUTBOUND transfers when II = 0, the I bit in the local pointer selects
                                                    whether local buffers are freed on a pointer-by-pointer basis:
                                                        - when (FL  I) is true, the hardware frees the local buffer when II=0.
                                                    For INBOUND, INTERNAL-ONLY, and EXTERNAL-ONLY PCI DMA transfers,
                                                    II must never be set, and local buffers are never freed. */
            uint64_t    fl              :  1;   /**< FL - Free local buffer.
                                                    When FL = 1, for an OUTBOUND operation, it indicates that the local buffers in
                                                    the FIRST BUFFERS area should be freed.
                                                    If II = 1, the FL bit alone indicates whether the local buffer should be freed:
                                                        - when FL = 1, the hardware frees the local buffer when II=1.
                                                        - when FL = 0, the hardware does not free the local buffer when II=1.
                                                    If II = 0, the I bit in the local pointer (refer to Section 9.5.2) determines whether
                                                    the local buffer is freed:
                                                        - when (FL  I) is true, the hardware frees the local buffer when II=0.
                                                    For an INBOUND, INTERNAL-ONLY, or EXTERNAL-ONLY PCI DMA transfer,
                                                    FL must never be set, and local buffers are never freed. */
            uint64_t    reserved_46     :  1;   /**< Must be zero */
            uint64_t    pt              :  2;   /**< Pointer type. 0=zero byte write, 1=zero byte write, 2=WQE, 3=CNT(0-63) increment */
            uint64_t    reserved_42_43  :  2;   /**< Must be zero */
            uint64_t    nlst            :  4;   /**< NLST - Number Last pointers.
                                                    The number of pointers in the LAST POINTERS area.
                                                    In the INBOUND, OUTBOUND, and EXTERNAL-ONLY cases, the LAST
                                                    POINTERS area contains PCI components, and the number of 64-bit words
                                                    required in the LAST POINTERS area is:
                                                        - HDR.NLST + ((HDR.NLST + 3)/4) where the division removes the fraction.
                                                    In the INTERNAL-ONLY case, the LAST POINTERS area contains local
                                                    pointers, and the number of 64-bit words required in the LAST POINTERS area is:
                                                        - HDR.NLST
                                                    Note that the sum of the number of 64-bit words in the LAST POINTERS and
                                                    FIRST POINTERS area must never exceed 31. */
            uint64_t    reserved_36_37  :  2;   /**< Must be zero */
            uint64_t    nfst            :  4;   /**< NFST - Number First pointers.
                                                    The number of pointers in the FIRST POINTERS area.
                                                    In the INBOUND, OUTBOUND, and INTERNAL-ONLY cases, the FIRST
                                                    POINTERS area contains local pointers, and the number of 64-bit words required
                                                    in the FIRST POINTERS area is:
                                                        - HDR.NFST
                                                    In the EXTERNAL-ONLY case, the FIRST POINTERS area contains PCI
                                                    components, and the number of 64-bit words required in the FIRST POINTERS
                                                    area is:
                                                        - HDR.NFST + ((HDR.NFST + 3)/4) where the division removes the fraction. */
            uint64_t    reserved_28_31  :  4;   /**< Must be zero */
            uint64_t    node            :  2;   /**< Submit node */
            uint64_t    grp             :  8;   /**< Submit group */
            uint64_t    tt              :  2;   /**< Tag type */
            uint64_t    reserved_10_15  :  6;   /**< Must be zero */
            uint64_t    aura            : 10;   /**< Aura to free buffers to */
        } v3;
    } word0;
    union /* The second word is only used on CN78XX */
    {
        uint64_t u64;
        struct
        {
            uint64_t    reserved_42_63 :  22;   /**< Must be zero */
            uint64_t    addr           :  42;   /**< See addr description above */
        } v3;
    } word1;
} bdk_dma_engine_header_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    i               :  1;   /**< I - Invert free.
                                                This bit gives the software the ability to free buffers independently for an
                                                OUTBOUND PCI DMA transfer. I is not used by the hardware when II is set. I
                                                must not be set, and buffers are never freed, for INBOUND, INTERNAL-ONLY,
                                                and EXTERNAL-ONLY PCI DMA transfers. */
        uint64_t    back            :  4;   /**< Back - Backup amount.
                                                Allows the start of a buffer that is to be freed during an OUTBOUND transfer to
                                                be different from the ptr value. Back specifies the amount to subtract from the
                                                pointer to reach the start when freeing a buffer.
                                                The address that is the start of the buffer being freed is:
                                                    - Buffer start address = ((ptr >> 7) - Back) << 7.
                                                Back is only used by the hardware when the buffer corresponding to ptr is freed.
                                                Back must be 0x0, and buffers are never freed, for INBOUND, INTERNAL-ONLY,
                                                and EXTERNAL-ONLY PCI DMA transfers. */
        uint64_t    pool            :  3;   /**< Pool - Free pool.
                                                Specifies which pool (of the eight hardware-managed FPA free pools) receives the
                                                buffer associated with ptr when freed during an OUTBOUND transfer.
                                                Pool is only used when the buffer corresponding to ptr is freed. Pool must be 0x0,
                                                and buffers are never freed, for INBOUND, INTERNAL-ONLY, and EXTERNAL-ONLY
                                                PCI DMA transfers. */
        uint64_t    f               :  1;   /**< F - Full-block writes are allowed.
                                                When set, the hardware is permitted to write all the bytes in the cache blocks
                                                covered by ptr, ptr + Size - 1. This can improve memory system performance
                                                when the write misses in the L2 cache.
                                                F can only be set for local pointers that can be written to:
                                                    - The local pointers in the FIRST POINTERS area that are write pointers for
                                                    INBOUND transfers.
                                                    - The local pointers in the LAST POINTERS area that are always write
                                                    pointers (when present for INTERNAL-ONLY transfers).
                                                F must not be set for local pointers that are not written to:
                                                    - The local pointers in the FIRST POINTERS area for OUTBOUND and
                                                    INTERNAL-ONLY transfers. */
        uint64_t    a               :  1;   /**< A - Allocate L2.
                                                This is a hint to the hardware that the cache blocks should be allocated in the L2
                                                cache (if they were not already). */
        uint64_t    l               :  1;   /**< L - Little-endian.
                                                When L is set, the data at ptr is in little-endian format rather than big-endian. */
        uint64_t    size            : 13;   /**< Size - Size in bytes of the contiguous space specified by ptr. A Size value of 0 is
                                                illegal. Note that the sum of the sizes in the FIRST POINTERS area must always
                                                exactly equal the sum of the sizes/lengths in the LAST POINTERS area:
                                                    - In the OUTBOUND and INBOUND cases, the HDR.NFST size fields in the
                                                    local pointers in the FIRST POINTERS area must exactly equal the lengths
                                                    of the HDR.NLST fragments in the PCI components in the LAST POINTERS
                                                    area.
                                                    - In the INTERNAL-ONLY case, the HDR.NFST size fields in the local
                                                    pointers in the FIRST POINTERS area must equal the HDR.NLST size
                                                    fields in the local pointers in the LAST POINTERS area. */
        uint64_t    reserved_36_39  :  4;   /**< Must be zero */
        uint64_t    addr            : 36;   /**< L2/DRAM byte pointer. Points to where the packet data starts.
                                                Ptr can be any byte alignment. Note that ptr is interpreted as a big-endian byte
                                                pointer when L is clear, a little-endian byte pointer when L is set. */
    } internal_v1;
    struct
    {
        uint64_t    i               :  1;   /**< I - Invert free.
                                                This bit gives the software the ability to free buffers independently for an
                                                OUTBOUND PCI DMA transfer. I is not used by the hardware when II is set. I
                                                must not be set, and buffers are never freed, for INBOUND, INTERNAL-ONLY,
                                                and EXTERNAL-ONLY PCI DMA transfers. */
        uint64_t    f               :  1;   /**< F - Full-block writes are allowed.
                                                When set, the hardware is permitted to write all the bytes in the cache blocks
                                                covered by ptr, ptr + Size - 1. This can improve memory system performance
                                                when the write misses in the L2 cache.
                                                F can only be set for local pointers that can be written to:
                                                    - The local pointers in the FIRST POINTERS area that are write pointers for
                                                    INBOUND transfers.
                                                    - The local pointers in the LAST POINTERS area that are always write
                                                    pointers (when present for INTERNAL-ONLY transfers).
                                                F must not be set for local pointers that are not written to:
                                                    - The local pointers in the FIRST POINTERS area for OUTBOUND and
                                                    INTERNAL-ONLY transfers. */
        uint64_t    a               :  1;   /**< A - Allocate L2.
                                                This is a hint to the hardware that the cache blocks should be allocated in the L2
                                                cache (if they were not already). */
        uint64_t    size            : 13;   /**< Size - Size in bytes of the contiguous space specified by ptr. A Size value of 0 is
                                                illegal. Note that the sum of the sizes in the FIRST POINTERS area must always
                                                exactly equal the sum of the sizes/lengths in the LAST POINTERS area:
                                                    - In the OUTBOUND and INBOUND cases, the HDR.NFST size fields in the
                                                    local pointers in the FIRST POINTERS area must exactly equal the lengths
                                                    of the HDR.NLST fragments in the PCI components in the LAST POINTERS
                                                    area.
                                                    - In the INTERNAL-ONLY case, the HDR.NFST size fields in the local
                                                    pointers in the FIRST POINTERS area must equal the HDR.NLST size
                                                    fields in the local pointers in the LAST POINTERS area. */
        uint64_t    l               :  1;   /**< L - Little-endian.
                                                When L is set, the data at ptr is in little-endian format rather than big-endian. */
        uint64_t    reserved_42_46  :  5;   /**< Must be zero */
        uint64_t    addr            : 42;   /**< L2/DRAM byte pointer. Points to where the packet data starts.
                                                Ptr can be any byte alignment. Note that ptr is interpreted as a big-endian byte
                                                pointer when L is clear, a little-endian byte pointer when L is set. */
    } internal_v3;
    struct
    {
        uint64_t    len0            : 16;   /**< Length of PCI / PCIe memory for address 0 */
        uint64_t    len1            : 16;   /**< Length of PCI / PCIe memory for address 1 */
        uint64_t    len2            : 16;   /**< Length of PCI / PCIe memory for address 2 */
        uint64_t    len3            : 16;   /**< Length of PCI / PCIe memory for address 3 */
    } pcie_length;
} bdk_dma_engine_buffer_t;

/**
 * Initialize the DMA engines for use
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_dma_engine_initialize(bdk_node_t node);

/**
 * Shutdown all DMA engines. The engeines must be idle when this
 * function is called.
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_dma_engine_shutdown(bdk_node_t node);

/**
 * Return the number of DMA engimes supported by this chip
 *
 * @return Number of DMA engines
 */
extern int bdk_dma_engine_get_num(bdk_node_t node);

/**
 * Submit a series of DMA comamnd to the DMA engines.
 *
 * @param node    Node to use in a Numa setup. Can be an exact ID or a special value.
 * @param engine  Engine to submit to (0 to bdk_dma_engine_get_num()-1)
 * @param header  Command header
 * @param num_buffers
 *                The number of data pointers
 * @param buffers Comamnd data pointers
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_dma_engine_submit(bdk_node_t node, int engine, bdk_dma_engine_header_t header, int num_buffers, bdk_dma_engine_buffer_t buffers[]);

/**
 * Build the first and last pointers based on a DMA engine header
 * and submit them to the engine. The purpose of this function is
 * to simplify the building of DMA engine commands by automatically
 * converting a simple address and size into the appropriate internal
 * or PCI / PCIe address list. This function does not support gather lists,
 * so you will need to build your own lists in that case.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param engine Engine to submit to (0 to bdk_dma_engine_get_num()-1)
 * @param header DMA Command header. Note that the nfst and nlst fields do not
 *               need to be filled in. All other fields must be set properly.
 * @param first_address
 *               Address to use for the first pointers. In the case of INTERNAL,
 *               INBOUND, and OUTBOUND this is an Octeon memory address. In the
 *               case of EXTERNAL, this is the source PCI / PCIe address.
 * @param last_address
 *               Address to use for the last pointers. In the case of EXTERNAL,
 *               INBOUND, and OUTBOUND this is a PCI / PCIe address. In the
 *               case of INTERNAL, this is the Octeon memory destination address.
 * @param size   Size of the transfer to perform.
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_dma_engine_transfer(bdk_node_t node, int engine, bdk_dma_engine_header_t header,
                             uint64_t first_address, uint64_t last_address,
                             int size);

/** @} */
