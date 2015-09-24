#include <bdk.h>

void board_init_late()
{
    /* Initialize IO expander U29 to set SFP_TX_DISABLE_0=0 and SFP_TX_DISABLE_1=0 */
    /* Set all pins as inputs except:
        Pin 0.4: QSFP_RST_N
        Pin 0.5: QSFP_MODSEL_N
        Pin 0.6: QSFP_LPMODE
        Pin 1.3: SFP_TX_DISABLE_0
        Pin 1.7: SFP_TX_DISABLE_1
        Data high means pin is input */
    bdk_twsix_write_ia(bdk_numa_master(), 0, 0x20, 0x6, 1, 1, 0x8f);
    bdk_twsix_write_ia(bdk_numa_master(), 0, 0x20, 0x7, 1, 1, 0x77);
    /* Drive output pins:
        Pin 0.4: QSFP_RST_N=1
        Pin 0.5: QSFP_MODSEL_N=1
        Pin 0.6: QSFP_LPMODE=1
        Pin 1.3: SFP_TX_DISABLE_0=0
        Pin 1.7: SFP_TX_DISABLE_1=0 */
    bdk_twsix_write_ia(bdk_numa_master(), 0, 0x20, 0x2, 1, 1, 0x70);
    bdk_twsix_write_ia(bdk_numa_master(), 0, 0x20, 0x3, 1, 1, 0x00);

}
