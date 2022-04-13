#ifndef ___DISJSET___
#define ___DISJSET___

typedef int SetElementType;
typedef int SetType;
typedef int* DisJSet;
DisJSet CreateDisJSet(int size);
void Union(DisJSet S, SetType Root1, SetType Root2);
SetType Find(SetElementType X, DisJSet S);

#endif // !___DISJSET___

