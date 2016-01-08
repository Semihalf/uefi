/**
 * @file
 *
 * This is file defines ASM primitives for the executive.

 * <hr>$Revision: 53373 $<hr>
 *
 * @defgroup asm Assembly support
 * @{
 */

/* This header file can be included from a .S file.  Keep non-preprocessor
   things under !__ASSEMBLER__.  */
#ifndef __ASSEMBLER__

/* turn the variable name into a string */
#define __BDK_TMP_STR(x) __BDK_TMP_STR2(x)
#define __BDK_TMP_STR2(x) #x
#define __BDK_VASTR(...) #__VA_ARGS__

#define BDK_MRS_NV(reg, val) asm ("mrs %x[rd]," #reg : [rd] "=r" (val))
#define BDK_MRS(reg, val) asm volatile ("mrs %x[rd]," #reg : [rd] "=r" (val))
#define BDK_MSR(reg, val) asm volatile ("msr " #reg ",%x[rd]" : : [rd] "r" (val))

/* Bit insert / extract */
#define BDK_EXTRACT(result,input,lsb,width) asm ("UBFX %x[rt],%x[rs]," __BDK_TMP_STR(lsb) "," __BDK_TMP_STR(width) : [rt] "=r" (result) : [rs] "r" (input))
#define BDK_EXTRACTS(result,input,lsb,width) asm ("SBFX %x[rt],%x[rs]," __BDK_TMP_STR(lsb) "," __BDK_TMP_STR(width) : [rt] "=r" (result) : [rs] "r" (input))
#define BDK_INSERT(result,input,lsb,width) asm ("BFI %x[rt],%x[rs]," __BDK_TMP_STR(lsb) "," __BDK_TMP_STR(width) : [rt] "+r" (result) : [rs] "r" (input))

/* other useful stuff */
#define BDK_MB          asm volatile ("dmb sy"      : : :"memory") /* Full memory barrier, like MIPS SYNC */
#define BDK_WMB         asm volatile ("dmb st"      : : :"memory") /* Write memory barreir, like MIPS SYNCW */
#define BDK_WFE         asm volatile ("wfe"         : : :"memory") /* Wait for event */
#define BDK_SEV         asm volatile ("sev"         : : :"memory") /* Send global event */
#define BDK_DSB         asm volatile ("dsb sy"      : : :"memory") /* DSB */

// normal prefetches that use the pref instruction
#define BDK_PREFETCH_PREFX(type, address, offset) asm volatile ("PRFUM " type ", [%[rbase],%[off]]" : : [rbase] "r" (address), [off] "I" (offset))
// a normal prefetch
#define BDK_PREFETCH(address, offset) BDK_PREFETCH_PREFX("PLDL1KEEP", address, offset)
#define BDK_ICACHE_INVALIDATE  { asm volatile ("ic iallu" : : ); }    // invalidate entire icache

#define BDK_SYS_CVMCACHE_WBI_L2 "#0,c11,c1,#2"          // L2 Cache Cache Hit Writeback Invalidate
#define BDK_SYS_CVMCACHE_WB_L2 "#0,c11,c1,#3"           // L2 Cache Hit Writeback
#define BDK_SYS_CVMCACHE_LCK_L2 "#0,c11,c1,#4"          // L2 Cache Fetch and Lock
#define BDK_SYS_CVMCACHE_WBI_L2_INDEXED "#0,c11,c0,#5"  // L2 Cache Index Writeback Invalidate
#define BDK_SYS_CVMCACHE_LTG_L2_INDEXED "#0,c11,c0,#7"  // L2 Cache Index Load Tag
#define BDK_SYS_CVMCACHE_INVALL_DC "#0,c11,c0,#2"       // L1 Dcache Invalidate
#define BDK_CACHE_WBI_L2(address) { asm volatile ("sys " BDK_SYS_CVMCACHE_WBI_L2 ", %0" : : "r" (address)); } // Push to memory, invalidate, and unlock
#define BDK_CACHE_WBI_L2_INDEXED(encoded) { asm volatile ("sys " BDK_SYS_CVMCACHE_WBI_L2_INDEXED ", %0" : : "r" (encoded)); } // Push to memory, invalidate, and unlock, index by set/way
#define BDK_CACHE_WB_L2(address) { asm volatile ("sys " BDK_SYS_CVMCACHE_WB_L2 ", %0" : : "r" (address)); } // Push to memory, don't invalidate, don't unlock
#define BDK_CACHE_LCK_L2(address) { asm volatile ("sys " BDK_SYS_CVMCACHE_LCK_L2 ", %0" : : "r" (address)); } // Lock into L2
#define BDK_DCACHE_INVALIDATE { asm volatile ("sys " BDK_SYS_CVMCACHE_INVALL_DC ", xzr"); } // Invalidate the entire Dcache on local core
#define BDK_CACHE_LTG_L2_INDEXED(encoded) { asm volatile ("sys " BDK_SYS_CVMCACHE_LTG_L2_INDEXED ", %0" : : "r" (encoded)); } // Load L2 TAG, index by set/way 

#endif	/* __ASSEMBLER__ */

/** @} */
