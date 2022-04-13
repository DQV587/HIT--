#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	seqlist a = CreateSList(10);
	seqlist b = CreateSList(8);
	seqlist c = NULL;
	for (i = 0; i < 10; i++)
	{
		InsertS(a, 10 - i);
	}
	for (i = 0; i < 8; i++)
	{
		InsertS(b, 8 - i);
	}
	PrintS(a);
	ReverseS(a);
	PrintS(a);
	ReverseS(a);
	PrintS(a);
	PrintS(b);
	c = MergeS(a, b);
	PrintS(c);
	DeleteByValue(c, 2);
	PrintS(c);
	DeleteRepS(c);
	PrintS(c);
	MoveS(c, 3);
	PrintS(c);
	return 1;
}