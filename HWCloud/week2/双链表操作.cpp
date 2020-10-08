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
	TODO: ��˫����ı�β����ֵΪnum��DLLNode��㣬ע�⿼�ǿ��������Ĳ������
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

    //����˫����
    void createList()
    {
        cout << "����������0Ϊ��β��";
        T i;
        cin >> i;
        while (i != 0 && i != '0') {
            Insert(i);
            cin >> i;
        }
    }

    /*
	TODO:����ֵΪvalue�Ľ�㣬���ص�һ��valueֵ�Ľ�㣬���������򷵻�NULL
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
	TODO��ɾ������ֵΪvalue�Ľ��,���δ�ҵ������ӡcout << "������ֵΪvalue�Ľ��" << endl;�����ء�
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
        if (flag==0) cout << "������ֵΪvalue�Ľ��" << endl;
    }
    //��ӡ��������
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
    DLL.Insert(value1); //����value1
    DLL.printList();
    DLL.deleteValue(value2); //ɾ��value2
    DLL.printList();
}