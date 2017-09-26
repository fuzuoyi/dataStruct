#include <stdio.h>
#include <stdlib.h>
#include "Queue/queue.h"

struct QueueRecord;
typedef QueueRecord * PQueue;

struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};


int main ()
{

   return 0;
}

