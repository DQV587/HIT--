#ifndef ____STACK____
#define ____STACK____
#include"BinTree.h"

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
#define ElementTypeS Position

int IsEmptyS(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void Push(ElementTypeS X,Stack S);
ElementTypeS Pop(Stack S);
ElementTypeS Top(Stack S);

struct Node
{
	ElementTypeS Element;
	PtrToNode Next;
};
#endif
