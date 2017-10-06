#include <stdio.h>
#include <stdlib.h>
//#include "Queue/queue.h"

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

void emptyQueue (arrayQueue Q);
void deleteQueue (arrayQueue Q);

bool enqueue (int value, arrayQueue Q);
int dequeue (arrayQueue Q);

int front (arrayQueue Q);

void traversal_Queue (arrayQueue Q);


bool isEmpty (arrayQueue Q)
{
    Q->size == 0;
}

bool isFull (arrayQueue Q)
{
    return Q->size == Q->capacity;
}





int getSize (arrayQueue Q)
{
    return Q->size;
}

arrayQueue createArrayQueue (int capacity)
{
    arrayQueue Q = (pQueue) malloc (sizeof (struct QueueRecord));

    if(Q == NULL)
        logError ("Out of space!!!");

    Q->array = (int *)malloc (sizeof (int) * capacity);

    if(Q->array == NULL)
        logError ("Out of space!!!");

    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;

}

void emptyQueue (arrayQueue Q)
{

}
void deleteQueue (arrayQueue Q);

bool enqueue (int value, arrayQueue Q);
int dequeue (arrayQueue Q);

int front (arrayQueue Q);

void traversal_Queue (arrayQueue Q);

int main ()
{

   return 0;
}

