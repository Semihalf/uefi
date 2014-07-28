#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(ERROR_DECODE);

#define CHECK_CHIP_ERROR(csr, chip, field)  \
if (c.chip.field) {                         \
    typedef_##csr w1c;                      \
    w1c.u = 0;                              \
    w1c.chip.field = c.chip.field;          \
    bdk_csr_write(node, bustype_##csr,      \
        busnum_##csr, sizeof(typedef_##csr),\
        csr, w1c.u);                        \
    display_error(node, basename_##csr, arguments_##csr, #field); \
}

static void display_error(bdk_node_t node, const char *csr_name, int arg1, int arg2, int arg3, int arg4, const char *field_name)
{
    if (arg4 != -1)
        bdk_error("N%d %s(%d,%d,%d,%d)[%s]\n", node, csr_name, arg1, arg2, arg3, arg4, field_name);
    else if (arg3 != -1)
        bdk_error("N%d %s(%d,%d,%d)[%s]\n", node, csr_name, arg1, arg2, arg3, field_name);
    else if (arg2 != -1)
        bdk_error("N%d %s(%d,%d)[%s]\n", node, csr_name, arg1, arg2, field_name);
    else if (arg1 != -1)
        bdk_error("N%d %s(%d)[%s]\n", node, csr_name, arg1, field_name);
    else
        bdk_error("N%d %s[%s]\n", node, csr_name, field_name);
}

static void check_cn88xx(bdk_node_t node)
{
    for (int index = 0; index < 4; index++)
    {
        {
            BDK_CSR_INIT(c, node, BDK_L2C_CBCX_INT_W1C(index));
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT_W1C(index), s, iowrdisoci);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT_W1C(index), s, iorddisoci);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT_W1C(index), s, mibdbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT_W1C(index), s, mibsbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT_W1C(index), s, rsddbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT_W1C(index), s, rsdsbe);
        }
        {
            BDK_CSR_INIT(c, node, BDK_L2C_MCIX_INT_W1C(index));
            CHECK_CHIP_ERROR(BDK_L2C_MCIX_INT_W1C(index), s, vbfdbe);
            CHECK_CHIP_ERROR(BDK_L2C_MCIX_INT_W1C(index), s, vbfsbe);
        }
    }
    for (int index = 0; index < 8; index++)
    {
        BDK_CSR_INIT(c, node, BDK_L2C_TADX_INT_W1C(index));
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, wrdisoci);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, rddisoci);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, rtgdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, rtgsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, lfbto);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, wrdislmc);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, rddislmc);
        //CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, noway); /* Happens when we run with L2 locked */
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, tagdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, tagsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, reserved_6_7);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, fbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, fbfsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, sbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, sbfsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, l2ddbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT_W1C(index), s, l2dsbe);
    }

    for (int index = 0; index < 4; index++)
    {
        BDK_CSR_INIT(lmcx_dll_ctl2, node, BDK_LMCX_DLL_CTL2(index));
        if (lmcx_dll_ctl2.s.intf_en)
        {
            BDK_CSR_INIT(c, node, BDK_LMCX_INT(index));
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, dlcram_ded_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, dlcram_sec_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, ded_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, sec_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, nxm_wr_err);
        }
    }
}

static void enable_cn88xx(bdk_node_t node)
{
    /* Do nothing for now */
}

void (*bdk_error_check)(bdk_node_t node) = NULL;
void bdk_error_enable(bdk_node_t node)
{
    if (CAVIUM_IS_MODEL(OCTEON_CN88XX))
    {
        enable_cn88xx(node);
        check_cn88xx(node);
        bdk_error_check = check_cn88xx;
    }
    else
        bdk_error("Error reporting not implemented for this chip\n");
}
