#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 输出错误提示消息
#define logError(x) printf(x)

// 错误代码
#define NotInDeQueue -65533
#define EmptyDeQueue -65534
#define OutOfRange -65535

// 声明节点结构体
struct Node;
typedef struct Node* pNode;

// 声明双链表结构体
struct DEQUE;
typedef struct DEQUE* pDeque;
typedef pDeque Deque;

struct Node
{
    // 节点值
    int value;

    // 前驱和后驱
    pNode next;
    pNode piror;
};

struct DEQUE
{
    // 头尾节点(只是为了方便遍历，不存储值)
    pNode head;
    pNode tail;
};


// 创建新节点和双向队列
pNode makeEmptyNode (int Value = 0);
Deque makeEmptyDeque ();

// 判断是否为空；统计队列个数
bool isEmpty (Deque D);
int getSize (Deque D);

// 从队列头部或尾部插入新节点
void enqueue_front (int Value, Deque D);
void enqueue_back (int Value, Deque D);

// 从队列头部或尾部删除节点
void dequeue_front (Deque D);
void dequeue_back (Deque D);

//  删除队列
void deleteDeque (Deque D);

// 获取队列头部或尾部节点值
int peek_front (Deque D);
int peek_back (Deque D);

// 遍历双端队列
void traversal_Deque (Deque D);

#endif // !__DEQUE_H__
