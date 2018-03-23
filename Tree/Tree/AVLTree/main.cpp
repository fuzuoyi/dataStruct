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

int height (pTNode P);

pTNode find (AVL T, int x);
pTNode findMin (AVL T);
pTNode findMax (AVL T);

void insert (AVL &T, int x);
void deleteNode (AVL &T, int x);
void deleteTree (AVL &T);



pTNode _singleRotateWithLeft (AVL root);
pTNode _singleRotateWithRight (AVL root);
pTNode _doubleRotateWithLeft (AVL root);
pTNode _doubleRotateWithRight (AVL root);

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

    deleteNode (t,15);

    deleteTree (t);


    insert (t, 15);


    system ("pause");
    return 0;
}



pTNode makeEmpty (int x, int height)
{
    pTNode p = (pTNode) malloc (sizeof (struct AVLNode));
    if(p == NULL)
        logError ("Out of Space!!!!");
    p->left = NULL;
    p->right = NULL;
    p->x = x;
    p->height = height;
    return p;
}

int height (pTNode P)
{
    if(P == NULL)
        return -1;
    else
        return P->height;
}

pTNode find (AVL T, int x)
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

pTNode findMin (AVL T)
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
pTNode findMax (AVL T)
{
    if(T != NULL)
    {
        while(T->right != NULL)
            T = T->right;
    }
    return T;
}



pTNode _singleRotateWithLeft (AVL root)
{
    // rotate with root's left chlild

    // rotate
    pTNode lchild = root->left;
    root->left = lchild->right;
    lchild->right = root;

    // update height 
    root->height = _max (height (root->left), height (root->right)) + 1;
    lchild->height = _max (height (lchild->left), height (lchild->right)) + 1;

    // now, left child is new root
    return lchild;
}
pTNode _singleRotateWithRight (AVL root)
{
    // rotate with root's right chlild

    // rotate
    pTNode rchild = root->right;
    root->right = rchild->left;
    rchild->left = root;

    // update height 
    root->height = _max (height (root->left), height (root->right)) + 1;
    rchild->height = _max (height (rchild->left), height (rchild->right)) + 1;

    // now, right child is new root
    return rchild;
}

pTNode _doubleRotateWithLeft (AVL root)
{
    // double rotate with root's left child

    root->left = _singleRotateWithRight (root->left);
    return _singleRotateWithLeft (root);
}


pTNode _doubleRotateWithRight (AVL root)
{
    // double rotate with root's right child

    root->right = _singleRotateWithLeft (root->right);
    return _singleRotateWithRight (root);
}

void insert (AVL &T, int x)
{

    pTNode t = T, parent = NULL;

    if(t == NULL)
    {
        T = makeEmpty (x, 0);
    }
    else if(x < T->x)
    {
        insert (T->left, x);
        if(height (T->left) - height (T->right) == 2)
        {
            if(x < T->left->x)
                T = _singleRotateWithLeft (T);
            else
                T = _doubleRotateWithLeft (T);
        }
    }
    else if(x > T->x)
    {
        insert (T->right, x);
        if(height (T->right) - height (T->left) == 2)
        {
            if(x > T->right->x)
                T = _singleRotateWithRight (T);
            else
                T = _doubleRotateWithRight (T);
        }
    }

    T->height = _max (height (T->left), height (T->right)) + 1;

}


void deleteNode (AVL &T, int x)
{
    if(T == nullptr)
        return;

    if(T->x == x)
    {
        if(T->left != nullptr && T->right != nullptr)
        {
            if(height (T->left) > height (T->right))
            {
                pTNode lMaxChild = findMax (T->left);
                T->x = lMaxChild->x;
                deleteNode (T->left, lMaxChild->x);
            }
            else
            {
                pTNode rMinChild = findMin (T->right);
                T->x = rMinChild->x;
                deleteNode (T->right, rMinChild->x);
            }
        }
        else
        {
            if(T->left == nullptr && T->right == nullptr)
            {
                free (T);
                T = nullptr;
            }
            else
            {
                pTNode pTemp = T;
                if(T->left != nullptr)
                    T = T->left;
                else if(T->right != nullptr)
                    T = T->right;
                free (pTemp);
                pTemp = nullptr;
            }
        }
    }
    else if(T->x < x)
    {
        deleteNode (T->right, x);
        if(height (T->left) - height (T->right) == 2)
        {
            if(height (T->left->left) < height (T->left->right))
                _doubleRotateWithLeft (T);
            else
                _singleRotateWithLeft (T);
        }
    }
    else if(T->x > x)
    {
        deleteNode (T->left, x);
        if(height (T->right) - height (T->left) == 2)
        {
            if(height (T->right->right) < height (T->right->left))
                _doubleRotateWithRight (T);
            else
                _singleRotateWithRight (T);
        }
    }
}


void deleteTree (AVL &T)
{
    if(T != NULL)
    {
        deleteTree (T->left);
        deleteTree (T->right);
        free (T);
        T = nullptr;
    }
}
