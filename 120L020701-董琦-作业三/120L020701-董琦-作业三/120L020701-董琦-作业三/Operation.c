#include"Operation.h"
#include<stdio.h>
#include"BinTree.h"
void PreOrderRec(BinTree T)
{
	if (T != NULL)
	{
		Visit(T);
		PreOrderRec(T->Left);
		PreOrderRec(T->Right);
	}
}
void PreOrderNRec(BinTree T)
{
	Stack S = CreateStack();
	Position Tmp;
	if (T != NULL)
	{
		Push(T, S);
		while (!IsEmptyS(S))
		{
			Tmp = Pop(S);
			Visit(Tmp);
			if (Tmp->Right != NULL)
				Push(Tmp->Right, S);
			if (Tmp->Left != NULL)
				Push(Tmp->Left, S);
		}
	}
}
void MidOrderRec(BinTree T)
{
	if (T != NULL)
	{
		MidOrderRec(T->Left);
		Visit(T);
		MidOrderRec(T->Right);
	}
}
void MidOrderNRec(BinTree T)
{
	Stack S = CreateStack();
	Position Tmp;
	if (T != NULL)
	{
		Tmp = T;
		do {
			if (Tmp != NULL)
			{
				Push(Tmp, S);
				Tmp = Tmp->Left;
			}
			else
			{
				Tmp = Pop(S);
				Visit(Tmp);
				if (Tmp->Right != NULL)
					Tmp = Tmp->Right;
				else
					Tmp = NULL;
			}

		} while (!IsEmptyS(S)||Tmp!=NULL);
	}
	DisposeStack(S);
}
void PostOrderRec(BinTree T)
{
	if (T != NULL)
	{
		PostOrderRec(T->Left);
		PostOrderRec(T->Right);
		Visit(T);
	}
}
void PostOrderNRec(BinTree T)
{
	Position Tmp,Cur,Last=NULL;
	Stack S = CreateStack();
	Tmp = T;
	while (Tmp != NULL || !IsEmptyS(S))
	{
		if (Tmp != NULL)
		{
			Push(Tmp, S);
			Tmp = Tmp->Left;
		}
		else
		{
			Cur =Top(S);
			if ((Cur->Right != NULL) && (Cur->Right != Last))
				Tmp = Cur->Right;
			else
			{
				Visit(Cur);
				Pop(S);
				Last = Cur;
				Tmp = NULL;
			}
		}
	}
	DisposeStack(S);
}
void LayerOrder(BinTree T)
{
	Queue Q = CreateQueue(MAXSIZE);
	Position Tmp;
	if (T != NULL)
	{
		Tmp = T;
		Enqueue(T, Q);
		while(!IsEmptyQ(Q))
		{
			Tmp = Dequeue(Q);
			Visit(Tmp);
			if (Tmp->Left != NULL)
				Enqueue(Tmp->Left,Q);
			if (Tmp->Right != NULL)
				Enqueue(Tmp->Right,Q);
		}
	}
}
int IsFull(BinTree T)
{
	if (T->Left == NULL && T->Right == NULL)
		return 1;
	else if ((T->Left == NULL) ^ (T->Right == NULL))
		return 0;
	else
		return IsFull(T->Left) & IsFull(T->Right);
}
int Width(BinTree T)
{
	Queue Q = CreateQueue(100);
	int MaxWidth=0,i,width;
	Position Tmp;
	if (T != NULL)
	{
		MaxWidth = 1;
		Enqueue(T, Q);
	}
	while (!IsEmptyQ(Q))
	{
		width = Q->Size;
		MaxWidth = (MaxWidth > width) ? MaxWidth : width;
		for (i = 0; i < width; i++)
		{
			Tmp = Dequeue(Q);
			if (Tmp->Left != NULL)
				Enqueue(Tmp->Left, Q);
			if (Tmp->Right != NULL)
				Enqueue(Tmp->Right, Q);
		}
	}
	DisposeQueue(Q);
	return MaxWidth;
}