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

/*
 * construct_address_info builds a physical address from the FADR CSR fields.
 */
#define EXTRACT(v, lsb, width) (((v) >> (lsb)) & ((1ull << (width)) - 1))
#define INSERT(a, v, lsb, width) a|=(((v) & ((1ull << (width)) - 1)) << (lsb))

static uint64_t construct_address_info(bdk_node_t node, int lmc, int dimm,
				       int rank, int bank, int row, int col)

{
    uint64_t address = 0;

    // insert node bits
    INSERT(address, node, 40, 2); /* Address bits [41:40] */

    /* xbits depends on number of LMCs */
    int xbits = (__bdk_dram_get_num_lmc(node) == 4) ? 2 : 1;
    int bank_lsb = 7 + xbits;

    /* Figure out the bank field width */
    int bank_width = __bdk_dram_get_num_bank_bits(node, lmc);

    /* Extract additional info from the LMC_CONFIG CSR */
    BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(lmc));
    int dimm_lsb     = 28 + lmcx_config.s.pbank_lsb + xbits;
    int dimm_width   = 40 - dimm_lsb;
    int rank_lsb     = dimm_lsb - lmcx_config.s.rank_ena;
    int rank_width   = dimm_lsb - rank_lsb;
    int row_lsb      = 14 + lmcx_config.s.row_lsb + xbits;
    int row_width    = rank_lsb - row_lsb;
    int col_hi_lsb   = bank_lsb + bank_width;
    int col_hi_width = row_lsb - col_hi_lsb;

    /* Insert some other parts of the address */
    INSERT(address, dimm, dimm_lsb, dimm_width);
    INSERT(address, rank, rank_lsb, rank_width);
    INSERT(address, row,  row_lsb,  row_width);
    INSERT(address, col >> 4, col_hi_lsb, col_hi_width);
    INSERT(address, col, 3, 4);

    /* bank calculation may be aliased... */
    BDK_CSR_INIT(lmcx_control, node, BDK_LMCX_CONTROL(lmc));
    int new_bank = bank;
    if (lmcx_control.s.xor_bank)
        new_bank ^= EXTRACT(address, 12 + xbits, bank_width);
    INSERT(address, new_bank, bank_lsb, bank_width);
      
    /* Determine the actual C bits from the input LMC controller arg */
    /* The input LMC number was probably aliased with other fields */
    BDK_CSR_INIT(l2c_ctl, node, BDK_L2C_CTL);
    int new_lmc = lmc;
    if (!l2c_ctl.s.disidxalias)
	new_lmc ^= EXTRACT(address, 20, xbits) ^ EXTRACT(address, 12, xbits);
    INSERT(address, new_lmc, 7, xbits);

    return address;
}

static void construct_phase_info(char *buffer, int fill_order, int fail_index, int err_bits)
{
    int basic_phase, bitno, bitmask, phase_no, read_no;
    //printf("decode_err(%d, %d, %d)\n", fill_order, fail_index, err_bits);

    if ((fill_order != 0) || ((err_bits & 15) == 0)) {
	snprintf(buffer, 8, "BAD!");
	return;
    }

    // fail_index determines the byte of the map associated with the fill_order
    // FIXME: we only try for fill_order == 0 for now...
    // for FO = 0, it is a direct map: fail_index == byte # in the map == byte #
    // and the byte # maps directly to the basic phase #
    read_no = ((fail_index & 7) >> 2) + 1;
    basic_phase = (fail_index & 3) * 2;

    bitno = 0;
    bitmask = err_bits & 15;
    while (!(bitmask & 1)) { bitno++; bitmask >>= 1; } // FIXME: better error detect
    
    //printf("basic phase = %d or %d\n", basic_phase, basic_phase + 1);
    //printf("bitno phase = %d or %d\n", bitno, bitno + 4);

    phase_no = -1;
    if ((basic_phase == bitno) || (basic_phase == bitno + 4))
        phase_no = basic_phase;
    else if ((basic_phase + 1 == bitno) || (basic_phase + 1 == bitno + 4))
        phase_no = basic_phase + 1;

    if (phase_no < 0) { // better indication of not found/illegality
	snprintf(buffer, 8, "ILL!");
	return;
    }

    snprintf(buffer, 8, "R%dP%d", read_no, phase_no);
    return;
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
               report/count single bit errors if there hasn't been a
               double bit error */
            if (c.s.ded_err || c.s.sec_err)
            {
                char *err_type;
                char synstr[20];
		char phasestr[8];
		int err_bits;
                BDK_CSR_INIT(fadr, node, BDK_LMCX_FADR(index));
                BDK_CSR_INIT(ecc_synd, node, BDK_LMCX_ECC_SYND(index));
                uint64_t syndrome = ecc_synd.u;
                CLEAR_CHIP_ERROR(BDK_LMCX_INT(index), s, ded_err);
                CLEAR_CHIP_ERROR(BDK_LMCX_INT(index), s, sec_err);
                if (c.s.ded_err) { // if DED, count it and do not count SEC
                    bdk_atomic_add64_nosync(&__bdk_dram_ecc_double_bit_errors[index], 1);
                    err_type = "double";
		    err_bits = c.s.ded_err;
                    snprintf(synstr, sizeof(synstr), "DED=%d", err_bits);
                } else { // must be just SEC, also extract the syndrome byte
                    bdk_atomic_add64_nosync(&__bdk_dram_ecc_single_bit_errors[index], 1);
                    err_type = "single";
		    err_bits = c.s.sec_err;
                    int i = err_bits;
                    while ((i & 1) == 0) {syndrome >>= 8; i >>= 1; }
                    snprintf(synstr, sizeof(synstr), "SYND 0x%02lx/%d", syndrome & 0xff, err_bits);
                }
                uint32_t frow = fadr.s.frow & __bdk_dram_get_row_mask(node, index);
                uint32_t fcol = fadr.s.fcol & __bdk_dram_get_col_mask(node, index);
                uint64_t where = construct_address_info(node, index, fadr.s.fdimm, fadr.s.fbunk,
                                                        fadr.s.fbank, frow, fcol);
		construct_phase_info(phasestr, fadr.s.fill_order, EXTRACT(fadr.s.fcol, 1, 3), err_bits);

                bdk_error("N%d.LMC%d: ECC %s (DIMM%d,Rank%d,Bank%02d,Row 0x%05x,Col 0x%04x,%s,%s)[0x%011lx]\n",
                          node, index, err_type,
                          fadr.s.fdimm, fadr.s.fbunk, fadr.s.fbank,
                          frow, fcol, phasestr, synstr, where);
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
                //CHECK_CHIP_ERROR(BDK_OCX_COM_LINKX_INT(link), s, blk_err);
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
