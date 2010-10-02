/**
 * @file
 *
 * Interface to the GMX hardware.
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * Disables the sending of flow control (pause) frames on the specified
 * RGMII port(s).
 *
 * @param interface Which interface (0 or 1)
 * @param port_mask Mask (4bits) of which ports on the interface to disable
 *                  backpressure on.
 *                  1 => disable backpressure
 *                  0 => enable backpressure
 *
 * @return 0 on success
 *         -1 on error
 */

static inline int bdk_gmx_set_backpressure_override(uint32_t interface, uint32_t port_mask)
{
    bdk_gmxx_tx_ovr_bp_t gmxx_tx_ovr_bp;
    /* Check for valid arguments */
    if (port_mask & ~0xf || interface & ~0x1)
        return(-1);
    gmxx_tx_ovr_bp.u64 = 0;
    gmxx_tx_ovr_bp.s.en = port_mask; /* Per port Enable back pressure override */
    gmxx_tx_ovr_bp.s.ign_full = port_mask; /* Ignore the RX FIFO full when computing BP */
    BDK_CSR_WRITE(BDK_GMXX_TX_OVR_BP(interface), gmxx_tx_ovr_bp.u64);
    return(0);

}

