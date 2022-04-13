#ifndef  ____MAP____
#define  ____MAP____
#define InputFileName "input2.txt"
#define MaxNode 40
struct VertexStruct;
struct EdgeStruct;
struct MapStruct;
typedef struct VertexStruct* Vertex;
typedef struct EdgeStruct* Edge;
typedef struct TableStruct* Map;
Map ScanMap(char* FileName);
void Refresh(Map Map);
//顶点的结构体，记录是否访问、生成树时前置顶点、还有邻接的边
struct VertexStruct
{
	int Name;
	int Known;
	int Distant;
	Vertex Previous;
	Edge AdjEdge;
};
//边的结构体，记录连接的顶点和权值
struct EdgeStruct
{
	Vertex Another;
	Vertex This;
	int  Value;
	Edge Next;
};
//图的结构体，记录顶点个数，还有指向点数组的指针
struct TableStruct
{
	int Size;       
	Vertex* Table;
};
#endif // ! ____MAP____

