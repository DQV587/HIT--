#define _CRT_SECURE_NO_WARNINGS
#include"AdjacencyTable.h"
#include"Queue.h"
#include"Stack.h"
#include<stdlib.h>
#include <stdio.h>
#include<string.h>

int CurSerial;
MapTable ScanMapToTab(char* FileName)
{
	FILE* fp;
	if ((fp = fopen(FileName,"r")) == NULL)
	{
		printf("open file failed.");
		exit(2);
	}
	MapTable TmpTable = malloc(sizeof(struct TableStruct));
	AdjacencyTable Tmp = NULL;
	AdjNode TmpCell;
	int CurChar, Count,i,j,Front,Rear;
	char TmpName[5];
	if ((TmpTable->Table = malloc(MAXNODE*sizeof(PtrToMapNode))) == NULL)
		exit(1);
	Tmp = TmpTable->Table;
	for (i = MAXNODE; i > 0; i--)
	{
		Tmp[20 - i] = malloc(sizeof(struct NodeStruct));
		Tmp[20 - i]->Distant = Tmp[20 - i]->Name = Tmp[20 - i]->Serial = Tmp[20 - i]->Visited = 0;
		Tmp[20 - i]->Next = NULL;
	}
	Count = 0;
	CurChar = fgetc(fp);
    do
	{
		j = 0;
		while (CurChar != ',')
		{
			TmpName[j++] = CurChar;
			CurChar = fgetc(fp);
		}
		TmpName[j] = '\0';
		Front = atoi(TmpName);
		if (Count < Front) Count = Front;
		Tmp[Front - 1]->Name = Front;

		j = 0;
		CurChar = fgetc(fp);
		while (CurChar != 32&&CurChar!=EOF)
		{
			TmpName[j++] = CurChar;
			CurChar = fgetc(fp);
		}
		TmpName[j] = '\0';
		Rear = atoi(TmpName);
		if (Count < Rear) Count = Rear;
		Tmp[Rear-1]->Name = Rear;

		if ((TmpCell = malloc(sizeof(struct NodeStruct))) != NULL)
		{
			TmpCell->Name = Rear;
			TmpCell->Next = NULL;
		}
		TmpCell->Next = Tmp[Front - 1]->Next;
		Tmp[Front - 1]->Next = TmpCell;

		while ((CurChar = fgetc(fp)) == ' ' || CurChar == '\r' || CurChar == '\n') ;
	} while (CurChar != EOF);
	fclose(fp);
	Tmp=realloc(Tmp,Count * sizeof(struct NodeStruct));
	TmpTable->N = Count;
	TmpTable->Table = Tmp;
	if (Tmp != NULL)
		return TmpTable;
	else exit(1);
}
void Visit1(Node N)
{
	printf("Name:%d\t", N->Name);
	printf("Serial:%d\t", N->Serial);
	printf("Distant:%d\n", N->Distant);
}
void BFSbyTab(MapTable Map,int k)
{
	Queue NodeQueue = CreateQueue(MAXNODE);
	Node  AdjNode;
	int CurNode;
	int i = 0,n;
	AdjacencyTable Table = Map->Table;
	CurNode = Table[k-1]->Name;
	int Distant=0;
	CurSerial = 0;
	Enqueue(CurNode, NodeQueue);
	while (!IsEmptyQ(NodeQueue))
	{
		for (n = NodeQueue->Size;n > 0; n--)
		{
			CurNode = Dequeue(NodeQueue);
			if (Table[CurNode - 1]->Visited != 1)
			{
				Table[CurNode - 1]->Visited = 1;
				Table[CurNode - 1]->Serial = CurSerial++;
				Table[CurNode - 1]->Distant = Distant;
				Visit1(Table[CurNode - 1]);
				AdjNode = Table[CurNode - 1]->Next;
				while (AdjNode != NULL)
				{
					if (!(Table[AdjNode->Name - 1]->Visited))
						Enqueue(Table[AdjNode->Name - 1]->Name, NodeQueue);
					AdjNode = AdjNode->Next;
				}
			}
		}
		Distant++;
		if (IsEmptyQ(NodeQueue))
		{
			for(;i<Map->N;i++)
				if (Table[i]->Visited == 0)
				{
					Distant = 0;
					Enqueue(Table[i]->Name, NodeQueue);
					break;
				}
		}
	}
	Refresh1(Map);
}
void DFSbyTab(MapTable Map, int k)
{
	Stack NodeStack = CreateStack();
	Node  AdjNode;
	int CurNode;
	int i = 0;
	AdjacencyTable Table = Map->Table;
	CurNode = Table[k - 1]->Name;
	CurSerial = 0;
	Push(CurNode, NodeStack);
	while (!IsEmptyS(NodeStack))
	{
		CurNode = Pop(NodeStack);
		if (Table[CurNode - 1]->Visited != 1)
		{
			Table[CurNode - 1]->Visited = 1;
			Table[CurNode - 1]->Serial = CurSerial++;
			Visit1(Table[CurNode - 1]);
			AdjNode = Table[CurNode - 1]->Next;
			while (AdjNode != NULL)
			{
				if (!(Table[AdjNode->Name - 1]->Visited))
				{
					Push(Table[AdjNode->Name - 1]->Name, NodeStack);
					Table[AdjNode->Name - 1]->Distant = Table[CurNode - 1]->Distant + 1;
				}
				AdjNode = AdjNode->Next;
			}
		}
		if (IsEmptyS(NodeStack))
		{
			for (; i < Map->N; i++)
				if (Table[i]->Visited == 0)
				{
					Push(Table[i]->Name, NodeStack);
					break;
				}
		}
	}
	Refresh1(Map);
}
void DFSbyTabRec(MapTable Map, int k)
{
	CurSerial = 0;
	Map->Table[k - 1]->Visited = 1;
	DFS1(Map, Map->Table[k - 1]);
	Refresh1(Map);
}
void DFS1(MapTable Map,Node N)
{
	N->Serial = CurSerial++;
	Visit1(N);
	AdjNode Adj=Map->Table[N->Name-1]->Next;
	while (Adj != NULL)
	{
		if (Map->Table[Adj->Name - 1]->Visited == 0)
		{
			Map->Table[Adj->Name - 1]->Distant = Map->Table[N->Name - 1]->Distant + 1;
			Map->Table[Adj->Name - 1]->Visited = 1;
			DFS1(Map, Map->Table[Adj->Name - 1]);
		}
		Adj = Adj->Next;
	}
}
int* CountOutDegreeByTab(MapTable Map)
{
	int i,j,count;
	Node AdjNode,CurNode;
	AdjacencyTable Table = Map->Table;
	i = Map->N;
	int* OutDegree = (int*)malloc(i * sizeof(int));
	if (OutDegree == NULL)
		exit(1);
	memset(OutDegree, 0, 4 * i);
	for (j = 0; j < i; j++)
	{
		count = 0;
		CurNode = Table[j];
		AdjNode = CurNode->Next;
		while (AdjNode != NULL)
		{
			count++;
			AdjNode = AdjNode->Next;
		}
		OutDegree[j] = count;
	}
	return OutDegree;
}
int* CountInDegreeByTab(MapTable Map)
{
	int i, j;
	i = Map->N;
	Node AdjNode, CurNode;
	AdjacencyTable Table = Map->Table;
	int* InDegree=(int*)malloc(i * sizeof(int));
	if(InDegree==NULL)
		exit(1);
	memset(InDegree, 0, 4 * i);
	for (j = 0; j < i; j++)
	{
		CurNode = Table[j];
		AdjNode = CurNode->Next;
		while (AdjNode != NULL)
		{
			InDegree[AdjNode->Name-1]++;
			AdjNode = AdjNode->Next;
		}
	}
	return InDegree;
}
int* CountDegreeByTab(MapTable Map)
{
	int* InDegree = CountInDegreeByTab(Map);
	int* OutDegree = CountOutDegreeByTab(Map);
	int i = Map->N,j;
	int* Degree = (int*)malloc(i * sizeof(int));
	if (Degree == NULL)
		exit(1);
	for (j = 0; j < i; j++)
		Degree[j] = InDegree[j] + OutDegree[j];
	return Degree;
}
void Refresh1(MapTable Map)
{
	int i;
	AdjacencyTable Tmp = Map->Table;
	for(i=0;i<Map->N;i++)
		Tmp[i]->Distant =  Tmp[i]->Serial = Tmp[i]->Visited = 0;
}

