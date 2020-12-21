#include<iostream>
#include<queue>
#include<stack>
#include"graph.h"
#include"AdjGraph.h"
#include"BreakCycle.h"

int main()
{
	//采用书上图4-24(b)的图
	AdjGraph<int>  adjTuoPo(4);
	int sort[4]={0};
	adjTuoPo.setEdge(0, 0, 0); adjTuoPo.setEdge(0, 1, 1); adjTuoPo.setEdge(0, 2, 1); adjTuoPo.setEdge(0, 3, 0);
	adjTuoPo.setEdge(1, 0, 0); adjTuoPo.setEdge(1, 1, 0); adjTuoPo.setEdge(1, 2, 0); adjTuoPo.setEdge(1, 3, 1);
	adjTuoPo.setEdge(2, 0, 0); adjTuoPo.setEdge(2, 1, 1); adjTuoPo.setEdge(2, 2, 0); adjTuoPo.setEdge(2, 3, 0);
	adjTuoPo.setEdge(3, 0, 0); adjTuoPo.setEdge(3, 1, 0); adjTuoPo.setEdge(3, 2, 1); adjTuoPo.setEdge(3, 3, 0);
    adjTuoPo.DFSI(0);
	cout << endl;
	adjTuoPo.DCycle();
	Edge<int>*  edge;
	int n = adjTuoPo.vertexNum - 1;
	edge = BreakCircle(adjTuoPo);
	cout << "prim算法:" << endl;
	for (int j = 0; j < n; j++){
		cout << "边的起点是:" << edge[j].start + 1 << "   终点是:" << edge[j].end + 1 << "    权值是:" << edge[j].weight << endl;
	}
    return 0;
}