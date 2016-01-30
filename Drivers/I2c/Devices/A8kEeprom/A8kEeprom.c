/********************************************************************************
Copyright (C) 2016 Marvell International Ltd.

Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

	* Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.

	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.

	* Neither the name of Marvell nor the names of its contributors may be
	  used to endorse or promote products derived from this software without
	  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#include <Protocol/DriverBinding.h>
#include <Protocol/I2cIo.h>
#include <Protocol/Eeprom.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Pi/PiI2c.h>

#include "A8kEeprom.h"

/* Last byte of GUID will contain address of device */
#define I2C_GUID \
  { \
  0x391fc679, 0x6cb0, 0x4f01, { 0x9a, 0xc7, 0x8e, 0x1b, 0x78, 0x6b, 0x7a, 0x00 } \
  }

EFI_DRIVER_BINDING_PROTOCOL gDriverBindingProtocol = {
  A8kEepromSupported,
  A8kEepromStart,
  A8kEepromStop
};

EFI_STATUS
EFIAPI
A8kEepromSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  )
{
  EFI_STATUS Status = EFI_UNSUPPORTED;
  EFI_GUID EepromGuid = I2C_GUID;
  EFI_I2C_IO_PROTOCOL *TmpI2cIo;
  UINT8 *EepromAddresses;
  UINTN i;

  Status = gBS->OpenProtocol (
      ControllerHandle,
      &gEfiI2cIoProtocolGuid,
      (VOID **) &TmpI2cIo,
      gImageHandle,
      ControllerHandle,
      EFI_OPEN_PROTOCOL_BY_DRIVER
      );
  if (EFI_ERROR(Status)) {
    return EFI_UNSUPPORTED;
  }

  /* get EEPROM devices' addresses from PCD */
  EepromAddresses = PcdGetPtr (PcdEepromI2cAddresses);
  if (EepromAddresses == 0) {
    Status = EFI_UNSUPPORTED;
    goto out;
  }

  Status = EFI_UNSUPPORTED;
  for (i = 0; EepromAddresses[i] != '\0'; i++) {
    /* last byte of GUID contains address on I2C bus */
    EepromGuid.Data4[7] = EepromAddresses[i];
    if (CompareGuid(TmpI2cIo->DeviceGuid, &EepromGuid)) {
      DEBUG((DEBUG_INFO, "A8kEepromSupported: offered GUID fits desired\n"));
      Status = EFI_SUCCESS;
      break;
    }
  }

out:
  gBS->CloseProtocol (
      ControllerHandle,
      &gEfiI2cIoProtocolGuid,
      gImageHandle,
      ControllerHandle
      );
  return Status;
}

EFI_STATUS
EFIAPI
A8kEepromTransfer (
  IN CONST EFI_EEPROM_PROTOCOL *This,
  IN UINT16			Address,
  IN UINT32			Length,
  IN UINT8			*Buffer,
  IN UINT8			Operation
  )
{
  EFI_I2C_REQUEST_PACKET *RequestPacket;
  UINTN RequestPacketSize;
  EFI_STATUS Status = EFI_SUCCESS;
  EEPROM_CONTEXT *EepromContext = EEPROM_SC_FROM_EEPROM(This);
  UINT32 BufferLength;
  UINT32 Transmitted = 0;
  UINT32 CurrentAddress = Address;

  ASSERT(EepromContext != NULL);
  ASSERT(EepromContext->I2cIo != NULL);

  RequestPacketSize = sizeof(UINTN) + sizeof (EFI_I2C_OPERATION) * 2;
  RequestPacket = AllocateZeroPool (RequestPacketSize);
  if (RequestPacket == NULL)
    return EFI_OUT_OF_RESOURCES;
  RequestPacket->OperationCount = 2;
  RequestPacket->Operation[0].LengthInBytes = 2;
  RequestPacket->Operation[0].Buffer = AllocateZeroPool ( RequestPacket->Operation[0].LengthInBytes );
  if (RequestPacket->Operation[0].Buffer == NULL) {
    FreePool(RequestPacket);
    return EFI_OUT_OF_RESOURCES;
  }
  RequestPacket->Operation[1].Flags = (Operation == EEPROM_READ ? I2C_FLAG_READ : I2C_FLAG_NORESTART);

  while (Length > 0) {
    CurrentAddress = Address + Transmitted;
    BufferLength = (Length <= MAX_BUFFER_LENGTH ? Length : MAX_BUFFER_LENGTH);
    RequestPacket->Operation[0].Buffer[0] = (CurrentAddress >> 8) & 0xff;
    RequestPacket->Operation[0].Buffer[1] = CurrentAddress & 0xff;
    RequestPacket->Operation[1].LengthInBytes = BufferLength;
    RequestPacket->Operation[1].Buffer = Buffer + Transmitted;
    Status = EepromContext->I2cIo->QueueRequest(EepromContext->I2cIo, 0, NULL, RequestPacket, NULL);
    if (EFI_ERROR(Status)) {
      break;
    }
    Length -= BufferLength;
    Transmitted += BufferLength;
  }

  FreePool(RequestPacket->Operation[0].Buffer);
  FreePool(RequestPacket);
  return Status;
}

EFI_STATUS
EFIAPI
A8kEepromStart (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  )
{
  EFI_STATUS Status = EFI_SUCCESS;
  EEPROM_CONTEXT *EepromContext;

  EepromContext = AllocateZeroPool (sizeof(EEPROM_CONTEXT) );
  if (EepromContext == NULL) {
    DEBUG((DEBUG_ERROR, "Allocation fail.\n"));
    return EFI_OUT_OF_RESOURCES;
  }

  EepromContext->ControllerHandle = ControllerHandle;
  EepromContext->Signature = EEPROM_SIGNATURE;
  EepromContext->EepromProtocol.Transfer = A8kEepromTransfer;

  Status = gBS->OpenProtocol (
      ControllerHandle,
      &gEfiI2cIoProtocolGuid,
      (VOID **) &EepromContext->I2cIo,
      gImageHandle,
      ControllerHandle,
      EFI_OPEN_PROTOCOL_BY_DRIVER
      );
  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "A8kEepromStart: failed to open I2cIo!\n"));
    FreePool(EepromContext);
    return EFI_UNSUPPORTED;
  }

  EepromContext->EepromProtocol.Identifier = EepromContext->I2cIo->DeviceIndex;
  Status = gBS->InstallMultipleProtocolInterfaces (
      &ControllerHandle,
      &gEfiEepromProtocolGuid, &EepromContext->EepromProtocol,
      NULL
      );
  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "failed to install eeprom protocol\n"));
    goto fail;
  }

  return Status;

fail:
  FreePool(EepromContext);
  gBS->CloseProtocol (
      ControllerHandle,
      &gEfiI2cIoProtocolGuid,
      gImageHandle,
      ControllerHandle
      );

  return Status;
}

EFI_STATUS
EFIAPI
A8kEepromStop (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN  EFI_HANDLE                            ControllerHandle,
  IN  UINTN                                 NumberOfChildren,
  IN  EFI_HANDLE                            *ChildHandleBuffer OPTIONAL
  )
{
  EFI_EEPROM_PROTOCOL *EepromProtocol;
  EFI_STATUS Status;
  EEPROM_CONTEXT *EepromContext;

  Status = gBS->OpenProtocol (
                  ControllerHandle,
                  &gEfiEepromProtocolGuid,
                  (VOID **) &EepromProtocol,
                  This->DriverBindingHandle,
                  ControllerHandle,
                  EFI_OPEN_PROTOCOL_GET_PROTOCOL
                  );

  if (EFI_ERROR (Status)) {
    return EFI_DEVICE_ERROR;
  }
  EepromContext = EEPROM_SC_FROM_EEPROM(EepromProtocol);

  gBS->UninstallMultipleProtocolInterfaces (
      &ControllerHandle,
      &gEfiEepromProtocolGuid, &EepromContext->EepromProtocol,
      &gEfiDriverBindingProtocolGuid, &gDriverBindingProtocol,
      NULL
      );
  gBS->CloseProtocol (
      ControllerHandle,
      &gEfiI2cIoProtocolGuid,
      gImageHandle,
      ControllerHandle
      );
  FreePool(EepromContext);
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
A8kEepromInitialise (
  IN EFI_HANDLE  ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status;
  Status = gBS->InstallMultipleProtocolInterfaces (
      &ImageHandle,
      &gEfiDriverBindingProtocolGuid, &gDriverBindingProtocol,
      NULL
      );
  return Status;
}
