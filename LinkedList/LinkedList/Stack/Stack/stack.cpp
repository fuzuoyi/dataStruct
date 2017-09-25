/*!
 * \file stack.cpp
 * \date 2017/09/24 14:48
 *
 * \author fuy
 *
 * \brief stack.cppʵ��������ʽջ�Ľṹ�Ͳ�������
 *
 */


#include "stack.h"


//************************************
// Method:    isEmpty
// Parameter: Stack S
// Returns:   bool
// Description: �ж�ջ�Ƿ�Ϊ��
//************************************
bool isEmpty (Stack S)
{
    return S->next == NULL;
}


//************************************
// Method:    makeEmpty
// Parameter: int value
// Returns:   pNode
// Description: ��������ʼ��һ���µ�ջ�ڵ�
//************************************
pNode makeEmpty (int value)
{
    pNode p = (pNode) malloc (sizeof (struct Node));//����ڵ��ڴ�
    if(p == NULL)
    {
        logError ("Out of Space!!!");
    }
    //��ʼ���ڵ�Ԫ�غ�ָ��
    p->next = NULL;
    p->value = value;
    return p;
}


//************************************
// Method:    getSize
// Parameter: Stack S
// Returns:   int
// Description: ��ȡջ��Ԫ�ظ���
//************************************
int getSize (Stack S)
{
    int size = 0;
    S = S->next;     //�����к���ͷ���
    while(S != NULL) //����ջ����¼�ڵ����
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
// Description: ��һ����Ԫ�ؽڵ�ѹ��ջ��
//************************************
void push (int value, Stack S)
{
    //�����½ڵ�
    pNode p = makeEmpty (value);

    //���ָ��任
    p->next = S->next;
    S->next = p;
}
//************************************
// Method:    pop
// Parameter: Stack S
// Returns:   int
// Description: ��ջ��ȡ��һ��Ԫ��
//************************************
int pop (Stack S)
{
    //ֻ��ջ�ǿյ������²������ȡ������
    if(!isEmpty (S))
    {
        //�任ָ�룬��ջ��Ԫ�ش�ջ�й�������
        pNode p = S->next;
        S->next = S->next->next;

        int value = p->value; //ȡֵ
        free (p); //�ͷ�ջ���ڴ�
        return value;
    }

    //���Ϊ��ջ�����ؿ�ջ��־
    return EmptyStack;
}


//************************************
// Method:    top
// Parameter: Stack S
// Returns:   int
// Description: �鿴ջ��Ԫ�أ���ȡ��Ԫ�أ�
//************************************
int top (Stack S)
{
    //ֻ��ջ�ǿյ������²�����ɲ鿴����
    if(!isEmpty (S))
    {
        return  S->next->value;
    }

    //���Ϊ��ջ�����ؿ�ջ��־
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
// Description: ���ջ������Ԫ�أ�����ͷ��㣩����պ�ջָ��ʧЧ
//************************************
void deleteStack (Stack S)
{
    Stack s = S;
    //����ջ����һ�ͷ��ڴ�
    while(S != NULL)
    {
        //��Ԫ�ش�ջ�й�����Ȼ������ڴ�
        s = S;
        S = S->next;
        free (s);
    }
}

//************************************
// Method:    traversal_Stack
// Parameter: Stack S
// Returns:   void
// Description: ����ջ��Ԫ��
//************************************
void traversal_Stack (Stack S)
{
    S = S->next;  //�ƶ�ָ�뵽��һ��Ԫ��
    while(S != NULL)   //��ʼ��������һ��ӡ
    {
        printf ("%d\t", S->value);
        S = S->next;
    }
}
