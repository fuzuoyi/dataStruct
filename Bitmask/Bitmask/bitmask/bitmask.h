#ifndef __BITMASK_H__
#define __BITMASK_H__

#include <stdio.h>
#include <stdlib.h>

// �����Ƹ�ʽ���
void printf_bin (int S);

int setBit (int S, int index);
bool checkBit (int S, int index);
int toggleBit (int S, int index);
int clearBit (int S, int index);
int leastSignificantBit (int S);



#endif // !__BITMASK_H__

