/*!
 * \file stack.h
 * \date 2017/09/24 14:34
 *
 * \author fuy
 *
 * \brief stack.h声明了链表式栈的结构和操作方法
 *
 */

/************************************************************************/
/*
/*  stack.h和stack.cpp文件实现了链表结构的栈结构，有头结点
/*
/*　支持的操作：
/*      push,pop,top（在栈顶进行）
/*      遍历和删除栈
/*      判断链表是否为空和获取链表元素个数
/*
/*  栈结构：
/*      节点:     head -> index1 -> index2 -> index3 -> ... -> indexn -> NULL
/*      value:    NULL    value1    value2    value3           valuen
/*
/*  头结点（head）value都为空，无实际意义，head节点为栈顶
/*  头结点的存在是为了方便遍历链表（标记节点），上述操作如
/*      计算栈中元素个数并不会将head节点计入
/*      遍历链表时也不会将head的value打印出来
/*
/*  头结点也可以用头指针代替（与头结点相比，只有next指针，没有元素）
/*
/*  ************* !!! 链表中头结点，操作时容易引起错误 !!! *****************
/*
/************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//用于输出错误提示信息
# define logError(x) printf(x)

//空栈标志，在pop或top操作时，如果栈为空则返回该标志
#define EmptyStack -65534

// 栈结构体声明和结构体指针类型定义
struct Node;
typedef struct Node *pNode;
typedef pNode Stack;

// 栈节点结构体定义
// value：节点数值
// next：节点指针，指向下一个节点
struct Node
{
    int value;
    pNode next;
};

bool isEmpty (Stack S);          //判断栈是否为空
pNode makeEmpty (int value = 0); //创建并初始化一个新节点

int getSize (Stack S);           //获取栈中元素数目

void push (int value, Stack S);  //将一个新元素压入栈中
int pop (Stack S);               //从栈顶取出一个元素

int top (Stack S);               //查看栈顶元素

void clearStack (Stack S);       //清空栈(包括头结点)

void traversal_Stack (Stack S);  //遍历栈

#endif
