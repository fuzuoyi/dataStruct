#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "deque/deque.h"

int main ()
{
    pNode head = NULL, rear = NULL;
    Deque d = makeEmptyDeque ();

    isEmpty (d);
    getSize (d);

    enqueue_front (2, d);
    enqueue_back (3, d);
    enqueue_front (4, d);
    enqueue_back (5, d);

    peek_back (d);
    peek_front (d);

    traversal_Deque (d);

    enqueue_front (6, d);
    enqueue_front (7, d);

    traversal_Deque (d);

    dequeue_back (d);
    dequeue_front (d);

    traversal_Deque (d);

    isEmpty (d);
    getSize (d);

    system ("pause");
    return 0;
}


