#include "sort.h"

void _Merge_ (int A[], int TempArray[], int Left_index, int Right_index, int RightEnd);
void _MSort_ (int A[], int TmpArray[], int left, int right);
void mergeSort (int array[], int arrayLength);



void _Merge_ (int A[], int TempArray[], int Left_index, int Right_index, int RightEnd)
{
    int LeftEnd, NumElements, Temp_index;

    LeftEnd = Right_index - 1;
    Temp_index = Left_index;
    NumElements = RightEnd - Left_index + 1;

    while(Left_index <= LeftEnd && Right_index <= RightEnd)
    {
        if(A[Left_index] <= A[Right_index])
        {
            TempArray[Temp_index++] = A[Left_index++];
        }
        else
        {
            TempArray[Temp_index++] = A[Right_index++];
        }
    }
    while(Left_index <= LeftEnd)
        TempArray[Temp_index++] = A[Left_index++];


    while(Right_index <= RightEnd)
        TempArray[Temp_index++] = A[Right_index++];

    // copy temp back to A[]
    for(int i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TempArray[RightEnd];

}

void _MSort_ (int A[], int TmpArray[], int left, int right)
{
    int center;
    if(left < right)
    {
        center = (left + right) / 2;
        _MSort_ (A, TmpArray, left, center);
        _MSort_ (A, TmpArray, center + 1, right);

        _Merge_ (A, TmpArray, left, center + 1, right);
    }
};

void mergeSort (int array[], int arrayLength)
{
    int *temp_array = (int*) malloc (arrayLength * sizeof (int));
    if(temp_array == NULL)
        LogError ("No space for temp array!");

    _MSort_ (array, temp_array, 0, arrayLength - 1);
    free (temp_array);
}