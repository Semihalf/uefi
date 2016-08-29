/*
 * Copyright (c) 2014, ARM Limited and Contributors. All rights reserved.
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

#include <debug.h>
#include <psci.h>
#include <runtime_svc.h>
#include <thunder_svc.h>
#include <stdint.h>
#include <uuid.h>
#include <string.h>
#include <thunder_private.h>
#include <errno.h>
#include <libfdt.h>

#define PAR_EL1_F	(1 << 0)

 /* cf98f46f-fa9c-4e5a-a43a-2a2f05b14559 */

/* Cavium OEM Service UUID */
DEFINE_SVC_UUID(thunder_svc_uid,
		0xcf98f46f, 0xfa9c, 0x4e5a, 0xa4, 0x3a,
		0x2a, 0x2f, 0x05, 0xb1, 0x45, 0x59);

/* Setup Standard Services */
static int32_t thunder_svc_setup(void)
{
	return 0;
}

/*
 * Top-level OEM Service SMC handler
 */
uint64_t thunder_svc_smc_handler(uint32_t smc_fid,
								uint64_t x1,
								uint64_t x2,
								uint64_t x3,
								uint64_t x4,
								void *cookie,
								void *handle,
								uint64_t flags)
{
	uint64_t size, par_el1;
	int64_t ret;

	switch (smc_fid) {
	case THUNDERX_SVC_CALL_COUNT:
		/*
		 * Return the number of Service Calls.
		 */
		SMC_RET1(handle, THUNDERX_NUM_CALLS);

	case THUNDERX_SVC_UID:
		/* Return UID to the caller */
		SMC_UUID_RET(handle, thunder_svc_uid);

	case THUNDERX_SVC_VERSION:
		/* Return the version of current implementation */
		SMC_RET2(handle, THUNDERX_VERSION_MAJOR, THUNDERX_VERSION_MINOR);

	case THUNDERX_DRAM_SIZE:
		ret = thunder_dram_size_node(x1);
		WARN("DRAM size for %lx: %lx\n", x1, ret);
		SMC_RET1(handle, ret);

	case THUNDERX_NODE_COUNT:
		ret = thunder_get_node_count();
		SMC_RET1(handle, ret);

	case THUNDERX_FDT_GET:
		// x1 - buffer pointer
		// x2 - buffer size
		size = fdt_totalsize(fdt_ptr);

		__asm__ volatile("at s1e3w, %0" : : "r"(x1));
		__asm__ volatile("mrs %0, par_el1" : "=r"(par_el1));

		if (par_el1 & PAR_EL1_F)
			SMC_RET1(handle, -EFAULT);

		if (size > x2)
			SMC_RET1(handle, -ENOMEM);

		// copy FDT to non-secure memory
		memcpy((void*)x1, fdt_ptr, size);

		SMC_RET1(handle, size);
	default:
		WARN("Unimplemented ThunderX Service Call: 0x%x \n", smc_fid);
		SMC_RET1(handle, SMC_UNK);
	}
}

/* Register Standard Service Calls as runtime service */
DECLARE_RT_SVC(
		thunder_svc,
		OEN_OEM_START,
		OEN_OEM_END,
		SMC_TYPE_STD,
		thunder_svc_setup,
		thunder_svc_smc_handler
);
