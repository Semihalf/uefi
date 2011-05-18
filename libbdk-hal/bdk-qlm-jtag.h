/* These are the low level bit programming functions for the QLM JTAG
    chains. These should not be used directly. Instead you should use
    the higher level functions in bdk-qlm */

extern void __bdk_qlm_jtag_init(void);
extern uint32_t __bdk_qlm_jtag_shift(int qlm, int bits, uint32_t data);
extern void __bdk_qlm_jtag_shift_zeros(int qlm, int bits);
extern void __bdk_qlm_jtag_update(int qlm);
extern void __bdk_qlm_jtag_capture(int qlm);

