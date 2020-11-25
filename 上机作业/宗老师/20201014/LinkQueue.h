#include <bits/stdc++.h>
using namespace std;
template<class T>
class LinkNode
{
	public:
		T data;							//������
		LinkNode<T>*link;				//ָ����ָ��Ľ��

		LinkNode(const T&el, LinkNode<T>*ptr = 0){	//���캯��
			data=el;
			link=ptr;
	}
};

template<class T>
class Queue
{
public:
	void Clear();                		//��ն���
	bool EnQueue(const T item); 	//���е�β������Ԫ��item
	bool DeQueue(T & item);     		//ȡ�����еĵ�һ��Ԫ�أ���ɾ��
	bool IsEmpty();             		//�ж϶����Ƿ�Ϊ��
	bool IsFull();              		//�ж϶����Ƿ�����
	bool GetFront(T & item);     	//��ȡ��ͷԪ�أ�����ɾ��
};

template<class T>
class LinkQueue:public Queue<T>
{
private:


public:
	int size;              		//�����е�ǰԪ�صĸ���
	LinkNode<T> * front;       	//��ʾ���е�ͷָ��
	LinkNode<T> * rear;         	//��ʾ���е�βָ��
	LinkQueue()        	//���캯�����������е�ʵ��
	{
		size = 0;
		front = rear = NULL;
	}

	~LinkQueue()               	//��������
	{
		Clear();
	}

	void Clear()             		//��ն���
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

	bool EnQueue(const T item)	//item��ӣ������β
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

	bool DeQueue(T & item) 		//��ȡ��ͷԪ�ز�ɾ��
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

	bool GetFront(T & item) 		//���ض�ͷԪ�أ�����ɾ��
	{
		if(size == 0)
		{
			cout << "empty" << endl;
			return false;
		}
		item = front->data;
		return true;
	}

	void show()//ɾ�������
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
void connect(LinkQueue<T>& a, LinkQueue<T>& b)//���Ӷ���
{
	if (b.front == nullptr)//bΪ���򷵻�
		return;
	if (a.front == nullptr)//aΪ����ֱ���滻
		a.front = b.front;
	else
		a.rear->link = b.front;//a��β����b����
	a.rear = b.rear;//β������
	a.size += b.size;//��С����
	b.front = b.rear = nullptr;//��������ʱ�ظ�delete
	b.size = 0;//ɾ��b
}