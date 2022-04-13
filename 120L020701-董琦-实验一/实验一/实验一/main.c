#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"FileOpe.h"
#include"List.h"
#include"Polynomial.h"

int main()
{
	char C[2][40];
	List C0,C1,C2,C3,C4,C5;
	float result = 0;
	ReadFile(C);
	C0 = ConvertToList(C[0]);
	C1 = ConvertToList(C[1]);
	//输出多项式
	printf("C0:");
	PrintList(C0);
	WriteFile(C0);
	printf("C1:");
	PrintList(C1);
	WriteFile(C1);
	C2 = Addition(C0, C1);
	printf("C0+C1:");
	PrintList(C2);
	WriteFile(C2);
	C3 = Subtract(C0, C1);
	printf("C0-C1:");
	PrintList(C3);
	WriteFile(C3);
	C4 = Multiply(C0, C1);
	printf("C0*C1:");
	PrintList(C4);
	WriteFile(C4);
	C5 = Derivation(C0, 2);
	printf("对C0求二阶导:");
	PrintList(C5);
	WriteFile(C5);
	result = Calculate(C0, 2);
	printf("C0 x=2:");
	printf("%f", result);
	return 0;
}