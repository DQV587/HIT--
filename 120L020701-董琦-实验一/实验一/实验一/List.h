#ifndef ____LIST__
#define ____LIST__

struct Term;

typedef struct Term* PtrToTerm;
typedef PtrToTerm List;
typedef PtrToTerm Position;

List CreatList();//����������
Position CreatTerm(int degree, int numerator, int denominator, int sign);//�����½ڵ�
void Insert(Position Term, List L);//������
void PrintList(List L);//��ӡ����
List ConvertToList(char S[40]);//�ַ���ת����
struct Term
{
	int degree;
	int numerator;
	int denominator;
	int sign;
	Position Next;
};
#endif
