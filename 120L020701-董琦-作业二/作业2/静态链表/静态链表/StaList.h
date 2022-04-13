#ifndef ___STALIST__
#define ___STALIST__

#define DefaultValue 0
#define MaxSize 20
typedef int ElementType;
typedef int Position;
typedef int size;
typedef struct
{
	ElementType Element;
	Position Next;
} Node;
typedef Node* PtrToNode;
typedef Node* StaticList;

StaticList CreateList(void);
Position MallocNode(StaticList L);
void Insert(StaticList L, ElementType X);
void Delete(StaticList L, ElementType X);
int IsEmpty(StaticList L);
int IsFull(StaticList L);
Position Find(StaticList L, ElementType X);
Position FindPrevious(StaticList L, ElementType X);
void DeleteList(StaticList L);
void MakeEmpty(StaticList L);
void PrintList(StaticList L);
void ReverseList(StaticList L);




#endif 
