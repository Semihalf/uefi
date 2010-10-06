/**
 * @file
 *
 * Interface to the hardware work queue timers.
 *
`* <hr>$Revision: 49448 $<hr>
 */

#define BDK_TIM_NUM_TIMERS   16
#define BDK_TIM_NUM_BUCKETS  2048

typedef enum
{
    BDK_TIM_STATUS_SUCCESS = 0,
    BDK_TIM_STATUS_NO_MEMORY = -1,
    BDK_TIM_STATUS_TOO_FAR_AWAY = -2,
    BDK_TIM_STATUS_BUSY = -3
} bdk_tim_status_t;

/**
 * Each timer bucket contains a list of work queue entries to
 * schedule when the timer fires. The list is implemented as
 * a linked list of blocks. Each block contains an array of
 * work queue entries followed by a next block pointer. Since
 * these blocks are dynamically allocated off of a hardware
 * memory pool, there actual size isn't known compile time.
 * The next block pointer is stored in the last 8 bytes of
 * the memory block.
 */
typedef struct bdk_tim_entry_chunk
{
    volatile uint64_t entries[0];
} bdk_tim_entry_chunk_t;

/**
 * Each timer contains an array of buckets. Each bucket
 * represents the list of work queue entries that should be
 * scheduled when the timer fires.  The first 3 entries are used
 * byt the hardware.
 */
typedef struct
{
   volatile uint64_t                first_chunk_addr;
   volatile uint32_t                num_entries;    /**< Zeroed by HW after traversing list */
   volatile uint32_t                chunk_remainder;/**< Zeroed by HW after traversing list */

   // the remaining 16 bytes are not touched by hardware
   volatile bdk_tim_entry_chunk_t *last_chunk;
   uint64_t                         pad;
} bdk_tim_bucket_entry_t;

/**
 * Structure representing an individual timer. Each timer has
 * a timer period, a memory management pool, and a list of
 * buckets.
 */
typedef struct
{
    bdk_tim_bucket_entry_t*bucket;             /**< The timer buckets. Array of [BDK_TIM_NUM_TIMERS][BDK_TIM_NUM_BUCKETS] */
    uint64_t                tick_cycles;        /**< How long a bucket represents */
    uint64_t                start_time;         /**< Time the timer started in cycles */
    uint32_t                bucket_shift;       /**< How long a bucket represents in ms */
    uint32_t                num_buckets;        /**< How many buckets per wheel */
    uint32_t                max_ticks;          /**< maximum number of ticks allowed for timer */
} bdk_tim_t;

/**
 * Structure used to store state information needed to delete
 * an already scheduled timer entry. An instance of this
 * structure must be passed to bdk_tim_add_entry in order
 * to be able to delete an entry later with
 * bdk_tim_delete_entry.
 *
 * NOTE: This structure should be considered opaque by the application,
 * and the application should not access its members
 */
typedef struct
{
    uint64_t        commit_cycles;  /**< After this time the timer can't be changed */
    uint64_t *      timer_entry_ptr;/**< Where the work entry is. Zero this
                                            location to delete the entry */
} bdk_tim_delete_t;

/**
 * Global structure holding the state of all timers.
 */
extern bdk_tim_t bdk_tim;




#ifdef BDK_ENABLE_TIMER_FUNCTIONS
/**
 * Setup a timer for use. Must be called before the timer
 * can be used.
 *
 * @param tick      Time between each bucket in microseconds. This must not be
 *                  smaller than 1024/(clock frequency in MHz).
 * @param max_ticks The maximum number of ticks the timer must be able
 *                  to schedule in the future. There are guaranteed to be enough
 *                  timer buckets such that:
 *                  number of buckets >= max_ticks.
 * @return Zero on success. Negative on error. Failures are possible
 *         if the number of buckets needed is too large or memory
 *         allocation fails for creating the buckets.
 */
int bdk_tim_setup(uint64_t tick, uint64_t max_ticks);
#endif

/**
 * Start the hardware timer processing
 */
extern void bdk_tim_start(void);


/**
 * Stop the hardware timer processing. Timers stay configured.
 */
extern void bdk_tim_stop(void);


/**
 * Stop the timer. After this the timer must be setup again
 * before use.
 */
#ifdef BDK_ENABLE_TIMER_FUNCTIONS
extern void bdk_tim_shutdown(void);
#endif

#ifdef BDK_ENABLE_TIMER_FUNCTIONS
/**
 * Add a work queue entry to the timer.
 *
 * @param work_entry Work queue entry to add.
 * @param ticks_from_now
 * @param delete_info
 *                   Optional pointer where to store information needed to
 *                   delete the timer entry. If non NULL information needed
 *                   to delete the timer entry before it fires is stored here.
 *                   If you don't need to be able to delete the timer, pass
 *                   NULL.
 * @return Result return code
 */
static inline bdk_tim_status_t bdk_tim_add_entry(bdk_wqe_t *work_entry, uint64_t ticks_from_now, bdk_tim_delete_t *delete_info)
{
    bdk_tim_bucket_entry_t*    work_bucket_ptr;
    uint64_t                    current_bucket;
    uint64_t                    work_bucket;
    volatile uint64_t         * tim_entry_ptr;  /* pointer to wqe address in timer chunk */
    uint64_t                    entries_per_chunk;

    const uint64_t  cycles  = bdk_clock_get_count(BDK_CLOCK_TIM); /* Get our reference time early for accuracy */
    const uint64_t  core_num    = bdk_get_core_num();  /* One timer per processor, so use this to select */

    /* Make sure the specified time won't wrap our bucket list */
    if (ticks_from_now > bdk_tim.max_ticks)
    {
        bdk_dprintf("bdk_tim_add_entry: Tried to schedule work too far away.\n");
        return BDK_TIM_STATUS_TOO_FAR_AWAY;
    }

    /* Since we have no way to synchronize, we can't update a timer that is
        being used by the hardware. Two buckets forward should be safe */
    if (ticks_from_now < 2)
    {
        bdk_dprintf("bdk_tim_add_entry: Tried to schedule work too soon. Delaying it.\n");
        ticks_from_now = 2;
    }

    /* Get the bucket this work queue entry should be in. Remember the bucket
        array is circular */
    current_bucket = ((cycles - bdk_tim.start_time)
		   >> bdk_tim.bucket_shift);
    work_bucket = (((ticks_from_now * bdk_tim.tick_cycles) + cycles - bdk_tim.start_time)
		   >> bdk_tim.bucket_shift);

    work_bucket_ptr = bdk_tim.bucket + core_num * bdk_tim.num_buckets + (work_bucket & (bdk_tim.num_buckets - 1));
    entries_per_chunk = (BDK_FPA_TIMER_POOL_SIZE/8 - 1);

    /* Check if we have room to add this entry into the existing list */
    if (work_bucket_ptr->chunk_remainder)
    {
        /* Adding the work entry to the end of the existing list */
        tim_entry_ptr = &(work_bucket_ptr->last_chunk->entries[entries_per_chunk - work_bucket_ptr->chunk_remainder]);
        *tim_entry_ptr = bdk_ptr_to_phys(work_entry);
        work_bucket_ptr->chunk_remainder--;
        work_bucket_ptr->num_entries++;
    }
    else
    {
        /* Current list is either completely empty or completely full. We need
            to allocate a new chunk for storing this work entry */
        bdk_tim_entry_chunk_t *new_chunk = (bdk_tim_entry_chunk_t *)bdk_fpa_alloc(BDK_FPA_TIMER_POOL);
        if (new_chunk == NULL)
        {
            bdk_dprintf("bdk_tim_add_entry: Failed to allocate memory for new chunk.\n");
            return BDK_TIM_STATUS_NO_MEMORY;
        }

        /* Does a chunk currently exist? We have to check num_entries since
            the hardware doesn't NULL out the chunk pointers on free */
        if (work_bucket_ptr->num_entries)
        {
            /* This chunk must be appended to an existing list by putting
            ** its address in the last spot of the existing chunk. */
            work_bucket_ptr->last_chunk->entries[entries_per_chunk] = bdk_ptr_to_phys(new_chunk);
            work_bucket_ptr->num_entries++;
        }
        else
        {
            /* This is the very first chunk. Add it */
            work_bucket_ptr->first_chunk_addr = bdk_ptr_to_phys(new_chunk);
            work_bucket_ptr->num_entries = 1;
        }
        work_bucket_ptr->last_chunk = new_chunk;
        work_bucket_ptr->chunk_remainder = entries_per_chunk - 1;
        tim_entry_ptr = &(new_chunk->entries[0]);
        *tim_entry_ptr = bdk_ptr_to_phys(work_entry);
    }

    /* If the user supplied a delete info structure then fill it in */
    if (delete_info)
    {
        /* It would be very bad to delete a timer entry after, or during the
            timer's processing. During the processing could yield unpredicatable
            results, but after would always be bad. Modifying the entry after
            processing means we would be changing data in a buffer that has been
            freed, and possible allocated again. For this reason we store a
            commit cycle count in the delete structure. If we are after this
            count we will refuse to delete the timer entry. */
        delete_info->commit_cycles = cycles + (ticks_from_now - 2) * bdk_tim.tick_cycles;
        delete_info->timer_entry_ptr = (uint64_t *)tim_entry_ptr;  /* Cast to non-volatile type */
    }

    BDK_SYNCW; /* Make sure the hardware timer unit can access valid data from L2 */

    return BDK_TIM_STATUS_SUCCESS;
}
#endif


/**
 * Delete a timer entry scheduled using bdk_tim_add_entry.
 * Deleting a timer will fail if it has already triggered or
 * might be in progress. The actual state of the work queue
 * entry isn't changed. You need to dispose of it properly.
 *
 * @param delete_info
 *               Structure passed to bdk_tim_add_entry to store the
 *               information needed to delete a timer entry.
 * @return BDK_TIM_STATUS_BUSY if the timer was not deleted, otherwise
 *         BDK_TIM_STATUS_SUCCESS.
 */
static inline bdk_tim_status_t bdk_tim_delete_entry(bdk_tim_delete_t *delete_info)
{
    const uint64_t cycles = bdk_clock_get_count(BDK_CLOCK_TIM);

    if ((int64_t)(cycles - delete_info->commit_cycles) < 0)
    {
        /* Timer is far enough away. Safe to delete */
        *delete_info->timer_entry_ptr = 0;
        return BDK_TIM_STATUS_SUCCESS;
    }
    else
    {
        /* Timer is passed the commit time. It cannot be stopped */
        return BDK_TIM_STATUS_BUSY;
    }
}

