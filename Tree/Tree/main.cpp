#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <malloc.h>
#include "tree/listDirectory.h"

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

SearchTree makeEmpty(SearchTree T);
pTNode find(int x, SearchTree T);
pTNode findMin(SearchTree T);
pTNode findMax(SearchTree T);
SearchTree insert(int x, SearchTree T);
SearchTree deleteNode(int x, SearchTree T);

void traversal_List (SearchTree T);


int main()
{
	printf("%s", "sdfghjkl");

	system("pause");
	return 0;
}


SearchTree makeEmpty (SearchTree T)
{
    if(T != NULL)
    {
        makeEmpty (T->left);
        makeEmpty (T->right);
        free (T);
    }
    return NULL;
}

pTNode find (int x, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(x < T->value)
        return find (x, T->left);
    else if(x > T->value)
        return find (x, T->right);
    else
        return T;
}


pTNode findMin (SearchTree T)
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


pTNode findMax (SearchTree T)
{
    // 非递归实现，findMin同样可以用非递归来实现
    if(T != NULL)
    {
        while(T->right != NULL)
            T = T->right;
    }
    return T;

}


SearchTree insert (int x, SearchTree T)
{
    if(T == NULL)
    {
        T = (pTNode)malloc (sizeof (struct TreeNode));
        if(T == NULL)
            logError ("Out of space!!");
        else
        {
            T->value = x;
            T->left = T->right = NULL;
        }   
    }
    else
    {
        if(x < T->value)
            T->left = insert (x, T->left);
        else if(x > T->value)
            T->right = insert (x, T->right);
    }
    return T;
}


SearchTree deleteNode (int x, SearchTree T)
{
    pTNode tmpcell;

    if(T == NULL)
        logError ("element not found!!!");
    else
    {
        if(x < T->value)
            T->left = deleteNode (x,T->left);
        else if(x>T->value)
        {
            T->right = deleteNode (x, T->right);
        }
        else if(T->left && T->right)
        {
            tmpcell = findMin (T->right);
            T->value = T->right->value;
            T->right = deleteNode (T->value, T->right);
        }
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
    return T;
}


void traversal_List (SearchTree T)
{

}
