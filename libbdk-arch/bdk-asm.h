/**
 * @file
 *
 * This is file defines ASM primitives for the executive.

 * <hr>$Revision: 53373 $<hr>
 *
 * @defgroup asm Assembly support
 * @{
 */

#define COP0_INDEX	$0,0	/* TLB read/write index */
#define COP0_RANDOM	$1,0	/* TLB random index */
#define COP0_ENTRYLO0	$2,0	/* TLB entryLo0 */
#define COP0_ENTRYLO1	$3,0	/* TLB entryLo1 */
#define COP0_CONTEXT	$4,0	/* Context */
#define COP0_USERLOCAL  $4,2    /* User local (Octeon 2) */
#define COP0_PAGEMASK	$5,0	/* TLB pagemask */
#define COP0_PAGEGRAIN	$5,1	/* TLB config for max page sizes */
#define COP0_WIRED	$6,0	/* TLB number of wired entries */
#define COP0_HWRENA	$7,0	/* rdhw instruction enable per register */
#define COP0_BADVADDR	$8,0	/* Bad virtual address */
#define COP0_COUNT	$9,0	/* Mips count register */
#define COP0_CVMCOUNT	$9,6	/* Cavium count register */
#define COP0_CVMCTL	$9,7	/* Cavium control */
#define COP0_ENTRYHI	$10,0	/* TLB entryHi */
#define COP0_COMPARE	$11,0	/* Mips compare register */
#define COP0_POWTHROTTLE $11,6	/* Power throttle register (Octeon 2) */
#define COP0_CVMMEMCTL	$11,7	/* Cavium memory control */
#define COP0_STATUS	$12,0	/* Mips status register */
#define COP0_INTCTL	$12,1	/* Useless (Vectored interrupts) */
#define COP0_SRSCTL	$12,2	/* Useless (Shadow registers) */
#define COP0_CAUSE	$13,0	/* Mips cause register */
#define COP0_EPC	$14,0	/* Exception program counter */
#define COP0_PRID	$15,0	/* Processor ID */
#define COP0_EBASE	$15,1	/* Exception base */
#define COP0_CONFIG	$16,0	/* Misc config options */
#define COP0_CONFIG1	$16,1	/* Misc config options */
#define COP0_CONFIG2	$16,2	/* Misc config options */
#define COP0_CONFIG3	$16,3	/* Misc config options */
#define COP0_CONFIG4    $16,4   /* Misc config options (Octeon 2) */
#define COP0_CVMMEMCTL2 $16,6   /* Cavium memory control (Octeon 3) */
#define COP0_WATCHLO0	$18,0	/* Address watch registers */
#define COP0_WATCHLO1	$18,1	/* Address watch registers */
#define COP0_WATCHHI0	$19,0	/* Address watch registers */
#define COP0_WATCHHI1	$19,1	/* Address watch registers */
#define COP0_XCONTEXT	$20,0	/* OS context */
#define COP0_MULTICOREDEBUG $22,0 /* Cavium debug */
#define COP0_DEBUG	$23,0	/* Debug status */
#define COP0_DEBUG2     $23,6   /* Debug2 Complex breakpoints (Octeon 2) */
#define COP0_DEPC	$24,0	/* Debug PC */
#define COP0_PERFCONTROL0 $25,0	/* Performance counter control */
#define COP0_PERFCONTROL1 $25,2	/* Performance counter control */
#define COP0_PERFVALUE0	$25,1	/* Performance counter */
#define COP0_PERFVALUE1	$25,3	/* Performance counter */
#define COP0_CACHEERRI	$27,0	/* I cache error status */
#define COP0_CACHEERRD	$27,1	/* D cache error status */
#define COP0_TAGLOI	$28,0	/* I cache tagLo */
#define COP0_TAGLOD	$28,2	/* D cache tagLo */
#define COP0_DATALOI	$28,1	/* I cache dataLo */
#define COP0_DATALOD	$28,3	/* D cahce dataLo */
#define COP0_TAGHI	$29,2	/* ? */
#define COP0_DATAHII	$29,1	/* ? */
#define COP0_DATAHID	$29,3	/* ? */
#define COP0_ERROREPC	$30,0	/* Error PC */
#define COP0_DESAVE	$31,0	/* Debug scratch area */
#define COP0_KSCRATCH1  $31,2   /* Scratch area (Octeon 2) */
#define COP0_KSCRATCH2  $31,3   /* Scratch area (Octeon 2) */
#define COP0_KSCRATCH3  $31,4   /* Scratch area (Octeon 2) */

/* This header file can be included from a .S file.  Keep non-preprocessor
   things under !__ASSEMBLER__.  */
#ifndef __ASSEMBLER__

/* turn the variable name into a string */
#define __BDK_TMP_STR(x) __BDK_TMP_STR2(x)
#define __BDK_TMP_STR2(x) #x
#define __BDK_VASTR(...) #__VA_ARGS__

/* other useful stuff */
#define BDK_SYNC        asm volatile ("sync"        : : :"memory")
#define BDK_SYNCW       asm volatile ("syncw"       : : :"memory")
#define BDK_SYNCIOBDMA  asm volatile ("synciobdma"  : : :"memory")
#define BDK_SYNCS       asm volatile ("syncs"       : : :"memory")
#define BDK_SYNCWS      asm volatile ("syncws"      : : :"memory")
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
#define BDK_ICACHE_INVALIDATE2 { asm volatile ("cache 0, 0($0)" : : ); } // flush stores, invalidate entire icache
#define BDK_DCACHE_INVALIDATE  { asm volatile ("cache 9, 0($0)" : : ); } // complete prefetches, invalidate entire dcache

#define BDK_CACHE(op, address, offset) asm volatile ("cache " __BDK_TMP_STR(op) ", " __BDK_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address) )
#define BDK_CACHE_LCKL2(address, offset) BDK_CACHE(31, address, offset) // fetch and lock the state.
#define BDK_CACHE_WBIL2(address, offset) BDK_CACHE(23, address, offset) // unlock the state.
#define BDK_CACHE_WBIL2I(address, offset) BDK_CACHE(3, address, offset) // invalidate the cache block and clear the USED bits for the block
#define BDK_CACHE_LTGL2I(address, offset) BDK_CACHE(7, address, offset) // load virtual tag and data for the L2 cache block into L2C_TAD0_TAG register
/* Zero a cache block */
#define BDK_ZCB(address) asm volatile ("zcb (%[rbase])" : : [rbase] "d" (address) )
/* Zero a cache block skipping L2 */
#define BDK_ZCBT(address) asm volatile ("zcbt (%[rbase])" : : [rbase] "d" (address) )

/* new instruction to make RC4 run faster */
#define BDK_BADDU(result, input1, input2) asm ("baddu %[rd],%[rs],%[rt]" : [rd] "=d" (result) : [rs] "d" (input1) , [rt] "d" (input2))

// misc v2 stuff
#define BDK_ROTR(result, input1, shiftconst) asm ("rotr %[rd],%[rs]," __BDK_TMP_STR(shiftconst) : [rd] "=d" (result) : [rs] "d" (input1))
#define BDK_ROTRV(result, input1, input2) asm ("rotrv %[rd],%[rt],%[rs]" : [rd] "=d" (result) : [rt] "d" (input1) , [rs] "d" (input2))
#define BDK_DROTR(result, input1, shiftconst) asm ("drotr %[rd],%[rs]," __BDK_TMP_STR(shiftconst) : [rd] "=d" (result) : [rs] "d" (input1))
#define BDK_DROTRV(result, input1, input2) asm ("drotrv %[rd],%[rt],%[rs]" : [rd] "=d" (result) : [rt] "d" (input1) , [rs] "d" (input2))
#define BDK_SEB(result, input1) asm ("seb %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
#define BDK_SEH(result, input1) asm ("seh %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
#define BDK_DSBH(result, input1) asm ("dsbh %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
#define BDK_DSHD(result, input1) asm ("dshd %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
#define BDK_WSBH(result, input1) asm ("wsbh %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))

// Endian swap
#define BDK_ES64(result, input) \
        do {\
        BDK_DSBH(result, input); \
        BDK_DSHD(result, result); \
        } while (0)
#define BDK_ES32(result, input) \
        do {\
        BDK_WSBH(result, input); \
        BDK_ROTR(result, result, 16); \
        } while (0)


/* extract and insert - NOTE that pos and len variables must be constants! */
/* the P variants take len rather than lenm1 */
/* the M1 variants take lenm1 rather than len */
#define BDK_EXTS(result,input,pos,lenm1) asm ("exts %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(lenm1) : [rt] "=d" (result) : [rs] "d" (input))
#define BDK_EXTSP(result,input,pos,len) BDK_EXTS(result,input,pos,(len)-1)

#define BDK_DEXT(result,input,pos,len) asm ("dext %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(len) : [rt] "=d" (result) : [rs] "d" (input))
#define BDK_DEXTM1(result,input,pos,lenm1) BDK_DEXT(result,input,pos,(lenm1)+1)

#define BDK_EXT(result,input,pos,len) asm ("ext %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(len) : [rt] "=d" (result) : [rs] "d" (input))
#define BDK_EXTM1(result,input,pos,lenm1) BDK_EXT(result,input,pos,(lenm1)+1)

// removed
// #define BDK_EXTU(result,input,pos,lenm1) asm ("extu %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(lenm1) : [rt] "=d" (result) : [rs] "d" (input))
// #define BDK_EXTUP(result,input,pos,len) BDK_EXTU(result,input,pos,(len)-1)

#define BDK_CINS(result,input,pos,lenm1) asm ("cins %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(lenm1) : [rt] "=d" (result) : [rs] "d" (input))
#define BDK_CINSP(result,input,pos,len) BDK_CINS(result,input,pos,(len)-1)

#define BDK_DINS(result,input,pos,len) asm ("dins %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(len): [rt] "=d" (result): [rs] "d" (input), "[rt]" (result))
#define BDK_DINSM1(result,input,pos,lenm1) BDK_DINS(result,input,pos,(lenm1)+1)
#define BDK_DINSC(result,pos,len) asm ("dins %[rt],$0," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(len): [rt] "=d" (result): "[rt]" (result))
#define BDK_DINSCM1(result,pos,lenm1) BDK_DINSC(result,pos,(lenm1)+1)

#define BDK_INS(result,input,pos,len) asm ("ins %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(len): [rt] "=d" (result): [rs] "d" (input), "[rt]" (result))
#define BDK_INSM1(result,input,pos,lenm1) BDK_INS(result,input,pos,(lenm1)+1)
#define BDK_INSC(result,pos,len) asm ("ins %[rt],$0," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(len): [rt] "=d" (result): "[rt]" (result))
#define BDK_INSCM1(result,pos,lenm1) BDK_INSC(result,pos,(lenm1)+1)

// removed
// #define BDK_INS0(result,input,pos,lenm1) asm("ins0 %[rt],%[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(lenm1): [rt] "=d" (result): [rs] "d" (input), "[rt]" (result))
// #define BDK_INS0P(result,input,pos,len) BDK_INS0(result,input,pos,(len)-1)
// #define BDK_INS0C(result,pos,lenm1) asm ("ins0 %[rt],$0," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(lenm1) : [rt] "=d" (result) : "[rt]" (result))
// #define BDK_INS0CP(result,pos,len) BDK_INS0C(result,pos,(len)-1)

#define BDK_CLZ(result, input) asm ("clz %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
#define BDK_DCLZ(result, input) asm ("dclz %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
#define BDK_CLO(result, input) asm ("clo %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
#define BDK_DCLO(result, input) asm ("dclo %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
#define BDK_POP(result, input) asm ("pop %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
#define BDK_DPOP(result, input) asm ("dpop %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))

#  define BDK_RDHWR(result, regstr) asm volatile ("rdhwr %[rt],$" __BDK_TMP_STR(regstr) : [rt] "=d" (result))
#  define BDK_RDHWRNV(result, regstr) asm ("rdhwr %[rt],$" __BDK_TMP_STR(regstr) : [rt] "=d" (result))

// some new cop0-like stuff
#define BDK_DI(result) asm volatile ("di %[rt]" : [rt] "=d" (result))
#define BDK_DI_NULL asm volatile ("di")
#define BDK_EI(result) asm volatile ("ei %[rt]" : [rt] "=d" (result))
#define BDK_EI_NULL asm volatile ("ei")
#define BDK_EHB asm volatile ("ehb")

/* mul stuff */
#define BDK_MTM0(m) asm volatile ("mtm0 %[rs]" : : [rs] "d" (m))
#define BDK_MTM1(m) asm volatile ("mtm1 %[rs]" : : [rs] "d" (m))
#define BDK_MTM2(m) asm volatile ("mtm2 %[rs]" : : [rs] "d" (m))
#define BDK_MTP0(p) asm volatile ("mtp0 %[rs]" : : [rs] "d" (p))
#define BDK_MTP1(p) asm volatile ("mtp1 %[rs]" : : [rs] "d" (p))
#define BDK_MTP2(p) asm volatile ("mtp2 %[rs]" : : [rs] "d" (p))
#define BDK_VMULU(dest,mpcand,accum) asm volatile ("vmulu %[rd],%[rs],%[rt]" : [rd] "=d" (dest) : [rs] "d" (mpcand), [rt] "d" (accum))
#define BDK_VMM0(dest,mpcand,accum) asm volatile ("vmm0 %[rd],%[rs],%[rt]" : [rd] "=d" (dest) : [rs] "d" (mpcand), [rt] "d" (accum))
#define BDK_V3MULU(dest,mpcand,accum) asm volatile ("v3mulu %[rd],%[rs],%[rt]" : [rd] "=d" (dest) : [rs] "d" (mpcand), [rt] "d" (accum))

/* branch stuff */
// these are hard to make work because the compiler does not realize that the
// instruction is a branch so may optimize away the label
// the labels to these next two macros must not include a ":" at the end
#define BDK_BBIT1(var, pos, label) asm volatile ("bbit1 %[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(label) : : [rs] "d" (var))
#define BDK_BBIT0(var, pos, label) asm volatile ("bbit0 %[rs]," __BDK_TMP_STR(pos) "," __BDK_TMP_STR(label) : : [rs] "d" (var))
// the label to this macro must include a ":" at the end
#define BDK_ASM_LABEL(label) label \
                             asm volatile (__BDK_TMP_STR(label) : : )

//
// Low-latency memory stuff
//
// set can be 0-1
#define BDK_MT_LLM_READ_ADDR(set,val)    asm volatile ("dmtc2 %[rt],0x0400+(8*(" __BDK_TMP_STR(set) "))" : : [rt] "d" (val))
#define BDK_MT_LLM_WRITE_ADDR_INTERNAL(set,val)   asm volatile ("dmtc2 %[rt],0x0401+(8*(" __BDK_TMP_STR(set) "))" : : [rt] "d" (val))
#define BDK_MT_LLM_READ64_ADDR(set,val)  asm volatile ("dmtc2 %[rt],0x0404+(8*(" __BDK_TMP_STR(set) "))" : : [rt] "d" (val))
#define BDK_MT_LLM_WRITE64_ADDR_INTERNAL(set,val) asm volatile ("dmtc2 %[rt],0x0405+(8*(" __BDK_TMP_STR(set) "))" : : [rt] "d" (val))
#define BDK_MT_LLM_DATA(set,val)         asm volatile ("dmtc2 %[rt],0x0402+(8*(" __BDK_TMP_STR(set) "))" : : [rt] "d" (val))
#define BDK_MF_LLM_DATA(set,val)         asm volatile ("dmfc2 %[rt],0x0402+(8*(" __BDK_TMP_STR(set) "))" : [rt] "=d" (val) : )


// load linked, store conditional
#define BDK_LL(dest, address, offset) asm volatile ("ll %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (dest) : [rbase] "d" (address) )
#define BDK_LLD(dest, address, offset) asm volatile ("lld %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (dest) : [rbase] "d" (address) )
#define BDK_SC(srcdest, address, offset) asm volatile ("sc %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
#define BDK_SCD(srcdest, address, offset) asm volatile ("scd %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )

// load/store word left/right
#define BDK_LWR(srcdest, address, offset) asm volatile ("lwr %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
#define BDK_LWL(srcdest, address, offset) asm volatile ("lwl %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
#define BDK_LDR(srcdest, address, offset) asm volatile ("ldr %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
#define BDK_LDL(srcdest, address, offset) asm volatile ("ldl %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )

#define BDK_SWR(src, address, offset) asm volatile ("swr %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
#define BDK_SWL(src, address, offset) asm volatile ("swl %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
#define BDK_SDR(src, address, offset) asm volatile ("sdr %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
#define BDK_SDL(src, address, offset) asm volatile ("sdl %[rt], " __BDK_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )



//
// Useful crypto ASM's
//

// CRC

#define BDK_MT_CRC_POLYNOMIAL(val)         asm volatile ("dmtc2 %[rt],0x4200" : : [rt] "d" (val))
#define BDK_MT_CRC_IV(val)                 asm volatile ("dmtc2 %[rt],0x0201" : : [rt] "d" (val))
#define BDK_MT_CRC_LEN(val)                asm volatile ("dmtc2 %[rt],0x1202" : : [rt] "d" (val))
#define BDK_MT_CRC_BYTE(val)               asm volatile ("dmtc2 %[rt],0x0204" : : [rt] "d" (val))
#define BDK_MT_CRC_HALF(val)               asm volatile ("dmtc2 %[rt],0x0205" : : [rt] "d" (val))
#define BDK_MT_CRC_WORD(val)               asm volatile ("dmtc2 %[rt],0x0206" : : [rt] "d" (val))
#define BDK_MT_CRC_DWORD(val)              asm volatile ("dmtc2 %[rt],0x1207" : : [rt] "d" (val))
#define BDK_MT_CRC_VAR(val)                asm volatile ("dmtc2 %[rt],0x1208" : : [rt] "d" (val))
#define BDK_MT_CRC_POLYNOMIAL_REFLECT(val) asm volatile ("dmtc2 %[rt],0x4210" : : [rt] "d" (val))
#define BDK_MT_CRC_IV_REFLECT(val)         asm volatile ("dmtc2 %[rt],0x0211" : : [rt] "d" (val))
#define BDK_MT_CRC_BYTE_REFLECT(val)       asm volatile ("dmtc2 %[rt],0x0214" : : [rt] "d" (val))
#define BDK_MT_CRC_HALF_REFLECT(val)       asm volatile ("dmtc2 %[rt],0x0215" : : [rt] "d" (val))
#define BDK_MT_CRC_WORD_REFLECT(val)       asm volatile ("dmtc2 %[rt],0x0216" : : [rt] "d" (val))
#define BDK_MT_CRC_DWORD_REFLECT(val)      asm volatile ("dmtc2 %[rt],0x1217" : : [rt] "d" (val))
#define BDK_MT_CRC_VAR_REFLECT(val)        asm volatile ("dmtc2 %[rt],0x1218" : : [rt] "d" (val))

#define BDK_MF_CRC_POLYNOMIAL(val)         asm volatile ("dmfc2 %[rt],0x0200" : [rt] "=d" (val) : )
#define BDK_MF_CRC_IV(val)                 asm volatile ("dmfc2 %[rt],0x0201" : [rt] "=d" (val) : )
#define BDK_MF_CRC_IV_REFLECT(val)         asm volatile ("dmfc2 %[rt],0x0203" : [rt] "=d" (val) : )
#define BDK_MF_CRC_LEN(val)                asm volatile ("dmfc2 %[rt],0x0202" : [rt] "=d" (val) : )

// MD5 and SHA-1

// pos can be 0-6
#define BDK_MT_HSH_DAT(val,pos)    asm volatile ("dmtc2 %[rt],0x0040+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
#define BDK_MT_HSH_DATZ(pos)       asm volatile ("dmtc2    $0,0x0040+" __BDK_TMP_STR(pos) :                 :               )
// pos can be 0-14
#define BDK_MT_HSH_DATW(val,pos)   asm volatile ("dmtc2 %[rt],0x0240+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
#define BDK_MT_HSH_DATWZ(pos)      asm volatile ("dmtc2    $0,0x0240+" __BDK_TMP_STR(pos) :                 :               )
#define BDK_MT_HSH_STARTMD5(val)   asm volatile ("dmtc2 %[rt],0x4047"                   :                 : [rt] "d" (val))
#define BDK_MT_HSH_STARTSHA(val)   asm volatile ("dmtc2 %[rt],0x4057"                   :                 : [rt] "d" (val))
#define BDK_MT_HSH_STARTSHA256(val)   asm volatile ("dmtc2 %[rt],0x404f"                   :                 : [rt] "d" (val))
#define BDK_MT_HSH_STARTSHA512(val)   asm volatile ("dmtc2 %[rt],0x424f"                   :                 : [rt] "d" (val))
// pos can be 0-3
#define BDK_MT_HSH_IV(val,pos)     asm volatile ("dmtc2 %[rt],0x0048+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
// pos can be 0-7
#define BDK_MT_HSH_IVW(val,pos)     asm volatile ("dmtc2 %[rt],0x0250+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))

// pos can be 0-6
#define BDK_MF_HSH_DAT(val,pos)    asm volatile ("dmfc2 %[rt],0x0040+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-14
#define BDK_MF_HSH_DATW(val,pos)   asm volatile ("dmfc2 %[rt],0x0240+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-3
#define BDK_MF_HSH_IV(val,pos)     asm volatile ("dmfc2 %[rt],0x0048+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-7
#define BDK_MF_HSH_IVW(val,pos)     asm volatile ("dmfc2 %[rt],0x0250+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )

// 3DES

// pos can be 0-2
#define BDK_MT_3DES_KEY(val,pos)   asm volatile ("dmtc2 %[rt],0x0080+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
#define BDK_MT_3DES_IV(val)        asm volatile ("dmtc2 %[rt],0x0084"                   :                 : [rt] "d" (val))
#define BDK_MT_3DES_ENC_CBC(val)   asm volatile ("dmtc2 %[rt],0x4088"                   :                 : [rt] "d" (val))
#define BDK_MT_3DES_ENC(val)       asm volatile ("dmtc2 %[rt],0x408a"                   :                 : [rt] "d" (val))
#define BDK_MT_3DES_DEC_CBC(val)   asm volatile ("dmtc2 %[rt],0x408c"                   :                 : [rt] "d" (val))
#define BDK_MT_3DES_DEC(val)       asm volatile ("dmtc2 %[rt],0x408e"                   :                 : [rt] "d" (val))
#define BDK_MT_3DES_RESULT(val)    asm volatile ("dmtc2 %[rt],0x0098"                   :                 : [rt] "d" (val))

// pos can be 0-2
#define BDK_MF_3DES_KEY(val,pos)   asm volatile ("dmfc2 %[rt],0x0080+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
#define BDK_MF_3DES_IV(val)        asm volatile ("dmfc2 %[rt],0x0084"                   : [rt] "=d" (val) :               )
#define BDK_MF_3DES_RESULT(val)    asm volatile ("dmfc2 %[rt],0x0088"                   : [rt] "=d" (val) :               )

// KASUMI

// pos can be 0-1
#define BDK_MT_KAS_KEY(val,pos)    BDK_MT_3DES_KEY(val,pos)
#define BDK_MT_KAS_ENC_CBC(val)    asm volatile ("dmtc2 %[rt],0x4089"                   :                 : [rt] "d" (val))
#define BDK_MT_KAS_ENC(val)        asm volatile ("dmtc2 %[rt],0x408b"                   :                 : [rt] "d" (val))
#define BDK_MT_KAS_RESULT(val)     BDK_MT_3DES_RESULT(val)

// pos can be 0-1
#define BDK_MF_KAS_KEY(val,pos)    BDK_MF_3DES_KEY(val,pos)
#define BDK_MF_KAS_RESULT(val)     BDK_MF_3DES_RESULT(val)

// AES

#define BDK_MT_AES_ENC_CBC0(val)   asm volatile ("dmtc2 %[rt],0x0108"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_ENC_CBC1(val)   asm volatile ("dmtc2 %[rt],0x3109"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_ENC0(val)       asm volatile ("dmtc2 %[rt],0x010a"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_ENC1(val)       asm volatile ("dmtc2 %[rt],0x310b"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_DEC_CBC0(val)   asm volatile ("dmtc2 %[rt],0x010c"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_DEC_CBC1(val)   asm volatile ("dmtc2 %[rt],0x310d"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_DEC0(val)       asm volatile ("dmtc2 %[rt],0x010e"                   :                 : [rt] "d" (val))
#define BDK_MT_AES_DEC1(val)       asm volatile ("dmtc2 %[rt],0x310f"                   :                 : [rt] "d" (val))
// pos can be 0-3
#define BDK_MT_AES_KEY(val,pos)    asm volatile ("dmtc2 %[rt],0x0104+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
// pos can be 0-1
#define BDK_MT_AES_IV(val,pos)     asm volatile ("dmtc2 %[rt],0x0102+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
#define BDK_MT_AES_KEYLENGTH(val)  asm volatile ("dmtc2 %[rt],0x0110"                   :                 : [rt] "d" (val)) // write the keylen
// pos can be 0-1
#define BDK_MT_AES_RESULT(val,pos) asm volatile ("dmtc2 %[rt],0x0100+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))

// pos can be 0-1
#define BDK_MF_AES_RESULT(val,pos) asm volatile ("dmfc2 %[rt],0x0100+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-1
#define BDK_MF_AES_IV(val,pos)     asm volatile ("dmfc2 %[rt],0x0102+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-3
#define BDK_MF_AES_KEY(val,pos)    asm volatile ("dmfc2 %[rt],0x0104+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
#define BDK_MF_AES_KEYLENGTH(val)  asm volatile ("dmfc2 %[rt],0x0110"                   : [rt] "=d" (val) :               ) // read the keylen
#define BDK_MF_AES_DAT0(val)       asm volatile ("dmfc2 %[rt],0x0111"                   : [rt] "=d" (val) :               ) // first piece of input data

// GFM

// pos can be 0-1
#define BDK_MF_GFM_MUL(val,pos)             asm volatile ("dmfc2 %[rt],0x0258+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
#define BDK_MF_GFM_POLY(val)                asm volatile ("dmfc2 %[rt],0x025e"                    : [rt] "=d" (val) :               )
// pos can be 0-1
#define BDK_MF_GFM_RESINP(val,pos)          asm volatile ("dmfc2 %[rt],0x025a+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-1
#define BDK_MF_GFM_RESINP_REFLECT(val,pos)  asm volatile ("dmfc2 %[rt],0x005a+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )

// pos can be 0-1
#define BDK_MT_GFM_MUL(val,pos)             asm volatile ("dmtc2 %[rt],0x0258+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
#define BDK_MT_GFM_POLY(val)                asm volatile ("dmtc2 %[rt],0x025e"                    :                 : [rt] "d" (val))
// pos can be 0-1
#define BDK_MT_GFM_RESINP(val,pos)          asm volatile ("dmtc2 %[rt],0x025a+" __BDK_TMP_STR(pos) :                 : [rt] "d" (val))
#define BDK_MT_GFM_XOR0(val)                asm volatile ("dmtc2 %[rt],0x025c"                    :                 : [rt] "d" (val))
#define BDK_MT_GFM_XORMUL1(val)             asm volatile ("dmtc2 %[rt],0x425d"                    :                 : [rt] "d" (val))
// pos can be 0-1
#define BDK_MT_GFM_MUL_REFLECT(val,pos)     asm volatile ("dmtc2 %[rt],0x0058+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
#define BDK_MT_GFM_XOR0_REFLECT(val)        asm volatile ("dmtc2 %[rt],0x005c"                    :                 : [rt] "d" (val))
#define BDK_MT_GFM_XORMUL1_REFLECT(val)     asm volatile ("dmtc2 %[rt],0x405d"                    :                 : [rt] "d" (val))

// SNOW 3G

// pos can be 0-7
#define BDK_MF_SNOW3G_LFSR(val,pos)    asm volatile ("dmfc2 %[rt],0x0240+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-2
#define BDK_MF_SNOW3G_FSM(val,pos)     asm volatile ("dmfc2 %[rt],0x0251+" __BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
#define BDK_MF_SNOW3G_RESULT(val)      asm volatile ("dmfc2 %[rt],0x0250"                    : [rt] "=d" (val) :               )

// pos can be 0-7
#define BDK_MT_SNOW3G_LFSR(val,pos)    asm volatile ("dmtc2 %[rt],0x0240+" __BDK_TMP_STR(pos) : : [rt] "d" (val))
// pos can be 0-2
#define BDK_MT_SNOW3G_FSM(val,pos)     asm volatile ("dmtc2 %[rt],0x0251+" __BDK_TMP_STR(pos) : : [rt] "d" (val))
#define BDK_MT_SNOW3G_RESULT(val)      asm volatile ("dmtc2 %[rt],0x0250"                    : : [rt] "d" (val))
#define BDK_MT_SNOW3G_START(val)       asm volatile ("dmtc2 %[rt],0x404d"                    : : [rt] "d" (val))
#define BDK_MT_SNOW3G_MORE(val)        asm volatile ("dmtc2 %[rt],0x404e"                    : : [rt] "d" (val))

// SMS4

// pos can be 0-1
#define BDK_MF_SMS4_IV(val,pos)	asm volatile ("dmfc2 %[rt],0x0102+"__BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-1
#define BDK_MF_SMS4_KEY(val,pos)	asm volatile ("dmfc2 %[rt],0x0104+"__BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
// pos can be 0-1
#define BDK_MF_SMS4_RESINP(val,pos)	asm volatile ("dmfc2 %[rt],0x0100+"__BDK_TMP_STR(pos) : [rt] "=d" (val) :               )
#define BDK_MT_SMS4_DEC_CBC0(val)	asm volatile ("dmtc2 %[rt],0x010c"                   : : [rt] "d" (val))
#define BDK_MT_SMS4_DEC_CBC1(val)	asm volatile ("dmtc2 %[rt],0x311d"      : : [rt] "d" (val))
#define BDK_MT_SMS4_DEC0(val)		asm volatile ("dmtc2 %[rt],0x010e"      : : [rt] "d" (val))
#define BDK_MT_SMS4_DEC1(val)		asm volatile ("dmtc2 %[rt],0x311f"      : : [rt] "d" (val))
#define BDK_MT_SMS4_ENC_CBC0(val)	asm volatile ("dmtc2 %[rt],0x0108"      : : [rt] "d" (val))
#define BDK_MT_SMS4_ENC_CBC1(val)	asm volatile ("dmtc2 %[rt],0x3119"      : : [rt] "d" (val))
#define BDK_MT_SMS4_ENC0(val)		asm volatile ("dmtc2 %[rt],0x010a"      : : [rt] "d" (val))
#define BDK_MT_SMS4_ENC1(val)		asm volatile ("dmtc2 %[rt],0x311b"      : : [rt] "d" (val))
// pos can be 0-1
#define BDK_MT_SMS4_IV(val,pos)	asm volatile ("dmtc2 %[rt],0x0102+"__BDK_TMP_STR(pos) : : [rt] "d" (val))
// pos can be 0-1
#define BDK_MT_SMS4_KEY(val,pos)	asm volatile ("dmtc2 %[rt],0x0104+"__BDK_TMP_STR(pos) : : [rt] "d" (val))
// pos can be 0-1
#define BDK_MT_SMS4_RESINP(val,pos)	asm volatile ("dmtc2 %[rt],0x0100+"__BDK_TMP_STR(pos) : : [rt] "d" (val))

/* check_ordering stuff */
#define BDK_MF_CHORD(dest)         BDK_RDHWR(dest, 30)

#define BDK_MF_CYCLE(dest)         BDK_RDHWR(dest, 31) /* reads the current (64-bit) CvmCount value */

#define BDK_MT_CYCLE(src)         asm volatile ("dmtc0 %[rt],$9,6" :: [rt] "d" (src))

#define BDK_MF_COP0(val, cop0)           asm volatile ("dmfc0 %[rt]," __BDK_VASTR(cop0) : [rt] "=d" (val));
#define BDK_MT_COP0(val, cop0)           asm volatile ("dmtc0 %[rt]," __BDK_VASTR(cop0) : : [rt] "d" (val));

/* Macros for TLB */
#define BDK_TLBWI                       asm volatile ("tlbwi" : : )
#define BDK_TLBWR                       asm volatile ("tlbwr" : : )
#define BDK_TLBR                        asm volatile ("tlbr" : : )
#define BDK_TLBP                        asm volatile ("tlbp" : : )

/* assembler macros to guarantee byte loads/stores are used */
/* for an unaligned 16-bit access (these use AT register) */
/* we need the hidden argument (__a) so that GCC gets the dependencies right */
#define BDK_LOADUNA_INT16(result, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("ulh %[rdest], " __BDK_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : [rbase] "d" (__a), "m"(__a[offset]), "m"(__a[offset + 1])); }
#define BDK_LOADUNA_UINT16(result, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("ulhu %[rdest], " __BDK_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : [rbase] "d" (__a), "m"(__a[offset + 0]), "m"(__a[offset + 1])); }
#define BDK_STOREUNA_INT16(data, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("ush %[rsrc], " __BDK_TMP_STR(offset) "(%[rbase])" : "=m"(__a[offset + 0]), "=m"(__a[offset + 1]): [rsrc] "d" (data), [rbase] "d" (__a)); }

#define BDK_LOADUNA_INT32(result, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("ulw %[rdest], " __BDK_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : \
	       [rbase] "d" (__a), "m"(__a[offset + 0]), "m"(__a[offset + 1]), "m"(__a[offset + 2]), "m"(__a[offset + 3])); }
#define BDK_STOREUNA_INT32(data, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("usw %[rsrc], " __BDK_TMP_STR(offset) "(%[rbase])" : \
	       "=m"(__a[offset + 0]), "=m"(__a[offset + 1]), "=m"(__a[offset + 2]), "=m"(__a[offset + 3]) : \
	       [rsrc] "d" (data), [rbase] "d" (__a)); }

#define BDK_LOADUNA_INT64(result, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("uld %[rdest], " __BDK_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : \
	       [rbase] "d" (__a), "m"(__a[offset + 0]), "m"(__a[offset + 1]), "m"(__a[offset + 2]), "m"(__a[offset + 3]), \
	       "m"(__a[offset + 4]), "m"(__a[offset + 5]), "m"(__a[offset + 6]), "m"(__a[offset + 7])); }
#define BDK_STOREUNA_INT64(data, address, offset) \
	{ char *__a = (char *)(address); \
	  asm ("usd %[rsrc], " __BDK_TMP_STR(offset) "(%[rbase])" : \
	       "=m"(__a[offset + 0]), "=m"(__a[offset + 1]), "=m"(__a[offset + 2]), "=m"(__a[offset + 3]), \
	       "=m"(__a[offset + 4]), "=m"(__a[offset + 5]), "=m"(__a[offset + 6]), "=m"(__a[offset + 7]) : \
	       [rsrc] "d" (data), [rbase] "d" (__a)); }

#endif	/* __ASSEMBLER__ */

/** @} */
