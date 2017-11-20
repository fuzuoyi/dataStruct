#include <stdio.h>
#include <stdlib.h>
#include "bitmask/bitmask.h"







int main ()
{
    int s = 75;
    printf_bin (s);

    checkBit (s, 2);

    s = clearBit (s, 0);
    s = clearBit (s, 1);
    leastSignificantBit (s);

    printf_bin (s);

    system ("pause");
    return 0;
}

