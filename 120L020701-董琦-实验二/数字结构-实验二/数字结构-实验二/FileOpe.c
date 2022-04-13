#define _CRT_SECURE_NO_WARNINGS
#include"FileOpe.h"
#include<stdlib.h>
FILE* OpenFile(char* FileName, char* mode)
{
	FILE* fp;
	if ((fp = fopen(FileName, mode)) == NULL)
	{
		printf("Open file failed.");
		exit(1);
	}
	return fp;
}