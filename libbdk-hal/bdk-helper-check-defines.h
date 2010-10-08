#define BDK_PKO_MAX_PORTS_INTERFACE0 4
#define BDK_PKO_QUEUES_PER_PORT_INTERFACE0 2
#define BDK_PKO_MAX_PORTS_INTERFACE1 4
#define BDK_PKO_QUEUES_PER_PORT_INTERFACE1 2
#define BDK_PKO_QUEUES_PER_PORT_PCI 2
#define BDK_PKO_QUEUES_PER_PORT_LOOP 2
    /* We use two queues per port for SRIO1. Having two queues per
        port with two ports gives us four queues, one for each mailbox */
#define BDK_PKO_QUEUES_PER_PORT_SRIO0 2
#define BDK_PKO_QUEUES_PER_PORT_SRIO1 2

#define BDK_ENABLE_SSO_CHECKS 1

