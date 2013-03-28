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

extern int __bdk_pko_alloc_pipe(bdk_node_t node, int num_pipes);
extern int __bdk_pko_alloc_engine(bdk_node_t node);
extern int __bdk_pko_alloc_port(bdk_node_t node);

/** @} */
