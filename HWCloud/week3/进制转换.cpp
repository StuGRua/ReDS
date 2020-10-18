
/*课后习题1.8-g

		g.	设计算法把一个十进制整数转换为二至九进制之间的任意进制数输出。
			void Binaryconv(int n, int m)
*/
#include <iostream>
using namespace std;
class stack {
private:
    int maxsize;
    int top;
    int* st;

public:
    stack(int size)
    {
        maxsize = size;
        st = new int[maxsize];
        top = -1;
    }

    void push(int num)
    {
        st[++top] = num;
    }

    void pop()
    {
        int item;
        while (top != -1) {
            item = st[top--];
            cout << item;
        }
    }
};

/*
TODO:设计算法把一个十进制整数转换为二至九进制之间的任意进制数输出。
其中，n为要转换的10进制整数， m为进制，取值为2到9。
提示：利用栈解决
 */
void Binaryconv(int n, int m) //进制转换
{
    stack s(32);
    int temp = n;
    while (1)
    {
        s.push(temp % m);
        if (temp / m == 0)
        {
            break;
        }
        temp /= m;
    }
    cout << "整数" << n << "转成" << m << "进制后的结果是:";
    s.pop();
}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    Binaryconv(n, m);
    return 0;
}