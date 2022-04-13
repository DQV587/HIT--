#include"Map.h"
#include"MST.h"
#include<stdlib.h>
#include<Windows.h>
int main()
{
	Map map;
	LARGE_INTEGER  num;
	long long start, end, freq;
	//ʹ��Windows.h�е�ʱ��Ƶ�ʼ�ʱ
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;
	map = ScanMap(InputFileName);
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	PrimUseHeap(map);//ʹ�ö�
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("time=%ld\n", (end - start));
	ShowMST(map);
	printf("\n");
	Refresh(map);
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	Prim(map); //��ʹ�ö�
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("time=%ld\n", (end - start));
	ShowMST(map);
	printf("\n");
	Refresh(map);
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	Kruskal(map);
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("time=%ld\n", (end - start));
	return 0;
}