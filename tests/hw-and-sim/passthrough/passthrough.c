#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <bdk.h>

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(ERROR_DECODE);
}

static int packet_receiver(bdk_if_packet_t *packet, void *arg)
{
    /* Remove the input CRC */
    packet->length-=4;
    /* Send the packet */
    return !bdk_if_transmit(packet->if_handle, (bdk_if_packet_t *)packet);
}

int main()
{
    printf("Starting all cores\n");
    bdk_init_cores(0);

    printf("Registering for packets from XAUI interfaces\n");
    for (bdk_if_handle_t handle = bdk_if_next_port(NULL); handle != NULL; handle = bdk_if_next_port(handle))
    {
        if (bdk_if_get_type(handle) == BDK_IF_XAUI)
        {
            bdk_if_register_for_packets(handle, packet_receiver, NULL);
            bdk_if_enable(handle);
        }
    }

    printf("Processing packets\n");
    /* This thread is done. The dispatcher will process packets from now on */
}
