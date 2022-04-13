#include"Stack.h"
#include<stdlib.h>
#include<stdio.h>

int IsEmptyS(Stack S)
{
	return S->Next == NULL;
}
Stack CreateStack(void)
{
	Stack Tmp = malloc(sizeof(struct Node));
	if (Tmp == NULL)
	{
		printf("no space spared!");
		exit(1);
	}
	Tmp->Element = 0;
	Tmp->Next = NULL;
	return Tmp;
}
void DisposeStack(Stack S)
{
	while (!IsEmptyS(S))
	{
		Pop(S);
	}
	free(S);
}
void Push(ElementTypeS X,Stack S)
{
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		printf("Out of space!");
		exit(1);
	}
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
ElementTypeS Pop(Stack S)
{
	ElementTypeS Tmp;
	PtrToNode FirstNode;
	FirstNode = S->Next;
	Tmp = FirstNode->Element;
	S->Next = FirstNode->Next;
	free(FirstNode);
	return Tmp;
}
ElementTypeS Top(Stack S)
{
	if (!IsEmptyS(S))
		return S->Next->Element;
	else return 0;
}