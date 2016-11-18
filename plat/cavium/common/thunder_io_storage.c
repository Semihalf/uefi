/*
 * Copyright (c) 2015, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <assert.h>
#include <bl_common.h>		/* For ARRAY_SIZE */
#include <debug.h>
#include <firmware_image_package.h>
#include <io_driver.h>
#include <io_fip.h>
#include <io_spi.h>
#include <io_mmc.h>
#include <io_storage.h>
#include <platform_def.h>
#include <string.h>

#include <cavm-arch.h>

/* IO devices */
static const io_dev_connector_t *fip_dev_con;
static uintptr_t fip_dev_handle;
static const io_dev_connector_t *blk_dev_con;
static uintptr_t blk_dev_handle;

static const io_block_spec_t fip_block_spec = {
	.offset	= 0x580000,
};

static const io_uuid_spec_t bl2_uuid_spec = {
	.uuid = UUID_TRUSTED_BOOT_FIRMWARE_BL2,
};

static const io_uuid_spec_t scp_bl2_uuid_spec = {
	.uuid = UUID_SCP_FIRMWARE_SCP_BL2,
};

static const io_uuid_spec_t bl31_uuid_spec = {
	.uuid = UUID_EL3_RUNTIME_FIRMWARE_BL31,
};

static const io_uuid_spec_t bl32_uuid_spec = {
	.uuid = UUID_SECURE_PAYLOAD_BL32,
};

static const io_uuid_spec_t bl33_uuid_spec = {
	.uuid = UUID_NON_TRUSTED_FIRMWARE_BL33,
};

#if TRUSTED_BOARD_BOOT
static const io_uuid_spec_t tb_fw_cert_uuid_spec = {
	.uuid = UUID_TRUSTED_BOOT_FW_CERT,
};

static const io_uuid_spec_t trusted_key_cert_uuid_spec = {
	.uuid = UUID_TRUSTED_KEY_CERT,
};

static const io_uuid_spec_t scp_fw_key_cert_uuid_spec = {
	.uuid = UUID_SCP_FW_KEY_CERT,
};

static const io_uuid_spec_t soc_fw_key_cert_uuid_spec = {
	.uuid = UUID_SOC_FW_KEY_CERT,
};

static const io_uuid_spec_t tos_fw_key_cert_uuid_spec = {
	.uuid = UUID_TRUSTED_OS_FW_KEY_CERT,
};

static const io_uuid_spec_t nt_fw_key_cert_uuid_spec = {
	.uuid = UUID_NON_TRUSTED_FW_KEY_CERT,
};

static const io_uuid_spec_t scp_fw_cert_uuid_spec = {
	.uuid = UUID_SCP_FW_CONTENT_CERT,
};

static const io_uuid_spec_t soc_fw_cert_uuid_spec = {
	.uuid = UUID_SOC_FW_CONTENT_CERT,
};

static const io_uuid_spec_t tos_fw_cert_uuid_spec = {
	.uuid = UUID_TRUSTED_OS_FW_CONTENT_CERT,
};

static const io_uuid_spec_t nt_fw_cert_uuid_spec = {
	.uuid = UUID_NON_TRUSTED_FW_CONTENT_CERT,
};
#endif /* TRUSTED_BOARD_BOOT */


static int open_fip(const uintptr_t spec);
static int open_blk(const uintptr_t spec);

struct plat_io_policy {
	uintptr_t *dev_handle;
	uintptr_t image_spec;
	int (*check)(const uintptr_t spec);
};

/* By default, ARM platforms load images from the FIP */
static const struct plat_io_policy policies[] = {
	[FIP_IMAGE_ID] = {
		&blk_dev_handle,
		(uintptr_t)&fip_block_spec,
		open_blk
	},
	[BL2_IMAGE_ID] = {
		&fip_dev_handle,
		(uintptr_t)&bl2_uuid_spec,
		open_fip
	},
	[SCP_BL2_IMAGE_ID] = {
		&fip_dev_handle,
		(uintptr_t)&scp_bl2_uuid_spec,
		open_fip
	},
	[BL31_IMAGE_ID] = {
		&fip_dev_handle,
		(uintptr_t)&bl31_uuid_spec,
		open_fip
	},
	[BL32_IMAGE_ID] = {
		&fip_dev_handle,
		(uintptr_t)&bl32_uuid_spec,
		open_fip
	},
	[BL33_IMAGE_ID] = {
		&fip_dev_handle,
		(uintptr_t)&bl33_uuid_spec,
		open_fip
	},
#if TRUSTED_BOARD_BOOT
	[TRUSTED_BOOT_FW_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&tb_fw_cert_uuid_spec,
		open_fip
	},
	[TRUSTED_KEY_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&trusted_key_cert_uuid_spec,
		open_fip
	},
	[SCP_FW_KEY_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&scp_fw_key_cert_uuid_spec,
		open_fip
	},
	[SOC_FW_KEY_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&soc_fw_key_cert_uuid_spec,
		open_fip
	},
	[TRUSTED_OS_FW_KEY_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&tos_fw_key_cert_uuid_spec,
		open_fip
	},
	[NON_TRUSTED_FW_KEY_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&nt_fw_key_cert_uuid_spec,
		open_fip
	},
	[SCP_FW_CONTENT_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&scp_fw_cert_uuid_spec,
		open_fip
	},
	[SOC_FW_CONTENT_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&soc_fw_cert_uuid_spec,
		open_fip
	},
	[TRUSTED_OS_FW_CONTENT_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&tos_fw_cert_uuid_spec,
		open_fip
	},
	[NON_TRUSTED_FW_CONTENT_CERT_ID] = {
		&fip_dev_handle,
		(uintptr_t)&nt_fw_cert_uuid_spec,
		open_fip
	},
#endif /* TRUSTED_BOARD_BOOT */
};



static int open_fip(const uintptr_t spec)
{
	int result;
	uintptr_t local_image_handle;

	/* See if a Firmware Image Package is available */
	result = io_dev_init(fip_dev_handle, (uintptr_t)FIP_IMAGE_ID);
	if (result == 0) {
		result = io_open(fip_dev_handle, spec, &local_image_handle);
		if (result == 0) {
			VERBOSE("Using FIP\n");
			io_close(local_image_handle);
		}
	}
	return result;
}


static int open_blk(const uintptr_t spec)
{
	int result;
	uintptr_t local_image_handle;

	result = io_dev_init(blk_dev_handle, (uintptr_t)NULL);
	if (result == 0) {
		result = io_open(blk_dev_handle, spec, &local_image_handle);
		if (result == 0) {
			VERBOSE("Using SPI or (e)MMC\n");
			io_close(local_image_handle);
		}
	}
	return result;
}


void thunder_io_setup(void)
{
	int io_result, boot_medium;
	cavm_gpio_strap_t gpio_strap;

	io_result = register_io_dev_fip(&fip_dev_con);
	assert(io_result == 0);

	gpio_strap.u = CSR_READ_PA(0, CAVM_GPIO_STRAP);
	boot_medium = (gpio_strap.u) & 0x7;

	if (boot_medium == 0x5)
		io_result = register_io_dev_spi(&blk_dev_con);
	else
		io_result = register_io_dev_emmc(&blk_dev_con);
	assert(io_result == 0);

	/* Open connections to devices and cache the handles */
	io_result = io_dev_open(fip_dev_con, (uintptr_t)NULL,
				&fip_dev_handle);
	assert(io_result == 0);

	io_result = io_dev_open(blk_dev_con, (uintptr_t)NULL,
				&blk_dev_handle);
	assert(io_result == 0);

	/* Ignore improbable errors in release builds */
	(void)io_result;
}

/* Return an IO device handle and specification which can be used to access
 * an image. Use this to enforce platform load policy */
int plat_get_image_source(unsigned int image_id, uintptr_t *dev_handle,
			  uintptr_t *image_spec)
{
	int result;
	const struct plat_io_policy *policy;

	assert(image_id < ARRAY_SIZE(policies));

	policy = &policies[image_id];
	result = policy->check(policy->image_spec);

	if (result == 0) {
		*image_spec = policy->image_spec;
		*dev_handle = *(policy->dev_handle);
	} else {
		WARN("FIP not found\n");
		result = -ENOENT;
	}

	return result;
}
