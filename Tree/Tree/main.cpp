#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <malloc.h>
#include "tree/listDirectory.h"
//#include "tree/bst_book.h"


using namespace std;

#define logError(x) printf(x)


struct BSTNode;
typedef struct BSTNode *pTNode;
typedef pTNode  BST;

struct BSTNode
{
    int x;
    BST left;
    BST right;
};

pTNode makeEmpty (int x);
pTNode find (BST T, int x);
pTNode findMin (BST T);
pTNode findMax (BST T);
void insert (BST &T, int x);
void deleteNode (BST &T, int x);
void deleteTree (BST &T);





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


    system ("pause");

    return 0;
}




pTNode makeEmpty (int x)
{
    pTNode p = (pTNode) malloc (sizeof (struct BSTNode));
    if(p == NULL)
        logError ("Out of Space!!!!");
    p->left = NULL;
    p->right = NULL;
    p->x = x;
    return p;
}

pTNode find (BST T, int x)
{
    if(T == NULL)
        return NULL;
    if(x < T->x)
        return find (T->left, x);
    else if(x > T->x)
        return find (T->right, x);
    else
        return T;
}


pTNode findMin (BST T)
{
    // 递归实现，findMax同样可以用递归来实现
    if(T == NULL)
        return NULL;
    else
    {
        if(T->left == NULL)
            return T;
        else
            return findMin (T->left);
    }
}


pTNode findMax (BST T)
{
    if(T != NULL)
    {
        while(T->right != NULL)
            T = T->right;
    }
    return T;
}


void insert (BST &T, int x)
{
    pTNode t = T, parent=NULL;

    if(t == NULL)
    {
        T = makeEmpty (x);
        return;
    }

    while(t != NULL)
    {
        parent = t;
        if(t->x > x)
            t = t->left;
        else if(t->x < x)
            t = t->right;
        else
            return;
    }

    if(parent->x > x)
        parent->left = makeEmpty (x);
    else
        parent->right = makeEmpty (x);
}

void deleteNode (BST &T, int x)
{
    pTNode tmpcell;

    if(T == NULL)
    {
        logError ("empty Tree!!!");
        return;
    }

    if(x < T->x)
        deleteNode (T->left, x);
    else if(x > T->x)
    {
        deleteNode (T->right, x);
    }
    // x == T->x && (left & right leaf) exists 
    else if(T->left && T->right)
    {
        tmpcell = findMin (T->right);
        T->x = tmpcell->x;
        deleteNode (T->right, T->x);
    }
    // x == T->x && (left or right leaf) exists 
    else
    {
        tmpcell = T;
        if(T->left == NULL)
            T = T->right;
        else if(T->right == NULL)
            T = T->left;
        free (tmpcell);
    }
}

void deleteTree (BST &T)
{
    if(T != NULL)
    {
        deleteTree (T->left);
        deleteTree (T->right);
        free (T);
        T = nullptr;
    }
}




