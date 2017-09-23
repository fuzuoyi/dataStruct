/*!
 * \file linkedList.h
 *
 * \author fuy
 * \date ���� 2017
 *
 * \brief linkedList.h�����˵�����Ľṹ�Ͳ�������
 */

/************************************************************************/
/*
/*  linkedList.h��linkedList.cpp�ļ�ʵ�ֵ�����Ϊ����������ͷ���
/*  
/*��֧�ֵĲ�����
/*      ����ȡֵ����ֵ�Լ�ɾֵ��
/*      �����ڵ�ͻ�ȡĳһ��������ֵ��
/*      ���������ɾ���������
/*      �ж������Ƿ�Ϊ�պͻ�ȡ����Ԫ�ظ���
/*      �����������Ľڵ�ָ��
/*    
/*  ����ṹ��
/*      index:    NULL      0         1         2               n-1
/*      �ڵ�:     head -> index1 -> index2 -> index3 -> ... -> indexn -> NULL        
/*      value:    NULL    value1    value2    value3           valuen   
/*
/*  ͷ��㣨head����index��value��Ϊ�գ���ʵ������
/*  ͷ���Ĵ�����Ϊ�˷������������ǽڵ㣩������������
/*      ��������Ԫ�ظ��������Ὣhead�ڵ���룻
/*      ɾ����������߲�ѯhead�Ȳ���ʵ��Ҳ��ָ����index=0��Ԫ�أ�������ͷ���
/*      ��������ʱҲ���Ὣhead��value��ӡ����
/*
/*  ͷ���Ҳ������ͷָ����棨��ͷ�����ȣ�ֻ��nextָ�룬û��Ԫ�أ�
/*  
/*  ***************** ������ͷ��㣬����ʱ����������� *********************
/*
/************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// ����ֻ��logError(x) �ͱ����������õ���printf()���������������ʾ��Ϣ
#define logError(x) printf(x)

// �ڲ�ѯ���߲���ڵ�Ȳ���ʱ��index����Խ�磬����Ҳ����Ϊ�գ����������������ʾԽ�������Ϊ��
#define NotInList -65534
#define OutOfRange -65533
#define EmptyList -65532

// ����ṹ�������ͽṹ��ָ�����Ͷ���
struct Node;
typedef struct Node *pNode;
typedef pNode List;

// ����ṹ�嶨��
// value���ڵ���ֵ
// next���ڵ�ָ�룬ָ����һ���ڵ�
struct Node
{
    int value;
    pNode next;
};


pNode makeEmpty (int value = 0); //�����½ڵ㣬��value��ʼ��
bool isEmpty (List L);           //�ж������Ƿ�Ϊ��   

int getSize (List L);            //��ȡ����Ԫ�ش�С

void insert_head (int Value, List L);       //������ͷ������Ԫ��
void insert_tail (int Value, List L);       //������β������Ԫ��
bool insert (int Value, int index, List L); //��index������Ԫ��

void delete_head (List L);           //ɾ��ͷ��Ԫ��
void delete_tail (List L);           //ɾ��β��Ԫ��
void deleteNode (int index, List L); //ɾ��index��Ԫ��
void deleteList (List L);            //�������(����ͷ���ڵ�)

int search (int Value, List L);      //����������ֵΪvalue��Ԫ�أ�������index��û���򷵻�NotInList������ж��ֵΪvalue��Ԫ�أ���ֻ���ص�һ��Ԫ�ص�����ֵ��

pNode getNode (int index, List L);   //����������index���Ľڵ�ָ��

int getHead (List L);                //����ͷ��Ԫ��
int getTail (List L);                //����β��Ԫ��
int getValve (int index, List L);    //����index����Ԫ��

void traversal_List (List L);        //��������
