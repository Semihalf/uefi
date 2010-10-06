#include <bdk.h>
#include <malloc.h>

/**
 * Global structure holding the state of all timers.
 */
bdk_tim_t bdk_tim;


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
int bdk_tim_setup(uint64_t tick, uint64_t max_ticks)
{
    bdk_tim_mem_ring0_t    config_ring0;
    bdk_tim_mem_ring1_t    config_ring1;
    uint64_t                timer_id;
    int                     error = -1;
    uint64_t                tim_clock_hz = bdk_clock_get_rate(BDK_CLOCK_TIM);
    uint64_t                hw_tick_ns;
    uint64_t                hw_tick_ns_allowed;
    uint64_t                tick_ns = 1000 * tick;
    int                     i;
    uint32_t                temp;

    /* for the simulator */
    if (tim_clock_hz == 0)
      tim_clock_hz = 333000000;

    hw_tick_ns = 1024 * 1000000000ull / tim_clock_hz;
    /*
     * Double the minimal allowed tick to 2 * HW tick.  tick between
     * (hw_tick_ns, 2*hw_tick_ns) will set config_ring1.s.interval
     * to zero, or 1024 cycles. This is not enough time for the timer unit
     * to fetch the bucket data, Resulting in timer ring error interrupt
     * be always generated. Avoid such setting in software.
     */
    hw_tick_ns_allowed = hw_tick_ns * 2;

    /* Make sure the timers are stopped */
    bdk_tim_stop();

    /* Reinitialize out timer state */
    memset(&bdk_tim, 0, sizeof(bdk_tim));


    if ((tick_ns < (hw_tick_ns_allowed)) || (tick_ns > 4194304 * hw_tick_ns))
      {
	bdk_dprintf("ERROR: bdk_tim_setup: Requested tick %lu(ns) is smaller than"
		     " the minimal ticks allowed by hardware %lu(ns)\n",
		     tick_ns, hw_tick_ns_allowed);
	return error;
      }

    for (i=2; i<20; i++)
    {
      if (tick_ns < (hw_tick_ns << i))
	break;
    }

    bdk_tim.max_ticks = (uint32_t)max_ticks;
    bdk_tim.bucket_shift = (uint32_t)(i - 1 + 10);
    bdk_tim.tick_cycles = tick * tim_clock_hz / 1000000;

    temp = (max_ticks * bdk_tim.tick_cycles) >> bdk_tim.bucket_shift;

    /* round up to nearest power of 2 */
    temp -= 1;
    temp = temp | (temp >> 1);
    temp = temp | (temp >> 2);
    temp = temp | (temp >> 4);
    temp = temp | (temp >> 8);
    temp = temp | (temp >> 16);
    bdk_tim.num_buckets = temp + 1;

    /* ensure input params fall into permitted ranges */
    if ((bdk_tim.num_buckets < 3) || bdk_tim.num_buckets > 1048576)
      {
	bdk_dprintf("ERROR: bdk_tim_setup: num_buckets out of range\n");
	return error;
      }

    /* Allocate the timer buckets from hardware addressable memory */
    bdk_tim.bucket = memalign(BDK_CACHE_LINE_SIZE, BDK_TIM_NUM_TIMERS * bdk_tim.num_buckets
					 * sizeof(bdk_tim_bucket_entry_t));
    if (bdk_tim.bucket == NULL)
      {
	bdk_dprintf("ERROR: bdk_tim_setup: allocation problem\n");
	return error;
      }
    memset(bdk_tim.bucket, 0, BDK_TIM_NUM_TIMERS * bdk_tim.num_buckets * sizeof(bdk_tim_bucket_entry_t));

    bdk_tim.start_time = 0;

    /* Loop through all timers */
    for (timer_id = 0; timer_id<BDK_TIM_NUM_TIMERS; timer_id++)
    {
        bdk_tim_bucket_entry_t *bucket = bdk_tim.bucket + timer_id * bdk_tim.num_buckets;
        /* Tell the hardware where about the bucket array */
        config_ring0.u64 = 0;
        config_ring0.s.first_bucket = bdk_ptr_to_phys(bucket) >> 5;
        config_ring0.s.num_buckets = bdk_tim.num_buckets - 1;
        config_ring0.s.ring = timer_id;
        BDK_CSR_WRITE(BDK_TIM_MEM_RING0, config_ring0.u64);

        /* Tell the hardware the size of each chunk block in pointers */
        config_ring1.u64 = 0;
        config_ring1.s.enable = 1;
        config_ring1.s.pool = BDK_FPA_TIMER_POOL;
        config_ring1.s.words_per_chunk = bdk_fpa_get_block_size(BDK_FPA_TIMER_POOL) / 8;
        config_ring1.s.interval = (1 << (bdk_tim.bucket_shift - 10)) - 1;
        config_ring1.s.ring = timer_id;
        BDK_CSR_WRITE(BDK_TIM_MEM_RING1, config_ring1.u64);
    }

    return 0;
}

/**
 * Start the hardware timer processing
 */
void bdk_tim_start(void)
{
    bdk_tim_reg_flags_t control;

    control.u64 = 0;
    control.s.enable_dwb = 1;
    control.s.enable_timers = 1;

    /* Remember when we started the timers */
    bdk_tim.start_time = bdk_clock_get_count(BDK_CLOCK_TIM);
    BDK_CSR_WRITE(BDK_TIM_REG_FLAGS, control.u64);
}


/**
 * Stop the hardware timer processing. Timers stay configured.
 */
void bdk_tim_stop(void)
{
    bdk_tim_reg_flags_t control;
    control.u64 = 0;
    control.s.enable_dwb = 0;
    control.s.enable_timers = 0;
    BDK_CSR_WRITE(BDK_TIM_REG_FLAGS, control.u64);
}


/**
 * Stop the timer. After this the timer must be setup again
 * before use.
 */
void bdk_tim_shutdown(void)
{
    uint32_t                bucket;
    uint64_t                timer_id;
    uint64_t                entries_per_chunk;

    /* Make sure the timers are stopped */
    bdk_tim_stop();

    entries_per_chunk = bdk_fpa_get_block_size(BDK_FPA_TIMER_POOL)/8 - 1;

    /* Now walk all buckets freeing the chunks */
    for (timer_id = 0; timer_id<BDK_TIM_NUM_TIMERS; timer_id++)
    {
        for (bucket=0; bucket<bdk_tim.num_buckets; bucket++)
        {
            uint64_t chunk_addr;
            uint64_t next_chunk_addr;
            bdk_tim_bucket_entry_t *bucket_ptr = bdk_tim.bucket + timer_id * bdk_tim.num_buckets + bucket;
            BDK_PREFETCH(CAST64(bucket_ptr), 128);  /* prefetch the next cacheline for future buckets */

            /* Each bucket contains a list of chunks */
            chunk_addr = bucket_ptr->first_chunk_addr;
            while (bucket_ptr->num_entries)
            {
                /* Read next chunk pointer from end of the current chunk */
                next_chunk_addr = bdk_read64_uint64(BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, chunk_addr + bdk_fpa_get_block_size(BDK_FPA_TIMER_POOL) - 8));

                bdk_fpa_free(bdk_phys_to_ptr(chunk_addr), BDK_FPA_TIMER_POOL, 0);
                chunk_addr = next_chunk_addr;
                if (bucket_ptr->num_entries > entries_per_chunk)
                    bucket_ptr->num_entries -= entries_per_chunk;
                else
                    bucket_ptr->num_entries = 0;
            }
        }
    }
}

