/* �κ�ϰ��1.8-f 
	
	f.	��֪��һ��ѭ��˫����pָ���һ��Ԫ��Ϊx��ָ�룬���һ���㷨�Ӹ�ѭ��˫������ɾ��*p��㡣
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
	TODO��ѭ��˫����ɾ����㣬ɾ��ֵΪnum�����н��
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
            return; //˵��û��Ԫ�أ�ֱ�ӷ��ؼ���
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
    cout << "��ʼֵΪ:";
    ll.display();
    cin >> value;
    ll.deletelinknode(value);
    cout << "ɾ��ֵΪ" << value << "�Ľ���Ϊ:";
    ll.display();
    return 0;
}
