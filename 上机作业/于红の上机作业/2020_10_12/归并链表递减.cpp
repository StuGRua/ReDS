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
    LinkNode<T>*head, *tail,*headA,*tailA,*headC,*tailC; //表头和表尾指针
public:
    LinkList()
    {
        head = tail = NULL;
        headA = tailA =NULL;
        headC = tailC =NULL;
    }
    ~LinkList()
    {
        clear();
    }
    void createLink(); // 以表尾添加结点的方式构建链表
    int getSize() const; //返回链表中的元素个数
    bool isEmpty() const; //链表是否为空
    void clear(); //清空链表：释放所有结点的内存空间

    int findNode(const T& value); // 查找值为value的结点，返回第一个值为value的结点位置，若不存在返回-1
    void deleteValue(const T& value); // 删除所有值为value的结点
    LinkNode<T>* setPos(int pos); //返回指定位置pos的指针
    bool insertPos(const int i, const T value); //在指定位置插入结点
    bool deletePos(const int i); // 删除指定位置的结点
    int reFindPos(const int K); // 查找倒数第K个结点
    void printList(); //输出链表

    void createLinkC();
    void createLinkR();
    void printListR();
    void printListC();
    void insertTohead(const T&value);
    void mergeLists();//归并
};

/*
TODO:1.2-a 以表尾添加结点的方式构建链表,输入为0时，链表构建结束。
 */
template <class T>
void LinkList<T>::createLink()
{
    LinkNode<T>* s = new LinkNode<T>;
    LinkNode<T>* p;
    this->head = s;
    this->tail = s;
    this->tail->link = NULL;
    cout << "第一个链表，输入以 0 为结束" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //输入为0时，链表构建结束
    {
        //TODO:构建链表
        LinkNode<T> *temp = new LinkNode<T>(value);
        tail->link = temp;
        temp->link = NULL;
        tail=temp;
        cin >> value;

    }
}

template <class T>
void LinkList<T>::createLinkR()
{
    LinkNode<T>* s = new LinkNode<T>;
    LinkNode<T>* p;
    this->headA = s;
    this->tailA = s;
    this->tailA->link = NULL;
    cout << "另一个链表，输入以 0 为结束" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //输入为0时，链表构建结束
    {
        //TODO:构建链表
        LinkNode<T> *temp = new LinkNode<T>(value);
        tailA->link = temp;
        temp->link = NULL;
        tailA=temp;
        cin >> value;

    }
}

template <class T>
void LinkList<T>::createLinkC()
{
    LinkNode<T>* s = new LinkNode<T>;
    LinkNode<T>* p = new LinkNode<T>;
    this->headC = s;
    this->tailC = s;
    this->tailC->link = NULL;

}

//返回链表中的元素个数
template <class T>
int LinkList<T>::getSize() const
{
    int count = 0;
    LinkNode<T>* p = head->link;
    if (isEmpty())
        return 0;
    while (p != NULL) {
        p = p->link;
        count++;
    }
    return count;
}

//链表是否为空
template <class T>
bool LinkList<T>::isEmpty() const
{
    if (head->link == NULL) {
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
int LinkList<T>::findNode(const T& value)
{
    int count = 0;
    int flag=0;
    LinkNode<T>* p = head->link;
    while (p != NULL) {
        if (p->data==value) {
            flag=1;
            break;
        }  
        p = p->link;
        count++;
         
    }
    if (getSize()==count&&flag==0)
    {
        count=-1;
    }
    
    return count;
}


template <class T>
void LinkList<T>::deleteValue(const T& value)
{
    LinkNode<T> * p=head,*previous = NULL,*nxt=NULL;
        while (head->data==value) {
            nxt = head->link;
            delete head;
            head = nxt;
    }
    p = head->link;
    previous = head;
    while (p) {
        nxt = p->link;
        if(p->data ==value){
            previous->link = nxt;
            delete p;
            }else
                previous = p;
                p = nxt;
        }
    
}

//返回指定位置pos的指针
template <class T>
LinkNode<T>* LinkList<T>::setPos(int pos)
{
    if (pos == -1)
        return head;
    int count = 0;
    LinkNode<T>* p = this->head->link;
    while (p != NULL && count < pos) {
        p = p->link;
        count++;
    }
    return p;
}


template <class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
    LinkNode<T> *p,*q;
    if ((p=setPos(i-1))==NULL)
    {
        cout << "插入操作不允许" << endl;
        return false;
    }else{
        q = new LinkNode<T>();
        q->data=value;
        q->link=p->link;
        p->link=q;
        if (p==tail)
        {
            tail=q;
        }
        return true;
    }
}


template <class T>
bool LinkList<T>::deletePos(const int i)
{
    LinkNode<T> *p, *q;
    if ((p=setPos(i-1))==NULL||p==tail)
    {
        cout << "非法删除点" << endl;
        return false;
    } 
    q=p->link;
    if (q==tail)
    {
        tail=p;
        p->link=NULL;
        delete q;
    }else if(q!=NULL)
    {
        p->link=q->link;
        delete q;
    }
    
    return true;
}


template <class T>
int LinkList<T>::reFindPos(const int K)
{
    LinkNode<T> *p;
    if (K>getSize())
    {
        cout << "表长不够" << endl;
        return -1;
    }
    if (K<=0)
    {
        cout << "非法输入" << endl;
        return -1;
    }
    p=setPos(getSize()-K);
    return p->data;
    

}

template <class T>
void LinkList<T>::printList()
{
    LinkNode<T>* p = this->head->link;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

template <class T>
void LinkList<T>::printListR()
{
    LinkNode<T>* p = this->headA->link;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

template <class T>
void LinkList<T>::printListC()
{
    LinkNode<T>* p = this->headC->link;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

//头插
template <class T>
void LinkList<T>::insertTohead(const T&value)
{
	LinkNode<T> *p,*q;
	p=headC->link;
	q=new LinkNode<T>();
	q->data=value;
	q->link=p;
	headC->link=q;
}


//归并两链表
template<class T>
void LinkList<T>::mergeLists()
{
    LinkNode<T>*A, *B, *C;
    A=head->link;
    B=headA->link;
    C=headC->link;
    while (A&&B)
    {
        if (A->data<=B->data)
        {
            insertTohead(A->data);  
            A=A->link;
        }
        else
        {
            insertTohead(B->data);
            B=B->link;
        }

    }
    if (A)
    {
        while (A)
        {
            insertTohead(A->data);
            A=A->link;
        }
        
    }else
    {
        while (B)
        {
            insertTohead(B->data);
            B=B->link;
        }
    }
    
    
    free(headA);
    free(head);


}

int main()
{
    LinkList<int> l;
    l.createLink(); //创建链表
    l.printList();
    l.createLinkR();
    l.printListR();
    l.createLinkC();
    l.mergeLists();
    l.printListC();
    return 0;
}