/**
 * @file
 *
 * Helper utilities for enabling crypto.
 *
 * <hr>$Revision: $<hr>
 */

/**
 * Enable the dormant crypto functions.  If crypto is not already
 * enabled and it is possible to enable it, write the enable key.
 *
 * @param key  The dormant crypto enable key value.
 *
 * @return true if crypto is (or has been) enabled.
 */
extern int bdk_crypto_dormant_enable(uint64_t key);

/**
 * Read the crypto dormant debug value.
 *
 * @return The RNM_EER_DBG.DAT value, or zero if the feature is not
 * enabled.
 */
extern uint64_t bdk_crypto_dormant_dbg(void);

