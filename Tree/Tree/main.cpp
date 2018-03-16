#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "tree/listDirectory.h"

using namespace std;


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
    // �ݹ�ʵ�֣�findMaxͬ�������õݹ���ʵ��
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
    // �ǵݹ�ʵ�֣�findMinͬ�������÷ǵݹ���ʵ��
    if(T != NULL)
    {
        while(T->right != NULL)
            T = T->right;
        return T;
    }
}


SearchTree insert (int x, SearchTree T)
{

}


SearchTree deleteNode(int x, SearchTree T);



