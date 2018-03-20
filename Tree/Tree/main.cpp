#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <malloc.h>
// #include "tree/listDirectory.h"
#include "tree/bst.h"


using namespace std;


int main ()
{
    BST t = makeEmpty (10);

    pTNode p = NULL;

    insert (t, 5);
    insert (t, 4);
    insert (t, 8);
    insert (t, 12);
    insert (t, 16);
    insert (t, 15);

    p = findMax (t);

    deleteTree (t);


    insert (t, 15);

    return 0;
}




