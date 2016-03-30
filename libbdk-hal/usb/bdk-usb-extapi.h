#ifndef __BDK_USB_EXTAPI_H__
#define __BDK_USB_EXTAPI_H__
int bdk_usb_HCInit(bdk_node_t node, int usb_port);
int bdk_usb_HCPoll(bdk_node_t node, int usb_port);
int bdk_usb_HCList(bdk_node_t node, int usb_port);
int bdk_usb_HCSpare(bdk_node_t node, int usb_port);
#endif
