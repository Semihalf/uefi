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

/* other useful stuff */
#define BDK_MB          asm volatile ("dmb sy"      : : :"memory")
#define BDK_WMB         asm volatile ("dmb st"      : : :"memory")
#define BDK_WFE         asm volatile ("wfe"         : : :"memory")

// normal prefetches that use the pref instruction
#define BDK_PREFETCH_PREFX(X, address, offset) asm volatile ("pref %[type], %[off](%[rbase])" : : [rbase] "d" (address), [off] "I" (offset), [type] "n" (X))
// a normal prefetch
#define BDK_PREFETCH(address, offset) BDK_PREFETCH_PREFX(0, address, offset)
#define BDK_ICACHE_INVALIDATE  { asm volatile ("ic iallu" : : ); }    // invalidate entire icache
#define BDK_DCACHE_INVALIDATE  { asm volatile ("dc civac,xzr" : : ); } // invalidate entire dcache

#endif	/* __ASSEMBLER__ */

/** @} */
