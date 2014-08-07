#include <bdk.h>

#define CRC32X(out, in, data) asm ("CRC32X %w0, %w1, %x2" : "=r" (out) : "r" (in), "r" (data));
#define CRC32W(out, in, data) asm ("CRC32W %w0, %w1, %w2" : "=r" (out) : "r" (in), "r" (data));
#define CRC32H(out, in, data) asm ("CRC32H %w0, %w1, %w2" : "=r" (out) : "r" (in), "r" (data));
#define CRC32B(out, in, data) asm ("CRC32B %w0, %w1, %w2" : "=r" (out) : "r" (in), "r" (data));

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
    uint32_t crc32 = iv;
    while (len>=128)
    {
        BDK_PREFETCH(ptr, 128);
        uint64_t *p = ptr;
        CRC32X(crc32, crc32, p[0]);
        CRC32X(crc32, crc32, p[1]);
        CRC32X(crc32, crc32, p[2]);
        CRC32X(crc32, crc32, p[3]);
        CRC32X(crc32, crc32, p[4]);
        CRC32X(crc32, crc32, p[5]);
        CRC32X(crc32, crc32, p[6]);
        CRC32X(crc32, crc32, p[7]);
        CRC32X(crc32, crc32, p[8]);
        CRC32X(crc32, crc32, p[9]);
        CRC32X(crc32, crc32, p[10]);
        CRC32X(crc32, crc32, p[11]);
        CRC32X(crc32, crc32, p[12]);
        CRC32X(crc32, crc32, p[13]);
        CRC32X(crc32, crc32, p[14]);
        CRC32X(crc32, crc32, p[15]);
        ptr += 128;
        len -= 128;
    }
    while (len>=8)
    {
        CRC32X(crc32, crc32, *(uint64_t*)ptr);
        ptr += 8;
        len -= 8;
    }
    if (len>=4)
    {
        CRC32W(crc32, crc32, *(uint32_t*)ptr);
        ptr += 4;
        len -= 4;
    }
    if (len>=2)
    {
        CRC32H(crc32, crc32, *(uint16_t*)ptr);
        ptr += 2;
        len -= 2;
    }
    if (len)
        CRC32B(crc32, crc32, *(uint8_t*)ptr);
    return crc32;
}

