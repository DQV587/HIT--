#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

List CreatList()
{
	List Tmp = (List)malloc(sizeof(struct Term));
	if (!Tmp)
	{
		printf("The space is full!");
		exit(0);
	}
	Tmp->degree = -1;
	Tmp->denominator = -1;
	Tmp->numerator = -1;
	Tmp->sign = -1;
	Tmp->Next = NULL;
	return Tmp;
}
Position CreatTerm(int degree, int numerator, int denominator, int sign)
{
	Position Tmp = (Position)malloc(sizeof(struct Term));
	if (Tmp == NULL)
	{
		printf("out of space");
		exit(1);
	}
	Tmp->degree = degree;
	Tmp->numerator = numerator;
	Tmp->denominator = denominator;
	Tmp->sign = sign;
	Tmp->Next = NULL;
	return Tmp;
}
void Insert(Position Term, List L)
{
	Position P,Tmp=NULL;
	int TmpNum, TmpDen;
	P = L;
	while (P->Next != NULL && P->Next->degree > Term->degree)
		P = P->Next;
	if ((P->Next != NULL) && (P->Next->degree == Term->degree))
	{
		Tmp = P->Next;
		if (Tmp->sign == Term->sign)
		{
			if (Tmp->denominator == Term->denominator)
			{
				Tmp->numerator += Term->numerator;
			}
			else
			{
				TmpDen = Tmp->denominator * Term->denominator;
				TmpNum = Tmp->numerator * Term->denominator + Term->numerator * Tmp->denominator;
				Tmp->denominator = TmpDen;
				Tmp->numerator = TmpNum;
			}
			free(Term);
		}
		else
		{
			TmpDen = Tmp->denominator * Term->denominator;
			TmpNum = Tmp->numerator * Term->denominator - Term->numerator * Tmp->denominator;
			if (TmpNum == 0)
				P->Next=Tmp->Next;
			else
			{
				if (TmpNum < 0)
				{
					TmpNum = TmpNum * (-1);
					Tmp->sign = 1 - Tmp->sign;
				}
				Tmp->denominator = TmpDen;
				Tmp->numerator = TmpNum;
			}
		}
	}
	else 
	{
		Term->Next = P->Next;
		P->Next = Term;
	}
}
void PrintList(List L)
{
	Position P = L->Next;
	while (P != NULL)
	{
		if (P->sign == 1)
			printf("+");
		else printf("-");
		if (P->denominator != 1)
		{
			printf("%d", P->numerator);
			printf("/");
			printf("%d", P->denominator);
		}
		else
		{
			if (P->numerator != 1)
				printf("%d", P->numerator);
		}
		if (P->degree != 0)
		{
			printf("x");
			if (P->degree != 1)
				printf("*%d", P->degree);
		}
		P = P->Next;
	}
	printf("\n");
}
List ConvertToList(char S[40])
{
	List Tmp = CreatList();
	Position TmpCell;
	int Sign;
	char Numerator[5];
	char Denominator[5];
	int Degree;
	int i=strlen(S),j=0,m=0;
    while(j<i)
	{
		//检查符号
		if (S[j] == '-')
			Sign = 0;
		else
			Sign = 1;
		j++;
		//检查系数
		if (S[j] == 'x')
		{
			Numerator[0] = '1';
			Numerator[1] = '\0';
			Denominator[0] = '1';
			Denominator[1] = '\0';
		}
		else
		{
			while(S[j] <= '9' && S[j] >= '0')
				Numerator[m++] = S[j++];
			Numerator[m] = '\0';
			m = 0;
			if (S[j] == '/')
			{
				j++;
				while (S[j] <= '9' && S[j] >= '0')
					Denominator[m++] = S[j++];
				Denominator[m] = '\0';
				m = 0;
			}
			else
			{
				Denominator[0] = '1';
				Denominator[1] = '\0';
			}
		}
		//检查次数
		if (S[j] == '+' || S[j] == '-')
			Degree = 0;
		else
		{
			j++;
			if (S[j] == '+' || S[j] == '-')
				Degree = 1;
			else 
			{
				j++;
				Degree = S[j]-'0';
				j++;
			}
		}
        TmpCell = CreatTerm(Degree, atoi(Numerator), atoi(Denominator), Sign);
		Insert(TmpCell, Tmp);
		if (j == i) break;
	}
	return Tmp;
}