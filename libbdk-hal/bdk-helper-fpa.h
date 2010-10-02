/**
 * @file
 *
 * Helper functions for FPA setup.
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * Allocate memory and initialize the FPA pools using memory
 * from cvmx-bootmem. Sizes of each element in the pools is
 * controlled by the cvmx-config.h header file. Specifying
 * zero for any parameter will cause that FPA pool to not be
 * setup. This is useful if you aren't using some of the
 * hardware and want to save memory.
 *
 * @param packet_buffers
 *               Number of packet buffers to allocate
 * @param work_queue_entries
 *               Number of work queue entries
 * @param pko_buffers
 *               PKO Command buffers. You should at minimum have two per
 *               each PKO queue.
 * @param tim_buffers
 *               TIM ring buffer command queues. At least two per timer bucket
 *               is recommended.
 * @param dfa_buffers
 *               DFA command buffer. A relatively small (32 for example)
 *               number should work.
 * @return Zero on success, non-zero if out of memory
 */
extern int bdk_helper_initialize_fpa(int packet_buffers, int work_queue_entries,
                                      int pko_buffers, int tim_buffers,
                                      int dfa_buffers);

