#include"Map.h"
#include"MST.h"
#include<stdlib.h>
#include<Windows.h>
int main()
{
	Map map;
	LARGE_INTEGER  num;
	long long start, end, freq;
	//使用Windows.h中的时钟频率计时
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;
	map = ScanMap(InputFileName);
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	PrimUseHeap(map);//使用堆
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("time=%ld\n", (end - start));
	ShowMST(map);
	printf("\n");
	Refresh(map);
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	Prim(map); //不使用堆
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