#include "arrayQueue.h"

bool isEmpty (arrayQueue Q)
{
    return Q->size == 0;
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

    Q->array = (int *) malloc (sizeof (int) * capacity);

    if(Q->array == NULL)
        logError ("Out of space!!!");

    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}


bool enqueue (int value, arrayQueue Q)
{
    if(isFull (Q))
        return false;
    Q->array[Q->rear] = value;
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->size++;

    return true;
}

int dequeue (arrayQueue Q)
{
    if(isEmpty (Q))
        return EmptyQueue;

    int res = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;

    return res;
}

int front (arrayQueue Q)
{
    if(isEmpty (Q))
        return EmptyQueue;
    return Q->array[Q->front];
}

void clearQueue (arrayQueue Q)
{
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;
}
void deleteQueue (arrayQueue Q)
{
    if(Q != NULL)
    {
        free (Q->array);
        free (Q);
    }
}

void traversal_Queue (arrayQueue Q)
{
    int index = Q->front;
    for(int i = 0; i < getSize (Q); i++)
    {
        printf ("%d\t", Q->array[(Q->front + i) % Q->capacity]);
    }
    printf ("\r\n");
}