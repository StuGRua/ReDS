#include <iostream>
#include <stack>
using namespace std;
#define M 8
#define N 8
const int XLEN = 10, YLEN = 10; // 默认迷宫的行数和列数
int m, p;                       // 出口坐标
int mark[XLEN][YLEN];           // 访问标记数组

struct Offsets
{
    int a, b; // a和b是x,y方向的偏移
};

Offsets direction[4] = {
    {-1, 0}, // 北0
    {0, 1},  // 东1
    {1, 0},  // 南2
    {0, -1}  // 西3
};

struct items // 结点定义
{
    int x, y, dir;
};

// 栈算法，深度优先
void Path(int x, int y, int m, int n, int maze[M + 2][N + 2]) // x, y为入口坐标;m,n为出口坐标
{
    int i, j, g, h, d;
    stack<items> st; // 工作栈
    items tmp;

    mark[x][y] = 1; // x, y 是入口
    tmp.x = x, tmp.y = y;
    tmp.dir = 0;  // 从N方向开始
    st.push(tmp); // 入口坐标进栈
    while (!st.empty())
    {                   // 当栈不空，一直走下去
        tmp = st.top(); // 取栈顶元素
        cout << "testout:"<<tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
        st.pop();       // 退栈
        i = tmp.x;
        j = tmp.y;   // 取得当前位置坐标
        d = tmp.dir; // 方向
        while (d < 4)
        {
            // 找下一位置（g, h）
            g = i + direction[d].a;
            h = j + direction[d].b;
            if (g == m && h == n) // 到达出口
            {
                tmp.x = i; //为了输出完整路径将最后一段压栈
                tmp.y = j;
                st.push(tmp);
                cout << "Found way:(reversed order)\nx, y, D" << endl;
                cout << m << ", " << n << ", " << '0' << "(End)" << endl;
                while (!st.empty()) // 逆向输出路径
                {                   // 输出栈中存的路径
                    tmp = st.top(); // 取栈顶元素
                    st.pop();       // 出栈
                    cout << tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
                }
                exit(0);
            }

            if (maze[g][h] == 0 && mark[g][h] == 0) // 如果通且未被访问过(未到达出口)
            {
                mark[g][h] = 1; // 标记为已访问过
                tmp.x = i;
                tmp.y = j;
                tmp.dir = d;  // 记忆已走过的位置和前进的方向
                st.push(tmp); // 进栈
                cout << "testin:"<<tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
                i = g;
                j = h;
                d = 0; // 移动到（g, h）,重复向各个方向试探的过程
            }
            else // 试探下一个方向
                d++;
        } // 次循环，方向变换，4个方向均试探完毕则到栈顶的位置重新开始试探

    } //主循环，坐标移动
    cout << "No Way!" << endl;
}

int main()
{
    int mg[M + 2][N + 2] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1, 1, 0, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    Path(1, 1, 8, 8, mg);
    return 0;
}