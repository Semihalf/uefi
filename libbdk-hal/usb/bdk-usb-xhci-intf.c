/***********************license start***********************************
* Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
* reserved.
*
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*
*   * Neither the name of Cavium Inc. nor the names of
*     its contributors may be used to endorse or promote products
*     derived from this software without specific prior written
*     permission.
*
* This Software, including technical data, may be subject to U.S. export
* control laws, including the U.S. Export Administration Act and its
* associated regulations, and may be subject to export or import
* regulations in other countries.
*
* TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
* AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR
* WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
* TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
* REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
* DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
* OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
* PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT,
* QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK
* ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
***********************license end**************************************/

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
#include "UsbMass.h"
#include "UsbMassImpl.h"

static void async_request_monitor(int unused, void *ctl);

/*
** Bit masks for async monitor state
*/
typedef enum _ASYNC_MON_STATE {
    AM_Stop = 0x1, // user->async_mon request to stop
    AM_Stopped=0x2, // async_mon->user
    AM_Running = 0x4, // Bit is on while async mon is thread is running, off otherwise
} ASYNC_MON_STATE;

typedef struct usb_hc_descriptor_s {
    bdk_rlock_t xhci_lock;                  // Lock for xhci hardware instance
    volatile ASYNC_MON_STATE async_mon_state; // Async interrupt monitor state
    uint64_t root_hub_enum_timestamp;  // Timestamp of last root hub enumeration in BDK_CLOCK_TIME units
    uint64_t root_hub_poll_delta;      // Root hub poll interval in BDK_CLOCK_TIME units, keeping it here affords running async mon process on any node
    USB_BUS *usb_bus;                 // Pointer to usb_bus descriptor for root hub
    USB_DEVICE *root_hub;             // Pointer to hub descriptor for root hub
    USB_INTERFACE *root_if;           // Pointer to interface descriptor for root hub
    xhci_t *xhci_priv;                // Pointer for xhci hardware descriptor.
} usb_hc_descriptor_t;
/**
Internal helper routines
*/
#define CVM_XHCI_OP_TIMEOUT (1000 * 1000) /* 1000 milliseconds */

static usb_hc_descriptor_t usb_global_data[BDK_NUMA_MAX_NODES][CAVIUM_MAX_USB_INSTANCES];

void async_request_monitor(int unused, void *ctl)
{
    usb_hc_descriptor_t *p = (usb_hc_descriptor_t*)ctl;
    p->async_mon_state |= AM_Running;
    BDK_WMB;

    p->root_hub_poll_delta = USB_ROOTHUB_POLL_INTERVAL * bdk_clock_get_rate(bdk_numa_local(),BDK_CLOCK_TIME) / 1000000 ;
    p->root_hub_enum_timestamp = bdk_clock_get_count(BDK_CLOCK_TIME);
    while(1)
    {
        bdk_wait_usec(XHC_ASYNC_TIMER_INTERVAL);
        bdk_rlock_lock(&p->xhci_lock);
        if ((NULL == p->xhci_priv) ||  (p->async_mon_state & AM_Stop) ) {
            bdk_rlock_unlock(&p->xhci_lock);
            p->async_mon_state |= AM_Stopped;
            break;
        }
        uint64_t now =  bdk_clock_get_count(BDK_CLOCK_TIME);
        if ((now - p->root_hub_enum_timestamp) >= p->root_hub_poll_delta) {
            UsbRootHubEnumeration(0,(USB_INTERFACE *)p->root_if);
            p->root_hub_enum_timestamp = now;
        }
        XhcMonitorAsyncRequests(0,p->xhci_priv);
        bdk_rlock_unlock(&p->xhci_lock);
    }
    p->async_mon_state &= ~(AM_Stop | AM_Running);
    BDK_WMB;
}

const char* __bdk_usb_speed2token(const int speed)
{
    switch (speed) {
    case  EFI_USB_SPEED_SUPER:
        return "SuperSpeed";
    case EFI_USB_SPEED_HIGH:
        return "HighSpeed";
    case EFI_USB_SPEED_LOW:
        return "LowSpeed";
    case EFI_USB_SPEED_FULL:
        return "FullSpeed";
    default:
        return "??Speed";
    }
}

static void list_usb_interface(const USB_INTERFACE *UsbIf,const int tier, const int ifnum)
{
    char buf[128];
    USB_BUS    *Bus = UsbIf->Device->Bus;
    USB_DEVICE *Device;

    if (UsbIf->IsHub) {
        printf("%*sIf %2d Hub %d Ports\n",
               4*(tier+1),"",ifnum, UsbIf->NumOfPort);
    } else {
        int devIndex = UsbMassIfFind(UsbIf);
        if ( devIndex >= 0) {
            bdk_node_t if_node = 0;
            cvm_usbif2node(UsbIf, &if_node, NULL, NULL);
            snprintf(buf,sizeof(buf), "MassStorage => /dev/n%d.usb%d", if_node,devIndex);
        }
        else
            snprintf(buf,sizeof(buf),"Class %02x SubClass %02x Proto %02x",
                  UsbIf->IfSetting->Desc.InterfaceClass, UsbIf->IfSetting->Desc.InterfaceSubClass,
                     UsbIf->IfSetting->Desc.InterfaceProtocol);
        printf("%*sIf %2d %s\n",
               4*(tier+1),"", ifnum, buf);
    }
    if (UsbIf->IsHub) {
        // Order output by hub port number
        for(int port = 0; port < UsbIf->NumOfPort; port++) {
            for(unsigned ndx=1; ndx < Bus->MaxDevices; ndx++) {
                Device = Bus->Devices[ndx];

                if (Device == NULL) continue;
                if (Device->ParentAddr != UsbIf->Device->Address) continue;
                if (Device->ParentPort != port) continue;

                if (
                    ( Device->DevDesc->Desc.DeviceClass ||  Device->DevDesc->Desc.DeviceSubClass) &&
                    ((Device->DevDesc->Desc.DeviceClass != USB_HUB_CLASS_CODE) ||
                     (Device->DevDesc->Desc.DeviceSubClass !=  USB_HUB_SUBCLASS_CODE))
                    )
                {
                    snprintf(buf,sizeof(buf),"Class %02x SubClass %02x ",
                             Device->DevDesc->Desc.DeviceClass, Device->DevDesc->Desc.DeviceSubClass );
                } else {
                    buf[0] = '\0';
                }
                printf("%*s|__ Port %d Dev %d %sVendor 0x%04x Product 0x%04x %s\n",
                       4*tier,"",
                       Device->ParentPort,
                       Device->Address,
                       buf,
                       bdk_le16_to_cpu(Device->DevDesc->Desc.IdVendor),
                       bdk_le16_to_cpu(Device->DevDesc->Desc.IdProduct),
                       __bdk_usb_speed2token(Device->Speed)
                    );

                for(unsigned n=0; n < Device->NumOfInterface; n++) {
                    if (NULL == Device->Interfaces[n]) continue;
                    list_usb_interface(Device->Interfaces[n],Device->Tier,n);
                }
            }
        }
    }
}

/*
 * usb_check_node_and_port - verify that node and usb port combination is valid
 * @param node cavium node number
 * @param usb_port xhci instance on a node
 *
 * @return Zero	success
 * @return Non-Zero error
 **/
static int usb_check_node_and_port(bdk_node_t node, int usb_port)
{
    if (!bdk_numa_exists(node)) {
        printf("node %d does not exist", node);
        return -1;
    }
    if (usb_port >= CAVIUM_MAX_USB_INSTANCES) {
        printf("USB port must below then %d vs %d", CAVIUM_MAX_USB_INSTANCES, usb_port);
        return -1;
    }
    return 0;
}

/**
 * Print current USB topology discovered by enumeration
 *
 * @param node       Node
 * @param usb_port   Physical Port
 *
 * @return Zero on success, negative on error
 */
int bdk_usb_HCList(bdk_node_t node, int usb_port)
{
    char buf[64];

    if (0 > usb_check_node_and_port(node,usb_port)) return -1;

    usb_hc_descriptor_t *p = &usb_global_data[node][usb_port];
    if (p->usb_bus || p->root_hub||p->root_if || p->xhci_priv) {
        printf("Node %d PhysPort %d\n",node,usb_port);
        if (p->root_if) {
            USB_BUS *Bus = p->root_if->Device->Bus;
            USB_DEVICE              *Device;
            USB_INTERFACE           *UsbIf = p->root_if;
            int num_root_ports = p->xhci_priv->hcsparams1.s.maxports;

            printf("RootHub %d ports\n", num_root_ports);

            for(int port = 0; port < num_root_ports; port++) {
                bool portEmpty = true;

                for(unsigned ndx=1; ndx < Bus->MaxDevices; ndx++) {
                    Device = Bus->Devices[ndx];
                    if (Device &&
                        (Device->ParentAddr == p->root_if->Device->Address) &&
                        (port == Device->ParentPort)) {
                        portEmpty = false;
                        buf[0] = '\0';
                        if ((Device->DevDesc->Desc.DeviceClass == USB_HUB_CLASS_CODE) &&
                            (Device->DevDesc->Desc.DeviceSubClass ==  USB_HUB_SUBCLASS_CODE)) {
                        } else {
                            if (Device->DevDesc->Desc.DeviceClass || Device->DevDesc->Desc.DeviceSubClass) {
                                snprintf(buf, sizeof(buf) ,"Class %02x SubClass %02x ",
                                         Device->DevDesc->Desc.DeviceClass, Device->DevDesc->Desc.DeviceSubClass );
                            }
                        }
                        printf("|__ Port %d Dev %d %sVendor 0x%04x Product 0x%04x %s\n",
                               Device->ParentPort,
                               Device->Address,
                               buf,
                               bdk_le16_to_cpu(Device->DevDesc->Desc.IdVendor),
                               bdk_le16_to_cpu(Device->DevDesc->Desc.IdProduct),
                               __bdk_usb_speed2token(Device->Speed)
                            );

                        for(unsigned n=0; n < Device->NumOfInterface; n++) {
                            if (NULL == (UsbIf = Device->Interfaces[n])) continue;
                            list_usb_interface(Device->Interfaces[n], Device->Tier,n);
                        }
                    }
                }
                if (portEmpty) {
                    printf("|__ Port %d Empty\n",port);
                }
            }
        }
    } else {
        printf("Node %d PhysPort %d Host Controller is not initialized\n",node,usb_port);
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
    if (0 > usb_check_node_and_port(node,usb_port)) return -1;
    int rc = 0;
    xhci_t *thisHC = usb_global_data[node][usb_port].xhci_priv;
    if (thisHC) {
        printf("Initialization may happen only once\n");
        rc = -5;
        goto out;
    } else {
        thisHC = createUsbXHci(node,usb_port);
        if (thisHC == NULL) {
            rc = -3;
            goto out;
        }
        usb_global_data[node][usb_port].xhci_priv = thisHC;
        thisHC->xhci_lock = &usb_global_data[node][usb_port].xhci_lock;
    }

    if (0 != XhcInitSched(thisHC)) {
        printf("Failed to initialize Scheduler for node %d usb_port %d\n",
               thisHC->node, thisHC->usb_port
            );
        rc = -4;
        goto out;
    }
    USB_INTERFACE *RootIf = usb_global_data[node][usb_port].root_if;
    USB_BUS *UsbBus = usb_global_data[node][usb_port].usb_bus;
    USB_DEVICE *RootHub = usb_global_data[node][usb_port].root_hub;

    if (NULL !=  RootIf) { free(RootIf); RootIf = NULL;}
    if (NULL != UsbBus) {
        if (UsbBus->DevicePath) free( UsbBus->DevicePath);
        free(UsbBus);
        UsbBus = NULL;
    }
    if (NULL != RootHub) { free(RootHub); RootHub = NULL;}

    if (NULL == RootIf) {
        CONTROLLER_DEVICE_PATH *ctlPath;
        ctlPath = calloc(2,sizeof(*ctlPath));
        if (ctlPath) RootIf = calloc(1,sizeof(*RootIf));
        if (RootIf) UsbBus = calloc(1,sizeof(*UsbBus));
        if (UsbBus) RootHub = calloc(1,sizeof(*RootHub));
        if (!ctlPath || !RootIf || !UsbBus || !RootHub) {
            free(thisHC);
            if (ctlPath) free(ctlPath);
            if(RootIf) free(RootIf);
            if (UsbBus) free(UsbBus);
            if (RootHub) free(RootHub);
            usb_global_data[node][usb_port].root_if = NULL;
            usb_global_data[node][usb_port].usb_bus = NULL;
            usb_global_data[node][usb_port].root_hub = NULL;
            usb_global_data[node][usb_port].xhci_priv = NULL;
            printf("memory allocation failure\n");
            rc = -6;
            goto out;
        }

        ctlPath[0].Header.Type =  HARDWARE_DEVICE_PATH;
        ctlPath[0].Header.SubType = HW_CONTROLLER_DP;
        SetDevicePathNodeLength (&ctlPath[0].Header, sizeof (CONTROLLER_DEVICE_PATH));
        ctlPath[0].Controller = CAVIUM_NODE_PORT_TO_CONTROLLER(node,usb_port);
        SetDevicePathEndNode(&ctlPath[1].Header);

        /* UsbBus.c:UsbBusBuildProtocol */
        UsbBus->MaxDevices = 128;
        UsbBus->Usb2Hc = &thisHC->Usb2Hc;
        if (UsbBus->Usb2Hc->MajorRevision == 0x3) {
            UsbBus->MaxDevices = 256;
        }
        // We will reset at the end after hub is initialized
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

        mUsbRootHubApi.Init (RootIf);

        UsbBus->Devices[0] = RootHub;
        usb_global_data[node][usb_port].root_if = RootIf;
        usb_global_data[node][usb_port].usb_bus = UsbBus;
        usb_global_data[node][usb_port].root_hub = RootHub;
    }
    // This portion of init would be done at the end of driver init
    // - start xhci host controller hardware
    // - start thread which handles async interrupt transfers from subordinate hubs and root hub enumeration
    UsbHcReset (UsbBus, EFI_USB_HC_RESET_GLOBAL);
    UsbHcSetState (UsbBus, EfiUsbHcStateOperational);

    // Default stack is too small for async monitor - it issues callbacks into mass storage
#define _ASYNC_STACK_SIZE (6 * 1024)
    bdk_thread_create(node, 0, (bdk_thread_func_t)async_request_monitor, 0, &usb_global_data[node][usb_port], _ASYNC_STACK_SIZE);
#undef _ASYNC_STACK_SIZE

    // Wait for async thread to initialize - otherwise lua menus will not be right
    int count=1000;
    while((0 == (usb_global_data[node][usb_port].async_mon_state & AM_Running)) && (count)) {
        bdk_wait_usec(10*1000);
        count--;
    }
out:
    if (rc)
        bdk_warn("%s exiting with rc %d\n", __FUNCTION__, rc);
    return rc;
}

/**
 * Manually trigger root Hub enumeration pass
 *
 * @param node       Node to init
 * @param usb_port   Port to intialize
 *
 * @return Zero on success, negative on error
 */
int bdk_usb_HCPoll(bdk_node_t node, int usb_port){
    if (usb_check_node_and_port(node,usb_port)) return -1;

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
    if (usb_check_node_and_port(node,usb_port) ) return -1;

    usb_hc_descriptor_t *thisDesc  = &usb_global_data[node][usb_port];
    if (action == DO_QUERY) { /* State Inquiry */
        if (NULL == thisDesc->xhci_priv) return -1;
        return (thisDesc->async_mon_state & AM_Running ) ? 1 : 0;
    }

    if (NULL == thisDesc->xhci_priv) {
        printf("\n*** Initialize XHCI controller first ***\n");
        return -1;
    }
    if (!(thisDesc->async_mon_state & AM_Running)) { /* Polling needs to be started */
        UsbHcReset (thisDesc->usb_bus, EFI_USB_HC_RESET_GLOBAL);
        UsbHcSetState (thisDesc->usb_bus, EfiUsbHcStateOperational);

        bdk_thread_create(node, 0, (bdk_thread_func_t)async_request_monitor, 0, &usb_global_data[node][usb_port], 0);
        // Wait for polling to actually start, but not forever it matters only for LUA displays
        uint64_t done = bdk_clock_get_count(BDK_CLOCK_TIME) +
            5000 * XHC_1_MILLISECOND * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME) / 1000000;
        while( !(thisDesc->async_mon_state & AM_Running) &&
               (bdk_clock_get_count(BDK_CLOCK_TIME) < done) ) {
            bdk_thread_yield();
        }
        printf("\n*** USB-XHCI Polling have started ***\n");
        return 1;
    }
    /* Polling needs to stop */
    thisDesc->async_mon_state |= AM_Stop;
    BDK_WMB;
    // This may take a while - thread checks for stop requests only so often
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_TIME) +
        10000 * XHC_1_MILLISECOND * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME) / 1000000;
    while (( (thisDesc->async_mon_state & (AM_Running | AM_Stopped)) != AM_Stopped) &&
           (bdk_clock_get_count(BDK_CLOCK_TIME) < done) ) {
        bdk_thread_yield();
    }

    printf("\n*** USB-XHCI Polling have stopped ***\n");
    return 0;
}
