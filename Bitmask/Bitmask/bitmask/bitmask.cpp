#include "bitmask.h"



void printf_bin (int S)
{
    char c[32] = { '\0' };
    _itoa_s (S, c, 2);
    printf ("%d >> %s\r\n", S, c);
}


int setBit (int S, int index)
{
    return S | (1 << index);
}


bool checkBit (int S, int index)
{
    return (S & (1 << index));
}

int toggleBit (int S, int index)
{
    return S ^ (1 << index);
}
int clearBit (int S, int index)
{
    return S&(~(1 << index));
}

int leastSignificantBit (int S)
{
    return S&((~S) + 1);
}

