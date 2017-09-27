#include <stdlib.h>
#include <stdio.h>
#include "ArrayStack/arrayStack.h"
#include "stack/stack.h"

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

    pop (s);
    pop (s);

    traversal_Stack (s);

    printf ("%d\r\n", getSize (s));

    system ("pause");
    return 0;
}

