#ifndef ____LIST___
#define ____LIST___

#include"Tree.h"
#include<stdlib.h>

typedef  Position ListElementType;
struct ListNode;
typedef struct ListNode* List;

int IsEmptyL(List L);
List CreatList(void);
void InsertList(ListElementType X, List L);  
void DisposeList(List L);

struct ListNode
{
	ListElementType Element;
	char* HuffumanCode;
	List Next;
};
#endif // !____LIST___

