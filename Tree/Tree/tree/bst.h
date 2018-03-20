#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <malloc.h>


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

