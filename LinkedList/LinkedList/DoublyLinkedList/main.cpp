#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "doublyLinkedList/doublyLinkedList.h"


int main ()
{
    pNode head = NULL, rear = NULL;
    DList d = makeEmptyDList();


    insert_head (2, d);
    insert_tail (3, d);
    insert_head (4, d);
    insert_tail (5, d);

    getValve (2, d);

    traversal_List (d);

    insert (4, 8, d);
    insert (2, 7, d);
    insert (3,6, d);
    traversal_List (d);

    deleteNode (2, d);
    traversal_List (d);

    delete_head (d);
    delete_tail (d);
    traversal_List (d);

    isEmpty (d);
    getSize (d);

    search (2,d);

    system ("pause");
    return 0;
}