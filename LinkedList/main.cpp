#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#define logError(x) printf(x)

struct Node;
typedef struct Node *pNode;

typedef pNode List;

struct Node
{
    int value;
    pNode next;
};

List makeEmpty (int value = 0);
bool isEmpty (List L);
int getSize (List L);

void insert_head (int Value, List L);
void insert_tail (int Value, List L);
bool insert (int Value, int index, List L);

void delete_head (List L);
void delete_tail (List L);
void deleteNode (int index, List L);

int search (int Value, List L);
int getHead (List L);
int getTail (List L);
int getValve (int index, List L);

pNode getNode (int index, List L);




List makeEmpty (int value = 0)
{
    pNode p = (pNode) malloc (sizeof (struct Node));
    p->next = NULL;
    p->value = value;
    return p;
}

bool isEmpty (List L)
{
    return L->next == NULL;
}

int getSize (List L)
{
    int size = 0;
    List l = L;
    l = l->next;
    while(l != NULL)
    {
        size++;
        l = l->next;
    }
    return size;
}

void insert_head (int Value, List L)
{
    pNode temp = makeEmpty (Value);
    temp->next = L->next;
    L->next = temp;
}

void insert_tail (int Value, List L)
{
    pNode temp = makeEmpty (Value);
    List l = L;

    while(l->next != NULL)
    {
        l = l->next;
    }
    l->next = temp;
}

bool insert (int Value, int index, List L)
{
    if(getSize (L) < index || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!");
        return false;
    }

    List l = L;
    pNode temp = makeEmpty (Value);

    for(int i = 0; i < index; i++)
    {
        l = l->next;
    }

    temp->next = l->next;
    l->next = temp;
    return true;
}

void delete_head (List L)
{
    if(L->next == NULL)
        return;

    pNode l = L;

    l->next = L->next->next;
    free (L->next);
    L = l;
}

void delete_tail (List L)
{
    if(L->next == NULL)
        return;

    int size = getSize (L);
    List l = L;

    for(int i = 1; i < size; i++)
    {
        l = l->next;
    }

    free (l->next);
    l->next = NULL;
}

void deleteNode (int index, List L)
{
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!");
        return;
    }


}


pNode getNode (int index, List L)
{
    if(isEmpty (L))
        return NULL;

    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!");
        return NULL;
    }
    pNode pN = L;

    for(int i = -1; i < index; i++)
    {
        pN = pN->next;
    }
    return pN;
}

int main ()
{

}
