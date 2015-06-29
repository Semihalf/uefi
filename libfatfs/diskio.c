/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include <bdk.h>
#include "diskio.h"		/* FatFs lower layer API */


/* Physical drive numbers. Passed into diskio API as pdrv. */
#define DRV_SPI		0
#define DRV_MMC		1

PARTITION VolToPart[] =
{
	/* List of logical drives. Each line is a logical drive, drive numbers are
	 * incremented for each line. Drive numbers can be substituded by drive
	 * strings as defined by _VOLUME_STRS.
	 *
	 * Table entry format is:
	 *   { physical_drive_nr, partition_nr },
	 *
	 * physical_drive_nr:
	 *   Passed into all diskio API functions as pdrv.
	 * partition_nr:
	 *   Logical primary partition number of drive (1-4).
	 *   No extended partitions are supported.
	 */
	{ DRV_SPI, 1 },	/* SPI0 - device 0, partition 1, logical drive 0 */
	{ DRV_MMC, 1 },	/* MMC0 - device 1, partition 1, logical drive 1 */
};


static struct drv_list_d
{
	/* device configuration list */
	const char    *dev_string; /* device string to access raw block data */
	const int     sector_size; /* sector size for the device */
	const DWORD   img_offset;  /* offset of the FAT fs image on the device */

	/* work area for diskio */
	FILE *fp;     /* used internally, initialize as NULL */
	int dev_init; /* used internally, initialize as 0 */
} drv_list[] = {
	{
		/* Default device string for SPI. Will be overwritten if we booted form
		 * SPI.
		 */
		"/dev/n0.mpi0/cs-l,2wire,idle-h,msb,24bit,12",
		512,
		0x00000,
		NULL,
		0
	},
	{
		"/dev/n0.mmc0",
		512,
		0x00000,
		NULL,
		0
	},
};

#define DRV_NUM_DEVICES      (sizeof(drv_list)/sizeof(struct drv_list_d))
#define DRV_DEVSTR(drv)      (drv_list[drv].dev_string)
#define DRV_SECTOR_SIZE(drv) (drv_list[drv].sector_size)
#define DRV_IMG_OFFSET(drv)  (drv_list[drv].img_offset)
#define DRV_FP(drv)          (drv_list[drv].fp)
#define DRV_INIT(drv)        (drv_list[drv].dev_init)

static void fatfs_set_spi_device_name(int boot_method)
{
	char spi_dev[48] = { 0 };

	bdk_node_t node = bdk_numa_local();
	BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
	int chip_select = 0;
	int address_width;
	int active_high = mpi_cfg.s.cshi;
	int idle_mode = (mpi_cfg.s.idleclks) ? 'r' : (mpi_cfg.s.idlelo) ? 'l' : 'h';
	int is_msb = !mpi_cfg.s.lsbfirst;
	int freq_mhz = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / (2 * mpi_cfg.s.clkdiv) / 1000000;

	if (boot_method == RST_BOOT_METHOD_E_SPI24)
		address_width = 24;
	else
		address_width = 32;

	snprintf(spi_dev, sizeof(spi_dev), "/dev/n%d.mpi%d/cs-%c,2wire,idle-%c,%csb,%dbit,%d",
				node,
				chip_select,
				(active_high) ? 'h' : 'l',
				idle_mode,
				(is_msb) ? 'm' : 'l',
				address_width,
				freq_mhz);

	DRV_DEVSTR(DRV_SPI) = strdup(spi_dev); /* Note: this will leak if
											  fatfs_set_spi_device_name is
											  called again. */
}

int fatfs_diskio_init()
{
	FRESULT res = FR_OK;
	bdk_node_t node = bdk_numa_local();

	/* Determine how we booted */
	int boot_method;
	BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
	BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);

	switch (boot_method)
	{
		case RST_BOOT_METHOD_E_CCPI0:
		case RST_BOOT_METHOD_E_CCPI1:
		case RST_BOOT_METHOD_E_CCPI2:
		case RST_BOOT_METHOD_E_PCIE0:
		case RST_BOOT_METHOD_E_REMOTE:
			break;

		case RST_BOOT_METHOD_E_EMMC_LS:
		case RST_BOOT_METHOD_E_EMMC_SS:
			/* Set the default volume to MMC */
			res = f_chvol(DRV_MMC);
			break;

		case RST_BOOT_METHOD_E_SPI24:
		case RST_BOOT_METHOD_E_SPI32:
			/* For the SPI boot method we overwrite the default device name with a name
			 * derived from the SPI controller registers. These registers have been set
			 * by the boot code and are known to work as we just bootet from SPI.
			 */
			fatfs_set_spi_device_name(boot_method);
			res = f_chvol(DRV_SPI);
			break;

		default:
			break;
    }
	return res ? -1 : 0;
}


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;

	BDK_TRACE(FATFS, "%s:%d\n", __FUNCTION__, __LINE__);

	switch(pdrv)
	{
	case DRV_SPI:
		stat = RES_OK;
		break;
	case DRV_MMC:
		stat = RES_OK;
		break;
	default:
		stat = STA_NODISK;
		break;
	}

	return stat;
}



/*-----------------------------------------------------------------------*/
/* Initialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	BDK_TRACE(FATFS, "disk_initialize(): drv:%d\n", pdrv);

	if (pdrv >= DRV_NUM_DEVICES)
		return RES_PARERR;

	if (DRV_FP(pdrv))
	{
		bdk_warn("FatFs: Drive %d device already opened in disk_initialize(). "
					"Closing it first...\n", pdrv);
		fclose(DRV_FP(pdrv));
	}

	switch (pdrv)
	{
	case DRV_SPI:
	case DRV_MMC:
		if (!DRV_INIT(pdrv))
			DRV_INIT(pdrv) = 1;
		break;

	default:
		bdk_error("FatFs: Invalid drive number: %d\n", pdrv);
		return STA_NODISK;
	}


	DRV_FP(pdrv) = fopen(DRV_DEVSTR(pdrv), "r+b");
	if (!DRV_FP(pdrv))
	{
		bdk_error("FatFs: Could not open device %s for drive %d\n",
					DRV_DEVSTR(pdrv), pdrv);
		return RES_NOTRDY;
	}

	return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)
{
	int total;
	int num_bytes;

	BDK_TRACE(FATFS, "disk_read(): drv:%d - buf:%p - sec:%d - cnt:%d\n", pdrv, buff, sector, count);

	if (pdrv >= DRV_NUM_DEVICES)
		return RES_PARERR;

	num_bytes = count * DRV_SECTOR_SIZE(pdrv);
	fseek(DRV_FP(pdrv), sector * DRV_SECTOR_SIZE(pdrv) + DRV_IMG_OFFSET(pdrv), SEEK_SET);

	total = fread(buff, num_bytes, 1, DRV_FP(pdrv));
	if (total != 1)
	{
		bdk_error("FatFs: disk_read() failed: drv:%d - buf:%p - sec:%d - cnt:%d\n",
						pdrv, buff, sector, count);
		return RES_ERROR;
	}

	return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address in LBA */
	UINT count			/* Number of sectors to write */
)
{
	int total;

	BDK_TRACE(FATFS, "disk_write(): drv:%d - buf:%p - sec:%d - cnt:%d\n", pdrv, buff, sector, count);

	if (pdrv >= DRV_NUM_DEVICES)
		return RES_PARERR;

	fseek(DRV_FP(pdrv), sector * DRV_SECTOR_SIZE(pdrv) + DRV_IMG_OFFSET(pdrv), SEEK_SET);

	total = fwrite(buff, DRV_SECTOR_SIZE(pdrv) * count, 1, DRV_FP(pdrv));
	if (1 != count)
	{
		bdk_error("FatFs: disk_write(): failed drv:%d - buf:%p - sec:%d - cnt:%d - total:%d\n",
						pdrv, buff, sector, count, total);
		return RES_ERROR;
	}

	return RES_OK;
}
#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	BDK_TRACE(FATFS, "%s:%d\n", __FUNCTION__, __LINE__);

	if (pdrv >= DRV_NUM_DEVICES)
		return RES_PARERR;

	return RES_OK;
}
#endif
