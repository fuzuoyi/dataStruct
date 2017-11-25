#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#include <time.h>

// ��������ָ��
typedef void (*SortFunc)(int *, int);

// ���Ժ�������ʱ��
clock_t time_test (SortFunc, int array[], int arrayLength, int count = 1);

// ��ӡ����
void PrintIntArray (int num_array[], int arrayLength);

// ��ȡ������飬�б߽磬��������ʹ��
void getRandArray_bound (int num_array[], int arrayLength, int bound=10);

// ��ȡ������飬�ޱ߽�
void getRandArray (int num_array[], int arrayLength);

// ��ȡ������������飨���ظ�Ԫ�أ�
void getIntRandArray (int num_array[], int arrayLength);

// ��ȡ����������飨�������飬û���ظ�Ԫ�أ�
void getLinerIntRandArray (int num_array[], int arrayLength);

// ��ȡ�ź���Ĳ��ظ����飨���򡢷���
void getLinerIntArray (int num_array[], int arrayLength, bool reverseOrder = false);



#endif // !__UTILS_H__
