#include "linkedList.h"

pNode makeEmpty (int value)
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
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!\r\n");
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

    pNode temp = L->next;
    L->next = L->next->next;
    free (temp);
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
    if(isEmpty (L))
        return;
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!\r\n");
        return;
    }

    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }

    pNode temp = L->next->next;
    free (L->next);
    L->next = temp;
}


pNode getNode (int index, List L)
{
    if(isEmpty (L))
        return NULL;

    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!\r\n");
        return NULL;
    }
    pNode pN = L;

    for(int i = -1; i < index; i++)
    {
        pN = pN->next;
    }
    return pN;
}

int search (int Value, List L)
{
    int index = 0;

    L = L->next;

    while(L != NULL)
    {
        if(L->value == Value)
        {
            return index;
        }
        L = L->next;
        index++;
    }

    return NotInList;
}

int getValve (int index, List L)
{
    if(isEmpty (L))
        return EmptyList;
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!\r\n");
        return OutOfRange;
    }

    L = L->next;
    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }
    return L->value;
}


int getHead (List L)
{
    if(isEmpty (L))
        return false;
    return L->next->value;
}

int getTail (List L)
{
    return getValve (getSize (L) - 1, L);
}

void traversal_List (List L)
{
    List l = L->next;
    while(l != NULL)
    {
        printf ("%d\t", l->value);
        l = l->next;
    }
}
