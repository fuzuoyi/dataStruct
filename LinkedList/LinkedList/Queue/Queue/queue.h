/*!
 * \file queue.h
 * \date 2017/09/25 19:29
 *
 * \author fuy
 *
 * \brief queue.h queue.cpp ʵ��������ʽ����
 *        queue.h ��Ҫ�Ƕ��нṹ�Ͳ�������������
 *
 */

 /************************************************************************/
 /*
 /*  queue.h��queue.cpp�ļ�ʵ��������ṹ�Ķ��нṹ����ͷ���
 /*
 /*��֧�ֵĲ�����
 /*      enqueue���ڶ�β���Ԫ�أ�, dequeue���ڶ���ɾ��Ԫ�أ�
 /*      ��������ա�ɾ������
 /*      �ж϶����Ƿ�Ϊ�պͻ�ȡ����Ԫ�ظ���
 /*
 /*  ���нṹ��
 /*     ָ��:     front                                         rear 
 /*     �ڵ� :    head -> node_1 -> node_2 -> node_2 -> ... -> node_n -> NULL
 /*     value:    NULL    value1    value2    value3           valuen
 /*
 /*  ͷ��㣨head��value��Ϊ�գ���ʵ�����壬
 /*  frontָ����Զָ��head�ڵ㣬rearָ���ڿն�����ָ��head�ڵ㣬��Ԫ��ʱ��仯
 /*  �ڲ�������ע�⣬��һЩ������rearָ���λ��ͷ���
 /*
 /*  ͷ���Ĵ�����Ϊ�˷������������ǽڵ㣩������������
 /*      ����ջ��Ԫ�ظ��������Ὣhead�ڵ����
 /*      ��������ʱҲ���Ὣhead��value��ӡ����
 /*
 /*  ͷ���Ҳ������ͷָ����棨��ͷ�����ȣ�ֻ��nextָ�룬û��Ԫ�أ�
 /*
 /*  ************* !!! ������ͷ��㣬����ʱ����������� !!! *****************
 /*
 /************************************************************************/


#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <stdio.h>
#include <stdlib.h>

//���������ʾ��Ϣ
#define logError(x) printf(x)

//�ն��б�־�������Դӿն����л�ȡ��ɾ���ڵ�ʱ�����ظñ�־
#define EmptyQueue -65534


//���нڵ�ͽڵ�ָ�������
struct Node;
typedef struct Node *pNode;


//���м���ָ�������
struct QueueNode;
typedef struct QueueNode *pQNode;
typedef pQNode Queue;


// ���нڵ�Ķ���
// value:�ڵ����ֵ
// next:ָ����һ�ڵ��ָ��
struct Node
{
    int value;
    pNode next;
};


// ���нṹ�Ķ���
// front:����ͷ��ָ��
// rear:����β��ָ��
struct QueueNode
{
    pNode front;
    pNode rear;
};


pNode makeEmpty (int value = 0);// ����һ���½ڵ�

Queue createQueue ();     // ��������

bool isEmpty (Queue Q);   // �ж϶����Ƿ�Ϊ��

int getSize (Queue Q);    // ��ȡ����Ԫ�ظ���

void enqueue (int value, Queue Q); // ��һ����Ԫ�ؼ��뵽����β����
int dequeue (Queue Q);             // �Ӷ����ײ�ɾ��һ��Ԫ��

int front (Queue Q); // ��ȡ�����ײ�Ԫ��
int back (Queue Q);  // ��ȡ����β��Ԫ��


void clearQueue (Queue Q);  // ��ն���������Ԫ�أ�ͷ��㻹��
void deleteQueue (Queue Q); // ɾ�����У��ͷ��ڴ�

void traversal_Queue (Queue Q); // ��������

#endif // !__QUEUE_H__
