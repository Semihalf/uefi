/** @file

    Usb bus enumeration support.

Copyright (c) 2007 - 2014, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include "UsbBus.h"
#include "UsbMass.h"

/**
  Return the endpoint descriptor in this interface.

  @param  UsbIf                 The interface to search in.
  @param  EpAddr                The address of the endpoint to return.

  @return The endpoint descriptor or NULL.

**/
USB_ENDPOINT_DESC *
UsbGetEndpointDesc (
  IN USB_INTERFACE        *UsbIf,
  IN UINT8                EpAddr
  )
{
  USB_ENDPOINT_DESC       *EpDesc;
  UINT8                   Index;
  UINT8                   NumEndpoints;

  NumEndpoints = UsbIf->IfSetting->Desc.NumEndpoints;

  for (Index = 0; Index < NumEndpoints; Index++) {
    EpDesc = UsbIf->IfSetting->Endpoints[Index];

    if (EpDesc->Desc.EndpointAddress == EpAddr) {
      return EpDesc;
    }
  }

  return NULL;
}


/**
  Free the resource used by USB interface.

  @param  UsbIf                 The USB interface to free.

**/
VOID
UsbFreeInterface (
  IN USB_INTERFACE        *UsbIf
  )
{
#if defined(notdef_cavium)
  UsbCloseHostProtoByChild (UsbIf->Device->Bus, UsbIf->Handle);

  gBS->UninstallMultipleProtocolInterfaces (
         UsbIf->Handle,
         &gEfiDevicePathProtocolGuid,
         UsbIf->DevicePath,
         &gEfiUsbIoProtocolGuid,
         &UsbIf->UsbIo,
         NULL
         );
#else
  // Nothing needs to be done
#endif
  if (UsbIf->DevicePath != NULL) {
    FreePool (UsbIf->DevicePath);
  }

  FreePool (UsbIf);
}


/**
  Create an interface for the descriptor IfDesc. Each
  device's configuration can have several interfaces.

  @param  Device                The device has the interface descriptor.
  @param  IfDesc                The interface descriptor.

  @return The created USB interface for the descriptor, or NULL.

**/
USB_INTERFACE *
UsbCreateInterface (
  IN USB_DEVICE           *Device,
  IN USB_INTERFACE_DESC   *IfDesc
  )
{
  USB_DEVICE_PATH         UsbNode;
  USB_INTERFACE           *UsbIf;
  USB_INTERFACE           *HubIf;
#if defined(notdef_cavium)
  EFI_STATUS              Status;
#endif
  UsbIf = AllocateZeroPool (sizeof (USB_INTERFACE));

  if (UsbIf == NULL) {
    return NULL;
  }

  /* UsbIf->Signature  = USB_INTERFACE_SIGNATURE; */
  UsbIf->Device     = Device;
  UsbIf->IfDesc     = IfDesc;
  ASSERT (IfDesc->ActiveIndex < USB_MAX_INTERFACE_SETTING);
  UsbIf->IfSetting  = IfDesc->Settings[IfDesc->ActiveIndex];

  CopyMem (
    &(UsbIf->UsbIo),
    &mUsbIoProtocol,
    sizeof (EFI_USB_IO_PROTOCOL)
    );

  //
  // Install protocols for USBIO and device path
  //
  UsbNode.Header.Type       = MESSAGING_DEVICE_PATH;
  UsbNode.Header.SubType    = MSG_USB_DP;
  UsbNode.ParentPortNumber  = Device->ParentPort;
  UsbNode.InterfaceNumber   = UsbIf->IfSetting->Desc.InterfaceNumber;

  SetDevicePathNodeLength (&UsbNode.Header, sizeof (UsbNode));

  HubIf = Device->ParentIf;
  ASSERT (HubIf != NULL);

  UsbIf->DevicePath = AppendDevicePathNode (HubIf->DevicePath, &UsbNode.Header);

  if (UsbIf->DevicePath == NULL) {
    DEBUG ((EFI_D_ERROR, "UsbCreateInterface: failed to create device path\n"));

    /* Status = EFI_OUT_OF_RESOURCES; */
    goto ON_ERROR;
  }

#if defined(notdef_cavium)
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &UsbIf->Handle,
                  &gEfiDevicePathProtocolGuid,
                  UsbIf->DevicePath,
                  &gEfiUsbIoProtocolGuid,
                  &UsbIf->UsbIo,
                  NULL
                  );

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbCreateInterface: failed to install UsbIo - %d\n", (int) Status));
    goto ON_ERROR;
  }

  //
  // Open USB Host Controller Protocol by Child
  //

  Status = UsbOpenHostProtoByChild (Device->Bus, UsbIf->Handle);

  if (EFI_ERROR (Status)) {

    gBS->UninstallMultipleProtocolInterfaces (
           &UsbIf->Handle,
           &gEfiDevicePathProtocolGuid,
           UsbIf->DevicePath,
           &gEfiUsbIoProtocolGuid,
           &UsbIf->UsbIo,
           NULL
           );

    DEBUG ((EFI_D_ERROR, "UsbCreateInterface: failed to open host for child - %d\n", (int) Status));
    goto ON_ERROR;
  }
#else
  // Nothing needs to be done Connect/DisconnectDriver notifies bdk proper
#endif
  return UsbIf;

ON_ERROR:
  if (UsbIf->DevicePath != NULL) {
    FreePool (UsbIf->DevicePath);
  }

  FreePool (UsbIf);
  return NULL;
}


/**
  Free the resource used by this USB device.

  @param  Device                The USB device to free.

**/
VOID
UsbFreeDevice (
  IN USB_DEVICE           *Device
  )
{
  if (Device->DevDesc != NULL) {
    UsbFreeDevDesc (Device->DevDesc);
  }
#if defined(notdef_cavium)
  gBS->FreePool (Device);
#else
  free(Device);
#endif
}


/**
  Create a device which is on the parent's ParentPort port.

  @param  ParentIf              The parent HUB interface.
  @param  ParentPort            The port on the HUB this device is connected to.

  @return Created USB device, Or NULL.

**/
USB_DEVICE *
UsbCreateDevice (
  IN USB_INTERFACE        *ParentIf,
  IN UINT8                ParentPort
  )
{
  USB_DEVICE              *Device;

  ASSERT (ParentIf != NULL);

  Device = AllocateZeroPool (sizeof (USB_DEVICE));

  if (Device == NULL) {
    return NULL;
  }

  Device->Bus         = ParentIf->Device->Bus;
  Device->MaxPacket0  = 8;
  Device->ParentAddr  = ParentIf->Device->Address;
  Device->ParentIf    = ParentIf;
  Device->ParentPort  = ParentPort;
  Device->Tier        = (UINT8)(ParentIf->Device->Tier + 1);
  return Device;
}


/**
  Connect the USB interface with its driver. EFI USB bus will
  create a USB interface for each separate interface descriptor.

  @param  UsbIf             The interface to connect driver to.

  @return EFI_SUCCESS       Interface is managed by some driver.
  @return Others            Failed to locate a driver for this interface.

**/
EFI_STATUS
UsbConnectDriver (
  IN USB_INTERFACE        *UsbIf
  )
{
  EFI_STATUS              Status;

  Status = EFI_SUCCESS;

  //
  // Hub is maintained by the USB bus driver. Otherwise try to
  // connect drivers with this interface
  //
  if (UsbIsHubInterface (UsbIf)) {
    DEBUG ((EFI_D_INFO, "UsbConnectDriver: found a hub device\n"));
    Status = mUsbHubApi.Init (UsbIf);

  } else {
#if defined(notdef_cavium)
      /* EFI_TPL                 OldTpl; */
    //
    // This function is called in both UsbIoControlTransfer and
    // the timer callback in hub enumeration. So, at least it is
    // called at TPL_CALLBACK. Some driver sitting on USB has
    // twisted TPL used. It should be no problem for us to connect
    // or disconnect at CALLBACK.
    //

    //
    // Only recursively wanted usb child device
    //
    if (UsbBusIsWantedUsbIO (UsbIf->Device->Bus, UsbIf)) {
      /* OldTpl            = UsbGetCurrentTpl (); */
      /* DEBUG ((EFI_D_INFO, "UsbConnectDriver: TPL before connect is %d, %p\n", (UINT32)OldTpl, UsbIf->Handle)); */

      /* gBS->RestoreTPL (TPL_CALLBACK); */

        CAVIUM_NOTYET( Status            = gBS->ConnectController (UsbIf->Handle, NULL, NULL, TRUE); );
        UsbIf->IsManaged  = (BOOLEAN)!EFI_ERROR (Status);

      /* DEBUG ((EFI_D_INFO, "UsbConnectDriver: TPL after connect is %d\n", (UINT32)UsbGetCurrentTpl())); */
      /* ASSERT (UsbGetCurrentTpl () == TPL_CALLBACK); */

      /* gBS->RaiseTPL (OldTpl); */
    }
#else
        // We do not need to recursively connect.
        // Call notifier for usb mass storage
         if (UsbIf->IfSetting->Desc.InterfaceClass == USB_MASS_STORE_CLASS) {
             Status = UsbMassIfStart(&UsbIf->UsbIo,  UsbIf->DevicePath, UsbIf);
             // Record if mass storage will deal with it
             UsbIf->IsManaged  = (BOOLEAN)!EFI_ERROR (Status);
         } else {
             BDK_TRACE(USB_XHCI,"Not a storage device: class %d sub-class %d protocol %d\n",
                       UsbIf->IfSetting->Desc.InterfaceClass,
                       UsbIf->IfSetting->Desc.InterfaceSubClass,
                       UsbIf->IfSetting->Desc.InterfaceProtocol);
             UsbIf->IsManaged = FALSE;
         }
#endif

  }

  return Status;
}


/**
  Select an alternate setting for the interface.
  Each interface can have several mutually exclusive
  settings. Only one setting is active. It will
  also reset its endpoints' toggle to zero.

  @param  IfDesc                The interface descriptor to set.
  @param  Alternate             The alternate setting number to locate.

  @retval EFI_NOT_FOUND         There is no setting with this alternate index.
  @retval EFI_SUCCESS           The interface is set to Alternate setting.

**/
EFI_STATUS
UsbSelectSetting (
  IN USB_INTERFACE_DESC   *IfDesc,
  IN UINT8                Alternate
  )
{
  USB_INTERFACE_SETTING   *Setting;
  UINTN                   Index;

  //
  // Locate the active alternate setting
  //
  Setting = NULL;

  for (Index = 0; Index < IfDesc->NumOfSetting; Index++) {
    ASSERT (Index < USB_MAX_INTERFACE_SETTING);
    Setting = IfDesc->Settings[Index];

    if (Setting->Desc.AlternateSetting == Alternate) {
      break;
    }
  }

  if (Index == IfDesc->NumOfSetting) {
    return EFI_NOT_FOUND;
  }

  IfDesc->ActiveIndex = Index;

  ASSERT (Setting != NULL);
  DEBUG ((EFI_D_INFO, "UsbSelectSetting: setting %d selected for interface %d\n",
              Alternate, Setting->Desc.InterfaceNumber));

  //
  // Reset the endpoint toggle to zero
  //
  for (Index = 0; Index < Setting->Desc.NumEndpoints; Index++) {
    Setting->Endpoints[Index]->Toggle = 0;
  }

  return EFI_SUCCESS;
}


/**
  Select a new configuration for the device. Each
  device may support several configurations.

  @param  Device                The device to select configuration.
  @param  ConfigValue           The index of the configuration ( != 0).

  @retval EFI_NOT_FOUND         There is no configuration with the index.
  @retval EFI_OUT_OF_RESOURCES  Failed to allocate resource.
  @retval EFI_SUCCESS           The configuration is selected.

**/
EFI_STATUS
UsbSelectConfig (
  IN USB_DEVICE           *Device,
  IN UINT8                ConfigValue
  )
{
  USB_DEVICE_DESC         *DevDesc;
  USB_CONFIG_DESC         *ConfigDesc;
  USB_INTERFACE_DESC      *IfDesc;
  USB_INTERFACE           *UsbIf;
  EFI_STATUS              Status;
  UINT8                   Index;

  //
  // Locate the active config, then set the device's pointer
  //
  DevDesc     = Device->DevDesc;
  ConfigDesc  = NULL;

  for (Index = 0; Index < DevDesc->Desc.NumConfigurations; Index++) {
    ConfigDesc = DevDesc->Configs[Index];

    if (ConfigDesc->Desc.ConfigurationValue == ConfigValue) {
      break;
    }
  }

  if (Index == DevDesc->Desc.NumConfigurations) {
    return EFI_NOT_FOUND;
  }

  Device->ActiveConfig = ConfigDesc;

  DEBUG ((EFI_D_INFO, "UsbSelectConfig: config %d selected for device %d\n",
              ConfigValue, Device->Address));

  //
  // Create interfaces for each USB interface descriptor.
  //
  for (Index = 0; Index < ConfigDesc->Desc.NumInterfaces; Index++) {
    //
    // First select the default interface setting, and reset
    // the endpoint toggles to zero for its endpoints.
    //
    IfDesc = ConfigDesc->Interfaces[Index];
    UsbSelectSetting (IfDesc, IfDesc->Settings[0]->Desc.AlternateSetting);

    //
    // Create a USB_INTERFACE and install USB_IO and other protocols
    //
    UsbIf = UsbCreateInterface (Device, ConfigDesc->Interfaces[Index]);

    if (UsbIf == NULL) {
      Device->NumOfInterface = Index;
      return EFI_OUT_OF_RESOURCES;
    }

    ASSERT (Index < USB_MAX_INTERFACE);
    Device->Interfaces[Index] = UsbIf;

    //
    // Connect the device to drivers, if it failed, ignore
    // the error. Don't let the unsupported interfaces to block
    // the supported interfaces.
    //
    Status = UsbConnectDriver (UsbIf);

    if (EFI_ERROR (Status)) {
      DEBUG ((EFI_D_ERROR, "UsbSelectConfig: failed to connect driver %d, ignored\n", (int) Status));
    }
  }

  Device->NumOfInterface = Index;

  return EFI_SUCCESS;
}


/**
  Disconnect the USB interface with its driver.

  @param  UsbIf                 The interface to disconnect driver from.

**/
EFI_STATUS
UsbDisconnectDriver (
  IN USB_INTERFACE        *UsbIf
  )
{
  EFI_STATUS              Status;

  //
  // Release the hub if it's a hub controller, otherwise
  // disconnect the driver if it is managed by other drivers.
  //
  Status = EFI_SUCCESS;
  if (UsbIf->IsHub) {
    Status = UsbIf->HubApi->Release (UsbIf);

  } else if (UsbIf->IsManaged) {
#if defined(notdef_cavium)
      EFI_TPL                 OldTpl;
    //
    // This function is called in both UsbIoControlTransfer and
    // the timer callback in hub enumeration. So, at least it is
    // called at TPL_CALLBACK. Some driver sitting on USB has
    // twisted TPL used. It should be no problem for us to connect
    // or disconnect at CALLBACK.
    //
    OldTpl           = UsbGetCurrentTpl ();
    DEBUG ((EFI_D_INFO, "UsbDisconnectDriver: old TPL is %d, %p\n", (UINT32)OldTpl, UsbIf->Handle));

    gBS->RestoreTPL (TPL_CALLBACK);

    Status = gBS->DisconnectController (UsbIf->Handle, NULL, NULL);
    if (!EFI_ERROR (Status)) {
      UsbIf->IsManaged = FALSE;
    }

    DEBUG (( EFI_D_INFO, "UsbDisconnectDriver: TPL after disconnect is %d, %d\n", (UINT32)UsbGetCurrentTpl(), (int) Status));
    ASSERT (UsbGetCurrentTpl () == TPL_CALLBACK);

    gBS->RaiseTPL (OldTpl);
#else
    UsbIf->IsManaged = FALSE;
    UsbMassIfStop(UsbIf);
    DEBUG (( EFI_D_INFO, "UsbDisconnectDriver: Stopped UsbIf %p\n", UsbIf));
#endif
  }

  return Status;
}


/**
  Remove the current device configuration.

  @param  Device                The USB device to remove configuration from.

**/
EFI_STATUS
UsbRemoveConfig (
  IN USB_DEVICE           *Device
  )
{
  USB_INTERFACE           *UsbIf;
  UINTN                   Index;
  EFI_STATUS              Status;
  EFI_STATUS              ReturnStatus;

  //
  // Remove each interface of the device
  //
  ReturnStatus = EFI_SUCCESS;
  for (Index = 0; Index < Device->NumOfInterface; Index++) {
    ASSERT (Index < USB_MAX_INTERFACE);
    UsbIf = Device->Interfaces[Index];

    if (UsbIf == NULL) {
      continue;
    }

    Status = UsbDisconnectDriver (UsbIf);
    if (!EFI_ERROR (Status)) {
      UsbFreeInterface (UsbIf);
      Device->Interfaces[Index] = NULL;
    } else {
      ReturnStatus = Status;
    }
  }

  Device->ActiveConfig    = NULL;
  return ReturnStatus;
}


/**
  Remove the device and all its children from the bus.

  @param  Device                The device to remove.

  @retval EFI_SUCCESS           The device is removed.

**/
EFI_STATUS
UsbRemoveDevice (
  IN USB_DEVICE           *Device
  )
{
  USB_BUS                 *Bus;
  USB_DEVICE              *Child;
  EFI_STATUS              Status;
  EFI_STATUS              ReturnStatus;
  UINTN                   Index;

  Bus = Device->Bus;

  //
  // Remove all the devices on its downstream ports. Search from devices[1].
  // Devices[0] is the root hub.
  //
  ReturnStatus = EFI_SUCCESS;
  for (Index = 1; Index < Bus->MaxDevices; Index++) {
    Child = Bus->Devices[Index];

    if ((Child == NULL) || (Child->ParentAddr != Device->Address)) {
      continue;
    }

    Status = UsbRemoveDevice (Child);

    if (!EFI_ERROR (Status)) {
      Bus->Devices[Index] = NULL;
    } else {
      Bus->Devices[Index]->DisconnectFail = TRUE;
      ReturnStatus = Status;
      DEBUG ((EFI_D_INFO, "UsbRemoveDevice: failed to remove child %p at parent %p\n", Child, Device));
    }
  }

  if (EFI_ERROR (ReturnStatus)) {
    return ReturnStatus;
  }

  Status = UsbRemoveConfig (Device);

  if (!EFI_ERROR (Status)) {
    DEBUG (( EFI_D_INFO, "UsbRemoveDevice: device %d removed\n", Device->Address));

    ASSERT (Device->Address < Bus->MaxDevices);
    Bus->Devices[Device->Address] = NULL;
    UsbFreeDevice (Device);
  } else {
    Bus->Devices[Device->Address]->DisconnectFail = TRUE;
  }
  return Status;
}


/**
  Find the child device on the hub's port.

  @param  HubIf                 The hub interface.
  @param  Port                  The port of the hub this child is connected to.

  @return The device on the hub's port, or NULL if there is none.

**/
USB_DEVICE *
UsbFindChild (
  IN USB_INTERFACE        *HubIf,
  IN UINT8                Port
  )
{
  USB_DEVICE              *Device;
  USB_BUS                 *Bus;
  UINTN                   Index;

  Bus = HubIf->Device->Bus;

  //
  // Start checking from device 1, device 0 is the root hub
  //
  for (Index = 1; Index < Bus->MaxDevices; Index++) {
    Device = Bus->Devices[Index];

    if ((Device != NULL) && (Device->ParentAddr == HubIf->Device->Address) &&
        (Device->ParentPort == Port)) {

      return Device;
    }
  }

  return NULL;
}


/**
  Enumerate and configure the new device on the port of this HUB interface.

  @param  HubIf                 The HUB that has the device connected.
  @param  Port                  The port index of the hub (started with zero).

  @retval EFI_SUCCESS           The device is enumerated (added or removed).
  @retval EFI_OUT_OF_RESOURCES  Failed to allocate resource for the device.
  @retval Others                Failed to enumerate the device.

**/
EFI_STATUS
UsbEnumerateNewDev (
  IN USB_INTERFACE        *HubIf,
  IN UINT8                Port
  )
{
  USB_BUS                 *Bus;
  USB_HUB_API             *HubApi;
  USB_DEVICE              *Child;
  USB_DEVICE              *Parent;
  EFI_USB_PORT_STATUS     PortState;
  UINTN                   Address;
  UINT8                   Config;
  EFI_STATUS              Status;

  Parent  = HubIf->Device;
  Bus     = Parent->Bus;
  HubApi  = HubIf->HubApi;
  Address = Bus->MaxDevices;
#if defined(notdef_cavium)
  gBS->Stall (USB_WAIT_PORT_STABLE_STALL);
#else
  bdk_wait_usec(USB_WAIT_PORT_STABLE_STALL);
#endif
  //
  // Hub resets the device for at least 10 milliseconds.
  // Host learns device speed. If device is of low/full speed
  // and the hub is a EHCI root hub, ResetPort will release
  // the device to its companion UHCI and return an error.
  //
  Status = HubApi->ResetPort (HubIf, Port);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to reset port %d - %d\n", Port, (int) Status));

    return Status;
  }

  DEBUG (( EFI_D_INFO, "UsbEnumerateNewDev: hub port %d is reset\n", Port));

  Child = UsbCreateDevice (HubIf, Port);

  if (Child == NULL) {
    return EFI_OUT_OF_RESOURCES;
  }

  //
  // OK, now identify the device speed. After reset, hub
  // fully knows the actual device speed.
  //
  Status = HubApi->GetPortStatus (HubIf, Port, &PortState);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to get speed of port %d\n", Port));
    goto ON_ERROR;
  }

  if (!USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_CONNECTION)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: No device present at port %d\n", Port));
    goto ON_ERROR;
  } else if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_SUPER_SPEED)){
    Child->Speed      = EFI_USB_SPEED_SUPER;
    Child->MaxPacket0 = 512;
  } else if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_HIGH_SPEED)) {
    Child->Speed      = EFI_USB_SPEED_HIGH;
    Child->MaxPacket0 = 64;
  } else if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_LOW_SPEED)) {
    Child->Speed      = EFI_USB_SPEED_LOW;
    Child->MaxPacket0 = 8;
  } else {
    Child->Speed      = EFI_USB_SPEED_FULL;
    Child->MaxPacket0 = 8;
  }

  DEBUG (( EFI_D_INFO, "UsbEnumerateNewDev: device is of %d speed\n", Child->Speed));

  if (((Child->Speed == EFI_USB_SPEED_LOW) || (Child->Speed == EFI_USB_SPEED_FULL)) &&
      (Parent->Speed == EFI_USB_SPEED_HIGH)) {
    //
    // If the child is a low or full speed device, it is necessary to
    // set the transaction translator. Port TT is 1-based.
    // This is quite simple:
    //  1. if parent is of high speed, then parent is our translator
    //  2. otherwise use parent's translator.
    //
    Child->Translator.TranslatorHubAddress  = Parent->Address;
    Child->Translator.TranslatorPortNumber  = (UINT8) (Port + 1);
  } else {
    Child->Translator = Parent->Translator;
  }
  DEBUG (( EFI_D_INFO, "UsbEnumerateNewDev: device uses translator (%d, %d)\n",
           Child->Translator.TranslatorHubAddress,
           Child->Translator.TranslatorPortNumber));

  //
  // After port is reset, hub establishes a signal path between
  // the device and host (DEFALUT state). Device's registers are
  // reset, use default address 0 (host enumerates one device at
  // a time) , and ready to respond to control transfer at EP 0.
  //

  //
  // Host assigns an address to the device. Device completes the
  // status stage with default address, then switches to new address.
  // ADDRESS state. Address zero is reserved for root hub.
  //
  ASSERT (Bus->MaxDevices <= 256);
  for (Address = 1; Address < Bus->MaxDevices; Address++) {
    if (Bus->Devices[Address] == NULL) {
      break;
    }
  }

  if (Address >= Bus->MaxDevices) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: address pool is full for port %d\n", Port));

    Status = EFI_ACCESS_DENIED;
    goto ON_ERROR;
  }

  Status                = UsbSetAddress (Child, (UINT8)Address);
  Child->Address        = (UINT8)Address;
  Bus->Devices[Address] = Child;

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to set device address - %d\n", (int) Status));
    goto ON_ERROR;
  }
#if defined(notdef_cavium)
  gBS->Stall (USB_SET_DEVICE_ADDRESS_STALL);
#else
  bdk_wait_usec(USB_SET_DEVICE_ADDRESS_STALL);
#endif
  DEBUG ((EFI_D_INFO, "UsbEnumerateNewDev: device is now ADDRESSED at %d\n", (int) Address));

  //
  // Host sends a Get_Descriptor request to learn the max packet
  // size of default pipe (only part of the device's descriptor).
  //
  Status = UsbGetMaxPacketSize0 (Child);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to get max packet for EP 0 - %d\n", (int) Status));
    goto ON_ERROR;
  }

  DEBUG (( EFI_D_INFO, "UsbEnumerateNewDev: max packet size for EP 0 is %d\n", Child->MaxPacket0));

  //
  // Host learns about the device's abilities by requesting device's
  // entire descriptions.
  //
  Status = UsbBuildDescTable (Child);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to build descriptor table - %d\n", (int) Status));
    goto ON_ERROR;
  }

  //
  // Select a default configuration: UEFI must set the configuration
  // before the driver can connect to the device.
  //
  Config = Child->DevDesc->Configs[0]->Desc.ConfigurationValue;
  Status = UsbSetConfig (Child, Config);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to set configure %d - %d\n", Config, (int) Status));
    goto ON_ERROR;
  }

  DEBUG (( EFI_D_INFO, "UsbEnumerateNewDev: device %d is now in CONFIGED state\n", (int) Address));

  //
  // Host assigns and loads a device driver.
  //
  Status = UsbSelectConfig (Child, Config);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumerateNewDev: failed to create interfaces - %d\n", (int) Status));
    goto ON_ERROR;
  }

  //
  // Report Status Code to indicate USB device has been detected by hotplug
  //
  REPORT_STATUS_CODE_WITH_DEVICE_PATH (
    EFI_PROGRESS_CODE,
    (EFI_IO_BUS_USB | EFI_IOB_PC_HOTPLUG),
    Bus->DevicePath
    );
  return EFI_SUCCESS;

ON_ERROR:
  //
  // If reach here, it means the enumeration process on a given port is interrupted due to error.
  // The s/w resources, including the assigned address(Address) and the allocated usb device data
  // structure(Bus->Devices[Address]), will NOT be freed here. These resources will be freed when
  // the device is unplugged from the port or DriverBindingStop() is invoked.
  //
  // This way is used to co-work with the lower layer EDKII UHCI/EHCI/XHCI host controller driver.
  // It's mainly because to keep UEFI spec unchanged EDKII XHCI driver have to maintain a state machine
  // to keep track of the mapping between actual address and request address. If the request address
  // (Address) is freed here, the Address value will be used by next enumerated device. Then EDKII XHCI
  // host controller driver will have wrong information, which will cause further transaction error.
  //
  // EDKII UHCI/EHCI doesn't get impacted as it's make sense to reserve s/w resource till it gets unplugged.
  //
  return Status;
}


/**
  Process the events on the port.

  @param  HubIf                 The HUB that has the device connected.
  @param  Port                  The port index of the hub (started with zero).

  @retval EFI_SUCCESS           The device is enumerated (added or removed).
  @retval EFI_OUT_OF_RESOURCES  Failed to allocate resource for the device.
  @retval Others                Failed to enumerate the device.

**/
EFI_STATUS
UsbEnumeratePort (
  IN USB_INTERFACE        *HubIf,
  IN UINT8                Port
  )
{
  USB_HUB_API             *HubApi;
  USB_DEVICE              *Child;
  EFI_USB_PORT_STATUS     PortState;
  EFI_STATUS              Status;

  Child   = NULL;
  HubApi  = HubIf->HubApi;

  //
  // Host learns of the new device by polling the hub for port changes.
  //
  Status = HubApi->GetPortStatus (HubIf, Port, &PortState);

  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UsbEnumeratePort: failed to get state of port %d\n", Port));
    return Status;
  }

  //
  // Only handle connection/enable/overcurrent/reset change.
  // Usb super speed hub may report other changes, such as warm reset change. Ignore them.
  //
  if ((PortState.PortChangeStatus & (USB_PORT_STAT_C_CONNECTION | USB_PORT_STAT_C_ENABLE | USB_PORT_STAT_C_OVERCURRENT | USB_PORT_STAT_C_RESET)) == 0) {
    return EFI_SUCCESS;
  }

  DEBUG (( EFI_D_INFO, "UsbEnumeratePort: port %d state - %02x, change - %02x on %p\n",
              Port, PortState.PortStatus, PortState.PortChangeStatus, HubIf));

  //
  // This driver only process two kinds of events now: over current and
  // connect/disconnect. Other three events are: ENABLE, SUSPEND, RESET.
  // ENABLE/RESET is used to reset port. SUSPEND isn't supported.
  //

  if (USB_BIT_IS_SET (PortState.PortChangeStatus, USB_PORT_STAT_C_OVERCURRENT)) {

    if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_OVERCURRENT)) {
      //
      // Case1:
      //   Both OverCurrent and OverCurrentChange set, means over current occurs,
      //   which probably is caused by short circuit. It has to wait system hardware
      //   to perform recovery.
      //
      DEBUG (( EFI_D_ERROR, "UsbEnumeratePort: Critical Over Current %d\n", Port));
      return EFI_DEVICE_ERROR;

    }
    //
    // Case2:
    //   Only OverCurrentChange set, means system has been recoveried from
    //   over current. As a result, all ports are nearly power-off, so
    //   it's necessary to detach and enumerate all ports again.
    //
    DEBUG (( EFI_D_ERROR, "UsbEnumeratePort: 2.0 device Recovery Over Current %d\n", Port));
  }

  if (USB_BIT_IS_SET (PortState.PortChangeStatus, USB_PORT_STAT_C_ENABLE)) {
    //
    // Case3:
    //   1.1 roothub port reg doesn't reflect over-current state, while its counterpart
    //   on 2.0 roothub does. When over-current has influence on 1.1 device, the port
    //   would be disabled, so it's also necessary to detach and enumerate again.
    //
    DEBUG (( EFI_D_ERROR, "UsbEnumeratePort: 1.1 device Recovery Over Current %d\n", Port));
  }

  if (USB_BIT_IS_SET (PortState.PortChangeStatus, USB_PORT_STAT_C_CONNECTION)) {
    //
    // Case4:
    //   Device connected or disconnected normally.
    //
    DEBUG ((EFI_D_INFO, "UsbEnumeratePort: Device Connect/Disconnect Normally %d\n", Port));
  }

  //
  // Following as the above cases, it's safety to remove and create again.
  //
  Child = UsbFindChild (HubIf, Port);

  if (Child != NULL) {
    DEBUG (( EFI_D_INFO, "UsbEnumeratePort: device at port %d being removed from hub %p\n", Port, HubIf));
    UsbRemoveDevice (Child);
  }

  if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_CONNECTION)) {
    //
    // Now, new device connected, enumerate and configure the device
    //
    DEBUG (( EFI_D_INFO, "UsbEnumeratePort: new device connected at port %d\n", Port));
    Status = UsbEnumerateNewDev (HubIf, Port);

  } else {
    DEBUG (( EFI_D_INFO, "UsbEnumeratePort: device disconnected event on port %d\n", Port));
  }

  HubApi->ClearPortChange (HubIf, Port);
  return Status;
}


/**
  Enumerate all the changed hub ports.

  @param  Event                 The event that is triggered.
  @param  Context               The context to the event.

**/
VOID
EFIAPI
UsbHubEnumeration (
  IN EFI_EVENT            Event,
  IN VOID                 *Context
  )
{
  USB_INTERFACE           *HubIf;
  UINT8                   Byte;
  UINT8                   Bit;
  UINT8                   Index;
  USB_DEVICE              *Child;

  ASSERT (Context != NULL);

  HubIf = (USB_INTERFACE *) Context;

  for (Index = 0; Index < HubIf->NumOfPort; Index++) {
    Child = UsbFindChild (HubIf, Index);
    if ((Child != NULL) && (Child->DisconnectFail == TRUE)) {
      DEBUG (( EFI_D_INFO, "UsbEnumeratePort: The device disconnect fails at port %d from hub %p, try again\n", Index, HubIf));
      UsbRemoveDevice (Child);
    }
  }

  if (HubIf->ChangeMap == NULL) {
    return ;
  }

  //
  // HUB starts its port index with 1.
  //
  Byte  = 0;
  Bit   = 1;

  for (Index = 0; Index < HubIf->NumOfPort; Index++) {
    if (USB_BIT_IS_SET (HubIf->ChangeMap[Byte], USB_BIT (Bit))) {
      UsbEnumeratePort (HubIf, Index);
    }

    USB_NEXT_BIT (Byte, Bit);
  }

  UsbHubAckHubStatus (HubIf->Device);
#if defined(notdef_cavium)
  gBS->FreePool (HubIf->ChangeMap);
#else
  free(HubIf->ChangeMap);
#endif
  HubIf->ChangeMap = NULL;
  return ;
}


/**
  Enumerate all the changed hub ports.

  @param  Event                 The event that is triggered.
  @param  Context               The context to the event.

**/
VOID
EFIAPI
UsbRootHubEnumeration (
  IN EFI_EVENT            Event,
  IN VOID                 *Context
  )
{
  USB_INTERFACE           *RootHub;
  UINT8                   Index;
  USB_DEVICE              *Child;

  RootHub = (USB_INTERFACE *) Context;

  for (Index = 0; Index < RootHub->NumOfPort; Index++) {
    Child = UsbFindChild (RootHub, Index);
    if ((Child != NULL) && (Child->DisconnectFail == TRUE)) {
        DEBUG (( EFI_D_INFO, "%s: The device disconnect fails at port %d from root hub %p, try again\n", __FUNCTION__, Index, RootHub));
      UsbRemoveDevice (Child);
    }
    UsbEnumeratePort (RootHub, Index);
  }
}

