#include"HuffmanCoding.h"
int main()
{
	HuffumanCode Huf = GenerateHuffmanTree(ConpressFileName);
	GenerateHuffmanCode(Huf);
	ConpressedFile Con=CompressFile(ConpressFileName,Huf);
	ShowHuffmanCode(Huf->HuffumanCode);
	float ratio;
	ratio = (float)Con->Count / (float)Huf->Count;
	printf("%f", ratio);
	DeconpressedFile Dec = DeconpressFile(Con);
	return 0;
}