/*1.2-a-f ����

	void createLink();				//1.2-a �Ա�β��ӽ��ķ�ʽ��������
	int findNode(const T& value);	//1.2-b ����ֵΪvalue�Ľ�㣬���ص�һ��ֵΪvalue�Ľ��λ�ã��������ڷ���-1
	void deleteValue(const T& value);//1.2-c ɾ������ֵΪvalue�Ľ��
	bool insertPos(const int i, const T value); //1.2-d ��ָ��λ�ò�����
	bool deletePos(const int i);				//1.2-e ɾ��ָ��λ�õĽ��
	int reFindPos(const int K);     //1.2-f ���ҵ�����K�����

*/
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
    int getSize() const; //���������е�Ԫ�ظ���
    bool isEmpty() const; //�����Ƿ�Ϊ��
    void clear(); //��������ͷ����н����ڴ�ռ�

    int findNode(const T& value); //1.2-b ����ֵΪvalue�Ľ�㣬���ص�һ��ֵΪvalue�Ľ��λ�ã��������ڷ���-1
    void deleteValue(const T& value); //1.2-c ɾ������ֵΪvalue�Ľ��
    LinkNode<T>* setPos(int pos); //����ָ��λ��pos��ָ��
    bool insertPos(const int i, const T value); //1.2-d ��ָ��λ�ò�����
    bool deletePos(const int i); //1.2-e ɾ��ָ��λ�õĽ��
    int reFindPos(const int K); //1.2-f ���ҵ�����K�����
    void printList(); //�������
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
    cout << "������ 0 Ϊ����" << endl;
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

/*
TODO:1.2-b ����ֵΪvalue�Ľ�㣬���ص�һ��ֵΪvalue�Ľ��λ�ã��������ڷ���-1��
���磺�����һ��Ԫ�ؾ���value���򷵻�0����������
����ֵ˵�������ص�һ��ֵΪvalue�Ľ��λ�ã��������ڷ���-1��
 */
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

/*
TODO:1.2-c ɾ������ֵΪvalue�Ľ��

 */
template <class T>
void LinkList<T>::deleteValue(const T& value)
{
    LinkNode<T> *p = head, *previous = NULL, *nxt = NULL;
    while (head->data == value)
    {
        nxt = head->link;
        delete head;
        head = nxt;
    }
    p = head->link;
    previous = head;
    while (p)
    {
        nxt = p->link;
        if (p->data == value)
        {
            previous->link = nxt;
            delete p;
        }
        else
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

/*
TODO:.2-d ��ָ��λ��i����ֵΪvalue�Ľ�㣬���磺iΪ0����ʾ������ͷ������
����ֵ˵��������ɹ����룬�򷵻�true�����򣬷���false��
ע�������������λ��i�Ƿ�����λ��i�����ܽ��в�����������ӡcout << "�������������" << endl;������false��
 */
template <class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
    LinkNode<T> *p, *q;
    if ((p = setPos(i - 1)) == NULL)
    {
        cout << "�������������" << endl;
        return false;
    }
    else
    {
        q = new LinkNode<T>();
        q->data = value;
        q->link = p->link;
        p->link = q;
        if (p == tail)
        {
            tail = q;
        }
        return true;
    }    
}

/*
TODO:1.2-e ɾ��ָ��λ��i���Ľ��
����ֵ˵�����ɹ�ɾ����㣬�򷵻�true�����򷵻�false��
ע��������λ��i��û��Ԫ�أ����ӡcout << "�Ƿ�ɾ����" << endl;������false
 */
template <class T>
bool LinkList<T>::deletePos(const int i)
{
    LinkNode<T> *p, *q;
    if ((p = setPos(i - 1)) == NULL || p == tail)
    {
        cout << "�Ƿ�ɾ����" << endl;
        return false;
    }
    q = p->link;
    if (q == tail)
    {
        tail = p;
        p->link = NULL;
        delete q;
    }
    else if (q != NULL)
    {
        p->link = q->link;
        delete q;
    }

    return true;
}

/*
TODO:1.2-f ���ҵ�����K�����,����������ֵ�����磺KΪ1����ʾҪ���ҵ�Ԫ���ǵ�����1����Ҳ�����������һ��Ԫ��
����ֵ˵��������鵽��������K����㣬�򷵻�����ֵ�����򷵻�-1
ע�����1����������K�Ƿ�����С�ڵ���0�����ӡcout << "�Ƿ�����" << endl;������-1
         2����������K�Ƿ��������������ȣ����ӡcout << "������" << endl;������-1
 */
template <class T>
int LinkList<T>::reFindPos(const int K)
{
    LinkNode<T> *p;
    if (K > getSize())
    {
        cout << "������" << endl;
        return -1;
    }
    if (K <= 0)
    {
        cout << "�Ƿ�����" << endl;
        return -1;
    }
    p = setPos(getSize() - K);
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

int main()
{
    LinkList<int> l;
    l.createLink(); //��������
    l.printList();
    int value0, value1, value2, pos0, pos1, pos2;
    cin >> value0 >> value1 >> value2 >> pos0 >> pos1 >> pos2;
    cout << "ֵΪ" << value0 << "�Ľ��λ�ã�" << l.findNode(value0) << endl;
    l.deleteValue(value1); //ɾ��ֵΪvalue1�Ľ��
    l.printList();
    l.insertPos(pos0, value2); //��pos0������ֵΪvalue2�Ľ��
    l.printList();
    l.deletePos(pos1); //ɾ��pos1����Ԫ��
    l.printList();
    cout << "������" << pos2 << "������ֵ" << l.reFindPos(pos2) << endl; //���ҵ�����pos2����ʾ��λ�ô���Ԫ��
    return 0;
}