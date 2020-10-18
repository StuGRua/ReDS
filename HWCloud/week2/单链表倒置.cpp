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
void print(Node* node)
{
    while (NULL != node) {
        cout << node->value << " ";
        node = node->next;
    }
    cout<<endl;
}
/*
TODO:�����õ��㷨
 */
Node* Reverse(Node* first)
{
    Node *C_first,*res,*temp;
    res = new Node(-1);//res->�±�
    res->next = first;//res->link=�ɱ�
 
    C_first = res->next;//C_first=first       //C_first ʼ��Ϊ��һ����㣬���Ϻ���
    while(C_first->next!=NULL) //tempΪ��ǰ���
        {
        temp = C_first->next;//
        C_first->next = temp->next;
        temp->next = res->next;
        res->next = temp;     
        //print(first);
        //cout<<"res:"<<endl;
        //print(res);     
    }
    first=res;
    return first->next;
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

    cout << "����ǰΪ��";
    print(a);
    cout << endl;
    Node* r = Reverse(a);
    cout << "���ú�Ϊ��";
    print(r);
    cout << endl;
    return 0;
}
