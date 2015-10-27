#include <bdk.h>

/**
 * Configure TWSI on all nodes as part of booting
 */
void bdk_boot_twsi(void)
{
    int blob_length = 0;
    const char *blob = bdk_config_get_blob(&blob_length, BDK_CONFIG_TWSI_WRITE);
    if (!blob)
        return;
    const char *done = blob + blob_length;
    const char *str = blob;
    while (str < done)
    {
        /* Check for the special case of a sleep line specifying a delay (ms) */
        if (strncmp(str, "sleep,", 6) == 0)
        {
            int delay = 0;
            int count = sscanf(str, "sleep,%i", &delay);
            if (count != 1)
            {
                bdk_error("Parsing TWSI sleep failed: %s\n", str);
                break;
            }
            bdk_wait_usec(delay * 1000);
        }
        else
        {
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
                bdk_error("Parsing TWSI write failed: %s\n", str);
                break;
            }
            if (node == -1)
                node = bdk_numa_local();
            /* Perform the write */
            if (bdk_twsix_write_ia(node, twsi_id, dev_addr, internal_addr, num_bytes, ia_width_bytes, data))
            {
                bdk_error("TWSI write failed: %s\n", str);
                break;
            }
        }

        /* Move to the next string */
        str += strlen(str) + 1;
    }
}
