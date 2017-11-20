#include <stdio.h>
#include <stdlib.h>

void printf_bin (int S);

int setBit (int S, int index);
bool checkBit (int S, int index);
int toggleBit (int S, int index);
int clearBit (int S, int index);
int leastSignificantBit (int S);





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

void printf_bin (int S)
{
    char c[32] = {'\0'};
    _itoa_s (S,c,2);
    printf ("%d >> %s\r\n",S, c);
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