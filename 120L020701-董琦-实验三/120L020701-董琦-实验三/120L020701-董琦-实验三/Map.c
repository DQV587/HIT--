#define _CRT_SECURE_NO_WARNINGS
#include"Map.h"
#include<stdlib.h>
#include<stdio.h>

Map ScanMap(char* FileName)//从文件中读取点和边
{
	FILE* fp;
	if ((fp = fopen(FileName, "r")) == NULL)
	{
		printf("open file failed.");
		exit(2);
	}
	Map TmpTable = malloc(sizeof(struct TableStruct));
	Vertex* Tmp = NULL;
	Edge TmpEdge;
	int CurChar, Count, i, j, V1, V2,Value;
	char TmpName[5];
	if ((TmpTable->Table = malloc(MaxNode * sizeof(Vertex))) == NULL)
		exit(1);
	Tmp = TmpTable->Table;
	for (i = MaxNode; i > 0; i--)
	{
		if((Tmp[MaxNode - i] = malloc(sizeof(struct VertexStruct)))==NULL)
			exit(1);
		Tmp[MaxNode - i]->Known = 0;
		Tmp[MaxNode - i]->Distant = 10000;
		Tmp[MaxNode - i]->Name = MaxNode - i + 1;
		Tmp[MaxNode - i]->AdjEdge = NULL;
		Tmp[MaxNode - i]->Previous = NULL;
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
		V1 = atoi(TmpName);
		if (Count < V1) Count = V1;

		j = 0;
		CurChar = fgetc(fp);
		while (CurChar != ',')
		{
			TmpName[j++] = CurChar;
			CurChar = fgetc(fp);
		}
		TmpName[j] = '\0';
		V2 = atoi(TmpName);
		if (Count < V2) Count = V2;

		j = 0;
		CurChar = fgetc(fp);
		while (CurChar != 32 && CurChar != EOF)
		{
			TmpName[j++] = CurChar;
			CurChar = fgetc(fp);
		}
		TmpName[j] = '\0';
		Value = atoi(TmpName);

		if ((TmpEdge = malloc(sizeof(struct EdgeStruct))) != NULL)
		{
			TmpEdge->Another = Tmp[V2-1];
			TmpEdge->Value = Value;
			TmpEdge->This = Tmp[V1 - 1];
		}
		TmpEdge->Next = Tmp[V1 - 1]->AdjEdge;
		Tmp[V1 - 1]->AdjEdge = TmpEdge;
		if ((TmpEdge = malloc(sizeof(struct EdgeStruct))) != NULL)
		{
			TmpEdge->Another = Tmp[V1-1];
			TmpEdge->Value = Value;
			TmpEdge->This = Tmp[V2 - 1];
		}
		TmpEdge->Next = Tmp[V2 - 1]->AdjEdge;
		Tmp[V2 - 1]->AdjEdge = TmpEdge;
		while ((CurChar = fgetc(fp)) == ' ' || CurChar == '\r' || CurChar == '\n');
	} while (CurChar != EOF);
	fclose(fp);
	TmpTable->Size = Count;
	TmpTable->Table = Tmp;
	if (Tmp != NULL)
		return TmpTable;
	else exit(1);
}
void Refresh(Map Map)//将图的设置重置
{
	int i;
	for (i = 0; i < Map->Size; i++)
	{
		Map->Table[i]->Distant = 10000;
		Map->Table[i]->Known = 0;
		Map->Table[i]->Previous = NULL;
	}
}