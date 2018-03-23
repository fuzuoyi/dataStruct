#pragma once


#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <malloc.h>

using namespace std;

#define _max(a,b) (((a) > (b)) ? (a) : (b))
#define _min(a,b) (((a) < (b)) ? (a) : (b))

#define logError(x) printf(x)


struct AVLNode;
typedef struct AVLNode *pTNode;
typedef pTNode  AVL;


struct AVLNode
{
    int x;
    AVL left;
    AVL right;
    int height;
};


pTNode makeEmpty (int x, int height = 0);

// 获取树高
int height (pTNode P);

pTNode find (AVL T, int x);
pTNode findMin (AVL T);
pTNode findMax (AVL T);

// 插入 / 删除
void insert (AVL &T, int x);
void deleteNode (AVL &T, int x);
void deleteTree (AVL &T);


// 旋转操作
pTNode _singleRotateWithLeft (AVL root);  
pTNode _singleRotateWithRight (AVL root);
pTNode _doubleRotateWithLeft (AVL root);
pTNode _doubleRotateWithRight (AVL root);


