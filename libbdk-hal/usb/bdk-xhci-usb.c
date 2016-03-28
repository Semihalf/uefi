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
#include "Xhci.h"
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
/**
Internal helper routines
*/
#define CVM_XHCI_OP_TIMEOUT (1000 * 1000) /* 1000 milliseconds */
/*
 * Reset hxci host controller
 * @param node       Node 
 * @param usb_port   Usb port
 *
 * @return Zero on success, non zero on failure
 */
static int halt_xhc(bdk_node_t node,int usb_port)
{
    BDK_CSR_MODIFY(c,node,BDK_USBHX_UAHC_USBCMD(usb_port),
                   c.s.r_s = 0;);
    return BDK_CSR_WAIT_FOR_FIELD(node,BDK_USBHX_UAHC_USBSTS(usb_port), hch, == ,1, CVM_XHCI_OP_TIMEOUT); 
}

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
    int rc = 0;
    xhci_t *thisHC = usb_global_data[node][usb_port].xhci_priv;
    if (thisHC) {
        // If host controller is not halted, halt it.
        if (!bdk_xhc_halted(node,usb_port)) {
            halt_xhc(node,usb_port);
        }
        // Reset Host controller
        BDK_CSR_MODIFY(c,node,BDK_USBHX_UAHC_USBCMD(usb_port),c.s.hcrst=1;);
        rc = BDK_CSR_WAIT_FOR_FIELD(node, BDK_USBHX_UAHC_USBCMD(usb_port), hcrst, == , 0,CVM_XHCI_OP_TIMEOUT);
        if (rc) {
            bdk_error("USB%d - timeout waiting for controller reset\n", usb_port);
            rc = -2 ;
            goto out;
        }
        // Wait for USBSTS.CNR == 0
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_USBHX_UAHC_USBSTS(usb_port), cnr, ==, 0, 10000)) {
            bdk_error("USB%d - timeout waiting for controller ready\n", usb_port);
            rc = -3;
            goto out;
        }

        //-- TODO Free async transfers
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
    
    if (0 != xhciInitSched(thisHC)) {
        printf("Failed to initialize Scheduler for node %d usb_port %d\n",
               thisHC->node, thisHC->usb_port
            );
        rc = -4;
        goto out;
    }
    USB_INTERFACE *RootIf = usb_global_data[node][usb_port].root_if;
    USB_BUS *UsbBus = usb_global_data[node][usb_port].usb_bus;
    USB_DEVICE *RootHub = usb_global_data[node][usb_port].root_hub;
    if (NULL !=  RootIf) { free(RootIf); }
    if (NULL != UsbBus) { free(UsbBus);}
    if (NULL != RootHub) { free(RootHub);}

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
            RootIf->HubApi     = &mUsbRootHubApi;
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
        
        printf("RootIf@ 0x%p\nUsbBus@ 0x%p\nRootHub@ 0x%p\n",
               RootIf, UsbBus, RootHub);
    }   
    CAVIUM_NOTYET("Not yet enumerating at the end of init");
out:
    if (rc) 
        printf("%s exiting with rc %d\n", __FUNCTION__, rc);
    return rc;
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
    UsbRootHubEnumeration(0,RootHubIf);
    printf("Returned from  UsbRootHubEnumeration\n");
    return 0;
}

