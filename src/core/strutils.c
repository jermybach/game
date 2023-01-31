#include "core.h"
#include "strutils.h"

#define rotateleft32(n, count) (n << count) | (n >> (32 - count))
#define rotateright32(n, count) (n >> count) | (n << (32 - count))

uint32_t core_hash32(void *data, size_t length)
{
        uint32_t result = 0xFFFFFFFF;
        
        for (size_t i = 0; i < length; i++)
        {
                uint8_t byte = ((uint8_t*)data)[i];
                result = 0x8a88e0ff + byte ^ rotateleft32(result, 1);
        }
        return result;
}
