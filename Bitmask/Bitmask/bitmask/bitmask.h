#ifndef __BITMASK_H__
#define __BITMASK_H__

#include <stdio.h>
#include <stdlib.h>

// 二进制格式输出
void printf_bin (int S);


bool checkBit (int S, int index); // 位状态


int setBit (int S, int index);    // 位置高
int toggleBit (int S, int index); // 位翻转
int clearBit (int S, int index);  // 位清零

int leastSignificantBit (int S);  // 最小有效位



#endif // !__BITMASK_H__

