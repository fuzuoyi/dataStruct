#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#include <time.h>

typedef void (*SortFunc)(int *, int);


clock_t time_test (SortFunc, int array[], int arrayLength, int count = 1);
void PrintIntArray (int num_array[], int arrayLength);

void getIntRandArray (int num_array[], int arrayLength);
void getLinerIntRandArray (int num_array[], int arrayLength);




#endif // !__UTILS_H__
