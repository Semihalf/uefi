#include <bdk.h>
#include <malloc.h>

#include "boot-common.h"

/* Weakly bound default functions. Can be overwritten by board specific
 * functions in board/$(BOARD_TYPE)/board_init.c
 */
void board_init_early() { }
void board_init_late()  { }
