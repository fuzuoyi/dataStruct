/*!
 * \file queue.cpp
 * \date 2017/09/25 19:42
 *
 * \author fuy
 *
 * \brief queue.cpp 实现了链表式队列的操作方法
 *
 */

#include "queue.h"


//************************************
// Method:    makeEmpty
// Parameter: int value
// Returns:   pNode
// Description: 创建并初始化一个新的元素节点
//************************************
pNode makeEmpty (int value)
{
    // 申请节点内存
    pNode p = (pNode) malloc (sizeof (struct Node));

    // 校验是否申请到内存
    if(p == NULL)
        logError ("Out of Space!!!!");

    // 初始化节点的指针和值
    p->next = NULL;
    p->value = value;

    return p;
}


//************************************
// Method:    createQueue
// Returns:   Queue
// Description: 创建队列，初始化头结点
//************************************
Queue createQueue ()
{
    // 申请头结点内存
    pNode head = makeEmpty ();

    // 申请队列结构体内存
    pQNode q = (pQNode) malloc (sizeof (struct QueueNode));

    // 校验是否申请到内存
    if(q == NULL)
        logError ("Out of Space!!!");

    // 初始化队列两端指针的指向
    q->front = q->rear = head;

    return q;
}


//************************************
// Method:    isEmpty
// Parameter: Queue Q
// Returns:   bool
// Description: 判断队列是否为空
//************************************
bool isEmpty (Queue Q)
{
    // 判断头结点指向的下一个节点是否存在即可
    return Q->front->next == NULL;
}


//************************************
// Method:    getSize
// Parameter: Queue Q
// Returns:   int
// Description: 获取队列元素个数
//************************************
int getSize (Queue Q)
{
    int size = 0;

    pNode p = Q->front; // 创建遍历指针

    // 从头结点遍历到尾节点，记录个数
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
// Description: 将一个新元素加入到队列尾部中
//************************************
void enqueue (int value, Queue Q)
{
    pNode p = makeEmpty (value); // 创建新节点
    
    // 变换队列指针，完成插入操作
    Q->rear->next = p;
    Q->rear = Q->rear->next;
}


//************************************
// Method:    dequeue
// Parameter: Queue Q
// Returns:   int
// Description: 从队列头部移除一个元素
//************************************
int dequeue (Queue Q)
{
    // 如果队列元素为空，则将队尾指针归位，并返回空队列标志
    if(isEmpty (Q))
    {
        Q->rear = Q->front;
        return EmptyQueue;
    }

    pNode p = Q->front->next; // 用新指针标记队首节点位置
    int value = p->value;     // 记录新节点的值
    Q->front->next = Q->front->next->next; // 变换队列指针，孤立队首节点
    free (p);      // 释放队首节点内存

    return value;
}


//************************************
// Method:    front
// Parameter: Queue Q
// Returns:   int
// Description: 获取队首元素
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
// Description: 获取队尾元素
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
// Description: 清空队列中所有元素（清空后头结点还在）
//************************************
void clearQueue (Queue Q)
{
    // 只要队列中还有元素，则一直删除队首节点
    while(!isEmpty (Q))
        dequeue (Q);

    // 初始化指针
    Q->rear = Q->front;
}


//************************************
// Method:    deleteQueue
// Parameter: Queue Q
// Returns:   void
// Description: 删除队列（包括头结点，删除后指针失效）
//************************************
void deleteQueue (Queue Q)
{
    clearQueue (Q); // 先清空队列中所有元素
    free (Q->front);// 在释放头结点
}


//************************************
// Method:    traversal_Queue
// Parameter: Queue Q
// Returns:   void
// Description: 遍历队列
//************************************
void traversal_Queue (Queue Q)
{
    pNode p = Q->front->next; //创建遍历指针

    // 开始遍历，逐一打印
    while(p != NULL) 
    {
        printf ("%d\t", p->value);
        p = p->next;
    }
    printf ("\r\n");
}
