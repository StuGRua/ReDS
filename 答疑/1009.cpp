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
    int getSize() const; //返回链表中的元素个数
    bool isEmpty() const; //链表是否为空
    void clear(); //清空链表：释放所有结点的内存空间

    int findNode(const T& value); //1.2-b 查找值为value的结点，返回第一个值为value的结点位置，若不存在返回-1
    void deleteValue(const T& value); //1.2-c 删除所有值为value的结点
    LinkNode<T>* setPos(int pos); //返回指定位置pos的指针
    bool insertPos(const int i, const T value); //1.2-d 在指定位置插入结点
    bool deletePos(const int i); //1.2-e 删除指定位置的结点
    int reFindPos(const int K); //1.2-f 查找倒数第K个结点
    void printList(); //输出链表
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
    cout << "输入以 0 为结束" << endl;
    T value;
    cin >> value;
    while (value != 0 && value != '0') //输入为0时，链表构建结束
    {
        //TODO:构建链表
        LinkNode<T> *p1=new LinkNode<T>(value);
        tail->link=p1;
        p1->link=NULL;
        tail=p1;

        cin >> value;
    }
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

/*
TODO:1.2-b 查找值为value的结点，返回第一个值为value的结点位置，若不存在返回-1。
比如：假如第一个元素就是value，则返回0，依次类推
返回值说明：返回第一个值为value的结点位置，若不存在返回-1。
 */
template <class T>
int LinkList<T>::findNode(const T& value)
{
    int cnt=0;
 
    LinkNode<T> *p=head->link; 
    while(p!=NULL){
        if(p->data==value){
            
            return cnt;
            
        }cnt++;
        p=p->link;
        
    }
   
        return -1;
    }

/*
TODO:1.2-c 删除所有值为value的结点

 */
template <class T>
void LinkList<T>::deleteValue(const T& value)
{         
    int cnt=0;
    LinkNode<T> *p=head->link,*q=NULL; 
    while(p){
	    q=setPos(cnt-1);
        if(p->data==value){
          if(p!=tail){
                q->link=p->link;
                //delete p;
            }
            else {
                tail=q; 
                q->link=NULL; 
                //delete p;
            }
            
        }
        p=p->link;
		cnt++;
        
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

/*
TODO:.2-d 在指定位置i插入值为value的结点，比如：i为0，表示在链表头部插入
返回值说明：如果成功插入，则返回true，否则，返回false。
注意事项：假如插入的位置i非法，即位置i处不能进行插入操作，则打印cout << "插入操作不允许" << endl;并返回false。
 */
template <class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
    LinkNode<T> *p,*q;
    if ((p=setPos(i-1))==NULL){
        cout << "插入操作不允许" << endl;
        return false;

    }
    q=new LinkNode<T>(value);
    q->link=p->link;//漏了新加入的链接了
    p->link=q;
    
    if(p==tail){
        tail=q;

    }
    return true;
}

/*
TODO:1.2-e 删除指定位置i处的结点
返回值说明：成功删除结点，则返回true，否则返回false。
注意事项：如果位置i处没有元素，则打印cout << "非法删除点" << endl;并返回false
 */
template <class T>
bool LinkList<T>::deletePos(const int i)
{
    LinkNode<T> *p,*q;
    if((p=setPos(i-1))==NULL|| p==tail ){
        cout << "非法删除点" << endl;
        return false;
    }
    q=p->link;
    if(q==tail){
        tail=p;
        p->link=NULL;
        delete q;

    }
    else if (q!=NULL){
        p->link=q->link;
        delete q;
    }
    return true;
}

/*
TODO:1.2-f 查找倒数第K个结点,并返回它的值。比如：K为1，表示要查找的元素是倒数第1个，也即是链表最后一个元素
返回值说明：如果查到到倒数第K个结点，则返回它的值，否则返回-1
注意事项：1）如果输入的K非法，即小于等于0，则打印cout << "非法输入" << endl;并返回-1
         2）如果输入的K非法，即大于链表长度，则打印cout << "表长不够" << endl;并返回-1
 */
template <class T>
int LinkList<T>::reFindPos(const int K)
{
    LinkNode<T> *p;
    if(K<0||K==0){
        cout << "非法输入" << endl;
        return -1;
    }
    if(K>getSize()){
        cout << "表长不够" << endl;
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

int main()
{
    LinkList<int> l;
    l.createLink(); //创建链表
    l.printList();
    int value0, value1, value2, pos0, pos1, pos2;
    cin >> value0 >> value1 >> value2 >> pos0 >> pos1 >> pos2;
    cout << "值为" << value0 << "的结点位置：" << l.findNode(value0) << endl;
    l.deleteValue(value1); //删除值为value1的结点
    l.printList();
    l.insertPos(pos0, value2); //在pos0处插入值为value2的结点
    l.printList();
    l.deletePos(pos1); //删除pos1处的元素
    l.printList();
    cout << "倒数第" << pos2 << "个结点的值" << l.reFindPos(pos2) << endl; //查找倒数第pos2所表示的位置处的元素
    return 0;
}