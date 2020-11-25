#include <bits/stdc++.h>
using namespace std;
template<class T>
class LinkNode
{
	public:
		T data;							//数据域
		LinkNode<T>*link;				//指向后继指针的结点

		LinkNode(const T&el, LinkNode<T>*ptr = 0){	//构造函数
			data=el;
			link=ptr;
	}
};

template<class T>
class Queue
{
public:
	void Clear();                		//清空队列
	bool EnQueue(const T item); 	//队列的尾部加入元素item
	bool DeQueue(T & item);     		//取出队列的第一个元素，并删除
	bool IsEmpty();             		//判断队列是否为空
	bool IsFull();              		//判断队列是否已满
	bool GetFront(T & item);     	//读取队头元素，但不删除
};

template<class T>
class LinkQueue:public Queue<T>
{
private:


public:
	int size;              		//队列中当前元素的个数
	LinkNode<T> * front;       	//表示队列的头指针
	LinkNode<T> * rear;         	//表示队列的尾指针
	LinkQueue()        	//构造函数，创建队列的实例
	{
		size = 0;
		front = rear = NULL;
	}

	~LinkQueue()               	//析构函数
	{
		Clear();
	}

	void Clear()             		//清空队列
	{
		while(front != NULL)
		{
			rear = front;
			front = front->link;
			delete rear;
		}
		rear = NULL;
		size = 0;
	}

	bool EnQueue(const T item)	//item入队，插入队尾
	{
		if(rear == NULL)
		{
			front = rear = new LinkNode<T>(item, NULL);
		}
		else
		{
			rear->link = new LinkNode<T>(item, NULL);
			rear = rear->link;
		}
		size++;
		return true;
	}

	bool DeQueue(T & item) 		//读取队头元素并删除
	{
		LinkNode<T> * temp;
		if(size == 0)
		{
			cout << "empty" << endl;
			return false;
		}
		item = front->data;
		temp = front;
		front = front->link;
		delete temp;
		if(front == NULL)
		{
			rear = NULL;
		}
		size--;
		return true;
	}

	bool GetFront(T & item) 		//返回队头元素，但不删除
	{
		if(size == 0)
		{
			cout << "empty" << endl;
			return false;
		}
		item = front->data;
		return true;
	}

	void show()//删除并输出
	{
		T temp;
		while (getsize()) {
			DeQueue(temp);
			cout << temp << " ";
		}
		cout << endl;
		
	}
	
	bool IsEmpty()
	{
		if(size==0) return 1;
		else return 0;
	}	


	int getsize()
	{
		return size;
	}

};

template<typename T>
void connect(LinkQueue<T>& a, LinkQueue<T>& b)//连接队列
{
	if (b.front == nullptr)//b为空则返回
		return;
	if (a.front == nullptr)//a为空则直接替换
		a.front = b.front;
	else
		a.rear->link = b.front;//a队尾连接b队首
	a.rear = b.rear;//尾部更新
	a.size += b.size;//大小更新
	b.front = b.rear = nullptr;//避免析构时重复delete
	b.size = 0;//删除b
}