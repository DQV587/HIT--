#ifndef __SEQLIST__
#define __SEQLIST__
typedef int ElementType;
typedef int Size;
typedef int Length;
typedef int Position;
typedef struct Seqlist
{
    ElementType* head;
    Size size;
    Length length;
} *seqlist;
seqlist CreateSList(Size size);
void InsertS(seqlist L, ElementType a);
void DeleteByValue(seqlist L, ElementType a);
void DeleteByPosition(seqlist L, Position P);
void DeleteRepS(seqlist L);
void ReverseS(seqlist L);
seqlist MergeS(seqlist A, seqlist B); 
void MoveS(seqlist L, int k);
void PrintS(seqlist L);
void ClearS(seqlist L);
void DeleteList(seqlist L);
#endif

