/*!
 * \file arrayStack.h
 * \date 2017/09/24 17:04
 *
 * \author fuy
 *
 * \brief arrayStack.h��arrayStack.cppʵ��������ʽ��ջ�ṹ
 *
 */

 /************************************************************************/
 /*
 /*  arrayStack.h��arrayStack.cpp�ļ�ʵ��������ʽջ�ṹ
 /*
 /*��֧�ֵĲ�����
 /*      push,pop,top����ջ�����У�
 /*      ��������պ�ɾ��ջ
 /*      �ж�ջ�Ƿ�Ϊ�պͻ�ȡջԪ�ظ���
 /*
 /*  ����ṹ��
 /*      index:    -1        0         1         2      ...       n-1
 /*      value:    NULL    value1    value2    value3   ...      valuen
 /*
 /*  TopOfStackΪջ������ֵ��������ɾ��Ԫ��ʵ�ʶ��Ǹı�ջ������
 /*  
 /*  ����-1����ֵ�������ڣ��ɿ��������ͷ���
 /*
 /************************************************************************/


#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__


#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


//���������ʾ��Ϣ
#define logError(x) printf(x)

//��ջ�����������±�Ϊ-1
#define EmptyTopOfStack -1

//��ջ��־����������Ҫ������ջʱ�����ظ�ֵ
#define EmptyArrayStack -65534


//��������ջ�Ľṹ��ָ�붨��
struct StackRecord;
typedef StackRecord *arrayStack;


//��������ʽջ�Ľṹ��
struct StackRecord
{
    int capacity;  //ջ������
    int topOfStack;//ջ������ֵ�������±꣬��ջΪ-1��
    int *array;    //����ָ�룬ʹ��ǰ��Ҫ��ɳ�ʼ��
};

bool isEmpty (arrayStack S);  //�ж�ջ�Ƿ�Ϊ��
bool isFull (arrayStack S);   //�ж�ջ�Ƿ�����

int getSize (arrayStack S);   //��ȡջ��Ԫ�صĴ�С

arrayStack createStack (int cpacity); //����һ����ջ����ɽṹ��ĳ�ʼ��

void emptyStack (arrayStack S);      //���ջ��Ԫ�أ�ʵ���ǽ������±���Ϊ-1
void deleteStack (arrayStack S);     //ɾ��ջ��ջ���ڴ潫�����գ�ָ��ʧȥ����

bool push (int value, arrayStack S); //��һ���µ�Ԫ��ѹ��ջ�У����ջ���򷵻�false
int pop (arrayStack S);              //ȡ��ջ��Ԫ�أ����ջ���򷵻ؿ�ջ��־

int top (arrayStack S);              //�鿴ջ��Ԫ�أ����ջ���򷵻ؿ�ջ��־

void traversal_Stack (arrayStack S); //����ջ


#endif
