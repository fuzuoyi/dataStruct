/*!
 * \file linkedList.cpp
 *
 * \author fuy
 * \date ���� 2017
 *
 * \brief linkedList.cpp������Ľṹ�Ͳ���������ʵ��
 */


#include "linkedList.h"


//************************************
// Method:    makeEmpty
// Returns:   pNode
// Parameter: int value
// Description:��������ʼ��һ���ڵ㣬Ĭ��ֵΪ0��ָ��ָ��NULL
//************************************
pNode makeEmpty (int value)
{
    pNode p = (pNode) malloc (sizeof (struct Node));//����ڵ��ڴ�
    if(p == NULL)
        logError ("Out of Space!!!!");
    //��ʼ���ڵ�Ԫ�غ�ָ��
    p->next = NULL;
    p->value = value;
    return p;
}


//************************************
// Method:    isEmpty
// Returns:   bool
// Parameter: List L
// Description: �ж�����L�Ƿ�Ϊ��
//************************************
bool isEmpty (List L)
{
    return L->next == NULL;//�����һ���ڵ�Ϊͷ��㣬Ԫ����ͷ����
}


//************************************
// Method:    getSize
// Returns:   int
// Parameter: List L
// Description: ��ȡ������Ԫ�صĸ�����������ͷ��㣩
//************************************
int getSize (List L)
{
    int size = 0;
    L = L->next;      //��ָ���ͷ����ƶ�����һ��Ԫ��
    while(L != NULL)  //����������¼�ڵ����
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
// Description: ������ͷ������ڵ�
//************************************
void insert_head (int Value, List L)
{
    pNode temp = makeEmpty (Value); //��������ʼ������Ľڵ�
    temp->next = L->next;  //�½ڵ�ָ��ָ��ڶ���Ԫ�أ�����Ϊ�գ�����Ӱ�죩
    L->next = temp;        //ͷ��ָ��ָ���½ڵ�
}


//************************************
// Method:    insert_tail
// Parameter: int Value
// Parameter: List L
// Description: ������β������ڵ�
//************************************
void insert_tail (int Value, List L)
{
    pNode temp = makeEmpty (Value);

    while(L->next != NULL) //��������ֱ��ָ��ڵ�Ϊβ��Ԫ�أ�ָ��ָ��NULL��
    {
        L = L->next;
    }
    L->next = temp;        //��ɲ������
}


//************************************
// Method:    insert
// Parameter: int Value
// Parameter: int index
// Parameter: List L
// Return:    bool
// Description: ��index������ڵ㣬�����ýڵ������ֵΪindex
//************************************
bool insert (int Value, int index, List L)
{
    //�ж�����ֵ�Ƿ�Ϸ����Ͻ�:size���½�:0��
    //���Խ�磬��ӡ������ʾ��Ϣ������false����������½ڵ㲢����true
    if(getSize (L) < index || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!\r\n");
        return false;
    }

    pNode temp = makeEmpty (Value);//��������ʼ���½ڵ�

    //��ָ���ƶ���index�ڵ��ǰһ���ڵ�
    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }

    //�任�ڵ�ָ�룬��ɲ������
    temp->next = L->next;
    L->next = temp;

    return true;
}


//************************************
// Method:    delete_head
// Parameter: List L
// Description: ɾ����һ���ڵ�
//************************************
void delete_head (List L)
{
    if(L->next == NULL)//�������Ϊ�գ���û��Ԫ�ؿ�ɾ����ֱ�ӷ���
        return;

    //�任ָ��ָ�򣬽���һ���ڵ���뿪��
    pNode temp = L->next;
    L->next = L->next->next;

    free (temp);//ɾ����һ��Ԫ�ؽڵ�
}


//************************************
// Method:    delete_tail
// Parameter: List L
// Description: ɾ��β���ڵ㣨Ҳ������deleteNode(size-1,L)��ɣ�
//************************************
void delete_tail (List L)
{
    if(L->next == NULL)//�������Ϊ�գ���û��Ԫ�ؿ�ɾ����ֱ�ӷ���
        return;

    //��ȡ����Ԫ�ظ����ʹ�������ָ��
    int size = getSize (L);

    //������ָ���ƶ���β��Ԫ�ص�ǰһ���ڵ�
    for(int i = 1; i < size; i++)
    {
        L = L->next;
    }

    //β��Ԫ�����������һ��Ԫ�أ���ֱ��free��Ȼ��ǰһԪ��ָ��ָ��NULL
    free (L->next);
    L->next = NULL;
}


//************************************
// Method:    deleteNode
// Parameter: int index
// Parameter: List L
// Description: ɾ������Ϊindex�Ľڵ�
//************************************
void deleteNode (int index, List L)
{
    if(isEmpty (L))//�������Ϊ�գ���û��Ԫ�ؿ�ɾ����ֱ�ӷ���
        return;

    //�ж�����ֵ�Ƿ�Ϸ����Ͻ�:size-1���½�:0��
    //�������ֵԽ�磬��ӡ������ʾ��Ϣ��ֱ�ӷ���
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Insert Error: Insert index is lower than zero or larger than size of ist!!!\r\n");
        return;
    }

    //��ָ��ָ��index�ڵ��ǰһ���ڵ�
    for(int i = 0; i < index; i++)
    {
        L = L->next;
    }

    //���ָ��任��free�ڵ�
    pNode temp = L->next->next;
    free (L->next);
    L->next = temp;
}


//************************************
// Method:    deleteList
// Parameter: List L
// Returns:   void
// Description: ɾ������������Ԫ��(����ͷ���)����պ�����ָ��ʧЧ
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
// Description: ��ȡindex���Ľڵ�ָ��
//************************************
pNode getNode (int index, List L)
{
    if(isEmpty (L))//�������Ϊ�գ���û��Ԫ�ؿɻ�ȡ��ֱ�ӷ���NULL
        return NULL;

    //�ж�����ֵ�Ƿ�Ϸ����Ͻ�:size-1���½�:0��
    //�������ֵԽ�磬��ӡ������ʾ��Ϣ��ֱ�ӷ���
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!\r\n");
        return NULL;
    }

    //��ָ���ƶ���index��
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
// Description: ���������Ƿ���ĳһԪ�أ���������ж��ֵΪvalue��Ԫ�أ���ֻ���ص�һ��������
//              ���û�и�Ԫ�أ�����NotInList
//************************************
int search (int Value, List L)
{
    //��������ֵ�ͱ���ָ��
    int index = 0;
    L = L->next;

    while(L != NULL)          //��������
    {
        if(L->value == Value) //��һ�Ա�Ԫ�أ����ڵ�ֵ������ֵ��ͬ��ֱ�ӷ�������
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
// Description: ��ȡ����������Ϊindex����Ԫ��ֵ
//************************************
int getValve (int index, List L)
{
    if(isEmpty (L))//�������Ϊ�գ���û��Ԫ�ؿɻ�ȡ��ֱ�ӷ���EmptyList
        return EmptyList;

    //�ж�����ֵ�Ƿ�Ϸ����Ͻ�:size-1���½�:0��
    //�������ֵԽ�磬��ӡ������ʾ��Ϣ��ֱ�ӷ���OutOfRange
    if(index > getSize (L) - 1 || index < 0)
    {
        logError ("Index Error: Index is lower than zero or larger than (size-1) of ist!!!\r\n");
        return OutOfRange;
    }

    //��ָ���ƶ���Ŀ��������
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
// Description: ��ȡ�����һ��Ԫ��
//************************************
int getHead (List L)
{
    if(isEmpty (L))//�������Ϊ�գ���û��Ԫ�ؿɻ�ȡ��ֱ�ӷ���EmptyList
        return EmptyList;
    return L->next->value;
}


//************************************
// Method:    getTail
// Parameter: List L
// Returns:   int
// Description: ��ȡ����β��Ԫ��
//************************************
int getTail (List L)
{
    //ֱ�ӵ���getValve()������ȡ
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
    L = L->next;  //�ƶ�ָ�뵽��һ��Ԫ��
    while(L != NULL)   //��ʼ��������һ��ӡ
    {
        printf ("%d\t", L->value);
        L = L->next;
    }
}
