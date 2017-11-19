#include "utils.h"

void PrintIntArray (int num_array[], int arrayLength)
{
    for(int i = 0; i<arrayLength; i++)
    {
        printf ("%d\t", num_array[i]);
    }
    printf ("\r\n");
}

void getIntRandArray (int num_array[], int arrayLength)
{
    int index = arrayLength - 1;
    int rand_value;

    srand ((unsigned) time (0));

    for(int i = 0; i < arrayLength; i++)
    {
        rand_value = rand () % arrayLength;
        num_array[i] = rand_value;
    }
}

void getLinerIntRandArray (int num_array[], int arrayLength)
{
    int index = arrayLength - 1;
    int rand_value;

    int *usedIndex = (int*) malloc (arrayLength * sizeof (int));

    for(int i = 0; i < arrayLength; i++)
        usedIndex[i] = 0;

    srand ((unsigned) time (0));

    while(index >= 0)
    {
        rand_value = rand () % arrayLength;
        if(usedIndex[rand_value] == 1) continue;
        else
        {
            usedIndex[rand_value] = 1;
            num_array[index] = rand_value;
            index--;
        }
    }
}


clock_t time_test (SortFunc sort, int num_array[], int arrayLength, int count)
{
    clock_t start, end, duration = 0;

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