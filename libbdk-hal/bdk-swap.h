/**
 * @file
 *
 * Utility functions for endian swapping
 *
 * <hr>$Revision: 32636 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Byte swap a 16 bit number
 *
 * @param x      16 bit number
 * @return Byte swapped result
 */
static inline uint16_t bdk_swap16(uint16_t x)
{
    return ((uint16_t)((((uint16_t)(x) & (uint16_t)0x00ffU) << 8) |
                       (((uint16_t)(x) & (uint16_t)0xff00U) >> 8) ));
}


/**
 * Byte swap a 32 bit number
 *
 * @param x      32 bit number
 * @return Byte swapped result
 */
static inline uint32_t bdk_swap32(uint32_t x)
{
    return ((uint32_t)((((uint32_t)(x) & (uint32_t)0x000000ffUL) << 24) |
                       (((uint32_t)(x) & (uint32_t)0x0000ff00UL) <<  8) |
                       (((uint32_t)(x) & (uint32_t)0x00ff0000UL) >>  8) |
                       (((uint32_t)(x) & (uint32_t)0xff000000UL) >> 24) ));
}


/**
 * Byte swap a 64 bit number
 *
 * @param x      64 bit number
 * @return Byte swapped result
 */
static inline uint64_t bdk_swap64(uint64_t x)
{
    return ((x >> 56) |
            (((x >> 48) & 0xfful) << 8) |
            (((x >> 40) & 0xfful) << 16) |
            (((x >> 32) & 0xfful) << 24) |
            (((x >> 24) & 0xfful) << 32) |
            (((x >> 16) & 0xfful) << 40) |
            (((x >>  8) & 0xfful) << 48) |
            (((x >>  0) & 0xfful) << 56));
}


#if __BYTE_ORDER == __BIG_ENDIAN

#define bdk_cpu_to_le16(x) bdk_swap16(x)
#define bdk_cpu_to_le32(x) bdk_swap32(x)
#define bdk_cpu_to_le64(x) bdk_swap64(x)

#define bdk_cpu_to_be16(x) (x)
#define bdk_cpu_to_be32(x) (x)
#define bdk_cpu_to_be64(x) (x)

#else

#define bdk_cpu_to_le16(x) (x)
#define bdk_cpu_to_le32(x) (x)
#define bdk_cpu_to_le64(x) (x)

#define bdk_cpu_to_be16(x) bdk_swap16(x)
#define bdk_cpu_to_be32(x) bdk_swap32(x)
#define bdk_cpu_to_be64(x) bdk_swap64(x)

#endif

#define bdk_le16_to_cpu(x) bdk_cpu_to_le16(x)
#define bdk_le32_to_cpu(x) bdk_cpu_to_le32(x)
#define bdk_le64_to_cpu(x) bdk_cpu_to_le64(x)

#define bdk_be16_to_cpu(x) bdk_cpu_to_be16(x)
#define bdk_be32_to_cpu(x) bdk_cpu_to_be32(x)
#define bdk_be64_to_cpu(x) bdk_cpu_to_be64(x)

/** @} */
