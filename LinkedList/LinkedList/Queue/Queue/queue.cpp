/*!
 * \file queue.cpp
 * \date 2017/09/25 19:42
 *
 * \author fuy
 *
 * \brief queue.cpp ʵ��������ʽ���еĲ�������
 *
 */

#include "queue.h"


//************************************
// Method:    makeEmpty
// Parameter: int value
// Returns:   pNode
// Description: ��������ʼ��һ���µ�Ԫ�ؽڵ�
//************************************
pNode makeEmpty (int value)
{
    // ����ڵ��ڴ�
    pNode p = (pNode) malloc (sizeof (struct Node));

    // У���Ƿ����뵽�ڴ�
    if(p == NULL)
        logError ("Out of Space!!!!");

    // ��ʼ���ڵ��ָ���ֵ
    p->next = NULL;
    p->value = value;

    return p;
}


//************************************
// Method:    createQueue
// Returns:   Queue
// Description: �������У���ʼ��ͷ���
//************************************
Queue createQueue ()
{
    // ����ͷ����ڴ�
    pNode head = makeEmpty ();

    // ������нṹ���ڴ�
    pQNode q = (pQNode) malloc (sizeof (struct QueueNode));

    // У���Ƿ����뵽�ڴ�
    if(q == NULL)
        logError ("Out of Space!!!");

    // ��ʼ����������ָ���ָ��
    q->front = q->rear = head;

    return q;
}


//************************************
// Method:    isEmpty
// Parameter: Queue Q
// Returns:   bool
// Description: �ж϶����Ƿ�Ϊ��
//************************************
bool isEmpty (Queue Q)
{
    // �ж�ͷ���ָ�����һ���ڵ��Ƿ���ڼ���
    return Q->front->next == NULL;
}


//************************************
// Method:    getSize
// Parameter: Queue Q
// Returns:   int
// Description: ��ȡ����Ԫ�ظ���
//************************************
int getSize (Queue Q)
{
    int size = 0;

    pNode p = Q->front; // ��������ָ��

    // ��ͷ��������β�ڵ㣬��¼����
    while(p != Q->rear) 
    {
        size++;
        p = p->next;
    }

    return size;
}


//************************************
// Method:    enqueue
// Parameter: int value
// Parameter: Queue Q
// Returns:   void
// Description: ��һ����Ԫ�ؼ��뵽����β����
//************************************
void enqueue (int value, Queue Q)
{
    pNode p = makeEmpty (value); // �����½ڵ�
    
    // �任����ָ�룬��ɲ������
    Q->rear->next = p;
    Q->rear = Q->rear->next;
}


//************************************
// Method:    dequeue
// Parameter: Queue Q
// Returns:   int
// Description: �Ӷ���ͷ���Ƴ�һ��Ԫ��
//************************************
int dequeue (Queue Q)
{
    // �������Ԫ��Ϊ�գ��򽫶�βָ���λ�������ؿն��б�־
    if(isEmpty (Q))
    {
        Q->rear = Q->front;
        return EmptyQueue;
    }

    pNode p = Q->front->next; // ����ָ���Ƕ��׽ڵ�λ��
    int value = p->value;     // ��¼�½ڵ��ֵ
    Q->front->next = Q->front->next->next; // �任����ָ�룬�������׽ڵ�
    free (p);      // �ͷŶ��׽ڵ��ڴ�

    return value;
}


//************************************
// Method:    front
// Parameter: Queue Q
// Returns:   int
// Description: ��ȡ����Ԫ��
//************************************
int front (Queue Q)
{
    if(isEmpty (Q))
        return EmptyQueue;

    return Q->front->next->value;
}


//************************************
// Method:    back
// Parameter: Queue Q
// Returns:   int
// Description: ��ȡ��βԪ��
//************************************
int back (Queue Q)
{
    if(isEmpty (Q))
        return EmptyQueue;

    return Q->rear->value;
}


//************************************
// Method:    clearQueue
// Parameter: Queue Q
// Returns:   void
// Description: ��ն���������Ԫ�أ���պ�ͷ��㻹�ڣ�
//************************************
void clearQueue (Queue Q)
{
    // ֻҪ�����л���Ԫ�أ���һֱɾ�����׽ڵ�
    while(!isEmpty (Q))
        dequeue (Q);

    // ��ʼ��ָ��
    Q->rear = Q->front;
}


//************************************
// Method:    deleteQueue
// Parameter: Queue Q
// Returns:   void
// Description: ɾ�����У�����ͷ��㣬ɾ����ָ��ʧЧ��
//************************************
void deleteQueue (Queue Q)
{
    clearQueue (Q); // ����ն���������Ԫ��
    free (Q->front);// ���ͷ�ͷ���
}


//************************************
// Method:    traversal_Queue
// Parameter: Queue Q
// Returns:   void
// Description: ��������
//************************************
void traversal_Queue (Queue Q)
{
    pNode p = Q->front->next; //��������ָ��

    // ��ʼ��������һ��ӡ
    while(p != NULL) 
    {
        printf ("%d\t", p->value);
        p = p->next;
    }
    printf ("\r\n");
}
