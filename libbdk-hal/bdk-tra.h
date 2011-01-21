/**
 * @file
 *
 * <hr>$Revision: 53259 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Enumeration of the bitmask of all the filter commands
 */
typedef enum
{
    BDK_TRA_FILT_NOP     = 1ull<<0,  /**< none */
    BDK_TRA_FILT_LDT     = 1ull<<1,  /**< don't allocate L2 or L1 */
    BDK_TRA_FILT_LDI     = 1ull<<2,  /**< don't allocate L1 */
    BDK_TRA_FILT_PL2     = 1ull<<3,  /**< pref L2 */
    BDK_TRA_FILT_RPL2    = 1ull<<4,  /**< mark for replacement in L2 */
    BDK_TRA_FILT_DWB     = 1ull<<5,  /**< clear L2 dirty bit (no writeback) + RPL2 */
    BDK_TRA_FILT_LDD     = 1ull<<8,  /**< normal load */
    BDK_TRA_FILT_PSL1    = 1ull<<9,  /**< pref L1, bypass L2 */
    BDK_TRA_FILT_IOBDMA  = 1ull<<15,  /**< store reflection by IOB for prior load */
    BDK_TRA_FILT_STF     = 1ull<<16, /**< full block store to L2, fill 0's */
    BDK_TRA_FILT_STT     = 1ull<<17, /**< full block store bypass-L2, fill 0's */
    BDK_TRA_FILT_STP     = 1ull<<18, /**< partial store to L2 */
    BDK_TRA_FILT_STC     = 1ull<<19, /**< partial store to L2, if duptag valid */
    BDK_TRA_FILT_STFIL1  = 1ull<<20, /**< full block store to L2, fill 0's, invalidate L1 */
    BDK_TRA_FILT_STTIL1  = 1ull<<21, /**< full block store bypass-L2, fill 0's, invalidate L1 */
    BDK_TRA_FILT_FAS32   = 1ull<<22, /**< to load from and write a word of memory atomically */
    BDK_TRA_FILT_FAS64   = 1ull<<23, /**< to load from and write a doubleword of memory atomically */
    BDK_TRA_FILT_WBIL2I  = 1ull<<24, /**< writeback if dirty, invalidate, clear use bit, by index/way */
    BDK_TRA_FILT_LTGL2I  = 1ull<<25, /**< read tag @ index/way into CSR */
    BDK_TRA_FILT_STGL2I  = 1ull<<26, /**< write tag @ index/way from CSR */
    BDK_TRA_FILT_INVL2   = 1ull<<28, /**< invalidate, clear use bit, by address (dirty data is LOST) */
    BDK_TRA_FILT_WBIL2   = 1ull<<29, /**< writeback if dirty, invalidate, clear use bit, by address */
    BDK_TRA_FILT_WBL2    = 1ull<<30, /**< writeback if dirty, make clean, clear use bit, by address */
    BDK_TRA_FILT_LCKL2   = 1ull<<31, /**< allocate (if miss), set lock bit, set use bit, by address */
    BDK_TRA_FILT_IOBLD8  = 1ull<<32, /**< load reflection 8bit */
    BDK_TRA_FILT_IOBLD16 = 1ull<<33, /**< load reflection 16bit */
    BDK_TRA_FILT_IOBLD32 = 1ull<<34, /**< load reflection 32bit */
    BDK_TRA_FILT_IOBLD64 = 1ull<<35, /**< load reflection 64bit */
    BDK_TRA_FILT_IOBST8  = 1ull<<36, /**< store reflection 8bit */
    BDK_TRA_FILT_IOBST16 = 1ull<<37, /**< store reflection 16bit */
    BDK_TRA_FILT_IOBST32 = 1ull<<38, /**< store reflection 32bit */
    BDK_TRA_FILT_IOBST64 = 1ull<<39, /**< store reflection 64bit */
    BDK_TRA_FILT_SET8    = 1ull<<40, /**< to load from and write 1's to 8bit of memory atomically */
    BDK_TRA_FILT_SET16   = 1ull<<41, /**< to load from and write 1's to 16bit of memory atomically */
    BDK_TRA_FILT_SET32   = 1ull<<42, /**< to load from and write 1's to 32bit of memory atomically */
    BDK_TRA_FILT_SET64   = 1ull<<43, /**< to load from and write 1's to 64bit of memory atomically */
    BDK_TRA_FILT_CLR8    = 1ull<<44, /**< to load from and write 0's to 8bit of memory atomically */
    BDK_TRA_FILT_CLR16   = 1ull<<45, /**< to load from and write 0's to 16bit of memory atomically */
    BDK_TRA_FILT_CLR32   = 1ull<<46, /**< to load from and write 0's to 32bit of memory atomically */
    BDK_TRA_FILT_CLR64   = 1ull<<47, /**< to load from and write 0's to 64bit of memory atomically */
    BDK_TRA_FILT_INCR8   = 1ull<<48, /**< to load and increment 8bit of memory atomically */
    BDK_TRA_FILT_INCR16  = 1ull<<49, /**< to load and increment 16bit of memory atomically */
    BDK_TRA_FILT_INCR32  = 1ull<<50, /**< to load and increment 32bit of memory atomically */
    BDK_TRA_FILT_INCR64  = 1ull<<51, /**< to load and increment 64bit of memory atomically */
    BDK_TRA_FILT_DECR8   = 1ull<<52, /**< to load and decrement 8bit of memory atomically */
    BDK_TRA_FILT_DECR16  = 1ull<<53, /**< to load and decrement 16bit of memory atomically */
    BDK_TRA_FILT_DECR32  = 1ull<<54, /**< to load and decrement 32bit of memory atomically */
    BDK_TRA_FILT_DECR64  = 1ull<<55, /**< to load and decrement 64bit of memory atomically */
    BDK_TRA_FILT_FAA32   = 1ull<<58, /**< to load from and add to a word of memory atomically */
    BDK_TRA_FILT_FAA64   = 1ull<<59, /**< to load from and add to a doubleword of memory atomically  */
    BDK_TRA_FILT_SAA32   = 1ull<<62, /**< to atomically add a word to a memory location */
    BDK_TRA_FILT_SAA64   = 1ull<<63, /**< to atomically add a doubleword to a memory location */
    BDK_TRA_FILT_ALL     = -1ull     /**< all the above filter commands */
} bdk_tra_filt_t;

/*
 * Enumeration of the bitmask of all source commands.
 */
typedef enum
{
    BDK_TRA_SID_PP0      = 1ull<<0,  /**< Enable tracing from PP0 with matching sourceID */
    BDK_TRA_SID_PP1      = 1ull<<1,  /**< Enable tracing from PP1 with matching sourceID */
    BDK_TRA_SID_PP2      = 1ull<<2,  /**< Enable tracing from PP2 with matching sourceID */
    BDK_TRA_SID_PP3      = 1ull<<3,  /**< Enable tracing from PP3 with matching sourceID */
    BDK_TRA_SID_PP4      = 1ull<<4,  /**< Enable tracing from PP4 with matching sourceID */
    BDK_TRA_SID_PP5      = 1ull<<5,  /**< Enable tracing from PP5 with matching sourceID */
    BDK_TRA_SID_PP6      = 1ull<<6,  /**< Enable tracing from PP6 with matching sourceID */
    BDK_TRA_SID_PP7      = 1ull<<7,  /**< Enable tracing from PP7 with matching sourceID */
    BDK_TRA_SID_PP8      = 1ull<<8,  /**< Enable tracing from PP8 with matching sourceID */
    BDK_TRA_SID_PP9      = 1ull<<9,  /**< Enable tracing from PP9 with matching sourceID */
    BDK_TRA_SID_PP10     = 1ull<<10, /**< Enable tracing from PP10 with matching sourceID */
    BDK_TRA_SID_PP11     = 1ull<<11, /**< Enable tracing from PP11 with matching sourceID */
    BDK_TRA_SID_PP12     = 1ull<<12, /**< Enable tracing from PP12 with matching sourceID */
    BDK_TRA_SID_PP13     = 1ull<<13, /**< Enable tracing from PP13 with matching sourceID */
    BDK_TRA_SID_PP14     = 1ull<<14, /**< Enable tracing from PP14 with matching sourceID */
    BDK_TRA_SID_PP15     = 1ull<<15, /**< Enable tracing from PP15 with matching sourceID */
    BDK_TRA_SID_PKI      = 1ull<<16, /**< Enable tracing of write requests from PIP/IPD */
    BDK_TRA_SID_PKO      = 1ull<<17, /**< Enable tracing of write requests from PKO */
    BDK_TRA_SID_IOBREQ   = 1ull<<18, /**< Enable tracing of write requests from FPA,TIM,DFA,PCI,ZIP,SSO, and PKO (writes) */
    BDK_TRA_SID_DWB      = 1ull<<19, /**< Enable tracing of write requests from IOB DWB engine */
    BDK_TRA_SID_ALL      = -1ull     /**< Enable tracing all the above source commands */
} bdk_tra_sid_t;


#define BDK_TRA_DID_SLI  BDK_TRA_DID_PCI /**< Enable tracing of requests to SLI and RSL-type CSRs. */
/*
 * Enumeration of the bitmask of all destination commands.
 */
typedef enum
{
    BDK_TRA_DID_MIO      = 1ull<<0,  /**< Enable tracing of CIU and GPIO CSR's */
    BDK_TRA_DID_PCI      = 1ull<<3,  /**< Enable tracing of requests to PCI and RSL type CSR's */
    BDK_TRA_DID_KEY      = 1ull<<4,  /**< Enable tracing of requests to KEY memory */
    BDK_TRA_DID_FPA      = 1ull<<5,  /**< Enable tracing of requests to FPA */
    BDK_TRA_DID_DFA      = 1ull<<6,  /**< Enable tracing of requests to DFA */
    BDK_TRA_DID_ZIP      = 1ull<<7,  /**< Enable tracing of requests to ZIP */
    BDK_TRA_DID_RNG      = 1ull<<8,  /**< Enable tracing of requests to RNG */
    BDK_TRA_DID_IPD      = 1ull<<9,  /**< Enable tracing of IPD CSR accesses */
    BDK_TRA_DID_PKO      = 1ull<<10, /**< Enable tracing of PKO accesses (doorbells) */
    BDK_TRA_DID_SSO      = 1ull<<12, /**< Enable tracing of requests to RNG */
    BDK_TRA_DID_USB0     = 1ull<<13, /**< Enable tracing of USB0 accesses (UAHC0 EHCI and OHCI NCB CSRs) */
    BDK_TRA_DID_RAD      = 1ull<<14, /**< Enable tracing of RAD accesses (doorbells) */
    BDK_TRA_DID_DPI      = 1ull<<27, /**< Enable tracing of DPI accesses (DPI NCD CSRs) */
    BDK_TRA_DID_FAU      = 1ull<<30, /**< Enable tracing FAU accesses */
    BDK_TRA_DID_ALL      = -1ull     /**< Enable tracing all the above destination commands */
} bdk_tra_did_t;

typedef struct
{
    uint64_t data[(128*2+1)*4];
} bdk_tra_capture_t;

/**
 * Setup the TRA buffer for use
 *
 * @param control TRA control setup
 * @param filter  Which events to log
 * @param source_filter
 *                Source match
 * @param dest_filter
 *                Destination match
 * @param address Address compare
 * @param address_mask
 *                Address mask
 */
extern void bdk_tra_setup(bdk_tra_filt_t filter, bdk_tra_sid_t source_filter,
    bdk_tra_did_t dest_filter, uint64_t address, uint64_t address_mask);

/**
 * Setup a TRA trigger. How the triggers are used should be
 * setup using bdk_tra_setup.
 *
 * @param trigger Trigger to setup (0 or 1)
 * @param filter  Which types of events to trigger on
 * @param source_filter
 *                Source trigger match
 * @param dest_filter
 *                Destination trigger match
 * @param address Trigger address compare
 * @param address_mask
 *                Trigger address mask
 */
extern void bdk_tra_trig_setup(int trigger, bdk_tra_filt_t filter,
    bdk_tra_sid_t source_filter, bdk_tra_did_t dest_filter,
    uint64_t address, uint64_t address_mask);

extern void bdk_tra_enable(void);
extern void bdk_tra_disable(void);
extern int bdk_tra_capture(bdk_tra_capture_t *capture);
extern int bdk_tra_decode(bdk_tra_capture_t *capture);

/** @} */
