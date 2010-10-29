/**
 * @file
 *
 * Interface to the Level 2 Cache (L2C) control, measurement, and debugging
 * facilities.
 *
 * <hr>$Revision: 50663 $<hr>
 *
 * @addtogroup hal
 * @{
 */

#define BDK_L2C_IDX_ADDR_SHIFT 7  /* based on 128 byte cache line size */
#define BDK_L2C_IDX_MASK       (bdk_l2c_get_num_sets() - 1)

/* Defines for index aliasing computations */
#define BDK_L2C_TAG_ADDR_ALIAS_SHIFT (BDK_L2C_IDX_ADDR_SHIFT + bdk_l2c_get_set_bits())
#define BDK_L2C_ALIAS_MASK (BDK_L2C_IDX_MASK << BDK_L2C_TAG_ADDR_ALIAS_SHIFT)
#define BDK_L2C_MEMBANK_SELECT_SIZE  4096

typedef union
{
    uint64_t u64;
#if __BYTE_ORDER == __BIG_ENDIAN
    struct
    {
	uint64_t reserved		: 28;
	uint64_t V			: 1;	// Line valid
	uint64_t D			: 1;	// Line dirty
	uint64_t L			: 1;	// Line locked
	uint64_t U			: 1;	// Use, LRU eviction
	uint64_t addr			: 32;	// Phys mem (not all bits valid)
    } s;
#endif
} bdk_l2c_tag_t;

/* Number of L2C Tag-and-data sections (TADs) that are connected to LMC. */
#define BDK_L2C_TADS  1

  /* L2C Performance Counter events. */
typedef enum
{
    BDK_L2C_EVENT_CYCLES           =  0,    /**< Cycles */
    BDK_L2C_EVENT_INSTRUCTION_MISS =  1,    /**< L2 Instruction Miss */
    BDK_L2C_EVENT_INSTRUCTION_HIT  =  2,    /**< L2 Instruction Hit */
    BDK_L2C_EVENT_DATA_MISS        =  3,    /**< L2 Data Miss */
    BDK_L2C_EVENT_DATA_HIT         =  4,    /**< L2 Data Hit */
    BDK_L2C_EVENT_MISS             =  5,    /**< L2 Miss (I/D) */
    BDK_L2C_EVENT_HIT              =  6,    /**< L2 Hit (I/D) */
    BDK_L2C_EVENT_VICTIM_HIT       =  7,    /**< L2 Victim Buffer Hit (Retry Probe) */
    BDK_L2C_EVENT_INDEX_CONFLICT   =  8,    /**< LFB-NQ Index Conflict */
    BDK_L2C_EVENT_TAG_PROBE        =  9,    /**< L2 Tag Probe (issued - could be VB-Retried) */
    BDK_L2C_EVENT_TAG_UPDATE       = 10,    /**< L2 Tag Update (completed). Note: Some CMD types do not update */
    BDK_L2C_EVENT_TAG_COMPLETE     = 11,    /**< L2 Tag Probe Completed (beyond VB-RTY window) */
    BDK_L2C_EVENT_TAG_DIRTY        = 12,    /**< L2 Tag Dirty Victim */
    BDK_L2C_EVENT_DATA_STORE_NOP   = 13,    /**< L2 Data Store NOP */
    BDK_L2C_EVENT_DATA_STORE_READ  = 14,    /**< L2 Data Store READ */
    BDK_L2C_EVENT_DATA_STORE_WRITE = 15,    /**< L2 Data Store WRITE */
    BDK_L2C_EVENT_FILL_DATA_VALID  = 16,    /**< Memory Fill Data valid */
    BDK_L2C_EVENT_WRITE_REQUEST    = 17,    /**< Memory Write Request */
    BDK_L2C_EVENT_READ_REQUEST     = 18,    /**< Memory Read Request */
    BDK_L2C_EVENT_WRITE_DATA_VALID = 19,    /**< Memory Write Data valid */
    BDK_L2C_EVENT_XMC_NOP          = 20,    /**< XMC NOP */
    BDK_L2C_EVENT_XMC_LDT          = 21,    /**< XMC LDT */
    BDK_L2C_EVENT_XMC_LDI          = 22,    /**< XMC LDI */
    BDK_L2C_EVENT_XMC_LDD          = 23,    /**< XMC LDD */
    BDK_L2C_EVENT_XMC_STF          = 24,    /**< XMC STF */
    BDK_L2C_EVENT_XMC_STT          = 25,    /**< XMC STT */
    BDK_L2C_EVENT_XMC_STP          = 26,    /**< XMC STP */
    BDK_L2C_EVENT_XMC_STC          = 27,    /**< XMC STC */
    BDK_L2C_EVENT_XMC_DWB          = 28,    /**< XMC DWB */
    BDK_L2C_EVENT_XMC_PL2          = 29,    /**< XMC PL2 */
    BDK_L2C_EVENT_XMC_PSL1         = 30,    /**< XMC PSL1 */
    BDK_L2C_EVENT_XMC_IOBLD        = 31,    /**< XMC IOBLD */
    BDK_L2C_EVENT_XMC_IOBST        = 32,    /**< XMC IOBST */
    BDK_L2C_EVENT_XMC_IOBDMA       = 33,    /**< XMC IOBDMA */
    BDK_L2C_EVENT_XMC_IOBRSP       = 34,    /**< XMC IOBRSP */
    BDK_L2C_EVENT_XMC_BUS_VALID    = 35,    /**< XMC Bus valid (all) */
    BDK_L2C_EVENT_XMC_MEM_DATA     = 36,    /**< XMC Bus valid (DST=L2C) Memory */
    BDK_L2C_EVENT_XMC_REFL_DATA    = 37,    /**< XMC Bus valid (DST=IOB) REFL Data */
    BDK_L2C_EVENT_XMC_IOBRSP_DATA  = 38,    /**< XMC Bus valid (DST=PP) IOBRSP Data */
    BDK_L2C_EVENT_RSC_NOP          = 39,    /**< RSC NOP */
    BDK_L2C_EVENT_RSC_STDN         = 40,    /**< RSC STDN */
    BDK_L2C_EVENT_RSC_FILL         = 41,    /**< RSC FILL */
    BDK_L2C_EVENT_RSC_REFL         = 42,    /**< RSC REFL */
    BDK_L2C_EVENT_RSC_STIN         = 43,    /**< RSC STIN */
    BDK_L2C_EVENT_RSC_SCIN         = 44,    /**< RSC SCIN */
    BDK_L2C_EVENT_RSC_SCFL         = 45,    /**< RSC SCFL */
    BDK_L2C_EVENT_RSC_SCDN         = 46,    /**< RSC SCDN */
    BDK_L2C_EVENT_RSC_DATA_VALID   = 47,    /**< RSC Data Valid */
    BDK_L2C_EVENT_RSC_VALID_FILL   = 48,    /**< RSC Data Valid (FILL) */
    BDK_L2C_EVENT_RSC_VALID_STRSP  = 49,    /**< RSC Data Valid (STRSP) */
    BDK_L2C_EVENT_RSC_VALID_REFL   = 50,    /**< RSC Data Valid (REFL) */
    BDK_L2C_EVENT_LRF_REQ          = 51,    /**< LRF-REQ (LFB-NQ) */
    BDK_L2C_EVENT_DT_RD_ALLOC      = 52,    /**< DT RD-ALLOC */
    BDK_L2C_EVENT_DT_WR_INVAL      = 53,    /**< DT WR-INVAL */
    BDK_L2C_EVENT_MAX
} bdk_l2c_event_t;

/* L2C Performance Counter events for Octeon2. */
typedef enum
{
     BDK_L2C_TAD_EVENT_NONE          = 0,     /* None */
     BDK_L2C_TAD_EVENT_TAG_HIT       = 1,     /* L2 Tag Hit */
     BDK_L2C_TAD_EVENT_TAG_MISS      = 2,     /* L2 Tag Miss */
     BDK_L2C_TAD_EVENT_TAG_NOALLOC   = 3,     /* L2 Tag NoAlloc (forced no-allocate) */
     BDK_L2C_TAD_EVENT_TAG_VICTIM    = 4,     /* L2 Tag Victim */
     BDK_L2C_TAD_EVENT_SC_FAIL       = 5,     /* SC Fail */
     BDK_L2C_TAD_EVENT_SC_PASS       = 6,     /* SC Pass */
     BDK_L2C_TAD_EVENT_LFB_VALID     = 7,     /* LFB Occupancy (each cycle adds \# of LFBs valid) */
     BDK_L2C_TAD_EVENT_LFB_WAIT_LFB  = 8,     /* LFB Wait LFB (each cycle adds \# LFBs waiting for other LFBs) */
     BDK_L2C_TAD_EVENT_LFB_WAIT_VAB  = 9,     /* LFB Wait VAB (each cycle adds \# LFBs waiting for VAB) */
     BDK_L2C_TAD_EVENT_QUAD0_INDEX   = 128,   /* Quad 0 index bus inuse */
     BDK_L2C_TAD_EVENT_QUAD0_READ    = 129,   /* Quad 0 read data bus inuse */
     BDK_L2C_TAD_EVENT_QUAD0_BANK    = 130,   /* Quad 0 \# banks inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD0_WDAT    = 131,   /* Quad 0 wdat flops inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD1_INDEX   = 144,   /* Quad 1 index bus inuse */
     BDK_L2C_TAD_EVENT_QUAD1_READ    = 145,   /* Quad 1 read data bus inuse */
     BDK_L2C_TAD_EVENT_QUAD1_BANK    = 146,   /* Quad 1 \# banks inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD1_WDAT    = 147,   /* Quad 1 wdat flops inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD2_INDEX   = 160,   /* Quad 2 index bus inuse */
     BDK_L2C_TAD_EVENT_QUAD2_READ    = 161,   /* Quad 2 read data bus inuse */
     BDK_L2C_TAD_EVENT_QUAD2_BANK    = 162,   /* Quad 2 \# banks inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD2_WDAT    = 163,   /* Quad 2 wdat flops inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD3_INDEX   = 176,   /* Quad 3 index bus inuse */
     BDK_L2C_TAD_EVENT_QUAD3_READ    = 177,   /* Quad 3 read data bus inuse */
     BDK_L2C_TAD_EVENT_QUAD3_BANK    = 178,   /* Quad 3 \# banks inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_QUAD3_WDAT    = 179,   /* Quad 3 wdat flops inuse (0-4/cycle) */
     BDK_L2C_TAD_EVENT_MAX
} bdk_l2c_tad_event_t;

/**
 * Configure one of the four L2 Cache performance counters to capture event
 * occurences.
 *
 * @param counter        The counter to configure. Range 0..3.
 * @param event          The type of L2 Cache event occurrence to count.
 * @param clear_on_read  When asserted, any read of the performance counter
 *                       clears the counter.
 *
 * @note The routine does not clear the counter.
 */
void bdk_l2c_config_perf(uint32_t counter, bdk_l2c_event_t event, uint32_t clear_on_read);

/**
 * Read the given L2 Cache performance counter. The counter must be configured
 * before reading, but this routine does not enforce this requirement.
 *
 * @param counter  The counter to configure. Range 0..3.
 *
 * @return The current counter value.
 */
uint64_t bdk_l2c_read_perf(uint32_t counter);

/**
 * Return the L2 Cache way partitioning for a given core.
 *
 * @param core  The core processor of interest.
 *
 * @return    The mask specifying the partitioning. 0 bits in mask indicates
 *              the cache 'ways' that a core can evict from.
 *            -1 on error
 */
int bdk_l2c_get_core_way_partition(uint32_t core);

/**
 * Partitions the L2 cache for a core
 *
 * @param core   The core that the partitioning applies to.
 * @param mask The partitioning of the ways expressed as a binary mask. A 0 bit allows the core
 *             to evict cache lines from a way, while a 1 bit blocks the core from evicting any lines
 *             from that way. There must be at least one allowed way (0 bit) in the mask.
 *
 * @note  If any ways are blocked for all cores and the HW blocks, then those ways will never have
 *        any cache lines evicted from them.  All cores and the hardware blocks are free to read from
 *        all ways regardless of the partitioning.
 */
int bdk_l2c_set_core_way_partition(uint32_t core, uint32_t mask);

/**
 * Return the L2 Cache way partitioning for the hw blocks.
 *
 * @return    The mask specifying the reserved way. 0 bits in mask indicates
 *              the cache 'ways' that a core can evict from.
 *            -1 on error
 */
int bdk_l2c_get_hw_way_partition(void);

/**
 * Partitions the L2 cache for the hardware blocks.
 *
 * @param mask The partitioning of the ways expressed as a binary mask. A 0 bit allows the core
 *             to evict cache lines from a way, while a 1 bit blocks the core from evicting any lines
 *             from that way. There must be at least one allowed way (0 bit) in the mask.
 *
 * @note  If any ways are blocked for all cores and the HW blocks, then those ways will never have
 *        any cache lines evicted from them.  All cores and the hardware blocks are free to read from
 *        all ways regardless of the partitioning.
 */
int bdk_l2c_set_hw_way_partition(uint32_t mask);


/**
 * Locks a line in the L2 cache at the specified physical address
 *
 * @param addr   physical address of line to lock
 *
 * @return 0 on success,
 *         1 if line not locked.
 */
int bdk_l2c_lock_line(uint64_t addr);

/**
 * Locks a specified memory region in the L2 cache.
 *
 * Note that if not all lines can be locked, that means that all
 * but one of the ways (associations) available to the locking
 * core are locked.  Having only 1 association available for
 * normal caching may have a significant adverse affect on performance.
 * Care should be taken to ensure that enough of the L2 cache is left
 * unlocked to allow for normal caching of DRAM.
 *
 * @param start  Physical address of the start of the region to lock
 * @param len    Length (in bytes) of region to lock
 *
 * @return Number of requested lines that where not locked.
 *         0 on success (all locked)
 */
int bdk_l2c_lock_mem_region(uint64_t start, uint64_t len);


/**
 * Unlock and flush a cache line from the L2 cache.
 * IMPORTANT: Must only be run by one core at a time due to use
 * of L2C debug features.
 * Note that this function will flush a matching but unlocked cache line.
 * (If address is not in L2, no lines are flushed.)
 *
 * @param address Physical address to unlock
 *
 * @return 0: line not unlocked
 *         1: line unlocked
 */
int bdk_l2c_unlock_line(uint64_t address);

/**
 * Unlocks a region of memory that is locked in the L2 cache
 *
 * @param start  start physical address
 * @param len    length (in bytes) to unlock
 *
 * @return Number of locked lines that the call unlocked
 */
int bdk_l2c_unlock_mem_region(uint64_t start, uint64_t len);




/**
 * Read the L2 controller tag for a given location in L2
 *
 * @param association
 *               Which association to read line from
 * @param index  Which way to read from.
 *
 * @return l2c tag structure for line requested.
 */
bdk_l2c_tag_t bdk_l2c_get_tag(uint32_t association, uint32_t index);

/**
 * Returns the cache index for a given physical address
 *
 * @param addr   physical address
 *
 * @return L2 cache index
 */
uint32_t bdk_l2c_address_to_index (uint64_t addr);


/**
 * Flushes (and unlocks) the entire L2 cache.
 * IMPORTANT: Must only be run by one core at a time due to use
 * of L2C debug features.
 */
void bdk_l2c_flush(void);



/**
 *
 * @return Returns the size of the L2 cache in bytes,
 * -1 on error (unrecognized model)
 */
int bdk_l2c_get_cache_size_bytes(void);

/**
 * Return the number of sets in the L2 Cache
 *
 * @return
 */
int bdk_l2c_get_num_sets(void);

/**
 * Return log base 2 of the number of sets in the L2 cache
 * @return
 */
int bdk_l2c_get_set_bits(void);
/**
 * Return the number of associations in the L2 Cache
 *
 * @return
 */
int bdk_l2c_get_num_assoc(void);

/**
 * Flush a line from the L2 cache
 * This should only be called from one core at a time, as this routine
 * sets the core to the 'debug' core in order to flush the line.
 *
 * @param assoc  Association (or way) to flush
 * @param index  Index to flush
 */
void bdk_l2c_flush_line(uint32_t assoc, uint32_t index);

/** @} */
