/*!
 * \file linkedList.cpp
 *
 * \author fuy
 * \date 九月 2017
 *
 * \brief linkedList.cpp单链表的结构和操作方法的实现
 */


#include "linkedList.h"


//************************************
// Method:    makeEmpty
// Returns:   pNode
// Parameter: int value
// Description:创建并初始化一个节点，默认值为0，指针指向NULL
//************************************
pNode makeEmpty (int value)
{
    pNode p = (pNode) malloc (sizeof (struct Node));//申请节点内存
    if(p == NULL)
        logError ("Out of Space!!!!");
    //初始化节点元素和指针
    p->next = NULL;
    p->value = value;
    return p;
}


//************************************
// Method:    isEmpty
// Returns:   bool
// Parameter: List L
// Description: 判断链表L是否为空
//************************************
bool isEmpty (List L)
{
    return L->next == NULL;//链表第一个节点为头结点，元素在头结点后
}


//************************************
// Method:    getSize
// Returns:   int
// Parameter: List L
// Description: 获取链表中元素的个数（不包含头结点）
//************************************
int getSize (List L)
{
    int size = 0;
    L = L->next;      //将指针从头结点移动到第一个元素
    while(L != NULL)  //遍历链表，记录节点个数
    {
        size++;
        L = L->next;
    }
    return size;
}


//************************************
// Method:    insert_head
// Returns:   void
// Parameter: int Value
// Parameter: List L
// Description: 在链表头部插入节点
//************************************
void insert_head (int Value, List L)
{
    pNode temp = makeEmpty (Value); //创建并初始化插入的节点
    temp->next = L->next;  //新节点指针指向第二个元素（可能为空，但不影响）
    L->next = temp;        //头部指针指向新节点
}


//************************************
// Method:    insert_tail
// Parameter: int Value
// Parameter: List L
// Description: 在链表尾部插入节点
//************************************
void insert_tail (int Value, List L)
{
    pNode temp = makeEmpty (Value);

    while(L->next != NULL) //遍历链表，直到指针节点为尾部元素（指针指向NULL）
    {
        L = L->next;
    }
    L->next = temp;        //完成插入操作
}


//************************************
// Method:    insert
// Parameter: int Value
// Parameter: int index
// Parameter: List L
// Return:    bool
// Description: 在index处插入节点，插入后该节点的索引值为index
//************************************
bool insert (int Value, int index, List L)
{
    //判断索引值是否合法（上界:size；下界:0）
    //如果越界，打印错误提示信息，返回false，否则插入新节点并返回true
    if(getSize (L) < index || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!\r\n");
        return false;
    }

    pNode temp = makeEmpty (Value);//创建并初始化新节点

    //将指针移动到index节点的前一个节点
    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }

    //变换节点指针，完成插入操作
    temp->next = L->next;
    L->next = temp;

    return true;
}


//************************************
// Method:    delete_head
// Parameter: List L
// Description: 删除第一个节点
//************************************
void delete_head (List L)
{
    if(L->next == NULL)//如果链表为空，则没有元素可删除，直接返回
        return;

    //变换指针指向，将第一个节点隔离开来
    pNode temp = L->next;
    L->next = L->next->next;

    free (temp);//删除第一个元素节点
}


//************************************
// Method:    delete_tail
// Parameter: List L
// Description: 删除尾部节点（也可以用deleteNode(size-1,L)完成）
//************************************
void delete_tail (List L)
{
    if(L->next == NULL)//如果链表为空，则没有元素可删除，直接返回
        return;

    //获取链表元素个数和创建遍历指针
    int size = getSize (L);

    //将遍历指针移动到尾部元素的前一个节点
    for(int i = 1; i < size; i++)
    {
        L = L->next;
    }

    //尾部元素是链表最后一个元素，可直接free，然后将前一元素指针指向NULL
    free (L->next);
    L->next = NULL;
}


//************************************
// Method:    deleteNode
// Parameter: int index
// Parameter: List L
// Description: 删除索引为index的节点
//************************************
void deleteNode (int index, List L)
{
    if(isEmpty (L))//如果链表为空，则没有元素可删除，直接返回
        return;

    //判断索引值是否合法（上界:size-1；下界:0）
    //如果索引值越界，打印错误提示信息，直接返回
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!\r\n");
        return;
    }

    //将指针指向index节点的前一个节点
    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }

    //完成指针变换，free节点
    pNode temp = L->next->next;
    free (L->next);
    L->next = temp;
}


//************************************
// Method:    deleteList
// Parameter: List L
// Returns:   void
// Description: 删除链表中所有元素(包括头结点)，清空后链表指针失效
//************************************
void deleteList (List L)
{
    List l = L;
    while(L != NULL)
    {
        l = L;
        L = L->next;
        free (l);
    }
}


//************************************
// Method:    getNode
// Parameter: int index
// Parameter: List L
// Returns:   pNode
// Description: 获取index处的节点指针
//************************************
pNode getNode (int index, List L)
{
    if(isEmpty (L))//如果链表为空，则没有元素可获取，直接返回NULL
        return NULL;

    //判断索引值是否合法（上界:size-1；下界:0）
    //如果索引值越界，打印错误提示信息，直接返回
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!\r\n");
        return NULL;
    }

    //将指针移动到index处
    for(int i = -1; i < index; i++)
    {
        L = L->next;
    }

    return L;
}

//************************************
// Method:    search
// Parameter: int Value
// Parameter: List L
// Returns:   int
// Description: 搜索链表是否有某一元素，如果链表有多个值为value的元素，则只返回第一个的索引
//              如果没有该元素，返回NotInList
//************************************
int search (int Value, List L)
{
    //创建索引值和遍历指针
    int index = 0;
    L = L->next;

    while(L != NULL)          //遍历链表
    {
        if(L->value == Value) //逐一对比元素，若节点值与搜索值相同，直接返回索引
        {
            return index;
        }
        L = L->next;
        index++;
    }

    return NotInList;
}


//************************************
// Method:    getValve
// Parameter: int index
// Parameter: List L
// Returns:   int
// Description: 获取链表中索引为index处的元素值
//************************************
int getValve (int index, List L)
{
    if(isEmpty (L))//如果链表为空，则没有元素可获取，直接返回EmptyList
        return EmptyList;

    //判断索引值是否合法（上界:size-1；下界:0）
    //如果索引值越界，打印错误提示信息，直接返回OutOfRange
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!\r\n");
        return OutOfRange;
    }

    //将指针移动到目标索引处
    L = L->next;
    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }

    return L->value;
}


//************************************
// Method:    getHead
// Parameter: List L
// Returns:   int
// Description: 获取链表第一个元素
//************************************
int getHead (List L)
{
    if(isEmpty (L))//如果链表为空，则没有元素可获取，直接返回EmptyList
        return EmptyList;
    return L->next->value;
}


//************************************
// Method:    getTail
// Parameter: List L
// Returns:   int
// Description: 获取链表尾部元素
//************************************
int getTail (List L)
{
    //直接调用getValve()函数获取
    return getValve (getSize (L) - 1, L);
}

//************************************
// Method:    traversal_List
// Parameter: List L
// Returns:   void
// Description:
//************************************
void traversal_List (List L)
{
    L = L->next;  //移动指针到第一个元素
    while(L != NULL)   //开始遍历，逐一打印
    {
        printf ("%d\t", L->value);
        L = L->next;
    }
}
