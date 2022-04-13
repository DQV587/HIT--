#define _CRT_SECURE_NO_WARNINGS
#ifndef  ___ADJACENCYMATRIX___
#define  ___ADJACENCYMATRIX___


struct MatrixStruct;
typedef struct MatrixStruct* MapMatrix;

#define InputFileName "input.txt"

MapMatrix ScanMapToMatrix(char* FileName);
void BFSbyMtx(MapMatrix Map,int k);
void DFSbyMtx(MapMatrix Map,int k);
void DFSbyMtxRec(MapMatrix Map, int k);
void DFS2(MapMatrix Map, int k);
void Refresh2(MapMatrix Map);
struct MatrixStruct
{
	int N;
	int* Matrix;
};
#endif // ! ___ADJACENCYMATRIX___

