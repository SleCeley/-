#include <stdlib.h>
#include <stdio.h>


//������ջ�еĽ������
typedef struct linknode
{
	int data;  //������
	struct linknode* next;   //ָ����
}LinkStNode;

//��ʼ��ջ
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

//�ݻ�ջ
void DestoryStack(LinkStNode*& s)
{
	LinkStNode* pre = s, * p = s->next;//preָ��ͷ��㣬pָ���׽��
	while (p != NULL)//ѭ����pΪ��
	{
		free(pre);//�ͷ�pre���
		pre = p;//pre��pͬ������
		p = pre->next;
	}
	free(pre);//��ʱpreָ��β��㣬�ͷ���ռ�
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}

//��ջ
void Push(LinkStNode*& s, int e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;//��ʱs->nextΪNULL�����Ǻ���Ͳ���NULL��
	s->next = p;
}

//��ջ
bool Pop(LinkStNode*& s, int& e)
{
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	p->data = e;
	s->next = p->next;
	free(p);
	return true;
}

//ȡջ��Ԫ��
bool GetTop(LinkStNode* s, int& e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

int main()
{
	LinkStNode* s;
	int e;
	InitStack(s);
	if (StackEmpty(s))
		printf("ջ��\n");
	else
		printf("ջ����Ԫ��\n");
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	GetTop(s, e);
	printf("ջ��Ԫ��Ϊ%d\n", &e);
	Pop(s, e);
	printf("ȡ����Ԫ����%d\n", &e);
	return 0;
}
