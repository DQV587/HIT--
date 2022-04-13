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
    BinTree T1 = BuildTree(A, 1024); //���ź�������н�����
    MakeRand(A, 1024);
    BinTree T2 = BuildTree(A, 1024);//�����˳�����н�����
    printf("\n");
    int test[10000];//���ɲ�������
    for (i = 0; i < 10000; i++)
    {
        test[i] = rand() % 2048;
    }
    int SucCount=0, SucTimes=0, FaiCount=0, FailTimes=0,Count;
    for (i = 0; i < 10000; i++)  //���Ҳ�����10000��Ԫ�أ��ֱ����ʧ�ܺͳɹ��������Ƚϴ���
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
    printf("T1:\nSuccess:%d\t%d\t%f\nFail:%d\t%d\t%f\n", SucCount, SucTimes, (float)SucCount / SucTimes, FaiCount, FailTimes, (float)FaiCount / FailTimes);//��ӡBST���ҵĽ��  T1��
    SucCount = 0, SucTimes = 0, FaiCount = 0, FailTimes = 0;
    for (i = 0; i < 10000; i++)  //���Ҳ�����10000��Ԫ�أ��ֱ����ʧ�ܺͳɹ��������Ƚϴ��� T2��
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
    printf("T2:\nSuccess:%d\t%d\t%f\nFail:%d\t%d\t%f\n", SucCount, SucTimes, (float)SucCount / SucTimes, FaiCount, FailTimes, (float)FaiCount / FailTimes);//��ӡBST���ҵĽ��
    SucCount = 0, SucTimes = 0, FaiCount = 0, FailTimes = 0;
    for (i = 0; i < 1024; i++) //BST����������м�Ϊ�ź�������У�������ֱ�������ź�������У����ʼ��ͬ
    {
        A[i] = 2 * i + 1;
    }
    for (i = 0; i < 10000; i++)  //���Ҳ�����10000��Ԫ�أ��ֱ����ʧ�ܺͳɹ��������Ƚϴ��� ���ֲ���
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
    printf("BinSearch:\nSuccess:%d\t%d\t%f\nFail:%d\t%d\t%f\n", SucCount, SucTimes, (float)SucCount / SucTimes, FaiCount, FailTimes, (float)FaiCount / FailTimes);//��ӡBST���ҵĽ��
    return 0;
}

void MakeRand(int arr[], int count)
{
    srand((unsigned int)time(NULL)); //���������;
    for (int i = 0; i < count - 1; i++)
    {
        int num = i + rand() % (count - 1 - i); // ȡ�����
        int temp = arr[i];
        arr[i] = arr[num];
        arr[num] = temp; //����
    }
}

int Binary_Search(int* a, int n, int key)
{
    int low, high, mid;
    low = 0;    //��������±�Ϊ��¼��λ
    high = n;   //��¼����±�Ϊ��¼ĩλ
    int Count = 0; //����˼·ͬ���Ĳ��ң��ɹ�������ֵ��ʧ�ܷ��ظ�ֵ
    while (low <= high)
    {
        mid = (low + high) / 2;
        Count++;
        if (key < a[mid]) {
            high = mid - 1;//���λ�±��С һλ
        }
        else if (key > a[mid]) {
            low = mid + 1; //����±��������λ�±��һλ
        }
        else {
            return Count; //������Ǵ�λ��
        }
    }
    return Count*(-1); //û���ҵ�����-1*Count
}
