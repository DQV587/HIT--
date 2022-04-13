                                                                                                                                                                                                      #include<stdio.h>
void InsertSort(int A[], int N);
void BubbleSort(int A[], int N);
void SelectSort(int A[], int N);
void InsertSortRec(int A[], int N, int S);
void BubbleSortRec(int A[], int N);
void SelectSortRec(int A[], int N);

int main()
{
	int A[6][10] = { { 2,5,3,6,1,7,9,8,0,4 },{ 2,5,3,6,1,7,9,8,0,4 },{ 2,5,3,6,1,7,9,8,0,4 },{ 2,5,3,6,1,7,9,8,0,4 },{ 2,5,3,6,1,7,9,8,0,4 },{ 2,5,3,6,1,7,9,8,0,4 } };
	int i;
	InsertSort(A[0], 10);
	printf("\n≤Â»Î≈≈–Ú£∫\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", A[0][i]);
	BubbleSort(A[1], 10);
	printf("\n√∞≈›≈≈–Ú£∫\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", A[1][i]);
	SelectSort(A[2], 10);
	printf("\n—°‘Ò≈≈–Ú£∫\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", A[2][i]);
	InsertSortRec(A[3], 10, 0);
	printf("\n≤Â»Î≈≈–Úµ›πÈ£∫\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", A[3][i]);
	BubbleSortRec(A[4], 10);
	printf("\n√∞≈›≈≈–Úµ›πÈ£∫\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", A[4][i]);
	SelectSortRec(A[5], 10);
	printf("\n—°‘Ò≈≈–Úµ›πÈ£∫\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", A[5][i]);
	return 0;
}
void InsertSort(int A[], int N)
{
	int i,j, tmp;
	for (i = 1; i < N; i++)
	{
		tmp = A[i];
		for(j = i; j > 0&& tmp < A[j-1]; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}
void InsertSortRec(int A[], int N,int S)
{
	if (S < 1)
		InsertSortRec(A, N, S + 1);
	else
	{
		int i, tmp;
		for (i = S - 1; i > 0 && A[i] <A[i - 1]; i--)
		{
			tmp = A[i];
			A[i] = A[i - 1];
			A[i -1] = tmp;
		}
		if (S < N)
			InsertSortRec(A, N, S + 1);
	}
}
void BubbleSort(int A[], int N)
{
	int i, j, tmp;
	for(i=N;i>0;i--)
		for(j=1;j<i;j++)
			if (A[j] < A[j - 1])
			{
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
}
void BubbleSortRec(int A[], int N)
{
	int i, tmp;
	for (i = 1; i < N;i++)
		if (A[i] < A[i - 1])
		{
			tmp = A[i];
			A[i] = A[i - 1];
			A[i - 1] = tmp;
		}
	if (N > 1)
		BubbleSortRec(A, N - 1);
}
void SelectSort(int A[], int N)
{
	int i, j, tmp,min_index;
	for (i = N - 1; i > 0; i--)
	{
		min_index = i;
		for (j = 0; j < i; j++)
		{
			if (A[j] > A[min_index])
				min_index = j;
		}
		tmp = A[min_index];
		A[min_index] = A[i];
		A[i] = tmp;
	}
}
void SelectSortRec(int A[], int N)
{
	int i, tmp, min_index=N-1;
	for (i = 0; i < N - 1; i++)
		if (A[i] > A[min_index])
			min_index = i;
	tmp = A[min_index];
	A[min_index] = A[i];
	A[i] = tmp;
	if (N > 2)
		SelectSortRec(A, N - 1);
}