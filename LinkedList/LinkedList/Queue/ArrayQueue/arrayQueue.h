/*!
 * \file arrayQueue.h
 * \date 2017/10/07 10:51
 *
 * \author fuy
 *
 * \brief arrayQueue.h��arrayQueue.cpp������ʵ��������ʽ����
 *
 */

 /************************************************************************/
 /*
 /*  arrayQueue.h��arrayQueue.cpp�ļ�ʵ��������ʽ���нṹ
 /*
 /*��֧�ֵĲ�����
 /*      enqueue,dequeue,front����ջ�����У�
 /*      ��������պ�ɾ������
 /*      �ж϶����Ƿ�Ϊ�պͻ�ȡ����Ԫ�ظ���
 /*
 /*  ����ṹ��
 /*                                     front             rear
 /*      index:       0         1         2      ...       n-1
 /*      value:     value1    value2    value3   ...      valuen
 /*
 /*  ���еĴ�rear�˲����µ�Ԫ�أ���front��ȡ��Ԫ�أ������ڲ�����front��rear��
 /*  ����ֵ�ᷢ���仯��û�й̶���λ��
 /*  
 /*
 /************************************************************************/


#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

// ���������ʾ��Ϣ
#define logError(x) printf(x)

// �ն��б�־�������Դӿն����л�ȡ��ɾ���ڵ�ʱ�����ظñ�־
#define EmptyQueue -65534

// ��������ʽ���е����ݽṹ����ָ������
struct QueueRecord;
typedef QueueRecord *pQueue;
typedef pQueue arrayQueue;


// ��������ʽ���еĽṹ��
struct QueueRecord
{
    int capacity; // ���еĴ�С
    int front;    // ����ͷ�����Ӵ˴�ȡ��Ԫ�أ�
    int rear;     // ����β�����Ӵ˴������Ԫ�أ�
    int size;     // ����Ԫ�ش�С
    int *array;   // ���Ԫ�ص����飨ʹ��ǰ��Ҫ��ʼ����
};

bool isEmpty (arrayQueue Q); // �ж϶����Ƿ�Ϊ��
bool isFull (arrayQueue Q);  // �ж϶����Ƿ�����

int getSize (arrayQueue Q);  // ��ȡ����Ԫ����Ŀ

arrayQueue createArrayQueue (int cpacity); // ��������ʼ��һ������

bool enqueue (int value, arrayQueue Q);    // ���һ����Ԫ�ؽ������
int dequeue (arrayQueue Q);                // �Ӷ����г�ȥһ����Ԫ��

int front (arrayQueue Q);                  // �鿴����ͷ��Ԫ��

void clearQueue (arrayQueue Q);       // ��ն���Ԫ�أ������ı�����ֵ��
void deleteQueue (arrayQueue Q);      // ɾ�����У��ͷ��ڴ�

void traversal_Queue (arrayQueue Q);  // ��������

#endif
