#include<iostream>
#include<queue>
#include<stack>
#include"graph.h"
#include"AdjGraph.h"
#include"ListData.h"
using namespace std;
int main()
{
	cout << "AdjGraph:" << endl;
	AdjGraph <int> tu(8);     //图的邻接矩阵实现
	tu.setEdge(0,1,1);
	tu.setEdge(0,2,1);
	tu.setEdge(1,0,1);
	tu.setEdge(1,3,1);
	tu.setEdge(1,4,1);
	tu.setEdge(2,0,1);
	tu.setEdge(2,5,1);
	tu.setEdge(2,6,1);
	tu.setEdge(3,1,1);
	tu.setEdge(3,7,1);
	tu.setEdge(4,1,1);
	tu.setEdge(4,7,1);
	tu.setEdge(5,2,1);
	tu.setEdge(5,6,1);
	tu.setEdge(6,2,1);
	tu.setEdge(6,5,1);
	tu.setEdge(7,3,1);
	tu.setEdge(7,4,1);
	cout << "DFS" << endl;
	tu.DFStraverse();
	cout << endl;
	cout << "DFSNoReverse" << endl;
	tu.DFSNoReverse();
	cout << endl;
	cout << "BFS" << endl;
	tu.BFStraverse();
	cout<<endl;
	cout << endl;

	cout << "ListGraph:" << endl;
	ListGraph <int> tu_2(8);  //图的邻接表实现
	tu_2.setEdge(0, 1, 1);
	tu_2.setEdge(0, 2, 1);
	tu_2.setEdge(1, 0, 1);
	tu_2.setEdge(1, 3, 1);
	tu_2.setEdge(1, 4, 1);
	tu_2.setEdge(2, 0, 1);
	tu_2.setEdge(2, 5, 1);
	tu_2.setEdge(2, 6, 1);
	tu_2.setEdge(3, 1, 1);
	tu_2.setEdge(3, 7, 1);
	tu_2.setEdge(4, 1, 1);
	tu_2.setEdge(4, 7, 1);
	tu_2.setEdge(5, 2, 1);
	tu_2.setEdge(5, 6, 1);
	tu_2.setEdge(6, 2, 1);
	tu_2.setEdge(6, 5, 1);
	tu_2.setEdge(7, 3, 1);
	tu_2.setEdge(7, 4, 1);
	cout << "DFS" << endl;
	tu_2.DFStraverse();
	cout << endl;
	cout << "DFSNoReverse" << endl;
	tu_2.DFSNoReverse();
	cout << endl;
	cout << "BFS" << endl;
	tu_2.BFStraverse();
	cout << endl;
	return 0;
}
