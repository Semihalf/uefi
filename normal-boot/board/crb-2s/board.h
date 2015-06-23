#ifndef __BOARD_H__
#define __BOARD_H__

/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT 8010 /* 3sec at 700Mhz */

/* Name of DRAM config for master node 0 */
#define DRAM_NODE0 crb_2s_V3
/* Name of DRAM config for slave node 1 */
#define DRAM_NODE1 crb_2s_V3

#include "watchdog.h"

#endif /* __BOARD_H__ */
