/** @file
*
*  Copyright (C) Marvell International Ltd. and its affiliates
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#ifndef __A8K_I2C_H__
#define __A8K_I2C_H__

#include <Uefi.h>

#define MV_TWSI_NAME    "twsi"
#define IICBUS_DEVNAME    "iicbus"

#define TWSI_BASE_ADDRESS	0xf0511000

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
#define TWSI_TRANSFER_TIMEOUT 10000

#define IIC_UNKNOWN        0x0
#define IIC_SLOW           0x1
#define IIC_FAST           0x2
#define IIC_FASTEST        0x3

#define I2C_MASTER_SIGNATURE          SIGNATURE_32 ('I', '2', 'C', 'M')

typedef struct {
  UINT32      Signature;
  EFI_HANDLE  Controller;
  EFI_LOCK    Lock;
  UINTN	      TclkFrequency;
  UINTN	      BaseAddress;
  EFI_I2C_MASTER_PROTOCOL I2cMaster;
  EFI_I2C_ENUMERATE_PROTOCOL I2cEnumerate;
  EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL I2cBusConf;
} I2C_MASTER_CONTEXT;

#define I2C_SC_FROM_MASTER(a) CR (a, I2C_MASTER_CONTEXT, I2cMaster, I2C_MASTER_SIGNATURE)
#define I2C_SC_FROM_ENUMERATE(a) CR (a, I2C_MASTER_CONTEXT, I2cEnumerate, I2C_MASTER_SIGNATURE)
#define I2C_SC_FROM_BUSCONF(a) CR (a, I2C_MASTER_CONTEXT, I2cBusConf, I2C_MASTER_SIGNATURE)

typedef struct {
  UINT32  raw;
  UINTN    param;
  UINTN    m;
  UINTN    n;
} A8K_I2C_BAUD_RATE;

typedef struct {
  VENDOR_DEVICE_PATH            Guid;
  EFI_DEVICE_PATH_PROTOCOL      End;
} A8K_I2C_DEVICE_PATH;

STATIC
UINT32
TWSI_READ(
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINTN off
  );

STATIC
EFI_STATUS
TWSI_WRITE (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINTN off,
  IN UINT32 val
  );

EFI_STATUS
EFIAPI
A8kI2cInitialise (
  IN EFI_HANDLE	ImageHandle,
  IN EFI_SYSTEM_TABLE	*SystemTable
  );

STATIC
VOID
A8kI2cControlClear (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINT32 mask
  );

STATIC
VOID
A8kI2cControlSet (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINT32 mask
  );

STATIC
VOID
A8kI2cClearIflg (
 IN I2C_MASTER_CONTEXT *I2cMasterContext
 );
STATIC
UINTN
A8kI2cPollCtrl (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINTN timeout,
  IN UINT32 mask
  );

STATIC
EFI_STATUS
A8kI2cLockedStart (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN INT32 mask,
  IN UINT8 slave,
  IN UINTN timeout
  );

STATIC
VOID
A8kI2cCalBaudRate (
  IN CONST UINT32 target,
  IN OUT A8K_I2C_BAUD_RATE *rate,
  UINT32 clk
  );

EFI_STATUS
EFIAPI
A8kI2cReset (
  IN CONST EFI_I2C_MASTER_PROTOCOL *This
  );

STATIC
EFI_STATUS
A8kI2cRepeatedStart (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINT8 slave,
  IN UINTN timeout
  );

STATIC
EFI_STATUS
A8kI2cStart (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN UINT8 slave,
  IN UINTN timeout
  );

STATIC
EFI_STATUS
A8kI2cStop (
  IN I2C_MASTER_CONTEXT *I2cMasterContext
  );

STATIC
EFI_STATUS
A8kI2cRead (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN OUT UINT8 *buf,
  IN UINTN len,
  IN OUT UINTN *read,
  IN UINTN last,
  IN UINTN delay
  );

STATIC
EFI_STATUS
A8kI2cWrite (
  IN I2C_MASTER_CONTEXT *I2cMasterContext,
  IN OUT CONST UINT8 *buf,
  IN UINTN len,
  IN OUT UINTN *sent,
  IN UINTN timeout
  );

STATIC
EFI_STATUS
EFIAPI
A8kI2cStartRequest (
  IN CONST EFI_I2C_MASTER_PROTOCOL *This,
  IN UINTN                         SlaveAddress,
  IN EFI_I2C_REQUEST_PACKET        *RequestPacket,
  IN EFI_EVENT                     Event      OPTIONAL,
  OUT EFI_STATUS                   *I2cStatus OPTIONAL
  );

STATIC
EFI_STATUS
EFIAPI
A8kI2cEnumerate (
  IN CONST EFI_I2C_ENUMERATE_PROTOCOL *This,
  IN OUT CONST EFI_I2C_DEVICE         **Device
  );

STATIC
EFI_STATUS
EFIAPI
A8kI2cEnableConf (
  IN CONST EFI_I2C_BUS_CONFIGURATION_MANAGEMENT_PROTOCOL *This,
  IN UINTN                                               I2cBusConfiguration,
  IN EFI_EVENT                                           Event      OPTIONAL,
  IN EFI_STATUS                                          *I2cStatus OPTIONAL
  );

#endif // __A8K_I2C_H__
