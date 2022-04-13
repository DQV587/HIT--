#include "Polynomial.h"
#include <math.h>

List Addition(List L1, List L2)
{
	List Tmp = CreatList();
	Position P,TmpCell;
	P = L1->Next;
	while(P!=NULL)
	{
		TmpCell = CreatTerm(P->degree, P->numerator, P->denominator, P->sign);
		Insert(TmpCell, Tmp);
		P = P->Next;
	}
	P = L2->Next;
	while (P != NULL)
	{
		TmpCell = CreatTerm(P->degree, P->numerator, P->denominator, P->sign);
		Insert(TmpCell, Tmp);
		P = P->Next;
	}
	return Tmp;
}
List Subtract(List L1, List L2)
{
	List Tmp = CreatList();
	Position P, TmpCell;
	P = L1->Next;
	while (P != NULL)
	{
		TmpCell = CreatTerm(P->degree, P->numerator, P->denominator, P->sign);
		Insert(TmpCell, Tmp);
		P = P->Next;
	}
	P = L2->Next;
	while (P != NULL)
	{
		TmpCell = CreatTerm(P->degree, P->numerator, P->denominator,1-(P->sign));
		Insert(TmpCell, Tmp);
		P = P->Next;
	}
	return Tmp;
}
List Multiply(List L1, List L2)
{
	Position P1, P2;
	List Tmp=CreatList();
	Position TmpCell=NULL;
	int TmpSign;
	P1 = L1->Next;
	P2 = L2->Next;
	if (P1 != NULL && P2 != NULL)
	{
		for (; P1 != NULL; P1 = P1->Next)
		{
			for (; P2 != NULL; P2 = P2->Next)
			{
				if (P1->sign == P2->sign)
					TmpSign = P1->sign;
				else
					TmpSign = 0;
				TmpCell = CreatTerm((P1->degree) + (P2->degree), (P1->numerator) * (P2->numerator), (P1->denominator) * (P2->denominator), TmpSign);
				Insert(TmpCell, Tmp);
			}
			P2 = L2->Next;
		}
	}
	return Tmp;
}
List Derivation(List L, int k)
{
	Position P=L->Next,TmpCell=NULL;
	int i;
	List Tmp = CreatList();
	int TmpDeg, TmpNum;
	while (P != NULL)
	{
		TmpNum = P->numerator;
		TmpDeg = P->degree;
		for (i=k; i > 0; i--)
		{
			TmpNum = TmpNum*TmpDeg;
			TmpDeg--;
			if (TmpDeg < 0)
				break;
		}
		if (i == 0)
		{
			if (TmpNum != 0) 
			{
				TmpCell = CreatTerm(TmpDeg, TmpNum, P->denominator, P->sign);
				Insert(TmpCell, Tmp);
			}
		}
		else 
			break;
		P = P->Next;
	}
	return Tmp;
}
float Calculate(List L, float x0)
{
	Position P=L->Next;
	float result = 0,tmp;
	while (P != NULL)
	{
		tmp = (float)(P->numerator) / (float)(P->denominator) * pow(x0, P->degree);
		if (P->sign == 1)
			result += tmp;
		else result -= tmp;
		P = P->Next;
	}
	return result;
}