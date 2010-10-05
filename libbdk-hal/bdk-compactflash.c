#include <bdk.h>

#ifndef MAX
#define	MAX(a,b) (((a)>(b))?(a):(b))
#endif
#define FLASH_RoundUP(_Dividend, _Divisor) (((_Dividend)+(_Divisor-1))/(_Divisor))
/**
 * Convert nanosecond based time to setting used in the
 * boot bus timing register, based on timing multiple
 *
 *
 */
static uint32_t ns_to_tim_reg(int tim_mult, uint32_t nsecs)
{
	uint32_t val;

	/* Compute # of eclock periods to get desired duration in nanoseconds */
	val = FLASH_RoundUP(nsecs * (bdk_clock_get_rate(BDK_CLOCK_SCLK)/1000000), 1000);

	/* Factor in timing multiple, if not 1 */
	if (tim_mult != 1)
		val = FLASH_RoundUP(val, tim_mult);

	return (val);
}

uint64_t bdk_compactflash_generate_dma_tim(int tim_mult, uint16_t *ident_data, int *mwdma_mode_ptr)
{

	bdk_mio_boot_dma_timx_t dma_tim;
	int oe_a;
	int oe_n;
	int dma_acks;
	int dma_ackh;
	int dma_arq;
	int pause;
	int To,Tkr,Td;
	int mwdma_mode = -1;
        uint16_t word53_field_valid;
        uint16_t word63_mwdma;
        uint16_t word163_adv_timing_info;

        if (!ident_data)
            return 0;

        word53_field_valid = ident_data[53];
        word63_mwdma = ident_data[63];
        word163_adv_timing_info = ident_data[163];

	dma_tim.u64 = 0;

	/* Check for basic MWDMA modes */
	if (word53_field_valid & 0x2)
	{
		if (word63_mwdma & 0x4)
			mwdma_mode = 2;
		else if (word63_mwdma & 0x2)
			mwdma_mode = 1;
		else if (word63_mwdma & 0x1)
			mwdma_mode = 0;
	}

	/* Check for advanced MWDMA modes */
	switch ((word163_adv_timing_info >> 3) & 0x7)
	{
		case 1:
			mwdma_mode = 3;
			break;
		case 2:
			mwdma_mode = 4;
			break;
		default:
			break;

	}
	/* DMA is not supported by this card */
	if (mwdma_mode < 0)
            return 0;

	/* Now set up the DMA timing */
	switch (tim_mult)
	{
		case 1:
		    dma_tim.s.tim_mult = 1;
		    break;
		case 2:
		    dma_tim.s.tim_mult = 2;
		    break;
		case 4:
		    dma_tim.s.tim_mult = 0;
		    break;
		case 8:
		    dma_tim.s.tim_mult = 3;
		    break;
		default:
		    bdk_dprintf("ERROR: invalid boot bus dma tim_mult setting\n");
		    break;
	}


	switch (mwdma_mode)
	{
		case 4:
			To = 80;
			Td = 55;
			Tkr = 20;

			oe_a = Td + 20;  // Td (Seem to need more margin here....
			oe_n = MAX(To - oe_a, Tkr);  // Tkr from cf spec, lengthened to meet To

			// oe_n + oe_h must be >= To (cycle time)
			dma_acks = 0; //Ti
			dma_ackh = 5; // Tj

			dma_arq = 8;  // not spec'ed, value in eclocks, not affected by tim_mult
			pause = 25 - dma_arq * 1000/(bdk_clock_get_rate(BDK_CLOCK_SCLK)/1000000); // Tz
			break;
		case 3:
			To = 100;
			Td = 65;
			Tkr = 20;

			oe_a = Td + 20;  // Td (Seem to need more margin here....
			oe_n = MAX(To - oe_a, Tkr);  // Tkr from cf spec, lengthened to meet To

			// oe_n + oe_h must be >= To (cycle time)
			dma_acks = 0; //Ti
			dma_ackh = 5; // Tj

			dma_arq = 8;  // not spec'ed, value in eclocks, not affected by tim_mult
			pause = 25 - dma_arq * 1000/(bdk_clock_get_rate(BDK_CLOCK_SCLK)/1000000); // Tz
			break;
		case 2:
			// +20 works
			// +10 works
			// + 10 + 0 fails
			// n=40, a=80 works
			To = 120;
			Td = 70;
			Tkr = 25;

                        // oe_a 0 fudge doesn't work; 10 seems to
			oe_a = Td + 20 + 10;  // Td (Seem to need more margin here....
			oe_n = MAX(To - oe_a, Tkr) + 10;  // Tkr from cf spec, lengthened to meet To
                        // oe_n 0 fudge fails;;; 10 boots

                        // 20 ns fudge needed on dma_acks
			// oe_n + oe_h must be >= To (cycle time)
			dma_acks = 0 + 20; //Ti
			dma_ackh = 5; // Tj

			dma_arq = 8;  // not spec'ed, value in eclocks, not affected by tim_mult
			pause = 25 - dma_arq * 1000/(bdk_clock_get_rate(BDK_CLOCK_SCLK)/1000000); // Tz
                        // no fudge needed on pause

			break;
		case 1:
		case 0:
		default:
			bdk_dprintf("ERROR: Unsupported DMA mode: %d\n", mwdma_mode);
			return(-1);
			break;
	}

        if (mwdma_mode_ptr)
            *mwdma_mode_ptr = mwdma_mode;

	dma_tim.s.dmack_pi = 1;

	dma_tim.s.oe_n = ns_to_tim_reg(tim_mult, oe_n);
	dma_tim.s.oe_a = ns_to_tim_reg(tim_mult, oe_a);

	dma_tim.s.dmack_s = ns_to_tim_reg(tim_mult, dma_acks);
	dma_tim.s.dmack_h = ns_to_tim_reg(tim_mult, dma_ackh);

	dma_tim.s.dmarq = dma_arq;
	dma_tim.s.pause = ns_to_tim_reg(tim_mult, pause);

	dma_tim.s.rd_dly = 0; /* Sample right on edge */

	/*  writes only */
	dma_tim.s.we_n = ns_to_tim_reg(tim_mult, oe_n);
	dma_tim.s.we_a = ns_to_tim_reg(tim_mult, oe_a);

	return(dma_tim.u64);


}


/**
 * Setup timing and region config to support a specific IDE PIO
 * mode over the bootbus.
 *
 * @param cs0      Bootbus region number connected to CS0 on the IDE device
 * @param cs1      Bootbus region number connected to CS1 on the IDE device
 * @param pio_mode PIO mode to set (0-6)
 */
void bdk_compactflash_set_piomode(int cs0, int cs1, int pio_mode)
{
    bdk_mio_boot_reg_cfgx_t mio_boot_reg_cfg;
    bdk_mio_boot_reg_timx_t mio_boot_reg_tim;
    int cs;
    int clocks_us;                      /* Number of clock cycles per microsec */
    int tim_mult;
    int use_iordy;                      /* Set for PIO0-4, not set for PIO5-6 */
    int t1;                             /* These t names are timing parameters from the ATA spec */
    int t2;
    int t2i;
    int t4;
    int t6;
    int t6z;
    int t9;

    /* PIO modes 0-4 all allow the device to deassert IORDY to slow down
        the host */
    use_iordy = 1;

    /* Use the PIO mode to determine timing parameters */
    switch(pio_mode) {
        case 6:
            /* CF spec say IORDY should be ignore in PIO 5 */
            use_iordy = 0;
            t1 = 10;
            t2 = 55;
            t2i = 20;
            t4 = 5;
            t6 = 5;
            t6z = 20;
            t9 = 10;
            break;
        case 5:
            /* CF spec say IORDY should be ignore in PIO 6 */
            use_iordy = 0;
            t1 = 15;
            t2 = 65;
            t2i = 25;
            t4 = 5;
            t6 = 5;
            t6z = 20;
            t9 = 10;
            break;
        case 4:
            t1 = 25;
            t2 = 70;
            t2i = 25;
            t4 = 10;
            t6 = 5;
            t6z = 30;
            t9 = 10;
            break;
        case 3:
            t1 = 30;
            t2 = 80;
            t2i = 70;
            t4 = 10;
            t6 = 5;
            t6z = 30;
            t9 = 10;
            break;
        case 2:
            t1 = 30;
            t2 = 100;
            t2i = 0;
            t4 = 15;
            t6 = 5;
            t6z = 30;
            t9 = 10;
            break;
        case 1:
            t1 = 50;
            t2 = 125;
            t2i = 0;
            t4 = 20;
            t6 = 5;
            t6z = 30;
            t9 = 15;
            break;
        default:
            t1 = 70;
            t2 = 165;
            t2i = 0;
            t4 = 30;
            t6 = 5;
            t6z = 30;
            t9 = 20;
            break;
    }
    /* Convert times in ns to clock cycles, rounding up */
    clocks_us = FLASH_RoundUP(bdk_clock_get_rate(BDK_CLOCK_SCLK), 1000000);

    /* Convert times in clock cycles, rounding up. Octeon parameters are in
        minus one notation, so take off one after the conversion */
    t1 = FLASH_RoundUP(t1 * clocks_us, 1000);
    if (t1)
        t1--;
    t2 = FLASH_RoundUP(t2 * clocks_us, 1000);
    if (t2)
        t2--;
    t2i = FLASH_RoundUP(t2i * clocks_us, 1000);
    if (t2i)
        t2i--;
    t4 = FLASH_RoundUP(t4 * clocks_us, 1000);
    if (t4)
        t4--;
    t6 = FLASH_RoundUP(t6 * clocks_us, 1000);
    if (t6)
        t6--;
    t6z = FLASH_RoundUP(t6z * clocks_us, 1000);
    if (t6z)
        t6z--;
    t9 = FLASH_RoundUP(t9 * clocks_us, 1000);
    if (t9)
        t9--;

    /* Start using a scale factor of one cycle. Keep doubling it until
        the parameters fit in their fields. Since t2 is the largest number,
        we only need to check it */
    tim_mult = 1;
    while (t2 >= 1<<6)
    {
        t1 = FLASH_RoundUP(t1, 2);
        t2 = FLASH_RoundUP(t2, 2);
        t2i = FLASH_RoundUP(t2i, 2);
        t4 = FLASH_RoundUP(t4, 2);
        t6 = FLASH_RoundUP(t6, 2);
        t6z = FLASH_RoundUP(t6z, 2);
        t9 = FLASH_RoundUP(t9, 2);
        tim_mult *= 2;
    }

    cs = cs0;
    do {
        mio_boot_reg_cfg.u64 = BDK_CSR_READ(BDK_MIO_BOOT_REG_CFGX(cs));
        mio_boot_reg_cfg.s.dmack = 0;   /* Don't assert DMACK on access */
        switch(tim_mult) {
            case 1:
                mio_boot_reg_cfg.s.tim_mult = 1;
                break;
            case 2:
                mio_boot_reg_cfg.s.tim_mult = 2;
                break;
            case 4:
                mio_boot_reg_cfg.s.tim_mult = 0;
                break;
            case 8:
            default:
                mio_boot_reg_cfg.s.tim_mult = 3;
                break;
        }
        mio_boot_reg_cfg.s.rd_dly = 0;  /* Sample on falling edge of BOOT_OE */
        mio_boot_reg_cfg.s.sam = 0;     /* Don't combine write and output enable */
        mio_boot_reg_cfg.s.we_ext = 0;  /* No write enable extension */
        mio_boot_reg_cfg.s.oe_ext = 0;  /* No read enable extension */
        mio_boot_reg_cfg.s.en = 1;      /* Enable this region */
        mio_boot_reg_cfg.s.orbit = 0;   /* Don't combine with previos region */
        mio_boot_reg_cfg.s.width = 1;   /* 16 bits wide */
        BDK_CSR_WRITE(BDK_MIO_BOOT_REG_CFGX(cs), mio_boot_reg_cfg.u64);
        if(cs == cs0)
            cs = cs1;
        else
            cs = cs0;
    } while(cs != cs0);

    mio_boot_reg_tim.u64 = 0;
    mio_boot_reg_tim.s.pagem = 0;       /* Disable page mode */
    mio_boot_reg_tim.s.waitm = use_iordy;    /* Enable dynamic timing */
    mio_boot_reg_tim.s.pages = 0;       /* Pages are disabled */
    mio_boot_reg_tim.s.ale = 8;         /* If someone uses ALE, this seems to work */
    mio_boot_reg_tim.s.page = 0;        /* Not used */
    mio_boot_reg_tim.s.wait = 0;        /* Time after IORDY to coninue to assert the data */
    mio_boot_reg_tim.s.pause = 0;       /* Time after CE that signals stay valid */
    mio_boot_reg_tim.s.wr_hld = t9;     /* How long to hold after a write */
    mio_boot_reg_tim.s.rd_hld = t9;     /* How long to wait after a read for device to tristate */
    mio_boot_reg_tim.s.we = t2;         /* How long write enable is asserted */
    mio_boot_reg_tim.s.oe = t2;         /* How long read enable is asserted */
    mio_boot_reg_tim.s.ce = t1;         /* Time after CE that read/write starts */
    mio_boot_reg_tim.s.adr = 1;         /* Time before CE that address is valid */

    /* Program the bootbus region timing for both chip selects */
    BDK_CSR_WRITE(BDK_MIO_BOOT_REG_TIMX(cs0), mio_boot_reg_tim.u64);
    BDK_CSR_WRITE(BDK_MIO_BOOT_REG_TIMX(cs1), mio_boot_reg_tim.u64);
}
