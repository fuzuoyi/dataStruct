/*!
 * \file arrayQueue.cpp
 * \date 2017/10/07 11:08
 *
 * \author fuy
 *
 * \brief arrayQueue.cpp 实现数组式队列
 * 
 */


#include "arrayQueue.h"


//************************************
// Method:    isEmpty
// Parameter: arrayQueue Q
// Returns:   bool
// Description: 判断队列是否为空
//************************************
bool isEmpty (arrayQueue Q)
{
    return Q->size == 0;
}


//************************************
// Method:    isFull
// Parameter: arrayQueue Q
// Returns:   bool
// Description: 判断队列是否已满
//************************************
bool isFull (arrayQueue Q)
{
    return Q->size == Q->capacity;
}


//************************************
// Method:    getSize
// Parameter: arrayQueue Q
// Returns:   int
// Description: 获取队列元素数目
//************************************
int getSize (arrayQueue Q)
{
    return Q->size;
}

//************************************
// Method:    createArrayQueue
// Parameter: int capacity
// Returns:   arrayQueue
// Description: 创建一个新的队列
//************************************
arrayQueue createArrayQueue (int capacity)
{
    // 申请队列结构体内存
    arrayQueue Q = (pQueue) malloc (sizeof (struct QueueRecord));

    // 判断是否申请成功
    if(Q == NULL)
        logError ("Out of space!!!");

    // 申请队列数组内存
    Q->array = (int *) malloc (sizeof (int) * capacity);

    // 判断是否申请成功
    if(Q->array == NULL)
        logError ("Out of space!!!");

    // 初始化队列参数（数目，头尾索引）
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}


//************************************
// Method:    enqueue
// Parameter: int value 新元素数值
// Parameter: arrayQueue Q
// Returns:   bool 
// Description: 将新元素插入队列
//************************************
bool enqueue (int value, arrayQueue Q)
{
    // 如果队列已满，插入失败，返回false
    if(isFull (Q))
        return false;

    // 插入元素；变换rear索引；修改队列size参数
    Q->array[Q->rear] = value;
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->size++;

    return true;
}


//************************************
// Method:    dequeue
// Parameter: arrayQueue Q
// Returns:   int
// Description: 从队列中取出一个元素
//************************************
int dequeue (arrayQueue Q)
{
    // 如果队列为空，取出失败，返回空队列标志
    if(isEmpty (Q))
        return EmptyQueue;
    
    // 取出元素；完成索引变换；修改队列参数
    int res = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size--;

    return res;
}


//************************************
// Method:    front
// Parameter: arrayQueue Q
// Returns:   int
// Description: 获取队列头部元素
//************************************
int front (arrayQueue Q)
{
    // 如果队列为空，返回空队列标志
    if(isEmpty (Q))
        return EmptyQueue;

    return Q->array[Q->front];
}


//************************************
// Method:    clearQueue
// Parameter: arrayQueue Q
// Returns:   void
// Description: 清空队列中的元素
//************************************
void clearQueue (arrayQueue Q)
{
    // 清空操作实质是改变队列参数
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;
}


//************************************
// Method:    deleteQueue
// Parameter: arrayQueue Q
// Returns:   void
// Description: 删除队列，释放内存
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
// Description: 遍历队列
//************************************
void traversal_Queue (arrayQueue Q)
{
    int index = Q->front; //从队列头部开始索引

    for(int i = 0; i < getSize (Q); i++)
    {
        printf ("%d\t", Q->array[(Q->front + i) % Q->capacity]);
    }
    printf ("\r\n");
}

