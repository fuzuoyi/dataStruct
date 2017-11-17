#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 输出错误提示消息
#define logError(x) printf(x)

// 错误代码
#define NotInList -65533
#define EmptyList -65534
#define OutOfRange -65535

// 声明节点结构体
struct Node;
typedef struct Node* pNode;

// 声明双链表结构体
struct doublyLinkedList;
typedef struct doublyLinkedList* pDList;
typedef pDList DList;

struct Node
{
    // 节点值
    int value;

    // 前驱和后驱
    pNode next;
    pNode piror;
};

struct doublyLinkedList
{
    // 头尾节点(只是为了方便遍历，不存储值)
    pNode head;
    pNode tail;
};


// 创建新节点和新的链表
pNode makeEmptyNode (int value);
DList makeEmptyDList ();

// 判断链表是否为空、获取链表个数
bool isEmpty (DList L);
int getSize (DList L);

// 从头尾部插入新元素进入链表
void insert_head (int Value, DList L);
void insert_tail (int Value, DList L);

// 从指定索引处插入新节点
bool insert (int Value, int index, DList L);

// 删除头尾节点 
void delete_head (DList L);
void delete_tail (DList L);

// 删除指定索引处的节点
void deleteNode (int index, DList L);

// 删除链表
void deleteList (DList L);

// 搜索链表中是否有某个值，返回NotInList或者该值在链表中的第一个索引
int search (int Value, DList L);

// 返回某个索引处节点的指针
pNode getNode (int index, DList L);

// 获取头尾节点的值
int getHead (DList L);
int getTail (DList L);

// 获取某个索引处的值
int getValve (int index, DList L);

// 遍历链表
void traversal_List (DList L);

#endif
