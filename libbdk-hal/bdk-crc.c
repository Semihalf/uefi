#include <bdk.h>

#if 0

/**
 * Perform a crc32 on the supplied data
 *
 * @param ptr    Data to CRC
 * @param len    Length of the data
 * @param iv     Starting IV
 *
 * @return Result, can be used in IV to continue later.
 */
uint32_t bdk_crc32(void *ptr, int len, uint32_t iv)
{
    BDK_PREFETCH(ptr, 0);
    uint32_t crc32;
    BDK_MT_CRC_POLYNOMIAL(0x04c11db7); /* Bit reversed standard CRC32 polynomial - 0xedb88320 */
    crc32 = ~iv;
    /* Do endian byte swap on CRC, then use reflect mode of
    ** MT IV to reverse the bits within the bytes.  This results
    ** in a bit-reversed IV. */
    BDK_ES32(crc32, crc32);
    BDK_MT_CRC_IV_REFLECT(crc32);
    while (len>=128)
    {
        BDK_PREFETCH(ptr, 128);
        uint64_t *p = ptr;
        BDK_MT_CRC_DWORD_REFLECT(p[0]);
        BDK_MT_CRC_DWORD_REFLECT(p[1]);
        BDK_MT_CRC_DWORD_REFLECT(p[2]);
        BDK_MT_CRC_DWORD_REFLECT(p[3]);
        BDK_MT_CRC_DWORD_REFLECT(p[4]);
        BDK_MT_CRC_DWORD_REFLECT(p[5]);
        BDK_MT_CRC_DWORD_REFLECT(p[6]);
        BDK_MT_CRC_DWORD_REFLECT(p[7]);
        BDK_MT_CRC_DWORD_REFLECT(p[8]);
        BDK_MT_CRC_DWORD_REFLECT(p[9]);
        BDK_MT_CRC_DWORD_REFLECT(p[10]);
        BDK_MT_CRC_DWORD_REFLECT(p[11]);
        BDK_MT_CRC_DWORD_REFLECT(p[12]);
        BDK_MT_CRC_DWORD_REFLECT(p[13]);
        BDK_MT_CRC_DWORD_REFLECT(p[14]);
        BDK_MT_CRC_DWORD_REFLECT(p[15]);
        ptr += 128;
        len -= 128;
    }
    while (len>=8)
    {
        BDK_MT_CRC_DWORD_REFLECT(*(uint64_t*)ptr);
        ptr += 8;
        len -= 8;
    }
    if (len>=4)
    {
        BDK_MT_CRC_WORD_REFLECT(*(uint32_t*)ptr);
        ptr += 4;
        len -= 4;
    }
    if (len>=2)
    {
        BDK_MT_CRC_HALF_REFLECT(*(uint16_t*)ptr);
        ptr += 2;
        len -= 2;
    }
    if (len)
        BDK_MT_CRC_BYTE_REFLECT(*(uint8_t*)ptr);
    BDK_MF_CRC_IV_REFLECT(crc32);
    return ~crc32;
}

#endif
