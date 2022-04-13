#include"List.h"

int IsEmptyL(List L)
{
	return L->Next == NULL;
}
List CreatList(void)
{
	List Tmp = malloc(sizeof(struct ListNode));
	if (Tmp == NULL)
		exit(1);
	Tmp->Element = Tmp->HuffumanCode = Tmp->Next = NULL;
	return Tmp;
}
void InsertList(ListElementType X, List L)
{
	List Tmp = malloc(sizeof(struct ListNode));
	if (Tmp == NULL)
		exit(1);
	Tmp->Element = X;
	Tmp->HuffumanCode = NULL;
	Tmp->Next = L->Next; 
	L->Next = Tmp;
}
void DisposeList(List L)
{
	if (L != NULL)
	{
		if (L->Next != NULL)
			DisposeList(L->Next);
		free(L);
	}
}