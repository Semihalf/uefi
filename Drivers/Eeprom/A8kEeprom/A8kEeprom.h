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

#define EEPROM_SIGNATURE          SIGNATURE_32 ('E', 'E', 'P', 'R')

#define MAX_BUFFER_LENGTH 64

typedef struct {
  UINT32  Signature;
  EFI_HANDLE ControllerHandle;
  EFI_I2C_IO_PROTOCOL *I2cIo;
  EFI_EEPROM_PROTOCOL EepromProtocol;
} EEPROM_CONTEXT;

#define EEPROM_SC_FROM_IO(a) CR (a, EEPROM_CONTEXT, I2cIo, EEPROM_SIGNATURE)
#define EEPROM_SC_FROM_EEPROM(a) CR (a, EEPROM_CONTEXT, EepromProtocol, EEPROM_SIGNATURE)

EFI_STATUS
EFIAPI
A8kEepromSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  );

EFI_STATUS
EFIAPI
A8kEepromStart (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  );

EFI_STATUS
EFIAPI
A8kEepromStop (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN  EFI_HANDLE                            ControllerHandle,
  IN  UINTN                                 NumberOfChildren,
  IN  EFI_HANDLE                            *ChildHandleBuffer OPTIONAL
  );

EFI_STATUS
EFIAPI
A8kEepromTransfer (
  IN CONST EFI_EEPROM_PROTOCOL *This,
  IN UINT16			Address,
  IN UINT32			Length,
  IN UINT8			*Buffer,
  IN UINT8			Operation
  );
#endif // __A8K_I2C_H__
