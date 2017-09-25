#include <stdio.h>
#include <stdlib.h>


struct Node;
typedef struct Node *pNode;
typedef pNode Queue;


struct Node
{
    int value;
    pNode next;
};

bool isEmpty (Queue Q);

int getSize (Queue Q);

void enqueue (int value, Queue Q);
int dequeue (Queue Q);

int front (Queue Q);
int back (Queue Q);


int main ()
{

   return 0;
}

