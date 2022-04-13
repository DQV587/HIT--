#ifndef ____QUEUE___
#define ____QUEUE___
#include"BinTree.h"
#define MAXSIZE 100
#define ElementTypeQ Position

struct QueueRecord;
typedef struct QueueRecord* Queue;
int IsEmptyQ(Queue Q);
int IsFullQ(Queue Q);
Queue CreateQueue(int Size);
void DisposeQueue(Queue Q);
void MakeEmptyQ(Queue Q);
void Enqueue(ElementTypeQ X, Queue Q);
ElementTypeQ Dequeue(Queue Q);
int Succ(int Rear, Queue Q);

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementTypeQ* Array;
};
#endif // !____QUEUE___

