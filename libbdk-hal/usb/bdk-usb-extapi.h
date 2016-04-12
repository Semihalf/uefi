#ifndef __BDK_USB_EXTAPI_H__
#define __BDK_USB_EXTAPI_H__

int bdk_usb_HCInit(bdk_node_t node, int usb_port);
int bdk_usb_HCPoll(bdk_node_t node, int usb_port);
int bdk_usb_HCList();

typedef enum {
    DO_QUERY,
    DO_TOGGLE
} bdk_usb_toggleReq_t;

int bdk_usb_togglePoll(bdk_node_t node, int usb_port, const bdk_usb_toggleReq_t action);
#endif
