#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //������
    LinkNode<T>* link; //ָ����ָ��Ľ��
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
    LinkNode<T>*head, *tail,*headA,*tailA,*headC,*tailC; //��ͷ�ͱ�βָ��
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
    void createLink(); // �Ա�β��ӽ��ķ�ʽ��������
    int getSize() const; //���������е�Ԫ�ظ���
    bool isEmpty() const; //�����Ƿ�Ϊ��
    void clear(); //��������ͷ����н����ڴ�ռ�

    int findNode(const T& value); // ����ֵΪvalue�Ľ�㣬���ص�һ��ֵΪvalue�Ľ��λ�ã��������ڷ���-1
    void deleteValue(const T& value); // ɾ������ֵΪvalue�Ľ��
    LinkNode<T>* setPos(int pos); //����ָ��λ��pos��ָ��
    bool insertPos(const int i, const T value); //��ָ��λ�ò�����
    bool deletePos(const int i); // ɾ��ָ��λ�õĽ��
    int reFindPos(const int K); // ���ҵ�����K�����
    void printList(); //�������

    void createLinkC();
    void createLinkR();
    void printListR();
    void printListC();
    void insertTohead(const T&value);
    void mergeLists();//�鲢
};

/*
TODO:1.2-a �Ա�β��ӽ��ķ�ʽ��������,����Ϊ0ʱ��������������
 */
template <class T>
void LinkList<T>::createLink()
{
    LinkNode<T>* s = new LinkNode<T>;
    LinkNode<T>* p;
    this->head = s;
    this->tail = s;
    this->tail->link = NULL;
    cout << "��һ������������ 0 Ϊ����" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //����Ϊ0ʱ������������
    {
        //TODO:��������
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
    cout << "��һ������������ 0 Ϊ����" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //����Ϊ0ʱ������������
    {
        //TODO:��������
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

//���������е�Ԫ�ظ���
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

//�����Ƿ�Ϊ��
template <class T>
bool LinkList<T>::isEmpty() const
{
    if (head->link == NULL) {
        return true;
    }
    return false;
}

//��������ͷ����н����ڴ�ռ�
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

//����ָ��λ��pos��ָ��
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
        cout << "�������������" << endl;
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
        cout << "�Ƿ�ɾ����" << endl;
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
        cout << "������" << endl;
        return -1;
    }
    if (K<=0)
    {
        cout << "�Ƿ�����" << endl;
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

//ͷ��
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


//�鲢������
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
    l.createLink(); //��������
    l.printList();
    l.createLinkR();
    l.printListR();
    l.createLinkC();
    l.mergeLists();
    l.printListC();
    return 0;
}