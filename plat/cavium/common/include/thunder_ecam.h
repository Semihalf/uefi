/** @file
 * #
 * #  Copyright (c) 2016, Cavium Inc. All rights reserved.<BR>
 * #  This program and the accompanying materials
 * #  are licensed and made available under the terms and conditions of the BSD License
 * #  which accompanies this distribution.  The full text of the license may be found at
 * #  http://opensource.org/licenses/bsd-license.php
 * #
 * #  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 * #  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 * #
 * #**/

#ifndef __THUNDER_ECAM_H__
#define __THUNDER_ECAM_H__

#define FALSE 0
#define TRUE 1

typedef int (*ecam_probe)(int node, unsigned long arg);

struct ecam_device{
    int ecam_id;
    int bus;
    int dev;
    int fun;
    int ns_visible;
    ecam_probe probe_fn;
    unsigned long probe_arg;
};

struct ecam_platform_defs {
	int soc_type;
	struct ecam_device *(*get_dev_idx)(int node, int ecam_id);
	int (*get_max_bus)(int ecam_id);
	uint64_t (*get_config_addr)(int node, int ecam_id);
	uint64_t (*get_config_size)(int node, int ecam_id);
	int (*disable_device_on_bus)(int node, int bus);
};

struct thunder_ecam{
    int ecam_id;
    uint64_t config_base;
    uint64_t config_size;
    uint64_t csr_base;
    uint64_t csr_size;
    int max_bus;
};

struct ecam_callback {
    int devid;
    int vendor_id;
    void (*io_init)(int, uint64_t, uint64_t);
};


#endif
