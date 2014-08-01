#include <bdk.h>
// Module for interfacing with performance counters

#if 0

#define MAX_L2_COPIES 8 /* CN78XX uses 0-7, CN70XX use 0 */
#define MAX_L2_PFC 10 /* CN78XX uses 8-9 for IO */
#define MAX_TADS 4
#define NUM_COUNTERS 4

static int l2_perf(lua_State* L)
{
    bdk_node_t node = bdk_numa_local();
    /* We cycle through 6 counter sets. 0-3 are each quad, and 4,5 are
        handpicked values */
    static int count_set = 0;
    /* This is the start time of the PFC setup for current count_set */
    static uint64_t last_start_pfc[MAX_L2_COPIES][NUM_COUNTERS];
    /* This is the time of the last update for each counter */
    static uint64_t last_update_bus[MAX_L2_PFC];

    uint64_t clock_rate = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE);
    uint64_t current_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);

    /* All results will be in a table with fields for each TAD */
    if (lua_istable(L, 1))
        lua_pushvalue(L, 1);
    else
        lua_newtable(L);

    /* Number of TADs change for each chip */
    int num_l2_copies = CAVIUM_IS_MODEL(CAVIUM_CN78XX) ? 10 : 1;
    for (int l2=0; l2<num_l2_copies; l2++)
    {
        /* Name the L2 table */
        char tad_name[8];
        sprintf(tad_name, "bank%d", l2);

        /* Get the L2 table */
        lua_getfield(L, -1, tad_name);
        if (!lua_istable(L, -1))
        {
            /* Create the table for this L2 */
            lua_pop(L, 1);
            lua_newtable(L);
            lua_setfield(L, -2, tad_name);
            lua_getfield(L, -1, tad_name);
        }

        uint64_t delta_cycle = current_cycle - last_update_bus[l2];
        uint64_t delta_cycle_percent = delta_cycle / 100;
        if (delta_cycle_percent == 0)
            delta_cycle_percent = 1;
        last_update_bus[l2] = current_cycle;

        /* Use captial so titles are on top row */
        if (l2 >= MAX_L2_COPIES)
            sprintf(tad_name, "iob%d", l2 - MAX_L2_COPIES);
        lua_pushstring(L, tad_name);
        BDK_CSR_WRITE(node, BDK_L2C_XMCX_PFC(l2), 0);
        lua_setfield(L, -2, "Title");

        /* Counts the number of cycles the XMC(Add bus) was busy. So the
            percentage used is simply 100 * count / RCLK */
        lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_XMCX_PFC(l2)) / delta_cycle_percent);
        BDK_CSR_WRITE(node, BDK_L2C_XMCX_PFC(l2), 0);
        lua_setfield(L, -2, "bus_xmc(add) %");
        /* Counts the number of cycles the XMD(Store bus) was busy. So the
            percentage used is simply 100 * count / RCLK */
        lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_XMDX_PFC(l2)) / delta_cycle_percent);
        BDK_CSR_WRITE(node, BDK_L2C_XMDX_PFC(l2), 0);
        lua_setfield(L, -2, "bus_xmd(store) %");
        /* Counts the number of cycles the RSC(Commit bus) was busy. So the
            percentage used is simply 100 * count / RCLK */
        lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_RSCX_PFC(l2)) / delta_cycle_percent);
        BDK_CSR_WRITE(node, BDK_L2C_RSCX_PFC(l2), 0);
        lua_setfield(L, -2, "bus_rsc(commit) %");
        /* Counts the number of cycles the RSD(Fill bus) was busy. So the
            percentage used is simply 100 * count / RCLK */
        lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_RSDX_PFC(l2)) / delta_cycle_percent);
        BDK_CSR_WRITE(node, BDK_L2C_RSDX_PFC(l2), 0);
        lua_setfield(L, -2, "bus_rsd(fill) %");

        /* 78xx uses the above counters for IOB0 and IOB1 at index 8-9, but
           nothing else applies */
        if (l2 >= MAX_L2_COPIES)
        {
            lua_pop(L, 1);
            continue;
        }

        /* Number of invalidates */
        lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_INVX_PFC(l2)));
        BDK_CSR_WRITE(node, BDK_L2C_INVX_PFC(l2), 0);
        lua_setfield(L, -2, "invalidates #");

        /* There is only one IO bus */
        if (l2 == 0)
        {
            /* Counts the number of cycles the IOC(IO request bus) was busy.
                So the percentage used is simply 100 * count / RCLK */
            lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_IOCX_PFC(l2)) / delta_cycle_percent);
            BDK_CSR_WRITE(node, BDK_L2C_IOCX_PFC(l2), 0);
            lua_setfield(L, -2, "bus_ioc(IO req) %");
            /* Counts the number of cycles the IOR(IO response bus) was busy.
                So the percentage used is simply 100 * count / RCLK */
            lua_pushnumber(L, BDK_CSR_READ(node, BDK_L2C_IORX_PFC(l2)) / delta_cycle_percent);
            BDK_CSR_WRITE(node, BDK_L2C_IORX_PFC(l2), 0);
            lua_setfield(L, -2, "bus_ior(IO resp) %");
        }

        /* Read the current performace counter settings */
        BDK_CSR_INIT(tadx_prf, node, BDK_L2C_TADX_PRF(l2));

        /* Cycle through counters adding them to our L2's table */
        for (int counter=0; counter<NUM_COUNTERS; counter++)
        {
            /* Calculate time since last update */
            delta_cycle = current_cycle - last_start_pfc[l2][counter];
            if (delta_cycle == 0)
                delta_cycle = 1;
            delta_cycle_percent = delta_cycle / 100;
            if (delta_cycle_percent == 0)
                delta_cycle_percent = 1;
            last_start_pfc[l2][counter] = current_cycle;

            /* Read the appropriate counter */
            uint64_t value = 0;
            value = BDK_CSR_READ(node, BDK_L2C_TADX_PFCX(l2, counter));

            /* Figure out what to do based on the counter type */
            int count_type = (tadx_prf.u64 >> (counter*8)) & 0xff;
            const char *name = NULL;
            switch (count_type)
            {
                case 0x00: /* Nothing (disabled) */
                    break;
                case 0x01: /* L2 Tag Hit */
                    name = "tag_hit #";
                    /* Value is a simple count, not a utilization. Scale to
                        be cout/sec */
                    value = value * clock_rate / delta_cycle;
                    break;
                case 0x02: /* L2 Tag Miss */
                    name = "tag_miss #";
                    /* Value is a simple count, not a utilization. Scale to
                        be cout/sec */
                    value = value * clock_rate / delta_cycle;
                    break;
                case 0x03: /* L2 Tag NoAlloc (forced no-allocate) */
                    name = "tag_noalloc #";
                    /* Value is a simple count, not a utilization. Scale to
                        be cout/sec */
                    value = value * clock_rate / delta_cycle;
                    break;
                case 0x04: /* L2 Victim */
                    name = "victim #";
                    /* Value is a simple count, not a utilization. Scale to
                        be cout/sec */
                    value = value * clock_rate / delta_cycle;
                    break;
                case 0x05: /* SC Fail */
                    name = "sc_fail #";
                    /* Value is a simple count, not a utilization. Scale to
                        be cout/sec */
                    value = value * clock_rate / delta_cycle;
                    break;
                case 0x06: /* SC Pass */
                    name = "sc_pass #";
                    /* Value is a simple count, not a utilization. Scale to
                        be cout/sec */
                    value = value * clock_rate / delta_cycle;
                    break;
                case 0x07: /* LFB Occupancy (each cycle adds \# of LFBs valid) */
                    name = "lfb_occupancy %";
                    /* There are 16 LFBs, so utilization percentage is
                        100 * count / (RCLK*16) */
                    value /= delta_cycle_percent*16;
                    break;
                case 0x08: /* LFB Wait LFB (each cycle adds \# LFBs waiting for other LFBs) */
                    name = "lfb_wait_lfb %";
                    /* There are 16 LFBs, so utilization percentage is
                        100 * count / (RCLK*16) */
                    value /= delta_cycle_percent*16;
                    break;
                case 0x09: /* LFB Wait VAB (each cycle adds \# LFBs waiting for VAB) */
                    name = "lfb_wait_vab %";
                    /* There are 16 LFBs, so utilization percentage is
                        100 * count / (RCLK*16) */
                    value /= delta_cycle_percent*16;
                    break;
                case 0x80: /* Quad 0 index bus inuse */
                    name = "quad0_index_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0x81: /* Quad 0 read data bus inuse */
                    name = "quad0_read_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0x82: /* Quad 0 \# banks inuse (0-4/cycle) */
                    name = "quad0_banks_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0x83: /* Quad 0 wdat flops inuse (0-4/cycle) */
                    name = "quad0_wdat_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0x90: /* Quad 1 index bus inuse */
                    name = "quad1_index_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0x91: /* Quad 1 read data bus inuse */
                    name = "quad1_read_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0x92: /* Quad 1 \# banks inuse (0-4/cycle) */
                    name = "quad1_banks_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0x93: /* Quad 1 wdat flops inuse (0-4/cycle) */
                    name = "quad1_wdat_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0xA0: /* Quad 2 index bus inuse */
                    name = "quad2_index_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0xA1: /* Quad 2 read data bus inuse */
                    name = "quad2_read_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0xA2: /* Quad 2 \# banks inuse (0-4/cycle) */
                    name = "quad2_banks_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0xA3: /* Quad 2 wdat flops inuse (0-4/cycle) */
                    name = "quad2_wdat_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0xB0: /* Quad 3 index bus inuse */
                    name = "quad3_index_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0xB1: /* Quad 3 read data bus inuse */
                    name = "quad3_read_bus %";
                    /* Count is number of cycle bus in use, so utilization
                        percentage is 100 * count / RCLK */
                    value /= delta_cycle_percent;
                    break;
                case 0xB2: /* Quad 3 \# banks inuse (0-4/cycle) */
                    name = "quad3_banks_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
                case 0xB3: /* Quad 3 wdat flops inuse (0-4/cycle) */
                    name = "quad3_wdat_inuse %";
                    /* Count is number of banks bus in use per cycle (there are
                        4 banks), so utilization percentage is 100 * count /
                        (RCLK*4) */
                    value /= delta_cycle_percent*4;
                    break;
            }
            /* Add the counter to our output table */
            if (name)
            {
                lua_pushnumber(L, value);
                lua_setfield(L, -2, name);
            }
        }
        lua_pop(L, 1);

        /* Set counter types for next update */
        switch (count_set)
        {
            case 0:
            case 1:
            case 2:
            case 3:
                tadx_prf.s.cnt0sel = 0x80 + count_set * 0x10; /* Quad X index bus inuse */
                tadx_prf.s.cnt1sel = 0x81 + count_set * 0x10; /* Quad X read data bus inuse */
                tadx_prf.s.cnt2sel = 0x82 + count_set * 0x10; /* Quad X # banks inuse (0-4/cycle) */
                tadx_prf.s.cnt3sel = 0x83 + count_set * 0x10; /* Quad X wdat flops inuse (0-4/cycle) */
                break;
            case 4:
                tadx_prf.s.cnt0sel = 0x01; /* L2 Tag Hit */
                tadx_prf.s.cnt1sel = 0x02; /* L2 Tag Miss */
                tadx_prf.s.cnt2sel = 0x03; /* L2 Tag NoAlloc (forced no-allocate) */
                tadx_prf.s.cnt3sel = 0x04; /* L2 Victim */
                break;
            case 5:
                tadx_prf.s.cnt0sel = 0x05; /* SC Fail */
                tadx_prf.s.cnt1sel = 0x06; /* SC Pass */
                tadx_prf.s.cnt2sel = 0x07; /* LFB Occupancy (each cycle adds \# of LFBs valid) */
                tadx_prf.s.cnt3sel = 0x08; /* LFB Wait LFB (each cycle adds \# LFBs waiting for other LFBs) */
                //0x09; /* LFB Wait VAB (each cycle adds \# LFBs waiting for VAB) */
                break;
        }
        BDK_CSR_WRITE(node, BDK_L2C_TADX_PRF(l2), tadx_prf.u64);
        BDK_CSR_WRITE(node, BDK_L2C_TADX_PFCX(l2, 0), 0);
        BDK_CSR_WRITE(node, BDK_L2C_TADX_PFCX(l2, 1), 0);
        BDK_CSR_WRITE(node, BDK_L2C_TADX_PFCX(l2, 2), 0);
        BDK_CSR_WRITE(node, BDK_L2C_TADX_PFCX(l2, 3), 0);
    }
    count_set++;
    if (count_set > 5)
        count_set = 0;
    return 1;
}

void register_cavium_perf(lua_State *L)
{
    lua_newtable(L);
    lua_pushcfunction(L, l2_perf);
    lua_setfield(L, -2, "get_l2");
    lua_setfield(L, -2, "perf");
}

#endif
