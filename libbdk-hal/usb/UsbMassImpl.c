/** @file
  USB Mass Storage Driver that manages USB Mass Storage Device and produces Block I/O Protocol.

Copyright (c) 2007 - 2015, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#if defined(notdef_cavium)
#include "UsbMass.h"

#define USB_MASS_TRANSPORT_COUNT    3
//
// Array of USB transport interfaces. 
//
USB_MASS_TRANSPORT *mUsbMassTransport[USB_MASS_TRANSPORT_COUNT] = {
  &mUsbCbi0Transport,
  &mUsbCbi1Transport,
  &mUsbBotTransport,
};

EFI_DRIVER_BINDING_PROTOCOL gUSBMassDriverBinding = {
  USBMassDriverBindingSupported,
  USBMassDriverBindingStart,
  USBMassDriverBindingStop,
  0x11,
  NULL,
  NULL
};
#else
#include <bdk.h>
#include "UsbBus.h"
#include "UsbMass.h"
#include "UsbMassImpl.h"

#define USB_MASS_TRANSPORT_COUNT    1
USB_MASS_TRANSPORT *mUsbMassTransport[USB_MASS_TRANSPORT_COUNT] = {
  &mUsbBotTransport,
};
#endif
/**
  Reset the block device.

  This function implements EFI_BLOCK_IO_PROTOCOL.Reset(). 
  It resets the block device hardware.
  ExtendedVerification is ignored in this implementation.

  @param  This                   Indicates a pointer to the calling context.
  @param  ExtendedVerification   Indicates that the driver may perform a more exhaustive
                                 verification operation of the device during reset.

  @retval EFI_SUCCESS            The block device was reset.
  @retval EFI_DEVICE_ERROR       The block device is not functioning correctly and could not be reset.

**/
EFI_STATUS
EFIAPI
UsbMassReset (
  IN EFI_BLOCK_IO_PROTOCOL    *This,
  IN BOOLEAN                  ExtendedVerification
  )
{
  USB_MASS_DEVICE *UsbMass;
  /* EFI_TPL         OldTpl; */
  EFI_STATUS      Status;

  //
  // Raise TPL to TPL_NOTIFY to serialize all its operations
  // to protect shared data structures.
  //
  /* OldTpl  = gBS->RaiseTPL (TPL_CALLBACK); */

  UsbMass = USB_MASS_DEVICE_FROM_BLOCK_IO (This);
  Status  = UsbMass->Transport->Reset (UsbMass->Context, ExtendedVerification);

  /* gBS->RestoreTPL (OldTpl); */

  return Status;
}

/**
  Reads the requested number of blocks from the device.

  This function implements EFI_BLOCK_IO_PROTOCOL.ReadBlocks(). 
  It reads the requested number of blocks from the device.
  All the blocks are read, or an error is returned.

  @param  This                   Indicates a pointer to the calling context.
  @param  MediaId                The media ID that the read request is for.
  @param  Lba                    The starting logical block address to read from on the device.
  @param  BufferSize             The size of the Buffer in bytes.
                                 This must be a multiple of the intrinsic block size of the device.
  @param  Buffer                 A pointer to the destination buffer for the data. The caller is
                                 responsible for either having implicit or explicit ownership of the buffer.

  @retval EFI_SUCCESS            The data was read correctly from the device.
  @retval EFI_DEVICE_ERROR       The device reported an error while attempting to perform the read operation.
  @retval EFI_NO_MEDIA           There is no media in the device.
  @retval EFI_MEDIA_CHANGED      The MediaId is not for the current media.
  @retval EFI_BAD_BUFFER_SIZE    The BufferSize parameter is not a multiple of the intrinsic block size of the device.
  @retval EFI_INVALID_PARAMETER  The read request contains LBAs that are not valid,
                                 or the buffer is not on proper alignment.

**/
EFI_STATUS
EFIAPI
UsbMassReadBlocks (
  IN EFI_BLOCK_IO_PROTOCOL    *This,
  IN UINT32                   MediaId,
  IN EFI_LBA                  Lba,
  IN UINTN                    BufferSize,
  OUT VOID                    *Buffer
  )
{
  USB_MASS_DEVICE     *UsbMass;
  EFI_BLOCK_IO_MEDIA  *Media;
  EFI_STATUS          Status;
  /* EFI_TPL             OldTpl; */
  UINTN               TotalBlock;

  //
  // Raise TPL to TPL_NOTIFY to serialize all its operations
  // to protect shared data structures.
  //
  /* OldTpl  = gBS->RaiseTPL (TPL_CALLBACK); */
  UsbMass = USB_MASS_DEVICE_FROM_BLOCK_IO (This);
  Media   = &UsbMass->BlockIoMedia;

  //
  // If it is a removable media, such as CD-Rom or Usb-Floppy,
  // need to detect the media before each read/write. While some of
  // Usb-Flash is marked as removable media.
  //
  if (Media->RemovableMedia) {
    Status = UsbBootDetectMedia (UsbMass);
    if (EFI_ERROR (Status)) {
      goto ON_EXIT;
    }
  }

  if (!(Media->MediaPresent)) {
    Status = EFI_NO_MEDIA;
    goto ON_EXIT;
  }

  if (MediaId != Media->MediaId) {
    Status = EFI_MEDIA_CHANGED;
    goto ON_EXIT;
  }

  if (BufferSize == 0) {
    Status = EFI_SUCCESS;
    goto ON_EXIT;
  }

  if (Buffer == NULL) {
    Status = EFI_INVALID_PARAMETER;
    goto ON_EXIT;
  }

  //
  // BufferSize must be a multiple of the intrinsic block size of the device.
  //
  if ((BufferSize % Media->BlockSize) != 0) {
    Status = EFI_BAD_BUFFER_SIZE;
    goto ON_EXIT;
  }

  TotalBlock = BufferSize / Media->BlockSize;

  //
  // Make sure the range to read is valid.
  //
  if (Lba + TotalBlock - 1 > Media->LastBlock) {
    Status = EFI_INVALID_PARAMETER;
    goto ON_EXIT;
  }

  if (UsbMass->Cdb16Byte) {
    Status = UsbBootReadBlocks16 (UsbMass, Lba, TotalBlock, Buffer);
  } else {
    Status = UsbBootReadBlocks (UsbMass, (UINT32) Lba, TotalBlock, Buffer);
  }

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbMassReadBlocks: UsbBootReadBlocks (%d) -> Reset\n", (int) Status));
    UsbMassReset (This, TRUE);
  }

ON_EXIT:
  /* gBS->RestoreTPL (OldTpl); */
  return Status;
}


/**
  Writes a specified number of blocks to the device.

  This function implements EFI_BLOCK_IO_PROTOCOL.WriteBlocks(). 
  It writes a specified number of blocks to the device.
  All blocks are written, or an error is returned.

  @param  This                   Indicates a pointer to the calling context.
  @param  MediaId                The media ID that the write request is for.
  @param  Lba                    The starting logical block address to be written.
  @param  BufferSize             The size of the Buffer in bytes.
                                 This must be a multiple of the intrinsic block size of the device.
  @param  Buffer                 Pointer to the source buffer for the data.

  @retval EFI_SUCCESS            The data were written correctly to the device.
  @retval EFI_WRITE_PROTECTED    The device cannot be written to.
  @retval EFI_NO_MEDIA           There is no media in the device.
  @retval EFI_MEDIA_CHANGED      The MediaId is not for the current media.
  @retval EFI_DEVICE_ERROR       The device reported an error while attempting to perform the write operation.
  @retval EFI_BAD_BUFFER_SIZE    The BufferSize parameter is not a multiple of the intrinsic
                                 block size of the device.
  @retval EFI_INVALID_PARAMETER  The write request contains LBAs that are not valid,
                                 or the buffer is not on proper alignment.

**/
EFI_STATUS
EFIAPI
UsbMassWriteBlocks (
  IN EFI_BLOCK_IO_PROTOCOL    *This,
  IN UINT32                   MediaId,
  IN EFI_LBA                  Lba,
  IN UINTN                    BufferSize,
  IN VOID                     *Buffer
  )
{
  USB_MASS_DEVICE     *UsbMass;
  EFI_BLOCK_IO_MEDIA  *Media;
  EFI_STATUS          Status;
  /* EFI_TPL             OldTpl; */
  UINTN               TotalBlock;

  //
  // Raise TPL to TPL_NOTIFY to serialize all its operations
  // to protect shared data structures.
  //
  /* OldTpl  = gBS->RaiseTPL (TPL_CALLBACK); */
  UsbMass = USB_MASS_DEVICE_FROM_BLOCK_IO (This);
  Media   = &UsbMass->BlockIoMedia;

  //
  // If it is a removable media, such as CD-Rom or Usb-Floppy,
  // need to detect the media before each read/write. Some of
  // USB Flash is marked as removable media.
  //
  if (Media->RemovableMedia) {
    Status = UsbBootDetectMedia (UsbMass);
    if (EFI_ERROR (Status)) {
      goto ON_EXIT;
    }
  }

  if (!(Media->MediaPresent)) {
    Status = EFI_NO_MEDIA;
    goto ON_EXIT;
  }

  if (MediaId != Media->MediaId) {
    Status = EFI_MEDIA_CHANGED;
    goto ON_EXIT;
  }

  if (BufferSize == 0) {
    Status = EFI_SUCCESS;
    goto ON_EXIT;
  }

  if (Buffer == NULL) {
    Status = EFI_INVALID_PARAMETER;
    goto ON_EXIT;
  }

  //
  // BufferSize must be a multiple of the intrinsic block size of the device.
  //
  if ((BufferSize % Media->BlockSize) != 0) {
    Status = EFI_BAD_BUFFER_SIZE;
    goto ON_EXIT;
  }

  TotalBlock = BufferSize / Media->BlockSize;

  //
  // Make sure the range to write is valid.
  //
  if (Lba + TotalBlock - 1 > Media->LastBlock) {
    Status = EFI_INVALID_PARAMETER;
    goto ON_EXIT;
  }

  //
  // Try to write the data even the device is marked as ReadOnly,
  // and clear the status should the write succeed.
  //
  if (UsbMass->Cdb16Byte) {
    Status = UsbBootWriteBlocks16 (UsbMass, Lba, TotalBlock, Buffer);
  } else {
    Status = UsbBootWriteBlocks (UsbMass, (UINT32) Lba, TotalBlock, Buffer);
  }  

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbMassWriteBlocks: UsbBootWriteBlocks (%d) -> Reset\n", (int) Status));
    UsbMassReset (This, TRUE);
  }

ON_EXIT:
  /* gBS->RestoreTPL (OldTpl); */
  return Status;
}

/**
  Flushes all modified data to a physical block device.

  This function implements EFI_BLOCK_IO_PROTOCOL.FlushBlocks().
  USB mass storage device doesn't support write cache,
  so return EFI_SUCCESS directly.

  @param  This                   Indicates a pointer to the calling context.

  @retval EFI_SUCCESS            All outstanding data were written correctly to the device.
  @retval EFI_DEVICE_ERROR       The device reported an error while attempting to write data.
  @retval EFI_NO_MEDIA           There is no media in the device.

**/
EFI_STATUS
EFIAPI
UsbMassFlushBlocks (
  IN EFI_BLOCK_IO_PROTOCOL  *This
  )
{
  return EFI_SUCCESS;
}

/**
  Initialize the media parameter data for EFI_BLOCK_IO_MEDIA of Block I/O Protocol.

  @param  UsbMass                The USB mass storage device

  @retval EFI_SUCCESS            The media parameters are updated successfully.
  @retval Others                 Failed to get the media parameters.

**/
static EFI_STATUS
UsbMassInitMedia (
  IN USB_MASS_DEVICE          *UsbMass
  )
{
  EFI_BLOCK_IO_MEDIA          *Media;
  EFI_STATUS                  Status;

  Media = &UsbMass->BlockIoMedia;

  //
  // Fields of EFI_BLOCK_IO_MEDIA are defined in UEFI 2.0 spec,
  // section for Block I/O Protocol.
  //
  Media->MediaPresent     = FALSE;
  Media->LogicalPartition = FALSE;
  Media->ReadOnly         = FALSE;
  Media->WriteCaching     = FALSE;
  Media->IoAlign          = 0;
  Media->MediaId          = 1;

  Status = UsbBootGetParams (UsbMass);
  return Status;
}
#if defined(notdef_cavium)
/**
  Initilize the USB Mass Storage transport.

  This function tries to find the matching USB Mass Storage transport
  protocol for USB device. If found, initializes the matching transport.

  @param  This            The USB mass driver's driver binding.
  @param  Controller      The device to test.
  @param  Transport       The pointer to pointer to USB_MASS_TRANSPORT.
  @param  Context         The parameter for USB_MASS_DEVICE.Context.
  @param  MaxLun          Get the MaxLun if is BOT dev.

  @retval EFI_SUCCESS     The initialization is successful.
  @retval EFI_UNSUPPORTED No matching transport protocol is found.
  @retval Others          Failed to initialize dev.

**/
EFI_STATUS
UsbMassInitTransport (
  IN  EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN  EFI_HANDLE                   Controller,
  OUT USB_MASS_TRANSPORT           **Transport,
  OUT VOID                         **Context,
  OUT UINT8                        *MaxLun
  )
{
  EFI_USB_IO_PROTOCOL           *UsbIo;
  EFI_USB_INTERFACE_DESCRIPTOR  Interface;
  UINT8                         Index;
  EFI_STATUS                    Status;
 
  Status = gBS->OpenProtocol (
                  Controller,
                  &gEfiUsbIoProtocolGuid,
                  (VOID **) &UsbIo,
                  This->DriverBindingHandle,
                  Controller,
                  EFI_OPEN_PROTOCOL_BY_DRIVER
                  );

  if (EFI_ERROR (Status)) {
    return Status;
  }
  
  Status = UsbIo->UsbGetInterfaceDescriptor (UsbIo, &Interface);
  if (EFI_ERROR (Status)) {
    goto ON_EXIT;
  }
  
  Status = EFI_UNSUPPORTED;

  //
  // Traverse the USB_MASS_TRANSPORT arrary and try to find the
  // matching transport protocol.
  // If not found, return EFI_UNSUPPORTED.
  // If found, execute USB_MASS_TRANSPORT.Init() to initialize the transport context.
  //
  for (Index = 0; Index < USB_MASS_TRANSPORT_COUNT; Index++) {
    *Transport = mUsbMassTransport[Index];

    if (Interface.InterfaceProtocol == (*Transport)->Protocol) {
      Status  = (*Transport)->Init (UsbIo, Context);
      break;
    }
  }

  if (EFI_ERROR (Status)) {
    goto ON_EXIT;
  }

  //
  // For BOT device, try to get its max LUN. 
  // If max LUN is 0, then it is a non-lun device.
  // Otherwise, it is a multi-lun device.
  //
  if ((*Transport)->Protocol == USB_MASS_STORE_BOT) {
    (*Transport)->GetMaxLun (*Context, MaxLun);
  }

ON_EXIT:
  gBS->CloseProtocol (
         Controller,
         &gEfiUsbIoProtocolGuid,
         This->DriverBindingHandle,
         Controller
         );
  return Status;  
}

/**
  Initialize data for device that supports multiple LUNSs.

  @param  This                 The Driver Binding Protocol instance.
  @param  Controller           The device to initialize.
  @param  Transport            Pointer to USB_MASS_TRANSPORT.
  @param  Context              Parameter for USB_MASS_DEVICE.Context.
  @param  DevicePath           The remaining device path.
  @param  MaxLun               The max LUN number.

  @retval EFI_SUCCESS          At least one LUN is initialized successfully.
  @retval EFI_NOT_FOUND        Fail to initialize any of multiple LUNs.

**/
EFI_STATUS
UsbMassInitMultiLun (
  IN EFI_DRIVER_BINDING_PROTOCOL   *This,
  IN EFI_HANDLE                    Controller,
  IN USB_MASS_TRANSPORT            *Transport,
  IN VOID                          *Context,
  IN EFI_DEVICE_PATH_PROTOCOL      *DevicePath,
  IN UINT8                         MaxLun
  )
{
  USB_MASS_DEVICE                  *UsbMass;
  EFI_USB_IO_PROTOCOL              *UsbIo;
  DEVICE_LOGICAL_UNIT_DEVICE_PATH  LunNode;
  UINT8                            Index;
  EFI_STATUS                       Status;
  EFI_STATUS                       ReturnStatus;

  ASSERT (MaxLun > 0);
  ReturnStatus = EFI_NOT_FOUND;

  for (Index = 0; Index <= MaxLun; Index++) { 

    DEBUG ((EFI_D_INFO, "UsbMassInitMultiLun: Start to initialize No.%d logic unit\n", Index));
    
    UsbIo   = NULL;
    UsbMass = AllocateZeroPool (sizeof (USB_MASS_DEVICE));
    ASSERT (UsbMass != NULL);
      
    UsbMass->Signature            = USB_MASS_SIGNATURE;
    UsbMass->UsbIo                = UsbIo;
    UsbMass->BlockIo.Media        = &UsbMass->BlockIoMedia;
    UsbMass->BlockIo.Reset        = UsbMassReset;
    UsbMass->BlockIo.ReadBlocks   = UsbMassReadBlocks;
    UsbMass->BlockIo.WriteBlocks  = UsbMassWriteBlocks;
    UsbMass->BlockIo.FlushBlocks  = UsbMassFlushBlocks;
    UsbMass->OpticalStorage       = FALSE;
    UsbMass->Transport            = Transport;
    UsbMass->Context              = Context;
    UsbMass->Lun                  = Index;
    
    //
    // Initialize the media parameter data for EFI_BLOCK_IO_MEDIA of Block I/O Protocol.
    //
    Status = UsbMassInitMedia (UsbMass);
    if ((EFI_ERROR (Status)) && (Status != EFI_NO_MEDIA)) {
      DEBUG ((EFI_D_ERROR, "UsbMassInitMultiLun: UsbMassInitMedia (%d)\n", (int) Status));
      FreePool (UsbMass);
      continue;
    }

    //
    // Create a device path node for device logic unit, and append it.
    //
    LunNode.Header.Type    = MESSAGING_DEVICE_PATH;
    LunNode.Header.SubType = MSG_DEVICE_LOGICAL_UNIT_DP;
    LunNode.Lun            = UsbMass->Lun;
  
    SetDevicePathNodeLength (&LunNode.Header, sizeof (LunNode));
  
    UsbMass->DevicePath = AppendDevicePathNode (DevicePath, &LunNode.Header);
  
    if (UsbMass->DevicePath == NULL) {
      DEBUG ((EFI_D_ERROR, "UsbMassInitMultiLun: failed to create device logic unit device path\n"));
      Status = EFI_OUT_OF_RESOURCES;
      FreePool (UsbMass);
      continue;
    }

    InitializeDiskInfo (UsbMass);

    //
    // Create a new handle for each LUN, and install Block I/O Protocol and Device Path Protocol.
    //
    Status = gBS->InstallMultipleProtocolInterfaces (
                    &UsbMass->Controller,
                    &gEfiDevicePathProtocolGuid,
                    UsbMass->DevicePath,
                    &gEfiBlockIoProtocolGuid,
                    &UsbMass->BlockIo,
                    &gEfiDiskInfoProtocolGuid,
                    &UsbMass->DiskInfo,
                    NULL
                    );
    
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "UsbMassInitMultiLun: InstallMultipleProtocolInterfaces (%d)\n", (int) Status));
      FreePool (UsbMass->DevicePath);
      FreePool (UsbMass);
      continue;
    }

    //
    // Open USB I/O Protocol by child to setup a parent-child relationship.
    //
    Status = gBS->OpenProtocol (
                    Controller,
                    &gEfiUsbIoProtocolGuid,
                    (VOID **) &UsbIo,
                    This->DriverBindingHandle,
                    UsbMass->Controller,
                    EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER
                    );

    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "UsbMassInitMultiLun: OpenUsbIoProtocol By Child (%d)\n", (int) Status));
      gBS->UninstallMultipleProtocolInterfaces (
             &UsbMass->Controller,
             &gEfiDevicePathProtocolGuid,
             UsbMass->DevicePath,
             &gEfiBlockIoProtocolGuid,
             &UsbMass->BlockIo,
             &gEfiDiskInfoProtocolGuid,
             &UsbMass->DiskInfo,
             NULL
             );
      FreePool (UsbMass->DevicePath);
      FreePool (UsbMass);
      continue;
    }
    ReturnStatus = EFI_SUCCESS;
    DEBUG ((EFI_D_INFO, "UsbMassInitMultiLun: Success to initialize No.%d logic unit\n", Index));
  }
  
  return ReturnStatus;
}

/**
  Initialize data for device that does not support multiple LUNSs.

  @param  This            The Driver Binding Protocol instance.
  @param  Controller      The device to initialize.
  @param  Transport       Pointer to USB_MASS_TRANSPORT.
  @param  Context         Parameter for USB_MASS_DEVICE.Context.

  @retval EFI_SUCCESS     Initialization succeeds.
  @retval Other           Initialization fails.

**/
EFI_STATUS
UsbMassInitNonLun (
  IN EFI_DRIVER_BINDING_PROTOCOL   *This,
  IN EFI_HANDLE                    Controller,
  IN USB_MASS_TRANSPORT            *Transport,
  IN VOID                          *Context
  )
{
  USB_MASS_DEVICE             *UsbMass;
  EFI_USB_IO_PROTOCOL         *UsbIo;
  EFI_STATUS                  Status;

  UsbIo   = NULL;
  UsbMass = AllocateZeroPool (sizeof (USB_MASS_DEVICE));
  ASSERT (UsbMass != NULL);

  Status = gBS->OpenProtocol (
                  Controller,
                  &gEfiUsbIoProtocolGuid,
                  (VOID **) &UsbIo,
                  This->DriverBindingHandle,
                  Controller,
                  EFI_OPEN_PROTOCOL_BY_DRIVER
                  );

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbMassInitNonLun: OpenUsbIoProtocol By Driver (%d)\n", (int) Status));
    goto ON_ERROR;
  }
  
  UsbMass->Signature            = USB_MASS_SIGNATURE;
  UsbMass->Controller           = Controller;
  UsbMass->UsbIo                = UsbIo;
  UsbMass->BlockIo.Media        = &UsbMass->BlockIoMedia;
  UsbMass->BlockIo.Reset        = UsbMassReset;
  UsbMass->BlockIo.ReadBlocks   = UsbMassReadBlocks;
  UsbMass->BlockIo.WriteBlocks  = UsbMassWriteBlocks;
  UsbMass->BlockIo.FlushBlocks  = UsbMassFlushBlocks;
  UsbMass->OpticalStorage       = FALSE;
  UsbMass->Transport            = Transport;
  UsbMass->Context              = Context;
  
  //
  // Initialize the media parameter data for EFI_BLOCK_IO_MEDIA of Block I/O Protocol.
  //
  Status = UsbMassInitMedia (UsbMass);
  if ((EFI_ERROR (Status)) && (Status != EFI_NO_MEDIA)) {
    DEBUG ((EFI_D_ERROR, "UsbMassInitNonLun: UsbMassInitMedia (%d)\n", (int) Status));
    goto ON_ERROR;
  }
    
  InitializeDiskInfo (UsbMass);

  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Controller,
                  &gEfiBlockIoProtocolGuid,
                  &UsbMass->BlockIo,
                  &gEfiDiskInfoProtocolGuid,
                  &UsbMass->DiskInfo,
                  NULL
                  );
  if (EFI_ERROR (Status)) {
    goto ON_ERROR;
  }

  return EFI_SUCCESS;

ON_ERROR:
  if (UsbMass != NULL) {
    FreePool (UsbMass);
  }
  if (UsbIo != NULL) {
    gBS->CloseProtocol (
           Controller,
           &gEfiUsbIoProtocolGuid,
           This->DriverBindingHandle,
           Controller
           );
  }
  return Status;  
}

/**
  Check whether the controller is a supported USB mass storage.

  @param  This                   The USB mass storage driver binding protocol.
  @param  Controller             The controller handle to check.
  @param  RemainingDevicePath    The remaining device path.

  @retval EFI_SUCCESS            The driver supports this controller.
  @retval other                  This device isn't supported.

**/
EFI_STATUS
EFIAPI
USBMassDriverBindingSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN EFI_HANDLE                   Controller,
  IN EFI_DEVICE_PATH_PROTOCOL     *RemainingDevicePath
  )
{
  EFI_USB_IO_PROTOCOL           *UsbIo;
  EFI_USB_INTERFACE_DESCRIPTOR  Interface;
  USB_MASS_TRANSPORT            *Transport;
  EFI_STATUS                    Status;
  UINTN                         Index;

  Status = gBS->OpenProtocol (
                  Controller,
                  &gEfiUsbIoProtocolGuid,
                  (VOID **) &UsbIo,
                  This->DriverBindingHandle,
                  Controller,
                  EFI_OPEN_PROTOCOL_BY_DRIVER
                  );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  //
  // Get the interface descriptor to check the USB class and find a transport
  // protocol handler.
  //
  Status = UsbIo->UsbGetInterfaceDescriptor (UsbIo, &Interface);
  if (EFI_ERROR (Status)) {
    goto ON_EXIT;
  }

  Status = EFI_UNSUPPORTED;

  if (Interface.InterfaceClass != USB_MASS_STORE_CLASS) {
    goto ON_EXIT;
  }

  //
  // Traverse the USB_MASS_TRANSPORT arrary and try to find the
  // matching transport method.
  // If not found, return EFI_UNSUPPORTED.
  // If found, execute USB_MASS_TRANSPORT.Init() to initialize the transport context.
  //
  for (Index = 0; Index < USB_MASS_TRANSPORT_COUNT; Index++) {
    Transport = mUsbMassTransport[Index];
    if (Interface.InterfaceProtocol == Transport->Protocol) {
      Status = Transport->Init (UsbIo, NULL);
      break;
    }
  }

ON_EXIT:
  gBS->CloseProtocol (
         Controller,
         &gEfiUsbIoProtocolGuid,
         This->DriverBindingHandle,
         Controller
         );

  return Status;
}

/**
  Starts the USB mass storage device with this driver.

  This function consumes USB I/O Portocol, intializes USB mass storage device,
  installs Block I/O Protocol, and submits Asynchronous Interrupt
  Transfer to manage the USB mass storage device.

  @param  This                  The USB mass storage driver binding protocol.
  @param  Controller            The USB mass storage device to start on
  @param  RemainingDevicePath   The remaining device path.

  @retval EFI_SUCCESS           This driver supports this device.
  @retval EFI_UNSUPPORTED       This driver does not support this device.
  @retval EFI_DEVICE_ERROR      This driver cannot be started due to device Error.
  @retval EFI_OUT_OF_RESOURCES  Can't allocate memory resources.
  @retval EFI_ALREADY_STARTED   This driver has been started.

**/
EFI_STATUS
EFIAPI
USBMassDriverBindingStart (
  IN EFI_DRIVER_BINDING_PROTOCOL  *This,
  IN EFI_HANDLE                   Controller,
  IN EFI_DEVICE_PATH_PROTOCOL     *RemainingDevicePath
  )
{
  USB_MASS_TRANSPORT            *Transport;
  EFI_DEVICE_PATH_PROTOCOL      *DevicePath;
  VOID                          *Context;
  UINT8                         MaxLun;
  EFI_STATUS                    Status;
  EFI_USB_IO_PROTOCOL           *UsbIo; 
  EFI_TPL                       OldTpl;

  OldTpl = gBS->RaiseTPL (TPL_CALLBACK);

  Transport = NULL;
  Context   = NULL;
  MaxLun    = 0;

  Status = UsbMassInitTransport (This, Controller, &Transport, &Context, &MaxLun);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "USBMassDriverBindingStart: UsbMassInitTransport (%d)\n", (int) Status));
    goto Exit;
  }
  if (MaxLun == 0) {
    //
    // Initialize data for device that does not support multiple LUNSs.
    //
    Status = UsbMassInitNonLun (This, Controller, Transport, Context);
    if (EFI_ERROR (Status)) { 
      DEBUG ((EFI_D_ERROR, "USBMassDriverBindingStart: UsbMassInitNonLun (%d)\n", (int) Status));
    }
  } else {
    //
    // Open device path to prepare for appending Device Logic Unit node.
    //
    Status = gBS->OpenProtocol (
                    Controller,
                    &gEfiDevicePathProtocolGuid,
                    (VOID **) &DevicePath,
                    This->DriverBindingHandle,
                    Controller,
                    EFI_OPEN_PROTOCOL_BY_DRIVER
                    );
  
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "USBMassDriverBindingStart: OpenDevicePathProtocol By Driver (%d)\n", (int) Status));
      goto Exit;
    }

    Status = gBS->OpenProtocol (
                    Controller,
                    &gEfiUsbIoProtocolGuid,
                    (VOID **) &UsbIo,
                    This->DriverBindingHandle,
                    Controller,
                    EFI_OPEN_PROTOCOL_BY_DRIVER
                    );
  
    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "USBMassDriverBindingStart: OpenUsbIoProtocol By Driver (%d)\n", (int) Status));
      gBS->CloseProtocol (
             Controller,
             &gEfiDevicePathProtocolGuid,
             This->DriverBindingHandle,
             Controller
             );
      goto Exit;
    }

    //
    // Initialize data for device that supports multiple LUNs.
    // EFI_SUCCESS is returned if at least 1 LUN is initialized successfully.
    //
    Status = UsbMassInitMultiLun (This, Controller, Transport, Context, DevicePath, MaxLun);
    if (EFI_ERROR (Status)) {
      gBS->CloseProtocol (
              Controller,
              &gEfiDevicePathProtocolGuid,
              This->DriverBindingHandle,
              Controller
              );
      gBS->CloseProtocol (
              Controller,
              &gEfiUsbIoProtocolGuid,
              This->DriverBindingHandle,
              Controller
              );
      DEBUG ((EFI_D_ERROR, "USBMassDriverBindingStart: UsbMassInitMultiLun (%d) with Maxlun=%d\n", Status, MaxLun));
    }
  }
Exit:
  gBS->RestoreTPL (OldTpl);
  return Status;
}


/**
  Stop controlling the device.

  @param  This                   The USB mass storage driver binding
  @param  Controller             The device controller controlled by the driver.
  @param  NumberOfChildren       The number of children of this device
  @param  ChildHandleBuffer      The buffer of children handle.

  @retval EFI_SUCCESS            The driver stopped from controlling the device.
  @retval EFI_DEVICE_ERROR       The device could not be stopped due to a device error.
  @retval EFI_UNSUPPORTED        Block I/O Protocol is not installed on Controller.
  @retval Others                 Failed to stop the driver

**/
EFI_STATUS
EFIAPI
USBMassDriverBindingStop (
  IN  EFI_DRIVER_BINDING_PROTOCOL *This,
  IN  EFI_HANDLE                  Controller,
  IN  UINTN                       NumberOfChildren,
  IN  EFI_HANDLE                  *ChildHandleBuffer
  )
{
  EFI_STATUS            Status;
  USB_MASS_DEVICE       *UsbMass;
  EFI_USB_IO_PROTOCOL   *UsbIo;
  EFI_BLOCK_IO_PROTOCOL *BlockIo;
  UINTN                 Index;
  BOOLEAN               AllChildrenStopped;

  //
  // This is a bus driver stop function since multi-lun is supported.
  // There are three kinds of device handles that might be passed:
  // 1st is a handle with USB I/O & Block I/O installed (non-multi-lun)
  // 2nd is a handle with Device Path & USB I/O installed (multi-lun root)
  // 3rd is a handle with Device Path & USB I/O & Block I/O installed (multi-lun).
  //
  if (NumberOfChildren == 0) {
    //
    // A handle without any children, might be 1st and 2nd type.
    //
    Status = gBS->OpenProtocol (
                    Controller,
                    &gEfiBlockIoProtocolGuid,
                    (VOID **) &BlockIo,
                    This->DriverBindingHandle,
                    Controller,
                    EFI_OPEN_PROTOCOL_GET_PROTOCOL
                    );
  
    if (EFI_ERROR(Status)) {
      //
      // This is a 2nd type handle(multi-lun root), it needs to close devicepath
      // and usbio protocol.
      //
      gBS->CloseProtocol (
            Controller,
            &gEfiDevicePathProtocolGuid,
            This->DriverBindingHandle,
            Controller
            );
      gBS->CloseProtocol (
            Controller,
            &gEfiUsbIoProtocolGuid,
            This->DriverBindingHandle,
            Controller
            );
      DEBUG ((EFI_D_INFO, "Success to stop multi-lun root handle\n"));
      return EFI_SUCCESS;
    }
    
    //
    // This is a 1st type handle(non-multi-lun), which only needs to uninstall
    // Block I/O Protocol, close USB I/O Protocol and free mass device.
    //
    UsbMass = USB_MASS_DEVICE_FROM_BLOCK_IO (BlockIo);
  
    //
    // Uninstall Block I/O protocol from the device handle,
    // then call the transport protocol to stop itself.
    //
    Status = gBS->UninstallMultipleProtocolInterfaces (
                    Controller,
                    &gEfiBlockIoProtocolGuid,
                    &UsbMass->BlockIo,
                    &gEfiDiskInfoProtocolGuid,
                    &UsbMass->DiskInfo,
                    NULL
                    );
    if (EFI_ERROR (Status)) {
      return Status;
    }
  
    gBS->CloseProtocol (
          Controller,
          &gEfiUsbIoProtocolGuid,
          This->DriverBindingHandle,
          Controller
          );
  
    UsbMass->Transport->CleanUp (UsbMass->Context);
    FreePool (UsbMass);
    
    DEBUG ((EFI_D_INFO, "Success to stop non-multi-lun root handle\n"));
    return EFI_SUCCESS;
  } 

  //
  // This is a 3rd type handle(multi-lun), which needs uninstall
  // Block I/O Protocol and Device Path Protocol, close USB I/O Protocol and 
  // free mass device for all children.
  //
  AllChildrenStopped = TRUE;

  for (Index = 0; Index < NumberOfChildren; Index++) {

    Status = gBS->OpenProtocol (
                    ChildHandleBuffer[Index],
                    &gEfiBlockIoProtocolGuid,
                    (VOID **) &BlockIo,
                    This->DriverBindingHandle,
                    Controller,
                    EFI_OPEN_PROTOCOL_GET_PROTOCOL
                    );
    if (EFI_ERROR (Status)) {
      AllChildrenStopped = FALSE;
      DEBUG ((EFI_D_ERROR, "Fail to stop No.%d multi-lun child handle when opening blockio\n", (UINT32)Index));
      continue;
    }

    UsbMass = USB_MASS_DEVICE_FROM_BLOCK_IO (BlockIo);

    gBS->CloseProtocol (
           Controller,
           &gEfiUsbIoProtocolGuid,
           This->DriverBindingHandle,
           ChildHandleBuffer[Index]
           );
  
    Status = gBS->UninstallMultipleProtocolInterfaces (
                    ChildHandleBuffer[Index],
                    &gEfiDevicePathProtocolGuid,
                    UsbMass->DevicePath,
                    &gEfiBlockIoProtocolGuid,
                    &UsbMass->BlockIo,
                    &gEfiDiskInfoProtocolGuid,
                    &UsbMass->DiskInfo,
                    NULL
                    );
    
    if (EFI_ERROR (Status)) {
      //
      // Fail to uninstall Block I/O Protocol and Device Path Protocol, so re-open USB I/O Protocol by child.
      //
      AllChildrenStopped = FALSE;
      DEBUG ((EFI_D_ERROR, "Fail to stop No.%d multi-lun child handle when uninstalling blockio and devicepath\n", (UINT32)Index));
      
      gBS->OpenProtocol (
             Controller,
             &gEfiUsbIoProtocolGuid,
             (VOID **) &UsbIo,
             This->DriverBindingHandle,
             ChildHandleBuffer[Index],
             EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER
             );
    } else {
      //
      // Succeed to stop this multi-lun handle, so go on with next child.
      //
      if (((Index + 1) == NumberOfChildren) && AllChildrenStopped) {
        UsbMass->Transport->CleanUp (UsbMass->Context);
      }
      FreePool (UsbMass);
    }
  }

  if (!AllChildrenStopped) {
    return EFI_DEVICE_ERROR;
  }
  
  DEBUG ((EFI_D_INFO, "Success to stop all %d multi-lun children handles\n", (UINT32) NumberOfChildren));
  return EFI_SUCCESS;
}

/**
  Entrypoint of USB Mass Storage Driver.

  This function is the entrypoint of USB Mass Storage Driver. It installs Driver Binding
  Protocol together with Component Name Protocols.

  @param  ImageHandle       The firmware allocated handle for the EFI image.
  @param  SystemTable       A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.

**/
EFI_STATUS
EFIAPI
USBMassStorageEntryPoint (
  IN EFI_HANDLE               ImageHandle,
  IN EFI_SYSTEM_TABLE         *SystemTable
  )
{
  EFI_STATUS  Status;

  //
  // Install driver binding protocol
  //
  Status = EfiLibInstallDriverBindingComponentName2 (
             ImageHandle,
             SystemTable,
             &gUSBMassDriverBinding,
             ImageHandle,
             &gUsbMassStorageComponentName,
             &gUsbMassStorageComponentName2
             );
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}
#else

/* Accounting of active devices */
typedef struct _MASSDEV
{
    void *ifHandle; // Handle provided by USB HCI layer 
    USB_MASS_DEVICE *UsbMass; // Pointer to UsbMassDevice
} MASSDEV;

bdk_rlock_t musb_list_lock = {0,0};
static MASSDEV musb_list[8];
/*
** Cavium IO methods
*/ 
static USB_MASS_DEVICE *findUsbMass(const unsigned index, const bool lockIt) {
    if ( index   >= ARRAY_SIZE(musb_list)) {
        DEBUG((EFI_D_ERROR,"Index %u out of bounds max %lu",index,ARRAY_SIZE(musb_list) ));
        return NULL;
    }
    USB_MASS_DEVICE *UsbMass = musb_list[index].UsbMass;
    if (NULL == UsbMass) {
        DEBUG((EFI_D_ERROR,"Index %d points to empty slot",index ));
        return NULL;
    }   
    if (lockIt) {
        ASSERT(UsbMass->bus_lock);
        bdk_rlock_lock(UsbMass->bus_lock);
    }
    return UsbMass;
}

static int cvm_usb_open(__bdk_fs_dev_t *handle, int flags)
{
  
    USB_MASS_DEVICE *UsbMass = findUsbMass(handle->dev_index,true);
    if (NULL == UsbMass) return -1;
 
    EFI_BLOCK_IO_MEDIA  *Media = &UsbMass->BlockIoMedia;
    printf("Opening Usb%d block size 0x%x MaxLBA 0x%lx Removable %d MediaId %u ReadOnly %d \n",
           handle->dev_index,
           Media->BlockSize,
           (uint64_t)Media->LastBlock,
           Media->RemovableMedia ? 1:0,
           (uint32_t)Media->MediaId,
           Media->ReadOnly ? 1: 0);
    bdk_rlock_unlock(UsbMass->bus_lock);
    return 0;
}

static int cvm_usb_read(__bdk_fs_dev_t *handle, void *buffer, int length)
{
    printf("%s: H:%p-%d called %d bytes @%lu\n",__FUNCTION__, handle, handle->dev_index, length,handle->location);
    USB_MASS_DEVICE *UsbMass = findUsbMass(handle->dev_index,true);
    if (NULL == UsbMass) return -1;
    EFI_BLOCK_IO_MEDIA  *Media = &UsbMass->BlockIoMedia;
    uint32_t BlockSize = Media->BlockSize;
    int BlockShift = HighBitSet32(Media->BlockSize);
    uint64_t BlockMask = (1ULL<<BlockShift) -1;
    // Check for unaligned beginning
    int head = handle->location & BlockMask;
    char *scratchbuf = NULL; // have to assign to stop compiler warnings
    int rc = length; // assume we have read everything
    EFI_STATUS Status;
    if (head || length&BlockMask) {
        scratchbuf = malloc(BlockSize);
        if (NULL == scratchbuf) {
            rc = 0;
            goto read_done;
        }
    }
    uint64_t LBA = handle->location / BlockSize;
    if (head) {
        Status = UsbMassReadBlocks(&UsbMass->BlockIo, Media->MediaId, LBA, BlockSize, scratchbuf);
        if (EFI_ERROR(Status)) {
            DEBUG ((EFI_D_ERROR, "%s: Error (%d) reading first block\n", __FUNCTION__, (int) Status));
            rc = 0;
            goto read_done;
        }
        int lcopy = BlockSize - head;
        if (lcopy > length) lcopy = length;
        memcpy(buffer,scratchbuf,lcopy);
        buffer = ((char*)buffer) + lcopy;
        length -= lcopy;
        LBA += 1;
    }
    if (0 == length) goto read_done;
    int numBlocks = length >> BlockShift;
    Status =  UsbMassReadBlocks(&UsbMass->BlockIo, Media->MediaId, LBA, (numBlocks<<BlockShift), buffer);
    if (EFI_ERROR(Status)) {
        DEBUG ((EFI_D_ERROR, "%s: Error (%d) reading middle blocks\n", __FUNCTION__, (int) Status));
        rc = 0;
        goto read_done;
    }
    length -=  (numBlocks<<BlockShift);
    if (length) {
        LBA += numBlocks;
        buffer = ((char*) buffer) + (numBlocks<<BlockShift);
        Status = UsbMassReadBlocks(&UsbMass->BlockIo, Media->MediaId, LBA, BlockSize, scratchbuf);
        if (EFI_ERROR(Status)) {
            DEBUG ((EFI_D_ERROR, "%s: Error (%d) reading tail block\n", __FUNCTION__, (int) Status));
            rc = 0;
            goto read_done;
        }
        memcpy(buffer,scratchbuf,length); 
    }
    read_done:
    bdk_rlock_unlock(UsbMass->bus_lock);
    if (scratchbuf) free(scratchbuf);
    return rc;
}

static int cvm_usb_write(__bdk_fs_dev_t *handle, const void *buffer, int length)
{
    printf("%s: H:%p-%d called for %d bytes @%lu\n",__FUNCTION__, handle, handle->dev_index, length,handle->location);
    USB_MASS_DEVICE *UsbMass = findUsbMass(handle->dev_index, true);
    if (NULL == UsbMass) return -1;

    bdk_rlock_unlock(UsbMass->bus_lock);
    return length;
}
static int cvm_usb_close(__bdk_fs_dev_t *handle)
{
    printf("%s: H:%p %d \n",__FUNCTION__, handle, handle->dev_index);
    USB_MASS_DEVICE *UsbMass = findUsbMass(handle->dev_index,false);
    if (NULL == UsbMass) return -1;

    return 0;
}


static const __bdk_fs_dev_ops_t bdk_fs_usb_ops =
{
    .open = cvm_usb_open,
    .close = cvm_usb_close,
    .read = cvm_usb_read,
    .write = cvm_usb_write,
};



/*
** Interface to USB proper for Device add/remove
*/


/**
  Start controlling the usb mass storage interface

  @param  UsbIo                 Pointer to UsbIo for the interface
  @param  RemainingDevicePath   The remaining device path. 
  @param  ifHandle              Opaque handle which will be passed when stopping the interface

  @retval EFI_SUCCESS           The driver stopped from controlling the device.
  @retval EFI_UNSUPPORTED       This driver does not support this device.
  @retval EFI_DEVICE_ERROR      This driver cannot be started due to device Error.
  @retval EFI_OUT_OF_RESOURCES  Can't allocate memory resources.
  @retval EFI_ALREADY_STARTED   Interface have been already registered

**/
EFI_STATUS
UsbMassIfStart(EFI_USB_IO_PROTOCOL *UsbIo,  
              EFI_DEVICE_PATH_PROTOCOL      *DevicePath,
              void *ifHandle
    )
{  
    EFI_USB_INTERFACE_DESCRIPTOR  Interface;
    EFI_STATUS                    Status;
    
    // Find and initialize transport
    USB_MASS_TRANSPORT            **Transport;
    VOID                          *tContext; 
    UINT8                         MaxLun;
    Status = UsbIo->UsbGetInterfaceDescriptor (UsbIo, &Interface);
    if (EFI_ERROR (Status)) {
        return Status;
    }
    
    // Traverse the USB_MASS_TRANSPORT arrary and try to find the
    // matching transport protocol.
    // If not found, return EFI_UNSUPPORTED.
    // If found, execute USB_MASS_TRANSPORT.Init() to initialize the transport context.
    Status = EFI_UNSUPPORTED;
    Transport = NULL;
    tContext = NULL;
    for (unsigned Index = 0; Index < USB_MASS_TRANSPORT_COUNT; Index++) {
        *Transport = mUsbMassTransport[Index];
        
        if (Interface.InterfaceProtocol == (*Transport)->Protocol) {
            Status  = (*Transport)->Init (UsbIo, &tContext);
            break;
        }
    }
    if (EFI_ERROR (Status)) {
        goto err_exit;
    }
    if ((*Transport)->Protocol == USB_MASS_STORE_BOT) {
        (*Transport)->GetMaxLun (tContext, &MaxLun);
    }  
    
    // Initialize mass device
    if (MaxLun > 0) {
        CAVIUM_NOTYET("MultiLun support is not implemented");
        Status = EFI_UNSUPPORTED;
        goto err_exit;
    }
    // make sure there is accounting space before going further
    int devIndex = -1;
    bdk_rlock_lock(&musb_list_lock); // There may be multiple xhci polls going on
    for(unsigned ndx = 0; ndx < ARRAY_SIZE(musb_list); ndx++) {
        if (ifHandle == musb_list[ndx].ifHandle) {
            Status = EFI_ALREADY_STARTED;
            DEBUG((EFI_D_ERROR, "%s: attempt to register ifHandle %p twice", __FUNCTION__,ifHandle));
            goto err_exit;
        }
        if ((NULL == musb_list[ndx].ifHandle) && (devIndex < 0) ) devIndex = ndx;
    }
    if (devIndex < 0) {
        bdk_rlock_unlock(&musb_list_lock);
        DEBUG((EFI_D_ERROR, "%s: No space for ifHandle %p in device list", __FUNCTION__, ifHandle));
        Status =  EFI_OUT_OF_RESOURCES;
        goto err_exit;
    }
    USB_MASS_DEVICE *UsbMass =
        musb_list[devIndex].UsbMass = calloc(1,sizeof(*musb_list[devIndex].UsbMass));
    if (NULL == UsbMass) {
        bdk_rlock_unlock(&musb_list_lock);
        DEBUG((EFI_D_ERROR, "%s: Failed to malloc USB_MASS_DEVICE for ifHandle %p ", __FUNCTION__, ifHandle));
        Status =  EFI_OUT_OF_RESOURCES;
        goto err_exit;
    }
    musb_list[devIndex].ifHandle = ifHandle;
    bdk_rlock_unlock(&musb_list_lock);

    UsbMass->UsbIo                = UsbIo;
    UsbMass->BlockIo.Media        = &UsbMass->BlockIoMedia;
    UsbMass->BlockIo.Reset        = UsbMassReset;
    UsbMass->BlockIo.ReadBlocks   = UsbMassReadBlocks;
    UsbMass->BlockIo.WriteBlocks  = UsbMassWriteBlocks;
    UsbMass->BlockIo.FlushBlocks  = UsbMassFlushBlocks;
    UsbMass->OpticalStorage       = FALSE;
    UsbMass->Transport            = *Transport;
    UsbMass->Context              = tContext;

    Status = UsbMassInitMedia (UsbMass);
    if ((EFI_ERROR (Status)) && (Status != EFI_NO_MEDIA)) {
        DEBUG ((EFI_D_ERROR, "UsbMassInitNonLun: UsbMassInitMedia (%d)\n", (int)Status));
        free(UsbMass);
        bdk_rlock_lock(&musb_list_lock); 
        musb_list[devIndex].ifHandle = NULL;
        musb_list[devIndex].UsbMass = NULL;
        bdk_rlock_unlock(&musb_list_lock);       
        goto err_exit;
    }
  
    bdk_node_t node;
    int usb_port;
    {
        /* mat-2016-04-8 - tired of plumbing handle conversion  - hack
           Need to get a pointer to bus lock - it is reliable at this time as all the enteties in the chain exist.
        */
        
        USB_INTERFACE *UsbIf =  (typeof(UsbIf))USB_INTERFACE_FROM_USBIO (UsbIo);
        USB_DEVICE *Device = UsbIf->Device;
        USB_BUS *Bus = Device->Bus;
        typedef struct _EFI_USB2_HC_PROTOCOL  EFI_USB2_HC_PROTOCOL;
        int cvmH2C_to_node( EFI_USB2_HC_PROTOCOL *This,
                            bdk_node_t           *node,
                            int *usb_port,
                            void **lock);
        
        cvmH2C_to_node(Bus->Usb2Hc, &node, &usb_port, (void**)&UsbMass->bus_lock);
        DEBUG((EFI_D_INFO,"Initialized USB_MASS %p ifhandle %p @devindex %d\n", UsbMass, ifHandle, devIndex)); 
    }
    DEBUG((EFI_D_INFO,"Initialized USB_MASS %p ifhandle %p @devindex %d for node %u usb_port %d lock @%p\n", UsbMass, ifHandle, devIndex, (unsigned) node, usb_port,UsbMass->bus_lock )); 
    int rc = bdk_fs_register_dev("usb",devIndex,&bdk_fs_usb_ops);
    printf("\nRegistered device USB%d for node %d usb port %d rc:%d ifHandle %p\n", devIndex, (int) node, usb_port,rc,ifHandle);

    return Status;

err_exit:
    if (Transport && tContext)
        (*Transport)->CleanUp(tContext);
    
    return Status;
}

/**
  Stop controlling the usb mass storage interface

  @param  ifHandle              Opaque handle which will be passed when stopping the interface

**/
void
UsbMassIfStop(void *ifHandle)
{
    USB_MASS_DEVICE *UsbMass = NULL;
    bdk_rlock_lock(&musb_list_lock); 
    unsigned devIndex;
    for(devIndex = 0;  devIndex < ARRAY_SIZE(musb_list); devIndex++) {
        if (ifHandle == musb_list[devIndex].ifHandle) {
            UsbMass = musb_list[devIndex].UsbMass;
            musb_list[devIndex].UsbMass = NULL;
            musb_list[devIndex].ifHandle = NULL;
            break;
        }
    }
    bdk_rlock_unlock(&musb_list_lock);
    if (NULL == UsbMass) {
        DEBUG((EFI_D_ERROR, "%s: Failed to find index for ifHandle %p in device list", __FUNCTION__, ifHandle));
    } else {
        int rc = bdk_fs_unregister_dev("usb",devIndex);
        printf("Unregister USB %d from bdk_fs rc:%d\n", devIndex,rc);
        UsbMass->Transport->CleanUp (UsbMass->Context);
        free(UsbMass);
    }
    DEBUG((EFI_D_INFO, "Stopped USbMass %p for ifHandle %p\n", UsbMass, ifHandle));
}


#endif
