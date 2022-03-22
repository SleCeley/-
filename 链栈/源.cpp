#include <stdlib.h>
#include <stdio.h>


//声明链栈中的结点类型
typedef struct linknode
{
	int data;  //数据域
	struct linknode* next;   //指针域
}LinkStNode;

//初始化栈
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

//摧毁栈
void DestoryStack(LinkStNode*& s)
{
	LinkStNode* pre = s, * p = s->next;//pre指向头结点，p指向首结点
	while (p != NULL)//循环到p为空
	{
		free(pre);//释放pre结点
		pre = p;//pre、p同步后移
		p = pre->next;
	}
	free(pre);//此时pre指向尾结点，释放其空间
}

//判断栈是否为空
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}

//进栈
void Push(LinkStNode*& s, int e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;//此时s->next为NULL，但是后面就不是NULL了
	s->next = p;
}

//出栈
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

//取栈顶元素
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
		printf("栈空\n");
	else
		printf("栈内有元素\n");
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	GetTop(s, e);
	printf("栈顶元素为%d\n", &e);
	Pop(s, e);
	printf("取出的元素是%d\n", &e);
	return 0;
}
