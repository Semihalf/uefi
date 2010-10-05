/**
 * @file
 *
 * PCI / PCIe packet engine related structures.
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * PCI / PCIe packet instruction header format
 */
typedef union
{
    uint64_t u64;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t            r :     1;      /**< Packet is RAW */
        uint64_t            g :     1;      /**< Gather list is used */
        uint64_t            dlengsz : 14;   /**< Data length / Gather list size */
        uint64_t            fsz     : 6;    /**< Front data size */
        uint64_t            qos     : 3;    /**< SSO QoS queue */
        uint64_t            grp     : 4;    /**< SSO Group */
        uint64_t            rs      : 1;    /**< Real short */
        bdk_sso_tag_type_t tt      : 2;    /**< SSO Tag type */
        uint64_t            tag     : 32;   /**< SSO 32 bit tag */
#else
	uint64_t            tag     : 32;
	bdk_sso_tag_type_t tt      : 2;
	uint64_t            rs      : 1;
	uint64_t            grp     : 4;
	uint64_t            qos     : 3;
	uint64_t            fsz     : 6;
	uint64_t            dlengsz : 14;
	uint64_t            g :     1;
	uint64_t            r :     1;
#endif
    } s;
} bdk_npi_inst_hdr_t;

/**
 * PCI / PCIe packet data pointer formats 0-3
 */
typedef union
{
    uint64_t dptr0;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    es      : 2;    /**< Endian swap mode */
        uint64_t    ns      : 1;    /**< No snoop */
        uint64_t    ro      : 1;    /**< Relaxed ordering */
        uint64_t    addr    : 60;   /**< PCI/PCIe address */
#else
        uint64_t    addr    : 60;
        uint64_t    ro      : 1;
        uint64_t    ns      : 1;
        uint64_t    es      : 2;
#endif
    } dptr1;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    pm      : 2;    /**< Parse mode */
        uint64_t    sl      : 7;    /**< Skip length */
        uint64_t    addr    : 55;   /**< PCI/PCIe address */
#else
        uint64_t    addr    : 55;
        uint64_t    sl      : 7;
        uint64_t    pm      : 2;
#endif
    } dptr2;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    es      : 2;    /**< Endian swap mode */
        uint64_t    ns      : 1;    /**< No snoop */
        uint64_t    ro      : 1;    /**< Relaxed ordering */
        uint64_t    pm      : 2;    /**< Parse mode */
        uint64_t    sl      : 7;    /**< Skip length */
        uint64_t    addr    : 51;   /**< PCI/PCIe address */
#else
        uint64_t    addr    : 51;
        uint64_t    sl      : 7;
        uint64_t    pm      : 2;
        uint64_t    ro      : 1;
        uint64_t    ns      : 1;
        uint64_t    es      : 2;
#endif
    } dptr3;
} bdk_npi_dptr_t;

