/*
   本测试题目目标是巩固单链表的相关操作
   请大家完成有todo注释的成员函数的定义,相应功能已经注释
   根据main中的提示的测试步骤来完成各个成员函数的测试

    循序渐进,提升编程信心,完善设计思维
*/

#include <iostream>
using namespace std;
/* 栈定义开始  */

template <class T>
class Stack
{
public:
	Stack(int MaStackSize = 10);
	~Stack() { delete[] stack; }
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == MaxTop; }
	T Top() const;
	bool push(const T &x);
	bool pop(T &x);
	void MakeEmpty() { top = -1; } //清空栈
private:
	int top;	//栈顶
	int MaxTop; //最大的栈顶值
	T *stack;   //堆栈元素数组
};
template <class T>
Stack<T>::Stack(int MaxStackSize)
{
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;
}

template <class T>
T Stack<T>::Top() const
{
	if (IsEmpty())
	{
		//cout << "no element\n";
		return -1;
	}
	else
		return stack[top];
}
template <class T>
bool Stack<T>::push(const T &x)
{
	if (IsFull())
	{
		cout << "no memory;" << endl;
		return false;
	}
	top = top + 1;
	stack[top] = x;
	return true;
}
template <class T>
bool Stack<T>::pop(T &x)
{
	if (IsEmpty())
	{
		cout << "no element\n"
			 << endl;
		return false;
	}
	x = stack[top];
	top = top - 1;
	return true;
}
/*  栈定义结束   */
//////////////////////////////////////////////////////////////
/*  链表定义开始  */
class Node //定义结点类型
{
public:
	int data;					 //存放数据
	Node *next;					 //存放后继结点地址
	Node(int val, Node *ptr = 0) //构造函数,初始化数据成员
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node *head; //记录表头结点地址

	List()
	{
		head = new Node(0, 0); //构造带有表头结点的空的单向链表
	}
	void insertToHead(int x)
	{
		//向表头插入数据值为x的结点
		Node *newNode = new Node(x, 0);
		newNode->next = head->next;
		head->next = newNode;
	}

	~List()
	{
		//todo: 1-释放链表的所有结点
		Node *p;
		while (head != NULL)
		{
			p = this->head;
			head = this->head->next;
			delete p;
		}
		head = NULL;
	}
	void print()
	{
		// todo: 2-依次输出链表的各个结点的数据值
		Node *p = this->head->next;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	void moveMinToFirst()
	{
		//todo:3-将链表中数据域值最小的那个链结点移到链表的最前面。
		//要求：不得额外申请新的链结点
		Node *pre = head, *p = NULL, *nxt = NULL;
		for (int i = 0; i < FindMinPos(); i++)
		{
			pre = pre->next;
		}
		p = pre->next;
		nxt = p->next;
		pre->next = nxt;
		p->next = head->next;
		head->next = p;
	}
	void delItem(int val)
	{
		//todo:4-删除第一个数据值为val的结点
		Node *p = head, *previous = NULL, *nxt = NULL;
		p = head->next;
		previous = head;
		while (p)
		{
			nxt = p->next;
			if (p->data == val)
			{
				previous->next = nxt;
				delete p;
				break;
			}
			else
				previous = p;
			p = nxt;
		}
	}
	void reverse()
	{
		//todo:5-利用栈将单链表的结点反转
		Node *p = head->next;
		Stack<int> tmp;
		int ttp;
		while (p)
		{
			tmp.push(p->data);
			p = p->next;
		}
		head->next = NULL;
		p = head;
		while (tmp.Top() != -1)
		{
			tmp.pop(ttp);
			Node *newNode = new Node(ttp, 0);
			p->next = newNode;
			p = newNode;
		}
	}

	bool isEmpty()
	{
		if (head->next == NULL)
		{
			return true;
		}
		return false;
	}

	int FindMinPos()
	{
		int min = head->next->data;
		int _Pos = 0;
		int _TPos = 0;
		Node *p = head->next;
		if (isEmpty())
		{
			return -1;
		}
		while (p != NULL)
		{
			if (p->data < min)
			{
				min = p->data;
				_TPos = _Pos;
			}
			p = p->next;
			_Pos++;
		}
		return _TPos;
	}
};
/*  链表定义结束  */
////////////////////////////////////////

/* main测试开始  */
int main()
{
	List mylist;

	//必须补充: 循环调用insertToHead方法向mylist中添加数据
	for (int i = 0; i < 9; i++)
	{
		mylist.insertToHead(i);
	}

	/* 下面开始测试各个成员函数,
	可以在实现每个测试目标的时候注释掉为完成其他测试目标而添加的代码*/

	//测试目标1: 测试析构函数----不需添加任何代码

	//测试目标2:测试print方法
	mylist.print();
	//测试目标3:测试 moveMinToFirst方法,执行 moveMinToFirst后利用print输出结果来查看
	mylist.moveMinToFirst();
	mylist.print();
	//测试目标4:测试delItem方法,执行 delItem后利用print输出结果来查看
	mylist.delItem(3);
	mylist.print();
	//测试目标5:测试reverse方法,执行reverse后利用print输出结果来查看
	mylist.reverse();
	mylist.print();
	return 0;
}
/* main测试结束  */