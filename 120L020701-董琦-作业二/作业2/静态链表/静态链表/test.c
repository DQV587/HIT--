#include <stdio.h>
#include <stdlib.h>
#include "StaList.h"

int main(void)
{
	StaticList L = CreateList();
	int i;
	for (i = 0; i < 10; i++)
		Insert(L, i);
	PrintList(L);
	Delete(L, 5);
	PrintList(L);
	Insert(L, 5);
	PrintList(L);
	ReverseList(L);
	PrintList(L);
	return 0;
}