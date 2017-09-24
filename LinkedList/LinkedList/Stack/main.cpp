#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
//#include "stack/stack.h"
#include "arrayStack/arrayStack.h"

#define logError(x) printf(x)

struct StackRecord;
typedef StackRecord *arrayStack;

struct StackRecord
{
    int capacity;
    int topOfStack;
    int *array;
};

bool isEmpty (arrayStack S);
bool isFull (arrayStack S);

arrayStack createStack (int cpacity);

void emptyStack (arrayStack S);
void clearStack (arrayStack S);

bool push (arrayStack S);
int pop (arrayStack S);

int top (arrayStack S);


bool isEmpty (arrayStack S)
{
    return S->topOfStack == -1;
}
bool isFull (arrayStack S)
{
    return S->topOfStack == S->capacity - 1;
}

arrayStack createStack (int capacity)
{
    arrayStack S = (StackRecord*) malloc (sizeof (struct StackRecord));
    
    if(S == NULL)
        logError ("Out of space!!!");

    S->array = (int *)malloc (sizeof (int) * capacity);
    S->capacity = capacity;

    if(S->capacity == NULL)
        logError ("Out of space!!!");

    S->topOfStack = -1;

    return S;
}

void emptyStack (arrayStack S);
void clearStack (arrayStack S);

bool push (arrayStack S);
int pop (arrayStack S);

int top (arrayStack S);


int main ()
{
    return 0;
}

