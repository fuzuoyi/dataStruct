#include "sort.h" 

// 当子数组数目太少时，直接使用插入排序
#define Cutoff 3

void quickSort (int array[], int arrayLength);

int _median3 (int array[], int left, int right);
void _QSort (int array[], int left, int right);


int _median3 (int array[], int left, int right)
{
    int center = (left + right) / 2;

    // make array[left] <= array[center] <= array[right]
    if(array[left] > array[center])
        swap (array, left, center);
    if(array[left] > array[right])
        swap (array, left, right);
    if(array[center] > array[right])
        swap (array, center, right);

    swap (array, center, right - 1);

    return array[right - 1];
}

void _QSort (int array[], int left, int right)
{
    int i, j;
    int pivot;

    if(left + Cutoff <= right)
    {
        pivot = _median3 (array, left, right);

        i = left;
        j = right - 1;

        for(;;)
        {
            while(array[++i]<pivot) {}
            while(array[--j]>pivot) {}

            if(i < j)
                swap (array, i, j);
            else
                break;
        }

        swap (array, i, right - 1);

        _QSort (array, left, i - 1);
        _QSort (array, i + 1, right);
    }
    else
        insertionSort (array + left, right - left + 1);
}

void quickSort (int array[], int arrayLength)
{
    _QSort (array, 0, arrayLength - 1);
}
