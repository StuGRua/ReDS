#include <iostream>
using namespace std;

template <class T>
class MaxHeap
{
private:
    T *heapArray;    //��Ŷ����ݵ�����
    int CurrentSize; //��ǰ����Ԫ����Ŀ
    int MaxSize;     //���������ɵ����Ԫ����Ŀ
public:
    MaxHeap(T *array, int num, int Max)
    {
        this->heapArray = new T[num];
        for (int i = 0; i < num; i++)
        {
            this->heapArray[i] = array[i];
        }
        this->CurrentSize = num;
        this->MaxSize = Max;
    }
    virtual ~MaxHeap(){}; //��������
    void BuildHeap();
    bool isLeaf(int pos) const;    //�����Ҷ��㣬����TRUE
    int leftchild(int pos) const;  //��������λ��
    int rightchild(int pos) const; //�����Һ���λ��
    int parent(int pos) const;     //���ظ����λ��
    bool Remove(int pos, T &node); //ɾ�������±��Ԫ��
    void SiftDown(int left);       //ɸѡ������������left��ʾ��ʼ����������±�
    void SiftUp(int position);     //��position���Ͽ�ʼ������ʹ���г�Ϊ��
    bool Insert(const T &newNode); //����в�����Ԫ��newNode
    void MoveMax();                //�ӶѶ��ƶ���Сֵ��β��
    void RemoveMax();                //�ӶѶ�ɾ����Сֵ
    T *getMaxHeap();
    int getCurrSize();
    void List();
    void heapSort();
};

template <class T>
int MaxHeap<T>::getCurrSize()
{
    return CurrentSize;
}

template <class T>
bool MaxHeap<T>::isLeaf(int pos) const
{
    if (2 * pos + 1 > CurrentSize - 1)
        return true;
    else
        return false;
}

template <class T>
int MaxHeap<T>::leftchild(int pos) const
{
    int leftchild;
    if (!isLeaf(pos))
    {
        leftchild = 2 * pos + 1;
        cout << pos << "�Ž�������Ϊ" << leftchild << "��" << endl;
    }
    else
        cout << pos << "�Ž����Ҷ�ӽ�㣬û������" << endl;
    return leftchild;
}

template <class T>
int MaxHeap<T>::rightchild(int pos) const
{
    int rightchild = 2 * pos + 2;
    if (rightchild < CurrentSize)
        cout << pos << "�Ž����Һ���Ϊ" << rightchild << "��" << endl;
    else
        cout << pos << "�Ž��û���Һ���" << endl;
    return rightchild;
}

template <class T>
int MaxHeap<T>::parent(int pos) const
{
    int parent = 0;
    if (pos > 0)
    {
        parent = (pos - 1) / 2;
        //cout << pos << "�Ž��ĸ����Ϊ" << parent << "��" << endl;
    }
    else
        cout << pos << "��λ���޸����" << endl;
    return parent;
}

template <class T>
bool MaxHeap<T>::Remove(int pos, T &node)
{
    int i = pos;
    int j = CurrentSize - 1;
    T temp = node;
    heapArray[i] = heapArray[j];
    heapArray[j] = temp;
    CurrentSize--;
    BuildHeap();//ˢ��
    return true;
}

template <class T>
void MaxHeap<T>::SiftUp(int position)
{
    int i = position;         //��ʶ������½��
    int j = parent(position); //��ʶ�����
    T temp = heapArray[i];    //�����½��Ĺؼ���
                              //��ɸ
    while (j >= 0)
    {
        if (temp > heapArray[j])
        {                                //�ý��Ĺؼ�����ڸ�����ֵʱ
            heapArray[i] = heapArray[j]; //������Ӧֵ
            i = j;
            j = parent(i); //���ϼ����ж��Ƿ�������С�ѵ�����
        }
        else
            break;
    }
    heapArray[i] = temp;
}

template <class T>
bool MaxHeap<T>::Insert(const T &newNode)
{
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize);
    CurrentSize++;
    return true;
}

template <class T>
T *MaxHeap<T>::getMaxHeap()
{
    return heapArray;
}

template <class T>
void MaxHeap<T>::BuildHeap()
{
    for (int i = CurrentSize / 2 - 1; i >= 0; i--)
        SiftDown(i);
}

template <class T>
void MaxHeap<T>::SiftDown(int left)//ɸѡ��
{
    int i = left;          //��ʶ�����
    int j = 2 * i + 1;     //��ʶ���ӽ��
    T temp = heapArray[i]; //���游���Ĺؼ���
                           //��ɸ
    while (j < CurrentSize)
    {
        if ((j < CurrentSize - 1) && (heapArray[j] < heapArray[j + 1]))
            j++;
        //�ý�����Һ������Һ��ӵĹؼ���������ӵĹؼ���ʱ��jָ�����ӽ�㣨ȡ�������ӽ�С��һ����
        if (temp < heapArray[j])
        {                                //�ý��Ĺؼ���������Һ����бȽ�С���Ǹ�ʱ
            heapArray[i] = heapArray[j]; //������Ӧֵ
            i = j;
            j = 2 * j + 1; //���¼����ж��Ƿ�������С�ѵ�����
        }
        else
            break;
    }
    heapArray[i] = temp;
}

template <class T>
void MaxHeap<T>::MoveMax()
{
    
}

template <class T>
void MaxHeap<T>::RemoveMax()
{
    if (this->CurrentSize > 0)
    {
        Remove(0,heapArray[0]);
        return;
    }
    cout << "�ն�" <<endl;
    exit(0);
}

template <class T>
void  MaxHeap<T>::List()
{
    for (int i = 0; i < getCurrSize()  ; i++)
    {
        cout << heapArray[i]<< ' ';
    }
    cout << endl;
}
template <class T>
void  MaxHeap<T>::heapSort()
{
    int _t=CurrentSize;
    int *tmp=new T[_t] ;
    for (int i = 0; i < _t; i++)
    {
        cout << heapArray[0] << ' ';
        tmp[i]=heapArray[i];
        RemoveMax();
    }
    heapArray=tmp;
}