#include"Tree.h"

Tree CreatTree()
{
	Tree Tmp = malloc(sizeof(struct  Node));
	if (Tmp == NULL)
		exit(2);
	Tmp->Element = 0;
	Tmp->Value = 0;
	Tmp->Parent=Tmp->Left = Tmp->Right = NULL;
	return Tmp;
}
Position CreatNode(char Element, int Value)
{
	Position Tmp = malloc(sizeof(struct  Node));
	if (Tmp == NULL)
		exit(2);
	Tmp->Element = Element;
	Tmp->Value = Value;
	Tmp->Parent=Tmp->Right = Tmp->Left = NULL;
	return Tmp;
}
int IsEmpty(Tree T)
{
	return T == NULL;
}
Tree Merge(Tree T1, Tree T2)
{
	Tree Tmp = CreatTree();
	Tmp->Value = T1->Value + T2->Value;
	if (T1->Value > T2->Value)
	{
		Tmp->Left = T1;
		Tmp->Right = T2;
	}
	else
	{
		Tmp->Left = T2;
		Tmp->Right = T1;
	}
	T1->Parent = T2->Parent = Tmp;
	return Tmp;
}
void DisposeTree(Tree T)
{
	if (T != NULL)
	{
		if (T->Left != NULL)
			DisposeTree(T->Left);
		if (T->Right != NULL)
			DisposeTree(T->Right);
		free(T);
	}
}