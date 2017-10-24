#include <stdio.h>
#include <stdlib.h>
#include "Sort/sort.h"

void mergeSort (int array[], int arrayLength);

   

int main ()
{  
    int data[] = { 34,1,7,5,44,30,33,22,18,4,11,4,31,11 };
    // 
    //int data[] = { 34};

    int size = sizeof (data) / sizeof (int);

    for (int i = 0;i<size;i++)
    {
        printf ("%d\t",data[i]);
    }
    printf ("\r\n");


    insertionSort (data, size);

    for(int i = 0; i < size; i++)
    {
        printf ("%d\t",data[i]);
    }

    printf ("\r\n");

    system ("pause");
    return 0;
}



void mergeSort (int array[], int arrayLength)
{
    auto MSort = [](int A[], int TmpArray, int start, int end) 
    {

    };



}