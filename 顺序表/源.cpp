#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define ElemType int 
#define MaxSize 50


typedef struct {
	ElemType data[MaxSize];		//存储空间基址
	int length;         //当前长度
}SqList;

//建立顺序表
void CreateList(SqList*& L, ElemType a[], int n)      //由a中的n个元素建立顺序表
{
	int i = 0, k = 0;                                //k表示L中元素的个数，初始值为0
	L = (SqList*)malloc(sizeof(SqList));             //分配存放线性表的空间
	while (i < n)                                    //i扫描数组a的元素
	{
		L->data[k] = a[i];                           //将元素a[i]存放到L中
		k++; i++;
	}
	if (L)
	{
		L != NULL;
		L->length = k;                                   //设置L的长度k
	}
}//初始化顺序表

void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));             //分配存放线性表的空间
	if (L)
	{
		L != NULL;
		L->length = 0;                               //置空线性表的长度为0
	}
}

//销毁线性表
void DestroyList(SqList*& L)
{
	free(L);                                        //释放L所指的顺序表空间
}

//判断线性表是否为空表
bool ListEmpty(SqList*& L)
{
	return(L->length == 0);
}

//求线性表的长度
int ListLength(SqList*& L)
{
	return(L->length);
}

//输出线性表
void DispList(SqList*& L)
{
	for (int i = 0; i < L->length; i++)              //扫描顺序表输出各元素值
	{
		printf("%d", L->data[i]);
		printf("\t");
	}
	printf("\n");
}

//按元素值查找
int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;                                       //查找元素e            
	if (i >= L->length)                            //未找到时返回0
		return 0;
	else
		return i + 1;                                           //找到后返回其逻辑序号
}

//插入数据元素
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == MaxSize)
		return false;                              //参数i错误时返回flase
	i--;                                           //将顺序表逻辑序号转化为物理序号
	for (j = L->length; j > i; j--)                //将data[i]及后面的元素后移一个位置
		L->data[j] = L->data[j - 1];
	L->data[i] = e;                                //插入元素e
	L->length++;                                   //顺序表长度增加1
	return true;                                   //成功插入返回true
}

//以第一个元素作为基准（即分界线）小于等于它的放在左边，大于它的放在右边
int partition(SqList*& L)
{
	int i = 0, j = L->length - 1;
	ElemType pivot = L->data[0];
	while (i < j)
	{
		while (i<j && L->data[j]>pivot)
			j--;                                   //从右向左扫描找一个小于等于pivot的元素
		while (i < j && L->data[i] <= pivot)
			i++;                                   //从左向右扫描找一个大于pivot的元素
		if (i < j)
			swap(L->data[i], L->data[j]);          //将data[i]和data[j]进行交换
	}
	swap(L->data[0], L->data[i]);                  //将data[0]和data[i]进行交换 
	return 0;
}

//求第k小元素
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
	    printf("插入成功\n");
	partition(L);
	DispList(L);
	GetKmin(L, 2);
	return 0;
}