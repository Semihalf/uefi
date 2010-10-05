#include <bdk.h>

/**
 * Due to errata G-720, the 2nd order CDR circuit on CN52XX pass
 * 1 doesn't work properly. The following code disables 2nd order
 * CDR for the specified QLM.
 *
 * @param qlm    QLM to disable 2nd order CDR for.
 */
void __bdk_helper_errata_qlm_disable_2nd_order_cdr(int qlm)
{
    int lane;
    bdk_helper_qlm_jtag_init();
    /* We need to load all four lanes of the QLM, a total of 1072 bits */
    for (lane=0; lane<4; lane++)
    {
        /* Each lane has 268 bits. We need to set cfg_cdr_incx<67:64>=3 and
            cfg_cdr_secord<77>=1. All other bits are zero. Bits go in LSB
            first, so start off with the zeros for bits <63:0> */
        bdk_helper_qlm_jtag_shift_zeros(qlm, 63 - 0 + 1);
        /* cfg_cdr_incx<67:64>=3 */
        bdk_helper_qlm_jtag_shift(qlm, 67 - 64 + 1, 3);
        /* Zeros for bits <76:68> */
        bdk_helper_qlm_jtag_shift_zeros(qlm, 76 - 68 + 1);
        /* cfg_cdr_secord<77>=1 */
        bdk_helper_qlm_jtag_shift(qlm, 77 - 77 + 1, 1);
        /* Zeros for bits <267:78> */
        bdk_helper_qlm_jtag_shift_zeros(qlm, 267 - 78 + 1);
    }
    bdk_helper_qlm_jtag_update(qlm);
}
