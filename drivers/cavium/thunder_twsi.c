/** @file
#
#  Copyright (c) 2014, Cavium Inc. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

#include <stddef.h>
#include <assert.h>
#include <platform_def.h>
#include <thunder_private.h>
#include <thunder_dt.h>

#define PLL_REF_CLK 50000000	/* 50 MHz */
#define TWSI_NUM 6

static int gpio_set_out (int pin)
{
	gpio_tx_set_t gpio_tx_set;
	gpio_bit_cfgx_t gpio_bit_cfg;
	unsigned long node = cavm_numa_local();

	gpio_tx_set.u = 0;
	gpio_tx_set.s.set = (1ULL << pin);
	CSR_WRITE_PA(node, GPIO_TX_SET, gpio_tx_set.u);
	gpio_bit_cfg.u = CSR_READ_PA(node, GPIO_BIT_CFGX(pin));
	gpio_bit_cfg.s.tx_oe = 1;
	gpio_bit_cfg.s.pin_sel = 0;
	CSR_WRITE_PA(node, GPIO_BIT_CFGX(pin), gpio_bit_cfg.u);
	return 0;
}

static int gpio_clr_out (int pin)
{
	gpio_bit_cfgx_t gpio_bit_cfg;
	gpio_tx_clr_t gpio_tx_clr;
	unsigned long node = cavm_numa_local();

	gpio_tx_clr.u = 0;
	gpio_tx_clr.s.clr = (1ULL << pin);
	CSR_WRITE_PA(node, GPIO_TX_CLR, gpio_tx_clr.u);
	gpio_bit_cfg.u = CSR_READ_PA(node, GPIO_BIT_CFGX(pin));
	gpio_bit_cfg.s.pin_sel = 0;
	gpio_bit_cfg.s.tx_oe = 1;
	CSR_WRITE_PA(node, GPIO_BIT_CFGX(pin), gpio_bit_cfg.u);
	return 0;
}

uint64_t tz_count(uint64_t x)
{
	uint64_t ret = 0;

	if (!x) {
		ret = 64;
	} else {
		ret += (x & 0x00000000ffffffff) ? 0 : 32;
		ret += (x & 0x0000ffff0000ffff) ? 0 : 16;
		ret += (x & 0x00ff00ff00ff00ff) ? 0 : 8;
		ret += (x & 0x0f0f0f0f0f0f0f0f) ? 0 : 4;
		ret += (x & 0x3333333333333333) ? 0 : 2;
		ret += (x & 0x5555555555555555) ? 0 : 1;
	}

	return ret;
}

enum {
	TWSI_SLAVE_ADD     = 0,
	TWSI_DATA 	   = 1,
	TWSI_CTL 	   = 2,
	TWSI_CLKCTL 	   = 3,
	TWSI_STAT 	   = 3,
	TWSI_SLAVE_ADD_EXT = 4,
	TWSI_RST	   = 7,
};


enum {
	TWSI_CTL_AAK	= 1 << 2,
	TWSI_CTL_IFLG	= 1 << 3,
	TWSI_CTL_STP	= 1 << 4,
	TWSI_CTL_STA	= 1 << 5,
	TWSI_CTL_ENAB	= 1 << 6,
	TWSI_CTL_CE	= 1 << 7,
};

enum {
	TWSI_CLKCTL_NS	= 0,
	TWSI_CLKCTL_MS	= 3,
};

static uint64_t twsi_write_sw(unsigned int node, unsigned int twsi_num,
			      mio_twsx_sw_twsi_t twsi_sw)
{
	twsi_sw.s.r = 0;
	twsi_sw.s.v = 1;

	assert(twsi_num < TWSI_NUM);

	CSR_WRITE_PA(node, MIO_TWSX_SW_TWSI(twsi_num), twsi_sw.u);

	do {
		twsi_sw.u = CSR_READ_PA(node, MIO_TWSX_SW_TWSI(twsi_num));
	} while (twsi_sw.s.v != 0);

	return twsi_sw.u;
}

static uint64_t twsi_read_sw(unsigned int node, unsigned int twsi_num,
			     mio_twsx_sw_twsi_t twsi_sw)
{
	twsi_sw.s.r = 1;
	twsi_sw.s.v = 1;

	assert(twsi_num < TWSI_NUM);

	CSR_WRITE_PA(node, MIO_TWSX_SW_TWSI(twsi_num), twsi_sw.u);

	do {
		twsi_sw.u = CSR_READ_PA(node, MIO_TWSX_SW_TWSI(twsi_num));
	} while (twsi_sw.s.v != 0);

	return twsi_sw.u;
}

void twsi_reset(unsigned int node, unsigned int twsi_num)
{
	mio_twsx_sw_twsi_t twsi_sw;

	twsi_sw.u = 0;

	twsi_sw.s.op = 0x6;
	twsi_sw.s.eop_ia = TWSI_RST;

	twsi_write_sw(node, twsi_num, twsi_sw);
}

static void twsi_write_ctl(unsigned int node, unsigned int twsi_num, uint8_t data)
{
	mio_twsx_sw_twsi_t twsi_sw;

	twsi_sw.u = 0;
	twsi_sw.s.op = 0x6;
	twsi_sw.s.eop_ia = TWSI_CTL;
	twsi_sw.s.data = data;

	twsi_write_sw(node, twsi_num, twsi_sw);
}

static uint8_t twsi_read_ctl(unsigned int node, unsigned int twsi_num)
{
	mio_twsx_sw_twsi_t twsi_sw;

	twsi_sw.u = 0;
	twsi_sw.s.op = 0x6;
	twsi_sw.s.eop_ia = TWSI_CTL;

	return twsi_read_sw(node, twsi_num, twsi_sw);
}

static void twsi_enable(unsigned int node, unsigned int twsi_num)
{
	uint8_t twsi_ctl = TWSI_CTL_ENAB;

	twsi_write_ctl(node, twsi_num, twsi_ctl);
}

static void twsi_start(unsigned int node, unsigned int twsi_num)
{
	uint8_t twsi_ctl = TWSI_CTL_STA | TWSI_CTL_ENAB;

	twsi_write_ctl(node, twsi_num, twsi_ctl);
}

static void twsi_stop(unsigned int node, unsigned int twsi_num)
{
	uint8_t twsi_ctl = TWSI_CTL_STP | TWSI_CTL_ENAB;

	twsi_write_ctl(node, twsi_num, twsi_ctl);
}

void twsi_set_speed(unsigned int node, unsigned int twsi_num, unsigned int speed)
{
	mio_twsx_sw_twsi_t twsi_sw;
	rst_boot_t rst_boot;
	uint8_t twsi_clkctl;
	unsigned int div_n, div_m, div_d;
	unsigned long pnr_clk, tclk;
	unsigned long thp;

	rst_boot.u = CSR_READ_PA(node, RST_BOOT);

	pnr_clk = rst_boot.s.pnr_mul * PLL_REF_CLK;

	twsi_sw.u = 0;
	twsi_sw.s.eop_ia = 0x4;

	thp = twsi_read_sw(node, twsi_num, twsi_sw);

	tclk = pnr_clk / (2 * (thp + 1));

	div_d = (speed > 400000) ? 15 : 10;

	div_n = tz_count(tclk / (speed * div_d));
	div_m = (tclk / (speed * div_d)) >> div_n;

	twsi_clkctl = ((div_m - 1) << TWSI_CLKCTL_MS) | (div_n << TWSI_CLKCTL_NS);

	twsi_sw.u = 0;
	twsi_sw.s.op = 0x6;
	twsi_sw.s.eop_ia = TWSI_CLKCTL;
	twsi_sw.s.data = twsi_clkctl;

	twsi_write_sw(node, twsi_num, twsi_sw);
}

int twsi_wait(unsigned int node, unsigned int twsi_num)
{
	unsigned int timeout = 500000;

	uint8_t twsi_ctl;

	do {
		twsi_ctl = twsi_read_ctl(node, twsi_num);
		twsi_ctl &= TWSI_CTL_IFLG;
	} while (timeout-- && !twsi_ctl);

	return timeout;
}

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

void thunder_twsi_send(unsigned int node, unsigned int twsi_num,
			uint16_t addr, const uint8_t *buffer, size_t size)
{
	mio_twsx_sw_twsi_t twsi_sw;

	size_t curr = 0;

	twsi_start(node, twsi_num);

	twsi_wait(node, twsi_num);

	twsi_sw.u = 0;
	twsi_sw.s.op = 6;
	twsi_sw.s.eop_ia = TWSI_DATA;
	twsi_sw.s.data = (uint32_t) addr << 1;

	twsi_write_sw(node, twsi_num, twsi_sw);
	twsi_enable(node, twsi_num);

	twsi_wait(node, twsi_num);

	while (curr < size) {
		twsi_sw.u = 0;

		twsi_sw.s.op = 6;
		twsi_sw.s.eop_ia = TWSI_DATA;
		twsi_sw.s.data = buffer[curr++];

		twsi_sw.u = twsi_write_sw(node, twsi_num, twsi_sw);

		twsi_enable(node, twsi_num);
		twsi_wait(node, twsi_num);
	}

	twsi_stop(node, twsi_num);
}
