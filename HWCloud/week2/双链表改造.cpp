/*�κ�ϰ��1.8-e

	e.	��˫�����ʾ�����Ա�L=��a1,a2,����,an������дһʱ�临�Ӷ�ΪO(n)���㷨��
		��L����ΪL=��a1,a3,����,an,����,a4,a2����

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
TODO:��˫�����ʾ�����Ա�L=��a1,a2,����,an������дһʱ�临�Ӷ�ΪO(n)���㷨��
		��L����ΪL=��a1,a3,����,an,����,a4,a2��
		����a=(1,2,3,4,5,6,7,8,9,10,11),���������a��Ϊ(1,3,5,7,9,11,10,8,6,4,2)
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
        i++; /**iֵ��ʾ��ǰpָ���ָ��**/
        if (i % 2 == 0)
        { /**����ż����ָ���Ƶ�ͷָ�����**/
            q->before = p;
            p->next = q;
            q = q->before;
            p = s;       /**��¼p��**/
            r->next = s; /**��sָ��ָ��Ľڵ����޸ĺ��ǰһ�ڵ�������**/
            s->before = r;
            r = r->next;
        }
        else /**������������pָ��������**/
            p = p->next;
    }
    cout<<"p="<<p->value<<" q="<<q->value<<endl;
    p->next = q;
    q->before = p;
}

int main()
{
    //����Ŀ�ɵ�n>=3,�Ƚ���˫������
    int initValue, count, iValue;
    cin >> initValue >> count;
    Node *ha = new Node(initValue); //������ʼֵ
    Node *p = ha;
    for (int i = 2; i <= count; i++) //ͨ��forѭ��������˫������ count��ʾ˫��������Ԫ�ظ���
    {
        cin >> iValue;
        Node *t = new Node(iValue);
        p->next = t;
        t->before = p;
        p = t;
    }
    p->next = ha;
    ha->before = p;

    cout << "����ǰ�������:";
    p = ha;
    while (p->next != ha)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << p->value << endl;

    Change(ha);

    cout << "������������:";
    p = ha;
    while (p->next != ha)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << p->value << endl;
    cout << "������������:";
    p = ha->before;
    while (p != ha)
    {
        cout << p->value << " ";
        p = p->before;
    }
    cout << p->value << endl;
    return 0;
}
