#include <stdlib.h>
#include <stdio.h>
#define MAX 5
typedef int ElemType;

//����ջ
typedef struct
{
	ElemType data[MAX];
	int top;//ջ��ָ��
}SqStack;

//��ʼ��ջ
void InitStck(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));//����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;//ջ��ָ����Ϊ-1
}

//����ջ
void DestoryStack(SqStack*& s)
{
	free(s);
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}

//��ջ
bool Push(SqStack* s, ElemType e)
{
	if (s->top == MAX - 1)//ջ��
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

//��ջ
bool Pop(SqStack* s, ElemType e)
{
	if (s->top == -1)//ջ��
		return false;
	e = s->data[s->top];//ȡջ����Ԫ��
	s->top--;
	return true;

}

//����ջ
void DisStack(SqStack* s)
{
	for (int i = 0; i < MAX; i++)
	{
		printf("ջ�е�Ԫ��Ϊ%d\n", s->data[i]);
	}
}
int main()
{
	SqStack* s;
	InitStck(s);//��ʼ��
	//�ж�ջ�Ƿ�Ϊ��
	if (StackEmpty(s))
		printf("ջ�գ�\n");
	else
		printf("ջ����Ԫ�أ�\n");
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	Push(s, 5);
	if (StackEmpty(s))
		printf("ջ�գ�\n");
	else
		printf("ջ����Ԫ�أ�\n");
	DisStack(s);
	return 0;
}
