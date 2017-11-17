#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Sort/sort.h"



   

int main ()
{  
    int data[] = { 3,44,38,5,47,15,36,26,27,2,46,4,25,44,32 };
    // 
    //int data[] = { 34};

    int size = sizeof (data) / sizeof (int);

    for (int i = 0;i<size;i++)
    {
        printf ("%d\t",data[i]);
    }
    printf ("\r\n");


    mergeSort (data, size);

    for(int i = 0; i < size; i++)
    {
        printf ("%d\t",data[i]);
    }

    printf ("\r\n");

    system ("pause");
    return 0;
}

