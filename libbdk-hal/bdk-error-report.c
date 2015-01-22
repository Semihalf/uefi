#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(ERROR_DECODE);

#define CLEAR_CHIP_ERROR(csr, chip, field)  \
if (c.chip.field) {                         \
    typedef_##csr w1c;                      \
    w1c.u = 0;                              \
    w1c.chip.field = c.chip.field;          \
    bdk_csr_write(node, bustype_##csr,      \
        busnum_##csr, sizeof(typedef_##csr),\
        csr, w1c.u);                        \
}

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
	/* LMC0 and LMC1 are always enabled, though we never set their INTF_EN bits */
        if (((index < 2) || (lmcx_dll_ctl2.s.intf_en == 1)) && !lmcx_dll_ctl2.s.dreset)
        {
            BDK_CSR_INIT(c, node, BDK_LMCX_INT(index));
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, macram_ded_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, macram_sec_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, ddr_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, dlcram_ded_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, dlcram_sec_err);
            //CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, ded_err);
            //CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, sec_err);
            CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, nxm_wr_err);
            /* A double bit error overwrites single info, so only
               report single bit errors if there hasn't been a
               double bit error */
            if (c.s.ded_err || c.s.sec_err)
            {
                BDK_CSR_INIT(fadr, node, BDK_LMCX_FADR(index));
                BDK_CSR_INIT(ecc_synd, node, BDK_LMCX_ECC_SYND(index));
                CLEAR_CHIP_ERROR(BDK_LMCX_INT(index), s, ded_err);
                CLEAR_CHIP_ERROR(BDK_LMCX_INT(index), s, sec_err);
                if (c.s.sec_err)
                    bdk_atomic_add64_nosync(&__bdk_dram_ecc_single_bit_errors, 1);
                if (c.s.ded_err)
                    bdk_atomic_add64_nosync(&__bdk_dram_ecc_double_bit_errors, 1);
                bdk_error("N%d.LMC%d: ECC %s bit error (DIMM%d,Rank%d,Bank%d,Row 0x%x,Col 0x%x, ECC_SYND 0x%016lx)\n",
                    node, index, (c.s.ded_err) ? "double" : "single",
                    fadr.s.fdimm, fadr.s.fbunk, fadr.s.fbank,
                    fadr.s.frow, fadr.s.fcol, ecc_synd.u);
            }
        }
    }


    BDK_CSR_INIT(l2c_oci_ctl, node, BDK_L2C_OCI_CTL);
    if (l2c_oci_ctl.s.enaoci > 1)
    {
        /* Check CCPI errors */
        BDK_CSR_INIT(c, node, BDK_OCX_COM_INT);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, io_badid);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, mem_badid);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, copr_badid);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, win_req_badid);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, win_req_tout);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, win_req_xmit);
        CHECK_CHIP_ERROR(BDK_OCX_COM_INT, s, win_rsp);
        if (c.s.rx_lane)
        {
            /* Check CCPI link errors */
            CLEAR_CHIP_ERROR(BDK_OCX_COM_INT, s, rx_lane);
            for (int lane=0; lane<24; lane++)
            {
                BDK_CSR_INIT(c, node, BDK_OCX_LNEX_INT(lane));
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, disp_err);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, bad_64b67b);
                CLEAR_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, stat_cnt_ovfl);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, stat_msg);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, dskew_fifo_ovfl);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, scrm_sync_loss);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, ukwn_cntl_word);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, crc32_err);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, bdry_sync_loss);
                CHECK_CHIP_ERROR(BDK_OCX_LNEX_INT(lane), s, serdes_lock_loss);
            }
        }
        /* Check high level link errors */
        for (int link=0; link<3; link++)
        {
            BDK_CSR_INIT(c, node, BDK_OCX_COM_LINKX_INT(link));
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, bad_word);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, align_fail);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, align_done);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, up);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, stop);
            if (c.s.blk_err)
            {
                BDK_CSR_MODIFY(c, node, BDK_OCX_RLKX_BLK_ERR(link), c.s.count = 0);
                CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, blk_err);
            }
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, reinit);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, lnk_data);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, rxfifo_dbe);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, rxfifo_sbe);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, txfifo_dbe);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, txfifo_sbe);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, replay_dbe);
            CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, replay_sbe);
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        enable_cn88xx(node);
        check_cn88xx(node);
        bdk_error_check = check_cn88xx;
    }
    else
        bdk_error("Error reporting not implemented for this chip\n");
}
