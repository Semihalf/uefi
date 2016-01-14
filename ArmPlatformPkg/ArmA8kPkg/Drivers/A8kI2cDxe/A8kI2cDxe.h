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

#define IIC_UNKNOWN        0x0
#define IIC_SLOW           0x1
#define IIC_FAST           0x2
#define IIC_FASTEST        0x3

#define TWSI_DEBUG
#undef TWSI_DEBUG

#ifdef  TWSI_DEBUG
#define debugf(fmt, args...) do { printf("%s(): ", __func__); printf(fmt,##args); } while (0)
#else
#define debugf(fmt, args...)
#endif

typedef struct {
  EFI_HANDLE            dev;
  EFI_CPU_IO2_PROTOCOL  *CpuIo;
} A8K_I2C_INSTANCE;

typedef struct {
  UINT32  raw;
  UINTN    param;
  UINTN    m;
  UINTN    n;
} A8K_I2C_BAUD_RATE;

EFI_STATUS
EFIAPI
A8kI2cInitialise (
  IN EFI_HANDLE	ImageHandle,
  IN EFI_SYSTEM_TABLE	*SystemTable
  );

EFI_STATUS
EFIAPI
A8kI2cBindingSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  );

EFI_STATUS
EFIAPI
A8kI2cBindingStart (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  );

EFI_STATUS
EFIAPI
A8kI2cBindingStop (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN  EFI_HANDLE                            ControllerHandle,
  IN  UINTN                                 NumberOfChildren,
  IN  EFI_HANDLE                            *ChildHandleBuffer OPTIONAL
  );

STATIC UINT32
TWSI_READ(
  IN A8K_I2C_INSTANCE *sc,
  IN UINTN off
  );

STATIC
VOID
TWSI_WRITE (
  IN A8K_I2C_INSTANCE *sc,
  IN UINTN off,
  IN UINT32 val
  );

STATIC
VOID
A8kI2cControlClear (
  IN A8K_I2C_INSTANCE *sc,
  IN UINT32 mask
  );

STATIC
VOID
A8kI2cControlSet (
  IN A8K_I2C_INSTANCE *sc,
  IN UINT32 mask
  );

STATIC
VOID
A8kI2cClearIflg (
 IN A8K_I2C_INSTANCE *sc
 );
STATIC
UINTN
A8kI2cPollCtrl (
  IN A8K_I2C_INSTANCE *sc,
  IN UINTN timeout,
  IN UINT32 mask
  );

STATIC
EFI_STATUS
A8kI2cLockedStart (
  IN EFI_HANDLE dev,
  IN A8K_I2C_INSTANCE *sc,
  IN INT32 mask,
  IN UINT8 slave,
  IN UINTN timeout
  );

STATIC
VOID
A8kI2cCalBaudRate (
  IN CONST UINT32 target,
  IN OUT A8K_I2C_BAUD_RATE *rate
  );

EFI_STATUS
EFIAPI
A8kI2cReset (
  IN CONST EFI_I2C_MASTER_PROTOCOL *This
  );

STATIC
EFI_STATUS
A8kI2cRepeatedStart (
  IN EFI_HANDLE dev,
  IN UINT8 slave,
  IN UINTN timeout
  );

STATIC
EFI_STATUS
A8kI2cStart (
  IN EFI_HANDLE dev,
  IN UINT8 slave,
  IN UINTN timeout
  );

STATIC
EFI_STATUS
A8kI2cStop (
  IN EFI_HANDLE dev
  );

STATIC
EFI_STATUS
A8kI2cRead (
  IN EFI_HANDLE dev,
  IN OUT UINT8 *buf,
  IN UINTN len,
  IN OUT UINTN *read,
  IN UINTN last,
  IN UINTN delay
  );

STATIC
EFI_STATUS
A8kI2cWrite (
  IN EFI_HANDLE dev,
  IN OUT CONST UINT8 *buf,
  IN UINTN len,
  IN OUT UINTN *sent,
  IN UINTN timeout
  );

STATIC
EFI_STATUS
A8kI2cStartRequest (
  IN CONST EFI_I2C_MASTER_PROTOCOL *This,
  IN UINTN                         SlaveAddress,
  IN EFI_I2C_REQUEST_PACKET        *RequestPacket,
  IN EFI_EVENT                     Event      OPTIONAL,
  OUT EFI_STATUS                   *I2cStatus OPTIONAL
  );

#endif // __A8K_I2C_H__
