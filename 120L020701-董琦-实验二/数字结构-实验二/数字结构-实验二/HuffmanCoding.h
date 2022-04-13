#ifndef ___HUFFMANCODING___
#define ___HUFFMANCODING___

#include"FileOpe.h"
#include"Heap.h"
#include"Tree.h"
#include"List.h"

#define ConpressFileName "UnendingLove.txt"  
#define TargerFileName "ConpressedFile.huf"   
#define DeconpressFileName "result.txt"     

struct HuffumanCodeStruct;
struct ConpressedFileStruct;
struct DeconpressedFileStruct;
typedef struct HuffumanCodeStruct* HuffumanCode;
typedef struct ConpressedFileStruct* ConpressedFile;
typedef struct DeconpressedFileStruct* DeconpressedFile;

int* CountChars(char* FileName);   //����ͳ�ƴ�ѹ���ļ��ĳ����ַ�����Ƶ�ʣ�������
HuffumanCode GenerateHuffmanTree(char* FileName);    //����CountChar���ص���������������������Ȼ����й���������
void GenerateHuffmanCode(HuffumanCode Huf);          //���ù�����������������������
ConpressedFile CompressFile(char* FileName,HuffumanCode Huf);    //���ù�����������ѹ���ļ�
void ShowHuffmanCode(List HuffmanCode);          //�ڿ���̨��ӡ����������
DeconpressedFile DeconpressFile(ConpressedFile Con);   //����ѹ���ļ�����Ϣ����ѹ�ļ�
 
struct HuffumanCodeStruct
{
	int Size;
	int Count;
	List HuffumanCode;
	Tree HuffumanTree;
};
struct ConpressedFileStruct
{
	char* TargetFileName;
	int Count;
	int OriginCount;
	Tree HuffumanTree;
};
struct DeconpressedFileStruct
{
	char* FileName;
	int Count;
};
#endif // !___HUFFMANCODING___

