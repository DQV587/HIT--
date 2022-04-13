#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
seqlist CreateSList(Size size) {
	seqlist temp=(seqlist)malloc(sizeof(struct Seqlist));
	if (!temp)
	{
		printf("no spaces spared!");
		exit(0);
	}
	temp->head = (int*)malloc(size * sizeof(ElementType));
	if (!temp->head)
	{
		printf("out of space!");
		exit(0);
	}
	temp->length = 0;
	temp->size = size;
	return temp;
}
//我们插入时就把他排好序哈，便于后续操作，从小到大哈
void InsertS(seqlist L, ElementType a)
{
	if (L->length == L->size)
	{
		printf("this list is full!");
		exit(0);
	}
	else {
	
		if (L->length == 0)
		{
			L->head[0] = a;
			L->length++;
		}
		else {
			ElementType tmp1, tmp2=0;
			int i;
			for (i = 0; i < L->length && L->head[i] < a; i++)
				;
			//到达队尾
			if (i == (L->length))
			{
				L->head[i] = a;
				L->length++;
			}
			//未到达，插入
			else {
				tmp1 = L->head[i];
				L->head[i] = a;
				if ((++i) == L->length)
				{
					L->head[i] = tmp1;
					L->length++;
				}
				else
				{
					for (; i < L->length; i++)
					{
						tmp2 = L->head[i];
						L->head[i] = tmp1;
						tmp1 = tmp2;
					}
					L->head[i] = tmp1;
					L->length++;
				}
			}
		}
	}
}
void DeleteByValue(seqlist L, ElementType a)
{
	int i = 0;
	for (; i < L->length && L->head[i] < a; i++)
		;
	//没有该元素
	if (i == L->length||L->head[i]>a)
		;
	else 
	{
		L->length--;
		for (; i < L->length; i++)
			L->head[i] = L->head[i + 1];
		DeleteByValue(L, a);
	}
}
void DeleteByPosition(seqlist L, Position P)
{
	Position i = P;
	L->length--;
	for (; i < L->length; i++)
	{
		L->head[i] = L->head[i + 1];
	}
}
void DeleteRepS(seqlist L)
{
	int i;
	for (i = 0; i < L->length-1; i++)
		if (L->head[i] == L->head[i + 1])
			DeleteByPosition(L, i+1);
}
void ReverseS(seqlist L)
{
	int i;
	ElementType tmp;
	for (i = 0; i < L->length / 2; i++)
	{
		tmp = L->head[i];
		L->head[i] = L->head[L->length - 1 - i];
		L->head[L->length - 1 - i] = tmp;
	}
}
seqlist MergeS(seqlist A, seqlist B)
{
	seqlist tmp;
	tmp = CreateSList(A->size + B->size);
	int i;
	for (i = 0; i < A->length; i++)
		InsertS(tmp, A->head[i]);
	for (i = 0; i < B->length; i++)
		InsertS(tmp, B->head[i]);
	return tmp;
}
void MoveS(seqlist L, int k)
{
	int i,j;
	ElementType tmp;
	while (k < 0)
		k += L->length;
	ElementType* Tmp = (ElementType*)malloc(k * sizeof(ElementType));
	if (!Tmp)
	{
		printf("no space spared!");
		exit(0);
	}
	for (i = 0; i < L->length; i++)
	{
		if (i < k)
			Tmp[i] = L->head[i];
		j = i + k;
		if (j >= L->length)
			j = j % L->length;
		else if(j<0)
			while(j<0)
				j += L->length;
		if (j >= k)
			L->head[i] = L->head[j];
		else
			L->head[i] = Tmp[j];
	}
}
void PrintS(seqlist L)
{
	int i;
	for (i = 0; i < L->length; i++)
		printf("%d\t", L->head[i]);
	printf("\n");
}
void ClearS(seqlist L)
{
	L->length = 0;
}
void DeleteList(seqlist L)
{
	ClearS(L);
	free(L->head);
	free(L);
}
