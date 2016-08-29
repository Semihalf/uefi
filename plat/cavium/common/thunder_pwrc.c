/*
 * Copyright (c) 2013-2014, ARM Limited and Contributors. All rights reserved.
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

#include <thunder_pwrc.h>
#include <thunder_private.h>

unsigned int thunder_pwrc_get_cpu_wkr(unsigned long mpidr)
{
	unsigned int rc = 0;
	return rc;
}

unsigned int thunder_pwrc_read_psysr(unsigned long mpidr)
{
	unsigned int rc = 0;
	return rc;
}

int thunder_wait_for_core(unsigned long rst_base)
{

    return 1;

}

void thunder_pwrc_write_pponr(unsigned long mpidr)
{
}

void thunder_pwrc_write_ppoffr(unsigned long mpidr)
{

}

void thunder_pwrc_set_wen(unsigned long mpidr)
{

}

void thunder_pwrc_clr_wen(unsigned long mpidr)
{

}

void thunder_pwrc_write_pcoffr(unsigned long mpidr)
{

}

/* Nothing else to do here apart from initializing the lock */
int thunder_pwrc_setup(void)
{
	return 0;
}
