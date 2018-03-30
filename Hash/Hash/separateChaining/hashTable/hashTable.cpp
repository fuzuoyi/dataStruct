#include "hashTable.h"

char * intToChar(int key, int radix)
{
	// 将int转换为char数组

	static char itoaBuffer[10];     //缓冲buffer
	_itoa_s(key, itoaBuffer, radix); //用itoa实现，默认使用转换为16进制
	return itoaBuffer;
}



int Hash(const char *Key, int tableSize)
{
	// 散列函数，计算字符串的散列值

	unsigned int hashVal = 0;
	while (*Key != '\0')
	{
		hashVal = (hashVal << 5) + *Key++;
	}
	return hashVal % tableSize;

}


HashTable InititalizeHashTable(int tableSize)
{
	// 初始化散列表

	HashTable H;

	if (tableSize < MinTableSize)
	{
		logError("table size too small!!");
		return NULL;
	}

	// 申请散列表空间
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		logError("out of space!!!");

	// 初始化散列表（表大小，各个链表的头节点）
	H->tableSize = tableSize;
	H->lists = (List *)malloc(sizeof(struct Node) * H->tableSize);
	if (H->lists == NULL)
		logError("out of space!!!");

	for (int i = 0; i < H->tableSize; i++)
		H->lists[i] = makeEmpty();

	return H;
}

int search(HashTable H, int key)
{
	// 搜索某个关键字在散列表中的位置（子链表的index）

	// 转换为字符串 -> 计算hash -> 在对应的子链表中查找 -> 返回index（若不在，则返回NotInList）

	int hashVal = Hash(intToChar(key), H->tableSize);

	List L = H->lists[hashVal];

	int index = search(L, key);

	return index;
}

void insert(HashTable H, int key)
{
	// 在散列表中插入某个关键字

	// 先判断该关键字在不在散列表中，若已经存在，跳过，否则插入该元素

	//  转换为字符串 -> 计算hash -> 找到hash对应的子链表的头节点 -> 插入该关键字

	int index = search(H, key);

	if (index == NotInList)
	{
		int hashVal = Hash(intToChar(key), H->tableSize);

		List L = H->lists[hashVal];
		insert_head(L, key);
	}
}


void remove(HashTable H, int key)
{
	// 在散列表中删除某个关键字

	// 先判断该关键字在不在散列表中，若已经存在，跳过，否则删除该元素

	//  转换为字符串 -> 计算hash -> 找到hash对应的子链表 -> 删除该关键字

	int index = search(H, key);

	if (index != NotInList)
	{
		int hashVal = Hash(intToChar(key), H->tableSize);

		List L = H->lists[hashVal];

		deleteNode(L, index);
	}
}

void deleteHashTable(HashTable &H)
{
	// 删除散列表

	// 先删除所有的子链表，在删除散列表结构体，并将指针指向Null

	for (int i = 0; i < H->tableSize; i++)
		deleteList(H->lists[i]);

	free(H);

	H = NULL;
}


void traversal_HashTable(HashTable H)
{
	// 遍历散列表，（遍历各个子链表）

	printf("hash table size: %d \r\n", H->tableSize);

	for (int i = 0; i < H->tableSize; i++)
	{
		printf("H->lists[%d] :  ", i);
		traversal_List(H->lists[i]);
		printf("\r\n");
	}

}



