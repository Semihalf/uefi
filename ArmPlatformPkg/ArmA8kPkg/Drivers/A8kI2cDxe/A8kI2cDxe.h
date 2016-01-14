#include <Uefi.h>

#ifndef __A8K_I2C_H__
#define __A8K_I2C_H__

#define MV_TWSI_NAME    "twsi"
#define IICBUS_DEVNAME    "iicbus"

#define TWSI_SLAVE_ADDR    0x00
#define TWSI_EXT_SLAVE_ADDR  0x10
#define TWSI_DATA    0x04

#define TWSI_CONTROL    0x08
#define TWSI_CONTROL_ACK  (1 << 2)
#define TWSI_CONTROL_IFLG  (1 << 3)
#define TWSI_CONTROL_STOP  (1 << 4)
#define TWSI_CONTROL_START  (1 << 5)
#define TWSI_CONTROL_TWSIEN  (1 << 6)
#define TWSI_CONTROL_INTEN  (1 << 7)

#define TWSI_STATUS      0x0c
#define TWSI_STATUS_START    0x08
#define TWSI_STATUS_RPTD_START    0x10
#define TWSI_STATUS_ADDR_W_ACK    0x18
#define TWSI_STATUS_DATA_WR_ACK    0x28
#define TWSI_STATUS_ADDR_R_ACK    0x40
#define TWSI_STATUS_DATA_RD_ACK    0x50
#define TWSI_STATUS_DATA_RD_NOACK  0x58

#define TWSI_BAUD_RATE    0x0c
#define TWSI_BAUD_RATE_PARAM(M,N)  ((((M) << 3) | ((N) & 0x7)) & 0x7f)
#define TWSI_BAUD_RATE_RAW(C,M,N)  ((C)/((10*(M+1))<<(N+1)))
#define TWSI_BAUD_RATE_SLOW    50000  /* 50kHz */
#define TWSI_BAUD_RATE_FAST    100000  /* 100kHz */

#define TWSI_SOFT_RESET    0x1c

#define TWSI_DEBUG
#undef TWSI_DEBUG

#ifdef  TWSI_DEBUG
#define debugf(fmt, args...) do { printf("%s(): ", __func__); printf(fmt,##args); } while (0)
#else
#define debugf(fmt, args...)
#endif

typedef struct {
  EFI_HANDLE            Handle;
  EFI_CPU_IO2_PROTOCOL  *CpuIo;
} A8K_I2C_INSTANCE;

#endif // __A8K_I2C_H__
