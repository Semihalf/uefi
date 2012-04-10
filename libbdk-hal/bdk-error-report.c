#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(ERROR_DECODE);

#define CHECK_ERROR(csr, field)             \
if (c.s.field) {                            \
    typedef_##csr w1c;                      \
    w1c.u = 0;                              \
    w1c.s.field = c.s.field;                \
    bdk_csr_write(bustype_##csr,            \
        busnum_##csr, sizeof(typedef_##csr),\
        csr, w1c.u);                        \
    bdk_error("%s[%s]\n", #csr, #field);    \
}

static void check_agl(void)
{
    {
        BDK_CSR_INIT(c, BDK_AGL_GMX_BAD_REG);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, loststat);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, out_ovr);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, ovrflw);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, ovrflw1);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, txpop);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, txpop1);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, txpsh);
        CHECK_ERROR(BDK_AGL_GMX_BAD_REG, txpsh1);
    }
    {
        BDK_CSR_INIT(c, BDK_AGL_GMX_TX_INT_REG);
        CHECK_ERROR(BDK_AGL_GMX_TX_INT_REG, pko_nxa);
        CHECK_ERROR(BDK_AGL_GMX_TX_INT_REG, undflw);
    }
    int max_agl = bdk_if_num_interfaces(BDK_IF_MGMT);
    for (int agl=0; agl<max_agl; agl++)
    {
        BDK_CSR_INIT(c, BDK_AGL_GMX_RXX_INT_REG(agl));
        CHECK_ERROR(BDK_AGL_GMX_RXX_INT_REG(agl), ovrerr);
        CHECK_ERROR(BDK_AGL_GMX_RXX_INT_REG(agl), skperr);
    }
}

static void check_dfa(void)
{
    BDK_CSR_INIT(c, BDK_DFA_ERROR);
    CHECK_ERROR(BDK_DFA_ERROR, dblovf);
    CHECK_ERROR(BDK_DFA_ERROR, dc0perr);
    CHECK_ERROR(BDK_DFA_ERROR, dc1perr);
    CHECK_ERROR(BDK_DFA_ERROR, dc2perr);
    CHECK_ERROR(BDK_DFA_ERROR, dfanxm);
    CHECK_ERROR(BDK_DFA_ERROR, dlc0_ovferr);
    CHECK_ERROR(BDK_DFA_ERROR, dlc1_ovferr);
    CHECK_ERROR(BDK_DFA_ERROR, replerr);
}

static void check_dpi(void)
{
    {
        BDK_CSR_INIT(c, BDK_DPI_INT_REG);
        CHECK_ERROR(BDK_DPI_INT_REG, dmadbo);
        CHECK_ERROR(BDK_DPI_INT_REG, nderr);
        CHECK_ERROR(BDK_DPI_INT_REG, nfovr);
        CHECK_ERROR(BDK_DPI_INT_REG, req_anull);
        CHECK_ERROR(BDK_DPI_INT_REG, req_badadr);
        CHECK_ERROR(BDK_DPI_INT_REG, req_badfil);
        CHECK_ERROR(BDK_DPI_INT_REG, req_badlen);
        CHECK_ERROR(BDK_DPI_INT_REG, req_inull);
        CHECK_ERROR(BDK_DPI_INT_REG, req_ovrflw);
        CHECK_ERROR(BDK_DPI_INT_REG, req_undflw);
        CHECK_ERROR(BDK_DPI_INT_REG, sprt0_rst);
        CHECK_ERROR(BDK_DPI_INT_REG, sprt1_rst);
        CHECK_ERROR(BDK_DPI_INT_REG, sprt2_rst);
        CHECK_ERROR(BDK_DPI_INT_REG, sprt3_rst);
    }
    {
        BDK_CSR_INIT(c, BDK_DPI_PKT_ERR_RSP);
        CHECK_ERROR(BDK_DPI_PKT_ERR_RSP, pkterr);
    }
    {
        BDK_CSR_INIT(c, BDK_DPI_REQ_ERR_RSP);
        CHECK_ERROR(BDK_DPI_REQ_ERR_RSP, qerr);
    }
    {
        BDK_CSR_INIT(c, BDK_DPI_REQ_ERR_RST);
        CHECK_ERROR(BDK_DPI_REQ_ERR_RST, qerr);
    }
}

static void check_fpa(void)
{
    BDK_CSR_INIT(c, BDK_FPA_INT_SUM);
    CHECK_ERROR(BDK_FPA_INT_SUM, fed0_dbe);
    CHECK_ERROR(BDK_FPA_INT_SUM, fed0_sbe);
    CHECK_ERROR(BDK_FPA_INT_SUM, fed1_dbe);
    CHECK_ERROR(BDK_FPA_INT_SUM, fed1_sbe);
    CHECK_ERROR(BDK_FPA_INT_SUM, free0);
    CHECK_ERROR(BDK_FPA_INT_SUM, free1);
    CHECK_ERROR(BDK_FPA_INT_SUM, free2);
    CHECK_ERROR(BDK_FPA_INT_SUM, free3);
    CHECK_ERROR(BDK_FPA_INT_SUM, free4);
    CHECK_ERROR(BDK_FPA_INT_SUM, free5);
    CHECK_ERROR(BDK_FPA_INT_SUM, free6);
    CHECK_ERROR(BDK_FPA_INT_SUM, free7);
    CHECK_ERROR(BDK_FPA_INT_SUM, free8);
    CHECK_ERROR(BDK_FPA_INT_SUM, paddr_e);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool0th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool1th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool2th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool3th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool4th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool5th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool6th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool7th);
    CHECK_ERROR(BDK_FPA_INT_SUM, pool8th);
    CHECK_ERROR(BDK_FPA_INT_SUM, q0_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q0_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q0_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q1_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q1_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q1_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q2_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q2_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q2_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q3_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q3_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q3_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q4_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q4_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q4_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q5_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q5_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q5_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q6_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q6_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q6_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q7_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q7_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q7_und);
    CHECK_ERROR(BDK_FPA_INT_SUM, q8_coff);
    CHECK_ERROR(BDK_FPA_INT_SUM, q8_perr);
    CHECK_ERROR(BDK_FPA_INT_SUM, q8_und);
}

static void check_gmx(int gmx)
{
    int max_index = (OCTEON_IS_MODEL(OCTEON_CNF71XX)) ? 2 : 4;
    for (int index=0; index<max_index; index++)
    {
        BDK_CSR_INIT(c, BDK_GMXX_RXX_INT_REG(index, gmx));
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), bad_seq);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), bad_term);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), carext);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), hg2cc);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), hg2fld);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), loc_fault);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), ovrerr);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), rem_fault);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), skperr);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), undat);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), uneop);
        CHECK_ERROR(BDK_GMXX_RXX_INT_REG(index, gmx), unsop);
    }
    {
        BDK_CSR_INIT(c, BDK_GMXX_TX_INT_REG(gmx));
        CHECK_ERROR(BDK_GMXX_TX_INT_REG(gmx), pko_nxa);
        CHECK_ERROR(BDK_GMXX_TX_INT_REG(gmx), pko_nxp);
        CHECK_ERROR(BDK_GMXX_TX_INT_REG(gmx), ptp_lost);
        CHECK_ERROR(BDK_GMXX_TX_INT_REG(gmx), undflw);
    }
    {
        BDK_CSR_INIT(c, BDK_GMXX_BAD_REG(gmx));
        CHECK_ERROR(BDK_GMXX_BAD_REG(gmx), inb_nxa);
        CHECK_ERROR(BDK_GMXX_BAD_REG(gmx), loststat);
        CHECK_ERROR(BDK_GMXX_BAD_REG(gmx), out_ovr);
        CHECK_ERROR(BDK_GMXX_BAD_REG(gmx), statovr);
    }
}

static void check_ilk(void)
{
    BDK_CSR_INIT(c, BDK_ILK_GBL_INT);
    CHECK_ERROR(BDK_ILK_GBL_INT, rxf_ctl_perr);
    CHECK_ERROR(BDK_ILK_GBL_INT, rxf_lnk0_perr);
    CHECK_ERROR(BDK_ILK_GBL_INT, rxf_lnk1_perr);
    CHECK_ERROR(BDK_ILK_GBL_INT, rxf_pop_empty);
    CHECK_ERROR(BDK_ILK_GBL_INT, rxf_push_full);

    for (int ilk=0; ilk<2; ilk++)
    {
        {
            BDK_CSR_INIT(c, BDK_ILK_TXX_INT(ilk));
            CHECK_ERROR(BDK_ILK_TXX_INT(ilk), bad_pipe);
            CHECK_ERROR(BDK_ILK_TXX_INT(ilk), bad_seq);
            CHECK_ERROR(BDK_ILK_TXX_INT(ilk), txf_err);
        }
        {
            BDK_CSR_INIT(c, BDK_ILK_RXX_INT(ilk));
            CHECK_ERROR(BDK_ILK_RXX_INT(ilk), crc24_err);
            CHECK_ERROR(BDK_ILK_RXX_INT(ilk), lane_bad_word);
            CHECK_ERROR(BDK_ILK_RXX_INT(ilk), pkt_drop_rid);
            CHECK_ERROR(BDK_ILK_RXX_INT(ilk), pkt_drop_rxf);
            CHECK_ERROR(BDK_ILK_RXX_INT(ilk), pkt_drop_sop);
        }
    }
    for (int lane=0; lane<8; lane++)
    {
        BDK_CSR_INIT(c, BDK_ILK_RX_LNEX_INT(lane));
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), bad_64b67b);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), bdry_sync_loss);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), crc32_err);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), dskew_fifo_ovfl);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), scrm_sync_loss);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), serdes_lock_loss);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), stat_msg);
        CHECK_ERROR(BDK_ILK_RX_LNEX_INT(lane), ukwn_cntl_word);
    }
}

static void check_iob(void)
{
    BDK_CSR_INIT(c, BDK_IOB0_INT_SUM);
    CHECK_ERROR(BDK_IOB0_INT_SUM, np_dat);
    CHECK_ERROR(BDK_IOB0_INT_SUM, np_eop);
    CHECK_ERROR(BDK_IOB0_INT_SUM, np_sop);
    CHECK_ERROR(BDK_IOB0_INT_SUM, p_dat);
    CHECK_ERROR(BDK_IOB0_INT_SUM, p_eop);
    CHECK_ERROR(BDK_IOB0_INT_SUM, p_sop);
}

static void check_ipd(void)
{
    BDK_CSR_INIT(c, BDK_IPD_INT_SUM);
    CHECK_ERROR(BDK_IPD_INT_SUM, bc_ovr);
    CHECK_ERROR(BDK_IPD_INT_SUM, bp_sub);
    CHECK_ERROR(BDK_IPD_INT_SUM, c_coll);
    CHECK_ERROR(BDK_IPD_INT_SUM, cc_ovr);
    CHECK_ERROR(BDK_IPD_INT_SUM, d_coll);
    CHECK_ERROR(BDK_IPD_INT_SUM, dat);
    CHECK_ERROR(BDK_IPD_INT_SUM, dc_ovr);
    CHECK_ERROR(BDK_IPD_INT_SUM, eop);
    CHECK_ERROR(BDK_IPD_INT_SUM, prc_par0);
    CHECK_ERROR(BDK_IPD_INT_SUM, prc_par1);
    CHECK_ERROR(BDK_IPD_INT_SUM, prc_par2);
    CHECK_ERROR(BDK_IPD_INT_SUM, prc_par3);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw0_dbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw0_sbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw1_dbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw1_sbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw2_dbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw2_sbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw3_dbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, pw3_sbe);
    CHECK_ERROR(BDK_IPD_INT_SUM, sop);
}

static void check_key(void)
{
    BDK_CSR_INIT(c, BDK_KEY_INT_SUM);
    CHECK_ERROR(BDK_KEY_INT_SUM, ked0_dbe);
    CHECK_ERROR(BDK_KEY_INT_SUM, ked0_sbe);
    CHECK_ERROR(BDK_KEY_INT_SUM, ked1_dbe);
    CHECK_ERROR(BDK_KEY_INT_SUM, ked1_sbe);
}

static void check_l2c_tad(int tad)
{
    BDK_CSR_INIT(c, BDK_L2C_TADX_INT(tad));
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), l2ddbe);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), l2dsbe);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), noway);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), rddislmc);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), tagdbe);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), tagsbe);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), vbfdbe);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), vbfsbe);
    CHECK_ERROR(BDK_L2C_TADX_INT(tad), wrdislmc);
}

static void check_l2c(void)
{
    BDK_CSR_INIT(c, BDK_L2C_INT_REG);
    CHECK_ERROR(BDK_L2C_INT_REG, bigrd);
    CHECK_ERROR(BDK_L2C_INT_REG, bigwr);
    CHECK_ERROR(BDK_L2C_INT_REG, holerd);
    CHECK_ERROR(BDK_L2C_INT_REG, holewr);
    if (c.s.tad0) check_l2c_tad(0);
    if (c.s.tad1) check_l2c_tad(1);
    if (c.s.tad2) check_l2c_tad(2);
    if (c.s.tad3) check_l2c_tad(3);
    CHECK_ERROR(BDK_L2C_INT_REG, vrtadrng);
    CHECK_ERROR(BDK_L2C_INT_REG, vrtidrng);
    CHECK_ERROR(BDK_L2C_INT_REG, vrtpe);
    CHECK_ERROR(BDK_L2C_INT_REG, vrtwr);
}

static void check_lmc(int lmc)
{
    BDK_CSR_INIT(c, BDK_LMCX_INT(lmc));
    CHECK_ERROR(BDK_LMCX_INT(lmc), ded_err);
    CHECK_ERROR(BDK_LMCX_INT(lmc), nxm_wr_err);
    CHECK_ERROR(BDK_LMCX_INT(lmc), sec_err);
}

static void check_mio(void)
{
    {
        BDK_CSR_INIT(c, BDK_MIO_BOOT_ERR);
        CHECK_ERROR(BDK_MIO_BOOT_ERR, adr_err);
        CHECK_ERROR(BDK_MIO_BOOT_ERR, wait_err);
    }
    {
        BDK_CSR_INIT(c, BDK_MIO_RST_INT);
        CHECK_ERROR(BDK_MIO_RST_INT, perst0);
        CHECK_ERROR(BDK_MIO_RST_INT, perst1);
        CHECK_ERROR(BDK_MIO_RST_INT, rst_link0);
        CHECK_ERROR(BDK_MIO_RST_INT, rst_link1);
        CHECK_ERROR(BDK_MIO_RST_INT, rst_link2);
        CHECK_ERROR(BDK_MIO_RST_INT, rst_link3);
    }
}

static void check_mix(int mix)
{
    BDK_CSR_INIT(c, BDK_MIXX_ISR(mix));
    CHECK_ERROR(BDK_MIXX_ISR(mix), data_drp);
    CHECK_ERROR(BDK_MIXX_ISR(mix), idblovf);
    CHECK_ERROR(BDK_MIXX_ISR(mix), irun);
    CHECK_ERROR(BDK_MIXX_ISR(mix), odblovf);
    CHECK_ERROR(BDK_MIXX_ISR(mix), orun);
}

static void check_nand(void)
{
    BDK_CSR_INIT(c, BDK_NDF_INT);
    CHECK_ERROR(BDK_NDF_INT, ecc_1bit);
    CHECK_ERROR(BDK_NDF_INT, ecc_mult);
    CHECK_ERROR(BDK_NDF_INT, ovrf);
    CHECK_ERROR(BDK_NDF_INT, sm_bad);
    CHECK_ERROR(BDK_NDF_INT, wdog);
}

static void check_pcm(void)
{
    for (int pcm=0; pcm<4; pcm++)
    {
        BDK_CSR_INIT(c, BDK_PCMX_INT_SUM(pcm));
        CHECK_ERROR(BDK_PCMX_INT_SUM(pcm), fsyncextra);
        CHECK_ERROR(BDK_PCMX_INT_SUM(pcm), fsyncmissed);
        CHECK_ERROR(BDK_PCMX_INT_SUM(pcm), rxovf);
        CHECK_ERROR(BDK_PCMX_INT_SUM(pcm), txempty);
    }
}

static void check_pcs(int pcs)
{
    int max_index = (OCTEON_IS_MODEL(OCTEON_CNF71XX)) ? 2 : 4;
    for (int index=0; index<max_index; index++)
    {
        BDK_CSR_INIT(c, BDK_PCSX_INTX_REG(index, pcs));
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), an_bad);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), an_err);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), dbg_sync);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), rxbad);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), rxlock);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), sync_bad);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), txbad);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), txfifo);
        CHECK_ERROR(BDK_PCSX_INTX_REG(index, pcs), txfifu);
    }
}

static void check_pcsx(int pcsx)
{
    BDK_CSR_INIT(c, BDK_PCSXX_INT_REG(pcsx));
    CHECK_ERROR(BDK_PCSXX_INT_REG(pcsx), rxbad);
    CHECK_ERROR(BDK_PCSXX_INT_REG(pcsx), rxsynbad);
    CHECK_ERROR(BDK_PCSXX_INT_REG(pcsx), txflt);
}

static void check_pem(int pem)
{
    BDK_CSR_INIT(c, BDK_PEMX_INT_SUM(pem));
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), crs_dr);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), crs_er);
    if (c.s.exc)
    {
        BDK_CSR_INIT(c, BDK_PEMX_DBG_INFO(pem));
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), acto);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), caar);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), dpeoosd);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), ecrc_e);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), fcpvwt);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), fcuv);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), mre);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), racca);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), racpp);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), racur);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), ramtlp);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rarwdns);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rauc);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rawwpp);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rcemrc);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rdwdle);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), recrce);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rfemrc);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rnfemrc);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rpe);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rpmerc);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rpoison);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rptamrc);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rqo);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rte);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rtlplle);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rtlpmal);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rtwdle);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rumep);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), rvdm);
        CHECK_ERROR(BDK_PEMX_DBG_INFO(pem), spoison);
    }
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), rdlk);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), se);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), un_b1);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), un_b2);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), un_bx);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), up_b1);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), up_b2);
    CHECK_ERROR(BDK_PEMX_INT_SUM(pem), up_bx);
}

static void check_pip(void)
{
    BDK_CSR_INIT(c, BDK_PIP_INT_REG);
    CHECK_ERROR(BDK_PIP_INT_REG, badtag);
    CHECK_ERROR(BDK_PIP_INT_REG, beperr);
    CHECK_ERROR(BDK_PIP_INT_REG, feperr);
    CHECK_ERROR(BDK_PIP_INT_REG, prtnxa);
    CHECK_ERROR(BDK_PIP_INT_REG, punyerr);
    CHECK_ERROR(BDK_PIP_INT_REG, skprunt);
    CHECK_ERROR(BDK_PIP_INT_REG, todoovr);
}

static void check_pko(void)
{
    BDK_CSR_INIT(c, BDK_PKO_REG_ERROR);
    CHECK_ERROR(BDK_PKO_REG_ERROR, currzero);
    CHECK_ERROR(BDK_PKO_REG_ERROR, doorbell);
    CHECK_ERROR(BDK_PKO_REG_ERROR, loopback);
    CHECK_ERROR(BDK_PKO_REG_ERROR, parity);
}

static void check_rad(void)
{
    BDK_CSR_INIT(c, BDK_RAD_REG_ERROR);
    CHECK_ERROR(BDK_RAD_REG_ERROR, doorbell);
}

static void check_srio(int srio)
{
    BDK_CSR_INIT(c, BDK_SRIOX_INT_REG(srio));
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), bar_err);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), degrad);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), deny_wr);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), f_error);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), fail);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), log_erb);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), mac_buf);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), mce_rx);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), omsg_err);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), phy_erb);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), pko_err);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), rtry_err);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), sli_err);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), ttl_tout);
    CHECK_ERROR(BDK_SRIOX_INT_REG(srio), zero_pkt);
}

static void check_sso_cn68xx(void)
{
    BDK_CSR_INIT(c, BDK_SSO_ERR);
    CHECK_ERROR(BDK_SSO_ERR, awe);
    CHECK_ERROR(BDK_SSO_ERR, bfp);
    CHECK_ERROR(BDK_SSO_ERR, fidx_dbe);
    CHECK_ERROR(BDK_SSO_ERR, fidx_sbe);
    CHECK_ERROR(BDK_SSO_ERR, fpe);
    CHECK_ERROR(BDK_SSO_ERR, idx_dbe);
    CHECK_ERROR(BDK_SSO_ERR, idx_sbe);
    CHECK_ERROR(BDK_SSO_ERR, iop);
    CHECK_ERROR(BDK_SSO_ERR, oth_dbe0);
    CHECK_ERROR(BDK_SSO_ERR, oth_dbe1);
    CHECK_ERROR(BDK_SSO_ERR, oth_sbe0);
    CHECK_ERROR(BDK_SSO_ERR, oth_sbe1);
    CHECK_ERROR(BDK_SSO_ERR, pnd_dbe0);
    CHECK_ERROR(BDK_SSO_ERR, pnd_dbe1);
    CHECK_ERROR(BDK_SSO_ERR, pnd_sbe0);
    CHECK_ERROR(BDK_SSO_ERR, pnd_sbe1);
}

static void check_sso_cn6xxx(void)
{
    //FIXME
}

static void check_tim_cn68xx(void)
{
    {
        BDK_CSR_INIT(c, BDK_TIM_INT0);
        CHECK_ERROR(BDK_TIM_INT0, int0);
    }
    {
        BDK_CSR_INIT(c, BDK_TIM_INT_ECCERR);
        CHECK_ERROR(BDK_TIM_INT_ECCERR, dbe);
        CHECK_ERROR(BDK_TIM_INT_ECCERR, sbe);
    }
}

static void check_tim_cn6xxx(void)
{
    BDK_CSR_INIT(c, BDK_TIM_REG_ERROR);
    CHECK_ERROR(BDK_TIM_REG_ERROR, mask);
}

static void check_usb(int usb)
{
    BDK_CSR_INIT(c, BDK_UCTLX_INT_REG(usb));
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), cf_psh_f);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), ec_ovf_e);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), er_psh_f);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), oc_ovf_e);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), or_psh_f);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), pp_psh_f);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), wb_pop_e);
    CHECK_ERROR(BDK_UCTLX_INT_REG(usb), wb_psh_f);
}

static void check_zip(void)
{
    BDK_CSR_INIT(c, BDK_ZIP_ERROR);
    CHECK_ERROR(BDK_ZIP_ERROR, doorbell);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_INIT(c, BDK_ZIP_INT_REG);
        CHECK_ERROR(BDK_ZIP_INT_REG, doorbell0);
        CHECK_ERROR(BDK_ZIP_INT_REG, doorbell1);
        CHECK_ERROR(BDK_ZIP_INT_REG, ibdbe);
        CHECK_ERROR(BDK_ZIP_INT_REG, ibsbe);
    }
}

static void check_cn6xxx(void)
{
    BDK_CSR_INIT(c, BDK_CIU_INTX_SUM0(0));
    if (c.s.mii) check_mix(0);
    if (c.s.pcm) check_pcm();
    if (c.s.rml)
    {
        BDK_CSR_INIT(c, BDK_CIU_BLOCK_INT);
        if (c.s.agl) check_agl();
        if (c.s.asxpcs0)
        {
            check_pcs(0);
            check_pcsx(0);
        }
        if (c.s.asxpcs1)
        {
            check_pcs(1);
            check_pcsx(1);
        }
        if (c.s.dfa) check_dfa();
        if (c.s.dpi) check_dpi();
        if (c.s.fpa) check_fpa();
        if (c.s.gmx0) check_gmx(0);
        if (c.s.gmx1) check_gmx(1);
        if (c.s.iob) check_iob();
        if (c.s.ipd) check_ipd();
        if (c.s.key) check_key();
        if (c.s.l2c) check_l2c();
        if (c.s.lmc0) check_lmc(0);
        if (c.s.mio) check_mio();
        if (c.s.pem0) check_pem(0);
        if (c.s.pem1) check_pem(1);
        if (c.s.pip) check_pip();
        if (c.s.pko) check_pko();
        if (c.s.pow) check_sso_cn6xxx();
        if (c.s.rad) check_rad();
        if (c.s.srio0) check_srio(0);
        if (c.s.srio1) check_srio(1);
        if (c.s.tim) check_tim_cn6xxx();
        if (c.s.zip) check_zip();
    }
    {
        BDK_CSR_INIT(c, BDK_CIU_INT_SUM1);
        if (c.s.mii1) check_mix(1);
        if (c.s.nand) check_nand();
        if (c.s.usb) check_usb(0);
    }
}

static void check_cn68xx(void)
{
    BDK_CSR_INIT(c, BDK_CIU2_SUM_PPX_IP2(0));
    if (c.s.io)
    {
        BDK_CSR_INIT(c, BDK_CIU2_SRC_PPX_IP2_IO(0));
        for (int pem=0; pem<2; pem++)
            if (c.s.pem & (1<<pem))
                check_pem(pem);
    }
    if (c.s.mem)
    {
        BDK_CSR_INIT(c, BDK_CIU2_SRC_PPX_IP2_MEM(0));
        for (int lmc=0; lmc<4; lmc++)
        if (c.s.lmc & (1<<lmc))
            check_lmc(lmc);
    }
    if (c.s.mio)
    {
        BDK_CSR_INIT(c, BDK_CIU2_SRC_PPX_IP2_MIO(0));
        if (c.s.mio) check_mio();
        if (c.s.nand) check_nand();
        if (c.s.usb_uctl) check_usb(0);
    }
    if (c.s.pkt)
    {
        BDK_CSR_INIT(c, BDK_CIU2_SRC_PPX_IP2_PKT(0));
        if (c.s.agl) check_agl();
        for (int gmx=0; gmx<5; gmx++)
        {
            if (c.s.agx & (1<<gmx))
            {
                check_gmx(gmx);
                check_pcs(gmx);
                check_pcsx(gmx);
            }
        }
        if (c.s.ilk) check_ilk();
        if (c.s.mii) check_mix(0);
    }
    if (c.s.rml)
    {
        BDK_CSR_INIT(c, BDK_CIU2_SRC_PPX_IP2_RML(0));
        if (c.s.dfa) check_dfa();
        if (c.s.dpi) check_dpi();
        if (c.s.fpa) check_fpa();
        if (c.s.iob) check_iob();
        if (c.s.ipd) check_ipd();
        if (c.s.key) check_key();
        if (c.s.l2c) check_l2c();
        if (c.s.pip) check_pip();
        if (c.s.pko) check_pko();
        if (c.s.rad) check_rad();
        if (c.s.sso) check_sso_cn68xx();
        if (c.s.tim) check_tim_cn68xx();
        if (c.s.zip) check_zip();
    }
}

static void enable_dfa(void)
{
    BDK_CSR_MODIFY(c, BDK_DFA_INTMSK,
        c.s.dblina = -1;
        c.s.dc0pena = -1;
        c.s.dc1pena = -1;
        c.s.dc2pena = -1;
        c.s.dfanxmena = -1;
        c.s.dlc0_ovfena = -1;
        c.s.dlc1_ovfena = -1;
        c.s.replerrena = -1;
    );
}

static void enable_dpi(void)
{
    BDK_CSR_MODIFY(c, BDK_DPI_INT_EN,
        c.s.dmadbo = -1;
        c.s.nderr = -1;
        c.s.nfovr = -1;
        c.s.req_anull = -1;
        c.s.req_badadr = -1;
        c.s.req_badfil = -1;
        c.s.req_badlen = -1;
        c.s.req_inull = -1;
        c.s.req_ovrflw = -1;
        c.s.req_undflw = -1;
        c.s.sprt0_rst = -1;
        c.s.sprt1_rst = -1;
        c.s.sprt2_rst = -1;
        c.s.sprt3_rst = -1;
    );
}

static void enable_fpa(void)
{
    BDK_CSR_MODIFY(c, BDK_FPA_INT_ENB,
        c.s.fed0_dbe = -1;
        c.s.fed0_sbe = -1;
        c.s.fed1_dbe = -1;
        c.s.fed1_sbe = -1;
        c.s.free0 = -1;
        c.s.free1 = -1;
        c.s.free2 = -1;
        c.s.free3 = -1;
        c.s.free4 = -1;
        c.s.free5 = -1;
        c.s.free6 = -1;
        c.s.free7 = -1;
        c.s.free8 = -1;
        c.s.paddr_e = -1;
        c.s.pool0th = -1;
        c.s.pool1th = -1;
        c.s.pool2th = -1;
        c.s.pool3th = -1;
        c.s.pool4th = -1;
        c.s.pool5th = -1;
        c.s.pool6th = -1;
        c.s.pool7th = -1;
        c.s.pool8th = -1;
        c.s.q0_coff = -1;
        c.s.q0_perr = -1;
        c.s.q0_und = -1;
        c.s.q1_coff = -1;
        c.s.q1_perr = -1;
        c.s.q1_und = -1;
        c.s.q2_coff = -1;
        c.s.q2_perr = -1;
        c.s.q2_und = -1;
        c.s.q3_coff = -1;
        c.s.q3_perr = -1;
        c.s.q3_und = -1;
        c.s.q4_coff = -1;
        c.s.q4_perr = -1;
        c.s.q4_und = -1;
        c.s.q5_coff = -1;
        c.s.q5_perr = -1;
        c.s.q5_und = -1;
        c.s.q6_coff = -1;
        c.s.q6_perr = -1;
        c.s.q6_und = -1;
        c.s.q7_coff = -1;
        c.s.q7_perr = -1;
        c.s.q7_und = -1;
        c.s.q8_coff = -1;
        c.s.q8_perr = -1;
        c.s.q8_und = -1;
    );
}

static void enable_iob(void)
{
    BDK_CSR_MODIFY(c, BDK_IOB0_INT_ENB,
        c.s.np_dat = -1;
        c.s.np_eop = -1;
        c.s.np_sop = -1;
        c.s.p_dat = -1;
        c.s.p_eop = -1;
        c.s.p_sop = -1;
    );
}

static void enable_ipd(void)
{
    BDK_CSR_MODIFY(c, BDK_IPD_INT_ENB,
        c.s.bc_ovr = -1;
        c.s.bp_sub = -1;
        c.s.c_coll = -1;
        c.s.cc_ovr = -1;
        c.s.d_coll = -1;
        c.s.dat = -1;
        c.s.dc_ovr = -1;
        c.s.eop = -1;
        c.s.prc_par0 = -1;
        c.s.prc_par1 = -1;
        c.s.prc_par2 = -1;
        c.s.prc_par3 = -1;
        c.s.pw0_dbe = -1;
        c.s.pw0_sbe = -1;
        c.s.pw1_dbe = -1;
        c.s.pw1_sbe = -1;
        c.s.pw2_dbe = -1;
        c.s.pw2_sbe = -1;
        c.s.pw3_dbe = -1;
        c.s.pw3_sbe = -1;
        c.s.sop = -1;
    );
}

static void enable_key(void)
{
    BDK_CSR_MODIFY(c, BDK_KEY_INT_ENB,
        c.s.ked0_dbe = -1;
        c.s.ked0_sbe = -1;
        c.s.ked1_dbe = -1;
        c.s.ked1_sbe = -1;
    );
}

static void enable_l2c_tad(int tad)
{
    BDK_CSR_MODIFY(c, BDK_L2C_TADX_IEN(tad),
        c.s.l2ddbe = -1;
        c.s.l2dsbe = -1;
        c.s.noway = -1;
        c.s.rddislmc = -1;
        c.s.tagdbe = -1;
        c.s.tagsbe = -1;
        c.s.vbfdbe = -1;
        c.s.vbfsbe = -1;
        c.s.wrdislmc = -1;
    );
}

static void enable_l2c(void)
{
    BDK_CSR_MODIFY(c, BDK_L2C_INT_ENA,
        c.s.bigrd = -1;
        c.s.bigwr = -1;
        c.s.holerd = -1;
        c.s.holewr = -1;
        c.s.vrtadrng = -1;
        c.s.vrtidrng = -1;
        c.s.vrtpe = -1;
        c.s.vrtwr = -1;
    );
    int max_tads = (OCTEON_IS_MODEL(OCTEON_CN68XX)) ? 4 : 1;
    for (int tad=0; tad<max_tads; tad++)
        enable_l2c_tad(tad);
}

static void enable_lmc(int lmc)
{
    BDK_CSR_MODIFY(c, BDK_LMCX_INT_EN(lmc),
        c.s.intr_ded_ena = -1;
        c.s.intr_nxm_wr_ena = -1;
        c.s.intr_sec_ena = -1;
    );
}

static void enable_mio(void)
{
    BDK_CSR_MODIFY(c, BDK_MIO_BOOT_INT,
        c.s.adr_int = -1;
        c.s.wait_int = -1;
    );
    BDK_CSR_MODIFY(c, BDK_MIO_RST_INT_EN,
        c.s.perst0 = -1;
        c.s.perst1 = -1;
        c.s.rst_link0 = -1;
        c.s.rst_link1 = -1;
        c.s.rst_link2 = -1;
        c.s.rst_link3 = -1;
    );
}

static void enable_nand(void)
{
    BDK_CSR_MODIFY(c, BDK_NDF_INT_EN,
        c.s.ecc_1bit = -1;
        c.s.ecc_mult = -1;
        c.s.ovrf = -1;
        c.s.sm_bad = -1;
        c.s.wdog = -1;
    );
}

static void enable_pcm(void)
{
    for (int pcm=0; pcm<4; pcm++)
    {
        BDK_CSR_MODIFY(c, BDK_PCMX_INT_ENA(pcm),
            c.s.fsyncextra = -1;
            c.s.fsyncmissed = -1;
            c.s.rxovf = -1;
            c.s.txempty = -1;
        );
    }
}

static void enable_pem(int pem)
{
    BDK_CSR_MODIFY(c, BDK_PEMX_INT_ENB(pem),
        c.s.crs_dr = -1;
        c.s.crs_er = -1;
        c.s.exc = -1;
        c.s.rdlk = -1;
        c.s.se = -1;
        c.s.un_b1 = -1;
        c.s.un_b2 = -1;
        c.s.un_bx = -1;
        c.s.up_b1 = -1;
        c.s.up_b2 = -1;
        c.s.up_bx = -1;
    );
    BDK_CSR_MODIFY(c, BDK_PEMX_DBG_INFO_EN(pem),
        c.s.acto = -1;
        c.s.caar = -1;
        c.s.dpeoosd = -1;
        c.s.ecrc_e = -1;
        c.s.fcpvwt = -1;
        c.s.fcuv = -1;
        c.s.mre = -1;
        c.s.racca = -1;
        c.s.racpp = -1;
        c.s.racur = -1;
        c.s.ramtlp = -1;
        c.s.rarwdns = -1;
        c.s.rauc = -1;
        c.s.rawwpp = -1;
        c.s.rcemrc = -1;
        c.s.rdwdle = -1;
        c.s.recrce = -1;
        c.s.rfemrc = -1;
        c.s.rnfemrc = -1;
        c.s.rpe = -1;
        c.s.rpmerc = -1;
        c.s.rpoison = -1;
        c.s.rptamrc = -1;
        c.s.rqo = -1;
        c.s.rte = -1;
        c.s.rtlplle = -1;
        c.s.rtlpmal = -1;
        c.s.rtwdle = -1;
        c.s.rumep = -1;
        c.s.rvdm = -1;
        c.s.spoison = -1;
    );
}

static void enable_pip(void)
{
    BDK_CSR_MODIFY(c, BDK_PIP_INT_EN,
        c.s.badtag = -1;
        c.s.beperr = -1;
        c.s.feperr = -1;
        c.s.prtnxa = -1;
        c.s.punyerr = -1;
        c.s.skprunt = -1;
        c.s.todoovr = -1;
    );
}

static void enable_pko(void)
{
    BDK_CSR_MODIFY(c, BDK_PKO_REG_INT_MASK,
        c.s.currzero = -1;
        c.s.doorbell = -1;
        c.s.loopback = -1;
        c.s.parity = -1;
    );
}

static void enable_rad(void)
{
    BDK_CSR_MODIFY(c, BDK_RAD_REG_INT_MASK,
        c.s.doorbell = -1;
    );
}

static void enable_srio(int srio)
{
    BDK_CSR_MODIFY(c, BDK_SRIOX_INT_ENABLE(srio),
        c.s.bar_err = -1;
        c.s.degrade = -1;
        c.s.deny_wr = -1;
        c.s.f_error = -1;
        c.s.fail = -1;
        c.s.log_erb = -1;
        c.s.mac_buf = -1;
        c.s.mce_rx = -1;
        c.s.omsg_err = -1;
        c.s.phy_erb = -1;
        c.s.pko_err = -1;
        c.s.rtry_err = -1;
        c.s.sli_err = -1;
        c.s.ttl_tout = -1;
        c.s.zero_pkt = -1;
    );
}

static void enable_sso_cn68xx(void)
{
    BDK_CSR_MODIFY(c, BDK_SSO_ERR_ENB,
        c.s.awe_ie = -1;
        c.s.bfp_ie = -1;
        c.s.fidx_dbe_ie = -1;
        c.s.fidx_sbe_ie = -1;
        c.s.fpe_ie = -1;
        c.s.idx_dbe_ie = -1;
        c.s.idx_sbe_ie = -1;
        c.s.iop_ie = -1;
        c.s.oth_dbe0_ie = -1;
        c.s.oth_dbe1_ie = -1;
        c.s.oth_sbe0_ie = -1;
        c.s.oth_sbe1_ie = -1;
        c.s.pnd_dbe0_ie = -1;
        c.s.pnd_dbe1_ie = -1;
        c.s.pnd_sbe0_ie = -1;
        c.s.pnd_sbe1_ie = -1;
    );
}

static void enable_sso_cn6xxx(void)
{
    // FIXME
}

static void enable_tim_cn68xx(void)
{
    BDK_CSR_MODIFY(c, BDK_TIM_INT0_EN,
        c.s.int0_en = -1;
    );
    BDK_CSR_MODIFY(c, BDK_TIM_INT_ECCERR_EN,
        c.s.dbe_en = -1;
        c.s.sbe_en = -1;
    );
}

static void enable_tim_cn6xxx(void)
{
    BDK_CSR_MODIFY(c, BDK_TIM_REG_INT_MASK,
        c.s.mask = -1;
    );
}

static void enable_usb(int usb)
{
    BDK_CSR_MODIFY(c, BDK_UCTLX_INT_ENA(usb),
        c.s.cf_psh_f = -1;
        c.s.ec_ovf_e = -1;
        c.s.er_psh_f = -1;
        c.s.oc_ovf_e = -1;
        c.s.or_psh_f = -1;
        c.s.pp_psh_f = -1;
        c.s.wb_pop_e = -1;
        c.s.wb_psh_f = -1;
    );
}

static void enable_zip(void)
{
    BDK_CSR_MODIFY(c, BDK_ZIP_INT_MASK,
        c.s.doorbell = -1;
    );
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        BDK_CSR_MODIFY(c, BDK_ZIP_INT_ENA,
            c.s.doorbell0 = -1;
            c.s.doorbell1 = -1;
            c.s.ibdbe = -1;
            c.s.ibsbe = -1;
        );
}

static void enable_cn6xxx(void)
{
    /* Interrupts connected to CIU SUM0 */
    BDK_CSR_MODIFY(c, BDK_CIU_INTX_EN0(0),
        c.s.mii = -1;
        c.s.pcm = -1;
        c.s.rml = -1;
    );
    /* MIX is enabled in the bdk_if code */
    if (OCTEON_IS_MODEL(OCTEON_CN61XX) || OCTEON_IS_MODEL(OCTEON_CNF71XX))
        enable_pcm();

    /* Interrupts off of RML */
    /* AGL, GMX, PCS and PCSX are enabled in the bdk_if code */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX) || OCTEON_IS_MODEL(OCTEON_CN66XX))
        enable_dfa();
    enable_dpi();
    enable_fpa();
    enable_iob();
    enable_ipd();
    enable_key();
    enable_l2c();
    enable_lmc(0);
    enable_mio();
    enable_pem(0);
    enable_pem(1);
    enable_pip();
    enable_pko();
    enable_rad();
    if (OCTEON_IS_MODEL(OCTEON_CN63XX) || OCTEON_IS_MODEL(OCTEON_CN66XX))
    {
        enable_srio(0);
        enable_srio(1);
    }
    enable_sso_cn6xxx();
    enable_tim_cn6xxx();
    if (!OCTEON_IS_MODEL(OCTEON_CNF71XX))
        enable_zip();

    /* Interrupts connected to CIU SUM1 */
    BDK_CSR_MODIFY(c, BDK_CIU_INTX_EN1(0),
        c.s.mii1 = -1;
        c.s.nand = -1;
        c.s.usb = -1;
    );
    if (!OCTEON_IS_MODEL(OCTEON_CNF71XX) && !OCTEON_IS_MODEL(OCTEON_CN61XX))
        enable_nand();
    enable_usb(0);
}

static void enable_cn68xx(void)
{
    /* Interrupts connected to IO */
    BDK_CSR_MODIFY(c, BDK_CIU2_EN_PPX_IP2_IO(0),
        c.s.pem = -1;
    );
    enable_pem(0);
    enable_pem(1);

    /* Interrupts connected to MEM */
    BDK_CSR_MODIFY(c, BDK_CIU2_EN_PPX_IP2_MEM(0),
        c.s.lmc = -1;
    );
    enable_lmc(0);
    enable_lmc(1);
    enable_lmc(2);
    enable_lmc(3);

    /* Interrupts connected to MIO */
    BDK_CSR_MODIFY(c, BDK_CIU2_EN_PPX_IP2_MIO(0),
        c.s.mio = -1;
        c.s.nand = -1;
        c.s.usb_uctl = -1;
    );
    enable_mio();
    enable_nand();
    enable_usb(0);

    /* Interrupts connected to PKT */
    BDK_CSR_MODIFY(c, BDK_CIU2_EN_PPX_IP2_PKT(0),
        c.s.agl = -1;
        c.s.agx = -1;
        c.s.ilk = -1;
        c.s.mii = -1;
    );
    /* AGL, MIX, ILK, GMX, PCS and PCSX are enabled in the bdk_if code */

    /* Interrupts connected to RML */
    BDK_CSR_MODIFY(c, BDK_CIU2_EN_PPX_IP2_RML(0),
        c.s.dfa = -1;
        c.s.dpi = -1;
        c.s.fpa = -1;
        c.s.iob = -1;
        c.s.ipd = -1;
        c.s.key = -1;
        c.s.l2c = -1;
        c.s.pip = -1;
        c.s.pko = -1;
        c.s.rad = -1;
        c.s.sso = -1;
        c.s.tim = -1;
        c.s.zip = -1;
    );
    enable_dfa();
    enable_dpi();
    enable_fpa();
    enable_iob();
    enable_ipd();
    enable_key();
    enable_l2c();
    enable_pip();
    enable_pko();
    enable_rad();
    enable_sso_cn68xx();
    enable_tim_cn68xx();
    enable_zip();
}

void (*bdk_error_check)(void) = NULL;
void bdk_error_enable(void)
{
    if (bdk_is_simulation())
        return;
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        enable_cn68xx();
        bdk_error_check = check_cn68xx;
    }
    else
    {
        enable_cn6xxx();
        bdk_error_check = check_cn6xxx;
    }
}
