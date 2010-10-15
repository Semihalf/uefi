#include <bdk.h>
#include <stdio.h>

uint8_t __bdk_config_is_valid[__BDK_CONFIG_END];
uint64_t __bdk_config_cache[__BDK_CONFIG_END];

#define AS_STRING(e) [e] = #e
static const char *__bdk_config_get_name[__BDK_CONFIG_END] =
{
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE0),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE1),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE2),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE3),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE4),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE5),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE6),
    AS_STRING(BDK_CONFIG_FPA_POOL_SIZE7),

    AS_STRING(BDK_CONFIG_FIRST_MBUFF_SKIP),
    AS_STRING(BDK_CONFIG_NOT_FIRST_MBUFF_SKIP),
    AS_STRING(BDK_CONFIG_ENABLE_IPD),
    AS_STRING(BDK_CONFIG_INPUT_TAG_TYPE),
    AS_STRING(BDK_CONFIG_INPUT_PORT_SKIP_MODE),

    AS_STRING(BDK_CONFIG_PHY_MGMT_PORT0),
    AS_STRING(BDK_CONFIG_PHY_MGMT_PORT1),

    AS_STRING(BDK_CONFIG_THREAD_STACK_SIZE),
    AS_STRING(BDK_CONFIG_MAC_ADDRESS),
};
#undef AS_STRING

uint64_t __bdk_config_get_slow(bdk_config_t cfg, uint64_t default_value)
{
    uint64_t result = default_value;
    const char *name = __bdk_config_get_name[cfg];
    const char *value = getenv(name);

    if (value)
    {
        if ((value[0] == '0') && (value[1] == 'x'))
        {
            if (sscanf(value+2, "%llx", (unsigned long long *)&result) != 1)
                result = 0;
        }
        else
        {
            if (sscanf(value, "%lli", (unsigned long long *)&result) != 1)
                result = 0;
        }
    }
    __bdk_config_cache[cfg] = result;
    BDK_SYNCW;
    __bdk_config_is_valid[cfg] = 1;
    BDK_SYNCW;
    return result;
}

extern void bdk_config_set(bdk_config_t cfg, uint64_t value)
{
    char buffer[19];
    const char *name = __bdk_config_get_name[cfg];

    __bdk_config_cache[cfg] = value;
    BDK_SYNCW;
    __bdk_config_is_valid[cfg] = 1;
    BDK_SYNCW;

    sprintf(buffer, "0x%llu", (unsigned long long)value);
    setenv(name, buffer, 1);
}

