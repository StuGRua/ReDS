/*课后习题1.8-d

	d.	设ha和hb分别是两个不带头结点的非递减有序单链表的表头指针，试设计一个算法，
		将这两个有序链表合并成一个非递减有序的单链表。要求结果链表仍使用原来两个链表的存储空间，
		不另外占用其他的存储空间。表中允许有重复的数据。

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
TODO:链表连接,将链表a和链表b进行连接合并，连接合并后结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间，且合并后的是一个非递减有序的单链表。
返回值说明：返回合并后的非递减有序单链表
*/
Node* Merge(Node* a, Node* b)
{
    Node*pA=a, *pB=b, *pC=a,*pD=pB->next;
    while (pA!=NULL&&pB!=NULL)
    {
        if (pA->value<=pB->value)//A入表，不做操作只记录位置
        {
            pC=pA;
            pA=pA->next;
        }
        else//B入表
        {
            pD=pB->next;//D指向B下一位
            pB->next=pA;//B的next指向链表1的指针位置
            pC->next=pB;//上一轮的链表1指针位置后接上B：C->B->A
            pC=pB;//CB指针向下迭代
            pB=pD;
        }

    }
    if (pB==NULL)
    {
        while (pA!=NULL)
        {
            pC=pA;
            pA=pA->next;
        }

    }else
    {
        while (pB!=NULL)
        {
            pC->next=pB;
            pB=pB->next;
        }
    }
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
    cout << "合并前链表1为:";
    print(ha);
    cout << "合并前链表2为:";
    print(hb);
    Node* head = Merge(ha, hb);
    cout << "合并后的单链表为:";
    print(head);
    return 0;
}

