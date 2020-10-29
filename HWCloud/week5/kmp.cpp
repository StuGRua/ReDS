#include <assert.h>
#include <iostream>
#include <string.h>

using namespace std;

/*
TODO:1.7-b.	计算字符串p的特征向量的算法，返回特征向量的数组。
 */
int* next(string P)
{
    int m = P.size();         		//模式P的长度
	assert(m > 0);                	//若长度等于0，则退出
	int * N = new int[m];          	//主数组
	assert(N != 0);
	N[0] = 0;//第一位无后缀串
	for(int i = 1; i < m; i++)    	//对P的每一个位置进行分析
	{
		int k = N[i - 1];         	//第i-1位置的最长前缀串长度（读取上一位的最长前缀长度）
		while(k > 0 && P[i] != P[k])//模式读取位置和偏移位置处不匹配
			k = N[k - 1];			//回退最大长度直到0或匹配成功
		if(P[i] == P[k])			//模式读取位置和偏移位置处匹配则长度+1
			N[i] = k + 1;
		else
			N[i] = 0;
	}
	return N;
}

/*
TODO:1.7-c.	KMP模式匹配算法，返回子串第一次出现的位置，若不存在，返回-1
参数说明：T为原始字符串
         P为子串
		 N为字符串P的特征向量
返回值说明：通过KMP算法如果查找到子串，则返回子串第一次出现的位置，
否则没有查找到，返回-1
*/
int KMPStrMatching(string T, string P, int* N, int startIndex)
{
    int lastIndex = T.size() - P.size();
	if((lastIndex - startIndex) < 0) //若startIndex过大，则无法匹配成功
		return (-1);
	int i;                         	//指向T内部字符的游标
	int j = 0;                    	//指向P内部字符的游标
	for(  i = startIndex;i < T.size(); i++)
	{
		while(P[j] != T[i] && j > 0)//不匹配时，右移特征向量位数
			j = N[j - 1];               
		if(P[j] == T[i])		//当P的第j位和T的第i位相同时，则继续
			j++;
		if(j == P.size())
			return (i -j + 1);	//j到达末位，匹配成功，返回该T子串的开始位置
	}
	return (-1);
}

int main()
{
    string p; //要查找的字符串
    string q; //原始字符串
    getline(cin, p);
    getline(cin, q);
    int* N;
    N = next(p);
    for (int i = 0; i < p.length(); i++)
        cout << N[i] << " ";
    cout << endl;
    cout << KMPStrMatching(q, p, N, 0) << endl;
}