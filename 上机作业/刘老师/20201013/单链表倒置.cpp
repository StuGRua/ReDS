#include <iostream>
using namespace std;
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
TODO:链表倒置的算法
 */
Node* Reverse(Node* first)
{
    Node *C_first,*res,*temp;
    res = new Node(-1);
    res->next = first;
 
    C_first = res->next;       //C_first 始终为第一个结点，不断后移
    while(C_first->next!=NULL) //temp为待前差的
        {
        temp = C_first->next;
        C_first->next = temp->next;
        temp->next = res->next;
        res->next = temp;          
    }
    first=res;
    return first->next;
}
void print(Node* node)
{
    while (NULL != node) {
        cout << node->value << " ";
        node = node->next;
    }
}
int main()
{
    int iNum;
    cin >> iNum;
    Node* a = NULL;
    Node* pTemp;

    for (int i = 0; i < iNum; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a = new Node(tmp);
            pTemp = a;
        } else {
            pTemp->next = new Node(tmp);
            pTemp = pTemp->next;
        }
    }

    cout << "倒置前为：";
    print(a);
    cout << endl;
    Node* r = Reverse(a);
    cout << "倒置后为：";
    print(r);
    cout << endl;
    return 0;
}
