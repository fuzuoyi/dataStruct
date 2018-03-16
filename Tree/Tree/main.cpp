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


SearchTree makeEmpty(SearchTree T);
pTNode find(int x, SearchTree T);
pTNode findMin(SearchTree T);
pTNode findMax(SearchTree T);
SearchTree insert(int x, SearchTree T);
SearchTree deleteNode(int x, SearchTree T);