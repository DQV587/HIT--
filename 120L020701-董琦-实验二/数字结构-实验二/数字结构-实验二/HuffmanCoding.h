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

int* CountChars(char* FileName);   //用于统计待压缩文件的出现字符及其频率（个数）
HuffumanCode GenerateHuffmanTree(char* FileName);    //利用CountChar返回的数组来构建哈夫曼树，然后进行哈夫曼编码
void GenerateHuffmanCode(HuffumanCode Huf);          //利用哈夫曼树来产生哈夫曼编码
ConpressedFile CompressFile(char* FileName,HuffumanCode Huf);    //利用哈夫曼编码来压缩文件
void ShowHuffmanCode(List HuffmanCode);          //在控制台打印哈夫曼编码
DeconpressedFile DeconpressFile(ConpressedFile Con);   //利用压缩文件的信息来解压文件
 
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

