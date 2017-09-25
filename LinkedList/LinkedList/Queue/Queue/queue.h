/*!
 * \file queue.h
 * \date 2017/09/25 19:29
 *
 * \author fuy
 *
 * \brief queue.h queue.cpp 实现了链表式队列
 *        queue.h 主要是队列结构和操作方法的声明
 *
 */

 /************************************************************************/
 /*
 /*  queue.h和queue.cpp文件实现了链表结构的队列结构，有头结点
 /*
 /*　支持的操作：
 /*      enqueue（在队尾添加元素）, dequeue（在队首删除元素）
 /*      遍历、清空、删除队列
 /*      判断队列是否为空和获取链表元素个数
 /*
 /*  队列结构：
 /*     指针:     front                                         rear 
 /*     节点 :    head -> node_1 -> node_2 -> node_2 -> ... -> node_n -> NULL
 /*     value:    NULL    value1    value2    value3           valuen
 /*
 /*  头结点（head）value都为空，无实际意义，
 /*  front指针永远指向head节点，rear指针在空队列是指向head节点，有元素时会变化
 /*  在操作中需注意，在一些操作后将rear指针归位到头结点
 /*
 /*  头结点的存在是为了方便遍历链表（标记节点），上述操作如
 /*      计算栈中元素个数并不会将head节点计入
 /*      遍历队列时也不会将head的value打印出来
 /*
 /*  头结点也可以用头指针代替（与头结点相比，只有next指针，没有元素）
 /*
 /*  ************* !!! 链表中头结点，操作时容易引起错误 !!! *****************
 /*
 /************************************************************************/


#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <stdio.h>
#include <stdlib.h>

//输出错误提示信息
#define logError(x) printf(x)

//空队列标志，当尝试从空队列中获取或删除节点时，返回该标志
#define EmptyQueue -65534


//队列节点和节点指针的声明
struct Node;
typedef struct Node *pNode;


//队列及其指针的声明
struct QueueNode;
typedef struct QueueNode *pQNode;
typedef pQNode Queue;


// 队列节点的定义
// value:节点的数值
// next:指向下一节点的指针
struct Node
{
    int value;
    pNode next;
};


// 队列结构的定义
// front:队列头部指针
// rear:队列尾部指针
struct QueueNode
{
    pNode front;
    pNode rear;
};


pNode makeEmpty (int value = 0);// 创建一个新节点

Queue createQueue ();     // 创建队列

bool isEmpty (Queue Q);   // 判断队列是否为空

int getSize (Queue Q);    // 获取队列元素个数

void enqueue (int value, Queue Q); // 将一个新元素加入到队列尾部中
int dequeue (Queue Q);             // 从队列首部删除一个元素

int front (Queue Q); // 获取队列首部元素
int back (Queue Q);  // 获取队列尾部元素


void clearQueue (Queue Q);  // 清空队列中所有元素，头结点还在
void deleteQueue (Queue Q); // 删除队列，释放内存

void traversal_Queue (Queue Q); // 遍历队列

#endif // !__QUEUE_H__
