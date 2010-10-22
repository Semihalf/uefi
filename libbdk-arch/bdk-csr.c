#include <bdk.h>

uint64_t __bdk_csr_read_slow(bdk_csr_type_t type, int busnum, int size, uint64_t address)
{
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
            /* Handled by inline code */
            return 0;

        case BDK_CSR_TYPE_PEXP:
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            bdk_pemx_cfg_rd_t pemx_cfg_rd;
            pemx_cfg_rd.u64 = 0;
            pemx_cfg_rd.s.addr = address;
            BDK_CSR_WRITE(BDK_PEMX_CFG_RD(busnum), pemx_cfg_rd.u64);
            pemx_cfg_rd.u64 = BDK_CSR_READ(BDK_PEMX_CFG_RD(busnum));
            return pemx_cfg_rd.s.data;
        }

        case BDK_CSR_TYPE_SRIOMAINT:
        {
            uint32_t result;
            if (bdk_srio_config_read32(busnum, 0, -1, 0, 0, address, &result) == 0)
                return result;
            else
                return 0;
        }
    }
    return 0;
}


void __bdk_csr_write_slow(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
            /* Handled by inline code */
            break;

        case BDK_CSR_TYPE_PEXP:
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            bdk_pemx_cfg_wr_t pemx_cfg_wr;
            pemx_cfg_wr.u64 = 0;
            pemx_cfg_wr.s.addr = address;
            pemx_cfg_wr.s.data = value;
            BDK_CSR_WRITE(BDK_PEMX_CFG_WR(busnum), pemx_cfg_wr.u64);
            break;
        }

        case BDK_CSR_TYPE_SRIOMAINT:
            bdk_srio_config_write32(busnum, 0, -1, 0, 0, address, value);
            break;
    }
}

