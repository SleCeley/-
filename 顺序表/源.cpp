#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define ElemType int 
#define MaxSize 50


typedef struct {
	ElemType data[MaxSize];		//�洢�ռ��ַ
	int length;         //��ǰ����
}SqList;

//����˳���
void CreateList(SqList*& L, ElemType a[], int n)      //��a�е�n��Ԫ�ؽ���˳���
{
	int i = 0, k = 0;                                //k��ʾL��Ԫ�صĸ�������ʼֵΪ0
	L = (SqList*)malloc(sizeof(SqList));             //���������Ա�Ŀռ�
	while (i < n)                                    //iɨ������a��Ԫ��
	{
		L->data[k] = a[i];                           //��Ԫ��a[i]��ŵ�L��
		k++; i++;
	}
	if (L)
	{
		L != NULL;
		L->length = k;                                   //����L�ĳ���k
	}
}//��ʼ��˳���

void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));             //���������Ա�Ŀռ�
	if (L)
	{
		L != NULL;
		L->length = 0;                               //�ÿ����Ա�ĳ���Ϊ0
	}
}

//�������Ա�
void DestroyList(SqList*& L)
{
	free(L);                                        //�ͷ�L��ָ��˳���ռ�
}

//�ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList*& L)
{
	return(L->length == 0);
}

//�����Ա�ĳ���
int ListLength(SqList*& L)
{
	return(L->length);
}

//������Ա�
void DispList(SqList*& L)
{
	for (int i = 0; i < L->length; i++)              //ɨ��˳��������Ԫ��ֵ
	{
		printf("%d", L->data[i]);
		printf("\t");
	}
	printf("\n");
}

//��Ԫ��ֵ����
int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;                                       //����Ԫ��e            
	if (i >= L->length)                            //δ�ҵ�ʱ����0
		return 0;
	else
		return i + 1;                                           //�ҵ��󷵻����߼����
}

//��������Ԫ��
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == MaxSize)
		return false;                              //����i����ʱ����flase
	i--;                                           //��˳����߼����ת��Ϊ�������
	for (j = L->length; j > i; j--)                //��data[i]�������Ԫ�غ���һ��λ��
		L->data[j] = L->data[j - 1];
	L->data[i] = e;                                //����Ԫ��e
	L->length++;                                   //˳���������1
	return true;                                   //�ɹ����뷵��true
}

//�Ե�һ��Ԫ����Ϊ��׼�����ֽ��ߣ�С�ڵ������ķ�����ߣ��������ķ����ұ�
int partition(SqList*& L)
{
	int i = 0, j = L->length - 1;
	ElemType pivot = L->data[0];
	while (i < j)
	{
		while (i<j && L->data[j]>pivot)
			j--;                                   //��������ɨ����һ��С�ڵ���pivot��Ԫ��
		while (i < j && L->data[i] <= pivot)
			i++;                                   //��������ɨ����һ������pivot��Ԫ��
		if (i < j)
			swap(L->data[i], L->data[j]);          //��data[i]��data[j]���н���
	}
	swap(L->data[0], L->data[i]);                  //��data[0]��data[i]���н��� 
	return 0;
}

//���kСԪ��
void GetKmin(SqList*& L, int k)
{
	int i;
	int j = L->length;
	while (k)
	{
		for (i = 0; i < j - 1; i++)
		{
			if (L->data[i] < L->data[i + 1])
				swap(L->data[i], L->data[i + 1]);
		}
		--k;
		--j;
	}
	printf("%d", L->data[j]);
}
int main()
{
	int n;
	SqList* L;
	InitList(L);
	ElemType b[MaxSize] = { 9,25,36,78,99,7,11,6,3,5,1,8,4 };
	int t = 13;
	CreateList(L, b, t);
	n = LocateElem(L, 9);
	printf("%d\n", n);
	DispList(L);
	if (ListInsert(L, 5, 66))
	    printf("����ɹ�\n");
	partition(L);
	DispList(L);
	GetKmin(L, 2);
	return 0;
}