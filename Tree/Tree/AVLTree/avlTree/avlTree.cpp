#include "avlTree.h"

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
    // return p -> height
    if(P == NULL)
        return -1;
    else
        return P->height;
}

pTNode find (AVL T, int x)
{
    // get node which value is x in tree
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
    // double rotate with root's left child (insert to left child's right)
    // doulerotate equal twice sigle rotate 

    root->left = _singleRotateWithRight (root->left);
    return _singleRotateWithLeft (root);
}


pTNode _doubleRotateWithRight (AVL root)
{
    // double rotate with root's right child (insert to right child's left)
    // doulerotate equal twice sigle rotate 

    root->right = _singleRotateWithLeft (root->right);
    return _singleRotateWithRight (root);
}

void insert (AVL &T, int x)
{
    // insert, in AVL Tree, should be maintain binary tree' Attributes (root >left, root<right)
    // also, all subtree should be balance, need to check in every insert(single/double rotate)
    // ��ʵ�ϣ��ݹ���ò����㷨����ƽ�������ɲ����ĵڶ��η���ʱ���ܷ��ֲ�ƽ�⣬����������ת����
    // �ڷ���ʱ�����ϸ��������ĸ߶�

    pTNode t = T, parent = NULL;

    if(t == NULL)
    {
        T = makeEmpty (x, 0);
    }
    else if(x < T->x)
    {
        insert (T->left, x);
        // balance tree with rotate
        if(height (T->left) - height (T->right) == 2)
        {
            if(x < T->left->x)
                // insert to left child' left
                T = _singleRotateWithLeft (T);
            else
                // insert to left child' right
                T = _doubleRotateWithLeft (T);
        }
    }
    else if(x > T->x)
    {
        insert (T->right, x);
        // balance tree with rotate
        if(height (T->right) - height (T->left) == 2)
        {
            if(x > T->right->x)
                // insert to right child' right
                T = _singleRotateWithRight (T);
            else
                // insert to right child' left
                T = _doubleRotateWithRight (T);
        }
    }

    // update height after every insert
    T->height = _max (height (T->left), height (T->right)) + 1;
}


void deleteNode (AVL &T, int x)
{
    // delete node which value is x

    if(T == nullptr)
        return;

    if(T->x == x)
    {
        // Node p has both left & right subtree
        if(T->left != nullptr && T->right != nullptr)
        {
            if(height (T->left) > height (T->right))
            {
                // ����������ĸ߶ȴ����������ĸ߶ȣ���ô�����������Ҷ�������ǰ�㣨
                // Ȼ���������е����Ҷ��ɾ��
                pTNode lMaxChild = findMax (T->left);
                T->x = lMaxChild->x;
                deleteNode (T->left, lMaxChild->x);
            }
            else
            {
                // ����������ĸ߶ȴ����������ĸ߶ȣ���ô����������СҶ�������ǰ��
                // Ȼ���������е���СҶ��ɾ��
                pTNode rMinChild = findMin (T->right);
                T->x = rMinChild->x;
                deleteNode (T->right, rMinChild->x);
            }
        }
        // ����������������û������
        else
        {
            // û��Ҷ�ӣ�ֱ��free
            if(T->left == nullptr && T->right == nullptr)
            {
                free (T);
                T = nullptr;
            }
            else
            {
                // ��һ����������ôָ���ƹ��ýڵ㣬����������free
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
        // ά������ƽ��
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
        // ά������ƽ��
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
    //ɾ����
    if(T != NULL)
    {
        deleteTree (T->left);
        deleteTree (T->right);
        free (T);
        T = nullptr;
    }
}


