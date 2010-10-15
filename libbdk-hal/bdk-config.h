
typedef enum
{
    BDK_CONFIG_FPA_POOL_SIZE0,
    BDK_CONFIG_FPA_POOL_SIZE1,
    BDK_CONFIG_FPA_POOL_SIZE2,
    BDK_CONFIG_FPA_POOL_SIZE3,
    BDK_CONFIG_FPA_POOL_SIZE4,
    BDK_CONFIG_FPA_POOL_SIZE5,
    BDK_CONFIG_FPA_POOL_SIZE6,
    BDK_CONFIG_FPA_POOL_SIZE7,

    BDK_CONFIG_FIRST_MBUFF_SKIP,
    BDK_CONFIG_NOT_FIRST_MBUFF_SKIP,
    BDK_CONFIG_ENABLE_IPD,
    BDK_CONFIG_INPUT_TAG_TYPE,
    BDK_CONFIG_INPUT_PORT_SKIP_MODE,

    BDK_CONFIG_PHY_MGMT_PORT0,
    BDK_CONFIG_PHY_MGMT_PORT1,

    BDK_CONFIG_THREAD_STACK_SIZE,

    __BDK_CONFIG_END
} bdk_config_t;

static inline uint64_t bdk_config_get(bdk_config_t cfg, uint64_t default_value)
{
    extern uint64_t __bdk_config_get_slow(bdk_config_t cfg, uint64_t default_value);
    extern uint8_t __bdk_config_is_valid[__BDK_CONFIG_END];
    extern uint64_t __bdk_config_cache[__BDK_CONFIG_END];

    if (bdk_likely(__bdk_config_is_valid[cfg]))
        return __bdk_config_cache[cfg];
    else
        return __bdk_config_get_slow(cfg, default_value);
}

extern void bdk_config_set(bdk_config_t cfg, uint64_t value);

