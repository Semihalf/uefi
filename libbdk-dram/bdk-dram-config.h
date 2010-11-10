typedef struct
{
    uint8_t data[256];
} bdk_dram_spd_t;

extern int bdk_dram_config();
extern int bdk_dram_spd_read(int spd_address, bdk_dram_spd_t *spd);
extern int bdk_dram_spd_check_csum(const bdk_dram_spd_t *spd);

