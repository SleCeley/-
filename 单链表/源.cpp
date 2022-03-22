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
	List();//初始化
	bool add(int data);//增加
	bool del(int data);//删除
	bool insert(int posi, int data);//插入
	int find(int posi);//查找
};


List::List() {
	head = NULL;
	length = 0;
}

//增加
bool List::add(int data)
{
	Point* p = new Point();
	p->setdata(data);
	if (head == NULL) {//头结点为空的时候
		head = p;
		length++;
		return 1;
	}
	else               //非结节点
	{
		Point* q = head;
		for (int i = 0; i < length - 1; i++)
			q = q->getnext();
		q->setnext(p);
		length++;
		return 1;
	}
}

//删除：删除头结点、删除中间结点、删除尾结点
bool List::del(int posi)
{
	if (posi<0 || posi>length)
		return "del error";
	//1.如果删除结点为头结点
	Point* q = head;
	if (posi == 0)
	{
		head = q->getnext();
		length--;
		delete(q);
		return 1;
	}
	//2.删除结点为尾结点
	if (posi == length)
	{
		for (int i = 0; i < posi - 1; i++)
		{
			delete(q->getnext());
			return 1;
		}
	}
	else//3.删除结点并非头结点和尾结点
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


//插入
bool List::insert(int posi, int data)
{
	if (posi<0 || posi>length)//判断位置是否合法
		return "insert error";
	Point* p = new Point();//新建的
	p->setdata(data);
	Point* q = head;//原来的头结点
	//1.如果插入为头结点
	if (posi == 0)
	{
		p->setnext(q);
		head = p;
		length++;
		return 1;
	}
	else//2.插入处并非头结点
	{
		for (int i = 0; i < posi - 1; i++)
			q = q->getnext();
		p->setnext(q->getnext());
		q->setnext(p);
		length++;
	}
}

//遍历
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