#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "stack/stack.h"
#include "arrayStack/arrayStack.h"

int main ()
{
    arrayStack s = createStack (10);

    for(int i = 0; i < 11; i++)
    {
        push (i, s);
    }

    pop (s);
    pop (s);

    emptyStack (s);

    for(int i = 0; i < 5; i++)
    {
        push (i, s);
    }

    printf ("%d\r\n", getSize (s));


    pop (s);
    pop (s);

    traversal_Stack (s);
    printf ("%d\r\n", getSize (s));


    system ("pause");
    return 0;
}

