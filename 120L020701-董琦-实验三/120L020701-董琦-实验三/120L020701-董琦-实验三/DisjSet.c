#include"DisjSet.h"
#include<stdlib.h>

DisJSet CreateDisJSet(int size)
{
	DisJSet Tmp = malloc((size + 1) * sizeof(SetType));
	int i;
	for (i = 0; i < size + 1; i++)
		Tmp[i] = -1;
	return Tmp;
}
void Union(DisJSet S, SetType Root1, SetType Root2)
{
	if (S[Root1] < S[Root2])
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
	else
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}
SetType Find(SetElementType X, DisJSet S)
{
	if (S[X] <= 0)
		return X;
	else return Find(S[X], S);
}