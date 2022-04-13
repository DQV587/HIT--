#ifndef  ___HEAP___
#define  ___HEAP___
#include"Map.h"
struct HeapStruct;
typedef struct HeapStruct* Heap;
#define ElementType Vertex

Heap Initialize(int MaxSize);
void DisposeHeap(Heap H);
void MakeEmpty(Heap H);
void Insert(ElementType X, Heap H);
ElementType DeleteMin(Heap H);
int IsEmptyH(Heap H);
int IsFullH(Heap H);
int Compare(ElementType X, ElementType Y);

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType* Elements;
};
#endif // ! ___HEAP___

