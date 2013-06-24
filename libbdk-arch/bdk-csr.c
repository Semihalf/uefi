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
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_PEXPV_NCB:
            /* Handled by inline code, we should never get here */
            bdk_error("%s: Passed type that should be handled inline\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PEXP:
            /* We don't handle BAR0 CSRs */
            bdk_error("%s: PEXP registers not supported\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            bdk_pemx_cfg_rd_t pemx_cfg_rd;
            pemx_cfg_rd.u = 0;
            pemx_cfg_rd.s.addr = address;
            BDK_CSR_WRITE(node, BDK_PEMX_CFG_RD(busnum), pemx_cfg_rd.u);
            pemx_cfg_rd.u = BDK_CSR_READ(node, BDK_PEMX_CFG_RD(busnum));
            return pemx_cfg_rd.s.data;
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
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_PEXPV_NCB:
            /* Handled by inline code, we should never get here */
            bdk_error("%s: Passed type that should be handled inline\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PEXP:
            /* We don't handle BAR0 CSRs */
            bdk_error("%s: PEXP registers not supported\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            bdk_pemx_cfg_wr_t pemx_cfg_wr;
            pemx_cfg_wr.u = 0;
            pemx_cfg_wr.s.addr = address;
            pemx_cfg_wr.s.data = value;
            BDK_CSR_WRITE(node, BDK_PEMX_CFG_WR(busnum), pemx_cfg_wr.u);
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

