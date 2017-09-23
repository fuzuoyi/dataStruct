#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define logError(x) printf(x)

#define NotInList -65534
#define OutOfRange -65533
#define EmptyList -65533

struct Node;
typedef struct Node *pNode;

typedef pNode List;

struct Node
{
    int value;
    pNode next;
};

pNode makeEmpty (int value = 0);
bool isEmpty (List L);
int getSize (List L);

void insert_head (int Value, List L);
void insert_tail (int Value, List L);
bool insert (int Value, int index, List L);

void delete_head (List L);
void delete_tail (List L);
void deleteNode (int index, List L);

int search (int Value, List L);

pNode getNode (int index, List L);

int getHead (List L);
int getTail (List L);
int getValve (int index, List L);

void traversal_List (List L);
