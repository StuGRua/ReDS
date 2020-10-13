/*课后习题1.8-e

	e.	设双链表表示的线性表L=（a1,a2,……,an），试写一时间复杂度为O(n)的算法，
		将L改造为L=（a1,a3,……,an,……,a4,a2）。

		void Change(Node* a)

*/
#include <iostream>
using namespace std;
const int MinNumber = -1000000;
struct Node
{
    Node(int x)
    {
        value = x;
        before = NULL;
        next = NULL;
    }
    int value;
    Node *before;
    Node *next;
};

/*
TODO:设双链表表示的线性表L=（a1,a2,……,an），试写一时间复杂度为O(n)的算法，
		将L改造为L=（a1,a3,……,an,……,a4,a2）
		假如a=(1,2,3,4,5,6,7,8,9,10,11),经过改造后，a变为(1,3,5,7,9,11,10,8,6,4,2)
 */
void Change(Node *a)
{

    Node *p, *q, *s, *r;
    int i = 0;
    q = a;
    p = a;
    //p = p -> next;
    r = p;
    while (p->next != a)
    {

        s = p->next;
        i++; /**i值表示当前p指针的指向**/
        if (i % 2 == 0)
        { /**将第偶数个指针移到头指针左边**/
            q->before = p;
            p->next = q;
            q = q->before;
            p = s;       /**记录p点**/
            r->next = s; /**将s指针指向的节点与修改后的前一节点相连接**/
            s->before = r;
            r = r->next;
        }
        else /**不符合条件，p指针往后移**/
            p = p->next;
    }
    cout<<"p="<<p->value<<" q="<<q->value<<endl;
    p->next = q;
    q->before = p;
}

int main()
{
    //由题目可得n>=3,先建立双向链表
    int initValue, count, iValue;
    cin >> initValue >> count;
    Node *ha = new Node(initValue); //建立初始值
    Node *p = ha;
    for (int i = 2; i <= count; i++) //通过for循环，建立双向链表。 count表示双向链表中元素个数
    {
        cin >> iValue;
        Node *t = new Node(iValue);
        p->next = t;
        t->before = p;
        p = t;
    }
    p->next = ha;
    ha->before = p;

    cout << "改造前正向输出:";
    p = ha;
    while (p->next != ha)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << p->value << endl;

    Change(ha);

    cout << "改造后正向输出:";
    p = ha;
    while (p->next != ha)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << p->value << endl;
    cout << "改造后逆向输出:";
    p = ha->before;
    while (p != ha)
    {
        cout << p->value << " ";
        p = p->before;
    }
    cout << p->value << endl;
    return 0;
}
