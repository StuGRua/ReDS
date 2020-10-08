/* 课后习题1.8-f 
	
	f.	已知有一个循环双链表，p指向第一个元素为x的指针，设计一个算法从该循环双链表中删除*p结点。
		void deletelinknode(int num)

*/
#include <iostream>
using namespace std;
class linknode {
public:
    int data;
    linknode *next, *prev;
    linknode(int info = 0, linknode* nextpr = NULL, linknode* prevpr = NULL)
    {
        data = info;
        next = nextpr;
        prev = prevpr;
    }
};
class linklist {
public:
    linknode *head, *tail;
    linklist()
    {
        head = tail = NULL;
    }
    void push(int num)
    {
        if (head == NULL) {
            head = tail = new linknode(num);
            head->next = NULL;
            tail->next = head;
        } else {
            linknode* p = new linknode(num);
            tail->next = p;
            p->prev = tail;
            tail = p;
            tail->next = head;
        }
    }
    /*
	TODO：循环双链表删除结点，删除值为num的所有结点
	 */
    void deletelinknode(int num)
    {
    	linknode *p = head;
        while (p!=tail)
        {
            if(p->data==num){
                if (p==head)
                {
                    //cout<<p->next->data<<endl;
                    head->next->prev=NULL;
                    //cout<<p->next->data<<endl;
                    tail->next=p->next;
                    head=p->next;
                    //cout<<head->data<<endl;
                }
                else{
                    p->prev->next=p->next;
                    p->next->prev=p->prev; 
                }

            }
            p=p->next;
                       
        } 
        if (p==tail&&tail!=NULL&&p->data==num)
        {
            //cout<<"tailed"<<endl;
            if (head==tail)
            {
                //cout<<"tailed1"<<endl;
                head=tail;
                
            }
            else{
                //cout<<"tailed2"<<endl; 
                tail=p->prev;
                tail->next=head;
                
            }
           
        }
         
    }
    void display()
    {
        if (head == tail) {
            return; //说明没有元素，直接返回即可
        }
        for (linknode* p = head;; p = p->next) {
            if (p == tail) {
                cout << tail->data << endl;
                break;
            }
            cout << p->data << " ";
        }
    }
};

int main()
{
    linklist ll;
    int count, value;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> value;
        ll.push(value);
    }
    cout << "初始值为:";
    ll.display();
    cin >> value;
    ll.deletelinknode(value);
    cout << "删除值为" << value << "的结点后为:";
    ll.display();
    return 0;
}
