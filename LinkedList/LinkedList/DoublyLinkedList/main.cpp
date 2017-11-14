#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define logError(x) printf(x)

struct Node;
typedef struct Node *pNode;
typedef pNode DList;

struct Node
{
	int value;
	pNode next;
	pNode piror;
};


pNode makeEmptyNode(int value = 0); 
bool makeEmptyDList (pNode head, pNode rear);


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

bool makeEmptyDList (pNode head, pNode rear)
{

}


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

