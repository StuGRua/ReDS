/*课后习题1.8-h

	h.	假设表达式中允许包含3中括号：圆括号、方括号和大括号。
		设计一个算法采用顺序栈判断表达式中的括号是否正确配对。
		void Bracketmatch(const char* c)

*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
class stack
{
private:
    int maxsize;
    int top;
    char *st;

public:
    stack(int size)
    {
        maxsize = size;
        top = -1;
        st = new char[maxsize];
    }

    void push(char item)
    {
        st[++top] = item;
        //cout << "In:" << item << endl;
    }

    char top1()
    {
        return st[top];
    }

    void pop()
    {
        top--;
        //cout << "Out:" << st[top] << endl;
    }

    bool empty()
    {
        return top == -1;
    }
};
/*
TODO:计一个算法采用顺序栈判断表达式c中的括号是否正确配对。
输出：1. 遍历表达式c过程中，匹配错误 cout << c[i] << "  匹配错误" << endl;
      2. 遍历之后，栈为空，则匹配正确，cout << "匹配正确！" << endl;
               若不为空，则  cout << s1.top1() << "  匹配错误" << endl;
 */
void Bracketmatch(const char *c) //括号匹配
{
    stack s1(20);
    int i = 0;
    int flag = 1;
    for (; i < strlen(c); i++)
    {
        if (c[i] == '(' || c[i] == '[' || c[i] == '{')
        {
            s1.push(c[i]);
        }
        else if (c[i] == ')' && !s1.empty() && s1.top1() == '(')
            s1.pop();
        else if (c[i] == ')' && !s1.empty() && s1.top1() != '(')
        {
            cout << c[i] << "  匹配错误" << endl;
            flag = 0;
            break;
        }
        else if (c[i] == ']' && !s1.empty() && s1.top1() == '[')
            s1.pop();
        else if (c[i] == ']' && !s1.empty() && s1.top1() != '[')
        {
            cout << c[i] << "  匹配错误" << endl;
            flag = 0;
            break;
        }
        else if (c[i] == '}' && !s1.empty() && s1.top1() == '{')
            s1.pop();
        else if (c[i] == '}' && !s1.empty() && s1.top1() != '{')
        {
            cout << c[i] << "  匹配错误" << endl;
            flag = 0;
            break;
        }
        else if ((c[i] == ')' || c[i] == ']' || c[i] == '}') && s1.empty())
        {
            cout << c[i] << "  匹配错误" << endl;
            flag = 0;
            break;
        }
    }
    if (flag != 0)
    {
        if (!s1.empty())
            cout << s1.top1() << "  匹配错误" << endl;
        else if (i =strlen(c) - 1 && s1.empty())
        {
            cout << "匹配正确！" << endl;
        }
    }
    //cout<<"Round "<<i<<" of " <<strlen(c) <<endl;
}

int main()
{

    string s;
    getline(cin, s);
    Bracketmatch(s.c_str());
    return 0;
}
