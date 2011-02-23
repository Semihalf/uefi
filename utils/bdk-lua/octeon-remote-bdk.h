#ifndef __OCTEON_REMOTE_BDK_H__
#define __OCTEON_REMOTE_BDK_H__

extern void __bdk_csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2) __attribute__ ((noreturn));

#include <libbdk-arch/bdk-model.h>
#include <libbdk-arch/bdk-csr.h>
#include <libbdk-arch/bdk-csrs.h>
#include <libbdk-hal/bdk-swap.h>

#endif
