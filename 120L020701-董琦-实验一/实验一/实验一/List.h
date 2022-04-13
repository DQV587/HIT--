#ifndef ____LIST__
#define ____LIST__

struct Term;

typedef struct Term* PtrToTerm;
typedef PtrToTerm List;
typedef PtrToTerm Position;

List CreatList();//创建新链表
Position CreatTerm(int degree, int numerator, int denominator, int sign);//创建新节点
void Insert(Position Term, List L);//插入结点
void PrintList(List L);//打印链表
List ConvertToList(char S[40]);//字符串转链表
struct Term
{
	int degree;
	int numerator;
	int denominator;
	int sign;
	Position Next;
};
#endif
