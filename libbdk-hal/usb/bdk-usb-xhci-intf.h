#ifndef __BDK_USB_EXTAPI_H__
#define __BDK_USB_EXTAPI_H__
/**
 * @file
*  External interface to usb-xhci support to bdk
**/

//
// This header must not rely on xhci-private data types
//

/**
 * Convert USB speed encoding to human-readable token
 *
 * @param speed Encoded speed
 *
 * @return Pointer to a speed token one of SS:HS:LS:FS:??
 **/
const char* __bdk_usb_speed2token(const int speed);

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
int bdk_usb_HCInit(bdk_node_t node, int usb_port);

/**
 * Manually trigger root Hub enumeration pass
 *
 * @param node       Node to init
 * @param usb_port   Port to intialize
 *
 * @return Zero on success, negative on error
 */
int bdk_usb_HCPoll(bdk_node_t node, int usb_port);

/**
 * Print current USB topology discovered by enumeration
 *
 */
int bdk_usb_HCList();

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
typedef enum {
    DO_QUERY,
    DO_TOGGLE
} bdk_usb_toggleReq_t;

int bdk_usb_togglePoll(bdk_node_t node, int usb_port, const bdk_usb_toggleReq_t action);
#endif
