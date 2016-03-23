/** @file

    Usb bus support - external interfaces

Copyright (c) 2007 - 2014, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <bdk.h>
#include "bdk-xhci.h"
#include <malloc.h> // for memalign
#include "UsbBus.h"
#include "UsbDesc.h"
#include "UsbHub.h"

typedef struct usb_hc_descriptor_s {
    USB_BUS *usb_bus;
    USB_DEVICE *root_hub;
    USB_INTERFACE *root_if;
    xhci_t *xhci_priv;
} usb_hc_descriptor_t;

static usb_hc_descriptor_t usb_global_data[BDK_NUMA_MAX_NODES][CAVIUM_MAX_USB_INSTANCES];
int bdk_usb_HCInit(bdk_node_t node, int usb_port) 
{
    if ((unsigned int) node > BDK_NUMA_MAX_NODES) {
       printf("USB port must be less then %d", usb_port);
       return -1;
    }
    if (usb_port >= CAVIUM_MAX_USB_INSTANCES) {
        printf("USB port must be less then %d", usb_port);
        return -1;
    
    }
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_USBHX_UAHC_USBSTS(usb_port), cnr, ==, 0, 10000)) {
        bdk_error("USB%d - rimeout waiting for controller ready\n", usb_port);
        return -1;
    }
    int rc = 0;
    // If host controller is not halted, halt it.
    if (!bdk_xhc_halted(node,usb_port)) {
        reset_xhc(node,usb_port);
    }
    // Wait for USBSTS.CNR == 0
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_USBHX_UAHC_USBSTS(usb_port), cnr, ==, 0, 10000)) {
        bdk_error("USB%d - timeout waiting for controller ready\n", usb_port);
        rc = -2;
        goto out;
    }
    xhci_t *thisHC = usb_global_data[node][usb_port].xhci_priv;

    //-- TODO Free async transfers
    if (thisHC) {
        printf("freeing memory of previous instance\n");
        xhciFreeSched(thisHC);

    } else {
        thisHC = createUsbXHci(node,usb_port);
        if (thisHC == NULL) {
            printf("failed to allocate device context\n");
            rc = -3;
            goto out;
        }
        usb_global_data[node][usb_port].xhci_priv = thisHC;
       
    }

    printf("thisHC @%p\n",thisHC);
    printf("hcsparams1:%08lx\n",(unsigned long) thisHC->hcsparams1.u);
    printf("hcsparams2:%08lx\n",(unsigned long) thisHC->hcsparams2.u);
    printf("hccparams:%08lx\n",(unsigned long) thisHC->hccparams.u);
    printf("page size %d\nnode %d port %d\n", thisHC->PageSize,thisHC->node,thisHC->usb_port);
    printf("64 bit capability %d\n",thisHC->hccparams.s.ac64); 
    
    if (0 == (rc = xhciInitSched(thisHC))) {
        printf("Setting run bit for node %d usb_port %d\n",
               thisHC->node, thisHC->usb_port
            );
        run_xhc(thisHC->node,thisHC->usb_port);
// To do - start root hub status poll
    }
     USB_INTERFACE *RootIf = usb_global_data[node][usb_port].root_if;
    USB_BUS *UsbBus = usb_global_data[node][usb_port].usb_bus;
    USB_DEVICE *RootHub = usb_global_data[node][usb_port].root_hub;
    if (NULL == RootIf) {
        RootIf = calloc(1,sizeof(*RootIf));
        UsbBus = calloc(1,sizeof(*UsbBus));
        RootHub = calloc(1,sizeof(*RootHub));
        /* UsbBus.c:UsbBusBuildProtocol */
        UsbBus->MaxDevices = 128;
        UsbBus->Usb2Hc = &thisHC->Usb2Hc;
        if (UsbBus->Usb2Hc->MajorRevision == 0x3) {
            UsbBus->MaxDevices = 256;
        }
        UsbBus->Usb2Hc->Reset(UsbBus->Usb2Hc,  EFI_USB_HC_RESET_GLOBAL);
        UsbBus->Usb2Hc->SetState(UsbBus->Usb2Hc, EfiUsbHcStateOperational);
        InitializeListHead (&UsbBus->WantedUsbIoDPList);
        /* Status = UsbBusAddWantedUsbIoDP (&UsbBus->BusId, RemainingDevicePath); */
        RootHub->Bus            = UsbBus;
        RootHub->NumOfInterface = 1;
        RootHub->Interfaces[0]  = RootIf;
        RootHub->Tier           = 0;
        RootIf->Signature       = USB_INTERFACE_SIGNATURE;
        RootIf->Device          = RootHub;
        RootIf->DevicePath      = UsbBus->DevicePath;
        {
          /*UsbHub.c:UsbRootHubInit */
            /* EFI_STATUS              Status; */
            UINT8                   MaxSpeed;
            UINT8                   NumOfPort;
            UINT8                   Support64;
            UsbBus->Usb2Hc->GetCapability( UsbBus->Usb2Hc,
                                           &MaxSpeed,
                                           &NumOfPort,
                                           &Support64);
           
            RootIf->IsHub      = TRUE;
            RootIf->HubApi     = /*&mUsbRootHubApi*/ NULL;;
            RootIf->HubEp      = NULL;
            RootIf->MaxSpeed   = MaxSpeed;
            RootIf->NumOfPort  = NumOfPort;
            RootIf->HubNotify  = NULL;
            /*** */
        } 
        UsbBus->Devices[0] = RootHub;

        usb_global_data[node][usb_port].root_if = RootIf;
        usb_global_data[node][usb_port].usb_bus = UsbBus;
        usb_global_data[node][usb_port].root_hub = RootHub; 
    }   
out:
    if (rc) 
        printf("%s exiting with rc %d\n", __FUNCTION__, rc);
    return rc;
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

  /* gBS->FreePool (Device); */
  free(Device);
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
#if defined(notdef_cavium)
    Status = UsbDisconnectDriver (UsbIf);
    if (!EFI_ERROR (Status)) {
      UsbFreeInterface (UsbIf);
      Device->Interfaces[Index] = NULL;
    } else {
      ReturnStatus = Status;
    }
#else
    CAVIUM_NOTYET("Not removing Interface\n");
#endif
  }
  Device->ActiveConfig    = NULL;
  return ReturnStatus;
}


/**
  Find the child device on the hub's port.

  @param  HubIf                 The hub interface.
  @param  Port                  The port of the hub this child is connected to.

  @return The device on the hub's port, or NULL if there is none.

**/
static USB_DEVICE *
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

int bdk_usb_HCPoll(bdk_node_t node, int usb_port){
    if ((unsigned int) node > BDK_NUMA_MAX_NODES) {
        printf("USB port must be less then %d", usb_port);
        return -1;
    }
    if (usb_port >= CAVIUM_MAX_USB_INSTANCES) {
        printf("USB port must be less then %d", usb_port);
        return -1;
    }
    USB_INTERFACE* RootHubIf = (USB_INTERFACE *)usb_global_data[node][usb_port].root_if ;
    if (NULL == RootHubIf) {
        printf("node %d usb_port %d have not been initialized\n",
               node, usb_port);
        return -1;
    }
    unsigned Index;
    for (Index = 0; Index < RootHubIf->NumOfPort; Index++) {
        MT_DEBUG("Polling n:%d usb:%d port %d\n",  node, usb_port,Index);
        /* UsbEnumeratePort (RootHubIf, Index); */
        /* UsbEnumer.c:UsbEnumeratePort with Root api plugged in */
        {
            /* Inputs */
            USB_INTERFACE* HubIf = RootHubIf;
            UINT8 Port = Index;
            /* --- */
            EFI_USB_PORT_STATUS     PortState;
            /* EFI_STATUS              Status; */
            USB_DEVICE              *Child;
            USB_BUS* UsbBus = RootHubIf->Device->Bus;
            { 
                UsbBus->Usb2Hc->GetRootHubPortStatus(UsbBus->Usb2Hc, Port, &PortState);
                if (PortState.PortStatus || PortState.PortChangeStatus) {
                    MT_DEBUG("N:%d P:%d I:%d PS:%04x PCS:%04x\n", node, usb_port, Port, PortState.PortStatus , PortState.PortChangeStatus);
                }
            }
            if ((PortState.PortChangeStatus & (USB_PORT_STAT_C_CONNECTION | USB_PORT_STAT_C_ENABLE | USB_PORT_STAT_C_OVERCURRENT | USB_PORT_STAT_C_RESET)) == 0) {
                /* return EFI_SUCCESS; */ continue;
            }
            
            if (USB_BIT_IS_SET (PortState.PortChangeStatus, USB_PORT_STAT_C_OVERCURRENT)) {     
                
                if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_OVERCURRENT)) {
                    //
                    // Case1:
                    //   Both OverCurrent and OverCurrentChange set, means over current occurs, 
                    //   which probably is caused by short circuit. It has to wait system hardware
                    //   to perform recovery.
                    //
                    DEBUG (( EFI_D_ERROR, "UsbEnumeratePort: Critical Over Current\n", Port));
                    return EFI_DEVICE_ERROR;
                    
                } 
                //
                // Case2:
                //   Only OverCurrentChange set, means system has been recoveried from 
                //   over current. As a result, all ports are nearly power-off, so
                //   it's necessary to detach and enumerate all ports again. 
                //
                DEBUG (( EFI_D_ERROR, "UsbEnumeratePort: 2.0 device Recovery Over Current\n", Port)); 
            }
            if (USB_BIT_IS_SET (PortState.PortChangeStatus, USB_PORT_STAT_C_ENABLE)) {  
                //
                // Case3:
                //   1.1 roothub port reg doesn't reflect over-current state, while its counterpart
                //   on 2.0 roothub does. When over-current has influence on 1.1 device, the port 
                //   would be disabled, so it's also necessary to detach and enumerate again.
                //
                DEBUG (( EFI_D_ERROR, "UsbEnumeratePort: 1.1 device Recovery Over Current\n", Port));
            }
            if (USB_BIT_IS_SET (PortState.PortChangeStatus, USB_PORT_STAT_C_CONNECTION)) {
                //
                // Case4:
                //   Device connected or disconnected normally. 
                //
                DEBUG ((EFI_D_INFO, "UsbEnumeratePort: Device Connect/Disconnect Normally\n", Port));
            }
            Child = UsbFindChild (HubIf, Port);
            
            if (Child != NULL) {
                DEBUG (( EFI_D_INFO, "UsbEnumeratePort: device at port %d removed from root hub %p\n", Port, HubIf));
                UsbRemoveDevice (Child);
                MT_DEBUG("Removed device at %p %p : %d\n", HubIf, Child, Port);
            }

            if (USB_BIT_IS_SET (PortState.PortStatus, USB_PORT_STAT_CONNECTION)) {
                //
                // Now, new device connected, enumerate and configure the device 
                //
                DEBUG (( EFI_D_INFO, "UsbEnumeratePort: new device connected at port %d\n", Port));
                 MT_DEBUG("Adding new device at %p : %d\n", HubIf, Port);
                 //--->               Status = UsbEnumerateNewDev (HubIf, Port);
                
            } else {
                DEBUG (( EFI_D_INFO, "UsbEnumeratePort: device disconnected event on port %d\n", Port));
            }
            UsbBus->Usb2Hc->GetRootHubPortStatus(UsbBus->Usb2Hc, Port, &PortState);
            const USB_CHANGE_FEATURE_MAP  mRootHubFeatureMap[] = {
                {USB_PORT_STAT_C_CONNECTION,  EfiUsbPortConnectChange},
                {USB_PORT_STAT_C_ENABLE,      EfiUsbPortEnableChange},
                {USB_PORT_STAT_C_SUSPEND,     EfiUsbPortSuspendChange},
                {USB_PORT_STAT_C_OVERCURRENT, EfiUsbPortOverCurrentChange},
                {USB_PORT_STAT_C_RESET,       EfiUsbPortResetChange},
            };

            for (unsigned j = 0; j < ARRAY_SIZE( mRootHubFeatureMap);j++) {
                if (USB_BIT_IS_SET (PortState.PortChangeStatus,mRootHubFeatureMap[j].ChangedBit)) 
                  UsbBus->Usb2Hc->ClearRootHubPortFeature(UsbBus->Usb2Hc, Port, 
                                                          (EFI_USB_PORT_FEATURE) mRootHubFeatureMap[j].Feature);
            }
        }
    }
    return 0;
}

