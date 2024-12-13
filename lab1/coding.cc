#include "coding.h"

unsigned char encode(unsigned char c)
{
    return c^0xFF;
}
unsigned char decode(unsigned char c)
{
    return c^0xFF;
}
