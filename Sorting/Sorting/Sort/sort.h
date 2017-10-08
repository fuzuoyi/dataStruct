#ifndef __SORT_H__
#define __SORT_H__

#define getIntArraySize (_array) sizeof (_array) / sizeof (int);

void swap (int array[], int pos1, int pos2);

void bubbleSort (int array[], int arrayLength);
void selectionSort (int array[], int arrayLength);
void insertionSort (int array[], int arrayLength);
void mergeSort (int array[], int arrayLength);

#endif