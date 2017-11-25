#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

# define LogError(x) printf(x)

#define getIntArraySize (_array) sizeof (_array) / sizeof (int);

void swap (int array[], int pos1, int pos2);

// implement in "sort.cpp"

void bubbleSort (int array[], int arrayLength);
void selectionSort (int array[], int arrayLength);
void insertionSort (int array[], int arrayLength);


// implement in "mergeSort.cpp"

void mergeSort (int array[], int arrayLength);


// implement in "mergeSort.cpp"

void quickSort (int array[], int arrayLength);


// implement in "randomQuickSort.cpp"

void randomQuickSort (int array[], int arrayLength);


#endif