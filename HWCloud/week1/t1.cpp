#include <iostream>
using namespace std;

/*
TODO:从顺序表中删除具有最小值的元素并由函数返回被删元素的值，空出的位置由最后一个元素填补
参数说明：a-为顺序表
         n-为顺序表中元素个数，删除之后，需更新n值
 */
int deletemin(int* a, int& n)
{
    int min=*a;
    for (int i = 0; i < n; i++)
    {
        if (min>*(a+i))
        {
            min=*(a+i);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (*(a+i)==min)
        {
            *(a+i)=*(a+n-1);
            n--;
            
        }   
    }
    return min;
}
/*
TODO:从顺序表中删除具有给定x的所有元素，n为顺序表中元素个数，删除之后，需更新n值
 */
void deleteSame(int* a, int& n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a+i)==x)
        {
            for (int j = i; j < n; j++)
            {
                *(a+j)=*(a+j+1);
            }
            n--;
        }
    }
}
/*
TODO:从有序顺序表中删除其值在给定 s与t之间（s < t）的所有元素x，其中x满足s<x<t
n为顺序表中元素个数，删除之后，需更新n值
 */
void deleteSome(int* a, int& n, int s, int t)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a+i)<t&&*(a+i)>s)
        {
            //cout<<"in:"<<*(a+i)<<endl;
            for (int j = i; j < n; j++)
            {
                *(a+j)=*(a+j+1);
            }
            n--;
            i--;
        }
    }
}

void print(int* a, int& n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, samevalue, s, t;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // int a[10] = {5, 3, 2, 1, 9, 8, 4, 2, 7, 5};
    // int n = 10;
    cout << "顺序表数据为:";
    print(a, n);
    int min = deletemin(a, n);
    cout << "删除最小值后为:";
    print(a, n);
    cout << "最小值:" << min << endl;
    cin >> samevalue;
    deleteSame(a, n, samevalue);
    cout << "删除相同值后为:";
    print(a, n);
    cin >> s >> t;
    deleteSome(a, n, s, t);
    cout << "删除指定范围数值后为:";
    print(a, n);
    delete[] a;
    return 0;
}
