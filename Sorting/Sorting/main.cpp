#include <stdio.h>
#include <stdlib.h>


#define getIntArraySize (_array) sizeof (_array) / sizeof (int);

void swap (int array[], int pos1, int pos2);

void bubbleSort (int array[], int arrayLength);
void selectionSort (int array[], int arrayLength);
void insertionSort (int array[], int arrayLength);
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

void swap (int array[], int pos1, int pos2)
{
    int temp = *(array + pos1);
    *(array + pos1) = *(array + pos2);
    *(array + pos2) = temp;
}


void bubbleSort (int array[], int arrayLength)
{
    bool swapped;

    do
    {
        swapped = false;
        arrayLength--;
        for(int i = 0; i < arrayLength; i++)
        {
            if(array[i] > array[i + 1])
            {
                swap (array, i, i + 1);
                swapped = true;
            }
        }
    } while(swapped);
}

void selectionSort (int array[], int arrayLength)
{
    int minIndex = 0;
    int minValue;

    bool needSwap = false;

    for(int cycle = 0; cycle < arrayLength -1; cycle++)
    {
        minValue = array[cycle];
        for(int i = cycle; i < arrayLength ; i++)
        {
            if(array[i] < minValue)
            {
                minIndex = i;
                minValue = array[i];
                needSwap = true;
            }
        }

        if(needSwap)
        {
            swap (array, cycle, minIndex);
            needSwap = false;
        }
    }
}


void insertionSort (int array[], int arrayLength)
{
    int index = 1;
    for(int cycle = 0; cycle < arrayLength - 1; cycle++)
    {
        index = cycle + 1;

        for( ;array[index] < array[index-1] && index > 0;index-- )
        {
            swap (array,index,index-1);
        }
    }
}

void mergeSort (int array[], int arrayLength)
{

}