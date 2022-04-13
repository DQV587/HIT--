#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"
int main()
{
	List L = CreatList();
	ElementType i;
	for (i = 0; i < 10; i++)
		Insert(10 - i, L);
	PrintList(L);
	Reverse(L);
	PrintList(L);
	Reverse(L);
	for (i = 0; i < 10; i++)
		Insert(10 - i, L);
	PrintList(L);
	Delete(8, L);
	PrintList(L);
	DeleteRep(L);
	PrintList(L);
	Delete(9, L);
	PrintList(L);
	List L2 = CreatList();
	for (i = 0; i < 10; i++)
		Insert(10 + i, L2);
	PrintList(L2);
	L = Merge(L, L2);
	PrintList(L);
	Move(L, -3);
	PrintList(L);
	return 0;
}