/*�κ�ϰ��1.8-d

	d.	��ha��hb�ֱ�����������ͷ���ķǵݼ���������ı�ͷָ�룬�����һ���㷨��
		����������������ϲ���һ���ǵݼ�����ĵ�����Ҫ����������ʹ��ԭ����������Ĵ洢�ռ䣬
		������ռ�������Ĵ洢�ռ䡣�����������ظ������ݡ�

		Node* Merge(Node* a, Node* b)

*/
#include <iostream>
using namespace std;
const int MinNumber = -1000000;
struct Node {
    Node(int x)
    {
        value = x;
        next = NULL;
    }
    int value;
    Node* next;
};

/*
TODO:��������,������a������b�������Ӻϲ������Ӻϲ�����������ʹ��ԭ����������Ĵ洢�ռ䣬
������ռ�������Ĵ洢�ռ䣬�Һϲ������һ���ǵݼ�����ĵ�����
����ֵ˵�������غϲ���ķǵݼ���������
*/
Node* Merge(Node* a, Node* b)
{
    Node*A=NULL, *B=NULL, *C=NULL,*D=NULL;
    A=a;
    B=b;
    C=a;
    while (A!=NULL&&B!=NULL)
    {
        if (A->value<=B->value)
        {
            C=A;
            A=A->next;
        }
        else
        {
            D=B->next;
            B->next=A;
            C->next=B;
            C=B;
            B=D;
        }

    }

    C->next=A?A:B;
    return a;
}
void print(Node* pNode)
{
    while (pNode != NULL) {
        cout << pNode->value << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

Node* init()
{
    int count;
    cin >> count;
    Node *p = NULL, *q;
    for (int i = 0; i < count; i++) {
        int iValue;
        cin >> iValue;
        if (NULL == p) {
            p = new Node(iValue);
            q = p;
        } else {
            q->next = new Node(iValue);
            q = q->next;
        }
    }
    return p;
}

int main()
{
    Node* ha = init();
    Node* hb = init();
    cout << "�ϲ�ǰ����1Ϊ:";
    print(ha);
    cout << "�ϲ�ǰ����2Ϊ:";
    print(hb);
    Node* head = Merge(ha, hb);
    cout << "�ϲ���ĵ�����Ϊ:";
    print(head);
    return 0;
}
