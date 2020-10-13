#include <bits/stdc++.h>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //数据域
    LinkNode<T>* link; //指向后继指针的结点
    LinkNode()
    {
        data = 0;
        link = NULL;
    }
    LinkNode(const T& el)
    {
        data = el;
        link = NULL;
    }
};

//
template <class T>
class LinkStack
{
    private:
        LinkNode <T> *top;
        int size;
    
    public:
        LinkStack(int s)
        {
            top=NULL;
            size=0;
        }
        ~LinkStack()
        {
            Clear();
        }
        void Clear()
        {
            while (top!=NULL)
            {
                LinkNode <T> *tmp=top;
                top=top->link;
                delete tmp;
            }
            size=0;
        }
        bool Push(const T& el)
        {
            LinkNode<T>*tmp=new LinkNode<T>(el);
            top=tmp;
            size++;
            return true;
        }
        bool Pop(T&item)
        {
            LinkNode<T>*tmp;
            if (size==0)
            {
                cout<<"empty stack!"<<endl;
                return false;
            }
            item=top->data;
            tmp=top->link;
            delete top;
            top=tmp;
            size--;
            return true;
        }
        T Top()
        {
            if (size==0)
            {
                cout<<"empty stack!"<<endl;
                return 0;
            }
            return top->data;
        }
};

int main()
{
    LinkStack<char> s(100);
    s.Push('a');
    cout<<s.Top()<<endl;
    return 0;
}