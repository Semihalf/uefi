#include <bdk.h>

/**
 * Configure TWSI on all nodes as part of booting
 */
void bdk_boot_twsi(void)
{
    int index = 0;
    /* Loop as long as we're able to find TWSI write strings in the
       environment. The 0x10000 limit is arbitrary and only here to stop
       potential runaway loops on bad input */
    while (index < 0x10000)
    {
        /* Look for a TWSI write string for the current index */
        const char *str = bdk_brd_cfg_get_str(NULL, BDK_BRD_CFG_TWSI_WRITE, index);
        if (!str)
            break;
        /* Check for the special case of a sleep line specifying a delay (ms) */
        if (strncmp(str, "sleep,", 6) == 0)
        {
            int delay = 0;
            int count = sscanf(str, "sleep,%i", &delay);
            if (count != 1)
            {
                bdk_error("Parsing TWSI sleep failed: [%d]%s\n", index, str);
                break;
            }
            bdk_wait_usec(delay * 1000);
            /* Move to the next index */
            index++;
            continue;
        }
        /* Read the parameters from the write */
        int node = 0;
        int twsi_id = 0;
        int dev_addr = 0;
        int internal_addr = 0;
        int num_bytes = 0;
        int ia_width_bytes = 0;
        uint64_t data = 0;
        int count = sscanf(str, "%i,%i,%i,%i,%i,%i,%lu", &node, &twsi_id, &dev_addr, &internal_addr, &num_bytes, &ia_width_bytes, &data);
        if (count != 7)
        {
            bdk_error("Parsing TWSI write failed: [%d]%s\n", index, str);
            break;
        }
        if (node == -1)
            node = bdk_numa_local();
        /* Perform the write */
        if (bdk_twsix_write_ia(node, twsi_id, dev_addr, internal_addr, num_bytes, ia_width_bytes, data))
        {
            bdk_error("TWSI write failed: [%d]%s\n", index, str);
            break;
        }
        /* Move to the next index */
        index++;
    }
}
