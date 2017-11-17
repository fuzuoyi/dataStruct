#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#include <time.h>

#include "Sort/sort.h"
#include "utils/utils.h"

   

int main ()
{  
    //SortFunc sort = &mergeSort;
    //bubbleSort
    //selectionSort
    //insertionSort
    SortFunc sort = &mergeSort;

    int data[1000];
    int size = sizeof (data) / sizeof (int);

    getIntRandArray (data, size);

    PrintIntArray (data, size);

    

    clock_t t = time_test (sort, data,size,100);

    PrintIntArray (data, size);

    printf ("time: %ld\r\n", t);

    system ("pause");
    return 0;
}


