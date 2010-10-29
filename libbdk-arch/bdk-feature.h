/**
 * @file
 *
 * Functions for determining the current chip features.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup octeon Octeon chips and features
 * @{
 */


typedef enum
{
    OCTEON_FEATURE_ZIP,         /**<  Does this Octeon support the ZIP offload engine? */
    OCTEON_FEATURE_CRYPTO,      /**<  Does this Octeon support crypto acceleration using COP2? */
    OCTEON_FEATURE_SRIO,	/**<  Does this Octeon support SRIOs */
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
        case OCTEON_FEATURE_ZIP:
            return !bdk_fuse_read(121);

        case OCTEON_FEATURE_CRYPTO:
        {
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
        }

	case OCTEON_FEATURE_SRIO:
	    return (OCTEON_IS_MODEL(OCTEON_CN63XX));
    }
    return 0;
}

/**
 * Return true if the software is currently running on the
 * Octeon software simulator.
 *
 * @return Non zero if simulation
 */
static inline int bdk_is_simulation(void)
{
    static int is_simulation = -1;

    if (is_simulation == -1)
    {
        int sim;
        BDK_CSR_INIT(dbg, BDK_SLI_DBG_SELECT);
        BDK_CSR_DEFINE(tmp, BDK_SLI_DBG_SELECT);
        tmp = dbg;
        tmp.s.dbg_sel = 1;
        BDK_CSR_WRITE(BDK_SLI_DBG_SELECT, tmp.u64);
        tmp.u64 = BDK_CSR_READ(BDK_SLI_DBG_SELECT);
        BDK_CSR_WRITE(BDK_SLI_DBG_SELECT, dbg.u64);
        sim = (tmp.s.dbg_sel == 0);
        is_simulation = sim;
        return sim;
    }
    return is_simulation;
}

/** @} */
