/*!
 * \file arrayStack.h
 * \date 2017/09/24 17:04
 *
 * \author fuy
 *
 * \brief arrayStack.h和arrayStack.cpp实现了数组式的栈结构
 *
 */

 /************************************************************************/
 /*
 /*  arrayStack.h和arrayStack.cpp文件实现了数组式栈结构
 /*
 /*　支持的操作：
 /*      push,pop,top（在栈顶进行）
 /*      遍历、清空和删除栈
 /*      判断栈是否为空和获取栈元素个数
 /*
 /*  数组结构：
 /*      index:    -1        0         1         2      ...       n-1
 /*      value:    NULL    value1    value2    value3   ...      valuen
 /*
 /*  TopOfStack为栈顶索引值，新增或删除元素实质都是改变栈顶索引
 /*  
 /*  索引-1及其值都不存在，可看做假想的头结点
 /*
 /************************************************************************/


#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__


#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


//输出错误提示信息
#define logError(x) printf(x)

//空栈索引，数组下标为-1
#define EmptyTopOfStack -1

//空栈标志，当程序想要检索空栈时，返回该值
#define EmptyArrayStack -65534


//声明数组栈的结构和指针定义
struct StackRecord;
typedef StackRecord *arrayStack;


//定义数组式栈的结构体
struct StackRecord
{
    int capacity;  //栈的容量
    int topOfStack;//栈的索引值（数组下标，空栈为-1）
    int *array;    //数组指针，使用前需要完成初始化
};

bool isEmpty (arrayStack S);  //判断栈是否为空
bool isFull (arrayStack S);   //判断栈是否已满

int getSize (arrayStack S);   //获取栈中元素的大小

arrayStack createStack (int cpacity); //创建一个新栈，完成结构体的初始化

void emptyStack (arrayStack S);      //清空栈中元素，实质是将索引下标置为-1
void deleteStack (arrayStack S);     //删除栈，栈的内存将被回收，指针失去意义

bool push (int value, arrayStack S); //将一个新的元素压入栈中，如果栈满则返回false
int pop (arrayStack S);              //取出栈顶元素，如果栈空则返回空栈标志

int top (arrayStack S);              //查看栈顶元素，如果栈空则返回空栈标志

void traversal_Stack (arrayStack S); //遍历栈


#endif
