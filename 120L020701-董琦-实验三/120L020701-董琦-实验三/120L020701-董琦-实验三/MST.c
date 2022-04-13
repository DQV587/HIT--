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
		//���¾���
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
		//ѡ�������С��
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
		//�л���ѡ�еĵ�
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
		//���¾���
		CurEdge = Previous->AdjEdge;
		while (CurEdge != NULL)
		{
			if ((CurEdge->Value < CurEdge->Another->Distant) && (CurEdge->Another->Known == 0))
			{
				CurEdge->Another->Distant = CurEdge->Value;
				CurEdge->Another->Previous = Previous;
				//�����
				Insert(CurEdge->Another, heap);
			}
			CurEdge = CurEdge->Next;
		}
		//ѡ�������С��
		Current = DeleteMin(heap);
		//�ҵ�����û�б����ʹ�����С��
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
		//���뷨�����ѣ�����������ͼ��ÿ���߲��������Σ��ʽ���ʱ�����
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
		//ѡ�����㲻��ͬһ�����ϵ���СȨֵ��
		//printf("%d->%d:%d\n", V1, V2,AdjEdge->Value);
		//�ϲ�������
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