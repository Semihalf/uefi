#include <bdk.h>

int bdk_crypto_dormant_enable(uint64_t key)
{
    if (octeon_has_feature(OCTEON_FEATURE_CRYPTO))
        return 1;

    if (octeon_has_feature(OCTEON_FEATURE_DORM_CRYPTO)) {
        bdk_rnm_eer_key_t v;
        v.s.key = key;
        BDK_CSR_WRITE(BDK_RNM_EER_KEY, v.u64);
    }

    return octeon_has_feature(OCTEON_FEATURE_CRYPTO);
}

uint64_t bdk_crypto_dormant_dbg(void)
{
    bdk_rnm_eer_dbg_t dbg;

    if (!octeon_has_feature(OCTEON_FEATURE_DORM_CRYPTO))
        return 0;

    dbg.u64 = BDK_CSR_READ(BDK_RNM_EER_DBG);
    return dbg.s.dat;
}


