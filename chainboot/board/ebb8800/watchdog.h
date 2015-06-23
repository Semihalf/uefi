#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT 0

#define watchdog_set(timeout)
#define watchdog_poke()
#define watchdog_disable()

#endif /* __WATCHDOG_H__ */
