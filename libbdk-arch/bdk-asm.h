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

#define BDK_MRS(reg, val) asm volatile ("mrs %[rd]," #reg : [rd] "=r" (val))
#define BDK_MSR(reg, val) asm volatile ("msr " #reg ",%[rd]" : : [rd] "r" (val))

/* Bit insert / extract */
#define BDK_EXTRACT(result,input,lsb,width) asm ("UBFX %[rt],%[rs]," __BDK_TMP_STR(lsb) "," __BDK_TMP_STR(width) : [rt] "=r" (result) : [rs] "r" (input))
#define BDK_EXTRACTS(result,input,lsb,width) asm ("SBFX %[rt],%[rs]," __BDK_TMP_STR(lsb) "," __BDK_TMP_STR(width) : [rt] "=r" (result) : [rs] "r" (input))
#define BDK_INSERT(result,input,lsb,width) asm ("BFI %[rt],%[rs]," __BDK_TMP_STR(lsb) "," __BDK_TMP_STR(width) : [rt] "+r" (result) : [rs] "r" (input))

/* other useful stuff */
#define BDK_MB          asm volatile ("dmb sy"      : : :"memory")
#define BDK_WMB         asm volatile ("dmb st"      : : :"memory")
#define BDK_WFE         asm volatile ("wfe"         : : :"memory")

// normal prefetches that use the pref instruction
#define BDK_PREFETCH_PREFX(type, address, offset) asm volatile ("PRFUM " type ", [%[rbase],%[off]]" : : [rbase] "r" (address), [off] "I" (offset))
// a normal prefetch
#define BDK_PREFETCH(address, offset) BDK_PREFETCH_PREFX("PLDL1KEEP", address, offset)
#define BDK_ICACHE_INVALIDATE  { asm volatile ("ic iallu" : : ); }    // invalidate entire icache
#define BDK_DCACHE_INVALIDATE  { asm volatile ("dc civac,xzr" : : ); } // invalidate entire dcache
#define BDK_SYS_CVMCACHE_WB_L2 "#0,c11,c1,#3"
#define BDK_SYS_CVMCACHE_LCK_L2 "#0,c11,c1,#4"
#define BDK_CACHE_LCKL2(address) { asm volatile ("sys " BDK_SYS_CVMCACHE_WB_L2 ", %0" : : "r" (address)); } // lock into L2
#define BDK_CACHE_WBIL2(address) { asm volatile ("sys " BDK_SYS_CVMCACHE_LCK_L2 ", %0" : : "r" (address)); } // Push to memory

#endif	/* __ASSEMBLER__ */

/** @} */
