#include"Queue.h"
#include<stdlib.h>
#include<stdio.h>

int IsEmptyQ(Queue Q)
{
	return Q->Size == 0;
}
int IsFullQ(Queue Q)
{
	return Q->Size == Q->Capacity;
}
Queue CreateQueue(int Size)
{
	Queue Tmp = malloc(sizeof(struct QueueRecord));
	if (Tmp == NULL)
	{
		exit(3);
	}
	Tmp->Array = malloc(Size * sizeof(ElementType));
	if (Tmp->Array == NULL)
	{
		exit(4);
	}
	Tmp->Capacity = Size;
	Tmp->Rear = 0;
	Tmp->Front = 1;
	Tmp->Size = 0;
	return Tmp;
}
void DisposeQueue(Queue Q)
{
	free(Q->Array);
	free(Q);
}
void MakeEmptyQ(Queue Q)
{
	Q->Size = 0;
    Q->Rear = 0;
	Q->Front = 1;
}
int Succ(int Rear, Queue Q)
{
	if (++Rear == Q->Capacity)
		Rear = 0;
	return Rear;
}
void Enqueue(ElementTypeQ X, Queue Q)
{
	if (IsFullQ(Q))
	{
		printf("This Queue is full!");
		exit(1);
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}
ElementTypeQ Dequeue(Queue Q)
{
	ElementTypeQ Tmp;
	if (IsEmptyQ(Q))
	{
		printf("This Queue is empty!");
		exit(2);
	}
	else
	{
	    Tmp = Q->Array[Q->Front];
		Q->Size--;
		Q->Front=Succ(Q->Front,Q);
	}
	return Tmp;
}