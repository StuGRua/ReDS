#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //数据域
    LinkNode<T>* link; //指向后继指针的结点
    LinkNode()
    {
        data = 0;
        link = NULL;
    }
    LinkNode(const T& el)
    {
        data = el;
        link = NULL;
    }
};

template <class T>
class LinkList {
private:
    LinkNode<T>*head, *tail; //表头和表尾指针
public:
    LinkList()
    {
        head = tail = NULL;
    }
    ~LinkList()
    {
        clear();
    }
    void createLink(); //1.2-a 以表尾添加结点的方式构建链表
    
    bool isEmpty() const; //链表是否为空
    void clear(); //清空链表：释放所有结点的内存空间

    int findNode(const T& value); //1.2-b 查找值为value的结点，返回第一个值为value的结点位置，若不存在返回-1
    void deleteValue(const T& value); //1.2-c 删除所有值为value的结点
    void printList(); //输出链表

    void reList();
    void reDoList();
};

template <class T>
void LinkList<T>::createLink()
{
    LinkNode<T>* s = new LinkNode<T>;
    LinkNode<T>* p;
    this->head = s;
    this->tail = s;
    this->tail->link = NULL;
    cout << "input 0 to end" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //输入为0时，链表构建结束
    {
        if (!head->data)
        {
            head->data=value;
        }
        LinkNode<T> *temp = new LinkNode<T>(value);
        tail->link = temp;
        temp->link = NULL;
        tail=temp;
        cin >> value;

    }
}



//链表是否为空
template <class T>
bool LinkList<T>::isEmpty() const
{
    if (head->link == NULL&&!(head->data)) {
        return true;
    }
    return false;
}

//清空链表：释放所有结点的内存空间
template <class T>
void LinkList<T>::clear()
{
    LinkNode<T>* p;
    while (head != NULL) {
        p = this->head;
        head = this->head->link;
        delete p;
    }
    head = tail = NULL;
}




template <class T>
void LinkList<T>::printList()
{
    LinkNode<T>* p = this->head->link;
    cout<<"List:";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

//翻转单链表
template <class T>
void LinkList<T>::reList()
{

    LinkNode<T> *res,*first,*temp,*p;
    res = new LinkNode<T>(0);
    res->link = head;
 
    first = res->link;       //first 始终为第一个结点，不断后移
    while(first->link!=NULL) //temp为待前插的
        {
        temp = first->link;
        first->link = temp->link;
        temp->link = res->link;
        res->link = temp;          
    }
    p=res;
    while (p->link->link != NULL) {
        p = p->link;
    }
    p->link=NULL;
    head=res;
}

template <class T>
void LinkList<T>::reDoList()//思路:先把链表拆分成两部分，前一部分直接翻转，然后连接后一部分
{
    int size=0;
    LinkNode<T> *link1=head->link,*link2=head,*p;
    for (p=head;p->link!=NULL;p=p->link)//得到大小
    {
        size++;
    }
    for (int i = 0; i < size/2; i++)//指针指向区分点
    {
        link2=link2->link;
    }
    p->link=NULL;//断开链表
    head=link2;
    reList();
    for (p=head;p->link!=NULL;p=p->link);//指向连接点，连接两个分开的链表
    p->link=link1;
}


int main()
{
    LinkList<int> l;
    l.createLink(); //创建链表
    l.printList();
    l.reDoList();
    l.printList();
    return 0;
}