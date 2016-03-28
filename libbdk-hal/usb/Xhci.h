/** @file

  XHCI support main include file

Copyright (c) 2011 - 2015, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __BDK_XHCI_REG_H__
#define __BDK_XHCI_REG_H__
#include <bdk.h>
typedef struct xhci_s USB_XHCI_INSTANCE;
typedef struct _USB_DEV_CONTEXT USB_DEV_CONTEXT;
#include "usb-xhci-compat.h"
//mt20160315 - both usb and usb2 need to be included, usb must be first
// had to hack some because they repeat definitions verbatim
//#include "usb-industry.h" // USB3
#include <Protocol/Usb2HostController.h>
#include "usb2-industry.h" // USB2
#include "XhciReg.h"
#include "XhciSched.h" // Transfer scheduling routines
#if ! defined(DEBUG)
#define DEBUG(x...)
#endif

#define CAVIUM_MAX_USB_INSTANCES 2
//
// The unit is microsecond, setting it as 1us.
//
#define XHC_1_MICROSECOND            (1)
//
// The unit is microsecond, setting it as 1ms.
//
#define XHC_1_MILLISECOND            (1000)
//
// XHC generic timeout experience values.
// The unit is millisecond, setting it as 10s.
//
#define XHC_GENERIC_TIMEOUT          (10 * 1000)
//
// XHC reset timeout experience values.
// The unit is millisecond, setting it as 1s.
//
#define XHC_RESET_TIMEOUT            (1000)
//
// XHC async transfer timer interval, set by experience.
// The unit is 100us, takes 1ms as interval.
//
#define XHC_ASYNC_TIMER_INTERVAL     EFI_TIMER_PERIOD_MILLISECONDS(1)

#if defined(notdef_cavium)
//
// XHC raises TPL to TPL_NOTIFY to serialize all its operations
// to protect shared data structures.
//
#define XHC_TPL                      TPL_NOTIFY
#else
// Purposely removed TPL  - bdk does not have that
#endif

#define CMD_RING_TRB_NUMBER          0x100
#define TR_RING_TRB_NUMBER           0x100
#define ERST_NUMBER                  0x01
#define EVENT_RING_TRB_NUMBER        0x200

#define CMD_INTER                    0
#define CTRL_INTER                   1
#define BULK_INTER                   2
#define INT_INTER                    3
#define INT_INTER_ASYNC              4

//
// Iterate through the doule linked list. This is delete-safe.
// Don't touch NextEntry
//
#define EFI_LIST_FOR_EACH_SAFE(Entry, NextEntry, ListHead) \
  for (Entry = (ListHead)->ForwardLink, NextEntry = Entry->ForwardLink;\
      Entry != (ListHead); Entry = NextEntry, NextEntry = Entry->ForwardLink)

#define EFI_LIST_CONTAINER(Entry, Type, Field) BASE_CR(Entry, Type, Field)
#define BASE_CR(Record, TYPE, Field)  ((TYPE *) ((CHAR8 *) (Record) - (CHAR8 *) &(((TYPE *) 0)->Field)))
#define XHC_FROM_THIS(a)               BASE_CR(a,USB_XHCI_INSTANCE,Usb2Hc)  /* CR(a, USB_XHCI_INSTANCE, Usb2Hc, XHCI_INSTANCE_SIG)*/

#define XHC_LOW_32BIT(Addr64)          ((UINT32)(((UINTN)(Addr64)) & 0xFFFFFFFFU))
#define XHC_HIGH_32BIT(Addr64)         ((UINT32)(((UINTN)(Addr64)>>32) & 0xFFFFFFFFU))
#define XHC_BIT_IS_SET(Data, Bit)      ((BOOLEAN)(((Data) & (Bit)) == (Bit)))
#define XHCI_IS_DATAIN(EndpointAddr)   XHC_BIT_IS_SET((EndpointAddr), 0x80)

static inline bool bdk_xhc_halted(bdk_node_t node,int usb_port) __attribute__((always_inline));
static inline bool bdk_xhc_halted(bdk_node_t node,int usb_port)
{
    BDK_CSR_INIT(usbsts,node,BDK_USBHX_UAHC_USBSTS(usb_port));
    return 1 == usbsts.s.hch;
}

#define CAVIUM_XHCI_ALIGN 512
struct _USB_DEV_CONTEXT {
  //
  // Whether this entry in UsbDevContext array is used or not.
  //
  BOOLEAN                   Enabled;
  //
  // The slot id assigned to the new device through XHCI's Enable_Slot cmd.
  //
  UINT8                     SlotId;
  //
  // The route string presented an attached usb device.
  //
  USB_DEV_ROUTE             RouteString;
  //
  // The route string of parent device if it exists. Otherwise it's zero.
  //
  USB_DEV_ROUTE             ParentRouteString;
  //
  // The actual device address assigned by XHCI through Address_Device command.
  //
  UINT8                     XhciDevAddr;
  //
  // The requested device address from UsbBus driver through Set_Address standard usb request.
  // As XHCI spec replaces this request with Address_Device command, we have to record the
  // requested device address and establish a mapping relationship with the actual device address.
  // Then UsbBus driver just need to be aware of the requested device address to access usb device
  // through EFI_USB2_HC_PROTOCOL. Xhci driver would be responsible for translating it to actual
  // device address and access the actual device.
  //
  UINT8                     BusDevAddr;
  //
  // The pointer to the input device context.
  //
  VOID                      *InputContext;
  //
  // The pointer to the output device context.
  //
  VOID                      *OutputContext;
  //
  // The transfer queue for every endpoint.
  //
  VOID                      *EndpointTransferRing[31];
  //
  // The device descriptor which is stored to support XHCI's Evaluate_Context cmd.
  //
  EFI_USB_DEVICE_DESCRIPTOR DevDesc;
  //
  // As a usb device may include multiple configuration descriptors, we dynamically allocate an array
  // to store them.
  // Note that every configuration descriptor stored here includes those lower level descriptors,
  // such as Interface descriptor, Endpoint descriptor, and so on.
  // These information is used to support XHCI's Config_Endpoint cmd.
  //
  EFI_USB_CONFIG_DESCRIPTOR **ConfDesc;
  //
  // A device has an active Configuration.
  //
  UINT8                     ActiveConfiguration;
  //
  // Every interface has an active AlternateSetting.
  //
  UINT8                     *ActiveAlternateSetting;
};

struct xhci_s {
    EFI_USB2_HC_PROTOCOL      Usb2Hc;
 
    // Cmd Transfer Ring
    TRANSFER_RING             CmdRing;
    // EventRing
    EVENT_RING                EventRing;
//    void* msixPBA;
    LIST_ENTRY                AsyncIntTransfers;
    uint64_t* ScratchBuf;	// ...
    void* ScratchMap;		// ...
    uint64_t* DCBAA;
    BDK_CSR_DEFINE(hcsparams1,BDK_USBHX_UAHC_HCSPARAMS1(0));
    BDK_CSR_DEFINE(hcsparams2,BDK_USBHX_UAHC_HCSPARAMS2(0));
    BDK_CSR_DEFINE(hccparams,BDK_USBHX_UAHC_HCCPARAMS(0));
    uint32_t PageSize;
    uint32_t MaxSlotsEn;
    uint32_t MaxScratchPadBufs;

    //
    // Store device contexts managed by XHCI instance
    // The array supports up to 255 devices, entry 0 is reserved and should not be used.
    //
    USB_DEV_CONTEXT           UsbDevContext[256];
    // cavium node and port of the physical root hub
    bdk_node_t node;
    int usb_port;
};

typedef struct xhci_s xhci_t;

/**
 * Initialize hxci host controller
 * @param node       Node to init
 * @param usb_port   Port to intialize
 *
 * @return Pointer to XHCI instance on success, Zero on failure
 */
xhci_t* createUsbXHci(bdk_node_t node, int usb_port);

/**
  Clears a feature for the specified root hub port.

  @param  xhc                   A pointer to the EFI_USB2_HC_PROTOCOL instance.
  @param  PortNumber            Specifies the root hub port whose feature is
                                requested to be cleared.
  @param  PortFeature           Indicates the feature selector associated with the
                                feature clear request.

  @retval  Zero                 The feature specified by PortFeature was cleared
                                for the USB root hub port specified by PortNumber.
  @retval non-Zero              Error


**/
int xhcClearRootHubPortFeature (
    xhci_t *xhc,
  unsigned PortNumber,
  const EFI_USB_PORT_FEATURE  PortFeature
  );

EFI_STATUS
EFIAPI
XhcClearRootHubPortFeature (
  IN EFI_USB2_HC_PROTOCOL  *This,
  IN UINT8                 PortNumber,
  IN EFI_USB_PORT_FEATURE  PortFeature
  );
/**
  Sets a feature for the specified root hub port.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  PortNumber            Root hub port to set.
  @param  PortFeature           Feature to set.

  @retval EFI_SUCCESS           The feature specified by PortFeature was set.
  @retval EFI_INVALID_PARAMETER PortNumber is invalid or PortFeature is invalid.
  @retval EFI_DEVICE_ERROR      Can't read register.

**/
EFI_STATUS
EFIAPI
XhcSetRootHubPortFeature (
  IN EFI_USB2_HC_PROTOCOL  *This,
  IN UINT8                 PortNumber,
  IN EFI_USB_PORT_FEATURE  PortFeature
  );

/**
  Retrieves the capability of root hub ports.

  @param  This                  The EFI_USB2_HC_PROTOCOL instance.
  @param  MaxSpeed              Max speed supported by the controller.
  @param  PortNumber            Number of the root hub ports.
  @param  Is64BitCapable        Whether the controller supports 64-bit memory
                                addressing.

  @retval EFI_SUCCESS           Host controller capability were retrieved successfully.
  @retval EFI_INVALID_PARAMETER Either of the three capability pointer is NULL.

**/
EFI_STATUS
EFIAPI
XhcGetCapability (
  IN  EFI_USB2_HC_PROTOCOL  *This,
  OUT UINT8                 *MaxSpeed,
  OUT UINT8                 *PortNumber,
  OUT UINT8                 *Is64BitCapable
  );
/**
  Provides software reset for the USB host controller.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  Attributes            A bit mask of the reset operation to perform.

  @retval EFI_SUCCESS           The reset operation succeeded.
  @retval EFI_INVALID_PARAMETER Attributes is not valid.
  @retval EFI_UNSUPPOURTED      The type of reset specified by Attributes is
                                not currently supported by the host controller.
  @retval EFI_DEVICE_ERROR      Host controller isn't halted to reset.

**/
EFI_STATUS
EFIAPI
XhcReset (
  IN EFI_USB2_HC_PROTOCOL  *This,
  IN UINT16                Attributes
  );

/**
  Retrieves the current status of a USB root hub port.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  PortNumber            The root hub port to retrieve the state from.
                                This value is zero-based.
  @param  PortStatus            Variable to receive the port state.

  @retval EFI_SUCCESS           The status of the USB root hub port specified.
                                by PortNumber was returned in PortStatus.
  @retval EFI_INVALID_PARAMETER PortNumber is invalid.
  @retval EFI_DEVICE_ERROR      Can't read register.

**/
EFI_STATUS
EFIAPI
XhcGetRootHubPortStatus (
  IN  EFI_USB2_HC_PROTOCOL  *This,
  IN  UINT8                 PortNumber,
  OUT EFI_USB_PORT_STATUS   *PortStatus
    );

/**
  Retrieve the current state of the USB host controller.

  @param  This                   This EFI_USB2_HC_PROTOCOL instance.
  @param  State                  Variable to return the current host controller
                                 state.

  @retval EFI_SUCCESS            Host controller state was returned in State.
  @retval EFI_INVALID_PARAMETER  State is NULL.
  @retval EFI_DEVICE_ERROR       An error was encountered while attempting to
                                 retrieve the host controller's current state.

**/
EFI_STATUS
EFIAPI
XhcGetState (
  IN  EFI_USB2_HC_PROTOCOL  *This,
  OUT EFI_USB_HC_STATE      *State
  );

/**
  Sets the USB host controller to a specific state.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  State                 The state of the host controller that will be set.

  @retval EFI_SUCCESS           The USB host controller was successfully placed
                                in the state specified by State.
  @retval EFI_INVALID_PARAMETER State is invalid.
  @retval EFI_DEVICE_ERROR      Failed to set the state due to device error.

**/
EFI_STATUS
EFIAPI
XhcSetState (
  IN EFI_USB2_HC_PROTOCOL  *This,
  IN EFI_USB_HC_STATE      State
  );

EFI_STATUS
EFIAPI
XhcControlTransfer (
  IN     EFI_USB2_HC_PROTOCOL                *This,
  IN     UINT8                               DeviceAddress,
  IN     UINT8                               DeviceSpeed,
  IN     UINTN                               MaximumPacketLength,
  IN     EFI_USB_DEVICE_REQUEST              *Request,
  IN     EFI_USB_DATA_DIRECTION              TransferDirection,
  IN OUT VOID                                *Data,
  IN OUT UINTN                               *DataLength,
  IN     UINTN                               Timeout,
  IN     EFI_USB2_HC_TRANSACTION_TRANSLATOR  *Translator,
  OUT    UINT32                              *TransferResult
  );

/**
  Submits bulk transfer to a bulk endpoint of a USB device.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  DeviceAddress         Target device address.
  @param  EndPointAddress       Endpoint number and its direction in bit 7.
  @param  DeviceSpeed           Device speed, Low speed device doesn't support bulk
                                transfer.
  @param  MaximumPacketLength   Maximum packet size the endpoint is capable of
                                sending or receiving.
  @param  DataBuffersNumber     Number of data buffers prepared for the transfer.
  @param  Data                  Array of pointers to the buffers of data to transmit
                                from or receive into.
  @param  DataLength            The lenght of the data buffer.
  @param  DataToggle            On input, the initial data toggle for the transfer;
                                On output, it is updated to to next data toggle to
                                use of the subsequent bulk transfer.
  @param  Timeout               Indicates the maximum time, in millisecond, which
                                the transfer is allowed to complete.
  @param  Translator            A pointr to the transaction translator data.
  @param  TransferResult        A pointer to the detailed result information of the
                                bulk transfer.

  @retval EFI_SUCCESS           The transfer was completed successfully.
  @retval EFI_OUT_OF_RESOURCES  The transfer failed due to lack of resource.
  @retval EFI_INVALID_PARAMETER Some parameters are invalid.
  @retval EFI_TIMEOUT           The transfer failed due to timeout.
  @retval EFI_DEVICE_ERROR      The transfer failed due to host controller error.

**/
EFI_STATUS
EFIAPI
XhcBulkTransfer (
  IN     EFI_USB2_HC_PROTOCOL                *This,
  IN     UINT8                               DeviceAddress,
  IN     UINT8                               EndPointAddress,
  IN     UINT8                               DeviceSpeed,
  IN     UINTN                               MaximumPacketLength,
  IN     UINT8                               DataBuffersNumber,
  IN OUT VOID                                *Data[EFI_USB_MAX_BULK_BUFFER_NUM],
  IN OUT UINTN                               *DataLength,
  IN OUT UINT8                               *DataToggle,
  IN     UINTN                               Timeout,
  IN     EFI_USB2_HC_TRANSACTION_TRANSLATOR  *Translator,
  OUT    UINT32                              *TransferResult
  );

/**
  Submits an asynchronous interrupt transfer to an
  interrupt endpoint of a USB device.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  DeviceAddress         Target device address.
  @param  EndPointAddress       Endpoint number and its direction encoded in bit 7
  @param  DeviceSpeed           Indicates device speed.
  @param  MaximumPacketLength   Maximum packet size the target endpoint is capable
  @param  IsNewTransfer         If TRUE, to submit an new asynchronous interrupt
                                transfer If FALSE, to remove the specified
                                asynchronous interrupt.
  @param  DataToggle            On input, the initial data toggle to use; on output,
                                it is updated to indicate the next data toggle.
  @param  PollingInterval       The he interval, in milliseconds, that the transfer
                                is polled.
  @param  DataLength            The length of data to receive at the rate specified
                                by  PollingInterval.
  @param  Translator            Transaction translator to use.
  @param  CallBackFunction      Function to call at the rate specified by
                                PollingInterval.
  @param  Context               Context to CallBackFunction.

  @retval EFI_SUCCESS           The request has been successfully submitted or canceled.
  @retval EFI_INVALID_PARAMETER Some parameters are invalid.
  @retval EFI_OUT_OF_RESOURCES  The request failed due to a lack of resources.
  @retval EFI_DEVICE_ERROR      The transfer failed due to host controller error.

**/
EFI_STATUS
EFIAPI
XhcAsyncInterruptTransfer (
  IN     EFI_USB2_HC_PROTOCOL                *This,
  IN     UINT8                               DeviceAddress,
  IN     UINT8                               EndPointAddress,
  IN     UINT8                               DeviceSpeed,
  IN     UINTN                               MaximumPacketLength,
  IN     BOOLEAN                             IsNewTransfer,
  IN OUT UINT8                               *DataToggle,
  IN     UINTN                               PollingInterval,
  IN     UINTN                               DataLength,
  IN     EFI_USB2_HC_TRANSACTION_TRANSLATOR  *Translator,
  IN     EFI_ASYNC_USB_TRANSFER_CALLBACK     CallBackFunction,
  IN     VOID                                *Context OPTIONAL
  );

/**
  Submits synchronous interrupt transfer to an interrupt endpoint
  of a USB device.

  @param  This                  This EFI_USB2_HC_PROTOCOL instance.
  @param  DeviceAddress         Target device address.
  @param  EndPointAddress       Endpoint number and its direction encoded in bit 7
  @param  DeviceSpeed           Indicates device speed.
  @param  MaximumPacketLength   Maximum packet size the target endpoint is capable
                                of sending or receiving.
  @param  Data                  Buffer of data that will be transmitted to  USB
                                device or received from USB device.
  @param  DataLength            On input, the size, in bytes, of the data buffer; On
                                output, the number of bytes transferred.
  @param  DataToggle            On input, the initial data toggle to use; on output,
                                it is updated to indicate the next data toggle.
  @param  Timeout               Maximum time, in second, to complete.
  @param  Translator            Transaction translator to use.
  @param  TransferResult        Variable to receive the transfer result.

  @return EFI_SUCCESS           The transfer was completed successfully.
  @return EFI_OUT_OF_RESOURCES  The transfer failed due to lack of resource.
  @return EFI_INVALID_PARAMETER Some parameters are invalid.
  @return EFI_TIMEOUT           The transfer failed due to timeout.
  @return EFI_DEVICE_ERROR      The failed due to host controller or device error

**/
EFI_STATUS
EFIAPI
XhcSyncInterruptTransfer (
  IN     EFI_USB2_HC_PROTOCOL                *This,
  IN     UINT8                               DeviceAddress,
  IN     UINT8                               EndPointAddress,
  IN     UINT8                               DeviceSpeed,
  IN     UINTN                               MaximumPacketLength,
  IN OUT VOID                                *Data,
  IN OUT UINTN                               *DataLength,
  IN OUT UINT8                               *DataToggle,
  IN     UINTN                               Timeout,
  IN     EFI_USB2_HC_TRANSACTION_TRANSLATOR  *Translator,
  OUT    UINT32                              *TransferResult
  );

/**
  Submits isochronous transfer to a target USB device.

  @param  This                 This EFI_USB2_HC_PROTOCOL instance.
  @param  DeviceAddress        Target device address.
  @param  EndPointAddress      End point address with its direction.
  @param  DeviceSpeed          Device speed, Low speed device doesn't support this
                               type.
  @param  MaximumPacketLength  Maximum packet size that the endpoint is capable of
                               sending or receiving.
  @param  DataBuffersNumber    Number of data buffers prepared for the transfer.
  @param  Data                 Array of pointers to the buffers of data that will
                               be transmitted to USB device or received from USB
                               device.
  @param  DataLength           The size, in bytes, of the data buffer.
  @param  Translator           Transaction translator to use.
  @param  TransferResult       Variable to receive the transfer result.

  @return EFI_UNSUPPORTED      Isochronous transfer is unsupported.

**/
EFI_STATUS
EFIAPI
XhcIsochronousTransfer (
  IN     EFI_USB2_HC_PROTOCOL                *This,
  IN     UINT8                               DeviceAddress,
  IN     UINT8                               EndPointAddress,
  IN     UINT8                               DeviceSpeed,
  IN     UINTN                               MaximumPacketLength,
  IN     UINT8                               DataBuffersNumber,
  IN OUT VOID                                *Data[EFI_USB_MAX_ISO_BUFFER_NUM],
  IN     UINTN                               DataLength,
  IN     EFI_USB2_HC_TRANSACTION_TRANSLATOR  *Translator,
  OUT    UINT32                              *TransferResult
  );

/**
  Submits Async isochronous transfer to a target USB device.

  @param  This                 This EFI_USB2_HC_PROTOCOL instance.
  @param  DeviceAddress        Target device address.
  @param  EndPointAddress      End point address with its direction.
  @param  DeviceSpeed          Device speed, Low speed device doesn't support this
                               type.
  @param  MaximumPacketLength  Maximum packet size that the endpoint is capable of
                               sending or receiving.
  @param  DataBuffersNumber    Number of data buffers prepared for the transfer.
  @param  Data                 Array of pointers to the buffers of data that will
                               be transmitted to USB device or received from USB
                               device.
  @param  DataLength           The size, in bytes, of the data buffer.
  @param  Translator           Transaction translator to use.
  @param  IsochronousCallBack  Function to be called when the transfer complete.
  @param  Context              Context passed to the call back function as
                               parameter.

  @return EFI_UNSUPPORTED      Isochronous transfer isn't supported.

**/
EFI_STATUS
EFIAPI
XhcAsyncIsochronousTransfer (
  IN     EFI_USB2_HC_PROTOCOL                *This,
  IN     UINT8                               DeviceAddress,
  IN     UINT8                               EndPointAddress,
  IN     UINT8                               DeviceSpeed,
  IN     UINTN                               MaximumPacketLength,
  IN     UINT8                               DataBuffersNumber,
  IN OUT VOID                                *Data[EFI_USB_MAX_ISO_BUFFER_NUM],
  IN     UINTN                               DataLength,
  IN     EFI_USB2_HC_TRANSACTION_TRANSLATOR  *Translator,
  IN     EFI_ASYNC_USB_TRANSFER_CALLBACK     IsochronousCallBack,
  IN     VOID                                *Context
  );

//----------->
int xhcPollRootHub(void *usb_root_hub,xhci_t* xhc);

/*
** Register access portion
*/
static inline bool cvmXhcIsHalt(xhci_t* xhc) __attribute__((always_inline));
static inline bool cvmXhcIsHalt(xhci_t* xhc)
{
    BDK_CSR_INIT(usbsts,xhc->node,BDK_USBHX_UAHC_USBSTS(xhc->usb_port));
    return 1 == usbsts.s.hch;
}
static inline bool cvmXhcIsSysError(xhci_t* xhc) __attribute__((always_inline));
static inline bool cvmXhcIsSysError(xhci_t* xhc)
{
    BDK_CSR_INIT(usbsts,xhc->node,BDK_USBHX_UAHC_USBSTS(xhc->usb_port));
    return 1 == usbsts.s.hse;
}

static inline bool cvmXhcNotOK(xhci_t* xhc) __attribute__((always_inline));
static inline bool cvmXhcNotOK(xhci_t* xhc) {
     BDK_CSR_INIT(usbsts,xhc->node,BDK_USBHX_UAHC_USBSTS(xhc->usb_port));
     return (usbsts.s.hch|| usbsts.s.hse) != 0;
}

static inline void cvmXhcWriteDoorBellReg(xhci_t* xhc, const unsigned slot, const uint32_t data) __attribute__((always_inline));
static inline void cvmXhcWriteDoorBellReg(xhci_t* xhc, const unsigned slot, const uint32_t data)
{

    BDK_WMB;
    BDK_CSR_WRITE(xhc->node,BDK_USBHX_UAHC_DBX(xhc->usb_port,slot), data);
    BDK_WMB;
}
static inline uint32_t  cvmXhcReadDoorBellReg(xhci_t* xhc, const unsigned offset)  __attribute__((always_inline));
static inline uint32_t  cvmXhcReadDoorBellReg(xhci_t* xhc, const unsigned offset) {
    unsigned db_index = offset >>2;
    BDK_CSR_INIT(uahc_db,xhc->node,BDK_USBHX_UAHC_DBX(xhc->usb_port,db_index));
    return uahc_db.u;
}

#endif
