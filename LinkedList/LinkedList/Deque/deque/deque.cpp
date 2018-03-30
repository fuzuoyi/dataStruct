#include "deque.h"


pNode makeEmptyNode (int Value)
{
    pNode p = (pNode) malloc (sizeof (struct Node));
    if(p == NULL)
        logError ("Out of Space!!!!");

    p->next = NULL;
    p->piror = NULL;

    p->value = Value;
    return p;
}
Deque makeEmptyDeque ()
{
    pDeque d = (pDeque) malloc (sizeof (struct DEQUE));
    if(d == NULL)
        logError ("Out of Space!!!");

    d->head = makeEmptyNode ();
    d->tail = makeEmptyNode ();

    d->head->next = d->tail;
    d->tail->piror = d->head;

    return d;
}

bool isEmpty (Deque D)
{
    return D->head->next == D->tail;
}

int getSize (Deque D)
{
    pNode p = D->head;
    int size = 0;

    while(p->next != D->tail)
    {
        size++;
        p = p->next;
    }
    return size;
}

void enqueue_front (int Value, Deque D)
{
    pNode p = makeEmptyNode (Value);

    p->next = D->head->next;
    D->head->next->piror = p;


    D->head->next = p;
    p->piror = D->head;
}

void enqueue_back (int Value, Deque D)
{
    pNode p = makeEmptyNode (Value);

    p->piror = D->tail->piror;
    D->tail->piror->next = p;


    D->tail->piror = p;
    p->next = D->tail;
}


void dequeue_front (Deque D)
{
    if(isEmpty (D))
        return;

    pNode p = D->head->next;

    D->head->next = D->head->next->next;
    D->head->next->piror = D->head;

    free (p);
}

void dequeue_back (Deque D)
{
    if(isEmpty (D))
        return;
    pNode p = D->tail->piror;

    D->tail->piror = D->tail->piror->piror;
    D->tail->piror->next = D->tail;

    free (p);
}


void deleteDeque (Deque &D)
{
    while(!isEmpty (D))
    {
        dequeue_front (D);
    }
    free (D->head);
    free (D->tail);

    free (D);
}

int peek_front (Deque D)
{
    if(isEmpty (D))
        return EmptyDeQueue;

    return D->head->next->value;
}
int peek_back (Deque D)
{
    if(isEmpty (D))
        return EmptyDeQueue;

    return D->tail->piror->value;
}

void traversal_Deque (Deque D)
{
    pNode p = D->head->next;

    while(p != D->tail)
    {
        printf ("%d\t", p->value);
        p = p->next;
    }
    printf ("\r\n");
}

