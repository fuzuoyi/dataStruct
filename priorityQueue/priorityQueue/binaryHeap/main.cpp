#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


#define logError(x)		printf(x)

struct HeapStruct;

typedef HeapStruct *PriorityQueue;
typedef HeapStruct *Heap;

#define MinHeapSize 15
#define MinData		-1

Heap initializeHeap(int capacity=15);

bool isEmpty(Heap H);
bool isFull(Heap H);

void insert(Heap H, int x);

int deleteMin(Heap H);
int findMin(Heap H);



void deleteHeap(Heap &H);

void traversal_Heap(Heap H);


struct HeapStruct
{
	int Capacity;
	int Size;
	int *Array;
};


int main()
{
	Heap H = initializeHeap();

	insert(H, 13);
	insert(H, 21);
	insert(H, 16);
	insert(H, 24);
	insert(H, 31);
	insert(H, 19);
	insert(H, 68);
	insert(H, 65);
	insert(H, 26);
	insert(H, 32);

	traversal_Heap(H);

	insert(H, 14);

	traversal_Heap(H);


	system("pause");
	return 0;
}


Heap initializeHeap(int capacity)
{
	Heap H;

	if (capacity < MinHeapSize)
		logError("heap size too small!!!");

	H = (Heap)malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		logError("out of space!!!");

	H->Array = (int*)malloc(sizeof(int) * (capacity + 1));
	if (H->Array == NULL)
		logError("out of space");

	H->Capacity = capacity;
	H->Size = 0;
	H->Array[0] = 0;

	return H;
}

bool isEmpty(Heap H)
{
	return H->Size == 0;
}
bool isFull(Heap H)
{
	return H->Size == H->Capacity;
}

void insert(Heap H, int x)
{
	int i;
	if (isFull(H))
	{
		logError("Heap is Full");
		return;
	}

	//for (i = ++H->Size; H->Array[i / 2] > x ; i /= 2)
	//	H->Array[i] = H->Array[i / 2];
	//H->Array[i] = x;

	H->Array[H->Size] = x;	

	i = H->Size;
	H->Size++;

	while (H->Array[i] < H->Array[i / 2] & i > 1)
	{
		// swap
		int temp = H->Array[i / 2];
		H->Array[i / 2] = H->Array[i];
		H->Array[i] = temp;
	}

}

int deleteMin(Heap H);
int findMin(Heap H);



void deleteHeap(Heap &H);

void traversal_Heap(Heap H)
{
	for (int i = 0; i < H->Size; i++)
	{
		printf("%d\t", H->Array[i]);
	}

	printf("\r\n");
}
