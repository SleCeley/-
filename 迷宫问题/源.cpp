#include <iostream>
using namespace std;
const int M = 5, N = 5;

typedef struct
{
    int incX, incY;
} Direction;

typedef struct
{
    int x, y;//当前坐标
    int di;//当前方向
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
    int x, y, di;//当前位置坐标以及方向
    int line, col;//在方向di的作用下，即将移动到达的下一个位置坐标
    Box temp;//进栈 (push) 和出栈 (pop) 的“中转站”
    maze[1][1] = -1;//留下脚印
    temp = { 1,1,-1 };
    s.push(temp);
    while (!s.isEmpty())
    {
        temp = s.pop();
        x = temp.x;
        y = temp.y;//在一个位置无路可走时，回退一个位置，继续试探。
        di = temp.di + 1;//di=temp.di+1:尝试temp.di的下一个方向
        while (di < 4)  //di<4表示方向未试探完
        {
            line = x + direction[di].incX;
            col = y + direction[di].incY;
            /*判断能否进行在该方向上进行移动*/
            if (maze[line][col] == 0)  //maze[][]=0则可以移动
            {
                temp = { x,y,di };
                //s.push((temp = { line,col,di })); //记录该路线
                s.push(temp);
                x = line;
                y = col;
                maze[line][col] = -1;//留下脚印，到此一游
                if (x == M && y == N)//如果到达出口
                    return true;
                else//未到达出口
                    di = 0;//方向初始化为向右
            }
            else //有阻碍/走过了，则换下一方向继续续试探
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
