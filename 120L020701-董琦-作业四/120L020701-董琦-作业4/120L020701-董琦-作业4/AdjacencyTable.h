#ifndef ____ADJACENCYTABLE____
#define ____ADJACENCYTABLE____

struct NodeStruct;
struct TableStruct;
typedef struct NodeStruct* PtrToMapNode;
typedef PtrToMapNode Node;
typedef PtrToMapNode AdjNode;
typedef PtrToMapNode* AdjacencyTable;
typedef struct TableStruct* MapTable;

#define  MAXNODE   20
#define InputFileName "input.txt"

MapTable ScanMapToTab(char* FileName);
void BFSbyTab(MapTable Map,int k);
void DFSbyTab(MapTable Map,int k); //∑«µ›πÈ
void DFSbyTabRec(MapTable Map, int k); //µ›πÈ
void DFS1(MapTable Map, Node N);
void Visit1(Node N);
void Refresh1(MapTable Map);
//º∆À„∂»
int* CountOutDegreeByTab(MapTable Map);
int* CountInDegreeByTab(MapTable Map);
int* CountDegreeByTab(MapTable Map);
struct NodeStruct
{
	int Name;
	int Visited;
	int Serial;
	int Distant;
	Node Next;
};
struct TableStruct
{
	int N;
	AdjacencyTable Table;
};
#endif // !____ADJACENCYTABLE____

