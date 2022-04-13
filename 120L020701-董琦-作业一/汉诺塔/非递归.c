#include<stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef struct{
     int N;
     char A;        //起始柱
     char B;        //借助柱
     char C;        //目标柱
}ElementType;
typedef struct {
    ElementType Data[MaxSize];
    int top;
}Stack;//汉诺塔问题的结构类型
void Push(Stack *PtrS, ElementType item){
     //入栈操作
     if (PtrS->top == MaxSize)
     {
         printf("The stack is full!\n");
         return;
     }
     else
     {
         PtrS->Data[++(PtrS->top)] = item;
         return;
     }
}
ElementType Pop(Stack *PtrS){
    if (PtrS->top == -1)
      {
          printf("The stack is empty!\n");
          exit(1);   //直接终止程序，一般不会出现这个错误
      }
      else
      {
          PtrS->top--;
         return (PtrS->Data[PtrS->top + 1]);        //或者是return PtrS->Data[PtrS->top--];
      }
}
//借助栈的非递归实现
 void Hanoi(int n){
    ElementType P, toPush;
    Stack S;
     
    P.N = n; P.A = 'a'; P.B = 'b'; P.C = 'c';
    S.top = -1;

     Push(&S, P);
     while (S.top != -1)        //当堆栈不为空时
     {
         P = Pop(&S);//出栈
         if (P.N == 1)//当只剩一个盘子时，直接由当前柱移动到目的柱
             printf("%c -> %c\n", P.A, P.C);
         else
         {
             toPush.N = P.N - 1;
             toPush.A = P.B; toPush.B = P.A; toPush.C = P.C;
             Push(&S, toPush);        //将第三步(n - 1, b, a, c)入栈
             toPush.N = 1;
             toPush.A = P.A; toPush.B = P.B; toPush.C = P.C;
             Push(&S, toPush);        //将第二步1, a, b, c)入栈
             toPush.N = P.N - 1;
             toPush.A = P.A; toPush.B = P.C; toPush.C = P.B;
             Push(&S, toPush);        //将第一步(n - 1, a, c, b)入栈
         }
     }
 }
int main(){
    int n;
    scanf("%d", &n);
    if (n <= 0)return 0;
    else Hanoi(n);
}
