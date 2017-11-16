#ifndef __DOUBLYLINKEDLIST__
#define __DOUBLYLINKEDLIST__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define logError(x) printf(x)

#define NotInList -65533
#define EmptyList -65534
#define OutOfRange -65535

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


pNode makeEmptyNode (int value);
DList makeEmptyDList ();


bool isEmpty (DList L);

int getSize (DList L);

void insert_head (int Value, DList L);
void insert_tail (int Value, DList L);
bool insert (int Value, int index, DList L);

void delete_head (DList L);
void delete_tail (DList L);
void deleteNode (int index, DList L);
void deleteList (DList L);

int search (int Value, DList L);

pNode getNode (int index, DList L);

int getHead (DList L);
int getTail (DList L);
int getValve (int index, DList L);

void traversal_List (DList L);



#endif
