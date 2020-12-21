#include <iostream>
#include "AdjGraph.h"
using namespace std;


class MaxHeap
{

public:
    Edge<int> *heapArray; //存放堆数据的数组
    int CurrentSize;     //当前堆中元素数目
    int MaxSize;         //堆所能容纳的最大元素数目
    MaxHeap(Edge<int> *array, int num, int Max)
    {
        this->heapArray = new Edge<int>[num];
        for (int i = 0; i < num; i++)
        {
            this->heapArray[i] = array[i];
        }
        this->CurrentSize = num;
        this->MaxSize = Max;
    }



int getCurrSize()
{
    return CurrentSize;
}


bool isLeaf(int pos) const
{
    if (2 * pos + 1 > CurrentSize - 1)
        return true;
    else
        return false;
}



int parent(int pos) const
{
    int parent = 0;
    if (pos > 0)
    {
        parent = (pos - 1) / 2;
        //cout << pos << "号结点的父结点为" << parent << "号" << endl;
    }
    else
        cout << pos << "号位置无父结点" << endl;
    return parent;
}


bool Remove(int pos, Edge<int> &node)
{
    int i = pos;
    int j = CurrentSize - 1;
    Edge<int> temp = node;
    heapArray[i] = heapArray[j];
    heapArray[j] = temp;
    CurrentSize--;
    BuildHeap(); //刷新
    return true;
}


void SiftUp(int position)
{
    int i = position;         //标识插入的新结点
    int j = parent(position); //标识父结点
    Edge<int> temp = heapArray[i];    //保存新结点的关键码
                              //过筛
    while (j >= 0)
    {
        if (temp.weight > heapArray[j].weight)
        {                                //该结点的关键码大于父结点的值时
            heapArray[i] = heapArray[j]; //交换对应值
            i = j;
            j = parent(i); //向上继续判断是否满足最小堆的性质
        }
        else
            break;
    }
    heapArray[i] = temp;
}


bool Insert(const Edge<int> &newNode)
{
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize);
    CurrentSize++;
    return true;
}


Edge<int> *getMaxHeap()
{
    return heapArray;
}


void BuildHeap()
{
    for (int i = CurrentSize / 2 - 1; i >= 0; i--)
        SiftDown(i);
}


void SiftDown(int left) //筛选法
{
    int i = left;          //标识父结点
    int j = 2 * i + 1;     //标识左子结点
    Edge<int> temp = heapArray[i]; //保存父结点的关键码
                           //过筛
    while (j < CurrentSize)
    {
        if ((j < CurrentSize - 1) && (heapArray[j].weight < heapArray[j + 1].weight))
            j++;
        //该结点有右孩子且右孩子的关键码大于左孩子的关键码时，j指向右子结点（取两个孩子较小的一个）
        if (temp.weight < heapArray[j].weight)
        {                                //该结点的关键码大于左右孩子中比较小的那个时
            heapArray[i] = heapArray[j]; //交换对应值
            i = j;
            j = 2 * j + 1; //向下继续判断是否满足最小堆的性质
        }
        else
            break;
    }
    heapArray[i] = temp;
}


void MoveMax()
{
}


void RemoveMax()
{
    if (this->CurrentSize > 0)
    {
        Remove(0, heapArray[0]);
        return;
    }
    cout << "空堆" << endl;
    exit(0);
}


void List()
{
    for (int i = 0; i < getCurrSize(); i++)
    {
        cout << heapArray[i].start <<"to" <<heapArray[i].end<< ' ';
    }
    cout << endl;
}

void heapSort()
{
    int _t = CurrentSize;
    Edge<int> *tmp = new Edge<int>[_t];
    for (int i = 0; i < _t; i++)
    {
        cout << heapArray[0].start<<"to" <<heapArray[i].end<< ' ';
        tmp[i] = heapArray[i];
        RemoveMax();
    }
    heapArray = tmp;
}
};
