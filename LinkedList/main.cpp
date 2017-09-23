#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node;
typedef struct Node *pNode;

typedef pNode List;

struct Node
{
	int value;
	pNode next;
};

List makeEmpty ();

bool isEmpty (List L);
int getSize (List L);

void insert_head (int Value, List L);
void insert_tail (int Value, List L);
void insert (int Value, int index, List L);

void delete_head (List L);
void delete_tail (List L);
void deleteNode(int index, List L);

int search (int Value, List L);
int getHead (List L);
int getTail (List L);

List makeEmpty ()
{
	List l = (pNode)malloc (sizeof (struct Node));
	l->next = NULL;
	l->value = 0;
	return l;
}

bool isEmpty (List L)
{
	return L->next == NULL;
}

int main ()
{

}
