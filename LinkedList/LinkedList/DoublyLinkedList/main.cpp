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
    pNode rear;
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
    d->head = makeEmptyNode ();
    d->rear = makeEmptyNode ();
    d->head->next = d->rear;
    d->rear->piror = d->head;
    return d;
}


bool isEmpty (DList L)
{
    return L->head->next == L->rear;
}

int getSize (DList L)
{
    pNode p = L->head;
    int size = 0;

    while(p->next != L->rear)
    {
        size++;
        p = p->next;
    }
    return size;
}

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

int main ()
{
    pNode head = NULL, rear = NULL;
    DList d = makeEmptyDList();

    isEmpty (d);
    getSize (d);

    system ("pause");
    return 0;
}