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

#define DEFAULT_SECTOR_SIZE		512
#define DEFAULT_DEVICE_STRING	"/dev/n0.mpi0/cs-l,2wire,idle-h,msb,24bit,12"
#define FATFS_IMAGE_OFFSET		0x280000

/* Definitions of physical drive number for each drive */
#define ATA		0	/* Example: Map ATA harddisk to physical drive 0 */
#define MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define USB		2	/* Example: Map USB MSD to physical drive 2 */


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	BDK_TRACE(FATFS, "%s:%d\n", __FUNCTION__, __LINE__);
	DSTATUS stat = RES_OK;
	return stat;
}



/*-----------------------------------------------------------------------*/
/* Initialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

static FILE *mpi_fp = NULL; /* only one device supported for now */

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	static int mpi_initialized = 0;

	BDK_TRACE(FATFS, "disk_initialize(): drv:%d\n", pdrv);

	if (mpi_fp)
	{
		bdk_warn("FatFs: Drive %d already initialized in disk_initialize(). "
					"Closing it first...\n", pdrv);
		fclose(mpi_fp);
	}

	if (!mpi_initialized)
	{
		/* Initialize mpi_fp for FatFs access */
		extern int bdk_fs_mpi_init(void);
		bdk_fs_mpi_init();
		mpi_initialized++;
	}

	mpi_fp = fopen(DEFAULT_DEVICE_STRING, "r+b");
	if (!mpi_fp)
	{
		bdk_error("FatFs: Could not open device " DEFAULT_DEVICE_STRING
					" for drive %d\n", pdrv);
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
	int num_bytes = count * DEFAULT_SECTOR_SIZE;

	BDK_TRACE(FATFS, "disk_read(): drv:%d - buf:%p - sec:%d - cnt:%d\n", pdrv, buff, sector, count);

	fseek(mpi_fp, sector * DEFAULT_SECTOR_SIZE + FATFS_IMAGE_OFFSET, SEEK_SET);

	total = fread(buff, num_bytes, 1, mpi_fp);
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

	fseek(mpi_fp, sector * DEFAULT_SECTOR_SIZE + FATFS_IMAGE_OFFSET, SEEK_SET);

	total = fwrite(buff, DEFAULT_SECTOR_SIZE * count, 1, mpi_fp);
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
	return RES_OK;
}
#endif
