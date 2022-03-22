#include <stdlib.h>
#include <stdio.h>
#define MAX 5
typedef int ElemType;

//定义栈
typedef struct
{
	ElemType data[MAX];
	int top;//栈顶指针
}SqStack;

//初始化栈
void InitStck(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));//分配一个顺序栈空间，首地址存放在s中
	s->top = -1;//栈顶指针置为-1
}

//销毁栈
void DestoryStack(SqStack*& s)
{
	free(s);
}

//判断栈是否为空
bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}

//进栈
bool Push(SqStack* s, ElemType e)
{
	if (s->top == MAX - 1)//栈满
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//出栈
bool Pop(SqStack* s, ElemType e)
{
	if (s->top == -1)//栈空
		return false;
	e = s->data[s->top];//取栈顶的元素
	s->top--;
	return true;

}

//遍历栈
void DisStack(SqStack* s)
{
	for (int i = 0; i < MAX; i++)
	{
		printf("栈中的元素为%d\n", s->data[i]);
	}
}
int main()
{
	SqStack* s;
	InitStck(s);//初始化
	//判断栈是否为空
	if (StackEmpty(s))
		printf("栈空！\n");
	else
		printf("栈中有元素！\n");
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	Push(s, 5);
	if (StackEmpty(s))
		printf("栈空！\n");
	else
		printf("栈中有元素！\n");
	DisStack(s);
	return 0;
}
