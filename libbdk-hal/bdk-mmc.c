#include <bdk.h>

// Basic definitions for the OCTEON II eMMC interface
// Copyright 2012 Cavium,Inc.

// Basic Commands
#define MMC_CMD_GO_IDLE_STATE		0
#define MMC_CMD_SEND_OP_COND		1
#define MMC_CMD_ALL_SEND_CID		2
#define MMC_CMD_SET_RELATIVE_ADDR	3
#define MMC_CMD_SET_DSR			4
#define MMC_CMD_SLEEP_AWAKE             5
#define MMC_CMD_SWITCH			6
#define MMC_CMD_SELECT_CARD		7 // also DESELECT_CARD
#define MMC_CMD_SEND_EXT_CSD		8
#define MMC_CMD_SEND_CSD		9
#define MMC_CMD_SEND_CID		10
#define MMC_CMD_ERAD_DAT_UNTIL_STOP     11
#define MMC_CMD_STOP_TRANSMISSION	12
#define MMC_CMD_SEND_STATUS		13
#define MMC_CMD_BUSTEST_R               14
#define MMC_CMD_GO_INACTIVE_STATE       15
#define MMC_CMD_BUSTEST_W               19

// Block-oriented Read Commands
#define MMC_CMD_SET_BLOCKLEN		16
#define MMC_CMD_READ_SINGLE_BLOCK	17
#define MMC_CMD_READ_MULTIPLE_BLOCK	18

// Stream Write Commands
#define MMC_CMD_WRITE_ADT_UNTIL_STOP    20

//Block-oriented Write Commands
#define MMC_CMD_SET_BLOCK_COUNT         23
#define MMC_CMD_WRITE_BLOCK             24
#define MMC_CMD_WRITE_MULTIPLE_BLOCK	25
#define MMC_CMD_PROGRAM_CID             26
#define MMC_CMD_PROGRAM_CIS             27

// Block-oriented write protection commands
#define MMC_CMD_SET_WRITE_PROT          28
#define MMC_CMD_CLR_WRITE_PROT          29
#define MMC_CMD_SEND_WRITE_PROT         30
#define MMC_CMD_SEND_WRITE_PROT_TYPE    31

// Erase Commands
#define MMC_CMD_ERASE_GROUP_START       35
#define MMC_CMD_ERASE_GROUP_END         36
#define MMC_CMD_ERASE                   38

//I/O Mode Commands
#define MMC_CMD_FAST_IO                 39
#define MMC_CMD_GO_IRQ_STATE            40
#define MMC_CMD_RES_41                  41

// Lock Card Commands
#define MMC_CMD_LOCK_UNLOCK             42

// Application-specific Commands
#define MMC_CMD_APP_CMD                 55
#define MMC_CMD_GEN_CMD			56


typedef union ocr_register
{
    uint32_t u32;

    struct ocr_register_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN

        uint32_t done_bit        :1 ;
        uint32_t access_mode     :2 ;
        uint32_t reserved_24_28  :5 ;
        uint32_t volts_2_7__3_6  :9 ;
        uint32_t volts_2_0__2_6  :7 ;
        uint32_t volts_1_7__1_95 :1 ;
        uint32_t reserved_0_6    :7 ;
#else
        uint32_t reserved_0_6    :7 ;
        uint32_t volts_1_7__1_95 :1 ;
        uint32_t volts_2_0__2_6  :7 ;
        uint32_t volts_2_7__3_6  :9 ;
        uint32_t reserved_24_28  :5 ;
        uint32_t access_mode     :2 ;
        uint32_t done_bit        :1 ;
#endif
    } s;
} ocr_register_t;

typedef union mmc_csd_register_hi
{
	uint64_t u64;

    struct mmc_csd_register_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN

         uint64_t csd_structure      :2 ;
         uint64_t spec_vers          :4 ;
         uint64_t reserved_120_121   :2 ;
         uint64_t taac               :8 ;
         uint64_t nsac               :8 ;
         uint64_t tran_speed         :8 ;
         uint64_t ccc                :12 ;
         uint64_t read_bl_len        :4 ;
         uint64_t read_bl_partial    :1 ;
         uint64_t write_blk_misalign :1 ;
         uint64_t read_blk_misalign  :1 ;
         uint64_t dsr_imp            :1 ;
         uint64_t reserved_74_75     :2 ;
         uint64_t c_size             :10 ;

#else
         uint64_t c_size             :10 ;
         uint64_t reserved_74_75     :2 ;
         uint64_t dsr_imp            :1 ;
         uint64_t read_blk_misalign  :1 ;
         uint64_t write_blk_misalign :1 ;
         uint64_t read_bl_partial    :1 ;
         uint64_t read_bl_len        :4 ;
         uint64_t ccc                :12 ;
         uint64_t tran_speed         :8 ;
         uint64_t nsac               :8 ;
         uint64_t taac               :8 ;
         uint64_t reserved_120_121   :2 ;
         uint64_t spec_vers          :4 ;
         uint64_t csd_structure      :2 ;
#endif
    } s;
} mmc_csd_register_hi_t;


typedef union mmc_csd_register_lo
{
	uint64_t u64;

    struct mmc_csd_register_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN

         uint64_t c_size             :2 ;
         uint64_t vdd_r_curr_min     :3 ;
         uint64_t vdd_r_curr_max     :3 ;
         uint64_t vdd_w_curr_min     :3 ;
         uint64_t vdd_w_curr_max     :3 ;
         uint64_t c_size_mult        :3 ;
         uint64_t erase_grp_size     :5 ;
         uint64_t erase_grp_mult     :5 ;
         uint64_t wp_grp_size        :5 ;
         uint64_t wp_grp_enable      :1 ;
         uint64_t default_ecc        :2 ;
         uint64_t r2w_factor         :3 ;
         uint64_t write_bl_len       :4 ;
         uint64_t write_bl_partial   :1 ;
         uint64_t reserved_17_20     :4 ;
         uint64_t content_prot_app   :1 ;
         uint64_t file_format_grp    :1 ;
         uint64_t copy               :1 ;
         uint64_t perm_write_protect :1 ;
         uint64_t tmp_write_protect  :1 ;
         uint64_t file_format        :2 ;
         uint64_t ecc                :2 ;
         uint64_t crc                :7 ;
         uint64_t always_one         :1 ;
#else
         uint64_t always_one         :1 ;
         uint64_t crc                :7 ;
         uint64_t ecc                :2 ;
         uint64_t file_format        :2 ;
         uint64_t tmp_write_protect  :1 ;
         uint64_t perm_write_protect :1 ;
         uint64_t copy               :1 ;
         uint64_t file_format_grp    :1 ;
         uint64_t content_prot_app   :1 ;
         uint64_t reserved_17_20     :4 ;
         uint64_t write_bl_partial   :1 ;
         uint64_t write_bl_len       :4 ;
         uint64_t r2w_factor         :3 ;
         uint64_t default_ecc        :2 ;
         uint64_t wp_grp_enable      :1 ;
         uint64_t wp_grp_size        :5 ;
         uint64_t erase_grp_mult     :5 ;
         uint64_t erase_grp_size     :5 ;
         uint64_t c_size_mult        :3 ;
         uint64_t vdd_w_curr_max     :3 ;
         uint64_t vdd_w_curr_min     :3 ;
         uint64_t vdd_r_curr_max     :3 ;
         uint64_t vdd_r_curr_min     :3 ;
         uint64_t c_size             :2 ;
#endif
    } s;
} mmc_csd_register_lo_t;


typedef union sd_csd_register_hi
{
	uint64_t u64;

    struct sd_csd_register_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN

         uint64_t csd_structure      :2 ;
         uint64_t reserved_120_125   :6 ;
         uint64_t taac               :8 ;
         uint64_t nsac               :8 ;
         uint64_t tran_speed         :8 ;
         uint64_t ccc                :12 ;
         uint64_t read_bl_len        :4 ;
         uint64_t read_bl_partial    :1 ;
         uint64_t write_blk_misalign :1 ;
         uint64_t read_blk_misalign  :1 ;
         uint64_t dsr_imp            :1 ;
         uint64_t reserved_74_75     :2 ;
         uint64_t c_size             :10 ;

#else
         uint64_t c_size             :10 ;
         uint64_t reserved_74_75     :2 ;
         uint64_t dsr_imp            :1 ;
         uint64_t read_blk_misalign  :1 ;
         uint64_t write_blk_misalign :1 ;
         uint64_t read_bl_partial    :1 ;
         uint64_t read_bl_len        :4 ;
         uint64_t ccc                :12 ;
         uint64_t tran_speed         :8 ;
         uint64_t nsac               :8 ;
         uint64_t taac               :8 ;
         uint64_t reserved_120_125   :6 ;
         uint64_t csd_structure      :2 ;
#endif
    } s;
} sd_csd_register_hi_t;


typedef union sd_csd_register_lo
{
	uint64_t u64;

    struct sd_csd_register_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN

         uint64_t c_size             :2 ;
         uint64_t vdd_r_curr_min     :3 ;
         uint64_t vdd_r_curr_max     :3 ;
         uint64_t vdd_w_curr_min     :3 ;
         uint64_t vdd_w_curr_max     :3 ;
         uint64_t c_size_mult        :3 ;
         uint64_t erase_blk_en       :1 ;
         uint64_t sector_size        :7 ;
         uint64_t wp_grp_size        :7 ;
         uint64_t wp_grp_enable      :1 ;
         uint64_t reserved_29_30     :2 ;
         uint64_t r2w_factor         :3 ;
         uint64_t write_bl_len       :4 ;
         uint64_t write_bl_partial   :1 ;
         uint64_t reserved_16_20     :5 ;
         uint64_t file_format_grp    :1 ;
         uint64_t copy               :1 ;
         uint64_t perm_write_protect :1 ;
         uint64_t tmp_write_protect  :1 ;
         uint64_t file_format        :2 ;
         uint64_t reserved_8_9       :2 ;
         uint64_t crc                :7 ;
         uint64_t always_one         :1 ;
#else
         uint64_t always_one         :1 ;
         uint64_t crc                :7 ;
         uint64_t reserved_8_9       :2 ;
         uint64_t file_format        :2 ;
         uint64_t tmp_write_protect  :1 ;
         uint64_t perm_write_protect :1 ;
         uint64_t copy               :1 ;
         uint64_t file_format_grp    :1 ;
         uint64_t reserved_16_20     :5 ;
         uint64_t write_bl_partial   :1 ;
         uint64_t write_bl_len       :4 ;
         uint64_t r2w_factor         :3 ;
         uint64_t reserved_29_30     :2 ;
         uint64_t wp_grp_enable      :1 ;
         uint64_t wp_grp_size        :7 ;
         uint64_t sector_size        :7 ;
         uint64_t erase_blk_en       :1 ;
         uint64_t c_size_mult        :3 ;
         uint64_t vdd_w_curr_max     :3 ;
         uint64_t vdd_w_curr_min     :3 ;
         uint64_t vdd_r_curr_max     :3 ;
         uint64_t vdd_r_curr_min     :3 ;
         uint64_t c_size             :2 ;
#endif
    } s;
} sd_csd_register_lo_t;


// SCR reg. is SD only

typedef union scr_register
{
    uint64_t u64;

    struct scr_register_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN

        uint64_t scr_structure   :4 ;
        uint64_t sd_spec         :4 ;
        uint64_t data_stat_after_erase  :1 ;
        uint64_t sd_security     :3 ;
        uint64_t sd_bus_widths   :4 ;
        uint64_t sd_spec3        :1 ;
        uint64_t ex_security     :4 ;
        uint64_t reserved_46_43  :9 ;
        uint64_t cmd_support     :2 ;
        uint64_t reserved_31_0   :32 ;
#else
        uint64_t reserved_31_0   :32 ;
        uint64_t cmd_support     :2 ;
        uint64_t reserved_46_43  :9 ;
        uint64_t ex_security     :4 ;
        uint64_t sd_spec3        :1 ;
        uint64_t sd_bus_widths   :4 ;
        uint64_t sd_security     :3 ;
        uint64_t data_stat_after_erase  :1 ;
        uint64_t sd_spec         :4 ;
        uint64_t scr_structure   :4 ;
#endif
    } s;
} scr_register_t;

typedef struct
{
    uint64_t block_addressable_device;
    uint64_t card_is_sd;
    uint64_t relative_address;
} mmc_card_state_t;

#define ULL unsigned long long
static const int show_debug = 0;
static mmc_card_state_t card_state[4];


/**
 * print_cmd_status
 */
static void print_cmd_status(void)
{
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_INIT(sts_reg, node, BDK_MIO_EMM_RSP_STS);
    BDK_CSR_INIT(rsp_lo, node, BDK_MIO_EMM_RSP_LO);
    BDK_CSR_INIT(rsp_hi, node, BDK_MIO_EMM_RSP_HI);

    printf("Command index = %d, command type = %d\n", sts_reg.s.cmd_idx, sts_reg.s.cmd_type);
    switch (sts_reg.s.rsp_type)
    {
        case 1:
            printf("Response type 1, card status = 0x%08x\n", (uint32_t) ((rsp_lo.u64 >>8) & 0xFFFFFFFF));
            break;
        case 2:
            printf("Response type 2, rsp_hi-bits = 0x%016llx, rsp_lo-bits = 0x%016llx\n", (ULL)rsp_hi.u64, (ULL)rsp_lo.u64);
            break;
        case 3:
            printf("Response type 3, OCR Register = 0x%08x\n", (uint32_t) ((rsp_lo.u64 >>8) & 0xFFFFFFFF));
            break;
        case 4:
            printf("Response type 4, RCA = 0x%llx, status =0x%llx, reg. addr. = 0x%llx, reg. contents = 0x%llx\n",
                   (ULL)((rsp_lo.u64 >> 24) & 0xffff), (ULL)((rsp_lo.u64 >> 23) & 0x1), (ULL)((rsp_lo.u64 >> 16) & 0x7F), (ULL)((rsp_lo.u64 >> 8) & 0xFF));
            break;
        case 5:
            printf("Response type 5, RCA = 0x%llx, status =0x%llx, reg. addr. = 0x%llx\n",
                   (ULL)((rsp_lo.u64 >> 24) & 0xffff), (ULL)((rsp_lo.u64 >> 23) & 0x1), (ULL)((rsp_lo.u64 >> 16) & 0x7F));
            break;

        default:
            printf("Unknown response type, rsp_sts. reg. = 0x%llx\n", (ULL)sts_reg.u64);
    }
}


/**
 * mmc_cmd
 *
 * @param cmd
 * @param arg
 * @param busid
 * @param dbuf
 * @param rtype_xor
 * @param ctype_xor
 * @param offset
 *
 * @return
 */
static bdk_mio_emm_rsp_sts_t mmc_cmd(uint64_t cmd, uint64_t arg, uint64_t busid, uint64_t dbuf, uint64_t rtype_xor, uint64_t ctype_xor, uint64_t offset)
{
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_DEFINE(cmd_reg, BDK_MIO_EMM_CMD);
    cmd_reg.u64 = 0;
    cmd_reg.s.bus_id = busid;
    cmd_reg.s.cmd_idx = cmd;
    cmd_reg.s.arg = arg;
    cmd_reg.s.dbuf = dbuf;
    cmd_reg.s.rtype_xor = rtype_xor;
    cmd_reg.s.ctype_xor = ctype_xor;
    cmd_reg.s.offset = offset;
    cmd_reg.s.cmd_val = 1;

    BDK_CSR_WRITE(node, BDK_MIO_EMM_CMD, cmd_reg.u64);
    BDK_CSR_INIT(sts_reg, node, BDK_MIO_EMM_RSP_STS);

    /* We use loops ever 1ms here instead of a wall time based timeout so
        code isn't needed to keep track of accurate time on both host and
        target */
    int wait_loops = 1000;
    while (sts_reg.s.cmd_done != 1)
    {
        if (--wait_loops <= 0)
        {
            if (show_debug)
                printf("No response, timeout.\n");
            return sts_reg;
        }
        bdk_wait_usec(1000);
        sts_reg.u64 = BDK_CSR_READ(node, BDK_MIO_EMM_RSP_STS);
    }

    if (sts_reg.s.rsp_val || sts_reg.s.stp_val)
    {
        int cmd_error = 0;
        if (sts_reg.s.rsp_bad_sts || sts_reg.s.stp_bad_sts)
        {
            BDK_CSR_INIT(rsp_lo, node, BDK_MIO_EMM_RSP_LO);
            if (show_debug)
                printf("Response bad status, cmd response = 0x%08x\n", (uint32_t) ((rsp_lo.u64 >>8) & 0xFFFFFFFF));
            cmd_error++;
        }
        if (sts_reg.s.rsp_crc_err || sts_reg.s.stp_crc_err)
        {
            if (show_debug)
                printf("Response CRC error.\n");
            cmd_error++;
        }
        if (sts_reg.s.rsp_timeout || sts_reg.s.stp_timeout)
        {
            if (show_debug)
                printf("Response timeout error.\n");
            cmd_error++;
        }
        if (sts_reg.s.blk_crc_err)
        {
            if (show_debug)
                printf("Read/write block CRC error.\n");
            cmd_error++;
        }
        if (sts_reg.s.blk_timeout)
        {
            if (show_debug)
                printf("Read/write block timeout error.\n");
            cmd_error++;
        }
        if (sts_reg.s.dbuf_err)
        {
            if (show_debug)
                printf("Dbuf error, no free buffer\n");
            cmd_error++;
        }
        if (cmd_error)
        {
            if (show_debug)
                print_cmd_status();
            return sts_reg;
        }
    }
    else
    {
        if ((sts_reg.s.cmd_idx != MMC_CMD_GO_IDLE_STATE) &&
            (sts_reg.s.cmd_idx != MMC_CMD_SET_DSR) &&
            (sts_reg.s.cmd_idx != MMC_CMD_GO_INACTIVE_STATE))
        {
            if (show_debug)
            {
                cmd_reg.u64 = BDK_CSR_READ(node, BDK_MIO_EMM_CMD);
                sts_reg.u64 = BDK_CSR_READ(node, BDK_MIO_EMM_RSP_STS);
                BDK_CSR_INIT(rsp_lo, node, BDK_MIO_EMM_RSP_LO);
                BDK_CSR_INIT(rsp_hi, node, BDK_MIO_EMM_RSP_HI);
                printf("No valid response\n");
                printf("mio_emm_cmd     = 0x%016llx\n", (ULL)cmd_reg.u64);
                printf("mio_emm_rsp_sts = 0x%016llx\n", (ULL)sts_reg.u64);
                printf("mio_emm_rsp_lo  = 0x%016llx\n", (ULL)rsp_lo.u64);
                printf("mio_emm_rsp_hi  = 0x%016llx\n", (ULL)rsp_hi.u64);
            }
            return sts_reg;
        }
    }

    sts_reg.u64 = 0;
    return sts_reg;
}


/**
 * print_ocr_reg
 *
 * @param ocr_reg
 */
static void print_ocr_reg(ocr_register_t ocr_reg)
{
    printf("\nOCR Register fields --\n");
    printf("Volts 1.70 - 1.95 0x%04x\n", ocr_reg.s.volts_1_7__1_95);
    printf("Volts 2.0 - 2.6   0x%04x\n", ocr_reg.s.volts_2_0__2_6);
    printf("Volts 2.7 - 3.6   0x%04x\n", ocr_reg.s.volts_2_7__3_6);
    printf("Access Mode       0x%04x\n", ocr_reg.s.access_mode);
}


/**
 * print_csd_reg
 *
 * @param reg_hi
 * @param reg_lo
 */
static void print_csd_reg(int chip_sel, uint64_t reg_hi, uint64_t reg_lo)
{
    if (card_state[chip_sel].card_is_sd)
    {
        sd_csd_register_hi_t  sd_csd_reg_hi;
        sd_csd_register_lo_t  sd_csd_reg_lo;
        sd_csd_reg_hi.u64 = reg_hi;
        sd_csd_reg_lo.u64 = reg_lo;
        printf("\nCSD Register fields --\n");
        printf("csd_structure       = 0x%x\n", sd_csd_reg_hi.s.csd_structure);
        printf("reserved_120_125    = 0x%x\n", sd_csd_reg_hi.s.reserved_120_125);
        printf("taac                = 0x%x\n", sd_csd_reg_hi.s.taac);
        printf("nsac                = 0x%x\n", sd_csd_reg_hi.s.nsac);
        printf("tran_speed          = 0x%x\n", sd_csd_reg_hi.s.tran_speed);
        printf("ccc                 = 0x%x\n", sd_csd_reg_hi.s.ccc);
        printf("read_bl_len         = 0x%x\n", sd_csd_reg_hi.s.read_bl_len);
        printf("read_bl_partial     = 0x%x\n", sd_csd_reg_hi.s.read_bl_partial);
        printf("write_blk_misalign  = 0x%x\n", sd_csd_reg_hi.s.write_blk_misalign);
        printf("read_blk_misalign   = 0x%x\n", sd_csd_reg_hi.s.read_blk_misalign);
        printf("dsr_imp             = 0x%x\n", sd_csd_reg_hi.s.dsr_imp);
        printf("reserved_74_75      = 0x%x\n", sd_csd_reg_hi.s.reserved_74_75);
        printf("c_size              = 0x%x\n", (sd_csd_reg_hi.s.c_size << 2) + sd_csd_reg_lo.s.c_size);
        printf("vdd_r_curr_min      = 0x%x\n", sd_csd_reg_lo.s.vdd_r_curr_min);
        printf("vdd_r_curr_max      = 0x%x\n", sd_csd_reg_lo.s.vdd_r_curr_max);
        printf("vdd_w_curr_min      = 0x%x\n", sd_csd_reg_lo.s.vdd_w_curr_min);
        printf("vdd_w_curr_max      = 0x%x\n", sd_csd_reg_lo.s.vdd_w_curr_max);
        printf("c_size_mult         = 0x%x\n", sd_csd_reg_lo.s.c_size_mult);
        printf("erase_blk_en        = 0x%x\n", sd_csd_reg_lo.s.erase_blk_en);
        printf("wp_grp_size         = 0x%x\n", sd_csd_reg_lo.s.wp_grp_size);
        printf("wp_grp_enable       = 0x%x\n", sd_csd_reg_lo.s.wp_grp_enable);
        printf("reserved_29_30      = 0x%x\n", sd_csd_reg_lo.s.reserved_29_30);
        printf("r2w_factor          = 0x%x\n", sd_csd_reg_lo.s.r2w_factor);
        printf("write_bl_len        = 0x%x\n", sd_csd_reg_lo.s.write_bl_len);
        printf("write_bl_partial    = 0x%x\n", sd_csd_reg_lo.s.write_bl_partial);
        printf("reserved_16_20      = 0x%x\n", sd_csd_reg_lo.s.reserved_16_20);
        printf("file_format_grp     = 0x%x\n", sd_csd_reg_lo.s.file_format_grp);
        printf("copy                = 0x%x\n", sd_csd_reg_lo.s.copy);
        printf("perm_write_protect  = 0x%x\n", sd_csd_reg_lo.s.perm_write_protect);
        printf("tmp_write_protect   = 0x%x\n", sd_csd_reg_lo.s.tmp_write_protect);
        printf("file_format         = 0x%x\n", sd_csd_reg_lo.s.file_format);
        printf("reserved_8_9        = 0x%x\n", sd_csd_reg_lo.s.reserved_8_9);
        printf("crc                 = 0x%x\n", sd_csd_reg_lo.s.crc);
        printf("always_one          = 0x%x\n", sd_csd_reg_lo.s.always_one);
    }
    else
    {
        mmc_csd_register_hi_t mmc_csd_reg_hi;
        mmc_csd_register_lo_t mmc_csd_reg_lo;
        mmc_csd_reg_hi.u64 = reg_hi;
        mmc_csd_reg_lo.u64 = reg_lo;
        printf("\nCSD Register fields --\n");
        printf("csd_structure       = 0x%x\n", mmc_csd_reg_hi.s.csd_structure);
        printf("spec_vers           = 0x%x\n", mmc_csd_reg_hi.s.spec_vers);
        printf("reserved_120_121    = 0x%x\n", mmc_csd_reg_hi.s.reserved_120_121);
        printf("taac                = 0x%x\n", mmc_csd_reg_hi.s.taac);
        printf("nsac                = 0x%x\n", mmc_csd_reg_hi.s.nsac);
        printf("tran_speed          = 0x%x\n", mmc_csd_reg_hi.s.tran_speed);
        printf("ccc                 = 0x%x\n", mmc_csd_reg_hi.s.ccc);
        printf("read_bl_len         = 0x%x\n", mmc_csd_reg_hi.s.read_bl_len);
        printf("read_bl_partial     = 0x%x\n", mmc_csd_reg_hi.s.read_bl_partial);
        printf("write_blk_misalign  = 0x%x\n", mmc_csd_reg_hi.s.write_blk_misalign);
        printf("read_blk_misalign   = 0x%x\n", mmc_csd_reg_hi.s.read_blk_misalign);
        printf("dsr_imp             = 0x%x\n", mmc_csd_reg_hi.s.dsr_imp);
        printf("reserved_74_75      = 0x%x\n", mmc_csd_reg_hi.s.reserved_74_75);
        printf("c_size              = 0x%x\n", (mmc_csd_reg_hi.s.c_size << 2) + mmc_csd_reg_lo.s.c_size);
        printf("vdd_r_curr_min      = 0x%x\n", mmc_csd_reg_lo.s.vdd_r_curr_min);
        printf("vdd_r_curr_max      = 0x%x\n", mmc_csd_reg_lo.s.vdd_r_curr_max);
        printf("vdd_w_curr_min      = 0x%x\n", mmc_csd_reg_lo.s.vdd_w_curr_min);
        printf("vdd_w_curr_max      = 0x%x\n", mmc_csd_reg_lo.s.vdd_w_curr_max);
        printf("c_size_mult         = 0x%x\n", mmc_csd_reg_lo.s.c_size_mult);
        printf("erase_grp_size      = 0x%x\n", mmc_csd_reg_lo.s.erase_grp_size);
        printf("erase_grp_mult      = 0x%x\n", mmc_csd_reg_lo.s.erase_grp_mult);
        printf("wp_grp_size         = 0x%x\n", mmc_csd_reg_lo.s.wp_grp_size);
        printf("wp_grp_enable       = 0x%x\n", mmc_csd_reg_lo.s.wp_grp_enable);
        printf("default_ecc         = 0x%x\n", mmc_csd_reg_lo.s.default_ecc);
        printf("r2w_factor          = 0x%x\n", mmc_csd_reg_lo.s.r2w_factor);
        printf("write_bl_len        = 0x%x\n", mmc_csd_reg_lo.s.write_bl_len);
        printf("write_bl_partial    = 0x%x\n", mmc_csd_reg_lo.s.write_bl_partial);
        printf("reserved_17_20      = 0x%x\n", mmc_csd_reg_lo.s.reserved_17_20);
        printf("content_prot_app    = 0x%x\n", mmc_csd_reg_lo.s.content_prot_app);
        printf("file_format_grp     = 0x%x\n", mmc_csd_reg_lo.s.file_format_grp);
        printf("copy                = 0x%x\n", mmc_csd_reg_lo.s.copy);
        printf("perm_write_protect  = 0x%x\n", mmc_csd_reg_lo.s.perm_write_protect);
        printf("tmp_write_protect   = 0x%x\n", mmc_csd_reg_lo.s.tmp_write_protect);
        printf("file_format         = 0x%x\n", mmc_csd_reg_lo.s.file_format);
        printf("crc                 = 0x%x\n", mmc_csd_reg_lo.s.crc);
        printf("always_one          = 0x%x\n", mmc_csd_reg_lo.s.always_one);
    }
}


/**
 * Setup the eMMC controller watchdog to 100ms
 */
static void wdog_default()
{
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_INIT(rst_boot, node, BDK_RST_BOOT);
    BDK_CSR_INIT(mode_reg, node, BDK_MIO_EMM_MODEX(0));
    uint64_t sclk = 50000000ull * rst_boot.s.pnr_mul;
    uint64_t wdog_value = sclk / 10 / (mode_reg.s.clk_hi + mode_reg.s.clk_lo);
    BDK_CSR_WRITE(node, BDK_MIO_EMM_WDOG, wdog_value);
}


/**
 * Macro to make it easier to submit a command and fail on bad status
 */
#define MMC_CMD_OR_ERROR(cmd, arg, busid, dbuf, rtype_xor, ctype_xor, offset)   \
do {                                                                            \
    bdk_mio_emm_rsp_sts_t status = mmc_cmd(cmd, arg, busid, dbuf, rtype_xor, ctype_xor, offset); \
    if(status.u64) {                                                            \
        bdk_error("MMC: Command " #cmd " failed\n");                            \
        return 0 ;                                                              \
    }                                                                           \
} while (0)


/**
 * Initialize a MMC for read/write
 *
 * @author creese (10/14/2013)
 * @param chip_sel Chip select to use
 *
 * @return Size of the SD card, zero on failure
 */
int64_t bdk_mmc_initialize(int chip_sel)
{
    bdk_node_t node = bdk_numa_local();
    bdk_mio_emm_rsp_sts_t status;
    ocr_register_t ocr_reg;

    // Disable bus 1, casues the clocking to reset to the default
    BDK_CSR_WRITE(node, BDK_MIO_EMM_CFG, 0x0);
    bdk_wait_usec(200000);

    // Disable buses and reset device using GPIO8
    BDK_CSR_WRITE(node, BDK_MIO_EMM_CFG, 0x0);
    BDK_CSR_MODIFY(c, node, BDK_GPIO_BIT_CFGX(8),
                   c.s.tx_oe = 1);
    bdk_wait_usec(1000);

    BDK_CSR_WRITE(node, BDK_GPIO_TX_CLR, 1<<8);

    bdk_wait_usec(200000);

    BDK_CSR_WRITE(node, BDK_GPIO_TX_SET, 1<<8);

    bdk_wait_usec(2000);

    // Enable bus 1
    BDK_CSR_WRITE(node, BDK_MIO_EMM_CFG, 1<<chip_sel);

    // Assume card is eMMC
    card_state[chip_sel].card_is_sd = 0;

    // Reset the status mask reg., boot will change it
    BDK_CSR_WRITE(node, BDK_MIO_EMM_STS_MASK, 0xE4390080);

    bdk_wait_usec(2000);

    // Setup watchdog timer
    wdog_default();

    //Reset the device
    MMC_CMD_OR_ERROR(MMC_CMD_GO_IDLE_STATE, 0, chip_sel, 0, 0, 0, 0);

    // Do a CMD SEND_EXT_CSD (8)
    status = mmc_cmd(MMC_CMD_SEND_EXT_CSD, 0x000001AA, chip_sel, 0, 2, 1, 0);
    if (status.u64 == 0x0)
    {
        // We may have an SD card, as it should respond
        BDK_CSR_INIT(rsp_lo, node, BDK_MIO_EMM_RSP_LO);
        if (((rsp_lo.u64 >> 8) & 0xFFFFFFFFFF) != 0x08000001AA)
        {
            bdk_error("MMC: Unexpected response from MMC_CMD_SEND_EXT_CSD\n");
            return 0;
        }
        // Send a ACMD 41
        do
        {
            status = mmc_cmd(MMC_CMD_APP_CMD, 0, chip_sel, 0, 0, 0, 0);
            if (status.u64 == 0x0)
            {
                status = mmc_cmd(41, 0x40ff8000, chip_sel, 0, 3, 0, 0);
                if (status.u64)
                {
                    bdk_error("MMC: Failed to recognize card\n");
                    return 0;
                }
                card_state[chip_sel].card_is_sd = 1;
            }
            else
            {
                // Failed, not sure whats out there
                bdk_error("MMC: Failed to recognize card\n");
                return 0;
            }

            ocr_reg.u32 = (uint32_t) ((BDK_CSR_READ(node, BDK_MIO_EMM_RSP_LO) >>8) &0xFFFFFFFF);
        } while (ocr_reg.s.done_bit == 0x0);
        // Success, we have an SD card version 2.0 or above, fall thru
    }
    else
    {
        // Card could be an SD version less than 2.0 or an MMC card
        // Send a ACMD 41
        do
        {
            status = mmc_cmd(MMC_CMD_APP_CMD, 0, chip_sel, 0, 0, 0, 0);
            if (status.u64 == 0x0)
            {
                status = mmc_cmd(41, 0x40ff8000, chip_sel, 0, 3, 0, 0);
                if (status.u64)
                {
                    // Have an SD card, version less than 2.0
                    // fall thru, exit the loop
                    card_state[chip_sel].card_is_sd = 1;
                    break;
                }
            }
            else
            {
                // APP_CMD command failed
                break;
            }
            ocr_reg.u32 = (uint32_t) ((BDK_CSR_READ(node, BDK_MIO_EMM_RSP_LO) >>8) &0xFFFFFFFF);
        } while (ocr_reg.s.done_bit == 0x0);

        if (status.u64 == 0x0)
        {
            // Success, we have an SD card version 2.0 or less
            card_state[chip_sel].card_is_sd = 1;
        }
        else
        {
            //Have an MMC card, do a command 1
            //Select the initial operating conditions
            do
            {
                MMC_CMD_OR_ERROR(MMC_CMD_SEND_OP_COND, 0x40ff8000, chip_sel, 0, 0, 0, 0);
                ocr_reg.u32 = (uint32_t) ((BDK_CSR_READ(node, BDK_MIO_EMM_RSP_LO) >>8) &0xFFFFFFFF);
            } while (ocr_reg.s.done_bit == 0x0);
        }
    }
    // Global to determine if the card is block or byte addressable.
    card_state[chip_sel].block_addressable_device = ocr_reg.s.access_mode;
    if (show_debug)
        print_ocr_reg(ocr_reg);

    // Get card identification
    MMC_CMD_OR_ERROR(MMC_CMD_ALL_SEND_CID, 0, chip_sel, 0, 0, 0, 0);

    if (card_state[chip_sel].card_is_sd)
    {
        // For SD, read the relative address from the card
        // CMD3 response for SD cards is R6 format, similar to R1, but different
        // Need to chane the mio_EMM_STS_MASK register so we don't get a response status error
        BDK_CSR_INIT(sts_mask, node, BDK_MIO_EMM_STS_MASK);
        BDK_CSR_WRITE(node, BDK_MIO_EMM_STS_MASK, 0xE000);
        status = mmc_cmd(MMC_CMD_SET_RELATIVE_ADDR, 0, chip_sel, 0, 0, 0, 0);
        BDK_CSR_WRITE(node, BDK_MIO_EMM_STS_MASK, sts_mask.u64);
        if (status.u64)
        {
            bdk_error("MMC: Command MMC_CMD_SET_RELATIVE_ADDR failed\n");
            return 0;
        }
        card_state[chip_sel].relative_address = ((BDK_CSR_READ(node, BDK_MIO_EMM_RSP_LO) >>24) &0xFFFF);
    }
    else
    {
        // For MMC, set card relative address
        card_state[chip_sel].relative_address = 1; //Default for MMC cards
        MMC_CMD_OR_ERROR(MMC_CMD_SET_RELATIVE_ADDR, card_state[chip_sel].relative_address << 16, chip_sel, 0, 0, 0, 0);
    }

    BDK_CSR_WRITE(node, BDK_MIO_EMM_RCA, card_state[chip_sel].relative_address);

    // Get CSD Register
    MMC_CMD_OR_ERROR(MMC_CMD_SEND_CSD, card_state[chip_sel].relative_address << 16, chip_sel, 0, 0, 0, 0);
    mmc_csd_register_lo_t csd_reg_lo;
    csd_reg_lo.u64 = (BDK_CSR_READ(node, BDK_MIO_EMM_RSP_LO));
    mmc_csd_register_hi_t csd_reg_hi;
    csd_reg_hi.u64 = (BDK_CSR_READ(node, BDK_MIO_EMM_RSP_HI));
    uint64_t mmc_capacity;
    if (card_state[chip_sel].card_is_sd)
    {
        sd_csd_register_hi_t  sd_csd_reg_hi;
        sd_csd_register_lo_t  sd_csd_reg_lo;
        sd_csd_reg_hi.u64 = csd_reg_hi.u64;
        sd_csd_reg_lo.u64 = csd_reg_lo.u64;
        mmc_capacity = (sd_csd_reg_hi.s.c_size << 2) + sd_csd_reg_lo.s.c_size;
        mmc_capacity = (mmc_capacity + 1) << (sd_csd_reg_lo.s.c_size_mult + 2);
        mmc_capacity *= 1<<sd_csd_reg_hi.s.read_bl_len;
    }
    else
    {
        mmc_csd_register_hi_t mmc_csd_reg_hi;
        mmc_csd_register_lo_t mmc_csd_reg_lo;
        mmc_csd_reg_hi.u64 = csd_reg_hi.u64;
        mmc_csd_reg_lo.u64 = csd_reg_lo.u64;
        mmc_capacity = (mmc_csd_reg_hi.s.c_size << 2) + mmc_csd_reg_lo.s.c_size;
        mmc_capacity = (mmc_capacity + 1) << (mmc_csd_reg_lo.s.c_size_mult + 2);
        mmc_capacity *= 1<<mmc_csd_reg_hi.s.read_bl_len;
    }

    if (show_debug)
        print_csd_reg(chip_sel, csd_reg_hi.u64, csd_reg_lo.u64);

    // Select Card
    MMC_CMD_OR_ERROR(MMC_CMD_SELECT_CARD, card_state[chip_sel].relative_address << 16 , chip_sel, 0, 0, 0, 0);
    // Send Card Status
    MMC_CMD_OR_ERROR(MMC_CMD_SEND_STATUS, card_state[chip_sel].relative_address << 16 , chip_sel, 0, 0, 0, 0);

    // Return the card size in bytes
    return mmc_capacity;
}

/**
 * Read blocks from a MMC card
 *
 * @author creese (10/14/2013)
 * @param chip_sel Chip select to use
 * @param address  Offset into the card in bytes. Must be a multiple of 512
 * @param buffer   Buffer to read into
 * @param length   Length to read in bytes. Must be a multiple of 512
 *
 * @return Zero on success, negative on failure
 */
int bdk_mmc_read(int chip_sel, uint64_t address, void *buffer, int length)
{
    bdk_node_t node = bdk_numa_local();
    if (address > (1ull << 40))
    {
        bdk_error("MMC read address too large\n");
        return -1;
    }
    if (address & 511)
    {
        bdk_error("MMC read address must be a multiple of 512\n");
        return -1;
    }
    if (length > (1ll << 30))
    {
        bdk_error("MMC read length too large\n");
        return -1;
    }
    if (length & 511)
    {
        bdk_error("MMC read length must be a multiple of 512\n");
        return -1;
    }

    /* Read until we've read all data */
    while (length > 0)
    {
        /* Send the read command */
        BDK_CSR_DEFINE(status, BDK_MIO_EMM_RSP_STS);
        status = mmc_cmd(MMC_CMD_READ_SINGLE_BLOCK, (card_state[chip_sel].block_addressable_device) ? address/512 : address, chip_sel, 0, 0, 0, 0);
        if (status.u64)
        {
            bdk_error("MMC: Read single block failed\n");
            return -1;
        }

        /* Set our location in the internal buffer */
        BDK_CSR_DEFINE(buf_idx, BDK_MIO_EMM_BUF_IDX);
        buf_idx.u64 = 0;
        buf_idx.s.inc = 1;
        buf_idx.s.buf_num = 0;
        buf_idx.s.offset = 0;
        BDK_CSR_WRITE(node, BDK_MIO_EMM_BUF_IDX, buf_idx.u64);

        /* Read out the data block and add it to the output buffer */
        for (int i=0; i<512/8; i++)
        {
            uint64_t data = bdk_be64_to_cpu(BDK_CSR_READ(node, BDK_MIO_EMM_BUF_DAT));
            *(uint64_t*)buffer = data;
            buffer += 8;
        }
        /* Increment to the next position and adjust the size left */
        address += 512;
        length -= 512;
    }
    return 0;
}

/**
 * Write blocks to a MMC card
 *
 * @author creese (10/14/2013)
 * @param chip_sel Chip select to use
 * @param address  Offset into the card in bytes. Must be a multiple of 512
 * @param buffer   Buffer to write
 * @param length   Length to write in bytes. Must be a multiple of 512
 *
 * @return Zero on success, negative on failure
 */
int bdk_mmc_write(int chip_sel, uint64_t address, const void *buffer, int length)
{
    bdk_node_t node = bdk_numa_local();
    if (address > (1ull << 40))
    {
        bdk_error("MMC write address too large\n");
        return -1;
    }
    if (address & 511)
    {
        bdk_error("MMC write address must be a multiple of 512\n");
        return -1;
    }
    if (length > (1ll << 30))
    {
        bdk_error("MMC write length too large\n");
        return -1;
    }
    if (length & 511)
    {
        bdk_error("MMC write length must be a multiple of 512\n");
        return -1;
    }

    /* Write until no more data */
    while (length > 0)
    {
        /* Set our location in the internal buffer */
        BDK_CSR_DEFINE(buf_idx, BDK_MIO_EMM_BUF_IDX);
        buf_idx.u64 = 0;
        buf_idx.s.inc = 1;
        buf_idx.s.buf_num = 0;
        buf_idx.s.offset = 0;
        BDK_CSR_WRITE(node, BDK_MIO_EMM_BUF_IDX, buf_idx.u64);

        /* Fill the internal buffer */
        for (int i=0; i<512/8; i++)
        {
            BDK_CSR_WRITE(node, BDK_MIO_EMM_BUF_DAT, bdk_cpu_to_be64(*(uint64_t*)buffer));
            buffer += 8;
        }

        /* Write single block */
        BDK_CSR_DEFINE(status, BDK_MIO_EMM_RSP_STS);
        status = mmc_cmd(MMC_CMD_WRITE_BLOCK, (card_state[chip_sel].block_addressable_device) ? address/512 : address, chip_sel, 0, 0, 0, 0);
        if (status.u64)
        {
            bdk_error("MMC: Write single block failed\n");
            return -1;
        }
        length -= 512;
    }
    return 0;
}

