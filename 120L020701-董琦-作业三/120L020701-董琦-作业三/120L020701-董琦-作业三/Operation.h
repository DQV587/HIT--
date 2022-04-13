#ifndef ____OPERATION____
#define ____OPERATION____
#include"BinTree.h"
#include"Queue.h"
#include"Stack.h"
//四种遍历方法，前三种有递归和非递归俩种形式
void PreOrderRec(BinTree T);
void PreOrderNRec(BinTree T);
void MidOrderRec(BinTree T);
void MidOrderNRec(BinTree T);
void PostOrderRec(BinTree T);
void PostOrderNRec(BinTree T);
void LayerOrder(BinTree T);
//判断是否满二叉树
int IsFull(BinTree T);
//计算树的宽度，非递归
int Width(BinTree T);

#endif // !____OPERATION____

