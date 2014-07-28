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
#define BDK_SYNC        asm volatile ("sync"        : : :"memory")
#define BDK_SYNCW       asm volatile ("syncw"       : : :"memory")
#define BDK_ASM_PAUSE   asm volatile ("pause"       : : :"memory")

#define BDK_SYNCI(address, offset) asm volatile ("synci " __BDK_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address) )

// normal prefetches that use the pref instruction
#define BDK_PREFETCH_PREFX(X, address, offset) asm volatile ("pref %[type], %[off](%[rbase])" : : [rbase] "d" (address), [off] "I" (offset), [type] "n" (X))
// a normal prefetch
#define BDK_PREFETCH(address, offset) BDK_PREFETCH_PREFX(0, address, offset)
// prefetch into L1, do not put the block in the L2
#define BDK_PREFETCH_NOTL2(address, offset) BDK_PREFETCH_PREFX(4, address, offset)
// prefetch into L2, do not put the block in the L1
#define BDK_PREFETCH_L2(address, offset) BDK_PREFETCH_PREFX(28, address, offset)
// BDK_PREPARE_FOR_STORE makes each byte of the block unpredictable (actually old value or zero) until
// that byte is stored to (by this or another processor. Note that the value of each byte is not only
// unpredictable, but may also change again - up until the point when one of the cores stores to the
// byte.
#define BDK_PREPARE_FOR_STORE(address, offset) BDK_PREFETCH_PREFX(30, address, offset)
// This is a command headed to the L2 controller to tell it to clear its dirty bit for a
// block. Basically, SW is telling HW that the current version of the block will not be
// used.
#define BDK_DONT_WRITE_BACK(address, offset) BDK_PREFETCH_PREFX(29, address, offset)

#define BDK_ICACHE_INVALIDATE  { asm volatile ("synci 0($0)" : : ); }    // flush stores, invalidate entire icache
#define BDK_DCACHE_INVALIDATE  { asm volatile ("cache 9, 0($0)" : : ); } // complete prefetches, invalidate entire dcache

#endif	/* __ASSEMBLER__ */

/** @} */
