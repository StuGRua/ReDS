#include <iostream>
#include "LinkQueue.h"

using namespace std;

void Triangle(int n)
{
    LinkQueue<int> q;
    int s, t;//s,t为读取和修改队列缓存，s+t计算输出系数
    q.EnQueue(1);//第一行
    q.EnQueue(1);
    cout << 1 << "\t" << 1;
    for (int i = 2; i <= n; i++)
    {
        cout << endl;
        q.EnQueue(1);//每一行首位都是1
        cout << 1 << "\t";//每一行首位都是1
        q.DeQueue(s);//s向前读取一位
        for (int j = 2; j <= i; j++)//从每行第二位开始计算，每次计算都更新队列中的值，正在生成的第i行对应i+1元素和i-1次计算
        {
            q.DeQueue(t); //t为第i-1行第j个元素的值
            q.EnQueue(s + t); //s+t为第i行第j个元素的值，压栈更新值
            cout << s + t << "\t";//ai数值为ai+a(i-1)
            s = t;//s前进一位，t下一次循环中前进一位
        }
        q.EnQueue(1);//每一行末位都是1
        cout << 1;//每一行末位都是1
    }
    cout << endl;
}
int main()
{
    int i;
    cout << "enter i(i>=1) in (a+b)^i" << endl;
    cin >> i;
    if (i<1) exit(1);
    cout << "Result:" <<endl;
    Triangle(i);
    return 0;
}