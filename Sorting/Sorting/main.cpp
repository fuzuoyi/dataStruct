#include <stdio.h>
#include <stdlib.h>

int getSize (int array[])
{
    return sizeof (array) / sizeof (int);
}

void swap (int array[], int pos1, int pos2);

void bubbleSort (int array[], int arrayLength);


int main ()
{
    int data[] = { 34,1,7,5,44,30,33,22,18,4,11,4,31,11 };

    int size = sizeof (data) / sizeof (int);

    for (int i = 0;i<size;i++)
    {
        printf ("%d\t",data[i]);
    }
    bubbleSort (data, size);
    for(int i = 0; i < size; i++)
    {
        printf ("%d\t",data[i]);
    }
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
