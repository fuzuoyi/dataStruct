/*!
 * \file arrayQueue.cpp
 * \date 2017/10/07 11:08
 *
 * \author fuy
 *
 * \brief arrayQueue.cpp ʵ������ʽ����
 * 
 */


#include "arrayQueue.h"


//************************************
// Method:    isEmpty
// Parameter: arrayQueue Q
// Returns:   bool
// Description: �ж϶����Ƿ�Ϊ��
//************************************
bool isEmpty (arrayQueue Q)
{
    return Q->size == 0;
}


//************************************
// Method:    isFull
// Parameter: arrayQueue Q
// Returns:   bool
// Description: �ж϶����Ƿ�����
//************************************
bool isFull (arrayQueue Q)
{
    return Q->size == Q->capacity;
}


//************************************
// Method:    getSize
// Parameter: arrayQueue Q
// Returns:   int
// Description: ��ȡ����Ԫ����Ŀ
//************************************
int getSize (arrayQueue Q)
{
    return Q->size;
}

//************************************
// Method:    createArrayQueue
// Parameter: int capacity
// Returns:   arrayQueue
// Description: ����һ���µĶ���
//************************************
arrayQueue createArrayQueue (int capacity)
{
    // ������нṹ���ڴ�
    arrayQueue Q = (pQueue) malloc (sizeof (struct QueueRecord));

    // �ж��Ƿ�����ɹ�
    if(Q == NULL)
        logError ("Out of space!!!");

    // ������������ڴ�
    Q->array = (int *) malloc (sizeof (int) * capacity);

    // �ж��Ƿ�����ɹ�
    if(Q->array == NULL)
        logError ("Out of space!!!");

    // ��ʼ�����в�������Ŀ��ͷβ������
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}


//************************************
// Method:    enqueue
// Parameter: int value ��Ԫ����ֵ
// Parameter: arrayQueue Q
// Returns:   bool 
// Description: ����Ԫ�ز������
//************************************
bool enqueue (int value, arrayQueue Q)
{
    // �����������������ʧ�ܣ�����false
    if(isFull (Q))
        return false;

    // ����Ԫ�أ��任rear�������޸Ķ���size����
    Q->array[Q->rear] = value;
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->size++;

    return true;
}


//************************************
// Method:    dequeue
// Parameter: arrayQueue Q
// Returns:   int
// Description: �Ӷ�����ȡ��һ��Ԫ��
//************************************
int dequeue (arrayQueue Q)
{
    // �������Ϊ�գ�ȡ��ʧ�ܣ����ؿն��б�־
    if(isEmpty (Q))
        return EmptyQueue;
    
    // ȡ��Ԫ�أ���������任���޸Ķ��в���
    int res = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;

    return res;
}


//************************************
// Method:    front
// Parameter: arrayQueue Q
// Returns:   int
// Description: ��ȡ����ͷ��Ԫ��
//************************************
int front (arrayQueue Q)
{
    // �������Ϊ�գ����ؿն��б�־
    if(isEmpty (Q))
        return EmptyQueue;

    return Q->array[Q->front];
}


//************************************
// Method:    clearQueue
// Parameter: arrayQueue Q
// Returns:   void
// Description: ��ն����е�Ԫ��
//************************************
void clearQueue (arrayQueue Q)
{
    // ��ղ���ʵ���Ǹı���в���
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;
}


//************************************
// Method:    deleteQueue
// Parameter: arrayQueue Q
// Returns:   void
// Description: ɾ�����У��ͷ��ڴ�
//************************************
void deleteQueue (arrayQueue Q)
{
    if(Q != NULL)
    {
        free (Q->array);
        free (Q);
    }
}

//************************************
// Method:    traversal_Queue
// Parameter: arrayQueue Q
// Returns:   void
// Description: ��������
//************************************
void traversal_Queue (arrayQueue Q)
{
    int index = Q->front; //�Ӷ���ͷ����ʼ����

    for(int i = 0; i < getSize (Q); i++)
    {
        printf ("%d\t", Q->array[(Q->front + i) % Q->capacity]);
    }
    printf ("\r\n");
}

