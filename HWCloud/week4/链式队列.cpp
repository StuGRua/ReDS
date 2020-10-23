#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //数据域
    LinkNode<T>* link; //指向后继指针的结点
    LinkNode(const T& el)
    {
        data = el;
        link = NULL;
    }
};
template <class T>
class LinkQueue {
private:
    int size;
    LinkNode<T>* front;
    LinkNode<T>* rear;

public:
    LinkQueue()
    {
        size = 0;
        front = rear = NULL;
    }

    ~LinkQueue()
    {
        //Clear();
    }
    //清空队列
    void Clear()
    {
        while (front != NULL) {
            rear = front;
            front = front->link;
            delete rear;
        }
        rear = NULL;
        size = 0;
    }

    bool IsEmpty()
    {
        if (size == 0) {
            cout << "队列为空" << endl;
            return true;
        }
        return false;
    }
    /*
	TODO：将item入队，插入到队尾，并返回true。
	 */
    bool EnQueue(const T item)
    {
		if(rear == NULL)
		{
			front = rear = new LinkNode<T>(item);
		}
		else
		{
			rear->link = new LinkNode<T>(item);
			rear = rear->link;
		}
		size++;
		return true;        
    }

    /*
	TODO：读取对头元素,将其赋值给item变量，并将其从队列中删除掉
	返回值说明：如果队列为空，则返回false，否则返回true
	 */
    bool DeQueue(T& item)
    {
        LinkNode<T> * temp;
		if(IsEmpty())
		{
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

    /*
	TODO：取出队头元素赋值给item，但不删除它。
    返回值说明：如果队列为空，则无法取出元素，此时返回false。
    			否则返回true
	 */
    bool GetFront(T& item)
    {
        if(IsEmpty())
		{
			return false;
		}
		item = front->data;
		return true;
    }
};

int main()
{
    LinkQueue<int> lq;
    int iLoop1, iLoop2; //用于控制入队和出队的次数
    cin >> iLoop1 >> iLoop2;
    for (int i = 0; i < iLoop1; i++) {
        lq.EnQueue(i + 1000);
    }

    int temp, temp1 = -9999, temp2 = -9999;
    cout << "输入一个入队元素：";
    cin >> temp;
    lq.EnQueue(temp);
    for (int i = 0; i < iLoop2; i++) {
        lq.DeQueue(temp1);
    }

    cout << "出队：" << temp1 << endl;
    lq.GetFront(temp2);
    cout << "读取队头元素：" << temp2 << endl;
    return 0;
}