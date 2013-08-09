/***********************license start************************************
 * Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *     * Neither the name of Cavium Networks nor the names of
 *       its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS
 * OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
 * RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
 * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
 * DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
 * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
 * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET
 * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT
 * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 *
 *
 * For any questions regarding licensing please contact marketing@caviumnetworks.com
 *
 **********************license end**************************************/
#ifndef OCTEON_REMOTE_H
#define OCTEON_REMOTE_H

/**
 * @file octeon-remote.h
 *
 * Interface to Octeon remotely using various transports
 *
 * $Id: octeon-remote.h 48665 2010-04-22 18:23:31Z apinski $
 */

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef OCTEON_REMOTE_DEFAULT
#define OCTEON_REMOTE_DEFAULT NULL
#endif

#define OCTEON_REMOTE_NODE bdk_numa_local()

/**
 * - regs[0][0-31] = General purpose registers
 * - regs[0][32] = Lo
 * - regs[0][33] = Hi
 * - regs[0][128-255] = EJTAG special registers
 * - regs[1][0-255] = COP0 registers indexed by (reg*8)+select
 * - tlb[*][0] = EntryHi
 * - tlb[*][1] = Pagemask
 * - tlb[*][2] = EntryLo0
 * - tlb[*][3] = EntryLo1
 */
typedef struct
{
    uint64_t regs[2][256];
    uint64_t tlb[256][4];
} octeon_remote_registers_t;

/**
 * This typedef represents the data per core returned by an
 * octeon_remote_get_sample() function call. The get_sample will
 * populate as many of these fields it can with a minimum
 * performance impact to the core. Not all transports can fill
 * in all fields, but "pc" is generally supplied at a minimum.
 * Fields that cannot be filled will be zero.
 */
typedef struct
{
    uint64_t pc;
    uint64_t perf_count[2];
} octeon_remote_sample_t;

/**
 * This structure represents the API required to implement a
 * remote transport. If all these functions can be implemented
 * over some remote protocol (PCI, EJTAG, etc), then the Octeon
 * command line utilities should work. Which protocol that is
 * used can be controlled either by and argument to
 * octeon_remote_open() or the environment variable
 * OCTEON_REMOTE_PROTOCOL.
 */
typedef struct
{
    int debug; /* The current debug level as set by OCTEON_REMOTE_DEBUG */
    int debug_indent; /* The current debug indent level */
    uint32_t model; /* The remote's Octeon model, cached for fast access */

    /* The following function pointers must be populated by the underlying
        remote transport */
    int (*open)(const char *remote_spec);
    void (*close)(void);
    void (*read_mem)(void *buffer, uint64_t physical_address, int length);
    void (*write_mem)(uint64_t physical_address, const void *buffer, int length);
    uint32_t (*get_model)(void);
    void (*start_cores)(uint64_t start_mask);
    void (*stop_cores)(uint64_t stop_mask);
    uint64_t (*get_running_cores)(void);
    int (*get_core_state)(int core, octeon_remote_registers_t *registers);
    int (*set_core_state)(int core, const octeon_remote_registers_t *registers);
    int (*get_sample)(uint64_t coremask, octeon_remote_sample_t sample[64]);

    /* The following functions are optional. If they are not set, a default
        implementation is used. In general the default implementation should
        be used */
    void (*lock)(void);
    void (*unlock)(void);
    int (*reset)(int stop_core);
    uint64_t (*read_register)(int core, int reg);
    void (*write_register)(int core, int reg, uint64_t value);
    uint64_t (*read_csr)(bdk_csr_type_t type, int busnum, int size, uint64_t address);
    void (*write_csr)(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value);
} octeon_remote_funcs_t;

/**
 * Utility function to display debug messages. Only messages at
 * or below the current debug level are displayed.
 *
 * @param level  Level for this message
 * @param format prinf format
 */
void octeon_remote_debug(int level, const char *format, ...) __attribute__ ((format(printf, 2, 3)));

/**
 * Utility function to display library error messages similar to
 * perror(). As an extension, this functions takes full printf
 * style arguments instead of the simple string used by perror().
 * Only messages at or below the current debug level are
 * displayed.
 *
 * @param level  Level for this message
 * @param format prinf format
 */
void octeon_remote_perror(int level, const char *format, ...) __attribute__ ((format(printf, 2, 3)));

/**
 * Utility function to display output messages without line
 * prefixes. Only messages at or below the current debug level are
 * displayed.
 *
 * @param level  Level for this message
 * @param format prinf format
 */
void octeon_remote_output(int level, const char *format, ...) __attribute__ ((format(printf, 2, 3)));

void octeon_remote_debug_call(int is_return, const char *format, ...) __attribute__ ((format(printf, 2, 3)));
#define OCTEON_REMOTE_DEBUG_CALLED(format, ...) \
    octeon_remote_debug_call(0, "Called %s(" format ")\n", __FUNCTION__, ##__VA_ARGS__);
#define OCTEON_REMOTE_DEBUG_RETURNED(format, ...) \
    octeon_remote_debug_call(1, "Return %s(" format ")\n", __FUNCTION__, ##__VA_ARGS__);

/**
 * Open a connection to a remote Octeon.
 *
 * @param remote_spec
 *               Remote protocol spec to use. If NULL, it will be taken from the
 *               OCTEON_REMOTE_PROTOCOL environment variable.
 *
 * @return Zero on success, negative on failure.
 */
int octeon_remote_open(const char *remote_spec, int debug);

/**
 * Close a remote connection created by octeon_remote_open()
 */
void octeon_remote_close(void);

/**
 * Read a CSR from a remote Octeon
 *
 * @param physical_address
 *               Physical address of the CSR. Bits 63-49 should be zero.
 *
 * @return 64bit value of the CSR
 */
uint64_t octeon_remote_read_csr(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address);
#define OCTEON_REMOTE_READ_CSR(node, csr) octeon_remote_read_csr(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)
uint64_t __octeon_remote_default_read_csr(bdk_csr_type_t type, int busnum, int size, uint64_t address);

/**
 * Write a CSR on a remote Octeon
 *
 * @param physical_address
 *               Physical address of the CSR. Bits 63-49 should be zero.
 * @param value  Value to write
 */
void octeon_remote_write_csr(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value);
#define OCTEON_REMOTE_WRITE_CSR(node, csr, value) octeon_remote_write_csr(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, value)
void __octeon_remote_default_write_csr(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value);

/**
 * Read data from a physical memory address.
 *
 * @param buffer_ptr Buffer to put the data in
 * @param physical_address
 *                   Physical address to read from. Bits 63-38 should be zero.
 * @param length     Length to read in bytes
 */
void octeon_remote_read_mem(void *buffer, uint64_t physical_address, int length);

/**
 * Write data to a physical memory address
 *
 * @param physical_address
 *                   Physical address to write to. Bits 63-38 should be zero.
 * @param buffer_ptr Buffer containing the data to write
 * @param length     Number of bytes to write
 */
void octeon_remote_write_mem(uint64_t physical_address, const void *buffer, int length);

/**
 * Return the Processor ID of the Octeon. This should be identical
 * to the value found in the COP0 PRID register
 *
 * @return Processor ID
 */
uint32_t octeon_remote_get_model(void) __attribute__ ((pure));

/**
 * Take the cores in the bit vector out of the debug exception.
 *
 * @param start_mask Cores to start
 */
void octeon_remote_start_cores(uint64_t start_mask);

/**
 * Cause the cores in the stop mask to take a debug exception
 *
 * @param stop_mask Cores to stop
 */
void octeon_remote_stop_cores(uint64_t stop_mask);

/**
 * Get the number of cores Octeon has.
 *
 * @return Number of cores, or zero on failure.
 */
int octeon_remote_get_num_cores(void);

/**
 * Get a mask where each bit represents a running core. If a core
 * is in the debug exception handler, it's bit will be zero.
 *
 * @return Bit set for every running core
 */
uint64_t octeon_remote_get_running_cores(void);

/**
 * Get all registers, COP0, TLB, etc for a core
 *
 * @param core      Core to get state info for
 * @param registers All of the core's internal state
 *
 * @return Zero on success, negative on failure
 */
int octeon_remote_get_core_state(int core, octeon_remote_registers_t *registers);

/**
 * Set all registers, COP0, TLB, etc for a given core
 *
 * @param core      Core to set state for
 * @param registers All date for the core
 *
 * @return Zero on success, negative on failure
 */
int octeon_remote_set_core_state(int core, const octeon_remote_registers_t *registers);

/**
 * Read a single Octeon register
 *
 * @param core   Core to read the register from
 * @param reg    Register to read
 *
 * @return Register value
 */
uint64_t octeon_remote_read_register(int core, int reg);

/**
 * Write a single Octeon register.
 *
 * @param core   Core to write the register on
 * @param reg    Register to write
 * @param value  Value to write
 */
void octeon_remote_write_register(int core, int reg, uint64_t value);

/**
 * Lock the remote protocol for exclusive access. This is needed
 * if multiple programs might be accessing the same Octeon at the
 * same time.
 */
void octeon_remote_lock(void);

/**
 * Unlock the remote protocol for exclusive access. This is needed if multiple
 * programs might be accessing the same Octeon at the same time.
 */
void octeon_remote_unlock(void);

/**
 * Reset a remote Octeon. This performs a full chip soft reset.
 *
 * @param stop_core Attempt to stop core 0 from booting, if possible. If the remote
 *                  protocol supports it, core 0 is stopped before executing
 *                  instructions from flash.
 *
 * @return Zero on success, negative on failure.
 */
int octeon_remote_reset(int stop_core);

/**
 * Sample performance / profiling information for a set of cores
 * minimizing the performance impact of taking the sample. The
 * amount of data returned may vary depending on the remote
 * protocol used, but at least the program counter for each core
 * will normally be supported. Values that could not be sampled
 * will be zero.
 *
 * @param coremask Each set bit represent a core that should be sampled.
 * @param sample   Array of samples to populate. Note that the sample array must
 *                 contain elements for cores not set in the coremask. These may
 *                 be filled with sample data even if the coremask bit is clear.
 *                 Some transports may sample all core efficiently and yield
 *                 unwanted core samples.
 *
 * @return Zero on success, negative on failure
 */
int octeon_remote_get_sample(uint64_t coremask, octeon_remote_sample_t sample[64]);

/**
 * Write a 16 bit value into Octeon's memory. This code automatically correct
 * for differences between Octeon's endianness and where we are running.
 *
 * @param physical_address
 *               Physical address to write to. Bits 63-38 should be zero.
 * @param data   Data to write
 */
void octeon_remote_write_mem16(uint64_t physical_address, uint16_t data);

/**
 * Write a 32 bit value into Octeon's memory. This code automatically correct
 * for differences between Octeon's endianness and where we are running.
 *
 * @param physical_address
 *               Physical address to write to. Bits 63-38 should be zero.
 * @param data   Data to write
 */
void octeon_remote_write_mem32(uint64_t physical_address, uint32_t data);

/**
 * Write a 64 bit value into Octeon's memory. This code automatically correct
 * for differences between Octeon's endianness and where we are running.
 *
 * @param physical_address
 *               Physical address to write to. Bits 63-38 should be zero.
 * @param data   Data to write
 */
void octeon_remote_write_mem64(uint64_t physical_address, uint64_t data);

/**
 * Read a 16 bit value from Octeon's memory. This code automatically correct for
 * differences between Octeon's endianness and where we are running.
 *
 * @param physical_address
 *               Physical address to read from. Bits 63-38 should be zero.
 *
 * @return Data read
 */
uint16_t octeon_remote_read_mem16(uint64_t physical_address);

/**
 * Read a 32 bit value from Octeon's memory. This code automatically correct for
 * differences between Octeon's endianness and where we are running.
 *
 * @param physical_address
 *               Physical address to read from. Bits 63-38 should be zero.
 *
 * @return Data read
 */
uint32_t octeon_remote_read_mem32(uint64_t physical_address);

/**
 * Read a 64 bit value from Octeon's memory. This code automatically correct for
 * differences between Octeon's endianness and where we are running.
 *
 * @param physical_address
 *               Physical address to read from. Bits 63-38 should be zero.
 *
 * @return Data read
 */
uint64_t octeon_remote_read_mem64(uint64_t physical_address);

#ifdef	__cplusplus
}
#endif

#endif
