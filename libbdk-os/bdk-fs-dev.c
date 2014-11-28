#include <bdk.h>
#include <fcntl.h>

/**
 * Used to track dynamically allocated device. Note that only one device
 * is created for all nodes. For example, there will be 16 SATA devices on CN88XX
 * regardless of the number of nodes.
 */
typedef struct dev_fs
{
    struct dev_fs *next;
    const __bdk_fs_dev_ops_t *ops;
    char dev_name[16];
    int dev_index;
} dev_fs_t;

extern const __bdk_fs_dev_ops_t bdk_fs_uart_ops;

/* The uarts are treated special. These need to work very early, so statically
   add them to the device list. Do uart1 first as uart0 must point to it */
dev_fs_t bdk_fs_dev_uart1 = {
    .next = NULL,
    .ops = &bdk_fs_uart_ops,
    .dev_name = "uart1",
    .dev_index = 1,
};

/* Allocate uart0 pointing to uart1 */
dev_fs_t bdk_fs_dev_uart0 = {
    .next = &bdk_fs_dev_uart1,
    .ops = &bdk_fs_uart_ops,
    .dev_name = "uart0",
    .dev_index = 0,
};

/* Linked list of all device. Uart0 is the head and uart1 is the tail */
static dev_fs_t *dev_head = &bdk_fs_dev_uart0;
static dev_fs_t *dev_tail = &bdk_fs_dev_uart1;

/**
 * Register a hardware device for use as a IO file. Devices are treated differently
 * than other files as they are per node. Device names are of the format "n0.dev0".
 * "n0" is the node number of the device, "dev" is the dev_base prefix given in
 * this function call.
 *
 * @param dev_base  Name of the base device. Examples "sata", "uart", "pcie"
 * @param dev_index Device index tying this device to a hardware block. This becomes the last number
 *                  in the name.
 * @param ops       File operations for this device
 *
 * @return Zero on success, negative on failure
 */
int bdk_fs_register_dev(const char *dev_base, int dev_index, const __bdk_fs_dev_ops_t *ops)
{
    /* Allocate a structure to track this device */
    dev_fs_t *dev = calloc(1, sizeof(dev_fs_t));
    if (!dev)
    {
        bdk_error("Failed to allocate list entry for device %s%d\n", dev_base, dev_index);
        return -1;
    }

    /* Fill the structure */
    dev->next = NULL;
    dev->ops = ops;
    snprintf(dev->dev_name, sizeof(dev->dev_name), "%s%d", dev_base, dev_index);
    dev->dev_name[sizeof(dev->dev_name)-1] = 0;
    dev->dev_index = dev_index;

    /* Add it to the dev_head list */
    if (dev_tail)
        dev_tail->next = dev;
    else
        dev_head = dev;
    dev_tail = dev;
    return 0;
}

/**
 * Extract the node number from the device name. Names are "n0.dev0"
 *
 * @param name   Name to extract from
 *
 * @return Node number, or -1 on failure
 */
static int dev_get_node(const char *name)
{
    /* Skip any path prefix */
    if (name[0] == '/')
    {
        name++;
        while (name[0] != '/')
            name++;
        name++;
    }
    if (name[0] != 'n')
        return -1;
    if ((name[1] < '0') || (name[1] > '3'))
        return -1;
    if (name[2] != '.')
        return -1;
    int node = name[1] - '0';
    if (!bdk_numa_exists(node))
        return -1;
    return node;
}

/**
 * Lookup a device by name. Note that the leading node number is ignored in
 * the match checking.
 *
 * @param name   Name to search for. Format "N0.DEV0"
 *
 * @return Device structure or NULL
 */
static dev_fs_t *dev_find(const char *name)
{
    const char *name_no_node = name + 3;
    dev_fs_t *dev = dev_head;
    while (dev)
    {
        if (strcmp(name_no_node, dev->dev_name) == 0)
            return dev;
        dev = dev->next;
    }
    return NULL;
}

/**
 * Call open for the device if it is implemented. If there is no open, then
 * return good status. Not all devices care when they are opened / closed.
 *
 * @param name   Device name to open
 * @param flags  Flags of the open
 *
 * @return State pointer of success, NULL on failure
 */
static void *dev_open(const char *name, int flags)
{
    int node = dev_get_node(name);
    if (node < 0)
        return NULL;
    dev_fs_t *dev = dev_find(name);
    if (!dev)
        return NULL;

    __bdk_fs_dev_t state;
    state.filename = name;
    state.location = 0;
    state.dev_node = node;
    state.dev_index = dev->dev_index;

    if (dev->ops->open && dev->ops->open(&state, flags))
        return NULL;
    return dev;
}

/**
 * Called to close the file. May do nothing for some device
 *
 * @param handle File handle to close
 *
 * @return Zero on success, negative on failure
 */
static int dev_close(__bdk_fs_file_t *handle)
{
    const dev_fs_t *dev = handle->fs_state;
    int node = dev_get_node(handle->filename);
    if (node < 0)
        return -1;

    __bdk_fs_dev_t state;
    state.filename = handle->filename;
    state.location = handle->location;
    state.dev_node = node;
    state.dev_index = dev->dev_index;

    if (dev->ops->close)
        return dev->ops->close(&state);
    else
        return 0;
}

/**
 * Read data from a device
 *
 * @param handle File handle
 * @param buffer Buffer to fill
 * @param length NUmber of bytes to fill
 *
 * @return Bytes read, negative on error, zero on no more data
 */
static int dev_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    const dev_fs_t *dev = handle->fs_state;
    int node = dev_get_node(handle->filename);
    if (node < 0)
        return -1;

    __bdk_fs_dev_t state;
    state.filename = handle->filename;
    state.location = handle->location;
    state.dev_node = node;
    state.dev_index = dev->dev_index;

    if (dev->ops->read)
        return dev->ops->read(&state, buffer, length);
    else
        return -1;
}

static int dev_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    const dev_fs_t *dev = handle->fs_state;
    int node = dev_get_node(handle->filename);
    if (node < 0)
        return -1;

    __bdk_fs_dev_t state;
    state.filename = handle->filename;
    state.location = handle->location;
    state.dev_node = node;
    state.dev_index = dev->dev_index;

    if (dev->ops->write)
        return dev->ops->write(&state, buffer, length);
    else
        return -1;
}

const __bdk_fs_ops_t bdk_fs_dev_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = dev_open,
    .close = dev_close,
    .read = dev_read,
    .write = dev_write,
};

