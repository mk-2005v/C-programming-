/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_crc32.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief 32-bit [CRC
 * hash](https://en.wikipedia.org/wiki/Cyclic_redundancy_check#CRC-32_algorithm)
 * algorithm
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

/**
 * @brief 32-bit CRC algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 32-bit hash result
 */
uint32_t crc32(const char* s)
{
    uint32_t crc = 0xffffffff;
    size_t i = 0;
    while (s[i] != '\0')
    {
        uint8_t byte = s[i];
        crc = crc ^ byte;
        for (uint8_t j = 8; j > 0; --j)
            crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));

        i++;
    }
    return crc ^ 0xffffffff;
}

/**
 * @brief Test function for ::crc32
 */
void test_crc32()
{
    const uint32_t test1 = 1243066710;
    assert(crc32("Hello World") == test1);
    const uint32_t test2 = 472456355;
    assert(crc32("Hello World!") == test2);
    const uint32_t test3 = 2346098258;
    assert(crc32("Hello world") == test3);
    const uint32_t test4 = 461707669;
    assert(crc32("Hello world!") == test4);
    // printf("%" PRIu32 "\n", crc32("Hello World"));
    // printf("%" PRIu32 "\n", crc32("Hello World!"));
    // printf("%" PRIu32 "\n", crc32("Hello world"));
    // printf("%" PRIX32 "\n", crc32("Hello world!"));
    printf("Tests passed\n");
}

/** @} */

/** Main function */
int main()
{
    test_crc32();
    return 0;
}
