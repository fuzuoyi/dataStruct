#include <stdlib.h>
#include <stdio.h>
#include "stack/stack.h"

int main ()
{
    Stack s = makeEmpty ();
    push (1, s);
    push (2, s);
    push (3, s);
    top (s);
    pop (s);
    pop (s);
    push (4, s);
    push (6, s);
    top (s);
    top (s);
    printf ("%d\r\n", getSize (s));
    clearStack (s);
    push (4, s);
    push (6, s);
    top (s);
    printf ("%d\r\n", getSize (s));

    return 0;
}

