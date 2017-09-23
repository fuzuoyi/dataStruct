
#include "LinkedList/linkedList.h"
#include <stdlib.h>


int main ()
{
    List l = makeEmpty ();
    insert_tail (5, l);

    insert_head (2, l);
    insert_head (3, l);
    insert (10, 0, l);
    insert (9, 4, l);
    insert (4, 2, l);
    deleteNode (5,l);
    printf ("%d\r\n", search (10,l));
    traversal_List (l);
    deleteList (l);

    getchar ();
    return 0;
}
