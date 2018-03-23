#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <malloc.h>
#include "avlTree/avlTree.h"

using namespace std;



int main ()
{

    AVL t = makeEmpty (10);

    pTNode p = NULL;

    insert (t, 12);
    insert (t, 11);
    insert (t, 8);
    insert (t, 14);
    
    insert (t, 16);
    insert (t, 15);
    insert (t, 17);
    insert (t, 18);
    p = findMax (t);

    deleteNode (t,19);

    deleteTree (t);


    insert (t, 15);


    system ("pause");
    return 0; 
}



