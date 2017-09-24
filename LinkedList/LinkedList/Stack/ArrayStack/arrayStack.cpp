/*!
 * \file arrayStack.cpp
 * \date 2017/09/24 17:20
 *
 * \author fuy
 *
 * \brief arrayStack.cpp ʵ��������ջ�Ĳ�������
 *
 */


#include "arrayStack.h"


//************************************
// Method:    isEmpty
// Parameter: arrayStack S
// Returns:   bool ��ջ����true,�ǿշ���false
// Description: �ж�ջ�Ƿ�Ϊ��
//************************************
bool isEmpty (arrayStack S)
{
    //�Ա�����ֵ���ɵó��Ƿ�Ϊ��ջ
    return S->topOfStack == EmptyTopOfStack;
}


//************************************
// Method:    isFull
// Parameter: arrayStack S
// Returns:   bool ��ջ����true,���򷵻�false
// Description: �ж�ջ�Ƿ�����
//************************************
bool isFull (arrayStack S)
{
    //�Ա�����ֵ���ɵó��Ƿ�Ϊ��ջ
    return S->topOfStack == S->capacity - 1;
}


//************************************
// Method:    getSize
// Parameter: arrayStack S
// Returns:   int
// Description: ����ջ��Ԫ����Ŀ
//************************************
int getSize (arrayStack S)
{
    //�ÿ�ջ����ֵ������ɵó�Ԫ����Ŀ
    return S->topOfStack - EmptyTopOfStack;
}


//************************************
// Method:    createStack
// Parameter: int capacity ��ջ��Ԫ������
// Returns:   arrayStack
// Description: ����һ���µ�ջ
//************************************
arrayStack createStack (int capacity)
{
    arrayStack S = (StackRecord*) malloc (sizeof (struct StackRecord));//����ṹ���ڴ�

    //�����Ƿ����뵽�ڴ�
    if(S == NULL)
        logError ("Out of space!!!");

    S->array = (int *) malloc (sizeof (int) * capacity); //���������ڴ�

    //�����Ƿ����뵽�ڴ�
    if(S->capacity == NULL)
        logError ("Out of space!!!");

    //��ɳ�ʼ����������������
    S->capacity = capacity;
    S->topOfStack = EmptyTopOfStack;

    return S;
}


//************************************
// Method:    emptyStack
// Parameter: arrayStack S
// Returns:   void
// Description: ���ջ��Ԫ��
//************************************
void emptyStack (arrayStack S)
{
    //ʵ���ǽ������±���Ϊ-1
    S->topOfStack = EmptyTopOfStack;
}


//************************************
// Method:    deleteStack
// Parameter: arrayStack S
// Returns:   void
// Description: ɾ��ջ���ͷ�ջռ�õ��ڴ�
//************************************
void deleteStack (arrayStack S)
{
    if(S != NULL)
    {
        //���ͷ������ڴ����ͷŽṹ���ڴ�,�ͷŶ�����˳��
        free (S->array);
        free (S);
    }
}


//************************************
// Method:    push
// Parameter: int value
// Parameter: arrayStack S
// Returns:   bool
// Description:����Ԫ��ѹ��ջ��
//************************************
bool push (int value, arrayStack S)
{
    if(isFull (S))   //�������ջ�������������ʾ��Ϣ������ʧ�ܲ���ֵ
    {
        logError ("Full Stack!!!");
        return false;
    }
    else            //ջû������Ԫ�ط���ջ��
    {
        // S->array[++S->topOfStack] = value;
        S->topOfStack++;                 //��ջ��������һ
        S->array[S->topOfStack] = value; //��Ԫ�ط���ջ��
        return true;
    }

}


//************************************
// Method:    pop
// Parameter: arrayStack S
// Returns:   int
// Description: ȡ��ջ��Ԫ��
//************************************
int pop (arrayStack S)
{
    if(!isEmpty (S))
    {
        int value = S->array[S->topOfStack]; //ȡ��Ԫ��
        S->topOfStack--;                     //�ı�����
        return value;
    }
    else
        return EmptyArrayStack;     //��ջ�򷵻ؿ�ջ��־
}


//************************************
// Method:    top
// Parameter: arrayStack S
// Returns:   int
// Description: �鿴ջ��Ԫ��
//************************************
int top (arrayStack S)
{
    if(!isEmpty (S))
        return S->array[S->topOfStack]; //�鿴ջ��Ԫ��
    else
        return EmptyArrayStack;         //��ջ�򷵻ؿ�ջ��־
}


//************************************
// Method:    traversal_Stack
// Parameter: arrayStack S
// Returns:   void
// Description: ����ջ����˳���ӡջ��Ԫ��
//************************************
void traversal_Stack (arrayStack S)
{
    int index = S->topOfStack;
    while(index > EmptyTopOfStack)
    {
        printf ("%d\t", S->array[index]);//��ӡԪ��
        index--;                         //�任����
    }
    printf ("\r\n");
}
