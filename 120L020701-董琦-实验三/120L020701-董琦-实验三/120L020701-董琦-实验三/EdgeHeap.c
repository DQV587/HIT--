#include"EdgeHeap.h"
#include<stdlib.h>
#include<stdio.h>
Heap2 Initialize2(int MaxSize)
{
	Heap2 Tmp;
	Tmp = malloc(sizeof(struct Heap2Struct));
	if (Tmp == NULL)
	{
		printf("Out of space.");
		exit(1);
	}

	Tmp->Elements = (Heap2ElementType*)malloc((MaxSize + 1) * sizeof(Heap2ElementType));
	Tmp->Capacity = MaxSize;
	Tmp->Size = 0;
	Tmp->Elements[0] = NULL;

	return Tmp;
}
int IsEmptyH2(Heap2 H)
{
	return H->Size == 0;
}
int IsFullH2(Heap2 H)
{
	return H->Size == H->Capacity;
}
int Compare2(Heap2ElementType X, Heap2ElementType Y)
{
	if (X == NULL || Y == NULL)
		return 0;
	if (X->Value > Y->Value)
		return 1;
	else return 0;
}
void DisposeHeap2(Heap2 H)
{
	free(H->Elements);
	free(H);
}
void MakeEmpty2(Heap2 H)
{
	H->Size = 0;
}
void Insert2(Heap2ElementType X, Heap2 H)
{
	int i;
	if (IsFullH2(H))
	{
		printf("This Heap is full");
		return;
	}
	for (i = ++H->Size; Compare2(H->Elements[i / 2], X); i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}
Heap2ElementType DeleteMin2(Heap2 H)
{
	int i, Child;
	Heap2ElementType MinElement, LastElement;
	if (IsEmptyH2(H))
	{
		printf("This Heap is empty.");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;
		if ((Child != H->Size) && Compare2(H->Elements[Child], H->Elements[Child + 1]))
			Child++;
		if (Compare2(LastElement, H->Elements[Child]))
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}