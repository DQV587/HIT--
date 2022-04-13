#include"MST.h"
#include<stdlib.h>
#include"DisjSet.h"
#include<stdio.h>
void Prim(Map Map)
{
	Vertex Previous, Current=NULL;
	Edge CurEdge;
	Previous = Map->Table[0];
	Previous->Distant = 0;
	Previous->Known = 1;
	Previous->Previous = NULL;
	int i,j;
	for (i = 1; i < Map->Size; i++)
	{
		//更新距离
		CurEdge = Previous->AdjEdge;
		while (CurEdge != NULL)
		{
			if ((CurEdge->Value < CurEdge->Another->Distant) && (CurEdge->Another->Known == 0))
			{
				CurEdge->Another->Distant = CurEdge->Value;
				CurEdge->Another->Previous = Previous;
			}
			CurEdge = CurEdge->Next;
		}
		//选择距离最小点
		for (j = 1; j < Map->Size; j++)
		{
			if (Map->Table[j]->Known == 0)
			{
				Current = Map->Table[j];
				break;
			}
		}
		for (;j < Map->Size; j++)
			if ((Map->Table[j]->Known == 0) && (Current->Distant > Map->Table[j]->Distant))
				Current = Map->Table[j];
		Current->Known = 1;
		//切换到选中的点
		Previous = Current;
	}
}
void PrimUseHeap(Map Map)
{
	Vertex Previous, Current = NULL;
	Edge CurEdge;
	Heap heap= Initialize(200);
	Previous = Map->Table[0];
	Previous->Distant = 0;
	Previous->Known = 1;
	Previous->Previous = NULL;
	int i;
	for (i = 1; i < Map->Size; i++)
	{
		//更新距离
		CurEdge = Previous->AdjEdge;
		while (CurEdge != NULL)
		{
			if ((CurEdge->Value < CurEdge->Another->Distant) && (CurEdge->Another->Known == 0))
			{
				CurEdge->Another->Distant = CurEdge->Value;
				CurEdge->Another->Previous = Previous;
				//插入堆
				Insert(CurEdge->Another, heap);
			}
			CurEdge = CurEdge->Next;
		}
		//选择距离最小点
		Current = DeleteMin(heap);
		//找到堆里没有被访问过的最小点
		while(Current->Known==1)
			Current = DeleteMin(heap);
		Current->Known = 1;
		Previous = Current;
	}
	DisposeHeap(heap);
}
void Kruskal(Map Map)
{
	int i;
	Edge AdjEdge;
	int V1, V2;
	Vertex CurVertex;
	Heap2 EdgeHeap = Initialize2(200);
	DisJSet Set = CreateDisJSet(Map->Size);
	for (i = 0; i < Map->Size; i++)
	{
		CurVertex = Map->Table[i];
		AdjEdge = CurVertex->AdjEdge;
		//插入法建立堆，由于是无向图，每个边插入了俩次，故建立时间较慢
		while (AdjEdge != NULL)
		{
			Insert2(AdjEdge, EdgeHeap);
			AdjEdge = AdjEdge->Next;
		}
	}
	for (i = 1; i < Map->Size; i++)
	{
		do
		{
			AdjEdge = DeleteMin2(EdgeHeap);
			V1 = AdjEdge->This->Name;
			V2 = AdjEdge->Another->Name;
		} while (Find(V1, Set) == Find(V2, Set));
		//选择俩点不在同一棵树上的最小权值边
		//printf("%d->%d:%d\n", V1, V2,AdjEdge->Value);
		//合并俩棵树
		Union(Set, Find(V1, Set), Find(V2, Set));
	}
	DisposeHeap2(EdgeHeap);
}
void ShowMST(Map map)
{
	int i;
	for (i = 0; i < map->Size; i++)
		if (map->Table[i]->Previous != NULL)
		{
			printf("%d->%d:%d\n",
				map->Table[i]->Previous->Name, map->Table[i]->Name, map->Table[i]->Distant);
		}
}