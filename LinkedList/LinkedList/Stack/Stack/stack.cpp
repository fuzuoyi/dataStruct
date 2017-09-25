/*!
 * \file stack.cpp
 * \date 2017/09/24 14:48
 *
 * \author fuy
 *
 * \brief stack.cpp实现了链表式栈的结构和操作方法
 *
 */


#include "stack.h"


//************************************
// Method:    isEmpty
// Parameter: Stack S
// Returns:   bool
// Description: 判断栈是否为空
//************************************
bool isEmpty (Stack S)
{
    return S->next == NULL;
}


//************************************
// Method:    makeEmpty
// Parameter: int value
// Returns:   pNode
// Description: 创建并初始化一个新的栈节点
//************************************
pNode makeEmpty (int value)
{
    pNode p = (pNode) malloc (sizeof (struct Node));//申请节点内存
    if(p == NULL)
    {
        logError ("Out of Space!!!");
    }
    //初始化节点元素和指针
    p->next = NULL;
    p->value = value;
    return p;
}


//************************************
// Method:    getSize
// Parameter: Stack S
// Returns:   int
// Description: 获取栈中元素个数
//************************************
int getSize (Stack S)
{
    int size = 0;
    S = S->next;     //计算中忽略头结点
    while(S != NULL) //遍历栈，记录节点个数
    {
        size++;
        S = S->next;
    }
    return size;
}
//************************************
// Method:    push
// Parameter: int value
// Parameter: Stack S
// Returns:   void
// Description: 将一个新元素节点压入栈中
//************************************
void push (int value, Stack S)
{
    //创建新节点
    pNode p = makeEmpty (value);

    //完成指针变换
    p->next = S->next;
    S->next = p;
}
//************************************
// Method:    pop
// Parameter: Stack S
// Returns:   int
// Description: 从栈顶取出一个元素
//************************************
int pop (Stack S)
{
    //只有栈非空的条件下才能完成取出操作
    if(!isEmpty (S))
    {
        //变换指针，见栈顶元素从栈中孤立出来
        pNode p = S->next;
        S->next = S->next->next;

        int value = p->value; //取值
        free (p); //释放栈顶内存
        return value;
    }

    //如果为空栈，返回空栈标志
    return EmptyStack;
}


//************************************
// Method:    top
// Parameter: Stack S
// Returns:   int
// Description: 查看栈顶元素（不取出元素）
//************************************
int top (Stack S)
{
    //只有栈非空的条件下才能完成查看操作
    if(!isEmpty (S))
    {
        return  S->next->value;
    }

    //如果为空栈，返回空栈标志
    return EmptyStack;
}


//************************************
// Method:    clearStack
// FullName:  clearStack
// Access:    public 
// Qualifier:
// Parameter: Stack S
// Returns:   void
// Description:
//************************************
void clearStack (Stack S)
{
    while(!isEmpty (S))
        pop (S);
}

//************************************
// Method:    deleteStack
// Parameter: Stack S
// Returns:   void
// Description: 清空栈（所有元素，包括头结点），清空后栈指针失效
//************************************
void deleteStack (Stack S)
{
    Stack s = S;
    //遍历栈，逐一释放内存
    while(S != NULL)
    {
        //将元素从栈中孤立，然后回收内存
        s = S;
        S = S->next;
        free (s);
    }
}

//************************************
// Method:    traversal_Stack
// Parameter: Stack S
// Returns:   void
// Description: 遍历栈中元素
//************************************
void traversal_Stack (Stack S)
{
    S = S->next;  //移动指针到第一个元素
    while(S != NULL)   //开始遍历，逐一打印
    {
        printf ("%d\t", S->value);
        S = S->next;
    }
}
