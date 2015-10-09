#ifndef __BDK_CSRS_DAB_PMU_H__
#define __BDK_CSRS_DAB_PMU_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2015  Cavium Inc. (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Inc. nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium DAB_PMU.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration pmu_perf_e
 *
 * Performance Counter Event Enumeration
 * Enumerates the events that may be counted.  See PMU()_PMEVTYPER()_EL0[EVTCOUNT].
 * Internal:
 * <pre>
 *    0x0000 to 0x003F    Common architectural and microarchitectural events
 *       0x0020 to 0x03F      ARM house style events
 *       0x0040 to 0x04F      ARM Recommended, implementation defined events (Aka ARM House
 * Style)
 *    0x0040 to 0x00BF    ARM recommended common architectural and microarchitectural events.
 * IMPLEMENTATION DEFINED
 *    0x00C0 to 0x3FFF    IMPLEMENTATION DEFINED
 *      0x0180 to 0x01B7     Cavium Misc Counters
 *      0x01B8 to 0x01FF     Cavium - special instructions and events
 *      0x0300 to 0x03FF     Cavium - can be secure mode only
 *    0x4000 to 0x403F    Common architectural and microarchitectural events (PMCEID0_EL0[63:32],
 * PMCEID0_EL1[63:32])
 *    0x4040 to 0x40BF    ARM recommended common architectural and microarchitectural events.
 * IMPLEMENTATION DEFINED
 *    0x40C0 to 0x7FFF    IMPLEMENTATION DEFINED
 *    0x8000 to 0x80BF    Reserved
 *    0x80C0 to 0xBFFF    IMPLEMENTATION DEFINED
 *    0xC000 to 0xC0BF    Reserved
 *    0xC0C0 to 0xFFFF    IMPLEMENTATION DEFINED
 * </pre>
 */
#define BDK_PMU_PERF_E_ASE_SPEC (0x74) /**< Number of SIMD, speculatively executed (see v8 ARM ARM for definition of this class). */
#define BDK_PMU_PERF_E_ASID_OVF (0x300) /**< Number of times ASIDMap overflowed. */
#define BDK_PMU_PERF_E_BADD (0xe0) /**< Number of CMI address bus cycles used to either the L2 or IO. */
#define BDK_PMU_PERF_E_BADDL2 (0xe1) /**< Number of CMI address bus cycles used for destined for the L2/CCPI. */
#define BDK_PMU_PERF_E_BFILL (0xe2) /**< Number of fill bus cycles used from either IO or L2/CCPI to a core. */
#define BDK_PMU_PERF_E_BR (0xc7) /**< Internal:
                                       redundant with ARM counters
                                       Number of branches retired. Specifically bcond, br, blr, ret.
                                       Very similiar to BR_RETIRED but doesn't include eret.  Depracated - do not use,
                                       may be removed in future chips. */
#define BDK_PMU_PERF_E_BRMIS (0xc8) /**< Internal:
                                       Number of branches mispredicted. Specifically bcond, br, blr, ret.
                                       redundant with BR_MIS_PRED except BR_MIS_PRED also includes exception returns.
                                       Depracated. */
#define BDK_PMU_PERF_E_BR_FOLDED (0xc5) /**< Number of branch instructions that were folded and committed. */
#define BDK_PMU_PERF_E_BR_FOLDED_RAW (0xc6) /**< Number of branch instructions that were folded and issued but not necessarily committed. */
#define BDK_PMU_PERF_E_BR_FOLDED_SPEC_CN81XX (0xc6) /**< Number of branch instructions that were folded and issued but not necessarily committed. */
#define BDK_PMU_PERF_E_BR_FOLDED_SPEC_CN88XX (0xc6) /**< Number of branch instructions that were folded and issued but not necessarily committed.
                                       Name changed in pass2.0 from
                                       from BR_FOLDED_RAW */
#define BDK_PMU_PERF_E_BR_FOLDED_SPEC_CN83XX (0xc6) /**< Number of branch instructions that were folded and issued but not necessarily committed. */
#define BDK_PMU_PERF_E_BR_IMMED_RETIRED (0xd) /**< Number of br immediate instructions retired.
                                       Specifically counts -
                                         B, B.cond, BL, CBNZ, CBZ, TBNZ, TBZ */
#define BDK_PMU_PERF_E_BR_IMMED_SPEC (0x78) /**< Number of branch with immediate. */
#define BDK_PMU_PERF_E_BR_INDIRECT_SPEC (0x7a) /**< Number of indirect branches. */
#define BDK_PMU_PERF_E_BR_MIS_PRED (0x10) /**< Number of mispredicted or not predicted branch speculatively executed. */
#define BDK_PMU_PERF_E_BR_MIS_PRED_RETIRED (0x22) /**< Number of branches counted by BR_RETIRED that were not correctly predicted (and therefore
                                       have an associated performance loss). */
#define BDK_PMU_PERF_E_BR_PRED (0x12) /**< Number of predictable branches speculatively executed. */
#define BDK_PMU_PERF_E_BR_RETIRED (0x21) /**< Counts number of branches retired that are one of conditional, unconditional,
                                       branch and link, return and eret. */
#define BDK_PMU_PERF_E_BR_RETURN_RETIRED (0xe) /**< Number of instructions procedure return instructions retired. */
#define BDK_PMU_PERF_E_BR_RETURN_SPEC (0x79) /**< Number of branch returns. */
#define BDK_PMU_PERF_E_BUS_ACCESS (0x19) /**< Internal:
                                       Number of bus accesses outside the last cache level for which counters exist. */
#define BDK_PMU_PERF_E_BUS_ACCESS_LD (0x60) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_BUS_ACCESS_NORMAL (0x64) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_BUS_ACCESS_NOT_SHARED (0x63) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_BUS_ACCESS_PERIPH (0x65) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_BUS_ACCESS_SHARED (0x62) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_BUS_ACCESS_ST (0x61) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_BUS_CYCLES (0x1d) /**< Internal:
                                       Cycles CMB buses from this core are clocking.  Better to have cavium specifc
                                       counters for
                                       each CMB bus. */
#define BDK_PMU_PERF_E_CDMISS (0xe6) /**< Cycles that we don't issue an instruction because the memory system is busy.
                                       This include dcache miss cycles, but also
                                       includes cycles due to uTLB misses, Page Table Walks and writebuffer full stalls.
                                       In addition, there is a fixed overhead for recovering from each dcache miss.
                                       
                                       The following formula may be used to calculate the effective memory latency:
                                       
                                       _ latency = [(CDMISS - L1D_TLB_REFILL * 12) - WBUFFL + (L1D_CACHE_REFILL *
                                       8)]/L1D_CACHE_REFILL */
#define BDK_PMU_PERF_E_CHAIN (0x1e) /**< For odd-numbered counters, increments the count by one for each overflow of the preceding
                                       even-numbered counter. For even-numbered counters there is no increment. */
#define BDK_PMU_PERF_E_CID_WRITE_RETIRED (0xb) /**< Number of instructions completed that write to CONTEXTIDR. */
#define BDK_PMU_PERF_E_CIMISS (0xd8) /**< Cycles idle due to imiss. However, if an iprefetch is already active, the machine must
                                       wait for the
                                       iprefetch to return before starting the imiss.  These lost cycles are not counted. */
#define BDK_PMU_PERF_E_CPU_CYCLES (0x11) /**< CPU Cycles clocked. */
#define BDK_PMU_PERF_E_CRYPTO_SPEC (0x77) /**< Number of crypto instructions (excpet PMUJLL and VMULL) speculatively
                                       executed. see v8 ARM ARM for definition of this class. */
#define BDK_PMU_PERF_E_DC_CIVAC (0x1be) /**< Number of data cache clean and invalidate by virtual address to point of coherency. */
#define BDK_PMU_PERF_E_DC_CVAC (0x1bf) /**< Number of data cache clean by virtual address to point of coherency. */
#define BDK_PMU_PERF_E_DC_CVAU (0x1c0) /**< Number of data cache clean by virtual address to point of unification. */
#define BDK_PMU_PERF_E_DC_ISW_L1 (0x1c1) /**< Number of data cache invalidate by set/way to L1. */
#define BDK_PMU_PERF_E_DC_ISW_L2 (0x1c2) /**< Number of data cache invalidate by set/way to L2. */
#define BDK_PMU_PERF_E_DC_IVAC (0x1c3) /**< Number of data cache invalidate by virtual address to point of coherency. */
#define BDK_PMU_PERF_E_DDIDS (0xe3) /**< Number of DStream DIDs created. */
#define BDK_PMU_PERF_E_DIDNA (0xe5) /**< Number of cycles that no DIDs were available. */
#define BDK_PMU_PERF_E_DIDNT_DUAL_ISSUE_REASONX(a) (0x4e00 + (a)) /**< Internal:
                                       Event for every reason code why the second entry of the queue didn't issue(0 means we dual
                                       issued)
                                       Event for every reason code why the head of the queue didn't issue(0 means we issued)
                                       0 = issued */
#define BDK_PMU_PERF_E_DIDNT_ISSUE_REASONX(a) (0x4d00 + (a)) /**< Internal:
                                       Event for every reason code why the head of the queue didn't issue(0 means we issued)
                                       0 = issued */
#define BDK_PMU_PERF_E_DISSUE (0xc4) /**< Cycles two instructions were issued. */
#define BDK_PMU_PERF_E_DMB_ISH (0x1f2) /**< Number of DMB_ISH instructions retired. */
#define BDK_PMU_PERF_E_DMB_NSH (0x1f1) /**< Number of DMB_NSH instructions retired. */
#define BDK_PMU_PERF_E_DMB_OSH (0x1f3) /**< Number of DMB_OSH instructions retired. */
#define BDK_PMU_PERF_E_DMB_SPEC (0x7e) /**< Number of dsb instruction. */
#define BDK_PMU_PERF_E_DMB_SY (0x1f4) /**< Number of DMB_SY instructions retired. */
#define BDK_PMU_PERF_E_DP_SPEC (0x73) /**< Number of data processing instructions; speculatively executed (see ARM ARM v8
                                       for definition of this instruction class.) */
#define BDK_PMU_PERF_E_DSB_ISH (0x1f6) /**< Number of DSB_ISH instructions retired. */
#define BDK_PMU_PERF_E_DSB_NSH (0x1f5) /**< Number of DSB_NSH instructions retired. */
#define BDK_PMU_PERF_E_DSB_OSH (0x1f7) /**< Number of DSB_OSH instructions retired. */
#define BDK_PMU_PERF_E_DSB_SPEC (0x7d) /**< Number of dsb instructions. */
#define BDK_PMU_PERF_E_DSB_SY (0x1f8) /**< Number of DSB_SY instructions retired. */
#define BDK_PMU_PERF_E_ERET_MIS (0xe7) /**< Number of committed eret's that mispredict */
#define BDK_PMU_PERF_E_EXC_DABORT (0x84) /**< Number of data aborts or serrors taken to the default EL (i.e. locally taken). */
#define BDK_PMU_PERF_E_EXC_FIQ (0x87) /**< Number of fiq exceptions taken to the default EL (i.e. locally taken).   Includes FIRQ. */
#define BDK_PMU_PERF_E_EXC_HVC (0x8a) /**< Number of hypervisor call exceptions taken locally. The counter counts for both
                                       Hypervisor Call exception taken locally in the hypervisor and as exceptions from
                                       non-secure EL1. Includes all exceptions with EC=0x16. */
#define BDK_PMU_PERF_E_EXC_IRQ (0x86) /**< Number of irq exceptions taken to the default EL (i.e. locally taken).   Includes VIRQ. */
#define BDK_PMU_PERF_E_EXC_PABORT (0x83) /**< Number of instruction aborts taken to the default EL (i.e. locally taken). Includes all
                                       all exceptions with EC=0x20,0x21. */
#define BDK_PMU_PERF_E_EXC_RETURN (0xa) /**< Number of instruction architecturally executed, condition code check pass, exception return. */
#define BDK_PMU_PERF_E_EXC_SMC (0x88) /**< Number of system monitgor call exceptions taken locally.   Does not count SMC exceptions
                                       that are trapped to the hypervisor. Includes all exceptions with EC=0x17. */
#define BDK_PMU_PERF_E_EXC_SVC (0x82) /**< Number of SVC exceptions taken to the default EL (i.e. locally taken). Includes all
                                       exceptions with EC=0x15. */
#define BDK_PMU_PERF_E_EXC_TAKEN (9) /**< Number of exceptions taken. */
#define BDK_PMU_PERF_E_EXC_TRAP_DABORT (0x8c) /**< Number of data aborts not taken locally (i.e. not taken to the default EL). */
#define BDK_PMU_PERF_E_EXC_TRAP_FIQ (0x8f) /**< Number of fiq exceptions not taken locally exceptions (i.e. not taken to the default EL). */
#define BDK_PMU_PERF_E_EXC_TRAP_IRQ (0x8e) /**< Number of irq exceptions not taken locally exceptions (i.e. not taken to the default EL). */
#define BDK_PMU_PERF_E_EXC_TRAP_OTHER (0x8d) /**< Number of not taken locally exceptions (i.e. not taken to the default EL) that are not
                                       covered by other counters counting non locally taken exceptions. Includes all
                                       exceptions to EL2 or EL3 from a lower level. */
#define BDK_PMU_PERF_E_EXC_TRAP_PABORT (0x8b) /**< Number of instruction aborts not taken locally (i.e. not taken to the default EL). */
#define BDK_PMU_PERF_E_EXC_UNDEF (0x81) /**< Number of undefined instruction synchronous exceptions taken to the default EL (i.e.
                                       locally taken). Includes all exceptions with EC=0x0 to EL1 or same EL. */
#define BDK_PMU_PERF_E_FLEX_EX_DEL0 (0x180) /**< Number of committed instructions executed with 0 stage pipeline delay. */
#define BDK_PMU_PERF_E_FLEX_EX_DEL1 (0x181) /**< Number of committed instructions executed with 1 stage pipeline delay. */
#define BDK_PMU_PERF_E_FLEX_EX_DEL2 (0x182) /**< Number of committed instructions issued with 2 stages pipeline delay. */
#define BDK_PMU_PERF_E_FLEX_EX_DEL3 (0x183) /**< Number of committed instructions issued with 3 stages pipeline delay. */
#define BDK_PMU_PERF_E_F_MASK_CYC (0x302) /**< Number of cycles during which FIQ is masked */
#define BDK_PMU_PERF_E_GLBL_SYNC (0x1b8) /**< Number of Global Syncs broadcast from this core. */
#define BDK_PMU_PERF_E_IC_IALLUX (0x1ba) /**< Number of IC IALLU and IC IALLUIS executed. */
#define BDK_PMU_PERF_E_IC_IALLU_RCVD (0x1bc) /**< Number of IC IALLUIS received. */
#define BDK_PMU_PERF_E_IC_IVAU (0x1bb) /**< Number of IC IVAU executed. */
#define BDK_PMU_PERF_E_IC_IVAU_RCVD (0x1bd) /**< Number of IC IVAU received. */
#define BDK_PMU_PERF_E_IDIDS (0xe4) /**< Number of IStream DIDs created. */
#define BDK_PMU_PERF_E_IFILL (0xd3) /**< Number of Icache fills. Noncacheable pseudo fills are not counted. - same as ARM counter 0x0001. */
#define BDK_PMU_PERF_E_II (0xd6) /**< Number of Icache invalidates.  Includes all reasons that icache may be invalidated. */
#define BDK_PMU_PERF_E_INST_RETIRED (8) /**< Number of instructions architecturally executed */
#define BDK_PMU_PERF_E_INST_SPEC (0x1b) /**< Number of instructions that are speculatively executed (those that are subsequently
                                       committed as well as those that are subsequently squashed).
                                       
                                       Internal:
                                       If we can squash an
                                       instruction before we issue it for execution than this counter might be different from
                                       0x014. */
#define BDK_PMU_PERF_E_IP (0xd7) /**< Number of Icache parity errors. */
#define BDK_PMU_PERF_E_IPREF_LDI (0xd1) /**< Number of Icache fills sent to memory subsystem due to a software instruction prefetch.
                                       These may be dropped
                                       and not result in a subsequent fill. */
#define BDK_PMU_PERF_E_ISB (0x1f0) /**< Number of ISB instructions retired. */
#define BDK_PMU_PERF_E_ISB_SPEC (0x7c) /**< Number of isb instructions. */
#define BDK_PMU_PERF_E_ISSUE (0xc1) /**< Number of instructions issued. */
#define BDK_PMU_PERF_E_ISSUE_CSRCLK (0xee) /**< Cycles issue csr clk is active (ie not gated). */
#define BDK_PMU_PERF_E_ISSUE_ECLK (0xc0) /**< Cycles issue eclk is active (ie not gated). */
#define BDK_PMU_PERF_E_IUNA (0xcc) /**< Number of operations taking an unaligned replay, these may be
                                       speculative. Generally this is a 8 cycle penalty. */
#define BDK_PMU_PERF_E_I_MASK_CYC (0x303) /**< Number of cycles during which IRQ is masked */
#define BDK_PMU_PERF_E_L0D_TLB_REFILL (0x190) /**< Internal:
                                       Number of uTLB misses due to d-stream.
                                       Same as L1D_TLB_REFILL as defined by ARM but left over from Octeon. */
#define BDK_PMU_PERF_E_L0D_TLB_REFILL_LD (0x191) /**< Internal:
                                       Number of uTLB misses due to d-stream.
                                       Same as L1D_TLB_REFILL_LD as defined by ARM but left over from Octeon. */
#define BDK_PMU_PERF_E_L0D_TLB_REFILL_ST (0x192) /**< Internal:
                                       Number of uTLB misses due to d-stream.
                                       Same as L1D_TLB_REFILL_ST as defined by ARM but left over from Octeon. */
#define BDK_PMU_PERF_E_L0I_TLB_REFILL (0x18f) /**< Internal:
                                       Number of uTLB misses due to i-stream.
                                       Same as L1I_TLB_REFILL as defined by ARM but left over from Octeon. */
#define BDK_PMU_PERF_E_L1D_CACHE (4) /**< Number of level 1 data cache access. Does not include IO operations. */
#define BDK_PMU_PERF_E_L1D_CACHE_ALLOCATE (0x1f) /**< Internal:
                                       Number of Level 1 data cache allocation without refill. Includes DC ZVA
                                       operations. */
#define BDK_PMU_PERF_E_L1D_CACHE_INVAL (0x48) /**< Number of Level 1 data cache invalidates caused event outside the core. */
#define BDK_PMU_PERF_E_L1D_CACHE_LD (0x40) /**< Number of Level 1 data cache access - read operations (can be hit or miss). */
#define BDK_PMU_PERF_E_L1D_CACHE_MISS_ST (0xe9) /**< Number of stores that miss in the dcache. Similar to ARM house style L1D_CACHE_REFILL_ST
                                       (0x043) but we don't allocate on store misses. */
#define BDK_PMU_PERF_E_L1D_CACHE_PREF (0xea) /**< Number of dcache prefetch instructions. */
#define BDK_PMU_PERF_E_L1D_CACHE_REFILL (3) /**< Number of Level 1 data cache refills.  This counter counts only
                                       refills that cause a new miss to be processed by the L2/Memory system.
                                       If the miss is satisified by a previous miss, it is not counted.
                                       This refill counter counts both LD misses and PREF misses. */
#define BDK_PMU_PERF_E_L1D_CACHE_REFILL_INNER (0x44) /**< Internal:
                                       Not implemented. Number of Level 1 data cache refill, inner cluster. */
#define BDK_PMU_PERF_E_L1D_CACHE_REFILL_LD (0x42) /**< Number of Level 1 data cache refill - read operations caused by LD* instructions,
                                       does not include PREF.
                                       Counts refills that cause a new miss to be processed by the L2/Memory system.
                                       If the miss is satisified by a previous miss, it is not counted. */
#define BDK_PMU_PERF_E_L1D_CACHE_REFILL_OUTER (0x45) /**< Internal:
                                       Not implemented. Number of Level 1 data cache refill, same as 0x003
                                       L1_D_CACHE_REFILL. */
#define BDK_PMU_PERF_E_L1D_CACHE_REFILL_PREF (0xeb) /**< Number of Level 1 data cache refill - prefetch misses.
                                       Counts refills that cause a new miss to be processed by the L2/Memory system.
                                       If the miss is satisified by a previous miss, it is not counted. */
#define BDK_PMU_PERF_E_L1D_CACHE_REFILL_ST (0x43) /**< Internal:
                                       Not implemented. Number of Level 1 data cache refill - write operations. */
#define BDK_PMU_PERF_E_L1D_CACHE_ST (0x41) /**< Number of Level 1 data cache access - write operations.  This counts stores that
                                       can either hit or miss in the dcache. */
#define BDK_PMU_PERF_E_L1D_CACHE_WB (0x15) /**< Internal:
                                       Not implemented. Number of Level 1 data cache write-backs from the Level 1 data
                                       or unified cache. */
#define BDK_PMU_PERF_E_L1D_CACHE_WB_CLEAN (0x47) /**< Internal:
                                       Not implemented. Number of level 1 data cache writeback due to coherency
                                       request. */
#define BDK_PMU_PERF_E_L1D_CACHE_WB_VICTIM (0x46) /**< Internal:
                                       Not implemented. Number of level 1 data cache writebacks caused by action of
                                       this core. */
#define BDK_PMU_PERF_E_L1D_PTW_ACC_IPA_S1 (0x198) /**< Number of dstream PTW access to MTLB (hit/miss), IPA, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_ACC_L0_S1 (0x194) /**< Number of dstream PTW access to MTLB (hit/miss), stage1_level0, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_ACC_L1_S1 (0x195) /**< Number of dstream PTW access to MTLB (hit/miss), stage1_level1, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_ACC_L2_S1 (0x196) /**< Number of dstream PTW access to MTLB (hit/miss), stage1_level2, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_ACC_L3_S1 (0x197) /**< Number of dstream PTW access to MTLB (hit/miss), stage1_level3, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L0_S1 (0x19e) /**< Number of dstream PWC misses, level0, stage1. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L0_S2 (0x1a2) /**< Number of dstream PWC misses, level0, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L1_S1 (0x19f) /**< Number of dstream PWC misses, level1, stage1. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L1_S2 (0x1a3) /**< Number of dstream PWC misses, level1, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L2_S1 (0x1a0) /**< Number of dstream PWC misses, level2, stage1. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L2_S2 (0x1a4) /**< Number of dstream PWC misses, level2, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L3_S1 (0x1a1) /**< Number of dstream PWC misses, level3, stage1. */
#define BDK_PMU_PERF_E_L1D_PTW_PWC_REFILL_L3_S2 (0x1a5) /**< Number of dstream PWC misses, level3, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_REFILL_IPA_S2 (0x19d) /**< Number of dstream MTLB miss, IPA, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_REFILL_L0_S1 (0x199) /**< Number of dstream MTLB miss, stage1_level0, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_REFILL_L1_S1 (0x19a) /**< Number of dstream MTLB miss, stage1_level1, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_REFILL_L2_S1 (0x19b) /**< Number of dstream MTLB miss, stage1_level2, stage2. */
#define BDK_PMU_PERF_E_L1D_PTW_REFILL_L3_S1 (0x19c) /**< Number of dstream MTLB miss, stage1_level3, stage2. */
#define BDK_PMU_PERF_E_L1D_TLB (0x25) /**< Number of accesses to microtlb caused by a data reference. TLB maintenance instructions do
                                       not count. */
#define BDK_PMU_PERF_E_L1D_TLB_LD (0x4e) /**< Number of Level 1 data TLB access due to memory read operations.. */
#define BDK_PMU_PERF_E_L1D_TLB_REFILL (5) /**< Number of level 1 data TLB refills. */
#define BDK_PMU_PERF_E_L1D_TLB_REFILL_LD (0x4c) /**< Number of Level 1 data TLB refill (as in L1D_TLB_REFILL) and due to memory read operations.. */
#define BDK_PMU_PERF_E_L1D_TLB_REFILL_ST (0x4d) /**< Number of Level 1 data TLB refill (as in L1D_TLB_REFILL) and due to memory write operations. */
#define BDK_PMU_PERF_E_L1D_TLB_ST (0x4f) /**< Number of Level 1 data access memory write operations. */
#define BDK_PMU_PERF_E_L1I_CACHE (0x14) /**< Number ofinstruction memory accesses that access the L1 Icache. Counts both hits and misses. */
#define BDK_PMU_PERF_E_L1I_CACHE_PREF (0xec) /**< Number of icache prefetch instructions. */
#define BDK_PMU_PERF_E_L1I_CACHE_REFILL (1) /**< Number of level 1 instruction cache refills */
#define BDK_PMU_PERF_E_L1I_CACHE_REFILL_PREF (0xed) /**< Number of icache prefetch instructions that miss. */
#define BDK_PMU_PERF_E_L1I_PTW_ACC_IPA_S1 (0x1aa) /**< Number of istream PTW access to MTLB (hit/miss), IPA, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_ACC_L0_S1 (0x1a6) /**< Number of istream PTW access to MTLB (hit/miss), stage1_level0, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_ACC_L1_S1 (0x1a7) /**< Number of istream PTW access to MTLB (hit/miss), stage1_level1, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_ACC_L2_S1 (0x1a8) /**< Number of istream PTW access to MTLB (hit/miss), stage1_level2, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_ACC_L3_S1 (0x1a9) /**< Number of istream PTW access to MTLB (hit/miss), stage1_level3, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L0_S1 (0x1b0) /**< Number of istream PWC misses, level0, stage1. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L0_S2 (0x1b4) /**< Number of istream PWC misses, level0, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L1_S1 (0x1b1) /**< Number of istream PWC misses, level1, stage1. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L1_S2 (0x1b5) /**< Number of istream PWC misses, level1, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L2_S1 (0x1b2) /**< Number of istream PWC misses, level2, stage1. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L2_S2 (0x1b6) /**< Number of istream PWC misses, level2, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L3_S1 (0x1b3) /**< Number of istream PWC misses, level3, stage1. */
#define BDK_PMU_PERF_E_L1I_PTW_PWC_REFILL_L3_S2 (0x1b7) /**< Number of istream PWC misses, level3, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_REFILL_IPA_S2 (0x1af) /**< Number of istream MTLB miss, IPA, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_REFILL_L0_S1 (0x1ab) /**< Number of istream MTLB miss, stage1_level0, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_REFILL_L1_S1 (0x1ac) /**< Number of istream MTLB miss, stage1_level1, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_REFILL_L2_S1 (0x1ad) /**< Number of istream MTLB miss, stage1_level2, stage2. */
#define BDK_PMU_PERF_E_L1I_PTW_REFILL_L3_S1 (0x1ae) /**< Number of istream MTLB miss, stage1_level3, stage2. */
#define BDK_PMU_PERF_E_L1I_TLB (0x26) /**< Number of accesses to microtlb caused by an instruction reference. */
#define BDK_PMU_PERF_E_L1I_TLB_REFILL (2) /**< Number of Level 1 instruction TLB refill. */
#define BDK_PMU_PERF_E_L2C_EVENT_1 (0x4c00) /**< Internal:
                                       L2C event -code, local/remote, event, ccpi, comment (mcbuggin 21410):
                                       0000 = n/a, , , idx/way & broadcast commands, remote misses that don't allocate at
                                       requestor (note: missing counter)
                                       0001 = local, hit, none, load hit or store hit exclusive, no local invalidates required
                                       0010 = local, hi exclu, none, store hit exclusive, local invalidates required
                                       0011 = local, hist shared, SINV, store hit shared
                                       0100 = local, miss clean, none
                                       0101 = local, miss clean, SINV or FLDx, have to get data from remote sharer or invalidate
                                       a remote sharer
                                       0110 = local, miss dirty, none
                                       0111 = local, miss dirty, SINV or FLDx, have to get data from remote sharer or invalidate
                                       a remote sharer
                                       1000 = reserved
                                       1001 = remote, hit, none, load hit or store hit exclusive, no local
                                       1010 = remote, hit exclusive, none, store hit exclusive, local invalidates required
                                       1011 = remote, hit shared, RC2D/RSTC/RCAS, store hit shared
                                       1100 = remote, miss clean, RLDD/RLDI on CCPI, Allocating in L2 for a data or instruction
                                       read
                                       1101 = remote, miss clean, RLDX on CCPI, Allocating in L2 for a write (RLDX)(i.e. rqsting
                                       excl data)
                                       1110 = remote, miss dirty, RLDD/RLDI on CCPI, Allocating in L2 for  data or instruction
                                       read
                                       1111 = remote, miss dirty, RLDX on CCPI, Allocating in L2 for a write (RLDX)(i.e. rrqsting
                                       excl data) */
#define BDK_PMU_PERF_E_L2C_EVENT_10 (0x4c09) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_11 (0x4c0a) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_12 (0x4c0b) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_13 (0x4c0c) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_14 (0x4c0d) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_15 (0x4c0e) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_2 (0x4c01) /**< Internal:
                                       L2C event - */
#define BDK_PMU_PERF_E_L2C_EVENT_3 (0x4c02) /**< Internal:
                                       L2C event - */
#define BDK_PMU_PERF_E_L2C_EVENT_4 (0x4c03) /**< Internal:
                                       L2C event - miss clean */
#define BDK_PMU_PERF_E_L2C_EVENT_5 (0x4c04) /**< Internal:
                                       L2C event - */
#define BDK_PMU_PERF_E_L2C_EVENT_6 (0x4c05) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_7 (0x4c06) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_8 (0x4c07) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2C_EVENT_9 (0x4c08) /**< Internal:
                                       L2C event */
#define BDK_PMU_PERF_E_L2D_CACHE (0x16) /**< Number of Level 2 data cache access The counter counts memory-read or memory-write
                                       operations, that the PE made, that access at least the Level 2 data or unified
                                       cache. Each access to a cache line is counted including refills of the
                                       Level 1 data and instruction and writes from the writebuffer. Each access to
                                       other Level 2 data or unified memory
                                       structures, such as refill buffers, write buffers, and write-back buffers, is also
                                       counted. The counter does not count:
                                       *     Operations made by other PEs that share this cache.
                                       *     CP15 cache maintenance instructions. */
#define BDK_PMU_PERF_E_L2D_CACHE_ALLOCATE (0x20) /**< Internal:
                                       Number of Level 2 data cache allocation without refill, including write buffer
                                       full cache
                                       line, or DC ZVA operations. */
#define BDK_PMU_PERF_E_L2D_CACHE_CACHE_INVAL (0x58) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_L2D_CACHE_LD (0x50) /**< Number of accesses to L2 cache caused by memory read operations (load
                                       instructions, page table walks). Similar to 0x16 but does not include memory
                                       write operations or instruction misses. */
#define BDK_PMU_PERF_E_L2D_CACHE_REFILL (0x17) /**< Number of level 2 cache refills due to this AP.  Counts all refills from the L2
                                       to the icache, dcache and pwc. */
#define BDK_PMU_PERF_E_L2D_CACHE_REFILL_LD (0x52) /**< Number of accesses to L2 cache caused by memory read operations (load
                                       instructions, page table walks) that result in an L2 refill (miss). */
#define BDK_PMU_PERF_E_L2D_CACHE_REFILL_ST (0x53) /**< Number of access to L2 cache caused by memory write operations (stores from the
                                       write buffer) that result in an L2 refill. */
#define BDK_PMU_PERF_E_L2D_CACHE_ST (0x51) /**< Number of accesses to L2 cache caused by memory write operations (stores from
                                       the write buffer). Similar to 0x16 but does not include memory read operations
                                       or instruciton misses. */
#define BDK_PMU_PERF_E_L2D_CACHE_WB (0x18) /**< Number of level 2 cache writebacks due to actions by this AP. */
#define BDK_PMU_PERF_E_L2D_CACHE_WB_CLEAN (0x57) /**< Number of accesses to L2 cache that replaced a cache line that was not dirty. */
#define BDK_PMU_PERF_E_L2D_CACHE_WB_VICTIM (0x56) /**< Number of accesses to L2 cache that caused a writeback to occur from the L2. */
#define BDK_PMU_PERF_E_L2D_TLB (0x2f) /**< Number of MTLB accesses due to memory read or memory write operations. */
#define BDK_PMU_PERF_E_L2D_TLB_REFILL (0x2d) /**< Number of MTLB Refills due to memory read and memory write operations. */
#define BDK_PMU_PERF_E_L2D_TLB_REFILL_LD (0x5c) /**< Number of MTLB accesses that miss in the MTLB and were caused by memory read operations. */
#define BDK_PMU_PERF_E_L2D_TLB_REFILL_ST (0x5d) /**< Number of MTLB accesses that miss in the MTLB and were caused by memory write operation. */
#define BDK_PMU_PERF_E_L2I_CACHE (0x27) /**< Number of accesses made to the L2 by the L1 ICache misses. */
#define BDK_PMU_PERF_E_L2I_CACHE_REFILL (0x28) /**< Number of refills into the L2 destined for the icache. */
#define BDK_PMU_PERF_E_L2I_TLB (0x30) /**< Internal:
                                       Number of MTLB accesses due to instruction access. */
#define BDK_PMU_PERF_E_L2I_TLB_REFILL (0x2e) /**< Number of MTLB refills due to instruction tlb misses. */
#define BDK_PMU_PERF_E_L3D_CACHE (0x2b) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_L3D_CACHE_ALLOCATE (0x29) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_L3D_CACHE_REFILL (0x2a) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_L3D_CACHE_WB (0x2c) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_LDREX_SPEC (0x6c) /**< Number of speculative load exclusives. */
#define BDK_PMU_PERF_E_LDST_SPEC (0x72) /**< Number of load or store instructions; speculatively executed, instructions may
                                       be counted multiple times due to replays. */
#define BDK_PMU_PERF_E_LDX (0x1f9) /**< Number of load-exclusive instruction retired. */
#define BDK_PMU_PERF_E_LD_DEV_IO (0x188) /**< Number of committed load instructions to Device memory - I/O space (PA<47>=1). */
#define BDK_PMU_PERF_E_LD_DEV_MEM (0x18a) /**< Number of committed load instructions to Device memory - MEM space (PA<47>=0). */
#define BDK_PMU_PERF_E_LD_NORM_IO (0x184) /**< Number of committed load instructions to Normal memory - I/O space (PA<47>=1). */
#define BDK_PMU_PERF_E_LD_NORM_MEM (0x186) /**< Number of committed load instructions to Normal memory - MEM space (PA<47>=0). */
#define BDK_PMU_PERF_E_LD_RETIRED (6) /**< Number of loads retired. */
#define BDK_PMU_PERF_E_LD_SPEC (0x70) /**< Number of load instructions; same instructions as 0x6, but speculatively
                                       executed, instructions may be counted multiple times due to replays. */
#define BDK_PMU_PERF_E_MEMORY_ERROR (0x1a) /**< Number of parity errors coming from the icache. */
#define BDK_PMU_PERF_E_MEM_ACCESS (0x13) /**< Number of load and stores to memory (PA<47>=0), does not include tables walks, cache
                                       maintenance.  The
                                       access maybe cache hit or miss. */
#define BDK_PMU_PERF_E_MEM_ACCESS_LD (0x66) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_MEM_ACCESS_ST (0x67) /**< Internal:
                                       Not implemented. */
#define BDK_PMU_PERF_E_MSR_HAZTR (0xe8) /**< Number of hazard pipeline flushes */
#define BDK_PMU_PERF_E_NISSUE (0xc2) /**< Cycles no instructions were issued. */
#define BDK_PMU_PERF_E_PC_WRITE_RETIRED (0xc) /**< Number of instruction architecturally executed that change the PC.
                                       Includes:
                                       B, B.cond (if taken), BL, BR, BLR, RET, CBNZ (if taken), CBZ (if taken)
                                       TBNZ (if taken), TBZ (if taken), ERET */
#define BDK_PMU_PERF_E_PTW_CYCLES (0x193) /**< Number of cycles PageTable Walker is active. */
#define BDK_PMU_PERF_E_RC_LD_SPEC (0x90) /**< Number of load-aquire instructions. */
#define BDK_PMU_PERF_E_RC_ST_SPEC (0x91) /**< Number of store-release instructions. */
#define BDK_PMU_PERF_E_REPLAY (0xcb) /**< Number of mem replays. */
#define BDK_PMU_PERF_E_SEV (0x1b9) /**< Number of SEV instructions executed. */
#define BDK_PMU_PERF_E_SISSUE (0xc3) /**< Cycles one instruction was issued. */
#define BDK_PMU_PERF_E_STALL_BACKEND (0x24) /**< Cycles on which no operation instructions issued, even though instructions are available
                                       from the fetch unit.
                                       Possible reasons include functional unit resource conflicts, data cache misses and similar
                                       causes. */
#define BDK_PMU_PERF_E_STALL_FRONTEND (0x23) /**< Cycles on which no operation issued because there are instructions from the fetch unit. */
#define BDK_PMU_PERF_E_STREX_FAIL_SPEC (0x6e) /**< Number of speculative store exclusive fails.
                                       Might be counted multiple times due to replays. */
#define BDK_PMU_PERF_E_STREX_PASS_SPEC (0x6d) /**< Number of speculative store exclusive passes.
                                       might be counted multiple times due to replays. */
#define BDK_PMU_PERF_E_STX (0x1fa) /**< Number of store-exclusive instruction retired (may or may not succeed). */
#define BDK_PMU_PERF_E_STX_FAIL (0x1fb) /**< Number of store-exclusive fails. */
#define BDK_PMU_PERF_E_ST_DEV_IO (0x189) /**< Number of committed store instructions to Device memory - I/O space (PA<47>=1). */
#define BDK_PMU_PERF_E_ST_DEV_MEM (0x18b) /**< Number of committed store instructions to Device memory - MEM space (PA<47>=0). */
#define BDK_PMU_PERF_E_ST_NORM_IO (0x185) /**< Number of committed store instructions to Normal memory - I/O space (PA<47>=1). */
#define BDK_PMU_PERF_E_ST_NORM_MEM (0x187) /**< Number of committed store instructions to Normal memory - MEM space (PA<47>=0). */
#define BDK_PMU_PERF_E_ST_RETIRED (7) /**< Number of stores retired, includes DC ZVA. */
#define BDK_PMU_PERF_E_ST_SPEC (0x71) /**< Number of store instructions; same instructions as 0x7, but speculatively
                                       executed, instructions may be counted multiple times due to replays. */
#define BDK_PMU_PERF_E_SW_INCR (0) /**< This counter increments on writes to the PMSWINC register. */
#define BDK_PMU_PERF_E_THROTTLE_OFF (0xef) /**< Cycles execution is prevented to reduce power. */
#define BDK_PMU_PERF_E_TLBI_ALLE1 (0x1c6) /**< Number of TLBI with ALLE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_ALLE1IS (0x1c7) /**< Number of TLBI with ALLE1IS attribute. */
#define BDK_PMU_PERF_E_TLBI_ALLE2 (0x1c8) /**< Number of TLBI with ALLE2 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_ALLE2IS (0x1c9) /**< Number of TLBI with ALLE2IS attribute (local). */
#define BDK_PMU_PERF_E_TLBI_ALLE3 (0x1ca) /**< Number of TLBI with ALLE3 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_ALLE3IS (0x1cb) /**< Number of TLBI with ALLE3IS attribute. */
#define BDK_PMU_PERF_E_TLBI_ASIDE1 (0x1cc) /**< Number of TLBI with ASIDE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_ASIDE1IS (0x1cd) /**< Number of TLBI with ASIDE1IS attribute. */
#define BDK_PMU_PERF_E_TLBI_IPAS2E1 (0x1ce) /**< Number of TLBI with IPAS2E1 (local). */
#define BDK_PMU_PERF_E_TLBI_IPAS2E1IS (0x1cf) /**< Number of TLBI with IPAS2E1IS. */
#define BDK_PMU_PERF_E_TLBI_IPAS2LE1 (0x1d0) /**< Number of TLBI with IPAS2LE1 (local). */
#define BDK_PMU_PERF_E_TLBI_IPAS2LE1IS (0x1d1) /**< Number of TLBI with IPAS2LE1IS. */
#define BDK_PMU_PERF_E_TLBI_NOPS_CN81XX (0x1ef) /**< Number of TLBI broadcasts that are suppressed. */
#define BDK_PMU_PERF_E_TLBI_NOPS_CN88XX (0x1ef) /**< Number of TLBI broadcasts that are suppressed.
                                       Added in pass 2. */
#define BDK_PMU_PERF_E_TLBI_NOPS_CN83XX (0x1ef) /**< Number of TLBI broadcasts that are suppressed. */
#define BDK_PMU_PERF_E_TLBI_RCVD (0x1c5) /**< Number of TLBIs received. */
#define BDK_PMU_PERF_E_TLBI_SENT (0x1c4) /**< Number of TLBIs sent. */
#define BDK_PMU_PERF_E_TLBI_VAAE1 (0x1d2) /**< Number of TLBI with VAAE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VAAE1IS (0x1d3) /**< Number of TLBI with VAAE1 attribute. */
#define BDK_PMU_PERF_E_TLBI_VAALE1 (0x1d4) /**< Number of TLBI with VAALE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VAALE1IS (0x1d5) /**< Number of TLBI with VAALE1IS attribute. */
#define BDK_PMU_PERF_E_TLBI_VAE1 (0x1d6) /**< Number of TLBI with VAE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VAE1IS (0x1d7) /**< Number of TLBI with VAE1IS attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VAE2 (0x1d8) /**< Number of TLBI with VAE2 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VAE2IS (0x1d9) /**< Number of TLBI with VAE2IS attribute. */
#define BDK_PMU_PERF_E_TLBI_VAE3 (0x1da) /**< Number of TLBI with VAE3 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VAE3IS (0x1db) /**< Number of TLBI with VAE3IS attribute. */
#define BDK_PMU_PERF_E_TLBI_VALE1 (0x1dc) /**< Number of TLBI with VALE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VALE1IS (0x1dd) /**< Number of TLBI with VALE1IS attribute. */
#define BDK_PMU_PERF_E_TLBI_VALE2 (0x1de) /**< Number of TLBI with VALE2 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VALE2IS (0x1df) /**< Number of TLBI with VALE2IS attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VALE3 (0x1e0) /**< Number of TLBI with VALE3 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VALE3IS (0x1e1) /**< Number of TLBI with VALE3IS attribute. */
#define BDK_PMU_PERF_E_TLBI_VMALLE1 (0x1e2) /**< Number of TLBI with VMALLE1 attribute (local). */
#define BDK_PMU_PERF_E_TLBI_VMALLE1IS (0x1e3) /**< Number of TLBI with VMALLE1 attribute. */
#define BDK_PMU_PERF_E_TLBI_VMALLS12E1 (0x1e4) /**< Number of TLBI with VMALLS12E1 (local). */
#define BDK_PMU_PERF_E_TLBI_VMALLS12E1IS (0x1e5) /**< Number of TLBI with VMALLS12E1IS. */
#define BDK_PMU_PERF_E_TLB_REFILL_TTBR0_ELX (0x18c) /**< Number of stage 1 MTLB misses TTBR0. Can filter by EL level and security state. */
#define BDK_PMU_PERF_E_TLB_REFILL_TTBR1_ELX (0x18d) /**< Number of stage 1 MTLB misses TRBR1. Can filter by EL level (EL1 and EL2 - ARMv8.1). */
#define BDK_PMU_PERF_E_TLB_REFILL_VTTBR_EL2 (0x18e) /**< Number of stage 2 MTLB misses. Only makes sense for EL0 and EL1. */
#define BDK_PMU_PERF_E_TRAP (0xcd) /**< Number of traps. These include mem replays and exceptions but not mispredicts or unaligned replays */
#define BDK_PMU_PERF_E_TRAP_REASONX(a) (0x4f00 + (a)) /**< Internal:
                                       Event for every reason code why an exception or replay occured.
                                       Event for every reason code why the head of the queue didn't issue(0 means we issued)
                                       0 = issued */
#define BDK_PMU_PERF_E_TTBR_WRITE_RETIRED (0x1c) /**< Number of writes to TTBR0_EL1 and TTBR1_EL1. */
#define BDK_PMU_PERF_E_ULOAD (0xce) /**< Number of committed loads which used the unaligned flow.  Similar to  UNALIGNED_LD_SPEC
                                       but this
                                       counter counts only committed loads. */
#define BDK_PMU_PERF_E_UNALIGNED_LDST_RETIRED (0xf) /**< Number of unaligned load or store instructions retired. */
#define BDK_PMU_PERF_E_UNALIGNED_LDST_SPEC (0x6a) /**< Number of speculative unaligned load or unaligned stores. These unaligned loads and stores
                                       might be counted multiple times due to replays. */
#define BDK_PMU_PERF_E_UNALIGNED_LD_SPEC (0x68) /**< Number of speculative unaligned loads.  A load might be counted multiple times
                                       due to replays. */
#define BDK_PMU_PERF_E_UNALIGNED_ST_SPEC (0x69) /**< Number of speculative unaligned stores.  A store might be counted multiple times
                                       due to replays. */
#define BDK_PMU_PERF_E_USTORE (0xcf) /**< Number of committed stores which used the unaligned flow. Similar to UNALIGNED_ST_SPEC but
                                       this
                                       counter counts only committed stores. */
#define BDK_PMU_PERF_E_VFP_SPEC (0x75) /**< Number of FP, speculatively executed (see v8 ARM ARM for definition of this
                                       class). Includes FP SIMD instructions. */
#define BDK_PMU_PERF_E_VMID_OVF (0x301) /**< Number of times VMIDMap overflowed. */
#define BDK_PMU_PERF_E_WBUF (0xdb) /**< Number of write buffer entries created. */
#define BDK_PMU_PERF_E_WBUFFL (0xde) /**< Number of cycles that there was no available write buffer entry. */
#define BDK_PMU_PERF_E_WBUFLD (0xdd) /**< Number of write buffere entries forced out by loads. */
#define BDK_PMU_PERF_E_WBUFTR (0xdf) /**< Number of stores that found no available write buffer entries. */
#define BDK_PMU_PERF_E_WDAT (0xdc) /**< Number of cycles on the XMD bus which are used to transfer data from the writebuffer to the L2C. */

/**
 * Register (DAB32b) pmu#_pmauthstatus
 *
 * Performance Monitors Authentication Status Register
 * Provides information about the state of the implementation
 * defined authentication interface for performance monitors.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmauthstatus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t snid                  : 2;  /**< [  7:  6](RO) Holds the same value as DBGAUTHSTATUS_EL1.SNID. */
        uint32_t reserved_4_5          : 2;
        uint32_t nsnid                 : 2;  /**< [  3:  2](RO) Holds the same value as DBGAUTHSTATUS_EL1.NSNID. */
        uint32_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_1          : 2;
        uint32_t nsnid                 : 2;  /**< [  3:  2](RO) Holds the same value as DBGAUTHSTATUS_EL1.NSNID. */
        uint32_t reserved_4_5          : 2;
        uint32_t snid                  : 2;  /**< [  7:  6](RO) Holds the same value as DBGAUTHSTATUS_EL1.SNID. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmauthstatus_s cn; */
} bdk_pmux_pmauthstatus_t;

static inline uint64_t BDK_PMUX_PMAUTHSTATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMAUTHSTATUS(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fb8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMAUTHSTATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMAUTHSTATUS(a) bdk_pmux_pmauthstatus_t
#define bustype_BDK_PMUX_PMAUTHSTATUS(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMAUTHSTATUS(a) "PMUX_PMAUTHSTATUS"
#define busnum_BDK_PMUX_PMAUTHSTATUS(a) (a)
#define arguments_BDK_PMUX_PMAUTHSTATUS(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmccfiltr_el0
 *
 * Performance Monitors Cycle Counter Filter Register
 * Determines the modes in which the Cycle Counter, PMU()_PMCCNTR_EL0,
 *     increments.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmccfiltr_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count cycles in EL1.
                                                                 1 = Do not count cycles in EL1. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count cycles in EL0.
                                                                 1 = Do not count cycles in EL0. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, cycles in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, cycles in Non-secure EL1 are not counted. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, cycles in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, cycles in Non-secure EL0 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count cycles in EL2.
                                                                 1 = Count cycles in EL2. */
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, cycles in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, cycles in Secure EL3 are not counted. */
        uint32_t reserved_0_25         : 26;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_25         : 26;
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, cycles in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, cycles in Secure EL3 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count cycles in EL2.
                                                                 1 = Count cycles in EL2. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, cycles in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, cycles in Non-secure EL0 are not counted. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, cycles in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, cycles in Non-secure EL1 are not counted. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count cycles in EL0.
                                                                 1 = Do not count cycles in EL0. */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count cycles in EL1.
                                                                 1 = Do not count cycles in EL1. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmccfiltr_el0_s cn; */
} bdk_pmux_pmccfiltr_el0_t;

static inline uint64_t BDK_PMUX_PMCCFILTR_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCCFILTR_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a00802047cll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCCFILTR_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCCFILTR_EL0(a) bdk_pmux_pmccfiltr_el0_t
#define bustype_BDK_PMUX_PMCCFILTR_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCCFILTR_EL0(a) "PMUX_PMCCFILTR_EL0"
#define busnum_BDK_PMUX_PMCCFILTR_EL0(a) (a)
#define arguments_BDK_PMUX_PMCCFILTR_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmccntr_el0_hi
 *
 * Performance Monitors Cycle Counter High Register
 * Holds the value of the processor Cycle Counter, CCNT, that counts processor clock cycles.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmccntr_el0_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Cycle count. Depending on the values of PMU()_PMCR_EL0[LC,D], the cycle count
                                                                 increments in one of the following ways:
                                                                 * Every processor clock cycle.
                                                                 * Every 64th processor clock cycle.
                                                                 The cycle count can be reset to zero by writing 1 to PMU()_PMCR_EL0[C]. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Cycle count. Depending on the values of PMU()_PMCR_EL0[LC,D], the cycle count
                                                                 increments in one of the following ways:
                                                                 * Every processor clock cycle.
                                                                 * Every 64th processor clock cycle.
                                                                 The cycle count can be reset to zero by writing 1 to PMU()_PMCR_EL0[C]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmccntr_el0_hi_s cn; */
} bdk_pmux_pmccntr_el0_hi_t;

static inline uint64_t BDK_PMUX_PMCCNTR_EL0_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCCNTR_EL0_HI(unsigned long a)
{
    if (a<=47)
        return 0x87a0080200fcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCCNTR_EL0_HI", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCCNTR_EL0_HI(a) bdk_pmux_pmccntr_el0_hi_t
#define bustype_BDK_PMUX_PMCCNTR_EL0_HI(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCCNTR_EL0_HI(a) "PMUX_PMCCNTR_EL0_HI"
#define busnum_BDK_PMUX_PMCCNTR_EL0_HI(a) (a)
#define arguments_BDK_PMUX_PMCCNTR_EL0_HI(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmccntr_el0_lo
 *
 * Performance Monitors Cycle Counter Low Register
 * Holds the value of the processor Cycle Counter, CCNT, that counts processor clock cycles.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmccntr_el0_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Cycle count. Depending on the values of PMU()_PMCR_EL0[LC,D], the cycle count
                                                                 increments in one of the following ways:
                                                                 * Every processor clock cycle.
                                                                 * Every 64th processor clock cycle.
                                                                 The cycle count can be reset to zero by writing 1 to PMU()_PMCR_EL0[C]. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W) Cycle count. Depending on the values of PMU()_PMCR_EL0[LC,D], the cycle count
                                                                 increments in one of the following ways:
                                                                 * Every processor clock cycle.
                                                                 * Every 64th processor clock cycle.
                                                                 The cycle count can be reset to zero by writing 1 to PMU()_PMCR_EL0[C]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmccntr_el0_lo_s cn; */
} bdk_pmux_pmccntr_el0_lo_t;

static inline uint64_t BDK_PMUX_PMCCNTR_EL0_LO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCCNTR_EL0_LO(unsigned long a)
{
    if (a<=47)
        return 0x87a0080200f8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCCNTR_EL0_LO", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCCNTR_EL0_LO(a) bdk_pmux_pmccntr_el0_lo_t
#define bustype_BDK_PMUX_PMCCNTR_EL0_LO(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCCNTR_EL0_LO(a) "PMUX_PMCCNTR_EL0_LO"
#define busnum_BDK_PMUX_PMCCNTR_EL0_LO(a) (a)
#define arguments_BDK_PMUX_PMCCNTR_EL0_LO(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmceid0
 *
 * Performance Monitors Common Event Identification Register 0
 * Defines which common architectural and common
 *     microarchitectural feature events are implemented. If a
 *     particular bit is set to 1, then the event for that bit is
 *     implemented. Alias for PMU()_PMCEID1_EL0[31:0].
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmceid0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ce                    : 32; /**< [ 31:  0](RO) Common architectural and microarchitectural feature events that can be counted
                                                                 by the PMU event counters.

                                                                 In CNXXXX, the following bits are set to indicate the corresponding events are
                                                                 implemented:
                                                                   30 = 0x001e = CHAIN.
                                                                   28 = 0x001c = TTBR_WRITE_RETIRED.
                                                                   27 = 0x001b = INST_SPEC.
                                                                   26 = 0x001a = MEMORY_ERROR.
                                                                   24 = 0x0018 = L2D_CACHE_WB.
                                                                   23 = 0x0017 = L2D_CACHE_REFILL.
                                                                   22 = 0x0016 = L2D_CACHE.
                                                                   20 = 0x0014 = L1I_CACHE.
                                                                   19 = 0x0013 = MEM_ACCESS.
                                                                   18 = 0x0012 = BR_PRED.
                                                                   17 = 0x0011 = CPU_CYCLES.
                                                                   16 = 0x0010 = BR_MIS_PRED.
                                                                   15 = 0x000f = UNALIGNED_LDST_RETIRED.
                                                                   14 = 0x000e = BR_RETURN_RETIRED.
                                                                   13 = 0x000d = BR_IMMED_RETIRED.
                                                                   12 = 0x000c = PC_WRITE_RETIRED.
                                                                   11 = 0x000b = CID_WRITE_RETIRED.
                                                                   10 = 0x000a = EXC_RETURN.
                                                                    9 = 0x0009 = EXC_TAKEN.
                                                                    8 = 0x0008 = INST_RETIRED.
                                                                    7 = 0x0007 = ST_RETIRED.
                                                                    6 = 0x0006 = LD_RETIRED.
                                                                    5 = 0x0005 = L1D_TLB_REFILL.
                                                                    4 = 0x0004 = L1D_CACHE.
                                                                    3 = 0x0003 = L1D_CACHE_REFILL.
                                                                    2 = 0x0002 = L1I_TLB_REFILL.
                                                                    1 = 0x0001 = L1I_CACHE_REFILL.
                                                                    0 = 0x0000 = SW_INCR. */
#else /* Word 0 - Little Endian */
        uint32_t ce                    : 32; /**< [ 31:  0](RO) Common architectural and microarchitectural feature events that can be counted
                                                                 by the PMU event counters.

                                                                 In CNXXXX, the following bits are set to indicate the corresponding events are
                                                                 implemented:
                                                                   30 = 0x001e = CHAIN.
                                                                   28 = 0x001c = TTBR_WRITE_RETIRED.
                                                                   27 = 0x001b = INST_SPEC.
                                                                   26 = 0x001a = MEMORY_ERROR.
                                                                   24 = 0x0018 = L2D_CACHE_WB.
                                                                   23 = 0x0017 = L2D_CACHE_REFILL.
                                                                   22 = 0x0016 = L2D_CACHE.
                                                                   20 = 0x0014 = L1I_CACHE.
                                                                   19 = 0x0013 = MEM_ACCESS.
                                                                   18 = 0x0012 = BR_PRED.
                                                                   17 = 0x0011 = CPU_CYCLES.
                                                                   16 = 0x0010 = BR_MIS_PRED.
                                                                   15 = 0x000f = UNALIGNED_LDST_RETIRED.
                                                                   14 = 0x000e = BR_RETURN_RETIRED.
                                                                   13 = 0x000d = BR_IMMED_RETIRED.
                                                                   12 = 0x000c = PC_WRITE_RETIRED.
                                                                   11 = 0x000b = CID_WRITE_RETIRED.
                                                                   10 = 0x000a = EXC_RETURN.
                                                                    9 = 0x0009 = EXC_TAKEN.
                                                                    8 = 0x0008 = INST_RETIRED.
                                                                    7 = 0x0007 = ST_RETIRED.
                                                                    6 = 0x0006 = LD_RETIRED.
                                                                    5 = 0x0005 = L1D_TLB_REFILL.
                                                                    4 = 0x0004 = L1D_CACHE.
                                                                    3 = 0x0003 = L1D_CACHE_REFILL.
                                                                    2 = 0x0002 = L1I_TLB_REFILL.
                                                                    1 = 0x0001 = L1I_CACHE_REFILL.
                                                                    0 = 0x0000 = SW_INCR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmceid0_s cn; */
} bdk_pmux_pmceid0_t;

static inline uint64_t BDK_PMUX_PMCEID0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCEID0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020e20ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCEID0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCEID0(a) bdk_pmux_pmceid0_t
#define bustype_BDK_PMUX_PMCEID0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCEID0(a) "PMUX_PMCEID0"
#define busnum_BDK_PMUX_PMCEID0(a) (a)
#define arguments_BDK_PMUX_PMCEID0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmceid1
 *
 * Performance Monitors Common Event Identification Register 1
 * Reserved for future indication of which common architectural
 *     and common microarchitectural feature events are implemented.
 *     These events are in the range 0x20-0x3f.
 *     Alias for PMU()_PMCEID1_EL0[31:0].
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmceid1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ce                    : 32; /**< [ 31:  0](RO) Common architectural and microarchitectural feature events that can be counted
                                                                 by the PMU event counters.

                                                                 In CNXXXX, the following bits are set to indicate the corresponding events are
                                                                 implemented:
                                                                   15 = 0x002f = L2D_TLB.
                                                                   14 = 0x002e = L2I_TLB_REFILL.
                                                                   13 = 0x002d = L2D_TLB_REFILL.
                                                                   8  = 0x0028 = L2I_CACHE_REFILL.
                                                                   7  = 0x0027 = L2I_CACHE.
                                                                   6  = 0x0026 = L1I_TLB.
                                                                   5  = 0x0025 = L1D_TLB.
                                                                   4  = 0x0024 = STALL_BACKEND.
                                                                   3  = 0x0023 = STALL_FRONTEND.
                                                                   2  = 0x0022 = BR_MIS_PRED_RETIRED.
                                                                   1  = 0x0021 = BR_RETIRED. */
#else /* Word 0 - Little Endian */
        uint32_t ce                    : 32; /**< [ 31:  0](RO) Common architectural and microarchitectural feature events that can be counted
                                                                 by the PMU event counters.

                                                                 In CNXXXX, the following bits are set to indicate the corresponding events are
                                                                 implemented:
                                                                   15 = 0x002f = L2D_TLB.
                                                                   14 = 0x002e = L2I_TLB_REFILL.
                                                                   13 = 0x002d = L2D_TLB_REFILL.
                                                                   8  = 0x0028 = L2I_CACHE_REFILL.
                                                                   7  = 0x0027 = L2I_CACHE.
                                                                   6  = 0x0026 = L1I_TLB.
                                                                   5  = 0x0025 = L1D_TLB.
                                                                   4  = 0x0024 = STALL_BACKEND.
                                                                   3  = 0x0023 = STALL_FRONTEND.
                                                                   2  = 0x0022 = BR_MIS_PRED_RETIRED.
                                                                   1  = 0x0021 = BR_RETIRED. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmceid1_s cn; */
} bdk_pmux_pmceid1_t;

static inline uint64_t BDK_PMUX_PMCEID1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCEID1(unsigned long a)
{
    if (a<=47)
        return 0x87a008020e24ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCEID1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCEID1(a) bdk_pmux_pmceid1_t
#define bustype_BDK_PMUX_PMCEID1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCEID1(a) "PMUX_PMCEID1"
#define busnum_BDK_PMUX_PMCEID1(a) (a)
#define arguments_BDK_PMUX_PMCEID1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmceid2
 *
 * Performance Monitors Common Event Identification Register 2
 * Reserved for future indication of which common architectural
 *     and common microarchitectural feature events are implemented.
 *     These events are in the range 0x4000-0x401f
 *     Alias for PMU()_PMCEID0_EL0[63:32]
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmceid2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ce                    : 32; /**< [ 31:  0](RAZ) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t ce                    : 32; /**< [ 31:  0](RAZ) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmceid2_s cn; */
} bdk_pmux_pmceid2_t;

static inline uint64_t BDK_PMUX_PMCEID2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCEID2(unsigned long a)
{
    if (a<=47)
        return 0x87a008020e28ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCEID2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCEID2(a) bdk_pmux_pmceid2_t
#define bustype_BDK_PMUX_PMCEID2(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCEID2(a) "PMUX_PMCEID2"
#define busnum_BDK_PMUX_PMCEID2(a) (a)
#define arguments_BDK_PMUX_PMCEID2(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmceid3
 *
 * Performance Monitors Common Event Identification Register 3
 * Reserved for future indication of which common architectural
 *     and common microarchitectural feature events are implemented.
 *     These events are in the range 0x4020-0x403f
 *     Alias for PMU()_PMCEID1_EL0[63:32]
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmceid3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmceid3_s cn; */
} bdk_pmux_pmceid3_t;

static inline uint64_t BDK_PMUX_PMCEID3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCEID3(unsigned long a)
{
    if (a<=47)
        return 0x87a008020e2cll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCEID3", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCEID3(a) bdk_pmux_pmceid3_t
#define bustype_BDK_PMUX_PMCEID3(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCEID3(a) "PMUX_PMCEID3"
#define busnum_BDK_PMUX_PMCEID3(a) (a)
#define arguments_BDK_PMUX_PMCEID3(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcfgr
 *
 * Performance Monitors Configuration Register
 * Contains PMU-specific configuration data.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcfgr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t uen                   : 1;  /**< [ 19: 19](RO) User-mode Enable Register supported. PMUSERENR_EL0 is not
                                                                     visible in the external debug interface, so this bit is RES0. */
        uint32_t wt                    : 1;  /**< [ 18: 18](RO) This feature is not supported, so this bit is RES0. */
        uint32_t na                    : 1;  /**< [ 17: 17](RO) This feature is not supported, so this bit is RES0. */
        uint32_t ex                    : 1;  /**< [ 16: 16](RO) Export supported. Value is implementation defined.
                                                                 0 = PMU()_PMCR_EL0[X] is RES0.
                                                                 1 = PMU()_PMCR_EL0[X] is read/write.

                                                                 Not supported. */
        uint32_t ccd                   : 1;  /**< [ 15: 15](RO) Cycle counter has prescale. This is RES1 if AArch32 is
                                                                     supported at any EL, and RES0 otherwise.
                                                                 0 = PMU()_PMCR_EL0[D] is RES0.
                                                                 1 = PMU()_PMCR_EL0[D] is read/write. */
        uint32_t cc                    : 1;  /**< [ 14: 14](RO) Dedicated cycle counter (counter 31) supported. This bit is
                                                                     RES1. */
        uint32_t size                  : 6;  /**< [ 13:  8](RO) Size of counters. This field determines the spacing of
                                                                     counters in the memory-map.
                                                                 In v8-A the counters are at doubleword-aligned addresses, and
                                                                     the largest counter is 64-bits, so this field is 0x3f. */
        uint32_t n                     : 8;  /**< [  7:  0](RO) Number of counters implemented in addition to the cycle
                                                                     counter, PMU()_PMCCNTR_EL0. The maximum number of event counters is
                                                                     31, so bits[7:5] are always RES0.
                                                                 and so on up to 0x1F PMU()_PMCCNTR_EL0 and 31 event counters
                                                                     implemented.
                                                                 0x0 = Only PMU()_PMCCNTR_EL0 implemented.
                                                                 0x1 = PMU()_PMCCNTR_EL0 plus one event counter implemented. */
#else /* Word 0 - Little Endian */
        uint32_t n                     : 8;  /**< [  7:  0](RO) Number of counters implemented in addition to the cycle
                                                                     counter, PMU()_PMCCNTR_EL0. The maximum number of event counters is
                                                                     31, so bits[7:5] are always RES0.
                                                                 and so on up to 0x1F PMU()_PMCCNTR_EL0 and 31 event counters
                                                                     implemented.
                                                                 0x0 = Only PMU()_PMCCNTR_EL0 implemented.
                                                                 0x1 = PMU()_PMCCNTR_EL0 plus one event counter implemented. */
        uint32_t size                  : 6;  /**< [ 13:  8](RO) Size of counters. This field determines the spacing of
                                                                     counters in the memory-map.
                                                                 In v8-A the counters are at doubleword-aligned addresses, and
                                                                     the largest counter is 64-bits, so this field is 0x3f. */
        uint32_t cc                    : 1;  /**< [ 14: 14](RO) Dedicated cycle counter (counter 31) supported. This bit is
                                                                     RES1. */
        uint32_t ccd                   : 1;  /**< [ 15: 15](RO) Cycle counter has prescale. This is RES1 if AArch32 is
                                                                     supported at any EL, and RES0 otherwise.
                                                                 0 = PMU()_PMCR_EL0[D] is RES0.
                                                                 1 = PMU()_PMCR_EL0[D] is read/write. */
        uint32_t ex                    : 1;  /**< [ 16: 16](RO) Export supported. Value is implementation defined.
                                                                 0 = PMU()_PMCR_EL0[X] is RES0.
                                                                 1 = PMU()_PMCR_EL0[X] is read/write.

                                                                 Not supported. */
        uint32_t na                    : 1;  /**< [ 17: 17](RO) This feature is not supported, so this bit is RES0. */
        uint32_t wt                    : 1;  /**< [ 18: 18](RO) This feature is not supported, so this bit is RES0. */
        uint32_t uen                   : 1;  /**< [ 19: 19](RO) User-mode Enable Register supported. PMUSERENR_EL0 is not
                                                                     visible in the external debug interface, so this bit is RES0. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcfgr_s cn; */
} bdk_pmux_pmcfgr_t;

static inline uint64_t BDK_PMUX_PMCFGR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCFGR(unsigned long a)
{
    if (a<=47)
        return 0x87a008020e00ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCFGR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCFGR(a) bdk_pmux_pmcfgr_t
#define bustype_BDK_PMUX_PMCFGR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCFGR(a) "PMUX_PMCFGR"
#define busnum_BDK_PMUX_PMCFGR(a) (a)
#define arguments_BDK_PMUX_PMCFGR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcidr0
 *
 * Performance Monitors Component Identification Register 0
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prmbl_0               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x0D. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_0               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x0D. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcidr0_s cn; */
} bdk_pmux_pmcidr0_t;

static inline uint64_t BDK_PMUX_PMCIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCIDR0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020ff0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCIDR0(a) bdk_pmux_pmcidr0_t
#define bustype_BDK_PMUX_PMCIDR0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCIDR0(a) "PMUX_PMCIDR0"
#define busnum_BDK_PMUX_PMCIDR0(a) (a)
#define arguments_BDK_PMUX_PMCIDR0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcidr1
 *
 * Performance Monitors Component Identification Register 1
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. 0x9 = Debug component. */
        uint32_t prmbl_1               : 4;  /**< [  3:  0](RO) Preamble. RAZ. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_1               : 4;  /**< [  3:  0](RO) Preamble. RAZ. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. 0x9 = Debug component. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcidr1_s cn; */
} bdk_pmux_pmcidr1_t;

static inline uint64_t BDK_PMUX_PMCIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCIDR1(unsigned long a)
{
    if (a<=47)
        return 0x87a008020ff4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCIDR1(a) bdk_pmux_pmcidr1_t
#define bustype_BDK_PMUX_PMCIDR1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCIDR1(a) "PMUX_PMCIDR1"
#define busnum_BDK_PMUX_PMCIDR1(a) (a)
#define arguments_BDK_PMUX_PMCIDR1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcidr2
 *
 * Performance Monitors Component Identification Register 2
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prmbl_2               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x05. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_2               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x05. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcidr2_s cn; */
} bdk_pmux_pmcidr2_t;

static inline uint64_t BDK_PMUX_PMCIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCIDR2(unsigned long a)
{
    if (a<=47)
        return 0x87a008020ff8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCIDR2(a) bdk_pmux_pmcidr2_t
#define bustype_BDK_PMUX_PMCIDR2(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCIDR2(a) "PMUX_PMCIDR2"
#define busnum_BDK_PMUX_PMCIDR2(a) (a)
#define arguments_BDK_PMUX_PMCIDR2(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcidr3
 *
 * Performance Monitors Component Identification Register 3
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prmbl_3               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0xB1. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_3               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0xB1. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcidr3_s cn; */
} bdk_pmux_pmcidr3_t;

static inline uint64_t BDK_PMUX_PMCIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCIDR3(unsigned long a)
{
    if (a<=47)
        return 0x87a008020ffcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCIDR3(a) bdk_pmux_pmcidr3_t
#define bustype_BDK_PMUX_PMCIDR3(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCIDR3(a) "PMUX_PMCIDR3"
#define busnum_BDK_PMUX_PMCIDR3(a) (a)
#define arguments_BDK_PMUX_PMCIDR3(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcntenclr_el0
 *
 * Performance Monitors Count Enable Clear Register
 * Disables the Cycle Count Register, PMU()_PMCCNTR_EL0, and any
 *     implemented event counters PMEVCNTR<x>. Reading this register
 *     shows which counters are enabled.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcntenclr_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 disable bit. Disables the cycle counter register.
                                                                     Possible values are:
                                                                 0 = When read, means the cycle counter is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means the cycle counter is enabled. When written,
                                                                     disables the cycle counter. */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter disable bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values of each bit are:
                                                                 0 = When read, means that PMEVCNTR<x> is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> is enabled. When written,
                                                                     disables PMEVCNTR<x>. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter disable bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values of each bit are:
                                                                 0 = When read, means that PMEVCNTR<x> is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> is enabled. When written,
                                                                     disables PMEVCNTR<x>. */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 disable bit. Disables the cycle counter register.
                                                                     Possible values are:
                                                                 0 = When read, means the cycle counter is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means the cycle counter is enabled. When written,
                                                                     disables the cycle counter. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcntenclr_el0_s cn; */
} bdk_pmux_pmcntenclr_el0_t;

static inline uint64_t BDK_PMUX_PMCNTENCLR_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCNTENCLR_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020c20ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCNTENCLR_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCNTENCLR_EL0(a) bdk_pmux_pmcntenclr_el0_t
#define bustype_BDK_PMUX_PMCNTENCLR_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCNTENCLR_EL0(a) "PMUX_PMCNTENCLR_EL0"
#define busnum_BDK_PMUX_PMCNTENCLR_EL0(a) (a)
#define arguments_BDK_PMUX_PMCNTENCLR_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcntenset_el0
 *
 * Performance Monitors Count Enable Set Register
 * Enables the Cycle Count Register, PMU()_PMCCNTR_EL0, and any
 *     implemented event counters PMEVCNTR<x>. Reading this register
 *     shows which counters are enabled.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcntenset_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 enable bit. Enables the cycle counter register.
                                                                     Possible values are:
                                                                 0 = When read, means the cycle counter is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means the cycle counter is enabled. When written,
                                                                     enables the cycle counter. */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter enable bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values of each bit are:
                                                                 0 = When read, means that PMEVCNTR<x> is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> event counter is enabled.
                                                                     When written, enables PMEVCNTR<x>. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter enable bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values of each bit are:
                                                                 0 = When read, means that PMEVCNTR<x> is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> event counter is enabled.
                                                                     When written, enables PMEVCNTR<x>. */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 enable bit. Enables the cycle counter register.
                                                                     Possible values are:
                                                                 0 = When read, means the cycle counter is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means the cycle counter is enabled. When written,
                                                                     enables the cycle counter. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmcntenset_el0_s cn; */
} bdk_pmux_pmcntenset_el0_t;

static inline uint64_t BDK_PMUX_PMCNTENSET_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCNTENSET_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020c00ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCNTENSET_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCNTENSET_EL0(a) bdk_pmux_pmcntenset_el0_t
#define bustype_BDK_PMUX_PMCNTENSET_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCNTENSET_EL0(a) "PMUX_PMCNTENSET_EL0"
#define busnum_BDK_PMUX_PMCNTENSET_EL0(a) (a)
#define arguments_BDK_PMUX_PMCNTENSET_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmcr_el0
 *
 * Performance Monitors Control Register
 * Provides details of the Performance Monitors implementation,
 *     including the number of counters implemented, and configures
 *     and controls the counters.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmcr_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_7_31         : 25;
        uint32_t lc                    : 1;  /**< [  6:  6](R/W) Long cycle counter enable. Determines which PMU()_PMCCNTR_EL0 bit
                                                                     generates an overflow recorded by PMOVSR[31].
                                                                 ARM deprecates use of PMU()_PMCR_EL0[LC] = 0.
                                                                 0 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[31] from 1 to 0.
                                                                 1 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[63] from 1 to 0. */
        uint32_t dp                    : 1;  /**< [  5:  5](R/W) Disable cycle counter when event counting is prohibited. The
                                                                     possible values of this bit are:
                                                                 Event counting is prohibited when
                                                                     ProfilingProhibited(IsSecure(),PSTATE.EL) == TRUE. See the
                                                                     "Performance Monitors and Security" section of the ARMv8 Debug
                                                                     Specification, PRD03-PRDC-010486.
                                                                 This bit is RW.
                                                                 0 =  PMU()_PMCCNTR_EL0, if enabled, counts when event counting is
                                                                     prohibited.
                                                                 1 =  PMU()_PMCCNTR_EL0 does not count when event counting is prohibited. */
        uint32_t x                     : 1;  /**< [  4:  4](R/W) Enable export of events in an implementation defined event
                                                                     stream. The possible values of this bit are:
                                                                 This bit is used to permit events to be exported to another
                                                                     debug device, such as an OPTIONAL trace extension, over an
                                                                     event bus. If the implementation does not include such an
                                                                     event bus, this bit is RAZ/WI.
                                                                 This bit does not affect the generation of Performance
                                                                     Monitors overflow interrupt requests or signaling to a cross-
                                                                     trigger interface (CTI) that can be implemented as signals
                                                                     exported from the processor.
                                                                 If the implementation does not include an exported event
                                                                     stream, this bit is RAZ/WI. Otherwise this bit is RW.
                                                                 0 = Do not export events.
                                                                 1 = Export events where not prohibited. */
        uint32_t d_clk                 : 1;  /**< [  3:  3](R/W) Clock divider. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 If PMU()_PMCR_EL0[LC] == 1, this bit is ignored and the cycle counter
                                                                     counts every clock cycle.
                                                                 ARM deprecates use of PMU()_PMCR[D] = 1.
                                                                 0 = When enabled, PMU()_PMCCNTR_EL0 counts every clock cycle.
                                                                 1 = When enabled, PMU()_PMCCNTR_EL0 counts once every 64 clock cycles. */
        uint32_t c_rst                 : 1;  /**< [  2:  2](R/W) Cycle counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting PMU()_PMCCNTR_EL0 does not clear the PMU()_PMCCNTR_EL0 overflow
                                                                     bit to 0.
                                                                 0 = No action.
                                                                 1 = Reset PMU()_PMCCNTR_EL0 to zero. */
        uint32_t p                     : 1;  /**< [  1:  1](R/W) Event counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting the event counters does not clear any overflow bits
                                                                     to 0.
                                                                 0 = No action.
                                                                 1 = Reset all event counters, not including PMU()_PMCCNTR_EL0, to zero. */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 0 = All counters, including PMU()_PMCCNTR_EL0, are disabled.
                                                                 1 = All counters are enabled by PMU()_PMCNTENSET_EL0. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 0 = All counters, including PMU()_PMCCNTR_EL0, are disabled.
                                                                 1 = All counters are enabled by PMU()_PMCNTENSET_EL0. */
        uint32_t p                     : 1;  /**< [  1:  1](R/W) Event counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting the event counters does not clear any overflow bits
                                                                     to 0.
                                                                 0 = No action.
                                                                 1 = Reset all event counters, not including PMU()_PMCCNTR_EL0, to zero. */
        uint32_t c_rst                 : 1;  /**< [  2:  2](R/W) Cycle counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting PMU()_PMCCNTR_EL0 does not clear the PMU()_PMCCNTR_EL0 overflow
                                                                     bit to 0.
                                                                 0 = No action.
                                                                 1 = Reset PMU()_PMCCNTR_EL0 to zero. */
        uint32_t d_clk                 : 1;  /**< [  3:  3](R/W) Clock divider. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 If PMU()_PMCR_EL0[LC] == 1, this bit is ignored and the cycle counter
                                                                     counts every clock cycle.
                                                                 ARM deprecates use of PMU()_PMCR[D] = 1.
                                                                 0 = When enabled, PMU()_PMCCNTR_EL0 counts every clock cycle.
                                                                 1 = When enabled, PMU()_PMCCNTR_EL0 counts once every 64 clock cycles. */
        uint32_t x                     : 1;  /**< [  4:  4](R/W) Enable export of events in an implementation defined event
                                                                     stream. The possible values of this bit are:
                                                                 This bit is used to permit events to be exported to another
                                                                     debug device, such as an OPTIONAL trace extension, over an
                                                                     event bus. If the implementation does not include such an
                                                                     event bus, this bit is RAZ/WI.
                                                                 This bit does not affect the generation of Performance
                                                                     Monitors overflow interrupt requests or signaling to a cross-
                                                                     trigger interface (CTI) that can be implemented as signals
                                                                     exported from the processor.
                                                                 If the implementation does not include an exported event
                                                                     stream, this bit is RAZ/WI. Otherwise this bit is RW.
                                                                 0 = Do not export events.
                                                                 1 = Export events where not prohibited. */
        uint32_t dp                    : 1;  /**< [  5:  5](R/W) Disable cycle counter when event counting is prohibited. The
                                                                     possible values of this bit are:
                                                                 Event counting is prohibited when
                                                                     ProfilingProhibited(IsSecure(),PSTATE.EL) == TRUE. See the
                                                                     "Performance Monitors and Security" section of the ARMv8 Debug
                                                                     Specification, PRD03-PRDC-010486.
                                                                 This bit is RW.
                                                                 0 =  PMU()_PMCCNTR_EL0, if enabled, counts when event counting is
                                                                     prohibited.
                                                                 1 =  PMU()_PMCCNTR_EL0 does not count when event counting is prohibited. */
        uint32_t lc                    : 1;  /**< [  6:  6](R/W) Long cycle counter enable. Determines which PMU()_PMCCNTR_EL0 bit
                                                                     generates an overflow recorded by PMOVSR[31].
                                                                 ARM deprecates use of PMU()_PMCR_EL0[LC] = 0.
                                                                 0 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[31] from 1 to 0.
                                                                 1 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[63] from 1 to 0. */
        uint32_t reserved_7_31         : 25;
#endif /* Word 0 - End */
    } s;
    struct bdk_pmux_pmcr_el0_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_11_31        : 21;
        uint32_t reserved_7_10         : 4;
        uint32_t lc                    : 1;  /**< [  6:  6](R/W) Long cycle counter enable. Determines which PMU()_PMCCNTR_EL0 bit
                                                                     generates an overflow recorded by PMOVSR[31].
                                                                 ARM deprecates use of PMU()_PMCR_EL0[LC] = 0.
                                                                 0 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[31] from 1 to 0.
                                                                 1 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[63] from 1 to 0. */
        uint32_t dp                    : 1;  /**< [  5:  5](R/W) Disable cycle counter when event counting is prohibited. The
                                                                     possible values of this bit are:
                                                                 Event counting is prohibited when
                                                                     ProfilingProhibited(IsSecure(),PSTATE.EL) == TRUE. See the
                                                                     "Performance Monitors and Security" section of the ARMv8 Debug
                                                                     Specification, PRD03-PRDC-010486.
                                                                 This bit is RW.
                                                                 0 =  PMU()_PMCCNTR_EL0, if enabled, counts when event counting is
                                                                     prohibited.
                                                                 1 =  PMU()_PMCCNTR_EL0 does not count when event counting is prohibited. */
        uint32_t x                     : 1;  /**< [  4:  4](R/W) Enable export of events in an implementation defined event
                                                                     stream. The possible values of this bit are:
                                                                 This bit is used to permit events to be exported to another
                                                                     debug device, such as an OPTIONAL trace extension, over an
                                                                     event bus. If the implementation does not include such an
                                                                     event bus, this bit is RAZ/WI.
                                                                 This bit does not affect the generation of Performance
                                                                     Monitors overflow interrupt requests or signaling to a cross-
                                                                     trigger interface (CTI) that can be implemented as signals
                                                                     exported from the processor.
                                                                 If the implementation does not include an exported event
                                                                     stream, this bit is RAZ/WI. Otherwise this bit is RW.
                                                                 0 = Do not export events.
                                                                 1 = Export events where not prohibited. */
        uint32_t d_clk                 : 1;  /**< [  3:  3](R/W) Clock divider. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 If PMU()_PMCR_EL0[LC] == 1, this bit is ignored and the cycle counter
                                                                     counts every clock cycle.
                                                                 ARM deprecates use of PMU()_PMCR[D] = 1.
                                                                 0 = When enabled, PMU()_PMCCNTR_EL0 counts every clock cycle.
                                                                 1 = When enabled, PMU()_PMCCNTR_EL0 counts once every 64 clock cycles. */
        uint32_t c_rst                 : 1;  /**< [  2:  2](R/W) Cycle counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting PMU()_PMCCNTR_EL0 does not clear the PMU()_PMCCNTR_EL0 overflow
                                                                     bit to 0.
                                                                 0 = No action.
                                                                 1 = Reset PMU()_PMCCNTR_EL0 to zero. */
        uint32_t p                     : 1;  /**< [  1:  1](R/W) Event counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting the event counters does not clear any overflow bits
                                                                     to 0.
                                                                 0 = No action.
                                                                 1 = Reset all event counters, not including PMU()_PMCCNTR_EL0, to zero. */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 0 = All counters, including PMU()_PMCCNTR_EL0, are disabled.
                                                                 1 = All counters are enabled by PMU()_PMCNTENSET_EL0. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 0 = All counters, including PMU()_PMCCNTR_EL0, are disabled.
                                                                 1 = All counters are enabled by PMU()_PMCNTENSET_EL0. */
        uint32_t p                     : 1;  /**< [  1:  1](R/W) Event counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting the event counters does not clear any overflow bits
                                                                     to 0.
                                                                 0 = No action.
                                                                 1 = Reset all event counters, not including PMU()_PMCCNTR_EL0, to zero. */
        uint32_t c_rst                 : 1;  /**< [  2:  2](R/W) Cycle counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting PMU()_PMCCNTR_EL0 does not clear the PMU()_PMCCNTR_EL0 overflow
                                                                     bit to 0.
                                                                 0 = No action.
                                                                 1 = Reset PMU()_PMCCNTR_EL0 to zero. */
        uint32_t d_clk                 : 1;  /**< [  3:  3](R/W) Clock divider. The possible values of this bit are:
                                                                 This bit is RW.
                                                                 If PMU()_PMCR_EL0[LC] == 1, this bit is ignored and the cycle counter
                                                                     counts every clock cycle.
                                                                 ARM deprecates use of PMU()_PMCR[D] = 1.
                                                                 0 = When enabled, PMU()_PMCCNTR_EL0 counts every clock cycle.
                                                                 1 = When enabled, PMU()_PMCCNTR_EL0 counts once every 64 clock cycles. */
        uint32_t x                     : 1;  /**< [  4:  4](R/W) Enable export of events in an implementation defined event
                                                                     stream. The possible values of this bit are:
                                                                 This bit is used to permit events to be exported to another
                                                                     debug device, such as an OPTIONAL trace extension, over an
                                                                     event bus. If the implementation does not include such an
                                                                     event bus, this bit is RAZ/WI.
                                                                 This bit does not affect the generation of Performance
                                                                     Monitors overflow interrupt requests or signaling to a cross-
                                                                     trigger interface (CTI) that can be implemented as signals
                                                                     exported from the processor.
                                                                 If the implementation does not include an exported event
                                                                     stream, this bit is RAZ/WI. Otherwise this bit is RW.
                                                                 0 = Do not export events.
                                                                 1 = Export events where not prohibited. */
        uint32_t dp                    : 1;  /**< [  5:  5](R/W) Disable cycle counter when event counting is prohibited. The
                                                                     possible values of this bit are:
                                                                 Event counting is prohibited when
                                                                     ProfilingProhibited(IsSecure(),PSTATE.EL) == TRUE. See the
                                                                     "Performance Monitors and Security" section of the ARMv8 Debug
                                                                     Specification, PRD03-PRDC-010486.
                                                                 This bit is RW.
                                                                 0 =  PMU()_PMCCNTR_EL0, if enabled, counts when event counting is
                                                                     prohibited.
                                                                 1 =  PMU()_PMCCNTR_EL0 does not count when event counting is prohibited. */
        uint32_t lc                    : 1;  /**< [  6:  6](R/W) Long cycle counter enable. Determines which PMU()_PMCCNTR_EL0 bit
                                                                     generates an overflow recorded by PMOVSR[31].
                                                                 ARM deprecates use of PMU()_PMCR_EL0[LC] = 0.
                                                                 0 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[31] from 1 to 0.
                                                                 1 = Cycle counter overflow on increment that changes
                                                                     PMU()_PMCCNTR_EL0[63] from 1 to 0. */
        uint32_t reserved_7_10         : 4;
        uint32_t reserved_11_31        : 21;
#endif /* Word 0 - End */
    } cn;
} bdk_pmux_pmcr_el0_t;

static inline uint64_t BDK_PMUX_PMCR_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMCR_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020e04ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMCR_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMCR_EL0(a) bdk_pmux_pmcr_el0_t
#define bustype_BDK_PMUX_PMCR_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMCR_EL0(a) "PMUX_PMCR_EL0"
#define busnum_BDK_PMUX_PMCR_EL0(a) (a)
#define arguments_BDK_PMUX_PMCR_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmdevaff0
 *
 * Performance Monitors Device Affinity Register 0
 * Copy of the low half of the processor MPIDR_EL1 register that
 *     allows a debugger to determine which processor in a
 *     multiprocessor system the Performance Monitor component
 *     relates to.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmdevaff0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](RO) MPIDR_EL1 low half
                                                                 MPIDR_EL1 low half. Read-only copy of the low half of
                                                                    MPIDR_EL1, as seen from the highest implemented exception
                                                                    level. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](RO) MPIDR_EL1 low half
                                                                 MPIDR_EL1 low half. Read-only copy of the low half of
                                                                    MPIDR_EL1, as seen from the highest implemented exception
                                                                    level. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmdevaff0_s cn; */
} bdk_pmux_pmdevaff0_t;

static inline uint64_t BDK_PMUX_PMDEVAFF0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMDEVAFF0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fa8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMDEVAFF0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMDEVAFF0(a) bdk_pmux_pmdevaff0_t
#define bustype_BDK_PMUX_PMDEVAFF0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMDEVAFF0(a) "PMUX_PMDEVAFF0"
#define busnum_BDK_PMUX_PMDEVAFF0(a) (a)
#define arguments_BDK_PMUX_PMDEVAFF0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmdevaff1
 *
 * Performance Monitors Device Affinity Register 1
 * Copy of the high half of the processor MPIDR_EL1 register that
 *     allows a debugger to determine which processor in a
 *     multiprocessor system the Performance Monitor component
 *     relates to.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmdevaff1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](RO) MPIDR_EL1 high half
                                                                 MPIDR_EL1 high half. Read-only copy of the high half of
                                                                    MPIDR_EL1, as seen from the highest implemented exception
                                                                    level. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](RO) MPIDR_EL1 high half
                                                                 MPIDR_EL1 high half. Read-only copy of the high half of
                                                                    MPIDR_EL1, as seen from the highest implemented exception
                                                                    level. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmdevaff1_s cn; */
} bdk_pmux_pmdevaff1_t;

static inline uint64_t BDK_PMUX_PMDEVAFF1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMDEVAFF1(unsigned long a)
{
    if (a<=47)
        return 0x87a008020facll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMDEVAFF1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMDEVAFF1(a) bdk_pmux_pmdevaff1_t
#define bustype_BDK_PMUX_PMDEVAFF1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMDEVAFF1(a) "PMUX_PMDEVAFF1"
#define busnum_BDK_PMUX_PMDEVAFF1(a) (a)
#define arguments_BDK_PMUX_PMDEVAFF1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmdevarch
 *
 * Performance Monitors Device Architecture Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmdevarch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t architect             : 11; /**< [ 31: 21](RO) Defines the architecture of the component. For Performance
                                                                     Monitors, this is ARM Limited.

                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.

                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
        uint32_t present               : 1;  /**< [ 20: 20](RO) When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
        uint32_t revision              : 4;  /**< [ 19: 16](RO) Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For Performance Monitors, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
        uint32_t archid                : 16; /**< [ 15:  0](RO) Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For Performance Monitors:
                                                                  Bits [15:12] are the architecture version, 0x2.
                                                                  Bits [11:0] are the architecture part number, 0xA16.

                                                                 This corresponds to Performance Monitors architecture version
                                                                     PMUv3. */
#else /* Word 0 - Little Endian */
        uint32_t archid                : 16; /**< [ 15:  0](RO) Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For Performance Monitors:
                                                                  Bits [15:12] are the architecture version, 0x2.
                                                                  Bits [11:0] are the architecture part number, 0xA16.

                                                                 This corresponds to Performance Monitors architecture version
                                                                     PMUv3. */
        uint32_t revision              : 4;  /**< [ 19: 16](RO) Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For Performance Monitors, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
        uint32_t present               : 1;  /**< [ 20: 20](RO) When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
        uint32_t architect             : 11; /**< [ 31: 21](RO) Defines the architecture of the component. For Performance
                                                                     Monitors, this is ARM Limited.

                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.

                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmdevarch_s cn; */
} bdk_pmux_pmdevarch_t;

static inline uint64_t BDK_PMUX_PMDEVARCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMDEVARCH(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fbcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMDEVARCH", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMDEVARCH(a) bdk_pmux_pmdevarch_t
#define bustype_BDK_PMUX_PMDEVARCH(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMDEVARCH(a) "PMUX_PMDEVARCH"
#define busnum_BDK_PMUX_PMDEVARCH(a) (a)
#define arguments_BDK_PMUX_PMDEVARCH(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmdevtype
 *
 * Performance Monitors Device Type Register
 * Indicates to a debugger that this component is part of a
 *     processor's performance monitor interface.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmdevtype_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t sub                   : 4;  /**< [  7:  4](RO) Subtype. Must read as 0x1. */
        uint32_t major                 : 4;  /**< [  3:  0](RO) Major type. Must read as 0x6. */
#else /* Word 0 - Little Endian */
        uint32_t major                 : 4;  /**< [  3:  0](RO) Major type. Must read as 0x6. */
        uint32_t sub                   : 4;  /**< [  7:  4](RO) Subtype. Must read as 0x1. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmdevtype_s cn; */
} bdk_pmux_pmdevtype_t;

static inline uint64_t BDK_PMUX_PMDEVTYPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMDEVTYPE(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fccll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMDEVTYPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMDEVTYPE(a) bdk_pmux_pmdevtype_t
#define bustype_BDK_PMUX_PMDEVTYPE(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMDEVTYPE(a) "PMUX_PMDEVTYPE"
#define busnum_BDK_PMUX_PMDEVTYPE(a) (a)
#define arguments_BDK_PMUX_PMDEVTYPE(a) (a),-1,-1,-1

/**
 * Register (DAB) pmu#_pmevcntr#_el0
 *
 * Performance Monitors Event Count Registers
 * This register contains the event counters.
 */
typedef union
{
    uint64_t u;
    struct bdk_pmux_pmevcntrx_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Event counter. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Event counter. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmevcntrx_el0_s cn; */
} bdk_pmux_pmevcntrx_el0_t;

static inline uint64_t BDK_PMUX_PMEVCNTRX_EL0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMEVCNTRX_EL0(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008020000ll + 0x80000ll * ((a) & 0x3f) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("PMUX_PMEVCNTRX_EL0", 2, a, b, 0, 0);
}

#define typedef_BDK_PMUX_PMEVCNTRX_EL0(a,b) bdk_pmux_pmevcntrx_el0_t
#define bustype_BDK_PMUX_PMEVCNTRX_EL0(a,b) BDK_CSR_TYPE_DAB
#define basename_BDK_PMUX_PMEVCNTRX_EL0(a,b) "PMUX_PMEVCNTRX_EL0"
#define busnum_BDK_PMUX_PMEVCNTRX_EL0(a,b) (a)
#define arguments_BDK_PMUX_PMEVCNTRX_EL0(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) pmu#_pmevtyper#_el0
 *
 * Performance Monitors Event Type Registers
 * This register contains the event counters.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmevtyperx_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t reserved_16_25        : 10;
        uint32_t evtcount              : 16; /**< [ 15:  0](R/W) Event to count. */
#else /* Word 0 - Little Endian */
        uint32_t evtcount              : 16; /**< [ 15:  0](R/W) Event to count. */
        uint32_t reserved_16_25        : 10;
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
#endif /* Word 0 - End */
    } s;
    struct bdk_pmux_pmevtyperx_el0_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t reserved_10_25        : 16;
        uint32_t evtcount              : 10; /**< [  9:  0](R/W) Event to count. */
#else /* Word 0 - Little Endian */
        uint32_t evtcount              : 10; /**< [  9:  0](R/W) Event to count. */
        uint32_t reserved_10_25        : 16;
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pmux_pmevtyperx_el0_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t reserved_16_25        : 10;
        uint32_t evtcount              : 16; /**< [ 15:  0](R/W) Event to count. The event number of the event that is counted
                                                                     by event counter PMU()_PMEVCNTR()_EL0.
                                                                 Enumerated by PMU_PERF_E.

                                                                 Software must program this field with an event defined by the
                                                                     processor or a common event defined by the architecture.
                                                                 If evtCount is programmed to an event that is reserved or not
                                                                     implemented, the behavior depends on the event type.
                                                                 For common architectural and microarchitectural events:
                                                                  No events are counted.
                                                                  The value read back on evtCount is the value written.
                                                                 For implementation defined events:
                                                                  It is UNPREDICTABLE what event, if any, is counted.
                                                                     UNPREDICTABLE in this case means the event must not expose
                                                                     privileged information.
                                                                  The value read back on evtCount is an UNKNOWN value with the
                                                                     same effect.
                                                                 ARM recommends that the behavior across a family of
                                                                     implementations is defined such that if a given implementation
                                                                     does not include an event from a set of common implementation
                                                                     defined events, then no event is counted and the value read
                                                                     back on evtCount is the value written. */
#else /* Word 0 - Little Endian */
        uint32_t evtcount              : 16; /**< [ 15:  0](R/W) Event to count. The event number of the event that is counted
                                                                     by event counter PMU()_PMEVCNTR()_EL0.
                                                                 Enumerated by PMU_PERF_E.

                                                                 Software must program this field with an event defined by the
                                                                     processor or a common event defined by the architecture.
                                                                 If evtCount is programmed to an event that is reserved or not
                                                                     implemented, the behavior depends on the event type.
                                                                 For common architectural and microarchitectural events:
                                                                  No events are counted.
                                                                  The value read back on evtCount is the value written.
                                                                 For implementation defined events:
                                                                  It is UNPREDICTABLE what event, if any, is counted.
                                                                     UNPREDICTABLE in this case means the event must not expose
                                                                     privileged information.
                                                                  The value read back on evtCount is an UNKNOWN value with the
                                                                     same effect.
                                                                 ARM recommends that the behavior across a family of
                                                                     implementations is defined such that if a given implementation
                                                                     does not include an event from a set of common implementation
                                                                     defined events, then no event is counted and the value read
                                                                     back on evtCount is the value written. */
        uint32_t reserved_16_25        : 10;
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pmux_pmevtyperx_el0_cn81xx cn83xx; */
    struct bdk_pmux_pmevtyperx_el0_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t reserved_16_25        : 10;
        uint32_t evtcount              : 16; /**< [ 15:  0](R/W) Event to count. The event number of the event that is counted
                                                                     by event counter PMU()_PMEVCNTR()_EL0.
                                                                 Enumerated by PMU_PERF_E.

                                                                 Software must program this field with an event defined by the
                                                                     processor or a common event defined by the architecture.
                                                                 If evtCount is programmed to an event that is reserved or not
                                                                     implemented, the behavior depends on the event type.
                                                                 For common architectural and microarchitectural events:
                                                                  No events are counted.
                                                                  The value read back on evtCount is the value written.
                                                                 For implementation defined events:
                                                                  It is UNPREDICTABLE what event, if any, is counted.
                                                                     UNPREDICTABLE in this case means the event must not expose
                                                                     privileged information.
                                                                  The value read back on evtCount is an UNKNOWN value with the
                                                                     same effect.
                                                                 ARM recommends that the behavior across a family of
                                                                     implementations is defined such that if a given implementation
                                                                     does not include an event from a set of common implementation
                                                                     defined events, then no event is counted and the value read
                                                                     back on evtCount is the value written.
                                                                 Changed in Pass 2. */
#else /* Word 0 - Little Endian */
        uint32_t evtcount              : 16; /**< [ 15:  0](R/W) Event to count. The event number of the event that is counted
                                                                     by event counter PMU()_PMEVCNTR()_EL0.
                                                                 Enumerated by PMU_PERF_E.

                                                                 Software must program this field with an event defined by the
                                                                     processor or a common event defined by the architecture.
                                                                 If evtCount is programmed to an event that is reserved or not
                                                                     implemented, the behavior depends on the event type.
                                                                 For common architectural and microarchitectural events:
                                                                  No events are counted.
                                                                  The value read back on evtCount is the value written.
                                                                 For implementation defined events:
                                                                  It is UNPREDICTABLE what event, if any, is counted.
                                                                     UNPREDICTABLE in this case means the event must not expose
                                                                     privileged information.
                                                                  The value read back on evtCount is an UNKNOWN value with the
                                                                     same effect.
                                                                 ARM recommends that the behavior across a family of
                                                                     implementations is defined such that if a given implementation
                                                                     does not include an event from a set of common implementation
                                                                     defined events, then no event is counted and the value read
                                                                     back on evtCount is the value written.
                                                                 Changed in Pass 2. */
        uint32_t reserved_16_25        : 10;
        uint32_t m                     : 1;  /**< [ 26: 26](R/W) Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
        uint32_t nsh                   : 1;  /**< [ 27: 27](R/W) Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
        uint32_t nsu                   : 1;  /**< [ 28: 28](R/W) Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     Non-secure EL0 are counted.
                                                                 Otherwise, events in Non-secure EL0 are not counted. */
        uint32_t nsk                   : 1;  /**< [ 29: 29](R/W) Non-secure kernel modes filtering bit. Controls counting in
                                                                     Non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Non-secure EL1 are counted.
                                                                 Otherwise, events in Non-secure EL1 are not counted. */
        uint32_t u                     : 1;  /**< [ 30: 30](R/W) EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in Non-secure EL0 is further
                                                                     controlled by the NSU bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
        uint32_t p                     : 1;  /**< [ 31: 31](R/W) EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in Non-secure EL1 is further
                                                                     controlled by the NSK bit. The possible values of this bit
                                                                     are:
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pmux_pmevtyperx_el0_t;

static inline uint64_t BDK_PMUX_PMEVTYPERX_EL0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMEVTYPERX_EL0(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008020400ll + 0x80000ll * ((a) & 0x3f) + 4ll * ((b) & 0x7);
    __bdk_csr_fatal("PMUX_PMEVTYPERX_EL0", 2, a, b, 0, 0);
}

#define typedef_BDK_PMUX_PMEVTYPERX_EL0(a,b) bdk_pmux_pmevtyperx_el0_t
#define bustype_BDK_PMUX_PMEVTYPERX_EL0(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMEVTYPERX_EL0(a,b) "PMUX_PMEVTYPERX_EL0"
#define busnum_BDK_PMUX_PMEVTYPERX_EL0(a,b) (a)
#define arguments_BDK_PMUX_PMEVTYPERX_EL0(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) pmu#_pmintenclr_el1
 *
 * Performance Monitors Interrupt Enable Clear Register
 * Disables the generation of interrupt requests on overflows
 *     from the Cycle Count Register, PMU()_PMCCNTR_EL0, and the event
 *     counters PMEVCNTR<n>_EL0. Reading the register shows which
 *     overflow interrupt requests are enabled.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmintenclr_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow interrupt request disable bit. Possible
                                                                     values are:
                                                                 0 = When read, means the cycle counter overflow interrupt request
                                                                     is disabled. When written, has no effect.
                                                                 1 = When read, means the cycle counter overflow interrupt request
                                                                     is enabled. When written, disables the cycle count overflow
                                                                     interrupt request. */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow interrupt request disable bit for
                                                                     PMEVCNTR<x>_EL0.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values are:
                                                                 0 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is disabled. When written, has no effect.
                                                                 1 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is enabled. When written, disables the
                                                                     PMEVCNTR<x>_EL0 interrupt request. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow interrupt request disable bit for
                                                                     PMEVCNTR<x>_EL0.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values are:
                                                                 0 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is disabled. When written, has no effect.
                                                                 1 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is enabled. When written, disables the
                                                                     PMEVCNTR<x>_EL0 interrupt request. */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow interrupt request disable bit. Possible
                                                                     values are:
                                                                 0 = When read, means the cycle counter overflow interrupt request
                                                                     is disabled. When written, has no effect.
                                                                 1 = When read, means the cycle counter overflow interrupt request
                                                                     is enabled. When written, disables the cycle count overflow
                                                                     interrupt request. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmintenclr_el1_s cn; */
} bdk_pmux_pmintenclr_el1_t;

static inline uint64_t BDK_PMUX_PMINTENCLR_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMINTENCLR_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008020c60ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMINTENCLR_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMINTENCLR_EL1(a) bdk_pmux_pmintenclr_el1_t
#define bustype_BDK_PMUX_PMINTENCLR_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMINTENCLR_EL1(a) "PMUX_PMINTENCLR_EL1"
#define busnum_BDK_PMUX_PMINTENCLR_EL1(a) (a)
#define arguments_BDK_PMUX_PMINTENCLR_EL1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmintenset_el1
 *
 * Performance Monitors Interrupt Enable Set Register
 * Enables the generation of interrupt requests on overflows from
 *     the Cycle Count Register, PMU()_PMCCNTR_EL0, and the event counters
 *     PMEVCNTR<n>_EL0. Reading the register shows which overflow
 *     interrupt requests are enabled.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmintenset_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow interrupt request enable bit. Possible
                                                                     values are:
                                                                 0 = When read, means the cycle counter overflow interrupt request
                                                                     is disabled. When written, has no effect.
                                                                 1 = When read, means the cycle counter overflow interrupt request
                                                                     is enabled. When written, enables the cycle count overflow
                                                                     interrupt request. */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow interrupt request enable bit for
                                                                     PMEVCNTR<x>_EL0.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values are:
                                                                 0 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is disabled. When written, has no effect.
                                                                 1 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is enabled. When written, enables the
                                                                     PMEVCNTR<x>_EL0 interrupt request. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow interrupt request enable bit for
                                                                     PMEVCNTR<x>_EL0.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values are:
                                                                 0 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is disabled. When written, has no effect.
                                                                 1 = When read, means that the PMEVCNTR<x>_EL0 event counter
                                                                     interrupt request is enabled. When written, enables the
                                                                     PMEVCNTR<x>_EL0 interrupt request. */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow interrupt request enable bit. Possible
                                                                     values are:
                                                                 0 = When read, means the cycle counter overflow interrupt request
                                                                     is disabled. When written, has no effect.
                                                                 1 = When read, means the cycle counter overflow interrupt request
                                                                     is enabled. When written, enables the cycle count overflow
                                                                     interrupt request. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmintenset_el1_s cn; */
} bdk_pmux_pmintenset_el1_t;

static inline uint64_t BDK_PMUX_PMINTENSET_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMINTENSET_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008020c40ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMINTENSET_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMINTENSET_EL1(a) bdk_pmux_pmintenset_el1_t
#define bustype_BDK_PMUX_PMINTENSET_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMINTENSET_EL1(a) "PMUX_PMINTENSET_EL1"
#define busnum_BDK_PMUX_PMINTENSET_EL1(a) (a)
#define arguments_BDK_PMUX_PMINTENSET_EL1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmitctrl
 *
 * Performance Monitors Integration Mode Control Register
 * Enables the Performance Monitors to switch from default mode
 *     into integration mode, where test software can control
 *     directly the inputs and outputs of the processor, for
 *     integration testing or topology detection.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmitctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t ime                   : 1;  /**< [  0:  0](RO) Integration mode enable. When IME == 1, the device reverts to
                                                                     an integration mode to enable integration testing or topology
                                                                     detection. The integration mode behavior is implementation
                                                                     defined.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled. */
#else /* Word 0 - Little Endian */
        uint32_t ime                   : 1;  /**< [  0:  0](RO) Integration mode enable. When IME == 1, the device reverts to
                                                                     an integration mode to enable integration testing or topology
                                                                     detection. The integration mode behavior is implementation
                                                                     defined.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmitctrl_s cn; */
} bdk_pmux_pmitctrl_t;

static inline uint64_t BDK_PMUX_PMITCTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMITCTRL(unsigned long a)
{
    if (a<=47)
        return 0x87a008020f00ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMITCTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMITCTRL(a) bdk_pmux_pmitctrl_t
#define bustype_BDK_PMUX_PMITCTRL(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMITCTRL(a) "PMUX_PMITCTRL"
#define busnum_BDK_PMUX_PMITCTRL(a) (a)
#define arguments_BDK_PMUX_PMITCTRL(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmlar
 *
 * Performance Monitors Lock Access Register
 * Allows or disallows access to the Performance Monitors
 *     registers through a memory-mapped interface.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmlar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t key                   : 32; /**< [ 31:  0](WO) Lock access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface. */
#else /* Word 0 - Little Endian */
        uint32_t key                   : 32; /**< [ 31:  0](WO) Lock access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmlar_s cn; */
} bdk_pmux_pmlar_t;

static inline uint64_t BDK_PMUX_PMLAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMLAR(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fb0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMLAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMLAR(a) bdk_pmux_pmlar_t
#define bustype_BDK_PMUX_PMLAR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMLAR(a) "PMUX_PMLAR"
#define busnum_BDK_PMUX_PMLAR(a) (a)
#define arguments_BDK_PMUX_PMLAR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmlsr
 *
 * Performance Monitors Lock Status Register
 * Indicates the current status of the software lock for
 *     Performance Monitors registers.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmlsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t ntt                   : 1;  /**< [  2:  2](RO) Not thirty-two bit access required. RAZ. */
        uint32_t slk                   : 1;  /**< [  1:  1](RO/H) Software lock status for this component. For an access to LSR
                                                                     that is not a memory-mapped access, or when the software lock
                                                                     is not implemented, this field is RES0.
                                                                 On External debug reset, the field resets to 1.
                                                                 For memory-mapped accesses when the software lock is
                                                                     implemented, possible values of this field are:
                                                                 0 = Lock clear. Writes are permitted to this component's
                                                                     registers.
                                                                 1 = Lock set. Writes to this component's registers are ignored,
                                                                     and reads have no side effects. */
        uint32_t sli                   : 1;  /**< [  0:  0](RO) Software lock implemented. For an access to LSR that is not a
                                                                     memory-mapped access, this field is RAZ. For memory-mapped
                                                                     accesses, the value of this field is implementation defined.
                                                                     Permitted values are:
                                                                 0 = Software lock not implemented or not memory-mapped access.
                                                                 1 = Software lock implemented and memory-mapped access. */
#else /* Word 0 - Little Endian */
        uint32_t sli                   : 1;  /**< [  0:  0](RO) Software lock implemented. For an access to LSR that is not a
                                                                     memory-mapped access, this field is RAZ. For memory-mapped
                                                                     accesses, the value of this field is implementation defined.
                                                                     Permitted values are:
                                                                 0 = Software lock not implemented or not memory-mapped access.
                                                                 1 = Software lock implemented and memory-mapped access. */
        uint32_t slk                   : 1;  /**< [  1:  1](RO/H) Software lock status for this component. For an access to LSR
                                                                     that is not a memory-mapped access, or when the software lock
                                                                     is not implemented, this field is RES0.
                                                                 On External debug reset, the field resets to 1.
                                                                 For memory-mapped accesses when the software lock is
                                                                     implemented, possible values of this field are:
                                                                 0 = Lock clear. Writes are permitted to this component's
                                                                     registers.
                                                                 1 = Lock set. Writes to this component's registers are ignored,
                                                                     and reads have no side effects. */
        uint32_t ntt                   : 1;  /**< [  2:  2](RO) Not thirty-two bit access required. RAZ. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmlsr_s cn; */
} bdk_pmux_pmlsr_t;

static inline uint64_t BDK_PMUX_PMLSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMLSR(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fb4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMLSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMLSR(a) bdk_pmux_pmlsr_t
#define bustype_BDK_PMUX_PMLSR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMLSR(a) "PMUX_PMLSR"
#define busnum_BDK_PMUX_PMLSR(a) (a)
#define arguments_BDK_PMUX_PMLSR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmovsclr_el0
 *
 * Performance Monitors Overflow Flag Status Clear Register
 * Contains the state of the overflow bit for the Cycle Count
 *     Register, PMU()_PMCCNTR_EL0, and each of the implemented event
 *     counters PMEVCNTR<x>. Writing to this register clears these
 *     bits.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmovsclr_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow bit. Possible values are:
                                                                 PMU()_PMCR_EL0[LC] is used to control from which bit of PMU()_PMCCNTR_EL0
                                                                     (bit 31 or bit 63) an overflow is detected.
                                                                 0 = When read, means the cycle counter has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means the cycle counter has overflowed. When
                                                                     written, clears the overflow bit to 0. */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow clear bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values of each bit are:
                                                                 0 = When read, means that PMEVCNTR<x> has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> has overflowed. When
                                                                     written, clears the PMEVCNTR<x> overflow bit to 0. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow clear bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values of each bit are:
                                                                 0 = When read, means that PMEVCNTR<x> has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> has overflowed. When
                                                                     written, clears the PMEVCNTR<x> overflow bit to 0. */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow bit. Possible values are:
                                                                 PMU()_PMCR_EL0[LC] is used to control from which bit of PMU()_PMCCNTR_EL0
                                                                     (bit 31 or bit 63) an overflow is detected.
                                                                 0 = When read, means the cycle counter has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means the cycle counter has overflowed. When
                                                                     written, clears the overflow bit to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmovsclr_el0_s cn; */
} bdk_pmux_pmovsclr_el0_t;

static inline uint64_t BDK_PMUX_PMOVSCLR_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMOVSCLR_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020c80ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMOVSCLR_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMOVSCLR_EL0(a) bdk_pmux_pmovsclr_el0_t
#define bustype_BDK_PMUX_PMOVSCLR_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMOVSCLR_EL0(a) "PMUX_PMOVSCLR_EL0"
#define busnum_BDK_PMUX_PMOVSCLR_EL0(a) (a)
#define arguments_BDK_PMUX_PMOVSCLR_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmovsset_el0
 *
 * Performance Monitors Overflow Flag Status Set Register
 * Sets the state of the overflow bit for the Cycle Count
 *     Register, PMU()_PMCCNTR_EL0, and each of the implemented event
 *     counters PMEVCNTR<x>.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmovsset_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow bit. Possible values are:
                                                                 0 = When read, means the cycle counter has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means the cycle counter has overflowed. When
                                                                     written, sets the overflow bit to 1. */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow set bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values are:
                                                                 0 = When read, means that PMEVCNTR<x> has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> has overflowed. When
                                                                     written, sets the PMEVCNTR<x> overflow bit to 1. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](R/W) Event counter overflow set bit for PMEVCNTR<x>.
                                                                 N is the value in PMU()_PMCR_EL0[N]. Bits [30:N] are RAZ/WI.
                                                                 Possible values are:
                                                                 0 = When read, means that PMEVCNTR<x> has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means that PMEVCNTR<x> has overflowed. When
                                                                     written, sets the PMEVCNTR<x> overflow bit to 1. */
        uint32_t c_set                 : 1;  /**< [ 31: 31](R/W) PMU()_PMCCNTR_EL0 overflow bit. Possible values are:
                                                                 0 = When read, means the cycle counter has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means the cycle counter has overflowed. When
                                                                     written, sets the overflow bit to 1. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmovsset_el0_s cn; */
} bdk_pmux_pmovsset_el0_t;

static inline uint64_t BDK_PMUX_PMOVSSET_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMOVSSET_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020cc0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMOVSSET_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMOVSSET_EL0(a) bdk_pmux_pmovsset_el0_t
#define bustype_BDK_PMUX_PMOVSSET_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMOVSSET_EL0(a) "PMUX_PMOVSSET_EL0"
#define busnum_BDK_PMUX_PMOVSSET_EL0(a) (a)
#define arguments_BDK_PMUX_PMOVSSET_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr0
 *
 * Performance Monitors Peripheral Identification Register 0
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t part_0                : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::PMU. */
#else /* Word 0 - Little Endian */
        uint32_t part_0                : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::PMU. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr0_s cn; */
} bdk_pmux_pmpidr0_t;

static inline uint64_t BDK_PMUX_PMPIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fe0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR0(a) bdk_pmux_pmpidr0_t
#define bustype_BDK_PMUX_PMPIDR0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR0(a) "PMUX_PMPIDR0"
#define busnum_BDK_PMUX_PMPIDR0(a) (a)
#define arguments_BDK_PMUX_PMPIDR0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr1
 *
 * Performance Monitors Peripheral Identification Register 1
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t des_0                 : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t part_1                : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t part_1                : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t des_0                 : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr1_s cn; */
} bdk_pmux_pmpidr1_t;

static inline uint64_t BDK_PMUX_PMPIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR1(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fe4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR1(a) bdk_pmux_pmpidr1_t
#define bustype_BDK_PMUX_PMPIDR1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR1(a) "PMUX_PMPIDR1"
#define busnum_BDK_PMUX_PMPIDR1(a) (a)
#define arguments_BDK_PMUX_PMPIDR1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr2
 *
 * Performance Monitors Peripheral Identification Register 2
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t des_1                 : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t des_1                 : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision, as assigned by ARM. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr2_s cn; */
} bdk_pmux_pmpidr2_t;

static inline uint64_t BDK_PMUX_PMPIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR2(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fe8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR2(a) bdk_pmux_pmpidr2_t
#define bustype_BDK_PMUX_PMPIDR2(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR2(a) "PMUX_PMPIDR2"
#define busnum_BDK_PMUX_PMPIDR2(a) (a)
#define arguments_BDK_PMUX_PMPIDR2(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr3
 *
 * Performance Monitors Peripheral Identification Register 3
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cmod                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cmod                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr3_s cn; */
} bdk_pmux_pmpidr3_t;

static inline uint64_t BDK_PMUX_PMPIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR3(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fecll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR3(a) bdk_pmux_pmpidr3_t
#define bustype_BDK_PMUX_PMPIDR3(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR3(a) "PMUX_PMPIDR3"
#define busnum_BDK_PMUX_PMPIDR3(a) (a)
#define arguments_BDK_PMUX_PMPIDR3(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr4
 *
 * Performance Monitors Peripheral Identification Register 4
 * Provides information to identify a Performance Monitor
 *     component.
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t size                  : 4;  /**< [  7:  4](RO) Size of the component. RAZ. Log2 of the number of
                                                                     4KB pages from the start of the component to the end of the
                                                                     component ID registers. */
        uint32_t des_2                 : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t des_2                 : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. Indicates Cavium. */
        uint32_t size                  : 4;  /**< [  7:  4](RO) Size of the component. RAZ. Log2 of the number of
                                                                     4KB pages from the start of the component to the end of the
                                                                     component ID registers. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr4_s cn; */
} bdk_pmux_pmpidr4_t;

static inline uint64_t BDK_PMUX_PMPIDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR4(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fd0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR4", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR4(a) bdk_pmux_pmpidr4_t
#define bustype_BDK_PMUX_PMPIDR4(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR4(a) "PMUX_PMPIDR4"
#define busnum_BDK_PMUX_PMPIDR4(a) (a)
#define arguments_BDK_PMUX_PMPIDR4(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr5
 *
 * Performance Monitors Peripheral Identification Register 5
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr5_s cn; */
} bdk_pmux_pmpidr5_t;

static inline uint64_t BDK_PMUX_PMPIDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR5(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fd4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR5", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR5(a) bdk_pmux_pmpidr5_t
#define bustype_BDK_PMUX_PMPIDR5(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR5(a) "PMUX_PMPIDR5"
#define busnum_BDK_PMUX_PMPIDR5(a) (a)
#define arguments_BDK_PMUX_PMPIDR5(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr6
 *
 * Performance Monitors Peripheral Identification Register 6
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr6_s cn; */
} bdk_pmux_pmpidr6_t;

static inline uint64_t BDK_PMUX_PMPIDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR6(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fd8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR6", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR6(a) bdk_pmux_pmpidr6_t
#define bustype_BDK_PMUX_PMPIDR6(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR6(a) "PMUX_PMPIDR6"
#define busnum_BDK_PMUX_PMPIDR6(a) (a)
#define arguments_BDK_PMUX_PMPIDR6(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmpidr7
 *
 * Performance Monitors Peripheral Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmpidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmpidr7_s cn; */
} bdk_pmux_pmpidr7_t;

static inline uint64_t BDK_PMUX_PMPIDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMPIDR7(unsigned long a)
{
    if (a<=47)
        return 0x87a008020fdcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMPIDR7", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMPIDR7(a) bdk_pmux_pmpidr7_t
#define bustype_BDK_PMUX_PMPIDR7(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMPIDR7(a) "PMUX_PMPIDR7"
#define busnum_BDK_PMUX_PMPIDR7(a) (a)
#define arguments_BDK_PMUX_PMPIDR7(a) (a),-1,-1,-1

/**
 * Register (DAB32b) pmu#_pmswinc_el0
 *
 * Performance Monitors Software Increment Register
 * Increments a counter that is configured to count the Software
 *     increment event, event0x00
 */
typedef union
{
    uint32_t u;
    struct bdk_pmux_pmswinc_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t p                     : 31; /**< [ 30:  0](RO) Event counter software increment bit for PMEVCNTR<x>.
                                                                 P<x> is WI if x >= PMU()_PMCR_EL0[N], the number of implemented
                                                                     counters.
                                                                 Otherwise, the effects of writing to this bit are:
                                                                 0 = No action. The write to this bit is ignored.
                                                                 1 = It is CONSTRAINED UNPREDICTABLE whether a SW_INCR event is
                                                                     generated for event counter x. */
#else /* Word 0 - Little Endian */
        uint32_t p                     : 31; /**< [ 30:  0](RO) Event counter software increment bit for PMEVCNTR<x>.
                                                                 P<x> is WI if x >= PMU()_PMCR_EL0[N], the number of implemented
                                                                     counters.
                                                                 Otherwise, the effects of writing to this bit are:
                                                                 0 = No action. The write to this bit is ignored.
                                                                 1 = It is CONSTRAINED UNPREDICTABLE whether a SW_INCR event is
                                                                     generated for event counter x. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pmux_pmswinc_el0_s cn; */
} bdk_pmux_pmswinc_el0_t;

static inline uint64_t BDK_PMUX_PMSWINC_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PMUX_PMSWINC_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008020ca0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("PMUX_PMSWINC_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_PMUX_PMSWINC_EL0(a) bdk_pmux_pmswinc_el0_t
#define bustype_BDK_PMUX_PMSWINC_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_PMUX_PMSWINC_EL0(a) "PMUX_PMSWINC_EL0"
#define busnum_BDK_PMUX_PMSWINC_EL0(a) (a)
#define arguments_BDK_PMUX_PMSWINC_EL0(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_DAB_PMU_H__ */
