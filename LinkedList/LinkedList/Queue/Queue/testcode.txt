#include <stdio.h>
#include <stdlib.h>
#include "Queue/queue.h"

int main ()
{
    Queue q = createQueue ();
    printf ("%d\r\n", getSize (q));

    for(int i = 0; i < 5; i++)
    {
        enqueue (i, q);
    }

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

    clearQueue (q);

    printf ("%d\r\n", getSize (q));

    for(int i = 0; i < 5; i++)
    {
        enqueue (i, q);
    }

    traversal_Queue (q);
    
    printf ("%d\r\n", front(q));
    printf ("%d\r\n", back(q));

   return 0;
}

