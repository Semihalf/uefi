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

static void check_rst_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_CIU_CIB_RST_RAWX(0));
    CHECK_CHIP_ERROR(BDK_CIU_CIB_RST_RAWX(0), s, int_perstx);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_RST_RAWX(0), s, int_linkx);
}

static void enable_rst_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_CIU_CIB_RST_ENX(0),
        c.s.int_perstx = -1;
        c.s.int_linkx = -1);
}

static void check_lmc_cn70xx(bdk_node_t node, int index)
{
    {
        BDK_CSR_INIT(c, node, BDK_LMCX_INT(index));
        CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, ded_err);
        CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, sec_err);
        CHECK_CHIP_ERROR(BDK_LMCX_INT(index), s, nxm_wr_err);
    }
    {
        BDK_CSR_INIT(c, node, BDK_CIU_CIB_LMCX_RAWX(index, 0));
        CHECK_CHIP_ERROR(BDK_CIU_CIB_LMCX_RAWX(index, 0), s, int_ddr_err);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_LMCX_RAWX(index, 0), s, int_dlc_ded);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_LMCX_RAWX(index, 0), s, int_dlc_sec);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_LMCX_RAWX(index, 0), s, int_ded_errx);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_LMCX_RAWX(index, 0), s, int_sec_errx);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_LMCX_RAWX(index, 0), s, int_nxm_wr_err);
    }
}

static void enable_lmc_cn70xx(bdk_node_t node, int index)
{
    BDK_CSR_MODIFY(c, node, BDK_LMCX_INT_EN(index),
        c.s.intr_ded_ena = -1;
        c.s.intr_sec_ena = -1;
        c.s.intr_nxm_wr_ena = -1);
    BDK_CSR_MODIFY(c, node, BDK_CIU_CIB_LMCX_ENX(index, 0),
        c.s.int_ddr_err = -1;
        c.s.int_dlc_ded = -1;
        c.s.int_dlc_sec = -1;
        c.s.int_ded_errx = -1;
        c.s.int_sec_errx = -1;
        c.s.int_nxm_wr_err = -1);
}

static void check_pem_cn70xx(bdk_node_t node, int index)
{
    BDK_CSR_INIT(c, node, BDK_PEMX_INT_SUM(index));
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, crs_dr);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, crs_er);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, rdlk);
    if (c.s.exc)
    {
        BDK_CSR_INIT(c, node, BDK_PEMX_DBG_INFO(index));
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, c_c_dbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, c_c_sbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, c_d_dbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, c_d_sbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, n_c_dbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, n_c_sbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, n_d_dbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, n_d_sbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, p_c_dbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, p_c_sbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, p_d_dbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, p_d_sbe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, datq_pe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, hdrq_pe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), cn70xx, rtry_pe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, ecrc_e);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rawwpp);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, racpp);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, ramtlp);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rarwdns);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, caar);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, racca);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, racur);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rauc);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rqo);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, fcuv);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rpe);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, fcpvwt);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, dpeoosd);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rtwdle);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rdwdle);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, mre);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rte);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, acto);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rvdm);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rumep);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rptamrc);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rpmerc);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rfemrc);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rnfemrc);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rcemrc);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rpoison);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, recrce);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rtlplle);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, rtlpmal);
        CHECK_CHIP_ERROR(BDK_PEMX_DBG_INFO(index), s, spoison);
    }
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, un_bx);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, un_b2);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, un_b1);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, up_bx);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, up_b2);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, up_b1);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, pmem); // FIXME: RO?
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, pmei); // FIXME: RO?
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, se);
    CHECK_CHIP_ERROR(BDK_PEMX_INT_SUM(index), s, aeri); // FIXME: RO?
}

static void enable_pem_cn70xx(bdk_node_t node, int index)
{
    BDK_CSR_MODIFY(c, node, BDK_PEMX_INT_ENB_INT(index),
        c.s.crs_dr = -1;
        c.s.crs_er = -1;
        c.s.rdlk = -1;
        c.s.exc = -1;
        c.s.un_bx = -1;
        c.s.un_b2 = -1;
        c.s.un_b1 = -1;
        c.s.up_bx = -1;
        c.s.up_b2 = -1;
        c.s.up_b1 = -1;
        c.s.pmem = -1;
        c.s.pmei = -1;
        c.s.se = -1;
        c.s.aeri = -1);
#if 0 // Conditionally clocked?
    BDK_CSR_MODIFY(c, node, BDK_PEMX_DBG_INFO_EN(index),
        c.cn70xx.tpcdbe1 = -1;
        c.cn70xx.tpcsbe1 = -1;
        c.cn70xx.tpcdbe0 = -1;
        c.cn70xx.tpcsbe0 = -1;
        c.cn70xx.tnfdbe1 = -1;
        c.cn70xx.tnfsbe1 = -1;
        c.cn70xx.tnfdbe0 = -1;
        c.cn70xx.tnfsbe0 = -1;
        c.cn70xx.tpfdbe1 = -1;
        c.cn70xx.tpfsbe1 = -1;
        c.cn70xx.tpfdbe0 = -1;
        c.cn70xx.tpfsbe0 = -1;
        c.s.datq_pe = -1;
        c.s.hdrq_pe = -1;
        c.cn70xx.rtry_pe = -1;
        c.s.ecrc_e = -1;
        c.s.rawwpp = -1;
        c.s.racpp = -1;
        c.s.ramtlp = -1;
        c.s.rarwdns = -1;
        c.s.caar = -1;
        c.s.racca = -1;
        c.s.racur = -1;
        c.s.rauc = -1;
        c.s.rqo = -1;
        c.s.fcuv = -1;
        c.s.rpe = -1;
        c.s.fcpvwt = -1;
        c.s.dpeoosd = -1;
        c.s.rtwdle = -1;
        c.s.rdwdle = -1;
        c.s.mre = -1;
        c.s.rte = -1;
        c.s.acto = -1;
        c.s.rvdm = -1;
        c.s.rumep = -1;
        c.s.rptamrc = -1;
        c.s.rpmerc = -1;
        c.s.rfemrc = -1;
        c.s.rnfemrc = -1;
        c.s.rcemrc = -1;
        c.s.rpoison = -1;
        c.s.recrce = -1;
        c.s.rtlplle = -1;
        c.s.rtlpmal = -1;
        c.s.spoison = -1);
#endif
}

static void check_ptp_cn70xx(bdk_node_t node)
{
    /* No errors need to be reported */
}

static void enable_ptp_cn70xx(bdk_node_t node)
{
    /* No errors need to be reported */
}

static void check_agl_cn70xx(bdk_node_t node)
{
    {
        BDK_CSR_INIT(c, node, BDK_AGL_GMX_BAD_REG);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_BAD_REG, s, txpsh);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_BAD_REG, s, txpop);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_BAD_REG, s, ovrflw);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_BAD_REG, s, statovr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_BAD_REG, s, loststat);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_BAD_REG, s, out_ovr);
    }
    {
        BDK_CSR_INIT(c, node, BDK_AGL_GMX_RXX_INT_REG(0));
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, wol);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, pause_drp);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, ifgerr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, coldet);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, falerr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, rsverr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, pcterr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, ovrerr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, niberr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, skperr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, rcverr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, lenerr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, alnerr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, fcserr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, jabber);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, maxerr);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, carext);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_RXX_INT_REG(0), s, minerr);
    }
    {
        BDK_CSR_INIT(c, node, BDK_AGL_GMX_TX_INT_REG);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_TX_INT_REG, s, ptp_lost);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_TX_INT_REG, s, late_col);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_TX_INT_REG, s, xsdef);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_TX_INT_REG, s, xscol);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_TX_INT_REG, s, undflw);
        CHECK_CHIP_ERROR(BDK_AGL_GMX_TX_INT_REG, s, pko_nxa);
    }
}

static void enable_agl_cn70xx(bdk_node_t node)
{
    /* No enables for BDK_AGL_GMX_BAD_REG? */
    BDK_CSR_MODIFY(c, node, BDK_AGL_GMX_RXX_INT_EN(0),
        c.s.wol = -1;
        c.s.pause_drp = -1;
        c.s.ifgerr = -1;
        c.s.coldet = -1;
        c.s.falerr = -1;
        c.s.rsverr = -1;
        c.s.pcterr = -1;
        c.s.ovrerr = -1;
        c.s.niberr = -1;
        c.s.skperr = -1;
        c.s.rcverr = -1;
        c.s.lenerr = -1;
        c.s.alnerr = -1;
        c.s.fcserr = -1;
        c.s.jabber = -1;
        c.s.maxerr = -1;
        c.s.carext = -1;
        c.s.minerr = -1);
    BDK_CSR_MODIFY(c, node, BDK_AGL_GMX_TX_INT_EN,
        c.s.ptp_lost = -1;
        c.s.late_col = -1;
        c.s.xsdef = -1;
        c.s.xscol = -1;
        c.s.undflw = -1;
        c.s.pko_nxa = -1);
}

static void check_agx_cn70xx(bdk_node_t node, int index)
{
    {
        BDK_CSR_INIT(c, node, BDK_GMXX_BAD_REG(index));
        CHECK_CHIP_ERROR(BDK_GMXX_BAD_REG(index), s, inb_nxa);
        CHECK_CHIP_ERROR(BDK_GMXX_BAD_REG(index), s, statovr);
        CHECK_CHIP_ERROR(BDK_GMXX_BAD_REG(index), s, loststat);
        CHECK_CHIP_ERROR(BDK_GMXX_BAD_REG(index), s, out_ovr);
    }
    for (int port=0; port<4; port++)
    {
        BDK_CSR_INIT(c, node, BDK_GMXX_RXX_INT_REG(index, port));
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, wol);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, hg2cc);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, hg2fld);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, undat);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, uneop);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, unsop);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, bad_term);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, bad_seq);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, rem_fault);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, loc_fault);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, pause_drp);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, ifgerr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, coldet);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, falerr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, rsverr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, pcterr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, ovrerr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, skperr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, rcverr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, fcserr);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, jabber);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, carext);
        CHECK_CHIP_ERROR(BDK_GMXX_RXX_INT_REG(index, port), s, minerr);
    }
    {
        BDK_CSR_INIT(c, node, BDK_GMXX_TX_INT_REG(index));
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, xchange);
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, ptp_lost);
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, late_col);
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, xsdef);
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, xscol);
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, undflw);
        CHECK_CHIP_ERROR(BDK_GMXX_TX_INT_REG(index), s, pko_nxa);
    }
    for (int port=0; port<4; port++)
    {
        BDK_CSR_INIT(c, node, BDK_PCSX_INTX_REG(index, port));
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, dbg_sync);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, dup);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, sync_bad);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, an_bad);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, rxlock);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, rxbad);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, rxerr);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, txbad);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, txfifo);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, txfifu);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, an_err);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, xmit);
        CHECK_CHIP_ERROR(BDK_PCSX_INTX_REG(index, port), s, lnkspd);
    }
    if (index == 0)
    {
        BDK_CSR_INIT(c, node, BDK_PCSXX_INT_REG(index));
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, dbg_sync);
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, algnlos);
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, synlos);
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, bitlckls);
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, rxsynbad);
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, rxbad);
        CHECK_CHIP_ERROR(BDK_PCSXX_INT_REG(index), s, txflt);
    }

}

static void enable_agx_cn70xx(bdk_node_t node, int index)
{
    for (int port=0; port<4; port++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GMXX_RXX_INT_EN(index, port),
            c.s.wol = -1;
            c.s.hg2cc = -1;
            c.s.hg2fld = -1;
            c.s.undat = -1;
            c.s.uneop = -1;
            c.s.unsop = -1;
            c.s.bad_term = -1;
            c.s.bad_seq = -1;
            c.s.rem_fault = -1;
            c.s.loc_fault = -1;
            c.s.pause_drp = -1;
            c.s.ifgerr = -1;
            c.s.coldet = -1;
            c.s.falerr = -1;
            c.s.rsverr = -1;
            c.s.pcterr = -1;
            c.s.ovrerr = -1;
            c.s.skperr = -1;
            c.s.rcverr = -1;
            c.s.fcserr = -1;
            c.s.jabber = -1;
            c.s.carext = -1;
            c.s.minerr = -1);
    }
    BDK_CSR_MODIFY(c, node, BDK_GMXX_TX_INT_EN(index),
        c.s.xchange = -1;
        c.s.ptp_lost = -1;
        c.s.late_col = -1;
        c.s.xsdef = -1;
        c.s.xscol = -1;
        c.s.undflw = -1;
        c.s.pko_nxa = -1);
    for (int port=0; port<4; port++)
    {
        BDK_CSR_MODIFY(c, node, BDK_PCSX_INTX_EN_REG(index, port),
            c.s.dbg_sync_en = -1;
            c.s.dup = -1;
            c.s.sync_bad_en = -1;
            c.s.an_bad_en = -1;
            c.s.rxlock_en = -1;
            c.s.rxbad_en = -1;
            c.s.rxerr_en = -1;
            c.s.txbad_en = -1;
            c.s.txfifo_en = -1;
            c.s.txfifu_en = -1;
            c.s.an_err_en = -1;
            c.s.xmit_en = -1;
            c.s.lnkspd_en = -1);
    }
    if (index == 0)
        BDK_CSR_MODIFY(c, node, BDK_PCSXX_INT_EN_REG(index),
            c.s.dbg_sync_en = -1;
            c.s.algnlos_en = -1;
            c.s.synlos_en = -1;
            c.s.bitlckls_en = -1;
            c.s.rxsynbad_en = -1;
            c.s.rxbad_en = -1;
            c.s.txflt_en = -1);
}

static void check_dpi_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_DPI_INT_REG);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, sprt3_rst);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, sprt2_rst);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, sprt1_rst);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, sprt0_rst);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_badfil);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_inull);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_anull);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_undflw);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_ovrflw);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_badlen);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, req_badadr);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, dmadbo);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, nfovr);
    CHECK_CHIP_ERROR(BDK_DPI_INT_REG, s, nderr);
}

static void enable_dpi_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_DPI_INT_EN,
        c.s.sprt3_rst = -1;
        c.s.sprt2_rst = -1;
        c.s.sprt1_rst = -1;
        c.s.sprt0_rst = -1;
        c.s.req_badfil = -1;
        c.s.req_inull = -1;
        c.s.req_anull = -1;
        c.s.req_undflw = -1;
        c.s.req_ovrflw = -1;
        c.s.req_badlen = -1;
        c.s.req_badadr = -1;
        c.s.dmadbo = -1;
        c.s.nfovr = -1;
        c.s.nderr = -1);
}

static void check_sli_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_SLI_INT_SUM);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, ill_pad);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, sprt3_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, sprt2_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, sprt1_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, sprt0_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pins_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pop_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pdi_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pgl_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pin_bp);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pout_err);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, psldbof);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pidbof);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, dtime);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, dcnt);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, dmafi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, mac2_int);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, cn70xx, mio_int2);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m3_un_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m3_un_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m3_up_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m3_up_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m2_un_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m2_un_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m2_up_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m2_up_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, mac1_int);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, mac0_int);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, mio_int1);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, mio_int0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m1_un_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m1_un_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m1_up_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m1_up_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m0_un_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m0_un_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m0_up_wi);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, m0_up_b0);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, ptime);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, pcnt);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, iob2big);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, bar0_to);
    CHECK_CHIP_ERROR(BDK_SLI_INT_SUM, s, rml_to);
}

static void enable_sli_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_SLI_INT_ENB_CIU,
        c.s.ill_pad = -1;
        c.s.sprt3_err = -1;
        c.s.sprt2_err = -1;
        c.s.sprt1_err = -1;
        c.s.sprt0_err = -1;
        c.s.pins_err = -1;
        c.s.pop_err = -1;
        c.s.pdi_err = -1;
        c.s.pgl_err = -1;
        c.s.pin_bp = -1;
        c.s.pout_err = -1;
        c.s.psldbof = -1;
        c.s.pidbof = -1;
        c.s.dtime = -1;
        c.s.dcnt = -1;
        c.s.dmafi = -1;
        c.s.mio_int2 = -1;
        c.s.m3_un_wi = -1;
        c.s.m3_un_b0 = -1;
        c.s.m3_up_wi = -1;
        c.s.m3_up_b0 = -1;
        c.s.m2_un_wi = -1;
        c.s.m2_un_b0 = -1;
        c.s.m2_up_wi = -1;
        c.s.m2_up_b0 = -1;
        c.s.mio_int1 = -1;
        c.s.mio_int0 = -1;
        c.s.m1_un_wi = -1;
        c.s.m1_un_b0 = -1;
        c.s.m1_up_wi = -1;
        c.s.m1_up_b0 = -1;
        c.s.m0_un_wi = -1;
        c.s.m0_un_b0 = -1;
        c.s.m0_up_wi = -1;
        c.s.m0_up_b0 = -1;
        c.s.ptime = -1;
        c.s.pcnt = -1;
        c.s.iob2big = -1;
        c.s.bar0_to = -1;
        c.s.rml_to = -1);
}

static void check_usb_cn70xx(bdk_node_t node, int index)
{
    BDK_CSR_INIT(c, node, BDK_CIU_CIB_USBDRDX_RAWX(index, 0));
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, uahc_dev_int);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, uahc_imanx_ip);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, uahc_usbsts_hse);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_ram2_dbe);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_ram2_sbe);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_ram1_dbe);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_ram1_sbe);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_ram0_dbe);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_ram0_sbe);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_xm_bad_dma);
    CHECK_CHIP_ERROR(BDK_CIU_CIB_USBDRDX_RAWX(index, 0), s, intstat_xs_ncb_oob);
}

static void enable_usb_cn70xx(bdk_node_t node, int index)
{
    BDK_CSR_MODIFY(c, node, BDK_CIU_CIB_USBDRDX_ENX(index, 0),
        c.s.uahc_dev_int = -1;
        c.s.uahc_imanx_ip = -1;
        c.s.uahc_usbsts_hse = -1;
        c.s.intstat_ram2_dbe = -1;
        c.s.intstat_ram2_sbe = -1;
        c.s.intstat_ram1_dbe = -1;
        c.s.intstat_ram1_sbe = -1;
        c.s.intstat_ram0_dbe = -1;
        c.s.intstat_ram0_sbe = -1;
        c.s.intstat_xm_bad_dma = -1;
        c.s.intstat_xs_ncb_oob = -1);
}

static void check_dfa_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_DFA_ERROR);
    CHECK_CHIP_ERROR(BDK_DFA_ERROR, s, replerr);
    CHECK_CHIP_ERROR(BDK_DFA_ERROR, s, dfanxm);
    CHECK_CHIP_ERROR(BDK_DFA_ERROR, s, cndrd);
    CHECK_CHIP_ERROR(BDK_DFA_ERROR, s, dlc0_ovferr);
    CHECK_CHIP_ERROR(BDK_DFA_ERROR, s, dc0perr);
    CHECK_CHIP_ERROR(BDK_DFA_ERROR, s, dblovf);
}

static void enable_dfa_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_DFA_INTMSK,
        c.s.replerrena = -1;
        c.s.dfanxmena = -1;
        c.s.dlc0_ovfena = -1;
        c.s.dc0pena = -1;
        c.s.dblina = -1);
}

static void check_key_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_KEY_INT_SUM);
    CHECK_CHIP_ERROR(BDK_KEY_INT_SUM, cn70xx, key_dbe);
    CHECK_CHIP_ERROR(BDK_KEY_INT_SUM, cn70xx, key_sbe);
}

static void enable_key_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_KEY_INT_ENB,
        c.s.key_dbe = -1;
        c.s.key_sbe = -1);
}

static void check_rad_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_RAD_REG_ERROR);
    CHECK_CHIP_ERROR(BDK_RAD_REG_ERROR, s, doorbell);
}

static void enable_rad_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_RAD_REG_INT_MASK,
        c.s.doorbell = -1);
}

static void check_tim_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_TIM_REG_ERROR);
    CHECK_CHIP_ERROR(BDK_TIM_REG_ERROR, s, mask);
}

static void enable_tim_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_TIM_REG_INT_MASK,
        c.s.mask = -1);
}

static void check_pko_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_PKO_REG_ERROR);
    CHECK_CHIP_ERROR(BDK_PKO_REG_ERROR, s, currzero);
    CHECK_CHIP_ERROR(BDK_PKO_REG_ERROR, s, doorbell);
    CHECK_CHIP_ERROR(BDK_PKO_REG_ERROR, s, parity);
}

static void enable_pko_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_PKO_REG_INT_MASK,
        c.s.currzero = -1;
        c.s.doorbell = -1;
        c.s.parity = -1);
}

static void check_pip_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_PIP_INT_REG);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, punyerr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, lenerr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, maxerr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, minerr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, beperr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, feperr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, todoovr);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, skprunt);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, badtag);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, prtnxa);
    CHECK_CHIP_ERROR(BDK_PIP_INT_REG, s, crcerr);
}

static void enable_pip_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_PIP_INT_EN,
        c.s.punyerr = -1;
        c.s.lenerr = -1;
        c.s.maxerr = -1;
        c.s.minerr = -1;
        c.s.beperr = -1;
        c.s.feperr = -1;
        c.s.todoovr = -1;
        c.s.skprunt = -1;
        c.s.badtag = -1;
        c.s.prtnxa = -1;
        c.s.crcerr = -1);
}

static void check_ipd_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_IPD_INT_SUM);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, d_coll);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, c_coll);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, cc_ovr);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, dc_ovr);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, bp_sub);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, prc_par3);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, prc_par2);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, prc_par1);
    CHECK_CHIP_ERROR(BDK_IPD_INT_SUM, s, prc_par0);
}

static void enable_ipd_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_IPD_INT_ENB,
        c.s.d_coll = -1;
        c.s.c_coll = -1;
        c.s.cc_ovr = -1;
        c.s.dc_ovr = -1;
        c.s.bp_sub = -1;
        c.s.prc_par3 = -1;
        c.s.prc_par2 = -1;
        c.s.prc_par1 = -1;
        c.s.prc_par0 = -1);
}

static void check_l2c_cn70xx(bdk_node_t node)
{
    {
        BDK_CSR_INIT(c, node, BDK_L2C_CBCX_INT(0));
        CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(0), s, ioccmddbe);
        CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(0), s, ioccmdsbe);
        CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(0), s, rsddbe);
        CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(0), s, rsdsbe);
    }
    {
        BDK_CSR_INIT(c, node, BDK_L2C_MCIX_INT(0));
        CHECK_CHIP_ERROR(BDK_L2C_MCIX_INT(0), s, vbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_MCIX_INT(0), s, vbfsbe);
    }
    {
        BDK_CSR_INIT(c, node, BDK_L2C_TADX_INT(0));
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, rtgdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, rtgsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, wrdislmc);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, rddislmc);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, bigrd);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, bigwr);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, holerd);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, holewr);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, noway);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, tagdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, tagsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, fbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, fbfsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, sbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, sbfsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, l2ddbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(0), cn70xx, l2dsbe);
    }
    {
        BDK_CSR_INIT(c, node, BDK_CIU_CIB_L2C_RAWX(0));
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, cbcx_int_ioccmddbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, cbcx_int_ioccmdsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, cbcx_int_rsddbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, cbcx_int_rsdsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, mcix_int_vbfdbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, mcix_int_vbfsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_rtgdbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_rtgsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_rddislmc);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_wrdislmc);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_bigrd);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_bigwr);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_holerd);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_holewr);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_noway);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_tagdbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_tagsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_fbfdbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_fbfsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_sbfdbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_sbfsbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_l2ddbe);
        CHECK_CHIP_ERROR(BDK_CIU_CIB_L2C_RAWX(0), s, tadx_int_l2dsbe);
    }
}

static void enable_l2c_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_CIU_CIB_L2C_ENX(0),
        c.s.cbcx_int_ioccmddbe = -1;
        c.s.cbcx_int_ioccmdsbe = -1;
        c.s.cbcx_int_rsddbe = -1;
        c.s.cbcx_int_rsdsbe = -1;
        c.s.mcix_int_vbfdbe = -1;
        c.s.mcix_int_vbfsbe = -1;
        c.s.tadx_int_rtgdbe = -1;
        c.s.tadx_int_rtgsbe = -1;
        c.s.tadx_int_rddislmc = -1;
        c.s.tadx_int_wrdislmc = -1;
        c.s.tadx_int_bigrd = -1;
        c.s.tadx_int_bigwr = -1;
        c.s.tadx_int_holerd = -1;
        c.s.tadx_int_holewr = -1;
        c.s.tadx_int_noway = -1;
        c.s.tadx_int_tagdbe = -1;
        c.s.tadx_int_tagsbe = -1;
        c.s.tadx_int_fbfdbe = -1;
        c.s.tadx_int_fbfsbe = -1;
        c.s.tadx_int_sbfdbe = -1;
        c.s.tadx_int_sbfsbe = -1;
        c.s.tadx_int_l2ddbe = -1;
        c.s.tadx_int_l2dsbe = -1);
}

static void check_pow_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_SSO_ECC_ERR);
    BDK_CSR_WRITE(node, BDK_SSO_ECC_ERR, c.u);
    if (c.s.iop)
        display_error(node, basename_BDK_SSO_ECC_ERR, arguments_BDK_SSO_ECC_ERR, "iop");
    if (c.s.rpe)
        display_error(node, basename_BDK_SSO_ECC_ERR, arguments_BDK_SSO_ECC_ERR, "rpe");
    if (c.s.dbe)
        display_error(node, basename_BDK_SSO_ECC_ERR, arguments_BDK_SSO_ECC_ERR, "dbe");
    if (c.s.sbe)
        display_error(node, basename_BDK_SSO_ECC_ERR, arguments_BDK_SSO_ECC_ERR, "sbe");
}

static void enable_pow_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_SSO_ECC_ERR,
        c.s.iop_ie = -1;
        c.s.rpe_ie = -1;
        c.s.dbe_ie = -1;
        c.s.sbe_ie = -1);
}

static void check_fpa_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_FPA_INT_SUM);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, paddr_e);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool7th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool6th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool5th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool4th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool3th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool2th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool1th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, pool0th);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q7_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q7_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q7_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q6_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q6_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q6_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q5_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q5_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q5_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q4_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q4_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q4_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q3_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q3_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q3_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q2_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q2_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q2_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q1_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q1_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q1_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q0_perr);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q0_coff);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, q0_und);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, fed1_dbe);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, fed1_sbe);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, fed0_dbe);
    CHECK_CHIP_ERROR(BDK_FPA_INT_SUM, s, fed0_sbe);
}

static void enable_fpa_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_FPA_INT_ENB,
        c.s.paddr_e = -1;
        c.s.pool7th = -1;
        c.s.pool6th = -1;
        c.s.pool5th = -1;
        c.s.pool4th = -1;
        c.s.pool3th = -1;
        c.s.pool2th = -1;
        c.s.pool1th = -1;
        c.s.pool0th = -1;
        c.s.q7_perr = -1;
        c.s.q7_coff = -1;
        c.s.q7_und = -1;
        c.s.q6_perr = -1;
        c.s.q6_coff = -1;
        c.s.q6_und = -1;
        c.s.q5_perr = -1;
        c.s.q5_coff = -1;
        c.s.q5_und = -1;
        c.s.q4_perr = -1;
        c.s.q4_coff = -1;
        c.s.q4_und = -1;
        c.s.q3_perr = -1;
        c.s.q3_coff = -1;
        c.s.q3_und = -1;
        c.s.q2_perr = -1;
        c.s.q2_coff = -1;
        c.s.q2_und = -1;
        c.s.q1_perr = -1;
        c.s.q1_coff = -1;
        c.s.q1_und = -1;
        c.s.q0_perr = -1;
        c.s.q0_coff = -1;
        c.s.q0_und = -1;
        c.s.fed1_dbe = -1;
        c.s.fed1_sbe = -1;
        c.s.fed0_dbe = -1;
        c.s.fed0_sbe = -1);
}

static void check_iob_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_IOB_INT_SUM);
    //CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, outb_mat);
    //CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, inb_mat);
    CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, p_dat);
    CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, np_dat);
    CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, p_eop);
    CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, p_sop);
    CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, np_eop);
    CHECK_CHIP_ERROR(BDK_IOB_INT_SUM, s, np_sop);
}

static void enable_iob_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_IOB_INT_ENB,
        //c.s.outb_mat = -1;
        //c.s.inb_mat = -1;
        c.s.p_dat = -1;
        c.s.np_dat = -1;
        c.s.p_eop = -1;
        c.s.p_sop = -1;
        c.s.np_eop = -1;
        c.s.np_sop = -1);
}

static void check_mio_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_MIO_BOOT_ERR);
    CHECK_CHIP_ERROR(BDK_MIO_BOOT_ERR, s, wait_err);
    CHECK_CHIP_ERROR(BDK_MIO_BOOT_ERR, s, adr_err);
}

static void enable_mio_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_MIO_BOOT_INT,
        c.s.wait_int = -1;
        c.s.adr_int = -1);
}

static void check_nand_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_MIO_EMM_INT);
    CHECK_CHIP_ERROR(BDK_MIO_EMM_INT, s, switch_err);
    CHECK_CHIP_ERROR(BDK_MIO_EMM_INT, s, dma_err);
    CHECK_CHIP_ERROR(BDK_MIO_EMM_INT, s, cmd_err);
}

static void enable_nand_cn70xx(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_MIO_EMM_INT_EN,
        c.s.switch_err = -1;
        c.s.dma_err = -1;
        c.s.cmd_err = -1);
}

static void check_wdog_cn70xx(bdk_node_t node)
{
    /* No errors need to be reported */
}

static void enable_wdog_cn70xx(bdk_node_t node)
{
    /* No errors need to be reported */
}

static void check_cn70xx(bdk_node_t node)
{
    BDK_CSR_INIT(c, node, BDK_CIU_INT_SUM1);
    if (c.s.rst) check_rst_cn70xx(node);
    if (c.s.lmc0) check_lmc_cn70xx(node, 0);
    if (c.s.pem2) check_pem_cn70xx(node, 2);
    if (c.s.pem1) check_pem_cn70xx(node, 1);
    if (c.s.pem0) check_pem_cn70xx(node, 0);
    if (c.s.ptp) check_ptp_cn70xx(node);
    if (c.s.agl) check_agl_cn70xx(node);
    if (c.s.agx1) check_agx_cn70xx(node, 1);
    if (c.s.agx0) check_agx_cn70xx(node, 0);
    if (c.s.dpi) check_dpi_cn70xx(node);
    if (c.s.sli) check_sli_cn70xx(node);
    if (c.s.usb) check_usb_cn70xx(node, 0);
    if (c.s.dfa) check_dfa_cn70xx(node);
    if (c.s.key) check_key_cn70xx(node);
    if (c.s.rad) check_rad_cn70xx(node);
    if (c.s.tim) check_tim_cn70xx(node);
    if (c.s.pko) check_pko_cn70xx(node);
    if (c.s.pip) check_pip_cn70xx(node);
    if (c.s.ipd) check_ipd_cn70xx(node);
    if (c.s.l2c) check_l2c_cn70xx(node);
    if (c.s.pow) check_pow_cn70xx(node);
    if (c.s.fpa) check_fpa_cn70xx(node);
    if (c.s.iob) check_iob_cn70xx(node);
    if (c.s.mio) check_mio_cn70xx(node);
    if (c.s.nand) check_nand_cn70xx(node);
    if (c.s.usb1) check_usb_cn70xx(node, 1);
    if (c.s.wdog) check_wdog_cn70xx(node);
}

static void enable_cn70xx(bdk_node_t node)
{
    enable_rst_cn70xx(node);
    enable_lmc_cn70xx(node, 0);
    enable_pem_cn70xx(node, 2);
    enable_pem_cn70xx(node, 1);
    enable_pem_cn70xx(node, 0);
    enable_ptp_cn70xx(node);
    enable_agl_cn70xx(node);
    enable_agx_cn70xx(node, 1);
    enable_agx_cn70xx(node, 0);
    enable_dpi_cn70xx(node);
    enable_sli_cn70xx(node);
    enable_usb_cn70xx(node, 0);
    enable_dfa_cn70xx(node);
    enable_key_cn70xx(node);
    enable_rad_cn70xx(node);
    enable_tim_cn70xx(node);
    enable_pko_cn70xx(node);
    enable_pip_cn70xx(node);
    enable_ipd_cn70xx(node);
    enable_l2c_cn70xx(node);
    enable_pow_cn70xx(node);
    enable_fpa_cn70xx(node);
    enable_iob_cn70xx(node);
    enable_mio_cn70xx(node);
    enable_nand_cn70xx(node);
    enable_usb_cn70xx(node, 1);
    enable_wdog_cn70xx(node);
}

static void check_cn78xx(bdk_node_t node)
{
    for (int index = 0; index < 4; index++)
    {
        {
            BDK_CSR_INIT(c, node, BDK_L2C_CBCX_INT(index));
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, holerd);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, holewr);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, iowrdisoci);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, iorddisoci);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, mibdbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, mibsbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, ioccmddbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, ioccmdsbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, rsddbe);
            CHECK_CHIP_ERROR(BDK_L2C_CBCX_INT(index), s, rsdsbe);
        }
        {
            BDK_CSR_INIT(c, node, BDK_L2C_MCIX_INT(index));
            CHECK_CHIP_ERROR(BDK_L2C_MCIX_INT(index), s, vbfdbe);
            CHECK_CHIP_ERROR(BDK_L2C_MCIX_INT(index), s, vbfsbe);
        }
    }
    for (int index = 0; index < 8; index++)
    {
        BDK_CSR_INIT(c, node, BDK_L2C_TADX_INT(index));
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, wrdisoci);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, rddisoci);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, rtgdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, rtgsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, lfbto);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, wrdislmc);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, rddislmc);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, bigrd);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, bigwr);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, holerd);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, holewr);
        //CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, noway); /* Happens when we run with L2 locked */
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, tagdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, tagsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, reserved_6_7);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, fbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, fbfsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, sbfdbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, sbfsbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, l2ddbe);
        CHECK_CHIP_ERROR(BDK_L2C_TADX_INT(index), s, l2dsbe);
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

static void enable_cn78xx(bdk_node_t node)
{
    /* Do nothing for now */
}

void (*bdk_error_check)(bdk_node_t node) = NULL;
void bdk_error_enable(bdk_node_t node)
{
    if (OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        enable_cn70xx(node);
        check_cn70xx(node);
        bdk_error_check = check_cn70xx;
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        enable_cn78xx(node);
        check_cn78xx(node);
        bdk_error_check = check_cn78xx;
    }
    else
        bdk_error("Error reporting not implemented for this chip\n");
}
