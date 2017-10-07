#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define logError(x) printf(x)

//空队列标志，当尝试从空队列中获取或删除节点时，返回该标志
#define EmptyQueue -65534

struct QueueRecord;
typedef QueueRecord *pQueue;
typedef pQueue arrayQueue;

struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};

bool isEmpty (arrayQueue Q);
bool isFull (arrayQueue Q);

int getSize (arrayQueue Q);

arrayQueue createArrayQueue (int cpacity);

bool enqueue (int value, arrayQueue Q);
int dequeue (arrayQueue Q);

int front (arrayQueue Q);

void clearQueue (arrayQueue Q);
void deleteQueue (arrayQueue Q);

void traversal_Queue (arrayQueue Q);

#endif