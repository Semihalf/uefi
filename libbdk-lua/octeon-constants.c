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
#endif
}

