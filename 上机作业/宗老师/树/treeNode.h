#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
//------------------------------------
//结点定义
template <class T>
class BinaryTreeNode
{
private:
    

public:
    T element;                     //结点的数据域
    BinaryTreeNode<T> *leftChild;  //结点的左孩子结点
    BinaryTreeNode<T> *rightChild; //结点的右孩子结点
    BinaryTreeNode();                                                         //默认构造函数
    BinaryTreeNode(const T &ele);                                             //给定数据域的值的构造函数
    BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r); //给定数据值和左右孩子结点的构造函数
    BinaryTreeNode<T> *getLeftChild() const;                                  //返回该结点的左孩子结点
    BinaryTreeNode<T> *getRightChild() const;                                 //返回该结点的右孩子结点
    void setLeftChild(BinaryTreeNode<T> *l);                                  //设置该结点的左孩子结点
    void setRightChild(BinaryTreeNode<T> *r);                                 //设置该结点的右孩子结点
    void createLeftChild();                                                   //创建该结点的左孩子结点
    void createRightChild();                                                  //创建该结点的右孩子结点
    T getValue() const;                                                       //返回该结点的数据值
    void setValue(const T &val);                                              //设置该结点的数据域的值
    bool isLeaf() const;                                                      //判断该结点是否是叶子结点，若是，则返回true
};
template <class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
    element = 0;
    leftChild = rightChild = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele)
{
    element = ele;
    leftChild = rightChild = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r)
{
    element = ele;
    leftChild = l;
    rightChild = r;
}
template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::getLeftChild() const
{
    return leftChild;
}
template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::getRightChild() const
{
    return rightChild;
}
template <class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> *l)
{
    leftChild = l;
}
template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> *r)
{
    rightChild = r;
}
template <class T>
void BinaryTreeNode<T>::createLeftChild()
{
    leftChild = new BinaryTreeNode<T>;
}
template <class T>
void BinaryTreeNode<T>::createRightChild()
{
    rightChild = new BinaryTreeNode<T>;
}
template <class T>
T BinaryTreeNode<T>::getValue() const
{
    return element;
}
template <class T>
void BinaryTreeNode<T>::setValue(const T &val)
{
    element = val;
}
template <class T>
bool BinaryTreeNode<T>::isLeaf() const
{
    if (leftChild == NULL && rightChild == NULL)
        return true;
    else
        return false;
}