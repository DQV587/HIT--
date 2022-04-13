#ifndef  ___EDGEHEAP___
#define  ___EDGEHEAP___
#include"Map.h"
struct Heap2Struct;
typedef struct Heap2Struct* Heap2;
#define Heap2ElementType Edge

Heap2 Initialize2(int MaxSize);
void DisposeHeap2(Heap2 H);
void MakeEmpty2(Heap2 H);
void Insert2(Heap2ElementType X, Heap2 H);
Heap2ElementType DeleteMin2(Heap2 H);
int IsEmptyH2(Heap2 H);
int IsFullH2(Heap2 H);
int Compare2(Heap2ElementType X, Heap2ElementType Y);

struct Heap2Struct
{
	int Capacity;
	int Size;
	Heap2ElementType* Elements;
};
#endif // ! ___EDGEHEAP___

