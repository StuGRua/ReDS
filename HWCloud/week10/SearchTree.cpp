/*2.3  ����������

	void createSearchTree();									//2.3-a ��������������
	BinarySearchTreeNode<T>* search(BinarySearchTreeNode<T>* root, T x);
																//2.3-b �����������Ĳ���ֵΪx�Ľ�㣬�����ش˽��
	void insertNode(const T& value);							//2.3-c �����������Ĳ���x��
	void deleteByCopying(BinarySearchTreeNode<T>*& node);		//2.3-d ����ɾ��

*/

#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class BinarySearchTreeNode {
    friend class BinarySearchTree<T>;

private:
    T element;
    BinarySearchTreeNode<T>* leftChild;
    BinarySearchTreeNode<T>* rightChild;

public:
    BinarySearchTreeNode();
    BinarySearchTreeNode(const T& ele)
    {
        element = ele;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinarySearchTreeNode(const T& ele, BinarySearchTreeNode<T>* l, BinarySearchTreeNode<T>* r)
    {
        element = ele;
        leftChild = l;
        rightChild = r;
    }
    BinarySearchTreeNode<T>* getLeftChild() const
    {
        return leftChild;
    }
    BinarySearchTreeNode<T>* getRightChild() const
    {
        return rightChild;
    }
    void setLeftChild(BinarySearchTreeNode<T>* l)
    {
        leftChild = l;
    }
    void setRightChild(BinarySearchTreeNode<T>* r)
    {
        rightChild = r;
    }
    T getValue() const
    {
        return element;
    }
    void setValue(const T& val)
    {
        element = val;
    }
    bool isLeaf() const
    {
        if (leftChild == NULL && rightChild == NULL)
            return true;
        return false;
    }
};

template <class T>
class BinarySearchTree {
private:
    BinarySearchTreeNode<T>* root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    BinarySearchTree(BinarySearchTreeNode<T>*& r)
    {
        root = r;
    }
    void createSearchTree(); //2.3-a ��������������
    void visit(BinarySearchTreeNode<T>* current);
    BinarySearchTreeNode<T>* search(BinarySearchTreeNode<T>* root, T x);
    //2.3-b �����������Ĳ���ֵΪx�Ľ�㣬�����ش˽��
    void insertNode(const T& value); //2.3-c �����������Ĳ���x��
    void deleteByCopying(BinarySearchTreeNode<T>*& node); //2.3-d ����ɾ��
    void inOrder(BinarySearchTreeNode<T>* root);
    void setRoot(BinarySearchTreeNode<T>* r);
    BinarySearchTreeNode<T>* getRoot();
    BinarySearchTreeNode<T>* getParent(BinarySearchTreeNode<T>* root, BinarySearchTreeNode<T>* current) const;
};

/*
�������ܣ�2.3-a �������������� 
*/
template <class T>
void BinarySearchTree<T>::createSearchTree()
{
    int a;
    cout << "����int�ͣ���0Ϊ����" << endl;
    cin >> a;
    while (a != 0) {
        //TODO:������a���뵽�����������С�������������������
        insertNode(a);
        cin >> a;
    }
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getRoot()
{
    return root;
}

template <class T>
void BinarySearchTree<T>::setRoot(BinarySearchTreeNode<T>* r)
{
    this->root = r;
}
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::getParent(BinarySearchTreeNode<T>* root, BinarySearchTreeNode<T>* current) const
{
    if (root != NULL) {
        if (root == current) {
            cout << "�ýڵ�Ϊ����㣬�޸����" << endl;
            return NULL;
        } else if (root->leftChild == current || root->rightChild == current) {
            return root;
        } else {
            getParent(root->leftChild, current);
            getParent(root->rightChild, current);
        }
    }
}

template <class T>
void BinarySearchTree<T>::visit(BinarySearchTreeNode<T>* current)
{
    cout << current->element << " ";
}

/*
TODO:2.3-b �����������Ĳ���ֵΪx�Ľ�㣬�����ش˽��
 */
template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::search(BinarySearchTreeNode<T>* root, T x)
{
	BinarySearchTreeNode<T>* current = root;
	while ((NULL != root) && (x != current->element))
		//��ǰ����keyֵ���ڲ�ѯ��ֵʱ���˳�ѭ��
	{
		current = (x < current->element ? search(current->leftChild, x) : search(current->rightChild, x));
		//���ݵ�ǰ����ֵ�Ĵ�С�����ƶ�����
	}
	return current;
}

/*
TODO:2.3-c �����������Ĳ���,��value�����ȥ
 */
template <class T>
void BinarySearchTree<T>::insertNode(const T& value)
{
	BinarySearchTreeNode<T> *p = root, *prev = NULL;
	while (p != 0)
	{                                  		//�½�����λ��
		prev = p;                      	//��¼�����
		if (p->getValue() < value)
			p = p->rightChild;
		else
			p = p->leftChild;
	}
	if (root == NULL)               		//����ǿ��������½����Ϊ�����
		root = new BinarySearchTreeNode<T>(value);
	else if (prev->getValue() < value)
		//���ݹؼ����������Ϊ���ӽ�㻹�����ӽ��
		prev->rightChild = new BinarySearchTreeNode<T>(value,NULL,NULL);
	else
		prev->leftChild = new BinarySearchTreeNode<T>(value,NULL,NULL);    
}

/*
TODO:2.3-d ����ɾ��
*/
template <class T>
void BinarySearchTree<T>::deleteByCopying(BinarySearchTreeNode<T>*& node)
{
	BinarySearchTreeNode<T>* previous, *tmp =getParent(root,node);
	//�����ɾ�����û���������������������ĸ���������汻ɾ�����
    //cout<<"Case:NO R"<<endl;
	if (node->rightChild == NULL)
    {
        
        if(tmp->leftChild==node){
            tmp->leftChild=node->leftChild;
        }
        else
        {
            tmp->rightChild=node->leftChild;
        }
        
		//node = node->leftChild;
    }

	//�����ɾ�����û���������������������ĸ���������汻ɾ�����
	else if (node->leftChild == NULL)
    {
        //cout<<"Case:NO L"<<endl;
        if(tmp->leftChild==node){
        tmp->leftChild=node->rightChild;
        }
        else
        {
            tmp->rightChild=node->rightChild;
        }
		//node = node->rightChild;
    }

	else if(node->leftChild&&node->rightChild)    								//�����ɾ�������������������
	{
        //cout<<"Case:LR"<<endl;
		tmp = node->leftChild;
		previous = node;
		while (tmp->rightChild != NULL)	//�����������йؼ������Ľ��
		{
			previous = tmp;
			tmp = tmp->rightChild;
		}
		node->element = tmp->element;	//�����ҵ��Ľ���ֵ��ֵ����ɾ�����
		if (previous == node)
			previous->leftChild = tmp->leftChild;
		else
			previous->rightChild = tmp->leftChild;
	}
    //cout<<"DEL:"<<tmp->element<<endl;
	//delete tmp;
}

template <class T>
void BinarySearchTree<T>::inOrder(BinarySearchTreeNode<T>* root)
{
    if (root != NULL) {
        inOrder(root->leftChild);
        visit(root);
        inOrder(root->rightChild);
    }
}

int main()
{
    BinarySearchTreeNode<int>*tmp1, *tmp2;
    BinarySearchTree<int> st;
    st.createSearchTree();
    tmp1 = st.getRoot();
    st.inOrder(tmp1);
    cout << endl;
    int temp;
    cin >> temp;
    st.insertNode(temp);
    st.inOrder(tmp1);
    cout << endl;

    cout << "����һ����Ҫ���ҵ�ֵ" << endl;
    cin >> temp; // ����һ����Ҫ���ҵ�ֵ
    tmp2 = st.search(tmp1, temp); //�ҵ�ֵtemp ���ؽ�㣬�Ҳ�������NULL
    if (tmp2 != NULL) {
        cout << "���ҵ�ֵΪ: " << tmp2->getValue() << endl;
        st.deleteByCopying(tmp2);
        st.inOrder(tmp1);
    } else
        cout << "������ֵ" << temp;
    return 0;
}