#include"Prim.h"
int main()
{
	//例4.8 采用书上图4-15(a)的图  (b)为结果	
	AdjGraph<int> adjGWei(6);//无向无权，第二个参数表示有无权重，第三个参数表示有向无向，下面的例子同理
	adjGWei.setEdge(0, 0, AFFINITY); adjGWei.setEdge(0, 1, 6); adjGWei.setEdge(0, 2, 1); adjGWei.setEdge(0, 3, 5); adjGWei.setEdge(0, 4, AFFINITY); adjGWei.setEdge(0, 5, AFFINITY);
	adjGWei.setEdge(1, 0, 6); adjGWei.setEdge(1, 1, AFFINITY); adjGWei.setEdge(1, 2, 5); adjGWei.setEdge(1, 3, AFFINITY); adjGWei.setEdge(1, 4, 3); adjGWei.setEdge(1, 5, AFFINITY);
	adjGWei.setEdge(2, 0, 1); adjGWei.setEdge(2, 1, 5); adjGWei.setEdge(2, 2, AFFINITY); adjGWei.setEdge(2, 3, 5); adjGWei.setEdge(2, 4, 6); adjGWei.setEdge(2, 5, 4);
	adjGWei.setEdge(3, 0, 5); adjGWei.setEdge(3, 1, AFFINITY); adjGWei.setEdge(3, 2, 5); adjGWei.setEdge(3, 3, AFFINITY); adjGWei.setEdge(3, 4, AFFINITY); adjGWei.setEdge(3, 5, 2);
	adjGWei.setEdge(4, 0, AFFINITY); adjGWei.setEdge(4, 1, 3); adjGWei.setEdge(4, 2, 6); adjGWei.setEdge(4, 3, AFFINITY); adjGWei.setEdge(4, 4, AFFINITY); adjGWei.setEdge(4, 5, 6);
	adjGWei.setEdge(5, 0, AFFINITY); adjGWei.setEdge(5, 1, AFFINITY); adjGWei.setEdge(5, 2, 4); adjGWei.setEdge(5, 3, 2); adjGWei.setEdge(5, 4, 6); adjGWei.setEdge(5, 5, AFFINITY);
	Edge<int>*  edge;
	int n = adjGWei.vertexNum - 1;
	edge = Prim(adjGWei, 0);
	cout << "prim算法:" << endl;
	for (int j = 0; j < n; j++){
		cout << "边的起点是:" << edge[j].start + 1 << "   终点是:" << edge[j].end + 1 << "    权值是:" << edge[j].weight << endl;
	}
    return 0;
}