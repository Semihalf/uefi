/**
 * @file
 *
 * Module to support operations on core such as TLB config, etc.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * The types of performance counters supported per cpu
 */
typedef enum
{
    BDK_CORE_PERF_NONE      = 0,    /**< Turn off the performance counter */
    BDK_CORE_PERF_CLK       = 1,    /**< Conditionally clocked cycles (as opposed to count/cvm_count which count even with no clocks) */
    BDK_CORE_PERF_ISSUE     = 2,    /**< Instructions issued but not retired */
    BDK_CORE_PERF_RET       = 3,    /**< Instructions retired */
    BDK_CORE_PERF_NISSUE    = 4,    /**< Cycles no issue */
    BDK_CORE_PERF_SISSUE    = 5,    /**< Cycles single issue */
    BDK_CORE_PERF_DISSUE    = 6,    /**< Cycles dual issue */
    BDK_CORE_PERF_IFI       = 7,    /**< Cycle ifetch issued (but not necessarily commit to pp_mem) */
    BDK_CORE_PERF_BR        = 8,    /**< Branches retired */
    BDK_CORE_PERF_BRMIS     = 9,    /**< Branch mispredicts */
    BDK_CORE_PERF_J         = 10,   /**< Jumps retired */
    BDK_CORE_PERF_JMIS      = 11,   /**< Jumps mispredicted */
    BDK_CORE_PERF_REPLAY    = 12,   /**< Mem Replays */
    BDK_CORE_PERF_IUNA      = 13,   /**< Cycles idle due to unaligned_replays */
    BDK_CORE_PERF_TRAP      = 14,   /**< trap_6a signal */
    BDK_CORE_PERF_UULOAD    = 16,   /**< Unexpected unaligned loads (REPUN=1) */
    BDK_CORE_PERF_UUSTORE   = 17,   /**< Unexpected unaligned store (REPUN=1) */
    BDK_CORE_PERF_ULOAD     = 18,   /**< Unaligned loads (REPUN=1 or USEUN=1) */
    BDK_CORE_PERF_USTORE    = 19,   /**< Unaligned store (REPUN=1 or USEUN=1) */
    BDK_CORE_PERF_EC        = 20,   /**< Exec clocks(must set CvmCtl[DISCE] for accurate timing) */
    BDK_CORE_PERF_MC        = 21,   /**< Mul clocks(must set CvmCtl[DISCE] for accurate timing) */
    BDK_CORE_PERF_CC        = 22,   /**< Crypto clocks(must set CvmCtl[DISCE] for accurate timing) */
    BDK_CORE_PERF_CSRC      = 23,   /**< Issue_csr clocks(must set CvmCtl[DISCE] for accurate timing) */
    BDK_CORE_PERF_CFETCH    = 24,   /**< Icache committed fetches (demand+prefetch) */
    BDK_CORE_PERF_CPREF     = 25,   /**< Icache committed prefetches */
    BDK_CORE_PERF_ICA       = 26,   /**< Icache aliases */
    BDK_CORE_PERF_II        = 27,   /**< Icache invalidates */
    BDK_CORE_PERF_IP        = 28,   /**< Icache parity error */
    BDK_CORE_PERF_CIMISS    = 29,   /**< Cycles idle due to imiss (must set CvmCtl[DISCE] for accurate timing) */
    BDK_CORE_PERF_WBUF      = 32,   /**< Number of write buffer entries created */
    BDK_CORE_PERF_WDAT      = 33,   /**< Number of write buffer data cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
    BDK_CORE_PERF_WBUFLD    = 34,   /**< Number of write buffer entries forced out by loads */
    BDK_CORE_PERF_WBUFFL    = 35,   /**< Number of cycles that there was no available write buffer entry (may need to set CvmCtl[DISCE] and CvmMemCtl[MCLK] for accurate counts) */
    BDK_CORE_PERF_WBUFTR    = 36,   /**< Number of stores that found no available write buffer entries */
    BDK_CORE_PERF_BADD      = 37,   /**< Number of address bus cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
    BDK_CORE_PERF_BADDL2    = 38,   /**< Number of address bus cycles not reflected (i.e. destined for L2) (may need to set CvmCtl[DISCE] for accurate counts) */
    BDK_CORE_PERF_BFILL     = 39,   /**< Number of fill bus cycles used (may need to set CvmCtl[DISCE] for accurate counts) */
    BDK_CORE_PERF_DDIDS     = 40,   /**< Number of Dstream DIDs created */
    BDK_CORE_PERF_IDIDS     = 41,   /**< Number of Istream DIDs created */
    BDK_CORE_PERF_DIDNA     = 42,   /**< Number of cycles that no DIDs were available (may need to set CvmCtl[DISCE] and CvmMemCtl[MCLK] for accurate counts) */
    BDK_CORE_PERF_LDS       = 43,   /**< Number of load issues */
    BDK_CORE_PERF_LMLDS     = 44,   /**< Number of local memory load */
    BDK_CORE_PERF_IOLDS     = 45,   /**< Number of I/O load issues */
    BDK_CORE_PERF_DMLDS     = 46,   /**< Number of loads that were not prefetches and missed in the cache */
    BDK_CORE_PERF_STS       = 48,   /**< Number of store issues */
    BDK_CORE_PERF_LMSTS     = 49,   /**< Number of local memory store issues */
    BDK_CORE_PERF_IOSTS     = 50,   /**< Number of I/O store issues */
    BDK_CORE_PERF_IOBDMA    = 51,   /**< Number of IOBDMAs */
    BDK_CORE_PERF_DTLB      = 53,   /**< Number of dstream TLB refill, invalid, or modified exceptions */
    BDK_CORE_PERF_DTLBAD    = 54,   /**< Number of dstream TLB address errors */
    BDK_CORE_PERF_ITLB      = 55,   /**< Number of istream TLB refill, invalid, or address error exceptions */
    BDK_CORE_PERF_SYNC      = 56,   /**< Number of SYNC stall cycles (may need to set CvmCtl[DISCE] for accurate counts) */
    BDK_CORE_PERF_SYNCIOB   = 57,   /**< Number of SYNCIOBDMA stall cycles (may need to set CvmCtl[DISCE] for accurate counts) */
    BDK_CORE_PERF_SYNCW     = 58,   /**< Number of SYNCWs */
    /* Added in CN63XX */
    BDK_CORE_PERF_ERETMIS   = 64,   /**< D/eret mispredicts */
    BDK_CORE_PERF_LIKMIS    = 65,   /**< Branch likely mispredicts */
    BDK_CORE_PERF_HAZTR     = 66,   /**< Hazard traps due to *MTC0 to CvmCtl, Perf counter control, EntryHi, or CvmMemCtl registers */
    BDK_CORE_PERF_MAX               /**< This not a counter, just a marker for the highest number */
} bdk_core_perf_t;

/**
 * Bit description of the COP0 counter control register
 */
typedef union
{
    uint32_t u32;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32_t m              : 1; /**< Set to 1 for sel 0 and 0 for sel 2, indicating there are two performance counters */
        uint32_t w              : 1; /**< Set to 1 indicating coutners are 64 bit */
        uint32_t reserved_11_29 :15;
        bdk_core_perf_t event  :10; /**< Selects the event to be counted by the corresponding Counter Register */
        uint32_t ie             : 1; /**< Count in interrupt context */
        uint32_t u              : 1; /**< Count in user mode */
        uint32_t s              : 1; /**< Count in supervisor mode */
        uint32_t k              : 1; /**< Count in kernel mode */
        uint32_t ex             : 1; /**< Count in exception context */
#else
	uint32_t ex             : 1;
        uint32_t k              : 1;
        uint32_t s              : 1;
        uint32_t u              : 1;
        uint32_t ie             : 1;
        uint32_t event          :10;
        uint32_t reserved_11_29 :15;
        uint32_t w              : 1;
        uint32_t m              : 1;
#endif
    } s;
} bdk_core_perf_control_t;

typedef enum {
    BDK_TLB_PAGEMASK_4K   = 0x3     << 11,
    BDK_TLB_PAGEMASK_16K  = 0xF     << 11,
    BDK_TLB_PAGEMASK_64K  = 0x3F    << 11,
    BDK_TLB_PAGEMASK_256K = 0xFF    << 11,
    BDK_TLB_PAGEMASK_1M   = 0x3FF   << 11,
    BDK_TLB_PAGEMASK_4M   = 0xFFF   << 11,
    BDK_TLB_PAGEMASK_16M  = 0x3FFF  << 11,
    BDK_TLB_PAGEMASK_64M  = 0xFFFF  << 11,
    BDK_TLB_PAGEMASK_256M = 0x3FFFF << 11,
} bdk_tlb_pagemask_t;


int bdk_core_add_wired_tlb_entry(uint64_t hi, uint64_t lo0, uint64_t lo1, bdk_tlb_pagemask_t page_mask);


int bdk_core_add_fixed_tlb_mapping(uint64_t vaddr, uint64_t page0_addr, uint64_t page1_addr, bdk_tlb_pagemask_t page_mask);
int bdk_core_add_fixed_tlb_mapping_bits(uint64_t vaddr, uint64_t page0_addr, uint64_t page1_addr, bdk_tlb_pagemask_t page_mask);

/**
 * Return number of TLB entries.
 */
int bdk_core_get_tlb_entries(void);

/** @} */
