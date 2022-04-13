#ifndef ___TREE___
#define ___TREE___
#include<stdlib.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Tree;
typedef PtrToNode Position;

Tree CreatTree();
Position CreatNode(char Element,int Value);
int IsEmpty(Tree T);
Tree Merge(Tree T1, Tree T2);   
void DisposeTree(Tree T);   

struct Node
{
	unsigned char Element;
	int Value;         
	Position Parent;    
	Position Left;
	Position Right;
};


#endif // !___TREE___

