/*
   ��������ĿĿ���ǹ��̵��������ز���
   ���������todoע�͵ĳ�Ա�����Ķ���,��Ӧ�����Ѿ�ע��
   ����main�е���ʾ�Ĳ��Բ�������ɸ�����Ա�����Ĳ���

    ѭ�򽥽�,�����������,�������˼ά
*/

#include <iostream>
using namespace std;
/* ջ���忪ʼ  */

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
	void MakeEmpty() { top = -1; } //���ջ
private:
	int top;	//ջ��
	int MaxTop; //����ջ��ֵ
	T *stack;   //��ջԪ������
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
/*  ջ�������   */
//////////////////////////////////////////////////////////////
/*  �����忪ʼ  */
class Node //����������
{
public:
	int data;					 //�������
	Node *next;					 //��ź�̽���ַ
	Node(int val, Node *ptr = 0) //���캯��,��ʼ�����ݳ�Ա
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node *head; //��¼��ͷ����ַ

	List()
	{
		head = new Node(0, 0); //������б�ͷ���Ŀյĵ�������
	}
	void insertToHead(int x)
	{
		//���ͷ��������ֵΪx�Ľ��
		Node *newNode = new Node(x, 0);
		newNode->next = head->next;
		head->next = newNode;
	}

	~List()
	{
		//todo: 1-�ͷ���������н��
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
		// todo: 2-�����������ĸ�����������ֵ
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
		//todo:3-��������������ֵ��С���Ǹ�������Ƶ��������ǰ�档
		//Ҫ�󣺲��ö��������µ������
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
		//todo:4-ɾ����һ������ֵΪval�Ľ��
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
		//todo:5-����ջ��������Ľ�㷴ת
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
/*  ���������  */
////////////////////////////////////////

/* main���Կ�ʼ  */
int main()
{
	List mylist;

	//���벹��: ѭ������insertToHead������mylist���������
	for (int i = 0; i < 9; i++)
	{
		mylist.insertToHead(i);
	}

	/* ���濪ʼ���Ը�����Ա����,
	������ʵ��ÿ������Ŀ���ʱ��ע�͵�Ϊ�����������Ŀ�����ӵĴ���*/

	//����Ŀ��1: ������������----��������κδ���

	//����Ŀ��2:����print����
	mylist.print();
	//����Ŀ��3:���� moveMinToFirst����,ִ�� moveMinToFirst������print���������鿴
	mylist.moveMinToFirst();
	mylist.print();
	//����Ŀ��4:����delItem����,ִ�� delItem������print���������鿴
	mylist.delItem(3);
	mylist.print();
	//����Ŀ��5:����reverse����,ִ��reverse������print���������鿴
	mylist.reverse();
	mylist.print();
	return 0;
}
/* main���Խ���  */