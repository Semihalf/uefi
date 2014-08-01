#ifndef __CAVIUM_MMC_H__
#define __CAVIUM_MMC_H__

// Basic definitions for the eMMC interface
// Copyright 2014 Cavium,Inc.

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
	uint64_t u;

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
	uint64_t u;

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
	uint64_t u;

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
	uint64_t u;

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
    uint64_t u;

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

#endif /* __CAVIUM_MMC_H__ */
