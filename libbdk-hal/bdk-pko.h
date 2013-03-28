/**
 * @file
 *
 * Interface to the hardware Packet Output unit.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/* These functions are only used for CN68XX and can be removed
    when CN68XX support is removed */
extern int __bdk_pko_alloc_pipe(bdk_node_t node, int num_pipes);
extern int __bdk_pko_alloc_engine(bdk_node_t node);
extern int __bdk_pko_alloc_port(bdk_node_t node);

/** @} */
