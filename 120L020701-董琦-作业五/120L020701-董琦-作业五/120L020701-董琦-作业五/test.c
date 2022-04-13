#include"BinTree.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void MakeRand(int arr[], int count);
int Binary_Search(int* a, int n, int key);
int main()
{
    srand((int)time(0));
    int A[1024];
    int i;
    for (i = 0; i < 1024; i++)
    {
        A[i] = 2 * i + 1;
    }
    BinTree T1 = BuildTree(A, 1024); //用排好序的数列建立树
    MakeRand(A, 1024);
    BinTree T2 = BuildTree(A, 1024);//用随机顺序数列建立树
    printf("\n");
    int test[10000];//生成测试序列
    for (i = 0; i < 10000; i++)
    {
        test[i] = rand() % 2048;
    }
    int SucCount=0, SucTimes=0, FaiCount=0, FailTimes=0,Count;
    for (i = 0; i < 10000; i++)  //查找测试中10000个元素，分别计数失败和成功次数及比较次数
    {
        if ((Count = Find(test[i], T1)) > 0)
        {
            SucCount += Count; SucTimes++;
        }
        else
        {
            FaiCount += Count; FailTimes++;
        }
    }
    printf("T1:\nSuccess:%d\t%d\t%f\nFail:%d\t%d\t%f\n", SucCount, SucTimes, (float)SucCount / SucTimes, FaiCount, FailTimes, (float)FaiCount / FailTimes);//打印BST查找的结果  T1树
    SucCount = 0, SucTimes = 0, FaiCount = 0, FailTimes = 0;
    for (i = 0; i < 10000; i++)  //查找测试中10000个元素，分别计数失败和成功次数及比较次数 T2树
    {
        if ((Count = Find(test[i], T2)) > 0)
        {
            SucCount += Count; SucTimes++;
        }
        else
        {
            FaiCount += Count; FailTimes++;
        }
    }
    printf("T2:\nSuccess:%d\t%d\t%f\nFail:%d\t%d\t%f\n", SucCount, SucTimes, (float)SucCount / SucTimes, FaiCount, FailTimes, (float)FaiCount / FailTimes);//打印BST查找的结果
    SucCount = 0, SucTimes = 0, FaiCount = 0, FailTimes = 0;
    for (i = 0; i < 1024; i++) //BST中序遍历序列即为排好序的序列，故这里直接生成排好序的序列，与初始相同
    {
        A[i] = 2 * i + 1;
    }
    for (i = 0; i < 10000; i++)  //查找测试中10000个元素，分别计数失败和成功次数及比较次数 二分查找
    {
        if ((Count=Binary_Search(A,1024,test[i])) > 0)
        {
            SucCount += Count; SucTimes++;
        }
        else
        {
            FaiCount += Count; FailTimes++;
        }
    }
    printf("BinSearch:\nSuccess:%d\t%d\t%f\nFail:%d\t%d\t%f\n", SucCount, SucTimes, (float)SucCount / SucTimes, FaiCount, FailTimes, (float)FaiCount / FailTimes);//打印BST查找的结果
    return 0;
}

void MakeRand(int arr[], int count)
{
    srand((unsigned int)time(NULL)); //随机数种子;
    for (int i = 0; i < count - 1; i++)
    {
        int num = i + rand() % (count - 1 - i); // 取随机数
        int temp = arr[i];
        arr[i] = arr[num];
        arr[num] = temp; //交换
    }
}

int Binary_Search(int* a, int n, int key)
{
    int low, high, mid;
    low = 0;    //定义最低下标为记录首位
    high = n;   //记录最高下标为记录末位
    int Count = 0; //计数思路同树的查找，成功返回正值，失败返回负值
    while (low <= high)
    {
        mid = (low + high) / 2;
        Count++;
        if (key < a[mid]) {
            high = mid - 1;//最高位下标调小 一位
        }
        else if (key > a[mid]) {
            low = mid + 1; //最低下标调整到中位下标大一位
        }
        else {
            return Count; //代表就是次位置
        }
    }
    return Count*(-1); //没有找到返回-1*Count
}
