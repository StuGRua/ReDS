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
    LinkNode<T>*head, *tail; //��ͷ�ͱ�βָ��
public:
    LinkList()
    {
        head = tail = NULL;
    }
    ~LinkList()
    {
        clear();
    }
    void createLink(); //1.2-a �Ա�β��ӽ��ķ�ʽ��������
    
    bool isEmpty() const; //�����Ƿ�Ϊ��
    void clear(); //��������ͷ����н����ڴ�ռ�

    int findNode(const T& value); //1.2-b ����ֵΪvalue�Ľ�㣬���ص�һ��ֵΪvalue�Ľ��λ�ã��������ڷ���-1
    void deleteValue(const T& value); //1.2-c ɾ������ֵΪvalue�Ľ��
    void printList(); //�������

    void reList();

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
    cout << "input 0 to end" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //����Ϊ0ʱ������������
    {
        if (!head->data)
        {
            head->data=value;
        }
        
        //TODO:��������
        LinkNode<T> *temp = new LinkNode<T>(value);
        tail->link = temp;
        temp->link = NULL;
        tail=temp;
        cin >> value;

    }
}



//�����Ƿ�Ϊ��
template <class T>
bool LinkList<T>::isEmpty() const
{
    if (head->link == NULL&&!(head->data)) {
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
void LinkList<T>::printList()
{
    LinkNode<T>* p = this->head->link;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}

//��ת������
template <class T>
void LinkList<T>::reList()
{

    LinkNode<T> *res,*first,*temp,*p;
    res = new LinkNode<T>(0);
    res->link = head;
 
    first = res->link;       //first ʼ��Ϊ��һ����㣬���Ϻ���
    while(first->link!=NULL) //tempΪ��ǰ���
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



int main()
{
    LinkList<int> l;
    l.createLink(); //��������
    l.printList();
    l.reList();
    l.printList();



    //int value0, value1, value2, pos0, pos1, pos2;
    //cin >> value0 >> value1 >> value2 >> pos0 >> pos1 >> pos2;
    //cout << "ֵΪ" << value0 << "�Ľ��λ�ã�" << l.findNode(value0) << endl;
    //l.deleteValue(value1); //ɾ��ֵΪvalue1�Ľ��
    //l.printList();
    //l.insertPos(pos0, value2); //��pos0������ֵΪvalue2�Ľ��
    //l.printList();
    //l.deletePos(pos1); //ɾ��pos1����Ԫ��
    //l.printList();
    //cout << "������" << pos2 << "������ֵ" << l.reFindPos(pos2) << endl; //���ҵ�����pos2����ʾ��λ�ô���Ԫ��
    return 0;
}