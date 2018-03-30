#include <stdio.h>
#include <stdlib.h>
#include "linkedList/linkedList.h"
#include "hashTable/hashTable.h"



int main()
{
	HashTable H = InititalizeHashTable(7);

	insert(H, 10);
	insert(H, 1235);
	insert(H, 6845);
	insert(H, 41);
	insert(H, 89);


	insert(H, 101);
	insert(H, 12365);
	insert(H, 68456);
	insert(H, 417);
	insert(H, 894);

	remove(H, 417);

	search(H, 101);
	search(H, 1);


	traversal_HashTable(H);

	deleteHashTable(H);

	system("pause");
	return 0;
}


