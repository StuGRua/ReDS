#include <iostream>
#include <string.h>
using namespace std;

/*
TODO��1.7-a.���ص�ģʽƥ���㷨�������Ӵ���һ�γ��ֵ�λ�ã��������ڣ�����-1
*/
int NaiveStrMatch(const string& T, const string& P)
{
    int p = 0;			   //ģʽ���±����
	int t = 0;			   //Ŀ����±����
	int plen = P.length(); //ģʽ�ĳ���
	int tlen = T.length(); //Ŀ��ĳ���
	if (tlen < plen)	   //���Ŀ���ģʽ�̣�ƥ���޷��ɹ�
		return -1;
	while (p < plen && t < tlen) //�����Ƚ϶�Ӧ�ַ�����ƥ��
	{
		if (T[t] == P[p])
		{
			p++;
			t++;
		}
		else
		{
			t = t - p + 1;
			p = 0;
		}
	}
	if (p >= plen)
		return (t - plen);
	else
		return -1;
}
int main()
{
    int result;
    string t = "I Lo Love Programing";
    string p = "Love";
    getline(cin, t);
    getline(cin, p);
    result = NaiveStrMatch(t, p);
    if (result != -1) {
        cout << "Ŀ���ַ����д����ڵ�" << result << "λ��" << endl;
    } else {
        cout << "û���ҵ�" << endl;
    }
    return 0;
}