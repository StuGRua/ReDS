#include <iostream>
#include <string.h>
using namespace std;

/*
TODO：1.7-a.朴素的模式匹配算法，返回子串第一次出现的位置，若不存在，返回-1
*/
int NaiveStrMatch(const string& T, const string& P)
{
    int p = 0;			   //模式的下标变量
	int t = 0;			   //目标的下标变量
	int plen = P.length(); //模式的长度
	int tlen = T.length(); //目标的长度
	if (tlen < plen)	   //如果目标比模式短，匹配无法成功
		return -1;
	while (p < plen && t < tlen) //反复比较对应字符进行匹配
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
        cout << "目标字符串中存在于第" << result << "位上" << endl;
    } else {
        cout << "没有找到" << endl;
    }
    return 0;
}