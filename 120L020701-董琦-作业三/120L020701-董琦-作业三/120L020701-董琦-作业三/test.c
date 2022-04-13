#include "BinTree.h"
#include"Queue.h"
#include"Operation.h"
#include"Stack.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	BinTree T = NULL;
	int i;
	T=Insert(4, T);
	T=Insert(2, T);
	T=Insert(6, T);
	T=Insert(1, T);
	T=Insert(3, T);
	T=Insert(5, T);
	T=Insert(7, T);
	PreOrderRec(T);
	printf("\n");
	PreOrderNRec(T);
	printf("\n");
	MidOrderRec(T);
	printf("\n");
	MidOrderNRec(T);
	printf("\n");
	PostOrderRec(T);
	printf("\n");
	PostOrderNRec(T);
	printf("\n");
	LayerOrder(T);
	printf("\n");
	if (IsFull(T))
		printf("This tree is full.\n");
	i = Width(T);
	printf("%d\n", i);
	T = Delete(7, T);
	printf("%d\n", Width(T));
	if (IsFull(T))
		printf("This tree is full.\n");
	else
		printf("This tree is not full.\n");
	T = Insert(8, T);
	if (IsFull(T))
		printf("This tree is full.\n");
	printf("\n");
	return 0;
}