#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct Node {
	int data;//数据
	struct Node* pre;//前指针
	struct Node* next;//后结点指针
}Node;

//初始化指针
Node* InitList()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}

//头插法
void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0) {
		node->next = L->next;
		node->pre = L;
		L->next = node;
		L->data++;
	}
	else {
		node->pre = L;
		node->next = L->next;
		L->next->pre = node;
		L->next = node;
	}

}

//尾插法
void tailInsert(Node* L, int data)
{
	Node* node = L;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	while (node->next) {
		node = node->next;
	}
	n->next = node->next;//等价于n->next=NULL:因为经过上面的循环之后，node->next=NULL;
	node->next = n;
	n->pre = node;
	L->data++;
}

int deleteElem(Node* L, int data)
{
	Node* node = L->next;
	while (node)
	{
		if (node->data == data)//删除操作:指针指向是双向的
		{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			free(node);
			return TRUE;
		}
		node = node->next;
	}
	return FALSE;
}

//遍历链表
void printLisrt(Node* L)
{
	Node* node = L->next;
	while (node)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* L = InitList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);
	headInsert(L, 5);
	tailInsert(L, 6);
	printLisrt(L);
	deleteElem(L, 1);

	printLisrt(L);
	return 0;
}