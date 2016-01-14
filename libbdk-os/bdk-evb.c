#include <bdk.h>

/**
 * Intialize the LED display on a Cavium evaluation board. This is an eight
 * character display.
 *
 * @param node   Node the display is on
 */
void bdk_evb_display_init(bdk_node_t node)
{
    /* Setup access to the EBB8800 LED display
        GPIO[6] = DSP_R_L
        GPIO[7] = DSP_WE_CE_L
        GPIO[15:11] = DSP_AD[4:0]
        GPIO[16] = DSP_CLK
        GPIO[17] = DSP_CLS
        GPIO[18] = DSP_FL_L
        GPIO[20] = DSP_RST_L
        GPIO[28:21] = DSP_DATA[7:0] */
    BDK_CSR_WRITE(node, BDK_GPIO_TX_SET, 0x1ff7f8c0);
    for (int gpio = 6; gpio < 29; gpio++)
    {
        if ((gpio != 8) && (gpio != 9) && (gpio != 10) && (gpio != 19))
            BDK_CSR_WRITE(node, BDK_GPIO_BIT_CFGX(gpio), 1);
    }
    BDK_CSR_READ(node, BDK_GPIO_RX_DAT);
}

/**
 * Write a single character to the display
 *
 * @param node   Node the display is on
 * @param loc    Location to write (0-7). Zero is left most, 7 is right most
 * @param c      Character to write
 */
void bdk_evb_display_write_char(bdk_node_t node, int loc, char c)
{
    int address = 0x18 + loc;
    BDK_CSR_WRITE(node, BDK_GPIO_TX_SET, address << 11);
    BDK_CSR_WRITE(node, BDK_GPIO_TX_CLR, ((~address) & 0x1f) << 11);
    BDK_CSR_WRITE(node, BDK_GPIO_TX_SET, c << 21);
    BDK_CSR_WRITE(node, BDK_GPIO_TX_CLR, ((~c) & 0xff) << 21);
    BDK_CSR_READ(node, BDK_GPIO_RX_DAT);
    /* Do write */
    BDK_CSR_WRITE(node, BDK_GPIO_TX_CLR, 1ull << 7);
    BDK_CSR_READ(node, BDK_GPIO_RX_DAT);
    BDK_CSR_WRITE(node, BDK_GPIO_TX_SET, 1ull << 7);
}

/**
 * Write a string to the display
 *
 * @param node   Node the display is on
 * @param str    String to display
 */
void bdk_evb_display_write_str(bdk_node_t node, const char *str)
{
    for (int i = 0; i < 8; i++)
    {
        char c;
        if (*str)
            c = *str++;
        else
            c = ' ';
        bdk_evb_display_write_char(node, i, c);
    }
}

