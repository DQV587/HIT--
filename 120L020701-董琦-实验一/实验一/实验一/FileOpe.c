#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"FileOpe.h"
#include<stdlib.h>
#include<string.h>
void ReadFile(char C[2][40])
{
	FILE* fp;
	//读取多项式的文件
	fp = fopen("input.txt", "r");
	fgets(C[0], 40, fp);
	C[0][strlen(C[0]) - 1] = '\0';
	fgets(C[1], 40, fp);
	C[1][strlen(C[1]) - 1] = '\0';
	fclose(fp);
}
void WriteFile(List L)
{
	FILE* fp;
	Position P = L->Next;
	//输出多项式的文件
	fp = fopen("result.txt", "a");
	while (P != NULL)
	{
		if (P->sign == 1)
			fputc('+', fp);
		else
			fputc('-', fp);
		if (P->denominator != 1)
		{
			fprintf(fp, "%d", P->numerator);
			fprintf(fp, "/%d", P->denominator);
		}
		else
		{
			if (P->numerator == 1);
			else
				fprintf(fp, "%d", P->numerator);
		}
		if (P->degree == 0);
		else
		{
			fprintf(fp, "x");
			if (P->degree > 1)
				fprintf(fp, "*%d", P->degree);
		}
		P = P->Next;
	}
	fprintf(fp, "\n");
	fclose(fp);
}