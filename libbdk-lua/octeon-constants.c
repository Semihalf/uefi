#include <bdk.h>
#include <unistd.h>

/**
 * Called to register the octeon module
 *
 * @param L
 *
 * @return
 */
void register_octeon_constants(lua_State* L)
{
    #define push_bdk_enum(enum)             \
        do                                  \
        {                                   \
            lua_pushnumber(L, enum);        \
            lua_setfield(L, -2, #enum + 4); \
        } while (0)

    push_bdk_enum(BDK_CSR_TYPE_RSL);
    push_bdk_enum(BDK_CSR_TYPE_NCB);
    push_bdk_enum(BDK_CSR_TYPE_PEXP);
    push_bdk_enum(BDK_CSR_TYPE_PEXP_NCB);
    push_bdk_enum(BDK_CSR_TYPE_PEXPV_NCB);
    push_bdk_enum(BDK_CSR_TYPE_PCICONFIGEP);
    push_bdk_enum(BDK_CSR_TYPE_PCICONFIGRC);
#ifndef BDK_BUILD_HOST
    push_bdk_enum(BDK_MPI_FLAGS_ENABLE_CS0);
    push_bdk_enum(BDK_MPI_FLAGS_ENABLE_CS1);
    push_bdk_enum(BDK_MPI_FLAGS_ENABLE_CS2);
    push_bdk_enum(BDK_MPI_FLAGS_ENABLE_CS3);
    push_bdk_enum(BDK_MPI_FLAGS_CS_ACTIVE_HI);
    push_bdk_enum(BDK_MPI_FLAGS_ONE_WIRE);
    push_bdk_enum(BDK_MPI_FLAGS_IDLE_CLOCKS);
    push_bdk_enum(BDK_MPI_FLAGS_IDLE_LOW);
    push_bdk_enum(BDK_MPI_FLAGS_LSB_FIRST);

    push_bdk_enum(BDK_IF_SGMII);
    push_bdk_enum(BDK_IF_XAUI);
    push_bdk_enum(BDK_IF_HIGIG);
    push_bdk_enum(BDK_IF_DPI);
    push_bdk_enum(BDK_IF_LOOP);
    push_bdk_enum(BDK_IF_MGMT);
    push_bdk_enum(BDK_IF_ILK);
    push_bdk_enum(BDK_IF_BGX);

    push_bdk_enum(BDK_QLM_MODE_DISABLED);
    push_bdk_enum(BDK_QLM_MODE_PCIE_1X1);
    push_bdk_enum(BDK_QLM_MODE_PCIE_2X1);
    push_bdk_enum(BDK_QLM_MODE_PCIE_1X2);
    push_bdk_enum(BDK_QLM_MODE_PCIE_1X4);
    push_bdk_enum(BDK_QLM_MODE_PCIE_1X8);
    push_bdk_enum(BDK_QLM_MODE_ILK);
    push_bdk_enum(BDK_QLM_MODE_SGMII);
    push_bdk_enum(BDK_QLM_MODE_SGMII_SGMII);
    push_bdk_enum(BDK_QLM_MODE_SGMII_QSGMII);
    push_bdk_enum(BDK_QLM_MODE_SGMII_DISABLED);
    push_bdk_enum(BDK_QLM_MODE_QSGMII_SGMII);
    push_bdk_enum(BDK_QLM_MODE_QSGMII_QSGMII);
    push_bdk_enum(BDK_QLM_MODE_QSGMII_DISABLED);
    push_bdk_enum(BDK_QLM_MODE_DISABLED_SGMII);
    push_bdk_enum(BDK_QLM_MODE_DISABLED_QSGMII);
    push_bdk_enum(BDK_QLM_MODE_XAUI_1X4);
    push_bdk_enum(BDK_QLM_MODE_XAUI_4X1);
    push_bdk_enum(BDK_QLM_MODE_RXAUI_2X2);
    push_bdk_enum(BDK_QLM_MODE_RXAUI_1X2);
    push_bdk_enum(BDK_QLM_MODE_SATA_2X1);
    push_bdk_enum(BDK_QLM_MODE_OCI);

    push_bdk_enum(BDK_QLM_MODE_FLAG_ENDPOINT);
    push_bdk_enum(BDK_QLM_MODE_FLAG_GEN1);
    push_bdk_enum(BDK_QLM_MODE_FLAG_GEN2);
    push_bdk_enum(BDK_QLM_MODE_FLAG_GEN3);

    push_bdk_enum(BDK_QLM_LOOP_DISABLED);
    push_bdk_enum(BDK_QLM_LOOP_0_3);
    push_bdk_enum(BDK_QLM_LOOP_1_2);
    push_bdk_enum(BDK_QLM_LOOP_ALL);

    push_bdk_enum(BDK_QLM_DIRECTION_TX);
    push_bdk_enum(BDK_QLM_DIRECTION_RX);
    push_bdk_enum(BDK_QLM_DIRECTION_BOTH);
#endif
}

