typedef enum
{
    OCTEON_FEATURE_SAAD,        /**<  Octeon models in the CN5XXX family and higher support atomic add instructions to memory (saa/saad) */
    OCTEON_FEATURE_ZIP,         /**<  Does this Octeon support the ZIP offload engine? */
    OCTEON_FEATURE_CRYPTO,      /**<  Does this Octeon support crypto acceleration using COP2? */
    OCTEON_FEATURE_DORM_CRYPTO, /**<  Can crypto be enabled by calling cvmx_crypto_dormant_enable()? */
    OCTEON_FEATURE_PCIE,        /**<  Does this Octeon support PCI express? */
    OCTEON_FEATURE_SRIO,	/**<  Does this Octeon support SRIOs */
    OCTEON_FEATURE_KEY_MEMORY,  /**<  Some Octeon models support internal memory for storing cryptographic keys */
    OCTEON_FEATURE_LED_CONTROLLER, /**<  Octeon has a LED controller for banks of external LEDs */
    OCTEON_FEATURE_TRA,         /**<  Octeon has a trace buffer */
    OCTEON_FEATURE_MGMT_PORT,   /**<  Octeon has a management port */
    OCTEON_FEATURE_RAID,        /**<  Octeon has a raid unit */
    OCTEON_FEATURE_USB,         /**<  Octeon has a builtin USB */
    OCTEON_FEATURE_NO_WPTR,     /**<  Octeon IPD can run without using work queue entries */
    OCTEON_FEATURE_DFA,         /**<  Octeon has DFA state machines */
    OCTEON_FEATURE_MDIO_CLAUSE_45,     /**<  Octeon MDIO block supports clause 45 transactions for 10 Gig support */
    OCTEON_FEATURE_NPEI,        /**<  CN52XX and CN56XX used a block named NPEI for PCIe access. Newer chips replaced this with SLI+DPI */
} octeon_feature_t;

/**
 * Determine if the current Octeon supports a specific feature. These
 * checks have been optimized to be fairly quick, but they should still
 * be kept out of fast path code.
 *
 * @param feature Feature to check for. This should always be a constant so the
 *                compiler can remove the switch statement through optimization.
 *
 * @return Non zero if the feature exists. Zero if the feature does not
 *         exist.
 */
static inline int octeon_has_feature(octeon_feature_t feature)
{
    switch (feature)
    {
        case OCTEON_FEATURE_SAAD:
            return 1;

        case OCTEON_FEATURE_ZIP:
            if (OCTEON_IS_MODEL(OCTEON_CN52XX))
                return 0;
            else
                return !bdk_fuse_read(121);

        case OCTEON_FEATURE_CRYPTO:
	    if (OCTEON_IS_MODEL(OCTEON_CN6XXX)) {
                bdk_mio_fus_dat2_t fus_2;
                fus_2.u64 = BDK_CSR_READ(BDK_MIO_FUS_DAT2);
                if (fus_2.s.nocrypto || fus_2.s.nomul) {
                    return 0;
                } else if (!fus_2.s.dorm_crypto) {
                    return 1;
                } else {
                    bdk_rnm_ctl_status_t st;
                    st.u64 = BDK_CSR_READ(BDK_RNM_CTL_STATUS);
                    return st.s.eer_val;
                }
            } else {
                return !bdk_fuse_read(90);
            }

        case OCTEON_FEATURE_DORM_CRYPTO:
            if (OCTEON_IS_MODEL(OCTEON_CN6XXX)) {
                bdk_mio_fus_dat2_t fus_2;
                fus_2.u64 = BDK_CSR_READ(BDK_MIO_FUS_DAT2);
                return !fus_2.s.nocrypto && !fus_2.s.nomul && fus_2.s.dorm_crypto;
            } else {
                return 0;
            }

        case OCTEON_FEATURE_PCIE:
            return (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN6XXX));

	case OCTEON_FEATURE_SRIO:
	    return (OCTEON_IS_MODEL(OCTEON_CN6XXX));

        case OCTEON_FEATURE_KEY_MEMORY:
            return OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN6XXX);

        case OCTEON_FEATURE_LED_CONTROLLER:
            return OCTEON_IS_MODEL(OCTEON_CN56XX);

        case OCTEON_FEATURE_TRA:
            return 1;
        case OCTEON_FEATURE_MGMT_PORT:
            return OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN6XXX);

        case OCTEON_FEATURE_RAID:
            return OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN6XXX);

        case OCTEON_FEATURE_USB:
            return 1;

        case OCTEON_FEATURE_NO_WPTR:
            return (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN6XXX)) &&
                    !OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X) && !OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X);

        case OCTEON_FEATURE_DFA:
            return 0;

        case OCTEON_FEATURE_MDIO_CLAUSE_45:
            return 1;

        case OCTEON_FEATURE_NPEI:
            return (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX));
    }
    return 0;
}

