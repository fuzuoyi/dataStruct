#include "sort.h"


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

    for(int cycle = 0; cycle < arrayLength - 1; cycle++)
    {
        minValue = array[cycle];
        for(int i = cycle; i < arrayLength; i++)
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

        for(; array[index] < array[index - 1] && index > 0; index--)
        {
            swap (array, index, index - 1);
        }
    }
}


void countingSort (int array[], int arrayLength)
{
    int counts[MaxNum] = { 0 };

    // 将元素放到相应的计数数组中
    for(int i = 0; i < arrayLength; i++)
        counts[array[i]]++;

    int index = 0;

    // 从计数数组中取出元素到原数组
    for(int i = 0; i < MaxNum; i++)
    {
        while(counts[i] > 0)
        {
            counts[i]--;
            array[index++] = i;
        }
    }
}