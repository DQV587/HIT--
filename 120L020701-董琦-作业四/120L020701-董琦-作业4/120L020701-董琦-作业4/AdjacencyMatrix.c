#include"AdjacencyMatrix.h"
#include"Queue.h"
#include"Stack.h"
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
int CurSerial;
MapMatrix ScanMapToMatrix(char* FileName)
{
	MapMatrix TmpMap = malloc(sizeof(struct MatrixStruct));
	if (TmpMap == NULL)
		exit(1);
	FILE* fp;
	if ((fp = fopen(FileName, "r")) == NULL)
	{
		printf("open file failed.");
		exit(2);
	}
	int CurChar, Count=0, i, j, Front, Rear;
	char TmpName[5];
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
		j = 0;
		CurChar = fgetc(fp);
		while (CurChar != 32 && CurChar != EOF)
		{
			TmpName[j++] = CurChar;
			CurChar = fgetc(fp);
		}
		TmpName[j] = '\0';
		Rear = atoi(TmpName);
		if (Count < Rear) Count = Rear;
		while ((CurChar = fgetc(fp)) == ' ' || CurChar == '\r' || CurChar == '\n');
	} while (CurChar != EOF);

	TmpMap->N = Count;

	if((TmpMap->Matrix = malloc(Count * Count * sizeof(int)))==NULL)
		exit(1);
	memset(TmpMap->Matrix, 0, sizeof(int) * Count * Count);
	for (i = 0; i < Count; i++)
		TmpMap->Matrix[i * Count + i] = -1;
	fseek(fp, 0, SEEK_SET);
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
		j = 0;
		CurChar = fgetc(fp);
		while (CurChar != 32 && CurChar != EOF)
		{
			TmpName[j++] = CurChar;
			CurChar = fgetc(fp);
		}
		TmpName[j] = '\0';
		Rear = atoi(TmpName);
		TmpMap->Matrix[(Front-1)*Count+(Rear-1)] = 1;
		while ((CurChar = fgetc(fp)) == ' ' || CurChar == '\r' || CurChar == '\n');
	} while (CurChar != EOF);
	fclose(fp);
	return TmpMap;
}
void BFSbyMtx(MapMatrix Map, int k)
{
	int CurNode,Distant=0,i,n;
	CurSerial = 0;
	Queue NodeQueue = CreateQueue(MAXNODE);
	Enqueue(k, NodeQueue);
	while (!IsEmptyQ(NodeQueue))
	{
		for (n = NodeQueue->Size; n > 0; n--)
		{
			CurNode = Dequeue(NodeQueue);
			if (Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1] == -1)
			{
				Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1] = Distant;
				printf("Name:%d\t", CurNode);
				printf("Serial:%d\t", CurSerial++);
				printf("Distant:%d\n", Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1]);
				for (i = 0; i < Map->N; i++)
				{
					if (i != CurNode - 1 && Map->Matrix[(CurNode - 1) * Map->N + i] == 1 && Map->Matrix[i * Map->N + i] == -1)
						Enqueue(i + 1, NodeQueue);
				}
			}
		}
		Distant++;
		if (IsEmptyQ(NodeQueue))
		{
			for (i = 0; i < Map->N; i++)
				if (Map->Matrix[i * Map->N + i] == -1)
				{
					Distant = 0;
					Enqueue(i + 1, NodeQueue);
					break;
				}
		}
	}
	Refresh2(Map);
}
void DFSbyMtx(MapMatrix Map, int k)
{
	int CurNode, Distant = 0, i, n;
	CurSerial = 0;
	Stack NodeStack = CreateStack();
	Push(k, NodeStack);
	while (!IsEmptyS(NodeStack))
	{
		CurNode = Pop(NodeStack);
		if (Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1] == -1)
		{
			Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1] = 0;
		}
		printf("Name:%d\t", CurNode);
		printf("Serial:%d\t", CurSerial++);
		printf("Distant:%d\n", Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1]);
		for (i = 0; i < Map->N; i++)
		{
			if (Map->Matrix[(CurNode - 1) * Map->N + i] == 1 && Map->Matrix[i * Map->N + i] == -1)
			{
				Push(i+1,NodeStack);
				Map->Matrix[i * Map->N + i] = Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1] + 1;
			}
		}
		if (IsEmptyS(NodeStack))
			for (i = 0; i < Map->N; i++)
				if (Map->Matrix[i * Map->N + i] == -1)
					Push(i + 1, NodeStack);
	}
	Refresh2(Map);
}
void DFSbyMtxRec(MapMatrix Map, int k)
{
	CurSerial = 0;
	Map->Matrix[(k - 1) * Map->N + k - 1] = 0;
	DFS2(Map, k);
	Refresh2(Map);
}
void DFS2(MapMatrix Map, int k)
{
	int CurNode = k,i;
	printf("Name:%d\t", CurNode);
	printf("Serial:%d\t", CurSerial++);
	printf("Distant:%d\n", Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1]);
	for (i = 0; i < Map->N; i++)
	{
		if (Map->Matrix[(CurNode - 1) * Map->N + i] == 1 && Map->Matrix[i * Map->N + i] == -1)
		{
			Map->Matrix[i * Map->N + i] = Map->Matrix[(CurNode - 1) * Map->N + CurNode - 1] + 1;
			DFS2(Map, i + 1);
		}
	}
}
void Refresh2(MapMatrix Map)
{
	int i;
	for (i = 0; i < Map->N; i++)
		Map->Matrix[i * Map->N + i] = -1;
}
