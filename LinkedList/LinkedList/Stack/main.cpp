#include <stdlib.h>
#include "stack.h"

struct Node;
typedef struct Node *pNode;
typedef pNode Stack;


struct Node
{
    int value;
    pNode next;
};

bool isEmpty (Stack S);
pNode makeEmpty (int value);

int getSize (Stack S);

void push (int value);
int pop ();

int top ();

void clearStack (Stack S);

bool isEmpty (Stack S)
{
    return S->next == NULL;
}

pNode makeEmpty (int value)
{
    pNode p = (pNode) malloc (sizeof (struct Node));//申请节点内存
    //初始化节点元素和指针
    p->next = NULL;
    p->value = value;
    return p;
}

int getSize (Stack S)
{
    int size = 0;
    S = S->next;     
    while(S != NULL)
    {
        size++;
        S = S->next;
    }
    return size;
}

void push (int value);
int pop ();

int top ();

void clearStack (Stack S);

int main ()
{

    return 0;
}

