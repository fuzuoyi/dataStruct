#include <stdlib.h>
#include "stack.h"

#define EmptyStack -65534

struct Node;
typedef struct Node *pNode;
typedef pNode Stack;


struct Node
{
    int value;
    pNode next;
};

bool isEmpty (Stack S);
pNode makeEmpty (int value = 0);

int getSize (Stack S);

void push (int value, Stack S);
int pop (Stack S);

int top (Stack S);

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

void push (int value, Stack S)
{
    pNode p = makeEmpty(value);
    p->next = S->next;
    S->next = p;
}

int pop (Stack S)
{
    if(!isEmpty (S))
    {
        pNode p = S->next;
        int value = p->value;
        free (p);
        return value;
    } 
    return EmptyStack;
}

int top (Stack S)
{
    if(!isEmpty (S))
    {
        return  S->next->value;
    }
    return EmptyStack;
}

void clearStack (Stack S)
{
    Stack s = S;
    while(S != NULL)
    {
        s = S;
        S = S->next;
        free (s);
    }
}

int main ()
{
    Stack s = makeEmpty ();
    top (s);

    return 0;
}

