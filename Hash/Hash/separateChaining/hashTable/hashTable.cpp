#include "hashTable.h"

char * intToChar(int key, int radix)
{
	// ��intת��Ϊchar����

	static char itoaBuffer[10];     //����buffer
	_itoa_s(key, itoaBuffer, radix); //��itoaʵ�֣�Ĭ��ʹ��ת��Ϊ16����
	return itoaBuffer;
}



int Hash(const char *Key, int tableSize)
{
	// ɢ�к����������ַ�����ɢ��ֵ

	unsigned int hashVal = 0;
	while (*Key != '\0')
	{
		hashVal = (hashVal << 5) + *Key++;
	}
	return hashVal % tableSize;

}


HashTable InititalizeHashTable(int tableSize)
{
	// ��ʼ��ɢ�б�

	HashTable H;

	if (tableSize < MinTableSize)
	{
		logError("table size too small!!");
		return NULL;
	}

	// ����ɢ�б�ռ�
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		logError("out of space!!!");

	// ��ʼ��ɢ�б����С�����������ͷ�ڵ㣩
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
	// ����ĳ���ؼ�����ɢ�б��е�λ�ã��������index��

	// ת��Ϊ�ַ��� -> ����hash -> �ڶ�Ӧ���������в��� -> ����index�������ڣ��򷵻�NotInList��

	int hashVal = Hash(intToChar(key), H->tableSize);

	List L = H->lists[hashVal];

	int index = search(L, key);

	return index;
}

void insert(HashTable H, int key)
{
	// ��ɢ�б��в���ĳ���ؼ���

	// ���жϸùؼ����ڲ���ɢ�б��У����Ѿ����ڣ���������������Ԫ��

	//  ת��Ϊ�ַ��� -> ����hash -> �ҵ�hash��Ӧ���������ͷ�ڵ� -> ����ùؼ���

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
	// ��ɢ�б���ɾ��ĳ���ؼ���

	// ���жϸùؼ����ڲ���ɢ�б��У����Ѿ����ڣ�����������ɾ����Ԫ��

	//  ת��Ϊ�ַ��� -> ����hash -> �ҵ�hash��Ӧ�������� -> ɾ���ùؼ���

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
	// ɾ��ɢ�б�

	// ��ɾ�����е���������ɾ��ɢ�б�ṹ�壬����ָ��ָ��Null

	for (int i = 0; i < H->tableSize; i++)
		deleteList(H->lists[i]);

	free(H);

	H = NULL;
}


void traversal_HashTable(HashTable H)
{
	// ����ɢ�б�����������������

	printf("hash table size: %d \r\n", H->tableSize);

	for (int i = 0; i < H->tableSize; i++)
	{
		printf("H->lists[%d] :  ", i);
		traversal_List(H->lists[i]);
		printf("\r\n");
	}

}



