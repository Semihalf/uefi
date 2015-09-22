#include <bdk.h>

BDK_REQUIRE_DEFINE(DRIVER);

/**
 * Called by the BDK to register all loaded drivers with bdk-device.
 *
 * @return Zero on success, negative on failure
 */
int __bdk_driver_register_all(void)
{
    /* All drivers follow a standard naming convention. Use a macro
       to reduce the amount of cut/paste code */
    #define DRIVER(name)                                    \
        extern bdk_driver_t __bdk_driver_##name BDK_WEAK;   \
        if (&__bdk_driver_##name)                           \
            bdk_device_add_driver(&__bdk_driver_##name)

    DRIVER(mdio);
    DRIVER(rnm);
    DRIVER(smmu);

    return 0;
}
