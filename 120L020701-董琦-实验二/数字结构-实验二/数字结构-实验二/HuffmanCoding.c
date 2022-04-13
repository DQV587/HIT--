
#include"HuffmanCoding.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int* CountChars(char* FileName)
{
	int* Count;
	Count = (int*)malloc(256 * sizeof(int));  
	if (Count == NULL)
	{
		printf("No space spared.");
		exit(2);
	}
	memset(Count,0,1024);
	FILE* ReadFile = OpenFile(FileName, "rb");
	int i;
	while ((i = fgetc(ReadFile)) != EOF)
	{
		Count[i]++;           
	}
	fclose(ReadFile);
	return Count;            
}

HuffumanCode GenerateHuffmanTree(char* FileName)
{
	int* Count = CountChars(FileName);     
	HuffumanCode Tmp=malloc(sizeof(struct HuffumanCodeStruct));    
	if (Tmp == NULL)
		exit(1);
	Tmp->Size = 0;
	Heap H = Initialize(256);  
	Tree HuffmanTree, TmpCell;
	List HuffmanList = CreatList();  
	int i;
	for (i = 0; i < 256; i++)     
		if (Count[i] != 0)
		{
			TmpCell = CreatNode(i, Count[i]);
			InsertList(TmpCell, HuffmanList); 
			Tmp->Size++;    
			Insert(TmpCell, H);
		}
	free(Count);  
	while (H->Size != 1)   
		Insert(Merge(DeleteMin(H), DeleteMin(H)), H);
	HuffmanTree = DeleteMin(H);  
	DisposeHeap(H);   
	Tmp->HuffumanTree = HuffmanTree;  
	Tmp->Count = HuffmanTree->Value; 
	Tmp->HuffumanCode = HuffmanList;
	GenerateHuffmanCode(Tmp);
	return Tmp;
}

void Reverse(char* A) 
{
	int i = strlen(A),j;
	char Tmp;
	for (j = 0; j < i / 2; j++)
	{
		Tmp = A[j];
		A[j] = A[i - j - 1];
		A[i - j - 1] = Tmp;
	}
}

void GenerateHuffmanCode(HuffumanCode Huf)
{
	List CurListNode = Huf->HuffumanCode->Next;  
	Position CurTreeNode, Parent;
	int i; 
	char TmpCode[50];
	while (CurListNode != NULL)
	{
		i = 0;
		CurTreeNode = CurListNode->Element;
		Parent = CurTreeNode->Parent;
		while (Parent != NULL)     
		{
			if (Parent->Left == CurTreeNode)
				TmpCode[i++] = '0';
			else if (Parent->Right == CurTreeNode)
				TmpCode[i++] = '1';
			CurTreeNode = Parent;
			Parent = CurTreeNode->Parent;
		}
		TmpCode[i] = '\0';
		Reverse(TmpCode); 
		CurListNode->HuffumanCode = (char*)malloc((strlen(TmpCode) + 1) * sizeof(char)); 
		if (CurListNode->HuffumanCode == NULL)
			exit(1);
		strcpy_s(CurListNode->HuffumanCode,strlen(TmpCode)+1, TmpCode);
		CurListNode = CurListNode->Next;
	}
}

void ShowHuffmanCode(List HuffmanCode)  
{
	List CurNode = HuffmanCode->Next;
	while (CurNode != NULL)
	{
		printf("%c\t%s\n", CurNode->Element->Element, CurNode->HuffumanCode);
		CurNode = CurNode->Next;
	}
}

ConpressedFile CompressFile(char* FileName,HuffumanCode Huf)  
{
	int i;
	List CurListNode;
	char* HuffmanCodeMap[256];
	memset(HuffmanCodeMap, 0, 256*sizeof(char*));
	CurListNode = Huf->HuffumanCode->Next;
	while (CurListNode != NULL)  
	{
		HuffmanCodeMap[CurListNode->Element->Element] = CurListNode->HuffumanCode;
		CurListNode = CurListNode->Next;
	}
	FILE* SourceFile = OpenFile(ConpressFileName,"rb"); 
	FILE* TargerFile = OpenFile(TargerFileName, "wb");  
	unsigned char InputChar=0;
	int Count = 0,pos=0,j,CurChar;  
	char* CurCharCode=NULL;
	// 下面是压缩过程，具体就是对位操作，用位或操作写1，满8位则往文件中写一个字，然后到文件末尾时，如果不足八位则补足八位，压缩时统计压缩前的字符数，便于后面解码
	CurChar = fgetc(SourceFile);   
	while (CurChar != EOF)
	{
		CurCharCode = HuffmanCodeMap[CurChar];  
		j = strlen(CurCharCode);
		for (i = 0; i < j; i++)       
		{
			InputChar <<= 1;
			if (CurCharCode[i] == '1')
				InputChar |= 1;
			if (++pos == 8)         
			{
				fputc(InputChar, TargerFile);
				InputChar = 0;
				pos = 0;
				Count++;
			}
		}
		CurChar= fgetc(SourceFile);
	}
	if (pos)     
	{
		InputChar =InputChar << (8 - pos);
		fputc(InputChar, TargerFile);
	}

	fclose(SourceFile);
	fclose(TargerFile);

	
	ConpressedFile Con = malloc(sizeof(struct ConpressedFileStruct));
	assert(Con);
	Con->Count = Count;
	Con->OriginCount = Huf->Count;
	Con->TargetFileName = (char*)malloc((strlen(TargerFileName) + 1) * sizeof(char));
	assert(Con->TargetFileName);
	strcpy_s(Con->TargetFileName, strlen(TargerFileName) + 1, TargerFileName);
	Con->HuffumanTree = Huf->HuffumanTree;
	return Con;
}

DeconpressedFile DeconpressFile(ConpressedFile Con) 
{
	FILE* SourceFile,* TargetFile;
	SourceFile = OpenFile(Con->TargetFileName,"rb");
	TargetFile = OpenFile(DeconpressFileName, "wb");
	Tree HuffumanTree = Con->HuffumanTree;    
	Position CurPosition;
	int i = Con->OriginCount,Pos=8; 
	int CurBit = fgetc(SourceFile);
	CurPosition = Con->HuffumanTree;

	while (i > 0&&CurBit!=EOF)  
	{
		--Pos;
		if ((CurBit >> Pos) & 1)
			CurPosition = CurPosition->Right;
		else CurPosition = CurPosition->Left;
		if (CurPosition->Left == NULL && CurPosition->Right == NULL)   //走到叶子
		{
			fputc(CurPosition->Element, TargetFile);
			CurPosition = Con->HuffumanTree;
			i--;
		}
		if (Pos == 0)  //满八位则重置
		{
			CurBit = fgetc(SourceFile);
			Pos = 8;
		}
	}
	//创建解压文件的结构体，返回。
	DeconpressedFile Dec = malloc(sizeof(struct DeconpressedFileStruct));
	assert(Dec);
	Dec->Count = Con->OriginCount;
	Dec->FileName = malloc((strlen(TargerFileName) + 1) * sizeof(char));
	assert(Dec->FileName);
	strcpy_s(Dec->FileName, strlen(TargerFileName) + 1, TargerFileName);
	return Dec;
}