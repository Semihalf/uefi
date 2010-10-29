/**
 * @file
 *
 * Functions for accessing compact flash over the bootbus.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * This function takes values from the compact flash device
 * identify response, and returns the appropriate value to write
 * into the boot bus DMA timing register.
 *
 * @param tim_mult   Eclock timing multiple to use
 * @param ident_data Data returned by the 'identify' command.  This is used to
 *                   determine the DMA modes supported by the card, if any.
 * @param mwdma_mode_ptr
 *                   Optional pointer to return MWDMA mode in
 *
 * @return 64 bit value to write to DMA timing register
 */
extern uint64_t bdk_compactflash_generate_dma_tim(int tim_mult, uint16_t *ident_data, int *mwdma_mode_ptr);

/**
 * Setup timing and region config to support a specific IDE PIO
 * mode over the bootbus.
 *
 * @param cs0      Bootbus region number connected to CS0 on the IDE device
 * @param cs1      Bootbus region number connected to CS1 on the IDE device
 * @param pio_mode PIO mode to set (0-6)
 */
extern void bdk_compactflash_set_piomode(int cs0, int cs1, int pio_mode);

/** @} */
