#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

void watchdog_set(int timeout);
void watchdog_poke();
void watchdog_disable();

#endif /* __WATCHDOG_H__ */
