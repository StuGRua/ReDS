#include <iostream>
using namespace std;

/*
TODO:��˳�����ɾ��������Сֵ��Ԫ�ز��ɺ������ر�ɾԪ�ص�ֵ���ճ���λ�������һ��Ԫ���
����˵����a-Ϊ˳���
         n-Ϊ˳�����Ԫ�ظ�����ɾ��֮�������nֵ
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
TODO:��˳�����ɾ�����и���x������Ԫ�أ�nΪ˳�����Ԫ�ظ�����ɾ��֮�������nֵ
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
TODO:������˳�����ɾ����ֵ�ڸ��� s��t֮�䣨s < t��������Ԫ��x������x����s<x<t
nΪ˳�����Ԫ�ظ�����ɾ��֮�������nֵ
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
    cout << "˳�������Ϊ:";
    print(a, n);
    int min = deletemin(a, n);
    cout << "ɾ����Сֵ��Ϊ:";
    print(a, n);
    cout << "��Сֵ:" << min << endl;
    cin >> samevalue;
    deleteSame(a, n, samevalue);
    cout << "ɾ����ֵͬ��Ϊ:";
    print(a, n);
    cin >> s >> t;
    deleteSome(a, n, s, t);
    cout << "ɾ��ָ����Χ��ֵ��Ϊ:";
    print(a, n);
    delete[] a;
    return 0;
}
