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
#include "UsbBus.h"
#include "UsbDesc.h"
#include "UsbHub.h"

static void async_request_monitor(int unused, void *ctl);

typedef struct usb_hc_descriptor_s {
    bdk_rlock_t xhci_lock;
    int async_mon_state;
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
static usb_hc_descriptor_t usb_global_data[BDK_NUMA_MAX_NODES][CAVIUM_MAX_USB_INSTANCES];

void async_request_monitor(int unused, void *ctl)
{
    usb_hc_descriptor_t *p = (usb_hc_descriptor_t*)ctl;
    int count = 0;
    p->async_mon_state |= 4;
    BDK_WMB;
    while(1)
    {
        bdk_wait_usec(XHC_ASYNC_TIMER_INTERVAL);
        bdk_rlock_lock(&p->xhci_lock);
        if ((NULL == p->xhci_priv) ||  (p->async_mon_state & 1) ) {
            p->async_mon_state |= 2;
            bdk_rlock_unlock(&p->xhci_lock);
            break;
        }
        count++;
        if (count == (100 * 1000)/XHC_ASYNC_TIMER_INTERVAL) {
            UsbRootHubEnumeration(0,(USB_INTERFACE *)p->root_if);
            count = 0;
        }
        XhcMonitorAsyncRequests(0,p->xhci_priv);
        bdk_rlock_unlock(&p->xhci_lock);
    }
    p->async_mon_state &= ~(1|4);
    BDK_WMB;
}



#define b2i(x) ( (x) ? 1 : 0)
static int devPathToText(CONST EFI_DEVICE_PATH_PROTOCOL* DevicePath, char *buf, int len) {
    char *p = buf;
    int l = len;
    if (NULL == buf) return 0;
    if (NULL == DevicePath) { l = snprintf(buf,len,"Null"); buf[len-1] = '\0'; return l;}
    EFI_DEVICE_PATH_PROTOCOL *Node;
    Node = (typeof(Node))DevicePath;
    int c;
    while(l>0 && !IsDevicePathEnd(Node)) {
        if (DevicePathType (Node) == HARDWARE_DEVICE_PATH) {
            if (DevicePathSubType(Node) == HW_CONTROLLER_DP ) {
                CONTROLLER_DEVICE_PATH *hwctl = (CONTROLLER_DEVICE_PATH*) Node;
                c = snprintf(p,l, "<HWCTL %08x(node:%d,port:%d)>",
                             hwctl->Controller,
                             (hwctl->Controller >>8) & 0xff,
                             hwctl->Controller & 0xff
                    );
            } else {
               c = snprintf(p,l, "<HW? ST:%x L:%x>",
                            DevicePathSubType(Node),
                            DevicePathNodeLength(Node)
                   );
            }
        } else if (DevicePathType (Node) == MESSAGING_DEVICE_PATH) {
            switch (DevicePathSubType(Node))
            {
            default:
                c =  snprintf(p,l,"<MSG? ST:%x L:%x>",
                              DevicePathSubType(Node),
                              DevicePathNodeLength(Node));
                break;
            case MSG_USB_DP:
                c = snprintf(p,l,"<USB(0x%x,0x%x)>",
                             ((USB_DEVICE_PATH*) Node)->ParentPortNumber,
                             ((USB_DEVICE_PATH*) Node)->InterfaceNumber);
                break;
            case MSG_USB_CLASS_DP: {
                USB_CLASS_DEVICE_PATH *UsbClass;
                UsbClass = (typeof(UsbClass)) Node;
                c = snprintf(p,l,"<USB Class:%x Subclass:%x Vendor:%x Product:%x Proto:%x>",
                             UsbClass->DeviceClass,
                             UsbClass->DeviceSubClass,
                             UsbClass->VendorId,
                             UsbClass->ProductId,
                             UsbClass->DeviceProtocol
                    );
            } break;
            case MSG_USB_WWID_DP: {
                  USB_WWID_DEVICE_PATH  *UsbWWId;
                  UsbWWId = (typeof(UsbWWId)) Node;
                  c =  snprintf(p,l,"<USB WWId  Vendor:%x Product:%x Iface %x>",
                                UsbWWId->VendorId,
                                UsbWWId->ProductId,
                                UsbWWId->InterfaceNumber
                      );
            } break;

            }
        } else {
            c = snprintf(p,l,"<?? T:%x ST:%x L:%x>", DevicePathType(Node), DevicePathSubType(Node), DevicePathNodeLength(Node));
        }
        //
        // Next device path node
        //
        l -= c;
        p += c;
        Node = NextDevicePathNode (Node);
    }
    if (0==l) buf[len-1] = '\0';

    return (p - buf);
}

static void list_usb_interface(const USB_INTERFACE *UsbIf,const int tier)
{
    char buf[240];
    USB_BUS *Bus = UsbIf->Device->Bus;
    USB_DEVICE              *Device;

    char *token =
        ((UsbIf->IfSetting->Desc.InterfaceClass ==  USB_HUB_CLASS_CODE) &&
         (UsbIf->IfSetting->Desc.InterfaceSubClass == USB_HUB_SUBCLASS_CODE)) ? "--" : "EP";

    devPathToText(UsbIf->DevicePath, buf, sizeof(buf));
    printf("%*s%02u-%s DevIf@%p IsHub %d IsManaged %d Ports:%d Class %02x SubClass %02x Proto %02x\n%*s.DevicePath:%s\n",
           2*tier,"", UsbIf->Device->Tier, token,
           UsbIf, b2i(UsbIf->IsHub), b2i(UsbIf->IsManaged), UsbIf->NumOfPort,
           UsbIf->IfSetting->Desc.InterfaceClass, UsbIf->IfSetting->Desc.InterfaceSubClass,
           UsbIf->IfSetting->Desc.InterfaceProtocol,
           2*tier+7,"",buf
        );

    for(unsigned ndx=1; ndx < Bus->MaxDevices; ndx++) {
        Device = Bus->Devices[ndx];
        if (Device == NULL) continue;
        if (Device->ParentAddr != UsbIf->Device->Address) continue;
        int usbclass, usbsubclass;
        if ( 0 == (usbclass =Device->DevDesc->Desc.DeviceClass) &&  0 == Device->DevDesc->Desc.DeviceSubClass) {
            usbclass = UsbIf->IfSetting->Desc.InterfaceClass;
            usbsubclass =  UsbIf->IfSetting->Desc.InterfaceSubClass;
        } else {
            usbsubclass = Device->DevDesc->Desc.DeviceSubClass;
        }
        printf("%*s#%02u Device@%p PP:%d PA:%d Tier:%d NumIf:%d DF:%d Class %02x SubClass %02x\n",
               2*tier,"", ndx, Device,
               Device->ParentPort, Device->ParentAddr,
               Device->Tier,Device->NumOfInterface,
               b2i(Device->DisconnectFail),
               usbclass, usbsubclass);
        for(unsigned n=0; n < Device->NumOfInterface; n++) {
            if (NULL == Device->Interfaces[n]) continue;
            list_usb_interface(Device->Interfaces[n],Device->Tier);
        }
   }
}

/**
 * Display current state of enumeration for USB XHCI
 *
 *
 * @return Zero	success
 * @return Non-Zero error
 **/
int bdk_usb_HCList()
{
    unsigned i,j;
    char buf[240];
    for (i=0;i<BDK_NUMA_MAX_NODES;i++) {
        for(j=0;j<CAVIUM_MAX_USB_INSTANCES;j++) {
            usb_hc_descriptor_t *p = &usb_global_data[i][j];
            if (p->usb_bus || p->root_hub||p->root_if || p->xhci_priv) {
                printf("N:%d P:%d Bus@%p Hub@%p If@%p Xhci@%p\n",
                       i,j,p->usb_bus, p->root_hub,p->root_if,p->xhci_priv);
                if (p->root_if) {
                    USB_BUS *Bus = p->root_if->Device->Bus;
                    USB_DEVICE              *Device;
                    USB_INTERFACE           *UsbIf = p->root_if;
                    devPathToText(UsbIf->DevicePath, buf, sizeof(buf));
                    printf("RootHub If@%p IsHub %d IsManaged %d Ports:%d DevicePath:%s\n",
                           UsbIf, b2i(UsbIf->IsHub), b2i(UsbIf->IsManaged), UsbIf->NumOfPort, buf );
                    for(unsigned ndx=1; ndx < Bus->MaxDevices; ndx++) {
                         Device = Bus->Devices[ndx];
                         if (Device && (Device->ParentAddr == p->root_if->Device->Address)) {
                             printf("R#%02u Device@%p Port:%d Tier:%d NumIf:%d DF:%d Class %02x SubClass %02x\n",
                                    ndx, Device, Device->ParentPort,Device->Tier,Device->NumOfInterface,
                                    b2i(Device->DisconnectFail),
                                    Device->DevDesc->Desc.DeviceClass, Device->DevDesc->Desc.DeviceSubClass );
                             for(unsigned n=0; n < Device->NumOfInterface; n++) {
                                 if (NULL == (UsbIf = Device->Interfaces[n])) continue;
                                 list_usb_interface(Device->Interfaces[n], Device->Tier);
                             }
                         }
                    }
                }
            }
        }
    }
    return 0;
}

/**
 * Initialize root hub USB XHCI root hub instance on a thunder node
 * Root hub has to be initialized prior to that
 *
 * @param node cavium node number
 * @param usb_port xhci instance on a node
 *
 * @return Zero	success
 * @return Non-Zero error
 **/
int bdk_usb_HCInit(bdk_node_t node, int usb_port)
{
    if ((0 == __bdk_is_dram_enabled(node)) || (0 == __bdk_is_dram_enabled(0))) {
       printf("DRAM-less configuration does not fit\n");
       return -1;
    }
    if ((unsigned int) node > BDK_NUMA_MAX_NODES) {
        printf("Node must be less then %d vs %d", BDK_NUMA_MAX_NODES, node);
        return -1;
    }
    if (usb_port >= CAVIUM_MAX_USB_INSTANCES) {
        printf("USB port must be less then %d vs %d", CAVIUM_MAX_USB_INSTANCES, usb_port);
        return -1;
    }
    int rc = 0;
    xhci_t *thisHC = usb_global_data[node][usb_port].xhci_priv;
    if (thisHC) {
        printf("Initialization may happen only once\n");
        rc = -5;
        goto out;
    } else {
        thisHC = createUsbXHci(node,usb_port);
        if (thisHC == NULL) {
            printf("failed to allocate device context\n");
            rc = -3;
            goto out;
        }
        usb_global_data[node][usb_port].xhci_priv = thisHC;
        thisHC->xhci_lock = &usb_global_data[node][usb_port].xhci_lock;
    }
#if 0
    printf("thisHC @%p\n",thisHC);
    printf("hcsparams1:%08lx\n",(unsigned long) thisHC->hcsparams1.u);
    printf("hcsparams2:%08lx\n",(unsigned long) thisHC->hcsparams2.u);
    printf("hccparams:%08lx\n",(unsigned long) thisHC->hccparams.u);
    printf("page size %d\nnode %d port %d\n", thisHC->PageSize,thisHC->node,thisHC->usb_port);
    printf("64 bit capability %d\n",thisHC->hccparams.s.ac64);
#endif
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
    if (NULL != UsbBus) {
        if (UsbBus->DevicePath) free( UsbBus->DevicePath);
        free(UsbBus);
    }
    if (NULL != RootHub) { free(RootHub);}

    if (NULL == RootIf) {
        CONTROLLER_DEVICE_PATH *ctlPath;
        ctlPath = calloc(2,sizeof(*ctlPath));
        ctlPath[0].Header.Type =  HARDWARE_DEVICE_PATH;
        ctlPath[0].Header.SubType = HW_CONTROLLER_DP;
        SetDevicePathNodeLength (&ctlPath[0].Header, sizeof (CONTROLLER_DEVICE_PATH));
        ctlPath[0].Controller = CAVIUM_NODE_PORT_TO_CONTROLLER(node,usb_port);
        SetDevicePathEndNode(&ctlPath[1].Header);

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
        UsbBusAddWantedUsbIoDP (&UsbBus->BusId, NULL);
        UsbBus->DevicePath = AppendDevicePath( UsbBus->DevicePath,(const void*)ctlPath);
        free(ctlPath);
        RootHub->Bus            = UsbBus;
        RootHub->NumOfInterface = 1;
        RootHub->Interfaces[0]  = RootIf;
        RootHub->Tier           = 0;
        /* RootIf->Signature       = USB_INTERFACE_SIGNATURE; */
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
            RootIf->HubNotify  =  UsbRootHubEnumeration;
            /*** */
        }
        UsbBus->Devices[0] = RootHub;

        usb_global_data[node][usb_port].root_if = RootIf;
        usb_global_data[node][usb_port].usb_bus = UsbBus;
        usb_global_data[node][usb_port].root_hub = RootHub;
    }
    bdk_thread_create(node, 0, (bdk_thread_func_t)async_request_monitor, 0, &usb_global_data[node][usb_port], 0);
    // Wait for async thread to initialize - otherwise lua menus will not be right
    int count=1000;
    while((0 == (usb_global_data[node][usb_port].async_mon_state & 4)) && (count)) {
        bdk_thread_yield();
        count--;
    }
out:
    if (rc)
        printf("%s exiting with rc %d\n", __FUNCTION__, rc);
    return rc;
}

/**
 * Trigger enumeration on USB XHCI root hub instance on a thunder node (normally timer driven)
 * Root hub has to be initialized prior to that
 *
 * @param node cavium node number
 * @param usb_port xhci instance on a node
 *
 * @return Zero	success
 * @return Non-Zero error
 **/
int bdk_usb_HCPoll(bdk_node_t node, int usb_port){
    if ((unsigned int) node > BDK_NUMA_MAX_NODES) {
        printf("Node must be less then %d vs %d", BDK_NUMA_MAX_NODES, node);
       return -1;
    }
    if (usb_port >= CAVIUM_MAX_USB_INSTANCES) {
        printf("USB port must be less then %d vs %d", CAVIUM_MAX_USB_INSTANCES, usb_port);
        return -1;

    }

    USB_INTERFACE* RootHubIf = (USB_INTERFACE *)usb_global_data[node][usb_port].root_if ;
    if (NULL == RootHubIf) {
        printf("\n** node %d usb_port %d have not been initialized\n",
               node, usb_port);
        return -1;
    }
    if (bdk_rlock_try_lock(&usb_global_data[node][usb_port].xhci_lock)) {
        printf("N:%d P:%d is locked\n", node, usb_port);
        return 0;
    }
    UsbRootHubEnumeration(0,RootHubIf);
    bdk_rlock_unlock(&usb_global_data[node][usb_port].xhci_lock);

    return 0;
}

/**
 * Query or toggle polling for Root Hub Enumeration and async interrupt
 * transfers for XHCI.
 *
 * @param node cavium node number
 * @param usb_port xhci instance on a node
 * @param action DO_QUERY: query DO_TOGGLE: toggle state
 *
 * @return Zero	polling is off
 * @return Positive polling is on
 * @return Negative error
 **/
int bdk_usb_togglePoll(bdk_node_t node, int usb_port, const bdk_usb_toggleReq_t action)
{
   if ((unsigned int) node > BDK_NUMA_MAX_NODES) {
        printf("Node must be less then %d vs %d", BDK_NUMA_MAX_NODES, node);
       return -1;
    }
    if (usb_port >= CAVIUM_MAX_USB_INSTANCES) {
        printf("USB port must be less then %d vs %d", CAVIUM_MAX_USB_INSTANCES, usb_port);
        return -1;

    }

    usb_hc_descriptor_t *thisDesc  = &usb_global_data[node][usb_port];
    if (action == DO_QUERY) { /* State Inquiry */
        if (NULL == thisDesc->xhci_priv) return -1;
        return (thisDesc->async_mon_state & 4 ) ? 1 : 0;
    }

    if (NULL == thisDesc->xhci_priv) {
        printf("\n*** Initialize XHCI controller first ***\n");
        return -1;
    }
    if (!(thisDesc->async_mon_state & 4)) { /* Polling needs to be started */
        bdk_thread_create(node, 0, (bdk_thread_func_t)async_request_monitor, 0, &usb_global_data[node][usb_port], 0);
        while( !(thisDesc->async_mon_state & 4)) {
            bdk_thread_yield();
            bdk_wait_usec(100 * 1000);
        }
        printf("\n*** USB-XHCI Polling have started ***\n");
        return 1;
    }
    /* Polling needs to stop */
    thisDesc->async_mon_state |= 1;
    BDK_WMB;
    while( (thisDesc->async_mon_state & 6) != 2) {
        bdk_thread_yield();
        bdk_wait_usec(100 * 1000);
    }
    printf("\n*** USB-XHCI Polling have stopped ***\n");
    return 0;


}
