#ifndef __BITMASK_H__
#define __BITMASK_H__

#include <stdio.h>
#include <stdlib.h>

// �����Ƹ�ʽ���
void printf_bin (int S);


bool checkBit (int S, int index); // λ״̬


int setBit (int S, int index);    // λ�ø�
int toggleBit (int S, int index); // λ��ת
int clearBit (int S, int index);  // λ����

int leastSignificantBit (int S);  // ��С��Чλ



#endif // !__BITMASK_H__

