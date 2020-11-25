#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "treeNode.h"
using namespace std;

template <class T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *root;

public:
    BinaryTree();  //默认构造函数
    ~BinaryTree(); //析构函数

    bool isEmpty() const;               //判断二叉树是否为空树
    BinaryTreeNode<T> *getRoot() const; //返回二叉树的根结点

    BinaryTreeNode<T> *getParent(BinaryTreeNode<T> *current) const;       //返回current结点的父结点
    BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current) const;  //返回current结点的左兄弟
    BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current) const; //返回current结点的右兄弟

    void levelOrder(BinaryTreeNode<T> *root);               //广度优先遍历以root为根结点的子树
    void preOrder(BinaryTreeNode<T> *root);                 //先序遍历以root为根结点的子树
    void PreOrderWithoutRecusion(BinaryTreeNode<T> *root);  //非递归先序遍历以root为根结点的子树
    void inOrder(BinaryTreeNode<T> *root);                  //中序遍历以root为根结点的子树
    void InOrderWithoutRecusion(BinaryTreeNode<T> *root);   //非递归中序遍历以root为根结点的子树
    void postOrder(BinaryTreeNode<T> *root);                //后序遍历以root为根结点的子树
    void PostOrderWithoutRecusion(BinaryTreeNode<T> *root); //非递归后序遍历以root为根结点的子树

    void deleteBinaryTree(BinaryTreeNode<T> *root); //删除以root为根结点的子树
    void visit(BinaryTreeNode<T> *t);               //访问当前节点

    void create1(string m, string n);                                  //输入二叉树的先序和中序
    void preincreatetree(BinaryTreeNode<T> *t, string pre, string in); //先序和中序创建二叉树

    void create2(string m, string n);                                    //输入二叉树的后序和中序
    void inpostcreatetree(BinaryTreeNode<T> *t, string in, string post); //后序和中序创建二叉树
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    deleteBinaryTree(root);
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
    if (root == NULL)
        return true;
    else
        return false;
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::getRoot() const
{
    return root;
}

template <class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root)
{
    if (root != NULL)
    {
        deleteBinaryTree(root->getLeftChild());
        deleteBinaryTree(root->getRightChild());
        delete root;
    }
}

template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T> *t)
{
    cout << t->getValue();
}

//--------------------------------------
//7种遍历

template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root) //广度遍历，需要队列辅助完成，左右孩子有即入栈
{
    queue<BinaryTreeNode<T> *> nodeQueue; //用队列来存放将要访问的结点
    BinaryTreeNode<T> *pointer = root;

    if (pointer) //如果根结点非空，将根结点移入队列
        nodeQueue.push(pointer);
    while (!nodeQueue.empty()) //循环到队列空停止，即所有栈内所有非叶子结点都访问过
    {
        pointer = nodeQueue.front(); //读取队首结点
        visit(pointer);              //访问当前结点
        nodeQueue.pop();             //将访问过的结点移出队列
        if (pointer->getLeftChild())
            nodeQueue.push(pointer->getLeftChild());
        if (pointer->getRightChild())
            nodeQueue.push(pointer->getRightChild());
        //将访问过的结点的左右孩子结点依次加入到队尾
    }
}

//对于后6种遍历，两种类型在逻辑上是相同的，都是按顺序先遍历一侧子树再处理另一侧子树；递归不需要辅助结构，而非递归需要栈结构来实现类似递归的逻辑（存储已访问节点的未处理的一侧子树）

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root) //递归前序遍历
{
    if (root != NULL)
    {
        visit(root);                     //访问当前结点
        preOrder(root->getLeftChild());  //访问左子树，左子树递归终止时进入上一层的右子树递归
        preOrder(root->getRightChild()); //访问右子树，不断在递归终止时返回上一层递归
    }
}

template <class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T> *root) //非递归前序遍历，需要栈辅助
{
    stack<BinaryTreeNode<T> *> nodeStack; //存放待访问的结点的栈
    BinaryTreeNode<T> *pointer = root;    //保存根结点

    while (!nodeStack.empty() || pointer) //栈为空时遍历结束
    {
        if (pointer)//循环中pointer为上一次读取位置的左结点/栈顶结点
        {
            visit(pointer); //访问当前结点
            if (pointer->getRightChild() != NULL)
                nodeStack.push(pointer->getRightChild()); //当前访问结点的右子树的根结点入栈
            pointer = pointer->getLeftChild();            //转向访问其左子树
        }
        else
        {                              //左子树访问完毕，转向访问右子树
            pointer = nodeStack.top(); //读取栈顶待访问的结点
            nodeStack.pop();           //删除栈顶结点
        }
    } //栈不空时进入上一层的右子树
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root) //递归中序遍历
{
    if (root != NULL)
    {
        inOrder(root->getLeftChild());  //访问左子树
        visit(root);                    //访问当前结点
        inOrder(root->getRightChild()); //访问右子树
    }
}

template <class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T> *root) //非递归中序遍历，需要栈辅助
{
    stack<BinaryTreeNode<T> *> nodeStack; //存储待访问结点
    BinaryTreeNode<T> *pointer = root;    //保存根结点

    while (!nodeStack.empty() || pointer) //栈为空时遍历结束
    {
        if (pointer)
        {
            nodeStack.push(pointer);           //当前结点入栈
            pointer = pointer->getLeftChild(); //转向访问其左孩子
        }
        else
        {                                       //左子树访问完毕，转向访问右子树
            pointer = nodeStack.top();          //读取栈顶待访问的结点
            visit(pointer);                     //访问当前结点
            pointer = pointer->getRightChild(); //转向其右孩子
            nodeStack.pop();                    //删除栈顶结点
        }
    } //栈不空时进入上一层的右子树
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root) //递归后序遍历
{
    if (root != NULL)
    {
        postOrder(root->getLeftChild());  //访问左子树
        postOrder(root->getRightChild()); //访问右子树
        visit(root);                      //访问当前结点
    }
}

template <class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T> *root) //非递归后序遍历，需要栈辅助，需要额外的标记结点pre
{
    stack<BinaryTreeNode<T> *> nodeStack; //存储待访问结点
    BinaryTreeNode<T> *pointer = root;    //保存根结点
    BinaryTreeNode<T> *pre = root;        //保存前一个被访问的结点，便于判断是否返回到父元素

    while (pointer)//下移中是右孩子，上移是栈顶
    {
        for (; pointer->getLeftChild() != NULL; pointer = pointer->getLeftChild())
            nodeStack.push(pointer); //向左搜索，将有左子树特性的结点存入

        while (pointer != NULL && (pointer->getRightChild() == NULL || pointer->getRightChild() == pre)) //当前结点没有右孩子或者右孩子刚被访问过(当前结点右孩子为pre),则访问该结点
        {
            visit(pointer);
            pre = pointer; //记录刚被访问过的结点
            if (nodeStack.empty())
                return;
            pointer = nodeStack.top(); //取栈顶结点
            nodeStack.pop();
        } //上移循环
        nodeStack.push(pointer);
        pointer = pointer->getRightChild(); //转向当前结点的右子树
    }                                       //下移循环
}

//----------------------------------------
//创建树
//思想都相同，都是通过找到当前根结点从而划分中序序列，区别出左子树右子树；
//在递归方面都是通过递归更新leftchild_in和rightchild_length来实现迭代，
//同时通过标记结点（就是当前根结点或叶子结点）给目前结点赋值
template <class T>
void BinaryTree<T>::create1(string m, string n)
{
    root = new BinaryTreeNode<T>;
    preincreatetree(root, m, n);
}

template <class T>
void BinaryTree<T>::preincreatetree(BinaryTreeNode<T> *t, string pre, string in) //先序和中序创建二叉树
{
    if (pre.length() == 0)
    {
        t = NULL;
        return;
    }
    char tvalue = pre[0];                                     //前序序列第一位为根结点
    int index = in.find(tvalue);                              //在中序序列中的位置
    string leftchild_in = in.substr(0, index);                //左孩子的中序序列
    string rightchild_in = in.substr(index + 1);              //右孩子的中序序列
    int leftchild_length = leftchild_in.length();             //左孩子的长度
    int rightchild_length = rightchild_in.length();           //右孩子的长度
    string leftchild_pre = pre.substr(1, leftchild_length);   //左孩子的前序序列
    string rightchild_pre = pre.substr(leftchild_length + 1); //右孩子的前序序列
    if (leftchild_length == 0 && rightchild_length == 0)      //无左右孩子，结束
    {
        t->setValue(tvalue);
    }
    else if (leftchild_length > 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        preincreatetree(t->getLeftChild(), leftchild_pre, leftchild_in); //递归创建左孩子
    }
    else if (leftchild_length == 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createRightChild();
        preincreatetree(t->getRightChild(), rightchild_pre, rightchild_in); //递归创建右孩子
    }
    else if (leftchild_length > 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        t->createRightChild();
        preincreatetree(t->getLeftChild(), leftchild_pre, leftchild_in);    //递归创建左孩子
        preincreatetree(t->getRightChild(), rightchild_pre, rightchild_in); //递归创建右孩子
    }
}

template <class T>
void BinaryTree<T>::create2(string m, string n)
{
    root = new BinaryTreeNode<T>;
    inpostcreatetree(root, m, n);
}

template <class T>
void BinaryTree<T>::inpostcreatetree(BinaryTreeNode<T> *t, string in, string post) //后序和中序创建二叉树
{
    if (post.length() == 0)
    {
        t = NULL;
        return;
    }
    char tvalue = post[post.length() - 1];                                     //后序序列最后一位为根结点
    int index = in.find(tvalue);                                               //在中序序列中的位置
    string leftchild_in = in.substr(0, index);                                 //左孩子的中序序列
    string rightchild_in = in.substr(index + 1);                               //右孩子的中序序列
    int leftchild_length = leftchild_in.length();                              //左孩子的长度
    int rightchild_length = rightchild_in.length();                            //右孩子的长度
    string leftchild_post = post.substr(0, leftchild_length);                  //左孩子的后序序列
    string rightchild_post = post.substr(leftchild_length, rightchild_length); //右孩子的后序序列
    if (leftchild_length == 0 && rightchild_length == 0)                       //无左右孩子，结束
    {
        t->setValue(tvalue);
    }
    else if (leftchild_length > 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        inpostcreatetree(t->getLeftChild(), leftchild_in, leftchild_post); //递归创建左孩子
    }
    else if (leftchild_length == 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createRightChild();
        inpostcreatetree(t->getRightChild(), rightchild_in, rightchild_post); //递归创建右孩子
    }
    else if (leftchild_length > 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        t->createRightChild();
        inpostcreatetree(t->getLeftChild(), leftchild_in, leftchild_post);    //递归创建左孩子
        inpostcreatetree(t->getRightChild(), rightchild_in, rightchild_post); //递归创建右孩子
    }
}

int main()
{
    BinaryTree<char> tree;
    string m, n;
    m = "ABDFGCEH";
    n = "BFDGACEH";
    cout << "PreOrder sequence: " << m << endl;
    cout << "InOrder sequence:" << n << endl;
    tree.create1(m, n);
    /*
    m="BFDGACEH"
    n="FGDBHECA"
    cout << "InOrder sequence: " << m << endl;
    cout << "PostOrder sequence:" << n << endl;
    tree.create2(m,n);*/
    cout << "------------------------------------" << endl;
    cout << "The breadth-first:" << endl; //ABCDEFGH
    tree.levelOrder(tree.getRoot());
    cout << "\nPre-order:" << endl;
    tree.preOrder(tree.getRoot());
    cout << "\nPre-order without recusion:" << endl;
    tree.PreOrderWithoutRecusion(tree.getRoot());
    cout << "\nIn-order:" << endl;
    tree.inOrder(tree.getRoot());
    cout << "\nIn-order without recusion:" << endl;
    tree.InOrderWithoutRecusion(tree.getRoot());
    cout << "\nPost-order:" << endl;
    tree.postOrder(tree.getRoot());
    cout << "\nPost-order without recusion:" << endl;
    tree.PostOrderWithoutRecusion(tree.getRoot());
    return 0;
}
