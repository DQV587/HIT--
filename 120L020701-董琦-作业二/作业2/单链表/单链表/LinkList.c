#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
//我这个链表是有表头的链表，第一个节点不保存元素
List CreatList()
{
	List Tmp = (List)malloc(sizeof(struct Node));
	if (!Tmp)
	{
		printf("The space is full!");
		exit(0);
	}
	Tmp->Element = 0;
	Tmp->Next = NULL;
	return Tmp;
}
Position CreatNode(ElementType X)
{
	Position Tmp= (Position)malloc(sizeof(struct Node));
	if (!Tmp)
	{
		printf("The space is full!");
		exit(0);
	}
	Tmp->Element = X;
	Tmp->Next = NULL;
	return Tmp;
}
int IsEmpty(List L)
{
	return L->Next == NULL;
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P!=NULL && P->Element != X)
		P = P->Next;
	return P;
}
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element < X)
		P = P->Next;
	return P;
}
void Delete(ElementType X, List L)
{
	Position P, Tmp;
	P = FindPrevious(X, L);
	if (!IsLast(P, L)&&P->Next->Element==X)
	{
		Tmp = P->Next;
		P->Next = Tmp->Next;
		free(Tmp);
		L->Element--;
		Delete(X, L);
	}
}
void DeleteRep(List L)
{
	Position P1, P2;
	P1 = L->Next;
	P2 = P1->Next;
	while (P2!=NULL)
	{
		if (P1->Element == P2->Element)
		{
			P1->Next = P2->Next;
			free(P2);
			P2 = NULL;
			P2 = P1->Next;
			L->Element--;
		}
		else
		{
			P1 = P2;
			P2 = P1->Next;
		}
	}
}
List MakeEmpty(List L)
{
	Position P, Tmp;
	P = L->Next;
	while (P!=NULL)
	{
		Tmp = P;
		P = Tmp->Next;
		free(Tmp);
	}
	L->Element = 0;
	L->Next = NULL;
	return L;
}
//插入时就排好序，便于后面操作
void Insert(ElementType X, List L)
{
	Position Tmp = CreatNode(X);
	Position P;
	L->Element++;
	if (IsEmpty(L))
		L->Next = Tmp;
	else
	{
		P = L;
		while (P->Next!=NULL&&P->Next->Element < X)
			P = P->Next;
		if (IsLast(P, L))
			P->Next = Tmp;
		else
		{
			Tmp->Next = P->Next;
			P->Next = Tmp;
		}
	}
}
void DeleteList(List L)
{
	MakeEmpty(L);
	free(L);
}
void Reverse(List L)
{
	Position P1, P2;
	P1 = L->Next;
	if (P1!=NULL)
	{
		P2 = P1->Next;
		P1->Next = NULL;
		while (P2 != NULL)
		{
			P1 = P2;
			P2 = P2->Next;
			P1->Next = L->Next;
			L->Next = P1;
		}
	}
}
List Merge(List L1, List L2)
{
	List L = CreatList();
	L->Next = (L1->Element > L2->Element) ? L1->Next : L2->Next;
	Position P1, P2,Tmp;
	P1= (L1->Element <= L2->Element) ? L1->Next : L2->Next;
	while (P1 != NULL)
	{
		P2 = P1->Next;
		Tmp = FindPrevious(P1->Element, L);
		P1->Next = Tmp->Next;
		Tmp->Next = P1;
		P1 = P2;
	}
	L->Element = L1->Element + L2->Element;
	free(L1);
	free(L2);
	
	return L;
}
void Move(List L, int k)
{
	int i = L->Element-(L->Element + k) % L->Element;
	int j;
	Position P=L;
	Position Tmp=L->Next;
	for (j = 0; j < i; j++)
		P = P->Next;
	L->Next = P->Next;
	P->Next = NULL;
	P = L->Next;
	while (P->Next != NULL)
		P = P->Next;
	P->Next = Tmp;
}
void PrintList(List L)
{
	Position P;
	P = L->Next;
	while (P != NULL)
	{
		printf("%d\t", P->Element);
		P = P->Next;
	}
	printf("\n");
}