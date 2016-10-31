/** @file
  Copyright (c) 2016, Linaro, Ltd. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiDxe.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DevicePathLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/NonDiscoverableDeviceRegistrationLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/DevicePath.h>
#include <Protocol/NonDiscoverableDevice.h>

#pragma pack (1)
typedef struct {
  VENDOR_DEVICE_PATH                  Vendor;
  UINT64                              BaseAddress;
  EFI_DEVICE_PATH_PROTOCOL            End;
} NON_DISCOVERABLE_DEVICE_PATH;

#pragma pack ()

/**
  Register a platform device for PCI I/O protocol emulation

  @param[in]      BaseAddress     The MMIO base address of the platform device
  @param[in]      DeviceType      The type of platform device
  @param[in]      DmaType         Whether the device is DMA coherent
  @param[in]      InitFunc        Initialization routine to be invoked when the
                                  device is enabled
  @param[in,out]  Handle          The handle onto which to install the platform
                                  PCI I/O protocol has been installed.
                                  If Handle is NULL or *Handle is NULL, a new
                                  handle will be allocated.

  @retval EFI_SUCCESS             The registration succeeded.
  @retval other                   The registration failed.

**/
EFI_STATUS
EFIAPI
RegisterNonDiscoverableDevice (
  IN      EFI_PHYSICAL_ADDRESS              BaseAddress,
  IN      NON_DISCOVERABLE_DEVICE_TYPE      Type,
  IN      NON_DISCOVERABLE_DEVICE_DMA_TYPE  DmaType,
  IN      NON_DISCOVERABLE_DEVICE_INIT      InitFunc,
  IN OUT  EFI_HANDLE                        *Handle
  )
{
  NON_DISCOVERABLE_DEVICE       *Device;
  NON_DISCOVERABLE_DEVICE_PATH  *DevicePath;
  EFI_HANDLE                    LocalHandle;
  EFI_STATUS                    Status;

  if (Type >= NonDiscoverableDeviceTypeMax ||
      DmaType >= NonDiscoverableDeviceDmaTypeMax) {
    return EFI_INVALID_PARAMETER;
  }

  if (Handle == NULL) {
    Handle = &LocalHandle;
    LocalHandle = NULL;
  }

  Device = (NON_DISCOVERABLE_DEVICE *)AllocateZeroPool (sizeof *Device);
  if (Device == NULL) {
    return EFI_OUT_OF_RESOURCES;
  }

  Device->BaseAddress = BaseAddress;
  Device->Type = Type;
  Device->DmaType = DmaType;
  Device->Initialize = InitFunc;

  DevicePath = (NON_DISCOVERABLE_DEVICE_PATH *)CreateDeviceNode (
                                                 HARDWARE_DEVICE_PATH,
                                                 HW_VENDOR_DP,
                                                 sizeof (*DevicePath));
  if (DevicePath == NULL) {
    Status = EFI_OUT_OF_RESOURCES;
    goto FreeDevice;
  }

  CopyGuid (&DevicePath->Vendor.Guid, &gNonDiscoverableDeviceProtocolGuid);
  DevicePath->BaseAddress = BaseAddress;

  SetDevicePathNodeLength (&DevicePath->Vendor,
    sizeof (*DevicePath) - sizeof (DevicePath->End));
  SetDevicePathEndNode (&DevicePath->End);

  Status = gBS->InstallMultipleProtocolInterfaces (Handle,
                  &gNonDiscoverableDeviceProtocolGuid, Device,
                  &gEfiDevicePathProtocolGuid, DevicePath,
                  NULL);
  if (EFI_ERROR (Status)) {
    goto FreeDevicePath;
  }
  return EFI_SUCCESS;

FreeDevicePath:
  FreePool (DevicePath);

FreeDevice:
  FreePool (Device);

  return Status;
}
