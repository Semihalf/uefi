#include <bdk.h>

#define EXTRACT(v, lsb, width) (((v) >> (lsb)) & ((1ull << (width)) - 1))

/**
 * Given a physical DRAM address, extract information about the node, LMC, DIMM,
 * rank, bank, row, and column that was accessed.
 *
 * @param address Physical address to decode
 * @param node    Node the address was for
 * @param lmc     LMC controller the address was for
 * @param dimm    DIMM the address was for
 * @param rank    RANK on the DIMM
 * @param bank    BANK on the DIMM
 * @param row     Row on the DIMM
 * @param col     Column on the DIMM
 */
void bdk_dram_address_extract_info(uint64_t address, int *node, int *lmc,
    int *dimm, int *rank, int *bank, int *row, int *col)
{
    *node = EXTRACT(address, 40, 2); /* Address bits [41:40] */
    /* Determine the LMC controller */
    BDK_CSR_INIT(l2c_ctl, *node, BDK_L2C_CTL);
    int bank_lsb, xbits;

    /* xbits depends on number of LMCs */
    xbits = (__bdk_dram_get_num_lmc(*node) == 4) ? 2 : 1;
    bank_lsb = 7 + xbits;

    /* LMC number is probably aliased */
    if (l2c_ctl.s.disidxalias)
	*lmc = EXTRACT(address, 7, xbits);
    else
	*lmc = EXTRACT(address, 7, xbits) ^ EXTRACT(address, 20, xbits) ^ EXTRACT(address, 12, xbits);

    /* Figure out the bank field width */
    BDK_CSR_INIT(lmcx_config, *node, BDK_LMCX_CONFIG(*lmc));
    int bank_width = __bdk_dram_get_num_bank_bits(*node, *lmc);

    /* Extract additional info from the LMC_CONFIG CSR */
    int dimm_lsb    = 28 + lmcx_config.s.pbank_lsb + xbits;
    int dimm_width  = 40 - dimm_lsb;
    int rank_lsb    = dimm_lsb - lmcx_config.s.rank_ena;
    int rank_width  = dimm_lsb - rank_lsb;
    int row_lsb     = 14 + lmcx_config.s.row_lsb + xbits;
    int row_width   = rank_lsb - row_lsb;
    int col_hi_lsb  = bank_lsb + bank_width;
    int col_hi_width= row_lsb - col_hi_lsb;

    /* Extract the parts of the address */
    *dimm = EXTRACT(address, dimm_lsb, dimm_width);
    *rank = EXTRACT(address, rank_lsb, rank_width);
    *row = EXTRACT(address, row_lsb, row_width);

    /* bank calculation may be aliased... */
    BDK_CSR_INIT(lmcx_control, *node, BDK_LMCX_CONTROL(*lmc));
    if (lmcx_control.s.xor_bank)
        *bank = EXTRACT(address, bank_lsb, bank_width) ^ EXTRACT(address, 12 + xbits, bank_width);
    else
        *bank = EXTRACT(address, bank_lsb, bank_width);

    /* LMC number already extracted */
    int col_hi = EXTRACT(address, col_hi_lsb, col_hi_width);
    *col = EXTRACT(address, 3, 4) | (col_hi << 4);
    /* Bus byte is address bits [2:0]. Unused here */
}

