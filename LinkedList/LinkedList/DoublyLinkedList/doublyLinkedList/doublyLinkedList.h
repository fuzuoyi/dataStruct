#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ���������ʾ��Ϣ
#define logError(x) printf(x)

// �������
#define NotInList -65533
#define EmptyList -65534
#define OutOfRange -65535

// �����ڵ�ṹ��
struct Node;
typedef struct Node* pNode;

// ����˫����ṹ��
struct doublyLinkedList;
typedef struct doublyLinkedList* pDList;
typedef pDList DList;

struct Node
{
    // �ڵ�ֵ
    int value;

    // ǰ���ͺ���
    pNode next;
    pNode piror;
};

struct doublyLinkedList
{
    // ͷβ�ڵ�(ֻ��Ϊ�˷�����������洢ֵ)
    pNode head;
    pNode tail;
};


// �����½ڵ���µ�����
pNode makeEmptyNode (int value);
DList makeEmptyDList ();

// �ж������Ƿ�Ϊ�ա���ȡ�������
bool isEmpty (DList L);
int getSize (DList L);

// ��ͷβ��������Ԫ�ؽ�������
void insert_head (int Value, DList L);
void insert_tail (int Value, DList L);

// ��ָ�������������½ڵ�
bool insert (int Value, int index, DList L);

// ɾ��ͷβ�ڵ� 
void delete_head (DList L);
void delete_tail (DList L);

// ɾ��ָ���������Ľڵ�
void deleteNode (int index, DList L);

// ɾ������
void deleteList (DList L);

// �����������Ƿ���ĳ��ֵ������NotInList���߸�ֵ�������еĵ�һ������
int search (int Value, DList L);

// ����ĳ���������ڵ��ָ��
pNode getNode (int index, DList L);

// ��ȡͷβ�ڵ��ֵ
int getHead (DList L);
int getTail (DList L);

// ��ȡĳ����������ֵ
int getValve (int index, DList L);

// ��������
void traversal_List (DList L);

#endif
