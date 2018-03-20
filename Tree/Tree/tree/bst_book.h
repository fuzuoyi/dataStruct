#pragma once

#include <string>
#include <iostream>
#include <malloc.h>


using namespace std;

#define logError(x) printf(x)


struct TreeNode;
typedef struct TreeNode *pTNode;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int value;
    SearchTree left;
    SearchTree right;
};

SearchTree makeEmpty (SearchTree T);
pTNode find (int x, SearchTree T);
pTNode findMin (SearchTree T);
pTNode findMax (SearchTree T);
SearchTree insert (int x, SearchTree T);
SearchTree deleteNode (int x, SearchTree T);

void traversal_Tree (SearchTree T);

static void lsTree (SearchTree T, int depth);
void printValue (int value, int depth);


