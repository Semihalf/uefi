/***********************license start************************************
 * Copyright (c) 2003-2009 Cavium Networks (support@cavium.com). All rights
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

/**
 * @file
 *
 * Interface to Octeon remotely using PCI/PCIe
 *
 * $Id: octeon-remote-pci.c 56824 2011-02-01 18:01:19Z cchavva $
 */
#include <bdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <memory.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "octeon-remote.h"
#include "octeon-remote-map.h"
#include "octeon-remote-debug-handler.h"

#define ULL unsigned long long

#define OCTEON_SLI_ADDR 0x11f0000010000ull

static const char *PCI_DEVICE_FILENAME = "/proc/bus/pci/devices";
static const uint32_t  OCTEON_PCI_IDS[] = { 0x177d0091, /* CN68XX */
                                            0x177d0093, /* CN61XX */
                                            0x177d0095, /* CN78XX */
                                            0x177d0096, /* CN70XX */
                                            0 };

static uint32_t octeon_pci_bar0_size    = 0;    /* Size of the BAR0 memory mapped region */
static uint64_t octeon_pci_bar0_address = 0;    /* Physical address of the BAR0 region */
static char *   octeon_pci_bar0_ptr     = NULL; /* Virtual address of the BAR0 region */
static uint32_t octeon_pci_bar1_size    = 0;    /* Size of the BAR1 memory mapped region */
static uint64_t octeon_pci_bar1_address = 0;    /* Physical address of the BAR1 region */
static char *   octeon_pci_bar1_ptr     = NULL; /* Virtual address of the BAR1 region */
static uint32_t octeon_pci_model        = 0;    /* Octeon model we're connected to */
static int      octeon_pci_port         = 0;    /* Octeon PCIe we're connected to */
static octeon_remote_map_cookie_t bar0_cookie;
static octeon_remote_map_cookie_t bar1_cookie;


/**
 * Find an Octeon on the PCI bus and setup the BAR0 and BAR1
 * addresses. Use the parameter device to control which Octeon
 * is used.
 *
 * @param device Octeon device to use. Zero for the first device, one for
 *               the second, etc.
 * @return Zero on success
 */
static int pci_get_device(int device)
{
    FILE *in;
    unsigned int bus;
    unsigned int devfn;
    unsigned int pci_id;
    int num_pci_devices = 0;

    /* Open the list of all PCI/PCIe devices */
    in = fopen(PCI_DEVICE_FILENAME, "r");
    if (in == NULL)
    {
        octeon_remote_debug(1, "Unable to open %s\n", PCI_DEVICE_FILENAME);
        return -1;
    }

    /* Each line in this file represents a PCI/PCIe device */
    while (!feof(in))
    {
        int index;
        unsigned int irq;
        unsigned long long bar0;
        unsigned long long bar1;
        unsigned long long siz0;
        unsigned long long siz1;
        unsigned long long unused;
        char rest_of_line[256];

        int count = fscanf(in, "%2x%2x %8x %x %Lx %Lx %Lx %Lx %Lx %Lx %Lx %Lx %Lx %Lx",
                           &bus, &devfn, &pci_id, &irq,
                           &bar0, &unused, &bar1, &unused, &unused, &unused, &unused,
                           &siz0, &unused, &siz1);
        if (count != 14)
        {
            if (count == -1)
                break;
            octeon_remote_debug(1, "fscanf returned %d instead of 14\n", count);
            octeon_remote_perror(-1, "fscanf failed to read the format");
            continue;
        }

        /* The fscanf doesn't read the whole line. Read the rest and throw it away */
        if (fgets(rest_of_line, sizeof(rest_of_line), in) == NULL)
        {
            octeon_remote_perror(-1, "fgets failed to read the rest of the line");
            fclose(in);
            return -1;
        }
        num_pci_devices++;

        /* Loop through our PCI ID list and look for a match */
        index = 0;
        while (OCTEON_PCI_IDS[index] && (pci_id != OCTEON_PCI_IDS[index]))
            index++;
        /* If no match was found go read a new line */
        if (OCTEON_PCI_IDS[index] == 0)
        {
            octeon_remote_debug(1, "PCI ID 0x%08x not recognized\n", pci_id);
            continue;
        }

        octeon_remote_debug(1, "%d:%d.%d PCI ID 0x%08x is an Octeon. BAR0=0x%llx[0x%llx] BAR1=0x%llx[0x%llx]\n", bus, devfn>>3, devfn&7, pci_id, bar0, siz0, bar1, siz1);

        /* We found an Octeon and read the location of its bar registers. If
            this is the device number we want we can stop searching */
        if (device == 0)
        {
            /* We need to strip off the lower 3 flag bits */
            octeon_pci_bar0_address = bar0 & 0xfffffffffffffff0ull;
            octeon_pci_bar1_address = bar1 & 0xfffffffffffffff0ull;
            octeon_pci_bar0_size = siz0;
            octeon_pci_bar1_size = siz1;
            break;
        }
        else
        {
            octeon_remote_debug(1, "Looking for the next Octeon device\n");
            device--;
        }
    }
    fclose(in);

    /* If no Octeon device was found the print a message and fail */
    if (!(octeon_pci_bar0_address && octeon_pci_bar1_address && octeon_pci_bar0_size && octeon_pci_bar1_size))
    {
        octeon_remote_debug(-1, "Octeon device not found\n");
        return -1;
    }

    char proc_name[64];
    snprintf(proc_name, sizeof(proc_name), "/proc/bus/pci/%02x/%02x.0", bus, devfn>>3);
    in = fopen(proc_name, "r+");
    if (in == NULL)
    {
        octeon_remote_perror(-1, proc_name);
        return -1;
    }

    /* Read BDK_PCI_CFG01 and make sure bus master and memory space are enabled */
    uint32_t octeon_cfg1;
    if (fseek(in, 4 /* BDK_PCIERCX_CFG001 */, SEEK_SET))
    {
        octeon_remote_perror(-1, "fseek BDK_PCI_CFG01");
        fclose(in);
        return -1;
    }
    if (fread(&octeon_cfg1, sizeof(octeon_cfg1), 1, in) != 1)
    {
        octeon_remote_perror(-1, "fread BDK_PCI_CFG01");
        fclose(in);
        return -1;
    }
    if ((bdk_le32_to_cpu(octeon_cfg1) & 0x7) != 0x6)
    {
        octeon_remote_debug(1, "Device is not enabled. Enabling it (0x%08x)\n", bdk_le32_to_cpu(octeon_cfg1));
        /* Bus master and memory space are not enabled. Force them */
        octeon_cfg1 = bdk_cpu_to_le32(bdk_le32_to_cpu(octeon_cfg1) | 0x6);
        if (fseek(in, 4 /* BDK_PCIERCX_CFG001 */, SEEK_SET))
        {
            octeon_remote_perror(-1, "fread BDK_PCI_CFG01");
            fclose(in);
            return -1;
        }
        if (fwrite(&octeon_cfg1, sizeof(octeon_cfg1), 1, in) != 1)
        {
            octeon_remote_perror(-1, "fwrite BDK_PCI_CFG01");
            fclose(in);
            return -1;
        }
    }
    fclose(in);

    /* Use the PCI ID to figure out which Octeon we are talking to. Note that
        the actual pass number will be read later after the mmaps are setup */
    switch (pci_id & 0xff)
    {
        case 0x91: /* CN68XX */
            octeon_pci_model = OCTEON_CN68XX_PASS2_0 & ~0x3f;
            break;
        case 0x93: /* CN61XX */
            octeon_pci_model = OCTEON_CN61XX_PASS1_0;
            break;
        case 0x95: /* CN78XX */
            octeon_pci_model = OCTEON_CN78XX_PASS1_0;
            break;
        case 0x96: /* CN70XX */
            octeon_pci_model = OCTEON_CN70XX_PASS1_0;
            break;
        default:
            octeon_remote_debug(-1, "Octeon model not recognized\n");
            return -1;
    }
    octeon_remote_debug(1, "Found Octeon on bus %d in slot %d. BAR0=0x%08llx[0x%x], BAR1=0x%08llx[0x%x]\n",
           bus, devfn>>3,
           (unsigned long long)octeon_pci_bar0_address, octeon_pci_bar0_size,
           (unsigned long long)octeon_pci_bar1_address, octeon_pci_bar1_size);
    return 0;
}


/**
 * The normal memcpy() tends to do 1 byte at a time for 4 byte
 * and 8 byte sizes on some machines. Since we are copying over
 * the PCI bus, optimized size accesses can be much more
 * important. This function attempts to use larger transfers
 * whenever possible.
 *
 * @param dest   Destination of copy
 * @param src    Source of copy
 * @param length Number of bytes to transfer
 */
static void fast_memcpy(void *dest, const void *src, unsigned long length)
{
    /* Cast void pointers to chars so compiler won't complain about
        incrementing void pointers */
    char *dptr = (char*)dest;
    char *sptr = (char*)src;

    /* Only attempt 128bit copies if everything is aligned. This copy
        works well on Octeon as a host, firing 2 IO loads at once */
    if (!((unsigned long)dptr&0xf) && !((unsigned long)sptr&0xf))
    {
        while (length >= 16)
        {
            uint64_t tmp1 = *(volatile uint64_t *)sptr;
            uint64_t tmp2 = *(volatile uint64_t *)(sptr+8);
            *(volatile uint64_t*)dptr = tmp1;
            *(volatile uint64_t*)(dptr+8) = tmp2;
            dptr+=16;
            sptr+=16;
            length-=16;
        }
    }

    /* Only attempt 64bit copies if everything is aligned */
    if (!((unsigned long)dptr&7) && !((unsigned long)sptr&7))
    {
        while (length >= 8)
        {
            *(uint64_t*)dptr = *(uint64_t *)sptr;
            dptr+=8;
            sptr+=8;
            length-=8;
        }
    }
    /* Only attempt 32bit copies if everything is aligned */
    if (!((unsigned long)dptr&3) && !((unsigned long)sptr&3))
    {
        while (length >= 4)
        {
            *(uint32_t*)dptr = *(uint32_t *)sptr;
            dptr+=4;
            sptr+=4;
            length-=4;
        }
    }
    /* Copy everything that is left using the normal memcpy */
    if (length)
        memcpy(dptr, sptr, length);
}


/**
 * Setup BAR1 index register zero to access the supplied
 * address.
 *
 * @param address Octeon physical memory address to access.
 */
static void pci_bar1_setup(uint64_t address)
{
    bdk_pemx_bar1_indexx_t bar1_entry;
    bar1_entry.u64          = 0;            /* Unused fields should be zero */
    bar1_entry.s.addr_idx   = address>>22;  /* Physical memory address in 4MB pages */
    bar1_entry.s.end_swp    = 1;            /* 1=little endian order */
    bar1_entry.s.addr_v     = 1;            /* Valid */
    OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_PEMX_BAR1_INDEXX(octeon_pci_port, 0), bar1_entry.u64);
    OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_PEMX_BAR1_INDEXX(octeon_pci_port, 0));
}


/**
 * Read a 32bit value from BAR0. Data is swapped as necessary.
 *
 * @param offset Offset into BAR0
 *
 * @return Value in cpu endianness
 */
static uint32_t bar0_read32(int offset)
{
    offset &= 0xffff;
    octeon_remote_debug(4, "BAR0[0x%04x] read  ", offset);
    uint32_t result = bdk_le32_to_cpu(*(volatile uint32_t*)(octeon_pci_bar0_ptr + offset));
    octeon_remote_output(4, "0x%08x\n", result);
    return result;
}


/**
 * Write a 32bit value to BAR0. Data is swapped as necessary.
 *
 * @param offset Offset to write too.
 * @param value  Value to write in cpu endianness
 */
static void bar0_write32(int offset, uint32_t value)
{
    offset &= 0xffff;
    octeon_remote_debug(4, "BAR0[0x%04x] write 0x%08x\n", offset, value);
    *(volatile uint32_t*)(octeon_pci_bar0_ptr + offset) = bdk_cpu_to_le32(value);
}


/**
 * Called when octeon_remote_open() is called using a remote spec
 * for PCI.
 *
 * @param remote_spec
 *               String specification of the remote to connect to.
 *
 * @return Zero on success, negative on failure.
 */
static int pci_open(const char *remote_spec)
{
    int device = 0;

    /* If the spec contains a device number, then read it */
    if (remote_spec[3] == ':')
        device = atoi(remote_spec + 4);

    /* Check if the environment variable OCTEON_PCI_DEVICE is set. It is
        treated as an override for the passed device number. This is to
        maintain backwards compatibility with the old PCI utilites. The new
        remote spec should be used instead */
    const char *pci_device_str = getenv("OCTEON_PCI_DEVICE");
    if (pci_device_str)
    {
        device = atoi(pci_device_str);
        if (device < 0) device = 0;
        if (device > 20) device = 20;
    }
    octeon_remote_debug(3, "Searching for device %d\n", device);

    /* Find the Octeon and get its memory mapped region addresses */
    if (pci_get_device(device))
        return -1;

    /* Map BAR0 */
    octeon_pci_bar0_ptr = octeon_remote_map(octeon_pci_bar0_address, octeon_pci_bar0_size, &bar0_cookie);
    if (!octeon_pci_bar0_ptr)
        return -1;

    /* Map BAR1 */
    octeon_pci_bar1_ptr = octeon_remote_map(octeon_pci_bar1_address, octeon_pci_bar1_size, &bar1_cookie);
    if (!octeon_pci_bar1_ptr)
        return -1;

    /* Determin the pass number */
    bdk_sli_ctl_status_t sli_ctl_status;
    sli_ctl_status.u64 = bar0_read32(BDK_SLI_CTL_STATUS);
    octeon_pci_model |= sli_ctl_status.s.chip_rev;

    /* Determine the port number */
    octeon_pci_port = OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_SLI_MAC_NUMBER) & 0xff;
    return 0;
}


/**
 * Called when octeon_remote_close() is called.
 */
static void pci_close(void)
{
    if (octeon_remote_debug_handler_is_installed())
        octeon_remote_debug_handler_remove();
    octeon_remote_unmap(&bar0_cookie);
    octeon_pci_bar0_ptr = NULL;
    octeon_remote_unmap(&bar1_cookie);
    octeon_pci_bar1_ptr = NULL;
}


/**
 * Read a 64bit CSR over PCI/PCIe
 *
 * @param physical_address
 *               Physical address of the CSR. Bits 63-49 should be zero.
 *
 * @return 64bit value of the CSR
 */
static uint64_t pci_read_csr(bdk_csr_type_t type, int busnum, int size, uint64_t address)
{
    switch (type)
    {
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_PEXPV_NCB:
            address &= 0xffff;
            if (size == 4)
                return bar0_read32(address);
            else
                return (((uint64_t)bar0_read32(address+4))<<32) | (uint64_t)bar0_read32(address);

        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
            /* Octeon II needs the read width to be set */
            switch (size)
            {
                case 1:
                    address |= 0ull<<49;
                    break;
                case 2:
                    address |= 1ull<<49;
                    break;
                case 4:
                    address |= 2ull<<49;
                    break;
                default:
                    address |= 3ull<<49;
                    break;
            }
            bar0_write32(BDK_SLI_WIN_RD_ADDR+4, address>>32);
            bar0_write32(BDK_SLI_WIN_RD_ADDR, address);
#ifdef __ppc__
            /* This read is needed to enforce ordering on PowerPC */
            bar0_read32(BDK_SLI_WIN_RD_ADDR);
#endif
            /* This read triggers the actual read */
            uint64_t v = (uint64_t)bar0_read32(BDK_SLI_WIN_RD_DATA);
            uint64_t reg_addr = (octeon_pci_port) ? BDK_SLI_LAST_WIN_RDATA1 : BDK_SLI_LAST_WIN_RDATA0;
            v |= ((uint64_t)bar0_read32(reg_addr+4))<<32;
            if (size != 8)
                v &= (1<<(size*8)) - 1;
            return v;

        case BDK_CSR_TYPE_PEXP:
            /* The SLI CSRs are accessed directly using external address. */
            return bar0_read32(address & 0xffff);

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
            /* The generic code can be used here */
            return __octeon_remote_default_read_csr(type, busnum, size, address);
    }
    return -1;
}


/**
 * Write a 64bit CSR over PCI/PCIe
 *
 * @param physical_address
 *               Physical address of the CSR. Bits 63-49 should be zero.
 * @param value  Value to write
 */
static void pci_write_csr(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    switch (type)
    {
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_PEXPV_NCB:
            address &= 0xffff;
            if (size == 4)
                bar0_write32(address, value);
            else
            {
                bar0_write32(address, value);
                bar0_write32(address+4, value>>32);
            }
            break;

        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
            /* High order 4 bytes of BDK_SLI_WIN_WR_MASK is unused */
            bar0_write32(BDK_SLI_WIN_WR_MASK+4, 0);
            /* Create a mask telling which bits to write in a 64bit word. The
                bytes are big endian order so address 0 is bit 7, address 7 is
                bit 0 */
            int write_mask = (1<<size)-1;
            write_mask <<= 8 - (address & 7) - size;
            bar0_write32(BDK_SLI_WIN_WR_MASK, write_mask);
            /* Shift the value to the correct bytes in a 64bit word */
            value <<= (8 - (address & 7) - size) * 8;
            /* Mask off the lower address bits as they are encoded in the
                mask above */
            address &= -8;
            /* Write the address to the hardware */
            bar0_write32(BDK_SLI_WIN_WR_ADDR+4, address>>32);
            bar0_write32(BDK_SLI_WIN_WR_ADDR, address);
            /* Write the high part of value to the hardware */
            bar0_write32(BDK_SLI_WIN_WR_DATA+4, value>>32);
#ifdef __ppc__
            /* This read is needed to enforce ordering on PowerPC */
            bar0_read32(BDK_SLI_WIN_WR_DATA+4);
#endif
            /* Writing the low part of the data triggers the actual write. It
                needs to be last */
            bar0_write32(BDK_SLI_WIN_WR_DATA, value);
            break;

        case BDK_CSR_TYPE_PEXP:
            /* In Octeon II, the SLI CSRs are accessed directly using external address. */
            bar0_write32(address & 0xffff, value);
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
            /* The generic code can be used here */
            __octeon_remote_default_write_csr(type, busnum, size, address, value);
            break;
    }
}


/**
 * Read data from a physical memory address.
 *
 * @param buffer_ptr Buffer to put the data in
 * @param physical_address
 *                   Physical address to read from. Bits 63-38 should be zero.
 * @param length     Length to read in bytes
 */
static void pci_read_mem(void *buffer_ptr, uint64_t physical_address, int length)
{
    char *buffer = (char*)buffer_ptr;
    uint32_t block_mask = (1<<22) - 1;
    uint64_t end_address = physical_address + length;

    /* We need to do reads in 4MB aligned chunks. This way we only need to
        mess with one BAR1 index register */
    do
    {
        char *ptr = octeon_pci_bar1_ptr + (physical_address & block_mask);
        if (end_address > (physical_address & ~(uint64_t)block_mask) + block_mask + 1)
            length = block_mask + 1 - (physical_address & block_mask);
        else
            length = end_address - physical_address;

        pci_bar1_setup(physical_address);
        fast_memcpy(buffer, ptr, length);
        buffer += length;
        physical_address += length;
    } while (physical_address < end_address);
}


/**
 * Write data to a physical memory address
 *
 * @param physical_address
 *                   Physical address to write to. Bits 63-38 should be zero.
 * @param buffer_ptr Buffer containing the data to write
 * @param length     Number of bytes to write
 */
static void pci_write_mem(uint64_t physical_address, const void *buffer_ptr, int length)
{
    char *buffer = (char*)buffer_ptr;
    uint32_t block_mask = (1<<22) - 1;
    uint64_t end_address = physical_address + length;

    /* We need to do writes in 4MB aligned chunks. This way we only need to
        mess with one BAR1 index register */
    do
    {
        void *ptr = octeon_pci_bar1_ptr + (physical_address & block_mask);
        if (end_address > (physical_address & ~(uint64_t)block_mask) + block_mask + 1)
            length = block_mask + 1 - (physical_address & block_mask);
        else
            length = end_address - physical_address;

        pci_bar1_setup(physical_address);
        fast_memcpy(ptr, buffer, length);
        buffer += length;
        physical_address += length;
    } while (physical_address < end_address);
    /* Read from BAR1 to make sure writes are complete */
    *(volatile uint32_t *)octeon_pci_bar1_ptr;
}


/**
 * Return the Processor ID of the Octeon. This should be identical
 * to the value found in the COP0 PRID register
 *
 * @return Processor ID
 */
static uint32_t pci_get_model(void)
{
    return octeon_pci_model;
}


/**
 * Take the cores in the bit vector out of the debug exception.
 *
 * @param start_mask Cores to start
 */
static void pci_start_cores(uint64_t start_mask)
{
    int core;
    uint64_t reset_status;
    octeon_remote_debug(2, "Starting coremask 0x%llx\n", (ULL)start_mask);

    /* Handle Core 0 in reset as a special case. If core 0 is in reset, interpret
        this as a request to take it out of reset */
    reset_status = OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_CIU_PP_RST);
    if (reset_status & 1)
    {
        if (start_mask & 1)
            OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_CIU_PP_RST, reset_status & -2);
    }
    else
    {
        for (core=0; core<64; core++)
            if ((1ull<<core) & start_mask)
            {
                uint64_t base = octeon_remote_debug_handler_get_base(core);
                if (base)
                    octeon_remote_write_mem64(base, 0);
            }
    }
}


/**
 * Cause the cores in the stop mask to take a debug exception
 *
 * @param stop_mask Cores to stop
 */
static void pci_stop_cores(uint64_t stop_mask)
{
    octeon_remote_debug(2, "Stopping coremask 0x%llx\n", (ULL)stop_mask);
    if (octeon_remote_debug_handler_install(OCTEON_REMOTE_DEBUG_HANDLER))
        return;
    OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_CIU_DINT, stop_mask);
}


/**
 * Get a mask where each bit represents a running core. If a core
 * is in the debug exception handler, it's bit will be zero.
 *
 * @return Bit set for every running core
 */
static uint64_t pci_get_running_cores(void)
{
    return ~OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_CIU_PP_DBG);
}


/**
 * Get all registers, COP0, TLB, etc for a core
 *
 * @param core      Core to get state info for
 * @param registers All of the core's internal state
 *
 * @return Zero on success, negative on failure
 */
static int pci_get_core_state(int core, octeon_remote_registers_t *registers)
{
    int i, j;
    int temp_stop = 0;
    if (pci_get_running_cores() & (1ull<<core))
    {
        temp_stop = 1;
        pci_stop_cores(1ull<<core);
    }
    uint64_t base = octeon_remote_debug_handler_get_base(core);
    if (!base)
        return -1;

    /* Sometimes the host can get here before the PCIe block has propagated
        the CSR write to stop the cores. Spin here waiting for the core to
        stop */
    time_t timeout = time(NULL) + 2;
    do
    {
        if (time(NULL) >= timeout)
            return -1;
        octeon_remote_read_mem(registers, base, sizeof(*registers));
    } while (bdk_be64_to_cpu(registers->regs[0][0]) != 1);

    for (i=0; i<2; i++)
        for (j=0; j<256; j++)
            registers->regs[i][j] = bdk_be64_to_cpu(registers->regs[i][j]);

    for (i=0; i<128; i++)
        for (j=0; j<4; j++)
            registers->tlb[i][j] = bdk_be64_to_cpu(registers->tlb[i][j]);

    registers->regs[0][0] = 0;

    if (temp_stop)
        pci_start_cores(1ull<<core);
    return 0;
}


/**
 * Set all registers, COP0, TLB, etc for a given core
 *
 * @param core      Core to set state for
 * @param registers All date for the core
 *
 * @return Zero on success, negative on failure
 */
static int pci_set_core_state(int core, const octeon_remote_registers_t *registers)
{
    int i, j;
    octeon_remote_registers_t debug;
    uint64_t base = octeon_remote_debug_handler_get_base(core);
    if (!base)
        return -1;

    for (i=0; i<2; i++)
        for (j=0; j<256; j++)
            debug.regs[i][j] = bdk_be64_to_cpu(registers->regs[i][j]);

    for (i=0; i<128; i++)
        for (j=0; j<4; j++)
            debug.tlb[i][j] = bdk_be64_to_cpu(registers->tlb[i][j]);

    debug.regs[0][0] = bdk_cpu_to_be64(1);
    octeon_remote_write_mem(base, &debug, sizeof(debug));
    return 0;
}

/**
 * Due to errata, cn56xx pass 1.x can't use the normal reset function.
 *
 * @param stop_core Attempt to stop core 0 from booting, if possible. This is not
 *                  software controlled for PCI. The board must use the PCI_BOOT
 *                  pin to control this.
 *
 * @return Zero on success
 */
static int pci_reset(int stop_core __attribute__ ((unused)))
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX) || OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        bdk_rst_boot_t rst_boot;
        rst_boot.u64 = OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_RST_BOOT);
        rst_boot.s.rboot = stop_core;
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_RST_BOOT, rst_boot.u64);
        OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_RST_BOOT);
    }
    else
    {
        bdk_mio_rst_boot_t mio_rst_boot;
        mio_rst_boot.u64 = OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_MIO_RST_BOOT);
        mio_rst_boot.s.rboot = stop_core;
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_RST_BOOT, mio_rst_boot.u64);
        OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_MIO_RST_BOOT);
    }

    /* HRM specifies that CIU_SOFT_RST should be read before initiating
    ** a reset over PCI */
    OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_CIU_SOFT_RST);
    OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_CIU_SOFT_RST, 1);

    /* Delay here to ensure that no accesses to Octeon are made
    ** while it is in reset.  1 MS is what CN56XX HRM specifies,
    ** but add some margin. */
    usleep(5000);
    return 0;
}


static uint64_t pci_read_cop0(int core, int reg, int select)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX) || OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        bdk_l2c_cop0_adr_t adr;
        adr.u = 0;
        adr.s.ppid = core;
        adr.s.root = 1;
        adr.s.rd = reg;
        adr.s.sel = select;
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_L2C_COP0_ADR, adr.u);
        return OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_L2C_COP0_DAT);
    }
    else
    {
        return OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_L2C_COP0_MAPX((core<<8)|(reg<<3)|select));
    }
}

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
static int pci_get_sample(uint64_t coremask, octeon_remote_sample_t sample[])
{
    int num_cores = octeon_remote_get_num_cores();
    for (int core=0; core<num_cores; core++)
    {
        if ((1ull<<core) & coremask)
        {
            sample[core].pc = pci_read_cop0(core, 16, 0);
            if (sample[core].pc & 2)
                sample[core].pc = 0; /* The sample is invalid */
            else if (sample[core].pc >> 32 == 0xc001ffffull)
                sample[core].pc |= 0x3ffe000000000000ull; /* The hardware doesn't store these bits */
            sample[core].pc &= -4; /* AND off the lower two bits where extra data is encoded */
            sample[core].perf_count[0] = pci_read_cop0(core, 25, 1);
            sample[core].perf_count[1] = pci_read_cop0(core, 25, 3);
        }
    }
    return 0;
}


/**
 * Initialize the pointers needed for octeon_remote to work over
 * PCI/PCIe. This doesn't actually create a connection, just setup
 * internal data structures.
 *
 * @param remote_funcs
 *               Function pointers to be populated
 *
 * @return Zero on success, negative on failure
 */
int octeon_remote_pci(octeon_remote_funcs_t *remote_funcs)
{
    remote_funcs->open = pci_open;
    remote_funcs->close = pci_close;
    remote_funcs->read_csr = pci_read_csr;
    remote_funcs->write_csr = pci_write_csr;
    remote_funcs->read_mem = pci_read_mem;
    remote_funcs->write_mem = pci_write_mem;
    remote_funcs->get_model = pci_get_model;
    remote_funcs->start_cores = pci_start_cores;
    remote_funcs->stop_cores = pci_stop_cores;
    remote_funcs->get_running_cores = pci_get_running_cores;
    remote_funcs->get_core_state = pci_get_core_state;
    remote_funcs->set_core_state = pci_set_core_state;
    remote_funcs->reset = pci_reset;
    remote_funcs->get_sample = pci_get_sample;

    if (getenv("OCTEON_PCI_DEBUG"))
        remote_funcs->debug++;

    return 0;
}

