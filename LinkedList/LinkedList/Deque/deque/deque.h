#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ���������ʾ��Ϣ
#define logError(x) printf(x)

// �������
#define NotInDeQueue -65533
#define EmptyDeQueue -65534
#define OutOfRange -65535

// �����ڵ�ṹ��
struct Node;
typedef struct Node* pNode;

// ����˫����ṹ��
struct DEQUE;
typedef struct DEQUE* pDeque;
typedef pDeque Deque;

struct Node
{
    // �ڵ�ֵ
    int value;

    // ǰ���ͺ���
    pNode next;
    pNode piror;
};

struct DEQUE
{
    // ͷβ�ڵ�(ֻ��Ϊ�˷�����������洢ֵ)
    pNode head;
    pNode tail;
};


pNode makeEmptyNode (int Value = 0);
Deque makeEmptyDeque ();

bool isEmpty (Deque D);
int getSize (Deque D);

void enqueue_front (int Value, Deque D);
void enqueue_back (int Value, Deque D);


void dequeue_front (Deque D);
void dequeue_back (Deque D);


void deleteDeque (Deque D);

int peek_front (Deque D);
int peek_back (Deque D);

void traversal_List (Deque D);

#endif // !__DEQUE_H__
