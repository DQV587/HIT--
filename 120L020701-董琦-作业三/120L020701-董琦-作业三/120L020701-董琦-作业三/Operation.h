#ifndef ____OPERATION____
#define ____OPERATION____
#include"BinTree.h"
#include"Queue.h"
#include"Stack.h"
//���ֱ���������ǰ�����еݹ�ͷǵݹ�������ʽ
void PreOrderRec(BinTree T);
void PreOrderNRec(BinTree T);
void MidOrderRec(BinTree T);
void MidOrderNRec(BinTree T);
void PostOrderRec(BinTree T);
void PostOrderNRec(BinTree T);
void LayerOrder(BinTree T);
//�ж��Ƿ���������
int IsFull(BinTree T);
//�������Ŀ�ȣ��ǵݹ�
int Width(BinTree T);

#endif // !____OPERATION____

