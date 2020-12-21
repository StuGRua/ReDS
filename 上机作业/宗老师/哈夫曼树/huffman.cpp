#include<iostream>
#include<string>
#include<string.h>
using namespace std;

//哈夫曼树的存储结构
typedef struct
{
	char data;   //存储数据
	int weight;  //结点的权重
	string huffman_code;  //存放哈夫曼码
	int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
} HTNode, * HuffmanTree;

//两个最小结点
typedef struct
{
	int s1;
	int s2;
} MIN;

//选择结点权值最小的两个结点
MIN Select(HuffmanTree HT, int n)
{
	int min, secmin, s1, s2;
	min = 10000;
	secmin = 10000;
	MIN code;
	s1 = 1;
	s2 = 1;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && (HT[i].weight < min))
		{
			min = HT[i].weight;
			s1 = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && (HT[i].weight < secmin) && (i != s1))
		{
			secmin = HT[i].weight;
			s2 = i;
		}
	}
	code.s1 = s1;
	code.s2 = s2;
	return code;

}

//将哈夫曼码存储在结构体num中
void putlorinnum(HuffmanTree& hft, int num)
{
	for (int i = num; i >= 1; i--)
	{
		if (hft[hft[i].parent].parent)
		{
			hft[i].huffman_code = hft[hft[i].parent].huffman_code + hft[i].huffman_code;//更新哈夫曼编码
		}
	}
}


//创造哈夫曼树
void CreateHuffmanTree(HuffmanTree& HT, int num)
{

	int m;
	m = 2 * num - 1;
	HT = new HTNode[m + 1];   //分配空间
	for (int i = 1; i <= m; i++)   //初始化
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	cout << "请输入每个数据及其权值：" << endl;
	for (int i = 1; i <= num; i++)
	{
		cin >> HT[i].data;
		cin >> HT[i].weight;

	}

	for (int i = num + 1; i <= m; i++)  //构建哈夫曼树
	{
		MIN min;
		min = Select(HT, i - 1);      //选择二叉树
		HT[min.s1].parent = i;
		HT[min.s2].parent = i;
		HT[i].lchild = min.s1;
		HT[min.s1].huffman_code = "0";
		HT[i].rchild = min.s2;
		HT[min.s2].huffman_code = "1";
		HT[i].weight = HT[min.s1].weight + HT[min.s2].weight;
		HT[i].data = -1;
	}
	putlorinnum(HT, m);//注意是构建完树才进行编码的生成
	for (int i = 1; i <= m; i++)  //进行每个字符哈夫曼码的输出
	{
		if (HT[i].data != -1)
		{
			cout << HT[i].data << " 权重为" << HT[i].weight << "  ，哈夫曼码为：" << HT[i].huffman_code << endl;

			cout << endl;
		}
	}
}

//将一串字符编译成哈夫曼码
string changchartohft(HuffmanTree hft, string s, int m)
{
	string estring;
	for (int i = 0; i <= s.size(); i++)
	{
		for (int x = 1; x <= m; x++)
		{
			if (hft[x].data == s[i])//查找哈夫曼树中相应的字符
			{
				estring = estring + hft[x].huffman_code;//哈夫曼码连接
				x = m;
			}
		}
	}
	cout << estring << endl;
	return estring;
}



//将一串哈夫曼码解译成一串字符
void changhfttochar(HuffmanTree hft, string s, int m)
{
	string estring;
	int pos = 0, first = 0;
	for (int x = 0; x <= s.size(); x++)
	{
		pos++;
		for (int i = 1; i <= m; i++)
		{
			if (hft[i].huffman_code == s.substr(first, pos))//截取字符串和哈夫曼中哈夫曼码对比
			{
				cout << hft[i].data;
				first = pos + first;
				pos = 0;
			}
		}
	}
	cout << endl;
}

int main()
{
	//ADBDCDADBADBBCBD
	/*
	测试数据：
	4
	A 3 B 5 C 2 D 6
	A 19 B 31 C 13 D 38
	*/
	int num;  //结点的个数
	string s1 = "ADBDCDADBADBBCBD", s2;
	cout << "哈夫曼树叶子结点的个数：";
	cin >> num;
	//创造哈夫曼树
	HuffmanTree HT;
	CreateHuffmanTree(HT, num);


	cout <<"对 " <<s1<<" 进行编码：" << endl;
	s2 = changchartohft(HT, s1, num);

	cout << "解码：" << endl;
	changhfttochar(HT, s2, num);
	return 0;
}
