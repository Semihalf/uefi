/**
 * @file
 *
 * Functions for controlling the system configuration.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum
{
    BDK_CONFIG_PHY_IF0_PORT0,
    BDK_CONFIG_PHY_IF0_PORT1,
    BDK_CONFIG_PHY_IF0_PORT2,
    BDK_CONFIG_PHY_IF0_PORT3,
    BDK_CONFIG_PHY_IF1_PORT0,
    BDK_CONFIG_PHY_IF1_PORT1,
    BDK_CONFIG_PHY_IF1_PORT2,
    BDK_CONFIG_PHY_IF1_PORT3,
    BDK_CONFIG_PHY_IF2_PORT0,
    BDK_CONFIG_PHY_IF2_PORT1,
    BDK_CONFIG_PHY_IF2_PORT2,
    BDK_CONFIG_PHY_IF2_PORT3,
    BDK_CONFIG_PHY_IF3_PORT0,
    BDK_CONFIG_PHY_IF3_PORT1,
    BDK_CONFIG_PHY_IF3_PORT2,
    BDK_CONFIG_PHY_IF3_PORT3,
    BDK_CONFIG_PHY_IF4_PORT0,
    BDK_CONFIG_PHY_IF4_PORT1,
    BDK_CONFIG_PHY_IF4_PORT2,
    BDK_CONFIG_PHY_IF4_PORT3,
    BDK_CONFIG_PHY_IF5_PORT0,
    BDK_CONFIG_PHY_IF5_PORT1,
    BDK_CONFIG_PHY_IF5_PORT2,
    BDK_CONFIG_PHY_IF5_PORT3,

    BDK_CONFIG_THREAD_STACK_SIZE,
    BDK_CONFIG_MAC_ADDRESS,

    BDK_CONFIG_NUM_PACKET_BUFFERS,
    BDK_CONFIG_PACKET_BUFFER_SIZE,
    BDK_CONFIG_SHOW_LINK_STATUS,

    BDK_CONFIG_COREMASK,
    BDK_CONFIG_ENABLE_MULTINODE,

    __BDK_CONFIG_END
} bdk_config_t;

extern void __bdk_config_init(void);
extern uint64_t bdk_config_get(bdk_config_t cfg);
extern void bdk_config_set(bdk_config_t cfg, uint64_t value);
extern const char *bdk_config_get_name(bdk_config_t cfg);

/** @} */
