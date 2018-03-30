#pragma once

// ɢ�б��������ӷ�

#include <stdlib.h>
#include "../linkedList/linkedList.h"


typedef struct HashTbl * HashTable;

// ��Сɢ�б�ߴ�
#define MinTableSize 7

// ɢ�б�ṹ��
struct HashTbl
{
	int tableSize; // ���С
	List *lists;  // ��������
};


char * intToChar(int key, int radix = 16);     // intת��Ϊchar*�ַ���

int Hash(const char *Key, int tableSize);	   // ����ɢ��ֵ

HashTable InititalizeHashTable(int tableSize); // ��ʼ��ɢ�б�

int search(HashTable H, int key);				// ����ĳ���ؼ��֣�����index��NotInList��

void insert(HashTable H, int key);				// ����ؼ���
void remove(HashTable H, int key);				// ɾ��ĳ���ؼ���

void deleteHashTable(HashTable &H);				// ɾ��ɢ�б�

void traversal_HashTable(HashTable H);			//����ɢ�б�












