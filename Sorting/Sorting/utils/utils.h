#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#include <time.h>

// 排序函数的指针
typedef void (*SortFunc)(int *, int);

// 测试函数运行时间
clock_t time_test (SortFunc, int array[], int arrayLength, int count = 1);

// 打印数组
void PrintIntArray (int num_array[], int arrayLength);

// 获取随机数组，有边界，计数排序使用
void getRandArray_bound (int num_array[], int arrayLength, int bound=10);

// 获取随机数组，无边界
void getRandArray (int num_array[], int arrayLength);

// 获取随机的整数数组（有重复元素）
void getIntRandArray (int num_array[], int arrayLength);

// 获取随机整数数组（线性数组，没有重复元素）
void getLinerIntRandArray (int num_array[], int arrayLength);

// 获取排好序的不重复数组（正序、反序）
void getLinerIntArray (int num_array[], int arrayLength, bool reverseOrder = false);



#endif // !__UTILS_H__
