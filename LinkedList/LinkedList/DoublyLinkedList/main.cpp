#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define logError(x) printf(x)

struct Node;
typedef struct Node* pNode;
typedef struct doublyLinkedList* pDList;
typedef pDList DList;

struct Node
{
	int value;
	pNode next;
	pNode piror;
};

struct doublyLinkedList
{
    pNode head;
    pNode tail;
};


pNode makeEmptyNode(int value); 
DList makeEmptyDList ();


bool isEmpty(DList L);

int getSize(DList L);

void insert_head(int Value, DList L);
void insert_tail(int Value, DList L);
bool insert(int Value, int index, DList L);

void delete_head(DList L);
void delete_tail(DList L);
void deleteNode(int index, DList L);
void deleteList(DList L);

int search(int Value, DList L);

pNode getNode(int index, DList L);

int getHead(DList L);
int getTail(DList L);
int getValve(int index, DList L);

void traversal_List(DList L);



pNode makeEmptyNode(int value = 0)
{
	pNode p = (pNode)malloc(sizeof(struct Node));
	if (p == NULL)
		logError("Out of Space!!!!");

	p->next = NULL;
	p->piror = NULL;

	p->value = value;
	return p;
}

DList makeEmptyDList ()
{
    DList d = (pDList) malloc (sizeof (struct doublyLinkedList));
    if(d == NULL)
        logError ("Out of Space!!!");

    d->head = makeEmptyNode ();
    d->tail = makeEmptyNode ();
    d->head->next = d->tail;
    d->tail->piror = d->head;
    return d;
}


bool isEmpty (DList L)
{
    return L->head->next == L->tail;
}

int getSize (DList L)
{
    pNode p = L->head;
    int size = 0;

    while(p->next != L->tail)
    {
        size++;
        p = p->next;
    }
    return size;
}

void insert_head (int Value, DList L)
{
    pNode p = makeEmptyNode (Value);

    p->next = L->head->next;
    L->head->next->piror = p;


    L->head->next = p;
    p->piror = L->head;
}

void insert_tail (int Value, DList L)
{
    pNode p = makeEmptyNode (Value);

    p->piror = L->tail->piror;
    L->tail->piror->next = p;


    L->tail->piror = p;
    p->next = L->tail;
}

bool insert (int Value, int index, DList L)
{

    pNode p = getNode (index,L);
    if(p == NULL)
        return false;

    pNode temp = makeEmptyNode (Value);

    pNode pre = p->piror;

    pre->next = temp;
    temp->piror = pre;

    temp->next = p;
    p->piror = temp;

    return true;
}

void delete_head (DList L)
{
    if(isEmpty (L))
        return;
    pNode p = L->head->next;

    L->head->next = L->head->next->next;
    L->head->next->piror = L->head;

    free (p);
}

void delete_tail (DList L)
{
    if(isEmpty (L))
        return;
    pNode p = L->tail->piror;

    L->tail->piror = L->tail->piror->piror;
    L->tail->piror->next = L->tail;

    free (p);
}
void deleteNode (int index, DList L)
{
    pNode p = getNode (index, L);
    if(p == NULL)
        return;

    pNode temp = p->piror;

    temp->next = p->next;
    p->next->piror = temp;

    free (p);
}
void deleteList(DList L);

int search(int Value, DList L);

pNode getNode (int index, DList L)
{
    int size = getSize (L);
    if(index < 0 | index > size)
    {
        logError ("index out of range!!!");
        return NULL;
    }

    pNode p = L->head->next;
    int i = 0;
    while(i != index)
    {
        i++;
        p = p->next;
    }
    return p;
}

int getHead(DList L);
int getTail(DList L);
int getValve(int index, DList L);

void traversal_List(DList L);

int main ()
{
    pNode head = NULL, rear = NULL;
    DList d = makeEmptyDList();


    insert_head (2, d);
    insert_tail (3, d);
    insert_head (4, d);
    insert_tail (5, d);

    insert (8, 4, d);
    insert (7, 2, d);
    insert (6, 3, d);


    delete_head (d);
    delete_tail (d);

    isEmpty (d);
    getSize (d);

    system ("pause");
    return 0;
}