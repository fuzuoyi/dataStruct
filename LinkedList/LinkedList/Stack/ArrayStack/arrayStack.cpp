/*!
 * \file arrayStack.cpp
 * \date 2017/09/24 17:20
 *
 * \author fuy
 *
 * \brief arrayStack.cpp 实现了数组栈的操作方法
 *
 */


#include "arrayStack.h"


//************************************
// Method:    isEmpty
// Parameter: arrayStack S
// Returns:   bool 空栈返回true,非空返回false
// Description: 判断栈是否为空
//************************************
bool isEmpty (arrayStack S)
{
    //对比索引值即可得出是否为空栈
    return S->topOfStack == EmptyTopOfStack;
}


//************************************
// Method:    isFull
// Parameter: arrayStack S
// Returns:   bool 满栈返回true,否则返回false
// Description: 判断栈是否已满
//************************************
bool isFull (arrayStack S)
{
    //对比索引值即可得出是否为满栈
    return S->topOfStack == S->capacity - 1;
}


//************************************
// Method:    getSize
// Parameter: arrayStack S
// Returns:   int
// Description: 返回栈中元素数目
//************************************
int getSize (arrayStack S)
{
    //用空栈索引值相减即可得出元素数目
    return S->topOfStack - EmptyTopOfStack;
}


//************************************
// Method:    createStack
// Parameter: int capacity 新栈的元素容量
// Returns:   arrayStack
// Description: 创建一个新的栈
//************************************
arrayStack createStack (int capacity)
{
    arrayStack S = (StackRecord*) malloc (sizeof (struct StackRecord));//申请结构体内存

    //检验是否申请到内存
    if(S == NULL)
        logError ("Out of space!!!");

    S->array = (int *) malloc (sizeof (int) * capacity); //申请数组内存

    //检验是否申请到内存
    if(S->capacity == NULL)
        logError ("Out of space!!!");

    //完成初始化索引和容量操作
    S->capacity = capacity;
    S->topOfStack = EmptyTopOfStack;

    return S;
}


//************************************
// Method:    emptyStack
// Parameter: arrayStack S
// Returns:   void
// Description: 清空栈中元素
//************************************
void emptyStack (arrayStack S)
{
    //实质是将索引下标置为-1
    S->topOfStack = EmptyTopOfStack;
}


//************************************
// Method:    deleteStack
// Parameter: arrayStack S
// Returns:   void
// Description: 删除栈，释放栈占用的内存
//************************************
void deleteStack (arrayStack S)
{
    if(S != NULL)
    {
        //先释放数组内存再释放结构体内存,释放二者有顺序
        free (S->array);
        free (S);
    }
}


//************************************
// Method:    push
// Parameter: int value
// Parameter: arrayStack S
// Returns:   bool
// Description:将新元素压入栈中
//************************************
bool push (int value, arrayStack S)
{
    if(isFull (S))   //如果是满栈，则输出错误提示信息，返回失败布尔值
    {
        logError ("Full Stack!!!");
        return false;
    }
    else            //栈没满，则将元素放入栈顶
    {
        // S->array[++S->topOfStack] = value;
        S->topOfStack++;                 //将栈顶索引加一
        S->array[S->topOfStack] = value; //将元素放入栈顶
        return true;
    }

}


//************************************
// Method:    pop
// Parameter: arrayStack S
// Returns:   int
// Description: 取出栈顶元素
//************************************
int pop (arrayStack S)
{
    if(!isEmpty (S))
    {
        int value = S->array[S->topOfStack]; //取出元素
        S->topOfStack--;                     //改变索引
        return value;
    }
    else
        return EmptyArrayStack;     //空栈则返回空栈标志
}


//************************************
// Method:    top
// Parameter: arrayStack S
// Returns:   int
// Description: 查看栈顶元素
//************************************
int top (arrayStack S)
{
    if(!isEmpty (S))
        return S->array[S->topOfStack]; //查看栈顶元素
    else
        return EmptyArrayStack;         //空栈则返回空栈标志
}


//************************************
// Method:    traversal_Stack
// Parameter: arrayStack S
// Returns:   void
// Description: 遍历栈，按顺序打印栈中元素
//************************************
void traversal_Stack (arrayStack S)
{
    int index = S->topOfStack;
    while(index > EmptyTopOfStack)
    {
        printf ("%d\t", S->array[index]);//打印元素
        index--;                         //变换索引
    }
    printf ("\r\n");
}
