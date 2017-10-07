#include <stdio.h>
#include <stdlib.h>
#include "Queue/queue.h"
#include "ArrayQueue/arrayQueue.h"

int main ()
{
    arrayQueue q = createArrayQueue (10);
    printf ("%d\r\n", getSize (q));

    for(int i = 0; i < 5; i++)
    {
        enqueue (i, q);
    }

    traversal_Queue (q);

    dequeue (q);
    dequeue (q);
    dequeue (q);
    dequeue (q);
    dequeue (q);
    dequeue (q);

    for(int i = 0; i < 5; i++)
    {
        enqueue (i, q);
    }

    printf ("%d\r\n", getSize (q));

    clearQueue (q);

    printf ("%d\r\n", getSize (q));

    for(int i = 0; i < 5; i++)
    {
        enqueue (i, q);
    }

    traversal_Queue (q);

    printf ("%d\r\n", front (q));

    system ("pause");
    return 0;
}
