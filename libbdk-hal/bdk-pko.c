#include <bdk.h>

int bdk_pko_next_free_engine = 0;

int __bdk_pko_alloc_pipe(bdk_node_t node, int num_pipes)
{
    static int next_free_pipe = 0;
    int pipe = next_free_pipe;
    next_free_pipe += num_pipes;
    if (next_free_pipe > 128)
        bdk_fatal("PKO ran out of pipes. bdk_if_init() is incorrect\n");
    return pipe;
}

int __bdk_pko_alloc_engine(bdk_node_t node)
{
    int engine = bdk_pko_next_free_engine++;
    if (engine > 19)
        bdk_fatal("PKO ran out of engines. bdk_if_init() is incorrect\n");
    return engine;
}

int __bdk_pko_alloc_port(bdk_node_t node)
{
    static int next_free_port = 0;
    int port = next_free_port++;
    if (port > 127)
        bdk_fatal("PKO ran out of ports. bdk_if_init() is incorrect\n");
    return port;
}

