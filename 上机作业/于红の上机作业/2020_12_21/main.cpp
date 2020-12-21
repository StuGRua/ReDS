#include <iostream>
#include "Prim.h"
#include "Dijkstra.h"
#include "Floyd.h"
using namespace std;
void Prim()
{
	//例4.8 采用书上图4-15(a)的图  (b)为结果
	AdjGraph<int> adjGWei(6); //无向无权，第二个参数表示有无权重，第三个参数表示有向无向，下面的例子同理
	adjGWei.setEdge(0, 0, AFFINITY);
	adjGWei.setEdge(0, 1, 6);
	adjGWei.setEdge(0, 2, 1);
	adjGWei.setEdge(0, 3, 5);
	adjGWei.setEdge(0, 4, AFFINITY);
	adjGWei.setEdge(0, 5, AFFINITY);
	adjGWei.setEdge(1, 0, 6);
	adjGWei.setEdge(1, 1, AFFINITY);
	adjGWei.setEdge(1, 2, 5);
	adjGWei.setEdge(1, 3, AFFINITY);
	adjGWei.setEdge(1, 4, 3);
	adjGWei.setEdge(1, 5, AFFINITY);
	adjGWei.setEdge(2, 0, 1);
	adjGWei.setEdge(2, 1, 5);
	adjGWei.setEdge(2, 2, AFFINITY);
	adjGWei.setEdge(2, 3, 5);
	adjGWei.setEdge(2, 4, 6);
	adjGWei.setEdge(2, 5, 4);
	adjGWei.setEdge(3, 0, 5);
	adjGWei.setEdge(3, 1, AFFINITY);
	adjGWei.setEdge(3, 2, 5);
	adjGWei.setEdge(3, 3, AFFINITY);
	adjGWei.setEdge(3, 4, AFFINITY);
	adjGWei.setEdge(3, 5, 2);
	adjGWei.setEdge(4, 0, AFFINITY);
	adjGWei.setEdge(4, 1, 3);
	adjGWei.setEdge(4, 2, 6);
	adjGWei.setEdge(4, 3, AFFINITY);
	adjGWei.setEdge(4, 4, AFFINITY);
	adjGWei.setEdge(4, 5, 6);
	adjGWei.setEdge(5, 0, AFFINITY);
	adjGWei.setEdge(5, 1, AFFINITY);
	adjGWei.setEdge(5, 2, 4);
	adjGWei.setEdge(5, 3, 2);
	adjGWei.setEdge(5, 4, 6);
	adjGWei.setEdge(5, 5, AFFINITY);
	Edge<int> *edge;
	int n = adjGWei.vertexNum - 1;
	edge = Prim(adjGWei, 0);
	cout << "prim算法:" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << "边的起点是:" << edge[j].start + 1 << "   终点是:" << edge[j].end + 1 << "    权值是:" << edge[j].weight << endl;
	}
	system("pause");
}

void DJS()
{
	//例4.11 采用书上图4-18的图
	AdjGraph<int> adjGWeiDi(6);
	adjGWeiDi.setEdge(0, 0, AFFINITY);
	adjGWeiDi.setEdge(0, 1, 12);
	adjGWeiDi.setEdge(0, 2, 10);
	adjGWeiDi.setEdge(0, 3, AFFINITY);
	adjGWeiDi.setEdge(0, 4, 30);
	adjGWeiDi.setEdge(0, 5, 100);
	adjGWeiDi.setEdge(1, 0, AFFINITY);
	adjGWeiDi.setEdge(1, 1, AFFINITY);
	adjGWeiDi.setEdge(1, 2, 5);
	adjGWeiDi.setEdge(1, 3, AFFINITY);
	adjGWeiDi.setEdge(1, 4, AFFINITY);
	adjGWeiDi.setEdge(1, 5, AFFINITY);
	adjGWeiDi.setEdge(2, 0, AFFINITY);
	adjGWeiDi.setEdge(2, 1, AFFINITY);
	adjGWeiDi.setEdge(2, 2, AFFINITY);
	adjGWeiDi.setEdge(2, 3, 50);
	adjGWeiDi.setEdge(2, 4, AFFINITY);
	adjGWeiDi.setEdge(2, 5, AFFINITY);
	adjGWeiDi.setEdge(3, 0, AFFINITY);
	adjGWeiDi.setEdge(3, 1, AFFINITY);
	adjGWeiDi.setEdge(3, 2, AFFINITY);
	adjGWeiDi.setEdge(3, 3, AFFINITY);
	adjGWeiDi.setEdge(3, 4, AFFINITY);
	adjGWeiDi.setEdge(3, 5, 10);
	adjGWeiDi.setEdge(4, 0, AFFINITY);
	adjGWeiDi.setEdge(4, 1, AFFINITY);
	adjGWeiDi.setEdge(4, 2, AFFINITY);
	adjGWeiDi.setEdge(4, 3, 20);
	adjGWeiDi.setEdge(4, 4, AFFINITY);
	adjGWeiDi.setEdge(4, 5, 60);
	adjGWeiDi.setEdge(5, 0, AFFINITY);
	adjGWeiDi.setEdge(5, 1, AFFINITY);
	adjGWeiDi.setEdge(5, 2, AFFINITY);
	adjGWeiDi.setEdge(5, 3, AFFINITY);
	adjGWeiDi.setEdge(5, 4, AFFINITY);
	adjGWeiDi.setEdge(5, 5, AFFINITY);
	cout << "Dijkstra算法:" << endl;
	int *D = new int[6];
	int *P = new int[6];
	Dijkstra(adjGWeiDi, 0, D, P);
	PrintDj(adjGWeiDi, 0, D, P);
	system("pause");
}

void Floyd()
{
	//例4.12 采用书上图4-20的图
	int n = 3;
	cout << "Floyd算法:" << endl;
	int **adjArray = new int *[n];
	for (int i = 0; i < n; i++)
	{
		adjArray[i] = new int[n];
	}
	int **Path = new int *[n];
	for (int j = 0; j < n; j++)
	{
		Path[j] = new int[n];
	}
	AdjGraph<int> adjGWeiDiTwo(3);
	adjGWeiDiTwo.setEdge(0, 0, AFFINITY);
	adjGWeiDiTwo.setEdge(0, 1, 5);
	adjGWeiDiTwo.setEdge(0, 2, 10);
	adjGWeiDiTwo.setEdge(1, 0, 2);
	adjGWeiDiTwo.setEdge(1, 1, AFFINITY);
	adjGWeiDiTwo.setEdge(1, 2, 13);
	adjGWeiDiTwo.setEdge(2, 0, 9);
	adjGWeiDiTwo.setEdge(2, 1, 6);
	adjGWeiDiTwo.setEdge(2, 2, AFFINITY);
	Floyd(adjGWeiDiTwo, adjArray, Path);
	PrintFloyd(adjGWeiDiTwo, adjArray, Path);
	system("pause");
}
int main()
{
	Prim();
	DJS();
	Floyd();
	return 0;
}