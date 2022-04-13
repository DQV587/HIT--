#include"Heap.h"
#include<stdlib.h>
#include<stdio.h>
Heap Initialize(int MaxSize)
{
	Heap Tmp;
	Tmp = malloc(sizeof(struct HeapStruct));
	if (Tmp == NULL)
	{
		printf("Out of space.");
		exit(1);
	}

	Tmp->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
	Tmp->Capacity = MaxSize;
	Tmp->Size = 0;
	Tmp->Elements[0] = NULL;

	return Tmp;
}
int IsEmptyH(Heap H)
{
	return H->Size == 0;
}
int IsFullH(Heap H)
{
	return H->Size == H->Capacity;
}
int Compare(ElementType X, ElementType Y)
{
	if (X == NULL || Y == NULL)
		return 0;
	if (X->Distant > Y->Distant)
		return 1;
	else return 0;
}
void DisposeHeap(Heap H)
{
	free(H->Elements);
	free(H);
}
void MakeEmpty(Heap H)
{
	H->Size = 0;
}
void Insert(ElementType X, Heap H)
{
	int i;
	if (IsFullH(H))
	{
		printf("This Heap is full");
		return;
	}
	for (i = ++H->Size; Compare(H->Elements[i / 2], X); i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}
ElementType DeleteMin(Heap H)
{
	int i, Child;
	ElementType MinElement,LastElement;
	if (IsEmptyH(H))
	{
		printf("This Heap is empty.");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;
		if ((Child != H->Size) && Compare(H->Elements[Child], H->Elements[Child + 1]))
			Child++;
		if (Compare(LastElement, H->Elements[Child]))
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}