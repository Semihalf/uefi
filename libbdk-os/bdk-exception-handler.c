#include <bdk.h>
#include <stdio.h>

void __bdk_exception_handler(uint64_t saved_regs[32])
{
    printf("******************************************************************\n");
    printf("Node %d, Core %d: Unhandled Exception\n", bdk_numa_local(), bdk_get_core_num());
    printf("******************************************************************\n");
    for (int reg=0; reg<16; reg++)
    {
        printf("x%02d: 0x%016lx   x%02d: 0x%016lx\n",
            reg, saved_regs[reg], reg+16, saved_regs[reg+16]);
    }
    printf("******************************************************************\n");
    for (int i=0; i<128; i+=8)
        printf("stack[0x%02x] = 0x%016lx\n", i, *(uint64_t*)(saved_regs[32] + i));
    printf("******************************************************************\n");
    while (1) {}
}
