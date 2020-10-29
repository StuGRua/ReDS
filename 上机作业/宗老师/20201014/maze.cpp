#include <iostream>
#include <stack>
using namespace std;
#define M 8
#define N 8
const int XLEN = 10, YLEN = 10; // Ĭ���Թ�������������
int m, p;                       // ��������
int mark[XLEN][YLEN];           // ���ʱ������

struct Offsets
{
    int a, b; // a��b��x,y�����ƫ��
};

Offsets direction[4] = {
    {-1, 0}, // ��0
    {0, 1},  // ��1
    {1, 0},  // ��2
    {0, -1}  // ��3
};

struct items // ��㶨��
{
    int x, y, dir;
};

// ջ�㷨���������
void Path(int x, int y, int m, int n, int maze[M + 2][N + 2]) // x, yΪ�������;m,nΪ��������
{
    int i, j, g, h, d;
    stack<items> st; // ����ջ
    items tmp;

    mark[x][y] = 1; // x, y �����
    tmp.x = x, tmp.y = y;
    tmp.dir = 0;  // ��N����ʼ
    st.push(tmp); // ��������ջ
    while (!st.empty())
    {                   // ��ջ���գ�һֱ����ȥ
        tmp = st.top(); // ȡջ��Ԫ��
        cout << "testout:"<<tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
        st.pop();       // ��ջ
        i = tmp.x;
        j = tmp.y;   // ȡ�õ�ǰλ������
        d = tmp.dir; // ����
        while (d < 4)
        {
            // ����һλ�ã�g, h��
            g = i + direction[d].a;
            h = j + direction[d].b;
            if (g == m && h == n) // �������
            {
                tmp.x = i; //Ϊ���������·�������һ��ѹջ
                tmp.y = j;
                st.push(tmp);
                cout << "Found way:(reversed order)\nx, y, D" << endl;
                cout << m << ", " << n << ", " << '0' << "(End)" << endl;
                while (!st.empty()) // �������·��
                {                   // ���ջ�д��·��
                    tmp = st.top(); // ȡջ��Ԫ��
                    st.pop();       // ��ջ
                    cout << tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
                }
                exit(0);
            }

            if (maze[g][h] == 0 && mark[g][h] == 0) // ���ͨ��δ�����ʹ�(δ�������)
            {
                mark[g][h] = 1; // ���Ϊ�ѷ��ʹ�
                tmp.x = i;
                tmp.y = j;
                tmp.dir = d;  // �������߹���λ�ú�ǰ���ķ���
                st.push(tmp); // ��ջ
                cout << "testin:"<<tmp.x << ", " << tmp.y << ", " << tmp.dir << endl;
                i = g;
                j = h;
                d = 0; // �ƶ�����g, h��,�ظ������������̽�Ĺ���
            }
            else // ��̽��һ������
                d++;
        } // ��ѭ��������任��4���������̽�����ջ����λ�����¿�ʼ��̽

    } //��ѭ���������ƶ�
    cout << "No Way!" << endl;
}

int main()
{
    int mg[M + 2][N + 2] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1, 1, 0, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    Path(1, 1, 8, 8, mg);
    return 0;
}