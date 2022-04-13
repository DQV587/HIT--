#ifndef __LINKLIST__
#define __LINKLIST__

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;


List CreatList();
Position CreatNode(ElementType X);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L);
void DeleteList(List L);

void DeleteRep(List L);
void Reverse(List L);
List Merge(List L1, List L2);
void Move(List L, int k);
void PrintList(List L);

struct Node
{
	ElementType Element;
	Position Next;
};
#endif
