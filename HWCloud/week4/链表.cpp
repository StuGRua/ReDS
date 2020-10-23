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
TODO:求链表中的最大值,并返回。如果链表a为空，则直接返回MinNumber
*/
int GetMax(Node* a)
{
    if (a==NULL)
    {
        return MinNumber;
    }
    int max=MinNumber;
    
    for (Node *p=a; p!=NULL; p=p->next)
    {
        //cout<<p->value<<endl;
        if (max<p->value)
        {
            max=p->value;
        }
        
    }
    return max;
}
/*
TODO:求链表中的结点个数，并返回个数。
 */
int GetNodeNum(Node* a)
{
    int num=0;
    Node *p=a;
    while (p!=NULL)
    {
        p=p->next;
        num++;
    }
    return num;
}
/*
TODO: 求所有整数的平均值
*/
double GetAvg(Node* a, int n)
{
    int SumA=0;
    double Avg=0;
    Node *p=a;
    while (p != NULL) {
        SumA+=p->value;
        p = p->next;
    }
    Avg=(double)SumA/(double)n;
    return Avg;
}

int main()
{
    int count;
    cin >> count;
    Node *a = NULL, *p;
    for (int i = 0; i < count; i++) {
        int iValue;
        cin >> iValue;
        if (a == NULL) {
            a = new Node(iValue);
            p = a;
        } else {
            p->next = new Node(iValue);
            p = p->next;
        }
    }
    int max = GetMax(a);
    int nodeNum = GetNodeNum(a);
    double avg = GetAvg(a, nodeNum);
    cout << "最大值：" << max << endl;
    cout << "结点个数：" << nodeNum << endl;
    cout << "平均值：" << avg << endl;
}
