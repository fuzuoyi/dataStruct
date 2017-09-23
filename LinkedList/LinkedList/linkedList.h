/*!
 * \file linkedList.h
 *
 * \author fuy
 * \date 九月 2017
 *
 * \brief linkedList.h声明了单链表的结构和操作方法
 */

/************************************************************************/
/*
/*  linkedList.h和linkedList.cpp文件实现的链表为单向链表，有头结点
/*  
/*　支持的操作：
/*      两端取值、插值以及删值；
/*      搜索节点和获取某一索引处的值；
/*      遍历链表和删除链表操作
/*      判断链表是否为空和获取链表元素个数
/*      返回索引处的节点指针
/*    
/*  链表结构：
/*      index:    NULL      0         1         2               n-1
/*      节点:     head -> index1 -> index2 -> index3 -> ... -> indexn -> NULL        
/*      value:    NULL    value1    value2    value3           valuen   
/*
/*  头结点（head）的index和value都为空，无实际意义
/*  头结点的存在是为了方便遍历链表（标记节点），上述操作如
/*      计算链表元素个数并不会将head节点计入；
/*      删除、插入或者查询head等操作实际也是指链表index=0的元素，并不是头结点
/*      遍历链表时也不会将head的value打印出来
/*
/*  头结点也可以用头指针代替（与头结点相比，只有next指针，没有元素）
/*  
/*  ***************** 链表中头结点，操作时容易引起错误 *********************
/*
/************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// 链表只有logError(x) 和遍历链表函数用到了printf()函数，用于输出提示信息
#define logError(x) printf(x)

// 在查询或者插入节点等操作时，index可能越界，链表也可能为空，返回下面的数即表示越界或链表为空
#define NotInList -65534
#define OutOfRange -65533
#define EmptyList -65532

// 链表结构体声明和结构体指针类型定义
struct Node;
typedef struct Node *pNode;
typedef pNode List;

// 链表结构体定义
// value：节点数值
// next：节点指针，指向下一个节点
struct Node
{
    int value;
    pNode next;
};


pNode makeEmpty (int value = 0); //创建新节点，用value初始化
bool isEmpty (List L);           //判断链表是否为空   

int getSize (List L);            //获取链表元素大小

void insert_head (int Value, List L);       //在链表头部插入元素
void insert_tail (int Value, List L);       //在链表尾部插入元素
bool insert (int Value, int index, List L); //在index处插入元素

void delete_head (List L);           //删除头部元素
void delete_tail (List L);           //删除尾部元素
void deleteNode (int index, List L); //删除index处元素
void deleteList (List L);            //清空链表(包括头部节点)

int search (int Value, List L);      //搜索链表中值为value的元素，返回其index，没有则返回NotInList（如果有多个值为value的元素，则只返回第一个元素的索引值）

pNode getNode (int index, List L);   //返回链表中index处的节点指针

int getHead (List L);                //返回头部元素
int getTail (List L);                //返回尾部元素
int getValve (int index, List L);    //返回index处的元素

void traversal_List (List L);        //遍历链表
