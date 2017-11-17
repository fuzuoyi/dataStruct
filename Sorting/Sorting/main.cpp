#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#include <time.h>

#include "Sort/sort.h"

typedef void (*SortFunc)(int *,int);   


clock_t time_test (SortFunc, int array[], int arrayLength, int count);

void getRandArray (int arrayLength, int array[]);
   

int main ()
{  
    int data[] = { 3,44,38,5,47,15,36,26,27,2,46,4,25,44,32 };
    // 
    //int data[] = { 34};

    int size = sizeof (data) / sizeof (int);

    //for (int i = 0;i<size;i++)
    //{
    //    printf ("%d\t",data[i]);
    //}
    //printf ("\r\n");


    //mergeSort (data, size);

    //for(int i = 0; i < size; i++)
    //{
    //    printf ("%d\t",data[i]);
    //}

    //printf ("\r\n");

    SortFunc sort = &insertionSort;

    clock_t t = time_test (sort, data,size,10000);
    for(int i = 0; i < size; i++)
    {
        printf ("%d\t", data[i]);
    }
    printf ("time: %ld\r\n", t);

    system ("pause");
    return 0;
}

void getRandArray (int arrayLength, int array[])
{

}


clock_t time_test (SortFunc sort, int num_array[], int arrayLength, int count)
{
    clock_t start, end, duration=0;

    int *temp_array = (int*) malloc (arrayLength * sizeof (int));
    memcpy (temp_array, num_array, arrayLength * sizeof (int));


    

    for(int i = 0; i < count; i++)
    {
        
        memcpy (num_array, temp_array, arrayLength * sizeof (int));

        start = clock ();
        sort (num_array, arrayLength);
        end = clock ();

        duration += end - start;
    }

    free (temp_array);

    return duration;
}