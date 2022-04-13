#include"AdjacencyMatrix.h"
#include"AdjacencyTable.h"
#include<stdlib.h>
MapTable ConvertMatrixToTable(MapMatrix Map);
MapMatrix ConvertTableToMatrix(MapTable Map);
int main()
{
	MapTable Map = ScanMapToTab(InputFileName);
	printf("BFSbyTab:\n");
	BFSbyTab(Map, 1);
	printf("\n");
	printf("DFSbyTab:\n");
	DFSbyTab(Map, 1);
	printf("\n");
	MapMatrix Map2 = ScanMapToMatrix(InputFileName);
	printf("BFSbyMtx:\n");
	BFSbyMtx(Map2, 1);
	printf("\n");
	printf("DFSbyMtx:\n");
	DFSbyMtx(Map2, 1);
	printf("\n");
	Map = ConvertMatrixToTable(Map2);
	printf("DFSbyTabRec:\n");
	DFSbyTabRec(Map, 1);
	printf("\n");
	Map2 = ConvertTableToMatrix(Map);
	printf("DFSbyMtxRec:\n");
	DFSbyMtxRec(Map2, 1);
	int* OutDegree = CountOutDegreeByTab(Map);
	int i = Map->N;
	int j = 0;
	printf("\n");
	for (; j < i; j++)
	{
		printf("%d\t", OutDegree[j]);
	}
	printf("\n");
	int* InDegree = CountInDegreeByTab(Map);
	for (j = 0; j < i; j++)
	{
		printf("%d\t", InDegree[j]);
	}
	printf("\n");
	int* Degree = CountDegreeByTab(Map);
	for (j = 0; j < i; j++)
	{
		printf("%d\t", Degree[j]);
	}
	printf("\n");
	return 0;
}
MapTable ConvertMatrixToTable(MapMatrix Map)
{
	MapTable TmpTable = malloc(sizeof(struct TableStruct));
	if ((TmpTable->Table = malloc(Map->N * sizeof(PtrToMapNode))) == NULL)
		exit(1);
	TmpTable->N = Map->N;
	int i, j;
	AdjNode TmpCell;
	AdjacencyTable Tmp = NULL;
	Tmp = TmpTable->Table;
	for (i = 0; i < Map->N; i++)
	{
		if ((Tmp[i] = malloc(sizeof(struct NodeStruct))) == NULL)
			exit(1);
		Tmp[i]->Distant = Tmp[i]->Serial = Tmp[i]->Visited = 0;
		Tmp[i]->Name = i + 1;
		Tmp[i]->Next = NULL;
	}
	for (i = 0; i < Map->N; i++)
		for (j = 0; j < Map->N; j++)
			if (Map->Matrix[i * Map->N + j] == 1)
			{
				if ((TmpCell = malloc(sizeof(struct NodeStruct))) != NULL)
				{
					TmpCell->Name = j + 1;
					TmpCell->Next = NULL;
				}
				TmpCell->Next = Tmp[i]->Next;
				Tmp[i]->Next = TmpCell;
			}
	return TmpTable;
}
MapMatrix ConvertTableToMatrix(MapTable Map)
{
	MapMatrix TmpMap;
	AdjacencyTable Table;
	AdjNode Adj;
	int i, j;
	if ((TmpMap = malloc(sizeof(struct MatrixStruct))) == NULL)
		exit(1);
	TmpMap->N = Map->N;
	if ((TmpMap->Matrix = malloc(Map->N * Map->N * sizeof(int))) == NULL)
		exit(1);
	memset(TmpMap->Matrix, 0, sizeof(int) * Map->N * Map->N);
	for (i = 0; i < Map->N; i++)
		TmpMap->Matrix[i * Map->N + i] = -1;
	Table = Map->Table;
	for (i = 0; i < Map->N; i++)
	{
		Adj = Table[i]->Next;
		while (Adj != NULL)
		{
			j = Adj->Name - 1;
			TmpMap->Matrix[i * Map->N + j] = 1;
			Adj = Adj->Next;
		}
	}
	return TmpMap;
}