#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT 8010 /* 3sec at 700Mhz */

void watchdog_set(int timeout);
void watchdog_poke();
void watchdog_disable();

#endif /* __WATCHDOG_H__ */
