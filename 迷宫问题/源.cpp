#include <iostream>
using namespace std;
const int M = 5, N = 5;

typedef struct
{
    int incX, incY;
} Direction;

typedef struct
{
    int x, y;//��ǰ����
    int di;//��ǰ����
} Box;

const char* direct[4] = { "right","down","left","up" };

class Stack
{
private:
    Box* path;
    int top;
public:
    Stack();
    ~Stack();
    void push(Box temp);
    Box pop();
    bool isEmpty();
    bool isFull();
    void displayPath();
    class Empty {};
    class Full {};
};
Stack::Stack()
{
    top = -1;
    path = new Box[M * N];
}
Stack::~Stack()
{
    delete[] path;
}
void Stack::push(Box temp)
{
    if (!isFull())
        path[++top] = temp;
    else
        throw Full();
}
Box Stack::pop()
{
    if (!isEmpty())
        return path[top--];
    else
        throw Empty();
}
bool Stack::isEmpty()
{
    return top == -1;
}
bool Stack::isFull()
{
    return top == M * N - 1;
}
void Stack::displayPath()
{
    int i = 0;
    if (isEmpty())
        throw Empty();
    while (!isEmpty() && i <= top)
    {
        cout << "(" << path[i].x << " , " << path[i].y << ")" << "  " << direct[path[i].di] << endl;
        i++;
    }
}

bool findPath(int maze[M + 2][N + 2], Direction direction[], Stack& s)
{
    int x, y, di;//��ǰλ�������Լ�����
    int line, col;//�ڷ���di�������£������ƶ��������һ��λ������
    Box temp;//��ջ (push) �ͳ�ջ (pop) �ġ���תվ��
    maze[1][1] = -1;//���½�ӡ
    temp = { 1,1,-1 };
    s.push(temp);
    while (!s.isEmpty())
    {
        temp = s.pop();
        x = temp.x;
        y = temp.y;//��һ��λ����·����ʱ������һ��λ�ã�������̽��
        di = temp.di + 1;//di=temp.di+1:����temp.di����һ������
        while (di < 4)  //di<4��ʾ����δ��̽��
        {
            line = x + direction[di].incX;
            col = y + direction[di].incY;
            /*�ж��ܷ�����ڸ÷����Ͻ����ƶ�*/
            if (maze[line][col] == 0)  //maze[][]=0������ƶ�
            {
                temp = { x,y,di };
                //s.push((temp = { line,col,di })); //��¼��·��
                s.push(temp);
                x = line;
                y = col;
                maze[line][col] = -1;//���½�ӡ������һ��
                if (x == M && y == N)//����������
                    return true;
                else//δ�������
                    di = 0;//�����ʼ��Ϊ����
            }
            else //���谭/�߹��ˣ�����һ�����������̽
                di++;
        }
    }
    return false;
}

int main()
{
    int maze[M + 2][N + 2] =
    {
        {1,1,1,1,1,1,1},
        {1,0,0,1,0,0,1},
        {1,1,0,1,0,1,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };
    Stack s;
    Direction direction[4] = { {0,1},{1,0},{0,-1},{-1,0} };
    if (findPath(maze, direction, s))
    {
        cout << "Find path" << endl;
        s.displayPath();
    }
    else cout << "DON'T FIND" << endl;
}
