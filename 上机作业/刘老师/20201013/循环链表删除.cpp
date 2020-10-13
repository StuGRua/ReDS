#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //数据域
    LinkNode<T>* prior; //指向后继指针的结点
    LinkNode<T>* next; //前驱
    LinkNode();
    LinkNode(T _data, LinkNode<T> *_prior,LinkNode<T> *_next );
};

template <class T>
LinkNode<T>::LinkNode()
{
    prior=NULL;
    next=NULL;
}

template <class T>
LinkNode<T>::LinkNode(T _data, LinkNode<T> *_prior,LinkNode<T> *_next )
{
    prior=_prior;
    next=_next;
    data=_data;
}

template <class T>
class DoubleList
{
    int length;
    LinkNode<T> *head;
public:
    DoubleList();
    DoubleList(const T _data[],int n);
    void printL();
    void Delete(int pos);
    int FindByVal(const T& e);
    int Search(int pos);
    void FindDel(const T&f);
    void Change();
    //void ExChange(const T&m,const T&n);
    void Insert(const T _data, int pos);
    
};

template <class T>
DoubleList<T>::DoubleList()
{
    head=new LinkNode<T>;
    assert(head);
    head->prior=head;
    head->next=head;
    length=0;
}

template <class T>
DoubleList<T>::DoubleList(const T _data[], int n)
{
	head = new LinkNode<T>; //动态分配一个空结点，即头节点
	LinkNode<T> *p = head;//创建一个指向结点的指针p后面将用这个指针遍历，实现不断的加数据结点
	for (int i = 0; i < n; i++) {
		//step1 :new运算符建立下一个结点 且通过构造函数将数据域赋值为data_[i] 
		//step2:通过构造函数将该结点的首指针指向p（即上一个节点） 尾指针指向NULL
		//step3:通过赋值运算符将上一个结点的尾指针指向下一个结点
		//step4 将指针p移动至下一个结点 以便下一步的迭代
		p->next = new LinkNode<T>(_data[i], p,NULL);
		p = p->next;
	}
	length = n;
	p->next = head;
	head->prior = p;
}

template <class T>
void DoubleList<T>::printL()
{
    LinkNode<T>*p = head;
    for (int i = 0; i < length; i++)
    {
        p=p->next;
        cout << p->data << "" "";
    }
    cout << endl;
}

template <class T>
void DoubleList<T>::Delete(int pos)
{
	LinkNode<T> *p = head;

	if (pos<1 || pos>length)
	{
		cout << "false" << endl;
	}
	else
	{
		int i;
		for(i = 0; i < pos; i++)
		{
			p = p->next;
		}

		p->prior->next = p->next;
		p->next->prior = p->prior;
		length = length - 1;
		delete p;
	}
}

template <class T>
void DoubleList<T>::Insert(const T _data, int pos)
{
	//step0:准备工作 建立要遍历的指针p和新建要插入的数据结点add
	LinkNode<T> *p = head;//创建一个指向结点的指针p后面将用这个指针遍历
	LinkNode<T> *add = new LinkNode<T>(_data, NULL, NULL);//建立一个新结点，包含要插入的数据data_
	//step1:判断插入位置是否正确
	if (pos<1 || pos>length+1)
	{
		cout << "falseINSERT" << endl;
	}
	
	else
	{
		//step2,用指针p进行遍历，直到达到指定位置
		int i;
		for(i = 0; i < pos; i++)
		{
			p = p->next;
		}
		//step3 ,开始插入
		add->prior = p->prior;
		p->prior->next = add;
		p->prior = add;
		add->next = p;
		length += 1;
	}
 
}

template <class T>
int DoubleList<T>::FindByVal(const T& e)
{
    int i=0;
	LinkNode<T> *p = head;
    while ((i<length)&&(p->data!=e))
    {
        i++;
        p=p->next;
    }
    if (p==head)
    {
        return 0;
    }else
    {
        //cout << i << endl;
        return i;
    }
}

template <class T>
int DoubleList<T>::Search(int pos)
{
	//step0:准备工作 建立要遍历的指针p
	LinkNode<T> *p = head;//创建一个指向结点的指针p后面将用这个指针遍历
	//step1:判断查找位置是否正确
	if (pos<1 || pos>length)
	{
		std::cout << "NtFind" << endl;
		return 0;
	}
	else
	{
		int i;
		for(i = 0; i < pos; i++)
		{
			p = p->next;
		}
		//step2:返回查找数据
		return p->data;
		std::cout << "Find" << endl;
 
	}
}
template <class T>
void DoubleList<T>::FindDel(const T&f)
{
    Delete(FindByVal(f));  
}

template <class T>
void DoubleList<T>::Change()
{
    for (int i = 2,j=length; i < (length/2)+2; i++,j--)
    {
        int temp1=Search(i);
        Insert(temp1,j+1);
        Delete(i); 
    }
    

}

/*template <class T>
void DoubleList<T>::ExChange(const T&m,const T&n)
{

}*/
int main()
{
    int data[10]={1,2,3,4,5,6,7,8,9,10};
    int val;
    DoubleList<int> D(data,10);
    D.printL();
    //cin >> val;
    val=10;
    D.FindDel(val);
    D.printL();
    D.Change();
    D.printL();
    //D.FindByVal(4);
    
}