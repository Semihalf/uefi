#include <bdk.h>
#include <stdio.h>

#ifndef BDK_BUILD_HOST

/**
 * Read a slow CSR, not RSL or NCB.
 *
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 *
 * @return The value of the CSR
 */
uint64_t __bdk_csr_read_slow(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address)
{
    switch (type)
    {
        case BDK_CSR_TYPE_DAB:
        case BDK_CSR_TYPE_DAB32b:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_NCB32b:
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_RSL32b:
            /* Handled by inline code, we should never get here */
            bdk_error("%s: Passed type that should be handled inline\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCCBR:
        case BDK_CSR_TYPE_PCCPF:
        case BDK_CSR_TYPE_PCCVF:
        case BDK_CSR_TYPE_PEXP:
            bdk_error("%s: Register not supported\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            union pcc_dev_con_s dev_con;
            switch (busnum)
            {
                case 0:
                    dev_con.u = PCC_DEV_CON_E_PCIERC0;
                    break;
                case 1:
                    dev_con.u = PCC_DEV_CON_E_PCIERC1;
                    break;
                case 2:
                    dev_con.u = PCC_DEV_CON_E_PCIERC2;
                    break;
                case 3:
                    dev_con.u = PCC_DEV_CON_E_PCIERC3;
                    break;
                case 4:
                    dev_con.u = PCC_DEV_CON_E_PCIERC4;
                    break;
                case 5:
                    dev_con.u = PCC_DEV_CON_E_PCIERC5;
                    break;
                default:
                    bdk_error("%s: Illegal PCIe bus number\n", __FUNCTION__);
                    return -1;
            }
            return bdk_pcie_config_read32(node, 100 + dev_con.s.ecam, dev_con.s.bus, dev_con.s.func >> 3, dev_con.s.func & 7, address);
        }
    }
    return -1; /* Return -1 as this looks invalid in register dumps. Zero is too common as a good value */
}


/**
 * Write a value to a slow CSR, not RSL or NCB.
 *
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 * @param value   Value to write to the CSR
 */
void __bdk_csr_write_slow(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    switch (type)
    {
        case BDK_CSR_TYPE_DAB:
        case BDK_CSR_TYPE_DAB32b:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_NCB32b:
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_RSL32b:
            /* Handled by inline code, we should never get here */
            bdk_error("%s: Passed type that should be handled inline\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCCBR:
        case BDK_CSR_TYPE_PCCPF:
        case BDK_CSR_TYPE_PCCVF:
        case BDK_CSR_TYPE_PEXP:
            bdk_error("%s: Register not supported\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            union pcc_dev_con_s dev_con;
            switch (busnum)
            {
                case 0:
                    dev_con.u = PCC_DEV_CON_E_PCIERC0;
                    break;
                case 1:
                    dev_con.u = PCC_DEV_CON_E_PCIERC1;
                    break;
                case 2:
                    dev_con.u = PCC_DEV_CON_E_PCIERC2;
                    break;
                case 3:
                    dev_con.u = PCC_DEV_CON_E_PCIERC3;
                    break;
                case 4:
                    dev_con.u = PCC_DEV_CON_E_PCIERC4;
                    break;
                case 5:
                    dev_con.u = PCC_DEV_CON_E_PCIERC5;
                    break;
                default:
                    bdk_error("%s: Illegal PCIe bus number\n", __FUNCTION__);
                    return;
            }
            bdk_pcie_config_write32(node, 100 + dev_con.s.ecam, dev_con.s.bus, dev_con.s.func >> 3, dev_con.s.func & 7, address, value);
            break;
        }
    }
}

#endif

void __bdk_csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4)
{
    switch (num_args)
    {
        case 0:
            bdk_fatal("%s is invalid on this chip\n", name);
        case 1:
            bdk_fatal("%s(%lu) is invalid on this chip\n", name, arg1);
        case 2:
            bdk_fatal("%s(%lu,%lu) is invalid on this chip\n", name, arg1, arg2);
        case 3:
            bdk_fatal("%s(%lu,%lu,%lu) is invalid on this chip\n", name, arg1, arg2, arg3);
        default:
            bdk_fatal("%s(%lu,%lu,%lu,%lu) is invalid on this chip\n", name, arg1, arg2, arg3, arg4);
    }
}

/**
 * Read a core system register from a different node or core
 *
 * @param node   Node to read from
 * @param core   Core to read
 * @param regnum Register to read in MRS encoding
 *
 * @return Register value
 */
uint64_t bdk_sysreg_read(int node, int core, int regnum)
{
    BDK_CSR_INIT(pp_reset, node, BDK_RST_PP_RESET);
    if (pp_reset.u & (1ull<<core))
    {
        bdk_error("Attempt to read system register for core in reset\n");
        return -1;
    }

    /* Note this requires DAP_IMP_DAR[caben] = 1 */
    uint64_t address = 1ull<<47;
    address |= 0x7Bull << 36;
    address |= core << 19;
    address |= regnum << 3;
    address = bdk_numa_get_address(node, address);
    return bdk_read64_uint64(address);
}

/**
 * Write a system register for a different node or core
 *
 * @param node   Node to write too
 * @param core   Core to write
 * @param regnum Register to write in MSR encoding
 * @param value  Value to write
 */
void bdk_sysreg_write(int node, int core, int regnum, uint64_t value)
{
    BDK_CSR_INIT(pp_reset, node, BDK_RST_PP_RESET);
    if (pp_reset.u & (1ull<<core))
    {
        bdk_error("Attempt to write system register for core in reset\n");
        return;
    }

    /* Note this requires DAP_IMP_DAR[caben] = 1 */
    uint64_t address = 1ull<<47;
    address |= 0x7Bull << 36;
    address |= core << 19;
    address |= regnum << 3;
    address = bdk_numa_get_address(node, address);
    bdk_write64_uint64(address, value);
}

