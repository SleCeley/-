#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

class Point {
	int data;
	Point* next;
public:
	int getdata();
	void setdata(int data);
	Point* getnext();
	void setnext(Point* next);
};

int Point::getdata()
{
	return data;
}

void Point::setdata(int data) {
	this->data = data;
}

Point* Point::getnext() {
	return this->next;
}
void Point::setnext(Point* next) {
	this->next = next;
}

class List {
	Point* head;
	int length;
public:
	List();//��ʼ��
	bool add(int data);//����
	bool del(int data);//ɾ��
	bool insert(int posi, int data);//����
	int find(int posi);//����
};


List::List() {
	head = NULL;
	length = 0;
}

//����
bool List::add(int data)
{
	Point* p = new Point();
	p->setdata(data);
	if (head == NULL) {//ͷ���Ϊ�յ�ʱ��
		head = p;
		length++;
		return 1;
	}
	else               //�ǽ�ڵ�
	{
		Point* q = head;
		for (int i = 0; i < length - 1; i++)
			q = q->getnext();
		q->setnext(p);
		length++;
		return 1;
	}
}

//ɾ����ɾ��ͷ��㡢ɾ���м��㡢ɾ��β���
bool List::del(int posi)
{
	if (posi<0 || posi>length)
		return "del error";
	//1.���ɾ�����Ϊͷ���
	Point* q = head;
	if (posi == 0)
	{
		head = q->getnext();
		length--;
		delete(q);
		return 1;
	}
	//2.ɾ�����Ϊβ���
	if (posi == length)
	{
		for (int i = 0; i < posi - 1; i++)
		{
			delete(q->getnext());
			return 1;
		}
	}
	else//3.ɾ����㲢��ͷ����β���
	{
		for (int i = 0; i < posi - 1; i++)
		{
			q = q->getnext();
			Point* a = q->getnext();
			q->setnext(q->getnext()->getnext());
			delete(a);
			length--;
			return 1;
		}
	}
}


//����
bool List::insert(int posi, int data)
{
	if (posi<0 || posi>length)//�ж�λ���Ƿ�Ϸ�
		return "insert error";
	Point* p = new Point();//�½���
	p->setdata(data);
	Point* q = head;//ԭ����ͷ���
	//1.�������Ϊͷ���
	if (posi == 0)
	{
		p->setnext(q);
		head = p;
		length++;
		return 1;
	}
	else//2.���봦����ͷ���
	{
		for (int i = 0; i < posi - 1; i++)
			q = q->getnext();
		p->setnext(q->getnext());
		q->setnext(p);
		length++;
	}
}

//����
int List::find(int posi)
{
	if (posi<0 || posi>length)
	{
		cout << "find error" << endl;
		return 0;
	}
	Point* p = head;
	for (int i = 0; i < posi; i++)
	{
		p = p->getnext();
		return p->getdata();
	}
}
void main()
{
	List l = List();
	l.add(10);
	l.add(6);
	l.add(3);
	l.add(8);
	l.add(4);
	for (int i = 0; i < 5; i++)
		cout << l.find(i) << endl;
	l.insert(1, 4);
	l.del(2);
	for (int i = 0; i < 5; i++)
		cout << l.find(i) << endl;
}