#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define logError(x) printf(x)

//�ն��б�־�������Դӿն����л�ȡ��ɾ���ڵ�ʱ�����ظñ�־
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