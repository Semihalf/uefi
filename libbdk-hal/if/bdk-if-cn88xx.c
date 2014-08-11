#include <bdk.h>
#include <malloc.h>

static bdk_spinlock_t free_list_lock;
static void *free_list;

static int segment_init(void)
{
    /* Allow all IO units to access secure memory */
    for (int smmu = 0; smmu < 4; smmu++)
    {
        for (int id = 0; id < 2048; id++)
            BDK_CSR_WRITE(bdk_numa_local(), BDK_SMMUX_SSDRX(smmu, id), 0);
    }

    bdk_spinlock_init(&free_list_lock);

    const int num_bufs = bdk_config_get(BDK_CONFIG_NUM_PACKET_BUFFERS);
    const int buf_size = bdk_config_get(BDK_CONFIG_PACKET_BUFFER_SIZE);

    bdk_spinlock_lock(&free_list_lock);

    /* Allocate a list of buffers */
    free_list = memalign(BDK_CACHE_LINE_SIZE, num_bufs * buf_size);
    if (!free_list)
    {
        bdk_spinlock_unlock(&free_list_lock);
        bdk_error("Unable to allocate packet buffers\n");
        return -1;
    }

    /* Create a linked list of segments where each segment points to the next */
    void *ptr = free_list;
    for (int i = 0; i < num_bufs-1; i++)
    {
        *(void **)ptr = ptr + buf_size;
        ptr += buf_size;
    }
    *(void **)ptr = NULL;

    bdk_spinlock_unlock(&free_list_lock);
    return 0;
}

static uint64_t segment_alloc(int length)
{
    uint64_t result;
    bdk_spinlock_lock(&free_list_lock);
    if (free_list)
    {
        result = bdk_ptr_to_phys(free_list);
        free_list = *(void **)free_list;
    }
    else
        result = 0;
    bdk_spinlock_unlock(&free_list_lock);
    return result;
}

static void segment_free(uint64_t address, int length)
{
    void *ptr = bdk_phys_to_ptr(address);
    bdk_spinlock_lock(&free_list_lock);
    *(void **)ptr = free_list;
    free_list = ptr;
    bdk_spinlock_unlock(&free_list_lock);
}

const __bdk_if_global_ops_t __bdk_if_global_ops_cn88xx = {
    .init = segment_init,
    .alloc = segment_alloc,
    .free = segment_free,
};

