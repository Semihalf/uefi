#include <bdk.h>

/**
 * Read a byte of fuse data
 * @param byte_addr   address to read
 *
 * @return fuse value: 0 or 1
 */
static uint8_t bdk_fuse_read_byte(bdk_node_t node, int byte_addr)
{
    bdk_mio_fus_rcmd_t read_cmd;

    read_cmd.u = 0;
    read_cmd.s.addr = byte_addr;
    read_cmd.s.addr_hi = byte_addr >> 8;
    read_cmd.s.pend = 1;
    BDK_CSR_WRITE(node, BDK_MIO_FUS_RCMD, read_cmd.u);
    do
    {
        read_cmd.u = BDK_CSR_READ(node, BDK_MIO_FUS_RCMD);
    } while (read_cmd.s.pend);
    return read_cmd.s.dat;
}


/**
 * Read a single fuse bit
 *
 * @param fuse   Fuse number (0-1024)
 *
 * @return fuse value: 0 or 1
 */
int bdk_fuse_read(bdk_node_t node, int fuse)
{
    return((bdk_fuse_read_byte(node, fuse >> 3) >> (fuse & 0x7)) & 1);
}

/**
 * Soft blow a fuse. Soft blown fuses keep there new value over soft resets, but
 * not pwoer cycles.
 *
 * @param node   Node to blow
 * @param fuse   Fuse to blow
 *
 * @return Zero on success, negative on failure
 */
int bdk_fuse_soft_blow(bdk_node_t node, int fuse)
{
    /* Select the fuse bank. there are 128 fuses per bank */
    BDK_CSR_WRITE(node, BDK_MIO_FUS_WADR, fuse / 128);

    /* Select the fuse to program in the bank */
    int index = fuse & 127;
    if (index < 64)
    {
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(0), 1ull << index);
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(1), 0);
    }
    else
    {
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(0), 0);
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(1), 1ull << (index - 64));
    }

    /* Set to do a soft blow */
    BDK_CSR_DEFINE(fus_prog, BDK_MIO_FUS_PROG);
    fus_prog.u = 0;
    fus_prog.s.sft = 1;
    BDK_CSR_WRITE(node, BDK_MIO_FUS_PROG, fus_prog.u);

    /* Do the actual program */
    fus_prog.s.prog = 1;
    BDK_CSR_WRITE(node, BDK_MIO_FUS_PROG, fus_prog.u);

    /* Wait for the program to complete. We don't use timeouts because this
       code can run without the GTI timer */
    do
    {
        fus_prog.u = BDK_CSR_READ(node, BDK_MIO_FUS_PROG);
    } while (fus_prog.s.prog);

    /* Read the fuse to make sure it was really soft blown */
    if (bdk_fuse_read(node, fuse) == 0)
    {
        bdk_error("Soft blowing fuse failed\n");
        return -1;
    }
    return 0;
}

/**
 * Read a single fuse bit from the field set (FUSF)
 *
 * @param fuse   Fuse number (0-1024)
 *
 * @return fuse value: 0 or 1
 */
int bdk_fuse_field_read(bdk_node_t node, int fuse)
{
    bdk_fusf_rcmd_t read_cmd;

    read_cmd.u = 0;
    read_cmd.s.addr = fuse >> 8;
    read_cmd.s.addr_hi = fuse >> 16;
    read_cmd.s.pend = 1;
    BDK_CSR_WRITE(node, BDK_FUSF_RCMD, read_cmd.u);
    do
    {
        read_cmd.u = BDK_CSR_READ(node, BDK_FUSF_RCMD);
    } while (read_cmd.s.pend);

    int index = fuse & 0x7f;
    uint64_t dat = BDK_CSR_READ(node, BDK_FUSF_BNK_DATX(index >> 6));
    return (dat >> (index & 0x3f)) & 1;
}

/**
 * Soft blow a fuse in the field set (FUSF). Soft blown fuses
 * keep there new value over soft resets, but not pwoer cycles.
 *
 * @param node   Node to blow
 * @param fuse   Fuse to blow
 *
 * @return Zero on success, negative on failure
 */
int bdk_fuse_field_soft_blow(bdk_node_t node, int fuse)
{
    /* Select the fuse bank. there are 128 fuses per bank */
    BDK_CSR_WRITE(node, BDK_FUSF_WADR, fuse / 128);

    /* Select the fuse to program in the bank */
    int index = fuse & 127;
    if (index < 64)
    {
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(0), 1ull << index);
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(1), 0);
    }
    else
    {
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(0), 0);
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(1), 1ull << (index - 64));
    }

    /* Set to do a soft blow */
    BDK_CSR_DEFINE(fus_prog, BDK_FUSF_PROG);
    fus_prog.u = 0;
    fus_prog.s.sft = 1;
    BDK_CSR_WRITE(node, BDK_FUSF_PROG, fus_prog.u);

    /* Do the actual program */
    fus_prog.s.prog = 1;
    BDK_CSR_WRITE(node, BDK_FUSF_PROG, fus_prog.u);

    /* Wait for the program to complete. We don't use timeouts because this
       code can run without the GTI timer */
    do
    {
        fus_prog.u = BDK_CSR_READ(node, BDK_FUSF_PROG);
    } while (fus_prog.s.prog);

    /* Read the fuse to make sure it was really soft blown */
    if (bdk_fuse_field_read(node, fuse) == 0)
    {
        bdk_error("Soft blowing field fuse failed\n");
        return -1;
    }
    return 0;
}

/**
 * Read the current PNAME fuses into a 128 bit number. This makes processing
 * the fuses easier in code.
 *
 * @param node   Node to read fuses for
 *
 * @return Fuse state as a 128 bit number. First fuse is bit 0, last fuse is bit 127
 */
static __uint128_t pname_read(bdk_node_t node)
{
    __uint128_t pname_fuses = 0;
    for (int fuse = BDK_MIO_FUS_FUSE_NUM_E_PNAMEX(120) / 8;
          fuse >= BDK_MIO_FUS_FUSE_NUM_E_PNAMEX(0) / 8; fuse--)
    {
        pname_fuses <<= 8;
        pname_fuses |= bdk_fuse_read_byte(node, fuse);
    }
    return pname_fuses;
}

/**
 * Extrace PNAME fuses to determine chip info
 *
 * @param node   Node to query
 *
 * @return PNAME fuse states
 */
bdk_fuse_pname_info_t bdk_fuse_pname_extract(bdk_node_t node)
{
    /* Cache the results of this function as reading fuses is slow */
    static bdk_fuse_pname_info_t result[BDK_NUMA_MAX_NODES] = { { 0, }, };
    /* Returned cached results on Asim as fuses are meaningless there */
    if (result[node].valid || bdk_is_platform(BDK_PLATFORM_ASIM))
        return result[node];

    /* Read PNAME fuses. We only need to process if some are blown */
    __uint128_t pname_fuses = pname_read(node);
    result[node].valid = 1;
    if (!pname_fuses)
        return result[node];

    int fuse = 0;
    int tmp;

    /* Read index into SKU table */
    do
    {
        tmp = bdk_extract(pname_fuses, fuse, 8);
        fuse += 8;
    } while ((tmp == 0xff) && (fuse <= 120));
    if (tmp == 0xff) /* Bad fuse setup, stop processing */
        return result[node];
    result[node].index = tmp;

    /* Read number of cores field */
    do
    {
        tmp = bdk_extract(pname_fuses, fuse, 8);
        fuse += 8;
    } while ((tmp == 0xff) && (fuse <= 120));
    if (tmp == 0xff) /* Bad fuse setup, stop processing */
        return result[node];
    result[node].cores = tmp & 0x7f;

    /* Read the production and RCLK fields */
    do
    {
        tmp = bdk_extract(pname_fuses, fuse, 8);
        fuse += 8;
    } while ((tmp == 0xff) && (fuse <= 120));
    if (tmp == 0xff) /* Bad fuse setup, stop processing */
        return result[node];
    result[node].rclk = tmp & 0x3f;
    result[node].prod = (tmp >> 6) & 3;

    /* Read segment override */
    do
    {
        tmp = bdk_extract(pname_fuses, fuse, 16);
        fuse += 16;
    } while ((tmp >= 0xff00) && (fuse <= 112));
    if (tmp >= 0xff00) /* Bad fuse setup, stop processing */
        return result[node];
    result[node].segment = tmp;

    /* Read prefix override */
    do
    {
        tmp = bdk_extract(pname_fuses, fuse, 16);
        fuse += 16;
    } while ((tmp >= 0xff00) && (fuse <= 112));
    if (tmp >= 0xff00) /* Bad fuse setup, stop processing */
        return result[node];
    result[node].prefix = tmp;

    /* Read model override */
    do
    {
        tmp = bdk_extract(pname_fuses, fuse, 8);
        fuse += 8;
    } while ((tmp == 0xff) && (fuse <= 120));
    if (tmp != 0xff)
        result[node].model = tmp;

    return result[node];
}

/**
 * Fuse initialization is called very early in startup to determine if fuses are
 * properly setup. This function is called before the GTI clock is setup, so care
 * must be taken with delays. It is also called on secondary nodes before CCPI
 * is up and running. This function may trigger a soft reset internally, forcing
 * a reload of fuse information.
 *
 * @param node   Node to check and initialize fuses on
 *
 * @return Zero on success, negative on failure
 */
int bdk_fuse_init(bdk_node_t node)
{
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
        return 0;
    /* We can't process fuses if LCK_PRD is set */
    if (bdk_fuse_read(node, BDK_MIO_FUS_FUSE_NUM_E_EFUS_LCK_PRD))
        return 0;

    bool need_reset = false;

    /* Change the default core throttling level */
    BDK_CSR_INIT(mio_fus_dat2, node, BDK_MIO_FUS_DAT2);
    if (mio_fus_dat2.s.power_limit == 0)
    {
        /* Fuse Encoding: 00 - 71%, 01 - 66%, 10 - 61%, 11 - 100% */
        bdk_fuse_soft_blow(node, BDK_MIO_FUS_FUSE_NUM_E_POWER_LIMITX(0));
        need_reset = true;
    }

    /* Check if and model specific fuses need to be updated */
    const uint16_t* fuse_list = bdk_model_get_fuses(node);
    if (fuse_list)
    {
        int i = 0;
        while (fuse_list[i])
        {
            if (bdk_fuse_read(node, fuse_list[i]) == 0)
            {
                bdk_fuse_soft_blow(node, fuse_list[i]);
                need_reset = true;
            }
            i++;
        }
    }

    /* Limit the number of cores to the PNAME limit */
    bdk_fuse_pname_info_t pname = bdk_fuse_pname_extract(node);
    if (pname.cores)
    {
        /* Figure out the number of PP_AVAILABLE fuses */
        int max_cores;
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
            max_cores = 48;
        else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
            max_cores = 24;
        else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
            max_cores = 4;
        else /* Unknown die */
            return -1;

        /* We need to blow fuses to disable any unusable cores */
        int to_disable = bdk_get_num_cores(node) - pname.cores;
        /* Start at the top fuse and work down until we find a hole. This works
           because we assume manufacturing has already giving us a contiguous
           core set. Taking unusable cores off the end remains contiguous */
        int fuse = BDK_MIO_FUS_FUSE_NUM_E_PP_AVAILABLEX(max_cores - 1);
        while (to_disable > 0)
        {
            /* Find a non-blown fuse */
            while (bdk_fuse_read(node, fuse))
                fuse--;
            /* Blow this fuse */
            bdk_fuse_soft_blow(node, fuse);
            need_reset = true;
            to_disable--;
        }
    }

    /* Check various safety lock fuses */
    const uint16_t safety_fuses[] = {
        BDK_MIO_FUS_FUSE_NUM_E_EFUS_LCK_DES,
        BDK_MIO_FUS_FUSE_NUM_E_EFUS_LCK_MAN,
        BDK_MIO_FUS_FUSE_NUM_E_EFUS_LCK_PRD, /* This must be last */
        0, /* End of list marker */
    };

    {
        int i = 0;
        while (safety_fuses[i])
        {
            if (bdk_fuse_read(node, safety_fuses[i]) == 0)
            {
                bdk_fuse_soft_blow(node, safety_fuses[i]);
                need_reset = true;
            }
            i++;
        }
    }

    /* Perform a softrest if we need one */
    if (need_reset)
    {
        /* Perform a RSL read to flush everything */
        BDK_CSR_READ(node, BDK_RST_SOFT_RST);
        /* Do the reset */
        BDK_CSR_WRITE(node, BDK_RST_SOFT_RST, 1);
        /* Spin waiting for reset */
        while (true) {}
    }

    return 0;
}
