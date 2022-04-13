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
//����Ľṹ�壬��¼�Ƿ���ʡ�������ʱǰ�ö��㡢�����ڽӵı�
struct VertexStruct
{
	int Name;
	int Known;
	int Distant;
	Vertex Previous;
	Edge AdjEdge;
};
//�ߵĽṹ�壬��¼���ӵĶ����Ȩֵ
struct EdgeStruct
{
	Vertex Another;
	Vertex This;
	int  Value;
	Edge Next;
};
//ͼ�Ľṹ�壬��¼�������������ָ��������ָ��
struct TableStruct
{
	int Size;       
	Vertex* Table;
};
#endif // ! ____MAP____

