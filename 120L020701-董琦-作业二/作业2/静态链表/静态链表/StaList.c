#include <stdio.h>
#include <stdlib.h>
#include "StaList.h"

StaticList CreateList(void)
{
	StaticList Tmp = (StaticList)malloc(MaxSize * sizeof(Node));
	if (Tmp == NULL)
	{
		printf("out of space!");
		exit(1);
	}
	else
	{
		int i;
		for (i = 1; i < MaxSize-1; i++)
		{
			Tmp[i].Next = i + 1;
		}
		Tmp[0].Next = -1;
		Tmp[MaxSize - 1].Next = 0;
		return Tmp;
	}
}
Position MallocNode(StaticList L)
{
	int i = L[1].Next;
	if (i != 0)
	{
		L[1].Next = L[i].Next;
		return i;
	}
	else
	{
		printf("the list is full!");
		exit(2);
	}
}
void Insert(StaticList L, ElementType X)
{
	Position i = MallocNode(L);
	L[i].Element = X;
	L[i].Next = L[0].Next;
	L[0].Next = i;
}
int IsEmpty(StaticList L)
{
	return L[0].Next == -1;
}
int IsFull(StaticList L)
{
	return L[1].Next == 0;
}
void MakeEmpty(StaticList L)
{
	int i;
	for (i = 1; i < MaxSize - 1; i++)
	{
		L[i].Next = i + 1;
	}
	L[0].Next = -1;
	L[MaxSize - 1].Next = 0;
}
void DeleteList(StaticList L)
{
	free(L);
}
Position Find(StaticList L, ElementType X)
{
	Position i=L[0].Next;
	while (L[i].Element != X&&i!=-1)
		i = L[i].Next;
	return i;
}
Position FindPrevious(StaticList L, ElementType X)
{
	Position i = 0;
	while (L[L[i].Next].Element != X&&L[i].Next!=-1)
		i = L[i].Next;
	return i;
}
void Delete(StaticList L, ElementType X)
{
	Position i,j;
	i = FindPrevious(L, X);
	j = L[i].Next;
	if(j != -1)
	{
		L[i].Next = L[j].Next;
		L[j].Next = L[1].Next;
		L[1].Next = j;
		Delete(L, X);
	}
}
void PrintList(StaticList L)
{
	Position i=L[0].Next;
	while (i != -1)
	{
		printf("%d\t", L[i].Element);
		i = L[i].Next;
	}
	printf("\n");
}
void ReverseList(StaticList L)
{
	Position i, j;
	i = L[0].Next;
	j = L[i].Next;
	while (j != -1)
	{
		L[i].Next = L[j].Next;
		L[j].Next = L[0].Next;
		L[0].Next = j;
		j = L[i].Next;
	}
}