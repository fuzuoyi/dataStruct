/*!
 * \file stack.h
 * \date 2017/09/24 14:34
 *
 * \author fuy
 *
 * \brief stack.h����������ʽջ�Ľṹ�Ͳ�������
 *
 */

/************************************************************************/
/*
/*  stack.h��stack.cpp�ļ�ʵ��������ṹ��ջ�ṹ����ͷ���
/*
/*��֧�ֵĲ�����
/*      push,pop,top����ջ�����У�
/*      ������ɾ��ջ
/*      �ж������Ƿ�Ϊ�պͻ�ȡ����Ԫ�ظ���
/*
/*  ջ�ṹ��
/*      �ڵ�:     head -> index1 -> index2 -> index3 -> ... -> indexn -> NULL
/*      value:    NULL    value1    value2    value3           valuen
/*
/*  ͷ��㣨head��value��Ϊ�գ���ʵ�����壬head�ڵ�Ϊջ��
/*  ͷ���Ĵ�����Ϊ�˷������������ǽڵ㣩������������
/*      ����ջ��Ԫ�ظ��������Ὣhead�ڵ����
/*      ��������ʱҲ���Ὣhead��value��ӡ����
/*
/*  ͷ���Ҳ������ͷָ����棨��ͷ�����ȣ�ֻ��nextָ�룬û��Ԫ�أ�
/*
/*  ************* !!! ������ͷ��㣬����ʱ����������� !!! *****************
/*
/************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//�������������ʾ��Ϣ
# define logError(x) printf(x)

//��ջ��־����pop��top����ʱ�����ջΪ���򷵻ظñ�־
#define EmptyStack -65534

// ջ�ṹ�������ͽṹ��ָ�����Ͷ���
struct Node;
typedef struct Node *pNode;
typedef pNode Stack;

// ջ�ڵ�ṹ�嶨��
// value���ڵ���ֵ
// next���ڵ�ָ�룬ָ����һ���ڵ�
struct Node
{
    int value;
    pNode next;
};

bool isEmpty (Stack S);          //�ж�ջ�Ƿ�Ϊ��
pNode makeEmpty (int value = 0); //��������ʼ��һ���½ڵ�

int getSize (Stack S);           //��ȡջ��Ԫ����Ŀ

void push (int value, Stack S);  //��һ����Ԫ��ѹ��ջ��
int pop (Stack S);               //��ջ��ȡ��һ��Ԫ��

int top (Stack S);               //�鿴ջ��Ԫ��

void clearStack (Stack S);       //���ջ(����ͷ���)

void traversal_Stack (Stack S);  //����ջ

#endif
