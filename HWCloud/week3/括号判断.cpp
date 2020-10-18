/*课后习题1.8-h

	h.	假设表达式中允许包含3中括号：圆括号、方括号和大括号。
		设计一个算法采用顺序栈判断表达式中的括号是否正确配对。
		void Bracketmatch(const char* c)

*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
class stack {
private:
	int maxsize;
	int top;
	char* st;

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
	}

	char top1()
	{
		return st[top];
	}

	void pop()
	{
		top--;
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
void Bracketmatch(const char* c) //括号匹配
{
	stack z(strlen(c));
	bool err = 0;
	for (int i = 0; i < strlen(c); i++)//注意自动跳过非括号的元素
	{
		if (c[i] == '{' || c[i] == '[' || c[i] == '(')
		{
			z.push(c[i]);
		}
		if (c[i] == '}' || c[i] == ']' || c[i] == ')')
		{
			if ((c[i] == '}' && z.top1() == '{') || (c[i] == ']' && z.top1() == '[') || (c[i] == ')' && z.top1() == '('))//对应弹栈，弹不出来就是错的
			{
				z.pop();
			}
			else
			{
				cout << c[i] << "  匹配错误" << endl;
				err = 1;
				break;
			}
		}
	}
	if (err == 0 && z.empty())
	{
		cout << "匹配正确！" << endl;
	}
	else if (err == 0)
	{
		cout << z.top1() << "  匹配错误" << endl;
	}
}

int main()
{

	string s;
	getline(cin, s);
	Bracketmatch(s.c_str());
	return 0;
}
