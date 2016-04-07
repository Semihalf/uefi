#include <bdk.h>
#include <stdarg.h>
#include <libfdt.h>

static const char *QLM_BGX_MODE_MAP[BDK_QLM_MODE_LAST] =
{
    [BDK_QLM_MODE_SGMII_4X1]    = "sgmii",
    [BDK_QLM_MODE_SGMII_2X1]    = "sgmii",
    [BDK_QLM_MODE_XAUI_1X4]     = "xaui",
    [BDK_QLM_MODE_RXAUI_2X2]    = "rxaui",
    [BDK_QLM_MODE_RXAUI_1X2]    = "rxaui",
    [BDK_QLM_MODE_XFI_4X1]      = "xfi",
    [BDK_QLM_MODE_XFI_2X1]      = "xfi",
    [BDK_QLM_MODE_XLAUI_1X4]    = "xlaui",
    [BDK_QLM_MODE_10G_KR_4X1]   = "xfi-10g-kr",
    [BDK_QLM_MODE_10G_KR_2X1]   = "xfi-10g-kr",
    [BDK_QLM_MODE_40G_KR4_1X4]  = "xlaui-40g-kr",
    [BDK_QLM_MODE_QSGMII_4X1]   = "sgmii",
};

/**
 * Delete a node from a device tree, using printf style arguments to build the
 * node name
 *
 * @param fdt    Tree to delete the node from
 * @param format Printf style format string for the name
 *
 * @return Zero on success, negative on failure. Node that if the node doesn't exist when
 *         called, that is considered a success.
 */
static int devtree_node_del(void *fdt, const char *format, ...) __attribute__ ((format(printf, 2, 3)));
static int devtree_node_del(void *fdt, const char *format, ...)
{
    /* Format the name into a string */
    char name[64];
    va_list args;
    va_start(args, format);
    vsnprintf(name, sizeof(name), format, args);
    va_end(args);
    /* Find the node */
    int status = fdt_path_offset(fdt, name);
    if (status >= 0)
    {
        /* Delete the node without removing its space, so offsets are unaffected */
        status = fdt_nop_node(fdt, status);
        if (status != 0)
        {
            bdk_error("Unable to delete %s in FDT (%d:%s)\n", name, status, fdt_strerror(status));
            return -1;
        }
        BDK_TRACE(FDT_OS, "    Deleted FDT node %s\n", name);
    }
    return 0;
}

/**
 * Find a node with the given property name. Call with a startoffset of -1 on the
 * first call, then keep calling until the return value is -1.
 *
 * @param fdt      Tree to search
 * @param startoffset
 *                 Starting node, which has already been searched. Pass -1 on first call
 * @param propname Name of property to search for
 *
 * @return Node with property name, or -1 when iteration complete
 */
static int devtree_node_offset_by_prop_name(const void *fdt, int startoffset, const char *propname)
{
    int node;

    /* Figure out the starting node */
    if (startoffset == -1)
        node = 0;
    else
        node = fdt_next_node(fdt, startoffset, NULL);

    /* Search until we iterate through all nodes */
    while (node >= 0)
    {
        int proplen = 0;
        const void *propvalue = fdt_getprop(fdt, node, propname, &proplen);
        if (propvalue)
        {
            /* Found the desired prop name, return this node */
            return node;
        }
        /* Not found, proceed to next node */
        node = fdt_next_node(fdt, node, NULL);
    }
    /* Ran out of nodes, return -1 */
    return -1;
}

/**
 * Load a device tree DTB file, allocating new space for it
 *
 * @param filename File to load
 *
 * @return NULL on failure, or a pointer to the device tree
 */
static void *devtree_load(const char *filename)
{
    /* Attempt to open the input file */
    FILE *inf = fopen(filename, "rb");
    if (!inf)
        return NULL; /* Fails silently so we can search for DTB files */

    int fdt_size = 0x20000; /* Assume 128KB is big enough for FDT */
    void *fdt = malloc(fdt_size);
    if (!fdt)
    {
        bdk_error("Unable to allocate memory to load FDT\n");
        fclose(inf);
        return NULL;
    }

    /* Read the entire device tree */
    int count = fread(fdt, 1, fdt_size, inf);
    fclose(inf);

    /* Make sure the read succeeded */
    if (count < (int)sizeof(struct fdt_header))
    {
        bdk_error("Unable to read %s\n", filename);
        free(fdt);
        return NULL;
    }

    if (fdt_check_header(fdt))
    {
        bdk_error("Invalid FDT header read from %s\n", filename);
        free(fdt);
        return NULL;
    }

    /* Make sure we read enough data to contain the FDT */
    int correct_size = fdt_totalsize(fdt);
    if (count < correct_size)
    {
        bdk_error("Unable to read FDT from %s\n", filename);
        free(fdt);
        return NULL;
    }

    /* Check if a CRC32 was added on the end of the FDT */
    if (count >= correct_size + 4)
    {
        uint32_t crc32 = bdk_crc32(fdt, correct_size, 0);
        uint32_t correct_crc32 = *(uint32_t *)((const char *)fdt + correct_size);
        /* CRC32 is stored in same endianness as FDT */
        correct_crc32 = fdt32_to_cpu(correct_crc32);
        if (crc32 != correct_crc32)
        {
            bdk_error("FDT failed CRC32 verification (%s)\n", filename);
            free(fdt);
            return NULL;
        }
    }
    /* Tell the FDT it has extra space */
    fdt_set_totalsize(fdt,  fdt_size);
    return fdt;
}

/**
 * Copy the current BDK config settings into a device tree
 *
 * @param fdt    Tree to receive the new settings
 *
 * @return Zero on success, negative on failure
 */
static int devtree_copy_settings(void *fdt)
{
    /* If the bdk config node exists, delete it, removing all attributes and
       sub nodes */
    if (devtree_node_del(fdt, "/cavium,bdk"))
        return -1;

    /* Create a bdk config node */
    int top = fdt_add_subnode(fdt, 0, "cavium,bdk");
    if (top < 0)
    {
        bdk_error("Unable to create cavium,bdk node in FDT (%d:%s)\n", top, fdt_strerror(top));
        return -1;
    }
    BDK_TRACE(FDT_OS, "    Created /cavium,bdk\n");

    /* Copy all bdk attributes to the new tree */
    void *bdk_fdt = bdk_config_get_fdt();
    int bdk_top = fdt_path_offset(bdk_fdt, "/cavium,bdk");
    int offset = fdt_first_property_offset(bdk_fdt, bdk_top);
    while (offset >= 0)
    {
        const char *name = NULL;
        int blob_size = 0;
        const char *data = fdt_getprop_by_offset(bdk_fdt, offset, &name, &blob_size);
        fdt_setprop(fdt, top, name, data, blob_size);
        offset = fdt_next_property_offset(bdk_fdt, offset);
    }
    BDK_TRACE(FDT_OS, "    Copied /cavium,bdk properties\n");
    return 0;
}

/**
 * The operating system following the BDK needs soem changes made to the device
 * tree, making it match the dynamic state of the hardware
 *
 * @param fdt    Device tree to update
 *
 * @return Zero on success, negative on failure
 */
static int devtree_fixups(void *fdt)
{
    /* Extract our MAC address info so we can assign them in the device tree */
    uint64_t next_free_mac_address = bdk_config_get_int(BDK_CONFIG_MAC_ADDRESS);
    int num_free_mac_addresses = bdk_config_get_int(BDK_CONFIG_MAC_ADDRESS_NUM);

    /* Loop through all possible node IDs */
    for (bdk_node_t node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        /* The /soc name is used a lot, create a string containing it */
        char soc[32];
        if (node == 0)
            snprintf(soc, sizeof(soc), "soc@0");
        else
            snprintf(soc, sizeof(soc), "soc@%x000,00000000", node);

        /* 1) Remove unwanted CPUs and L2 caches */
        int num_cpus;
        if (bdk_numa_exists(node))
        {
            /* Figure out the number of CPUs */
            num_cpus = bdk_get_num_cores(node);
            /* We'll need to delete extra cpus below */
        }
        else
        {
            /* Node doesn't exist, so no CPUs */
            num_cpus = 0;
            /* Delete the entire cpu cluster */
            if (devtree_node_del(fdt, "/cpus/cpu-map/cluster%d", node))
                return -1;
            /* Delete the L2 for the node */
            if (devtree_node_del(fdt, "/cpus/l2-cache%d", node))
                return -1;
            /* We still need to delete the CPUs in /cpus/cpu*. This
               is done below */
        }

        /* Loop through node's cpu numbers and delete ones that don't exist */
        for (int cpu = 0; cpu < 64; cpu++)
        {
            if (cpu >= num_cpus)
            {
                /* Delete unused CPUs out of the CPU cluster */
                if (bdk_numa_exists(node) &&
                    devtree_node_del(fdt, "/cpus/cpu-map/cluster%d/core%d", node, cpu))
                        return -1;
                /* Delete unused CPUs out of /cpus/cpu* */
                int cpu_id = (node << 16) | ((cpu & 0xf0) << 4) | (cpu & 0xf);
                if (devtree_node_del(fdt, "/cpus/cpu@%x", cpu_id))
                    return -1;
            }
        }

        /* 2) Remove unwanted NUMA node entries:
             - /interrupt-controller@801000000000/gic-its@901000020000
             - /soc@100000000000
             - /memory@10000000000
             - /distance-map */
        if (!bdk_numa_exists(node))
        {
            uint64_t address = bdk_numa_get_address(node, BDK_GIC_BAR_E_GIC_PF_BAR2);
            uint32_t high = address >> 32;
            uint32_t low = address & bdk_build_mask(32);
            /* Delete the ITS interrupt entry */
            if (devtree_node_del(fdt, "/interrupt-controller@8010,00000000/gic-its@%x,%08x", high, low))
                return -1;
            /* Delete the SOC entry */
            if (devtree_node_del(fdt, "/%s", soc))
                return -1;
            /* Delete the memory entry */
            if (devtree_node_del(fdt, "/memory@%08lx", (uint64_t)node << 40))
                return -1;
        }

        /* 3) Remove unwanted PEM entries */
        if (bdk_numa_exists(node))
        {
            int num_pems = bdk_pcie_get_num_ports(node);
            for (int pem = 0; pem < 8; pem++)
            {
                /* Check that the PEM hardware exists on this chip */
                bool del_pem = (pem >= num_pems);
                /* Check that the PEM is on */
                if (!del_pem)
                {
                    BDK_CSR_INIT(pemx_on, node, BDK_PEMX_ON(pem));
                    del_pem = !pemx_on.s.pemon;
                }
                /* Check that the PEM is not in reset */
                if (!del_pem)
                {
                    BDK_CSR_INIT(soft_prst, node, BDK_RST_SOFT_PRSTX(pem));
                    del_pem = soft_prst.s.soft_prst;
                }
                /* Check that the PEM has link */
                if (!del_pem)
                {
                    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pem));
                    del_pem = (pciercx_cfg032.s.dlla == 0) || (pciercx_cfg032.s.lt == 1);
                }
                /* Delete PEMs that fail any of the above checks */
                if (del_pem)
                {
                    uint64_t address = bdk_numa_get_address(node, BDK_PEM_BAR_E_PEMX_PF_BAR0(pem));
                    uint32_t high = address >> 32;
                    uint32_t low = address & bdk_build_mask(32);
                    if (devtree_node_del(fdt, "/%s/pci@%x,%08x", soc, high, low))
                        return -1;
                }
            }
        }

        /* 4) Remove unwanted QLM mode entries.  For each BGX 0, 1 on node0,
          and 2, 3 on node 1, determine the mode.  This will be one of:

           See QLM_BGX_MODE_MAP above

          For each BGX, scan for nodes containing the property named
          "qlm-mode".  This will have property strings of the form "#,mode",
          where # is a BGX number (0..4) and mode is one of the modes listed
          above.  If the BGX number of the "qlm-mode" property matches, do one
          of the following:

          A) If the mode matches the BGX mode, remove the "qlm-mode" property.
          B) If the mode doesn't match the BGX mode, remove the entire node
          containing the "qlm-mode" property

          Note that some "qlm-mode" properties have multiple values of this form:

            qlm-mode = "2,xfi","2,sgmii"; for example.

          In this case the match must be tried against each value.
        5) Populate MAC addresses.  For each child node of the BGX nodes,
          add a property named "local-mac-address" set to the next available
          MAC address obtained from the Manufacturing data.  If no MAC address
          is available, don't add the "local-mac-address" property. */
        if (bdk_numa_exists(node))
        {
            /* Find all nodes with the property "qlm-mode" */
            const char *propname = "qlm-mode";
            int fdt_node = devtree_node_offset_by_prop_name(fdt, -1, propname);
            while (fdt_node >= 0)
            {
                /* Figure out the next node. If we delete this one, the link
                   will be gone later */
                int next_node = devtree_node_offset_by_prop_name(fdt, fdt_node, propname);
                const char *fdt_node_name = fdt_get_name(fdt, fdt_node, NULL);
                /* We will delete the node if none of the properties modes matches */
                bool update_node = true;
                bool delete_node = true;
                /* Get the value of the property */
                int proplen = 0;
                const char *propvalue = fdt_getprop(fdt, fdt_node, propname, &proplen);
                const char *propend = propvalue + proplen;
                const char *item = propvalue;
                /* Loop through all the string values of the properly */
                while (item < propend)
                {
                    /* Each string is "bgx_number,mode". Extract the two parts.
                       The BGX number increments through bgx ports (4), then
                       through BGXs, then other nodes */
                    int bgx_id = strtol(item, NULL, 0);
                    bdk_node_t bgx_node = bdk_extract(bgx_id, 8, 2);
                    int bgx_interface = bdk_extract(bgx_id, 4, 4);
                    int bgx_index = bdk_extract(bgx_id, 0, 4);
                    const char *comma = strchr(item, ',');
                    if (bgx_node != node)
                    {
                        /* For different node, skip it */
                        update_node = false;
                        delete_node = false;
                        break;
                    }
                    /* Stop searching if any string is invalid */
                    if (!comma || (bgx_interface >= 4))
                    {
                        /* Invalid: Node will be deleted */
                        BDK_TRACE(FDT_OS, "    %s[qlm-mode] is invalid (%s)\n", fdt_node_name, item);
                        break;
                    }
                    int qlm = bdk_qlm_get(bgx_node, BDK_IF_BGX, bgx_interface, bgx_index);
                    bdk_qlm_modes_t qlm_mode = (qlm == -1) ? BDK_QLM_MODE_DISABLED : bdk_qlm_get_mode(node, qlm);
                    const char *qlm_mode_str = QLM_BGX_MODE_MAP[qlm_mode];
                    /* If the string matches the QLM mode, we will keep this node */
                    if (qlm_mode_str && (strcasecmp(qlm_mode_str, comma + 1) == 0))
                    {
                        /* Property matches, keep this node */
                        delete_node = false;
                        BDK_TRACE(FDT_OS, "    %s[qlm-mode] = %s (match)\n", fdt_node_name, item);
                        break;
                    }
                    /* Move to the next list item */
                    item += strlen(item) + 1;
                }
                /* Delete the node if it didn't match */
                if (delete_node)
                {
                    BDK_TRACE(FDT_OS, "    Delete %s with unused qlm-mode\n", fdt_node_name);
                    if (fdt_nop_node(fdt, fdt_node))
                    {
                        bdk_error("Failed to delete node %s\n", fdt_node_name);
                        return -1;
                    }
                }
                else if (update_node)
                {
                    /* Remove the custom property from the tree */
                    if (fdt_nop_property(fdt, fdt_node, propname))
                    {
                        bdk_error("Failed to NOP property %s[%s]\n", fdt_node_name, propname);
                        return -1;
                    }
                    BDK_TRACE(FDT_OS, "    Removed property %s[%s]\n", fdt_node_name, propname);
                    /* See if this node needs a MAC address updated */
                    propvalue = fdt_getprop(fdt, fdt_node, "local-mac-address", &proplen);
                    if (propvalue && num_free_mac_addresses)
                    {
                        if (fdt_setprop_inplace_u64(fdt, fdt_node, "local-mac-address", next_free_mac_address))
                        {
                            bdk_error("Failed to update property %s[local-mac-address]\n", fdt_node_name);
                            return -1;
                        }
                        BDK_TRACE(FDT_OS, "    Set %s[local-mac-address] = 0x%lx\n", fdt_node_name, next_free_mac_address);
                        next_free_mac_address++;
                        num_free_mac_addresses--;
                    }
                    else if (propvalue)
                    {
                        if (fdt_nop_property(fdt, fdt_node, "local-mac-address"))
                        {
                            bdk_error("Failed to NOP property %s[local-mac-address]\n", fdt_node_name);
                            return -1;
                        }
                    }
                }
                fdt_node = next_node;
            }
        }

        /* 6) Set refclkuua clock rate.  For the node "/refclkuaa", set the
          "clock-frequency" property to the value of:
           (115200 * (64 * UAA_IBRD_REG + UAA_FBRD_REG)) / 4 */
        if (bdk_numa_exists(node))
        {
            char refclkuua[32];
            snprintf(refclkuua, sizeof(refclkuua), "/%s/refclkuua", soc);
            BDK_CSR_INIT(ibrd, node, BDK_UAAX_IBRD(0));
            BDK_CSR_INIT(fbrd, node, BDK_UAAX_IBRD(0));
            int uaa_clock = ((ibrd.u * 64) + fbrd.u) * 115200 * (64 / 4);
            int fdt_node = fdt_path_offset(fdt, refclkuua);
            if ((fdt_node >= 0) && fdt_setprop_inplace_u32(fdt, fdt_node, "clock-frequency", uaa_clock))
            {
                bdk_error("Unable to edit %s[clock-frequency] in FDT\n", refclkuua);
                return -1;
            }
            BDK_TRACE(FDT_OS, "    Set %s[clock-frequency] = %d\n", refclkuua, uaa_clock);
        }

        /* 7) Set the sclk clock rate.  For the node "/sclk", set the
          "clock-frequency" property to the value to the system SCLK rate (800000000 or so). */
        if (bdk_numa_exists(node))
        {
            char sclk_name[32];
            snprintf(sclk_name, sizeof(sclk_name), "/%s/sclk", soc);
            int rate = bdk_clock_get_rate(node, BDK_CLOCK_SCLK);
            int fdt_node = fdt_path_offset(fdt, sclk_name);
            if ((fdt_node >= 0) && fdt_setprop_inplace_u32(fdt, fdt_node, "clock-frequency", rate))
            {
                bdk_error("Unable to edit %s[clock-frequency] in FDT\n", sclk_name);
                return -1;
            }
            BDK_TRACE(FDT_OS, "    Set %s[clock-frequency] = %d\n", sclk_name, rate);
        }

        /* 8) Patch ECAM property names.  For systems that are *not* either T88
          pass1, nor T88 Pass2-2-node, find all "compatible" properties with a
          value "cavium,pci-host-thunder-ecam", and change the compatible
          value to "pci-host-ecam-generic". */
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) ||
            (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && !bdk_numa_is_only_one()))
        {
            const char *new_compatible = "pci-host-ecam-generic";
            const int new_compatible_len = strlen(new_compatible);
            int fdt_node = -1;
            fdt_node = fdt_node_offset_by_compatible(fdt, -1, "cavium,pci-host-thunder-pem");
            while (fdt_node > 0)
            {
                const char *fdt_node_name = fdt_get_name(fdt, fdt_node, NULL);
                if (fdt_setprop_inplace(fdt, fdt_node, "compatible", new_compatible, new_compatible_len))
                {
                    bdk_error("Unable to edit %s[compatible] in FDT\n", fdt_node_name);
                    return -1;
                }
                BDK_TRACE(FDT_OS, "    Changed %s[compatible] to %s\n", fdt_node_name, new_compatible);
                fdt_node = fdt_node_offset_by_compatible(fdt, fdt_node, "cavium,pci-host-thunder-pem");
            }
        }

        /* 9) Patch memory size.  For the memory node corresponding to each
          NUMA node, set the memory size.  These nodes have the following paths:

            - "/memory@0"
            - "/memory@10000000000"
          These nodes have a "reg" property of the following form:

            reg = <base_63_32 base_31_0 size_63_32 size_31_0>

          The base should be set the the physical address of the non-secure memory.
          The size should be set to the size of the non-secure memory on the corresponding node */
        if (bdk_numa_exists(node))
        {
            char mem[32];
            snprintf(mem, sizeof(mem), "/memory@%08lx", (uint64_t)node << 40);
            int fdt_node = fdt_path_offset(fdt, mem);
            if (fdt_node >= 0)
            {
                int mem_info_len = 0;
                const uint32_t *mem_info = fdt_getprop(fdt, fdt_node, "reg", &mem_info_len);
                if (mem_info && (mem_info_len == sizeof(uint32_t) * 4))
                {
                    uint64_t base = fdt32_to_cpu(mem_info[1]);
                    base |= (uint64_t)fdt32_to_cpu(mem_info[0]) << 32;
                    uint64_t size = bdk_dram_get_size_mbytes(node) << 20;
                    size -= base;
                    uint32_t new_mem[4];
                    new_mem[0] = cpu_to_fdt32(base >> 32);    /* High part of memory base */
                    new_mem[1] = cpu_to_fdt32(base);          /* Low part of memory base */
                    new_mem[2] = cpu_to_fdt32(size >> 32);    /* High part of memory size */
                    new_mem[3] = cpu_to_fdt32(size);          /* Low part of memory size */
                    if (fdt_setprop_inplace(fdt, fdt_node, "reg", new_mem, sizeof(new_mem)))
                    {
                        bdk_error("Unable to edit %s[reg] in FDT\n", mem);
                        return -1;
                    }
                    BDK_TRACE(FDT_OS, "    Set %s[reg] = mem size 0x%lx\n", mem, size);
                }
            }
        }
    }

    if (bdk_numa_is_only_one() && devtree_node_del(fdt, "/distance-map"))
        return -1;

    return 0;
}

/**
 * Called to load the operating system device tree and get it ready for following
 * software
 *
 * @return Zero on success, negative on failure
 */
int devtree_process(void)
{
    void *fdt = NULL;
    const char *model = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
    const char *revision = bdk_config_get_str(BDK_CONFIG_BOARD_REVISION);
    char filename[64];

    /* Load BOARD-REVISION-linux.dtb if it is there */
    if (model && revision)
    {
        snprintf(filename, sizeof(filename), "/fatfs/%s-%s-linux.dtb", model, revision);
        fdt = devtree_load(filename);
    }

    /* Load BOARD-linux.dtb if it is there */
    if (!fdt && model)
    {
        snprintf(filename, sizeof(filename), "/fatfs/%s-linux.dtb", model);
        fdt = devtree_load(filename);
    }

    /* Load generic-linux.dtb if it is there */
    if (!fdt)
    {
        snprintf(filename, sizeof(filename), "/fatfs/generic-linux.dtb");
        fdt = devtree_load(filename);
    }

    /* Warn if we could load a device tree */
    if (!fdt)
    {
        printf("\33[1m"); /* Bold */
        bdk_warn("\n");
        bdk_warn("********************************************************\n");
        bdk_warn("* Operating system device tree not found. Operating\n");
        bdk_warn("* system may not boot properly. DTB file not found for\n");
        bdk_warn("* board \"%s\".\n", model);
        bdk_warn("********************************************************\n");
        bdk_warn("\n");
        printf("\33[0m"); /* Normal */
        return -1;
    }

    BDK_TRACE(FDT_OS, "Processing FDT for Operating System (%s)\n", filename);

    /* Copy the BDK settings to the new tree */
    if (devtree_copy_settings(fdt))
    {
        free(fdt);
        return -1;
    }

    /* Perform device tree fixups for Linux */
    if (devtree_fixups(fdt))
    {
        free(fdt);
        return -1;
    }

    /* Compress the final tree */
    int status = fdt_pack(fdt);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        free(fdt);
        return -1;
    }

    /* Swap the BDK config FDT for this one */
    if (bdk_config_set_fdt(fdt))
    {
        bdk_error("Failed to replace config FDT\n");
        free(fdt);
        return -1;
    }
    BDK_TRACE(FDT_OS, "Using FDT for Operating System\n");

    return 0;
}
