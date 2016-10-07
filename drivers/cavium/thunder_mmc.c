#include <arch.h>
#include <platform_def.h>
#include <thunder_private.h>
#include <stdint.h>
#include <stdio.h>
#include "thunder_mmc.h"

#define MMC_DBG printf

#define ROUND_UP(val, align)	(((val) + (align) - 1) / (align) * (align))

typedef struct reg_base {
	uint64_t gpio_base;
	uint64_t rst_base;
	uint64_t emm_base;
} reg_base_t;

typedef struct mio_emm_driver {
	int bus_id;
	int rca;
	int sector_size;
	int bus_width;
	int sector_mode;
} mio_emm_driver_t;

mio_emm_driver_t mmc_drv = { 0 };
reg_base_t regs = { 0 };

int init_mmc();
union cavm_mio_emm_rsp_sts mio_emm_cmd(uint32_t cmd_idx, uint32_t ctype_xor, uint32_t rtype_xor, uint32_t arg);

/* Wait for delay reference cycles */
void wait(uint64_t delay)
{
	volatile uint64_t count = CSR_READ(regs.rst_base, CAVM_RST_REF_CNTR);
	uint64_t start = count;
	uint64_t end = start + delay;

	do {
		count = CSR_READ(regs.rst_base, CAVM_RST_REF_CNTR);
	} while (count < end);
}

void init_reg_base()
{
	unsigned long node = cavm_numa_local();

	regs.gpio_base = CSR_PA(node, CAVM_GPIO_PF_BAR0);
	regs.rst_base = CSR_PA(node, CAVM_RST_PF_BAR0);
	regs.emm_base = CSR_PA(node, CAVM_MIO_EMM_PF_BAR0);
}

int sdmmc_init()
{
	uint64_t val;
	int clock;
	int sec_cap = 0;
	volatile union cavm_rst_boot rst_boot;
	volatile union cavm_gpio_bit_cfgx gpio_bit_cfgx;
	volatile union cavm_mio_emm_switch emm_switch, slow_switch;
	volatile union cavm_mio_emm_rsp_sts emm_rsp_sts;
	volatile unsigned long emm_rsp_lo;


	init_reg_base();
	mmc_drv.bus_id = 0;
	mmc_drv.sector_size = MMC_SECTOR_SIZE;

	/* Set bit 1 to use eMMC bus 0 */
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_CFG, 0x1);
	return init_mmc();

	rst_boot.u = CSR_READ(regs.rst_base, CAVM_RST_BOOT);

	/* Clear GPIO_BIT_CFG8[TX_OE] to disable power / enable reset */
	//gpio_bit_cfgx.u = 0;
	//gpio_bit_cfgx.s.tx_oe = 0;
	//CSR_WRITE(regs.gpio_base, GPIO_BIT_CFGX(8), gpio_bit_cfgx.u);
	wait(200 * REF_FREQ);

	val = (CSR_READ(regs.gpio_base, CAVM_GPIO_RX_DAT) >> 8) & 0x1;
	if (val)
		CSR_WRITE(regs.gpio_base, CAVM_GPIO_TX_CLR, 1 << 8);
	else
		CSR_WRITE(regs.gpio_base, CAVM_GPIO_TX_SET, 1 << 8);

	gpio_bit_cfgx.u = 0;
	gpio_bit_cfgx.s.tx_oe = 1;
	CSR_WRITE(regs.gpio_base, CAVM_GPIO_BIT_CFGX(8), gpio_bit_cfgx.u);
	wait(2 * REF_FREQ);

	/* Set bit 1 to use eMMC bus 0 */
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_CFG, 0x1);

	/* EMMC:(70)  Clear mio_emm_sts_mask.STS_MSK[31:8,6:0], Set Switch_ERR(<7>)
	 * ignore errors except <7>
	 */
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_STS_MASK, 0x80);

	/* 400 KHz */
	clock = (125 * rst_boot.s.pnr_mul + 1) >> 1;
	emm_switch.u = 0;
	emm_switch.s.power_class = 10;
	emm_switch.s.clk_hi = emm_switch.s.clk_lo = clock;
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_SWITCH, emm_switch.u);

	clock = (5 * rst_boot.s.pnr_mul + 3) >> 2;
	emm_switch.s.clk_hi = emm_switch.s.clk_lo = clock;
	emm_switch.s.power_class = 10;
	emm_switch.s.bus_width = BUS_8_BIT;
	wait(1.2*REF_FREQ);

	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_WDOG, 0x400);

	// DO while loop
	clock = (125 * rst_boot.s.pnr_mul + 1) >> 1;
	slow_switch.u = 0;
	slow_switch.s.power_class = 10;
	//slow_switch.s.clk_hi = 0;
	//slow_switch.s.clk_lo = clock;
	slow_switch.s.clk_hi = slow_switch.s.clk_lo = clock;
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_SWITCH, slow_switch.u);

	mio_emm_cmd(MMC_CMD_GO_IDLE_STATE, 0, 0, 0);
	emm_rsp_sts = mio_emm_cmd(SD_CMD_SEND_IF_COND, 1, 2, 0x1aa);
	sec_cap = emm_rsp_sts.s.rsp_timeout ? 0 : 1;
	(void)sec_cap;

	mio_emm_cmd(MMC_CMD_APP_CMD, 0, 0, 0);
	emm_rsp_sts = mio_emm_cmd(SD_CMD_APP_SEND_OP_COND, 0, 3, 0x40ff8000);

	/* Command 41 SD_CMD_APP_SEND_OP_COND timesout - eMMC  */
	if (emm_rsp_sts.s.rsp_timeout) {
		MMC_DBG("%s %d: mmc_drv\n", __func__, __LINE__);
		return init_mmc();
	}

	emm_rsp_lo = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_LO);
	/* SD card */
	if ((emm_rsp_lo & (1UL << 39)) == 0) {
		MMC_DBG("%s %d: error emm_rsp_lo = %lx\n", __func__, __LINE__, emm_rsp_lo);
		/* TODO: retry */
		return -1;
	}
	mmc_drv.sector_mode = emm_rsp_lo & (0x3UL << 37);
	mmc_drv.bus_width = BUS_4_BIT;
	emm_rsp_sts = mio_emm_cmd(MMC_CMD_ALL_SEND_CID, 0, 0, 0x0);
	emm_rsp_sts = mio_emm_cmd(SD_CMD_SEND_RELATIVE_ADDR, 0, 0, 0x0);
	mmc_drv.rca = (emm_rsp_lo >> 24) & 0xffff;
	emm_rsp_sts = mio_emm_cmd(MMC_CMD_SELECT_CARD, 0, 0, mmc_drv.rca << 16);
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_RCA, mmc_drv.rca);

	/* Switch to new bus width etc.
	 * TODO: read the CSD register and config card properly
	 */
	mio_emm_cmd(MMC_CMD_APP_CMD, 0, 0, (mmc_drv.rca<<16));
	emm_rsp_sts = mio_emm_cmd(MMC_CMD_SWITCH, 0, 0, mmc_drv.bus_width << 1);
	emm_rsp_lo = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_LO);
	if (!emm_rsp_sts.s.rsp_timeout) {

		if (!(emm_rsp_lo >> (8 + 5) & 1)			// APP_CMD
			&& (emm_rsp_lo >> (8 + 31) & 1)		// OUT_OF_RANGE
			&& (emm_rsp_lo >> (8 + 19) & 1)){ 	// ERROR

			emm_rsp_sts = mio_emm_cmd(MMC_CMD_SEND_STATUS, 0, 0, mmc_drv.rca << 16);
			emm_rsp_lo = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_LO);
			if (!emm_rsp_sts.s.rsp_timeout) {

				if ((emm_rsp_lo >> (8 + 31) & 1)		// OUT_OF_RANGE
					 && (emm_rsp_lo >> (8 + 19) & 1)) {	// ERROR

					/* 20 MHz */
					clock = (5 * rst_boot.s.pnr_mul + 3) >> 2;
					emm_switch.u = 0;
					emm_switch.s.bus_width = mmc_drv.bus_width;
					emm_switch.s.clk_hi = clock;
					emm_switch.s.clk_lo = clock;
					emm_switch.s.power_class = 10;
					emm_switch.s.switch_exe = 1;
					CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_SWITCH, emm_switch.u);
					MMC_DBG("%s %d: emm_rsp_sts\n", __func__, __LINE__);

					do {
						emm_rsp_sts.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_STS);
					} while (emm_rsp_sts.s.switch_val);
				}
			}
		}
	}

	MMC_DBG("%s %d: done\n", __func__, __LINE__);
	return 0;
}

int init_mmc()
{
	int retry = INIT_MAX_RETRY;
	int clock;
	volatile uint64_t emm_rsp_lo;
	volatile union cavm_rst_boot rst_boot;
	volatile union cavm_mio_emm_rsp_sts emm_rsp_sts;
	volatile union cavm_mio_emm_switch emm_switch;

return 0;
	do {
		emm_rsp_sts = mio_emm_cmd(MMC_CMD_SEND_OP_COND, 0, 0, 0x40FF8000);
		if (emm_rsp_sts.s.rsp_timeout) {
			printf("Error, MMC_CMD_SEND_OP_COND timed out\n");
		}
		emm_rsp_lo = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_LO);
	} while (retry-- > 0 && (emm_rsp_lo & (1UL << 39)) == 0);

	if (retry == 0) {
		return -1;
	};

	mmc_drv.rca = 1;
	mmc_drv.bus_width = BUS_8_BIT;
	//mmc_drv.sector_mode = emm_rsp_lo & (0x3UL << 37);
	mmc_drv.sector_mode = emm_rsp_lo >> 38 & 1;
	emm_rsp_sts = mio_emm_cmd(MMC_CMD_ALL_SEND_CID, 0, 0, 0x0);
	if (emm_rsp_sts.s.rsp_timeout) {
		printf("Error, MMC_CMD_ALL_SEND_CID timed out\n");
	}
	emm_rsp_sts = mio_emm_cmd(MMC_CMD_SET_RELATIVE_ADDR, 0, 0, (mmc_drv.rca<<16));
	if (emm_rsp_sts.s.rsp_timeout || emm_rsp_sts.s.rsp_crc_err) {
		printf("Error, MMC_CMD_SET_RELATIVE_ADDR timed out\n");
	}
	emm_rsp_sts = mio_emm_cmd(MMC_CMD_SELECT_CARD, 0, 0, (mmc_drv.rca<<16));
	if (emm_rsp_sts.s.rsp_timeout || emm_rsp_sts.s.rsp_crc_err) {
		printf("Error, MMC_CMD_SELECT_CARD timed out\n");
	}
	//CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_RCA, mmc_drv.rca);
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_WDOG, 0xf80818);

	rst_boot.u = CSR_READ(regs.rst_base, CAVM_RST_BOOT);
	clock = (5 * rst_boot.s.pnr_mul + 3) >> 2;
	emm_switch.s.clk_hi = emm_switch.s.clk_lo = clock;
	emm_switch.s.power_class = 0;
	emm_switch.s.bus_width = 0;
	emm_switch.u = 0x140014;
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_SWITCH, emm_switch.u);

	/* 20 MHz */
	clock = (5 * rst_boot.s.pnr_mul + 3) >> 2;
	emm_switch.s.clk_hi = emm_switch.s.clk_lo = clock;
	emm_switch.s.power_class = 10;
	emm_switch.s.bus_width = BUS_8_BIT;
	emm_switch.s.switch_exe = 1;
	emm_switch.u = 0x800020a00140014;
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_SWITCH, emm_switch.u);
	do {
	  emm_rsp_sts.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_STS);
	} while (emm_rsp_sts.s.switch_val);

	return 0;
}

union cavm_mio_emm_rsp_sts mio_emm_cmd(uint32_t cmd_idx, uint32_t ctype_xor, uint32_t rtype_xor, uint32_t arg)
{
	union cavm_mio_emm_cmd cmd;
	volatile union cavm_mio_emm_rsp_sts emm_rsp_sts;

	cmd.u = 0;
	cmd.s.cmd_val = 1;
	cmd.s.ctype_xor = ctype_xor;
	cmd.s.rtype_xor = rtype_xor;
	cmd.s.arg = arg;
	cmd.s.cmd_idx = cmd_idx;
	CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_CMD, cmd.u);

	do {
		emm_rsp_sts.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_STS);
	} while (emm_rsp_sts.s.cmd_val);


	return emm_rsp_sts;
}

/* Initiatiate a DMA transfer */
int mmc_rw_sector(int write, unsigned int sector_addr, int blk_cnt, void *buf)
{
	int sector_mode;
	uintptr_t buffer = (uintptr_t)buf;
	union cavm_mio_emm_dma mio_emm_dma;
	union cavm_mio_emm_dma_cfg emm_dma_cfg;
	union cavm_mio_emm_rsp_sts emm_rsp_sts;

	sector_mode = 1;//mmc_drv.sector_mode;

	while (blk_cnt > 0) {
		int blks = blk_cnt;
		if (blks > 128)
			blks = 128;

		emm_dma_cfg.u = 0;
		mio_emm_dma.u = 0;

		emm_dma_cfg.s.en = 1;
		emm_dma_cfg.s.rw = write ? 1 : 0;
		emm_dma_cfg.s.endian = 1;
		emm_dma_cfg.s.size = ((blks << 9) >> 3) - 1;

		mio_emm_dma.s.dma_val = 1;
		mio_emm_dma.s.bus_id = mmc_drv.bus_id;
		mio_emm_dma.s.sector = sector_mode ? 1 : 0;
		mio_emm_dma.s.card_addr = sector_mode ? sector_addr >> 9 : sector_addr;
		mio_emm_dma.s.block_cnt = blks;

		CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_DMA_ADR, buffer);
		CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_DMA_CFG, emm_dma_cfg.u);
		CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_DMA, mio_emm_dma.u);

		do {
			emm_rsp_sts.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_STS);
		} while (emm_rsp_sts.s.dma_val);

		/* DMA error */
		if (emm_rsp_sts.s.dma_pend) {
			MMC_DBG("sdmmc: DMA error\n");

			mio_emm_dma.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_DMA);
			mio_emm_dma.s.dma_val = 1;
			mio_emm_dma.s.dat_null = 1;
			CSR_WRITE(regs.emm_base, CAVM_MIO_EMM_DMA, mio_emm_dma.u);
			do {
				emm_rsp_sts.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_RSP_STS);
			} while (emm_rsp_sts.s.dma_val);

			return -1;
		}

		do {
			emm_dma_cfg.u = CSR_READ(regs.emm_base, CAVM_MIO_EMM_DMA_CFG);
		} while (emm_dma_cfg.s.en);

		blk_cnt -= blks;
		sector_addr += 512 * blks;

		buffer += 512 * blks;
		__asm__ __volatile__ ("dsb sy");
		putchar('.');
	}

	putchar('\n');

	return 0;
}

int sdmmc_rw_data(int write, uintptr_t addr, int size, void *buf, int buf_size)
{
	int err;
	int blk_cnt;
	int round_size;

	/* DMA engine address must be 64-bit aligned */
	if (size == 0 || ((uintptr_t)buf & 0x7)) {
		printf("Invalid size %d or unaligned addr %p\n",
					size, buf);
		return -1;
	}

	round_size = ROUND_UP(size, mmc_drv.sector_size);
	if (buf_size < size) {
		printf("buf_size %d too small, need %d (aligned %d)\n",
			buf_size, size, round_size);
	}

	blk_cnt = round_size / mmc_drv.sector_size;

	err = mmc_rw_sector(write, addr, blk_cnt, buf);
	return err ? 0 : round_size;
}
