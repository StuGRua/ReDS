#include <iostream>
using namespace std;

template <class T>
class DLLNode {
public:
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;

    DLLNode(const T info, DLLNode<T>* prevVal = NULL, DLLNode<T>* nextVal = NULL)
    {
        data = info;
        prev = prevVal;
        next = nextVal;
    }
};

template <class T>
class DLLinkList {
public:
    DLLNode<T>*head, *tail;
    DLLinkList()
    {
        head = tail = NULL;
    }

    /*
	TODO: 在双链表的表尾插入值为num的DLLNode结点，注意考虑空链表场景的插入操作
	 */
    void Insert(const T& num)
    {
        if (head == NULL) {
            head = tail = new DLLNode<T>(num);
            head->next = NULL;
            tail->next = NULL;
        } else {
            DLLNode<T>* p = new DLLNode<T>(num);
            tail->next = p;
            p->prev = tail;
            tail = p;
            tail->next = NULL;
            //cout<<tail->data<<tail->prev->data<<endl;
        }
        
    }

    //构建双链表
    void createList()
    {
        cout << "输入链表，以0为结尾：";
        T i;
        cin >> i;
        while (i != 0 && i != '0') {
            Insert(i);
            cin >> i;
        }
    }

    /*
	TODO:查找值为value的结点，返回第一个value值的结点，若不存在则返回NULL
	*/
    DLLNode<T>* findValue(const T& value)
    {
        DLLNode<T> *p=head;
        while (p->next!=NULL)
        {
            if (p->data==value)
            {
                return p;
            }
            
        }
        return NULL;
    }

    /*
	TODO：删除所有值为value的结点,如果未找到，则打印cout << "不存在值为value的结点" << endl;并返回。
	 */
    void deleteValue(const T& value)
    {
        bool flag=0;
        DLLNode<T>*p=head;
        while (p!=NULL)
        {
            
            if (p->data==value)
            {
                if (p==tail)
                {
                    if (p==head)
                    {
                        //cout<<"EMP "<<p->data<<endl;
                        p=NULL;
                        head=p;
                        tail=p;
                        return;
                    }
                    else{
                        //cout<<"DEL TAIL "<<p->data<<endl;
                        tail=p->prev;
                        tail->next=NULL;
                    }
                }
                else if (p==head)
                {
                    head->next->prev=NULL;
                    //cout<<"DEL HEAD "<<p->data<<endl;
                    head=p->next;
                }else
                {
                    //cout<<"DEL"<<p->data<<endl;
                    p->prev->next=p->next;
                    p->next->prev=p->prev;
                }
                
                flag=1;
            }
            p=p->next;
        }
        if (flag==0) cout << "不存在值为value的结点" << endl;
    }
    //打印整个链表
    void printList()
    {
        DLLNode<T>* p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    int value1, value2;
    DLLinkList<int> DLL;
    DLL.createList();
    DLL.printList();
    cin >> value1 >> value2;
    DLL.Insert(value1); //插入value1
    DLL.printList();
    DLL.deleteValue(value2); //删除value2
    DLL.printList();
}