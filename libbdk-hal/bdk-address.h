/**
 * @file
 * Typedefs and defines for working with Octeon physical addresses.
 *
 * <hr>$Revision: 38306 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum {
   BDK_MIPS_SPACE_XKSEG = 3LL,
   BDK_MIPS_SPACE_XKPHYS = 2LL,
   BDK_MIPS_SPACE_XSSEG = 1LL,
   BDK_MIPS_SPACE_XUSEG = 0LL
} bdk_mips_space_t;

typedef enum {
   BDK_MIPS_XKSEG_SPACE_KSEG0 = 0LL,
   BDK_MIPS_XKSEG_SPACE_KSEG1 = 1LL,
   BDK_MIPS_XKSEG_SPACE_SSEG = 2LL,
   BDK_MIPS_XKSEG_SPACE_KSEG3 = 3LL
} bdk_mips_xkseg_space_t;

  /* decodes <14:13> of a kseg3 window address */
typedef enum {
   BDK_ADD_WIN_SCR = 0L,
   BDK_ADD_WIN_DMA = 1L,   /* see bdk_add_win_dma_dec_t for further decode */
   BDK_ADD_WIN_UNUSED = 2L,
   BDK_ADD_WIN_UNUSED2 = 3L
} bdk_add_win_dec_t;

  /* decode within DMA space */
typedef enum {
   BDK_ADD_WIN_DMA_ADD = 0L,     /* add store data to the write buffer entry, allocating it if necessary */
   BDK_ADD_WIN_DMA_SENDMEM = 1L, /* send out the write buffer entry to DRAM */
   /* store data must be normal DRAM memory space address in this case */
   BDK_ADD_WIN_DMA_SENDDMA = 2L, /* send out the write buffer entry as an IOBDMA command */
   /* see BDK_ADD_WIN_DMA_SEND_DEC for data contents */
   BDK_ADD_WIN_DMA_SENDIO = 3L,  /* send out the write buffer entry as an IO write */
   /* store data must be normal IO space address in this case */
   BDK_ADD_WIN_DMA_SENDSINGLE = 4L, /* send out a single-tick command on the NCB bus */
   /* no write buffer data needed/used */
} bdk_add_win_dma_dec_t;

/**
 *   Physical Address Decode
 *
 * Octeon-I HW never interprets this X (<39:36> reserved
 * for future expansion), software should set to 0.
 *
 *  - 0x0 XXX0 0000 0000 to      DRAM         Cached
 *  - 0x0 XXX0 0FFF FFFF
 *
 *  - 0x0 XXX0 1000 0000 to      Boot Bus     Uncached  (Converted to 0x1 00X0 1000 0000
 *  - 0x0 XXX0 1FFF FFFF         + EJTAG                           to 0x1 00X0 1FFF FFFF)
 *
 *  - 0x0 XXX0 2000 0000 to      DRAM         Cached
 *  - 0x0 XXXF FFFF FFFF
 *
 *  - 0x1 00X0 0000 0000 to      Boot Bus     Uncached
 *  - 0x1 00XF FFFF FFFF
 *
 *  - 0x1 01X0 0000 0000 to      Other NCB    Uncached
 *  - 0x1 FFXF FFFF FFFF         devices
 *
 * Decode of all Octeon addresses
 */
typedef union {

   uint64_t         u64;

   struct {
      bdk_mips_space_t          R   : 2;
      uint64_t               offset :62;
   } sva; /* mapped or unmapped virtual address */

   struct {
      uint64_t               zeroes :33;
      uint64_t               offset :31;
   } suseg; /* mapped USEG virtual addresses (typically) */

   struct {
      uint64_t                ones  :33;
      bdk_mips_xkseg_space_t   sp   : 2;
      uint64_t               offset :29;
   } sxkseg; /* mapped or unmapped virtual address */

   struct {
      bdk_mips_space_t          R   : 2; /* BDK_MIPS_SPACE_XKPHYS in this case */
      uint64_t                 cca  : 3; /* ignored by octeon */
      uint64_t                 mbz  :10;
      uint64_t                  pa  :49; /* physical address */
   } sxkphys; /* physical address accessed through xkphys unmapped virtual address */

   struct {
      uint64_t                 mbz  :15;
      uint64_t                is_io : 1; /* if set, the address is uncached and resides on MCB bus */
      uint64_t                 did  : 8; /* the hardware ignores this field when is_io==0, else device ID */
      uint64_t                unaddr: 4; /* the hardware ignores <39:36> in Octeon I */
      uint64_t               offset :36;
   } sphys; /* physical address */

   struct {
      uint64_t               zeroes :24; /* techically, <47:40> are dont-cares */
      uint64_t                unaddr: 4; /* the hardware ignores <39:36> in Octeon I */
      uint64_t               offset :36;
   } smem; /* physical mem address */

   struct {
      uint64_t                 mem_region  :2;
      uint64_t                 mbz  :13;
      uint64_t                is_io : 1; /* 1 in this case */
      uint64_t                 did  : 8; /* the hardware ignores this field when is_io==0, else device ID */
      uint64_t                unaddr: 4; /* the hardware ignores <39:36> in Octeon I */
      uint64_t               offset :36;
   } sio; /* physical IO address */

   struct {
      uint64_t                ones   : 49;
      bdk_add_win_dec_t   csrdec : 2;    /* BDK_ADD_WIN_SCR (0) in this case */
      uint64_t                addr   : 13;
   } sscr; /* scratchpad virtual address - accessed through a window at the end of kseg3 */

   /* there should only be stores to IOBDMA space, no loads */
   struct {
      uint64_t                ones   : 49;
      bdk_add_win_dec_t   csrdec : 2;    /* BDK_ADD_WIN_DMA (1) in this case */
      uint64_t                unused2: 3;
      bdk_add_win_dma_dec_t type : 3;
      uint64_t                addr   : 7;
   } sdma; /* IOBDMA virtual address - accessed through a window at the end of kseg3 */

   struct {
      uint64_t                didspace : 24;
      uint64_t                unused   : 40;
   } sfilldidspace;

} bdk_addr_t;

/* These macros for used by 32 bit applications */

#define BDK_MIPS32_SPACE_KSEG0 1l
#define BDK_ADD_SEG32(segment, add)          (((int32_t)segment << 31) | (int32_t)(add))

/* Currently all IOs are performed using XKPHYS addressing. Linux uses the
    CvmMemCtl register to enable XKPHYS addressing to IO space from user mode.
    Future OSes may need to change the upper bits of IO addresses. The
    following define controls the upper two bits for all IO addresses generated
    by the simple executive library */
#define BDK_IO_SEG BDK_MIPS_SPACE_XKPHYS

/* These macros simplify the process of creating common IO addresses */
#define BDK_ADD_SEG(segment, add)          ((((uint64_t)segment) << 62) | (add))
#ifndef BDK_ADD_IO_SEG
#define BDK_ADD_IO_SEG(add)                BDK_ADD_SEG(BDK_IO_SEG, (add))
#endif
#define BDK_ADDR_DIDSPACE(did)             (((BDK_IO_SEG) << 22) | ((1ULL) << 8) | (did))
#define BDK_ADDR_DID(did)                  (BDK_ADDR_DIDSPACE(did) << 40)
#define BDK_FULL_DID(did,subdid)           (((did) << 3) | (subdid))


   /* from include/ncb_rsl_id.v */
#define BDK_OCT_DID_MIS 0ULL   /* misc stuff */
#define BDK_OCT_DID_GMX0 1ULL
#define BDK_OCT_DID_GMX1 2ULL
#define BDK_OCT_DID_PCI 3ULL
#define BDK_OCT_DID_KEY 4ULL
#define BDK_OCT_DID_FPA 5ULL
#define BDK_OCT_DID_DFA 6ULL
#define BDK_OCT_DID_ZIP 7ULL
#define BDK_OCT_DID_RNG 8ULL
#define BDK_OCT_DID_IPD 9ULL
#define BDK_OCT_DID_PKT 10ULL
#define BDK_OCT_DID_TIM 11ULL
#define BDK_OCT_DID_TAG 12ULL
   /* the rest are not on the IO bus */
#define BDK_OCT_DID_L2C 16ULL
#define BDK_OCT_DID_LMC 17ULL
#define BDK_OCT_DID_SPX0 18ULL
#define BDK_OCT_DID_SPX1 19ULL
#define BDK_OCT_DID_PIP 20ULL
#define BDK_OCT_DID_ASX0 22ULL
#define BDK_OCT_DID_ASX1 23ULL
#define BDK_OCT_DID_IOB 30ULL

#define BDK_OCT_DID_PKT_SEND       BDK_FULL_DID(BDK_OCT_DID_PKT,2ULL)
#define BDK_OCT_DID_TAG_SWTAG      BDK_FULL_DID(BDK_OCT_DID_TAG,0ULL)
#define BDK_OCT_DID_TAG_TAG1       BDK_FULL_DID(BDK_OCT_DID_TAG,1ULL)
#define BDK_OCT_DID_TAG_TAG2       BDK_FULL_DID(BDK_OCT_DID_TAG,2ULL)
#define BDK_OCT_DID_TAG_TAG3       BDK_FULL_DID(BDK_OCT_DID_TAG,3ULL)
#define BDK_OCT_DID_TAG_NULL_RD    BDK_FULL_DID(BDK_OCT_DID_TAG,4ULL)
#define BDK_OCT_DID_TAG_CSR        BDK_FULL_DID(BDK_OCT_DID_TAG,7ULL)
#define BDK_OCT_DID_FAU_FAI        BDK_FULL_DID(BDK_OCT_DID_IOB,0ULL)
#define BDK_OCT_DID_TIM_CSR        BDK_FULL_DID(BDK_OCT_DID_TIM,0ULL)
#define BDK_OCT_DID_KEY_RW         BDK_FULL_DID(BDK_OCT_DID_KEY,0ULL)
#define BDK_OCT_DID_PCI_6          BDK_FULL_DID(BDK_OCT_DID_PCI,6ULL)
#define BDK_OCT_DID_MIS_BOO        BDK_FULL_DID(BDK_OCT_DID_MIS,0ULL)
#define BDK_OCT_DID_PCI_RML        BDK_FULL_DID(BDK_OCT_DID_PCI,0ULL)
#define BDK_OCT_DID_IPD_CSR        BDK_FULL_DID(BDK_OCT_DID_IPD,7ULL)
#define BDK_OCT_DID_DFA_CSR        BDK_FULL_DID(BDK_OCT_DID_DFA,7ULL)
#define BDK_OCT_DID_MIS_CSR        BDK_FULL_DID(BDK_OCT_DID_MIS,7ULL)
#define BDK_OCT_DID_ZIP_CSR        BDK_FULL_DID(BDK_OCT_DID_ZIP,0ULL)

/** @} */
