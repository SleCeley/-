#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct Node {
	int data;//����
	struct Node* pre;//ǰָ��
	struct Node* next;//����ָ��
}Node;

//��ʼ��ָ��
Node* InitList()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	L->pre = NULL;
	return L;
}

//ͷ�巨
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

//β�巨
void tailInsert(Node* L, int data)
{
	Node* node = L;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	while (node->next) {
		node = node->next;
	}
	n->next = node->next;//�ȼ���n->next=NULL:��Ϊ���������ѭ��֮��node->next=NULL;
	node->next = n;
	n->pre = node;
	L->data++;
}

int deleteElem(Node* L, int data)
{
	Node* node = L->next;
	while (node)
	{
		if (node->data == data)//ɾ������:ָ��ָ����˫���
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

//��������
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