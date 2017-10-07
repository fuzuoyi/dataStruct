/*!
 * \file arrayQueue.h
 * \date 2017/10/07 10:51
 *
 * \author fuy
 *
 * \brief arrayQueue.h和arrayQueue.cpp声明和实现了数组式队列
 *
 */

 /************************************************************************/
 /*
 /*  arrayQueue.h和arrayQueue.cpp文件实现了数组式队列结构
 /*
 /*　支持的操作：
 /*      enqueue,dequeue,front（在栈顶进行）
 /*      遍历、清空和删除队列
 /*      判断队列是否为空和获取队列元素个数
 /*
 /*  数组结构：
 /*                                     front             rear
 /*      index:       0         1         2      ...       n-1
 /*      value:     value1    value2    value3   ...      valuen
 /*
 /*  队列的从rear端插入新的元素，从front端取出元素，所以在操作中front和rear的
 /*  索引值会发生变化，没有固定的位置
 /*  
 /*
 /************************************************************************/


#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

// 输出错误提示信息
#define logError(x) printf(x)

// 空队列标志，当尝试从空队列中获取或删除节点时，返回该标志
#define EmptyQueue -65534

// 声明数组式队列的数据结构及其指针类型
struct QueueRecord;
typedef QueueRecord *pQueue;
typedef pQueue arrayQueue;


// 定义数组式队列的结构体
struct QueueRecord
{
    int capacity; // 队列的大小
    int front;    // 队列头部（从此处取出元素）
    int rear;     // 队列尾部（从此处添加新元素）
    int size;     // 队列元素打小
    int *array;   // 存放元素的数组（使用前需要初始化）
};

bool isEmpty (arrayQueue Q); // 判断队列是否为空
bool isFull (arrayQueue Q);  // 判断队列是否已满

int getSize (arrayQueue Q);  // 获取队列元素数目

arrayQueue createArrayQueue (int cpacity); // 创建并初始化一个队列

bool enqueue (int value, arrayQueue Q);    // 添加一个新元素进入队列
int dequeue (arrayQueue Q);                // 从队列中出去一个新元素

int front (arrayQueue Q);                  // 查看队列头部元素

void clearQueue (arrayQueue Q);       // 清空队列元素（仅仅改变索引值）
void deleteQueue (arrayQueue Q);      // 删除队列，释放内存

void traversal_Queue (arrayQueue Q);  // 遍历队列

#endif
