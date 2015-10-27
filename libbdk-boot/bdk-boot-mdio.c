#include <bdk.h>

/**
 * Configure MDIO on all nodes as part of booting
 */
void bdk_boot_mdio(void)
{
    int index = 0;
    /* Loop as long as we're able to find MDIO write strings in the
       environment. The 0x10000 limit is arbitrary and only here to stop
       potential runaway loops on bad input */
    while (index < 0x10000)
    {
        /* Look for a MDIO write string for the current index */
        const char *str = bdk_config_get_str(BDK_CONFIG_MDIO_WRITE, index);
        if (!str)
            break;
        /* Check for the special case of a sleep line specifying a delay (ms) */
        if (strncmp(str, "sleep,", 6) == 0)
        {
            int delay = 0;
            int count = sscanf(str, "sleep,%i", &delay);
            if (count != 1)
            {
                bdk_error("Parsing MDIO sleep failed: [%d]%s\n", index, str);
                break;
            }
            bdk_wait_usec(delay * 1000);
            /* Move to the next index */
            index++;
            continue;
        }

        /* Read the parameters from the write */
        int clause = 0;
        int node = 0;
        int bus_id = 0;
        int phy_id = 0;
        int device = 0;
        int location = 0;
        int val = 0;
        int count = sscanf(str, "%i,%i,%i,%i,%i,%i,%i", &clause, &node, &bus_id, &phy_id, &device, &location, &val);
        if (count != 7)
        {
            bdk_error("Parsing MDIO write failed: [%d]%s\n", index, str);
            break;
        }
        if (node == -1)
            node = bdk_numa_local();

        /* Perform the write */
        int status;
        if (clause == 45)
            status = bdk_mdio_45_write(node, bus_id, phy_id, device, location, val);
        else if (clause == 22)
            status = bdk_mdio_write(node, bus_id, phy_id, location, val);
        else
        {
            bdk_error("MDIO write with unsupported clause: [%d]%s\n", index, str);
            break;
        }
        if (status)
        {
            bdk_error("MDIO write failed: [%d]%s\n", index, str);
            break;
        }

        /* Move to the next index */
        index++;
    }
}
