#pragma once

// 散列表：分离连接法

#include <stdlib.h>
#include "../linkedList/linkedList.h"


typedef struct HashTbl * HashTable;

// 最小散列表尺寸
#define MinTableSize 7

// 散列表结构体
struct HashTbl
{
	int tableSize; // 表大小
	List *lists;  // 分离链表
};


char * intToChar(int key, int radix = 16);     // int转换为char*字符串

int Hash(const char *Key, int tableSize);	   // 计算散列值

HashTable InititalizeHashTable(int tableSize); // 初始化散列表

int search(HashTable H, int key);				// 搜索某个关键字（返回index或NotInList）

void insert(HashTable H, int key);				// 插入关键字
void remove(HashTable H, int key);				// 删除某个关键字

void deleteHashTable(HashTable &H);				// 删除散列表

void traversal_HashTable(HashTable H);			//遍历散列表












