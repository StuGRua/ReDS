#include <iostream>
using namespace std;
 
//包含队列的类定义
template<class T>
class Queue
{
public:
	Queue(int MaxQueueSize = 10);
	~Queue() { delete[] queue; }
	bool IsEmpty() { return front == rear; }
	bool IsFull()
	{
		if ((rear + 1) % MaxSize == front)
			return true;
		else
			return false;
	}
	T First();//返回队首元素
	T Last();//返回队尾元素
	void Add(const T& x);
	void Del(T& x);
private:
	int front; //与第一个元素在反时针方向上相差一个位置
	int rear; //指向最后一个元素
	int MaxSize;//队列数组的大小
	T* queue; //数组 
};

template<class T>
Queue<T>::Queue(int MaxQueueSize)
{
	MaxSize = MaxQueueSize;
	queue = new T[MaxSize];
	front = rear = 0;
}

template<class T>
T Queue<T>::First()
{
	if (IsEmpty())
		return NULL;
	else
		return queue[(front + 1) % MaxSize];
}

template<class T>
T Queue<T>::Last()
{
	if (IsEmpty())
		return false;
	else
		return queue[rear];
}

template<class T>
void Queue<T>::Add(const T& x)
{
	if (IsFull())
	{
		cout << "no memeory"; return;
	}
	rear = (rear + 1) % MaxSize;
	queue[rear] = x;
	return;
}

template<class T>
void Queue<T>::Del(T& x)
{
	if (IsEmpty())
	{
		cout << "no element"; return;
	}
	front = (front + 1) % MaxSize;
	x = queue[front];
	return;
}

//包含栈的类定义
template <class T>
class Stack {
public:
	Stack(int MaStackSize = 10);
	~Stack() { delete[] stack; }
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == MaxTop; }
	T Top() const;
	Stack<T>& Add(const T& x);
	Stack<T>& Delete(T& x);
	void MakeEmpty() { top = -1; } //清空栈
private:
	int top;//栈顶
	int MaxTop;//最大的栈顶值
	T* stack;//堆栈元素数组
};
template<class T>
Stack<T>::Stack(int MaxStackSize)
{
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;
}

template<class T>
T Stack<T>::Top() const
{
	if (IsEmpty())
	{
		cout << "no element"; 
        return NULL;
	}
	else
		return stack[top];
}
template<class T>
Stack<T>& Stack<T>::Add(const T& x)
{
	if (IsFull())
	{
		cout << "no memory;" << endl; return *this;
	}
	top = top + 1;
	stack[top] = x;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::Delete(T& x)
{
	if (IsEmpty())
	{
		cout << "no element" << endl; return *this;
	}
	x = stack[top];
	top = top - 1;
	return *this;
}
template<class T>
class BinaryTree;
//二叉搜索树节点定义
template <class T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;
public:

	T data;
	BinaryTreeNode* LeftChild, * RightChild;
	BinaryTreeNode(T e) { data = e; LeftChild = 0; RightChild = 0; }

};
//二叉搜索树定义
template <class T>
class BinaryTree
{
public:

	BinaryTreeNode<T>* root;
	BinaryTree() { root = 0; }

	void LevelOrder();//逐层遍历
	BinaryTreeNode<T>* Search(const T& key);//查找
	void Insert(const T& value);//插入
	bool DeleteByCopying(const T& value);//删除
};


//二叉搜索树插入节点
template <class T>
void BinaryTree<T>::Insert(const T& value)
{
	//给出代码
    BinaryTreeNode<T> *p = root, *prev = NULL;
	while (p != 0)
	{                                  		//新结点查找位置
		prev = p;                      	//记录父结点
		if (p->data < value)
			p = p->RightChild;
		else
			p = p->LeftChild;
	}
	if (root == NULL)               		//如果是空树，将新结点作为根结点
		root = new BinaryTreeNode<T>(value);
	else if (prev->data < value)
		//根据关键码决定设置为左子结点还是右子结点
		prev->RightChild = new BinaryTreeNode<T>(value);
	else
		prev->LeftChild = new BinaryTreeNode<T>(value);
}

//二叉搜索树查找节点
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Search(const T& key)
{
    Stack<BinaryTreeNode<T> *> nodeStack; //存放待访问的结点的栈
    BinaryTreeNode<T> *pointer = root,*temp;    //保存根结点

    while (!nodeStack.IsEmpty() || pointer) //栈为空时遍历结束
    {
        if (pointer)//循环中pointer为上一次读取位置的左结点/栈顶结点
        {
            if(pointer->data==key) return pointer;
            if (pointer->RightChild != NULL)
                nodeStack.Add(pointer->RightChild); //当前访问结点的右子树的根结点入栈
            pointer = pointer->LeftChild;            //转向访问其左子树
        }
        else
        {                              //左子树访问完毕，转向访问右子树
            pointer = nodeStack.Top(); //读取栈顶待访问的结点
            nodeStack.Delete(temp);           //删除栈顶结点
        }
    } //栈不空时进入上一层的右子树
    return NULL;
}

//二叉搜索树删除节点
template <class T>
bool BinaryTree<T>::DeleteByCopying(const T& value)
{
	BinaryTreeNode<T>* previous, *tmp = Search(value),*node=Search(value);
	//如果被删除结点没有右子树，用其左子树的根结点来代替被删除结点
	if (node->RightChild == NULL)
		node = node->LeftChild;
	//如果被删除结点没有左子树，用其右子树的根结点来代替被删除结点
	else if (node->LeftChild == NULL)
		node = node->RightChild;
	else    								//如果被删除结点左右子树都存在
	{
		tmp = node->LeftChild;
		previous = node;
		while (tmp->RightChild != NULL)	//查找左子树中关键码最大的结点
		{
			previous = tmp;
			tmp = tmp->RightChild;
		}
		node->data = tmp->data;	//将查找到的结点的值赋值给被删除结点 
		if (previous == node)
			previous->LeftChild = tmp->LeftChild;
		else
			previous->RightChild = tmp->LeftChild;
	}
	delete tmp;
    return true;
}

//逐层遍历
//打印时，假设p为当前需要访问的结点，循环中cout<<p->data<<" ";  在全部打印完成之后，cout<<endl;
template <class T>
void BinaryTree<T>::LevelOrder()
{
	//给出代码
    Queue<BinaryTreeNode<T> *> nodeQueue; //用队列来存放将要访问的结点
    BinaryTreeNode<T> *pointer = root;
    BinaryTreeNode<T> *temp = NULL;
    if (pointer) //如果根结点非空，将根结点移入队列
        nodeQueue.Add(pointer);
    while (!nodeQueue.IsEmpty()) //循环到队列空停止，即所有栈内所有非叶子结点都访问过
    {
        pointer = nodeQueue.First(); //读取队首结点
        cout<<pointer->data<<" ";              //访问当前结点
        nodeQueue.Del(temp);             //将访问过的结点移出队列
        if (pointer->LeftChild)
            nodeQueue.Add(pointer->LeftChild);
        if (pointer->RightChild)
            nodeQueue.Add(pointer->RightChild);
        //将访问过的结点的左右孩子结点依次加入到队尾
    }
    cout<<endl;
}

int main()
{
	BinaryTree<int> bt;
	BinaryTreeNode<int>* tmp;
	bt.Insert(400);
	bt.Insert(122);
	bt.Insert(450);
	bt.Insert(99);
	bt.Insert(250);
	bt.Insert(500);
	bt.Insert(110);
	bt.Insert(200);
	bt.Insert(300);
	bt.Insert(105);
	bt.Insert(330);       //插入建立二叉搜索树
	bt.LevelOrder();      //层次遍历
	if (bt.DeleteByCopying(122))	//删除值为122的节点
	{
		cout << "successful" << endl;
	}
	else
	{
		cout << "failed" << endl;
	}
	bt.LevelOrder();
	tmp = bt.Search(4);       //查找值为4的节点
	if(tmp != NULL)
		cout << "successful" << endl;
	else
		cout << "failed" << endl;
	bt.Insert(5);			//插入5
	bt.LevelOrder();
	return 0;
}