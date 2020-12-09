#pragma once
#include <iostream>
#include "Edge.h"
#include "queue"
#include "stack"
#define INFINITY INT_MAX
#define VISITED 1
#define UNVISITED 0
using namespace std;
template <class EdgeType>
class Graph //图类型
{
public:
	int vertexNum;  //图的顶点数目
	int edgeNum;	//图的边数目
	int *Mark;		//标记某顶点是否被访问过,访问过为1，没访问为0
	bool Cflag; //环标记
	queue<int> Path;
	Graph(int verticesNum)
	{
		vertexNum = verticesNum;
		edgeNum = 0;
		Cflag=0;
		Mark = new int[verticesNum];
		for (int i = 0; i < verticesNum; i++)
		{
			Mark[i] = UNVISITED;
		}
	}
	~Graph()
	{
		delete[] Mark;
	}
	virtual Edge<EdgeType> FirstEdge(int onevertex) = 0;		 //返回与顶点相关联的第一条边
	virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge) = 0; //返回与oneedge有相同起点的下一条边
	int VerticesNum()											 //返回图的顶点个数
	{
		return vertexNum;
	}
	int edgesnum() //返回边个数
	{
		return edgeNum;
	}
	bool Isedge(Edge<EdgeType> oneEdge) //判断是否为边
	{
		if (oneEdge.weight > 0 && oneEdge.weight < INFINITY && oneEdge.end >= 0)
			return true;
		else
			return false;
	}
	int StartVertex(Edge<EdgeType> oneEdge) //返回边的始点
	{
		return oneEdge.start;
	}
	int EndVertex(Edge<EdgeType> oneEdge) //返回边的终点
	{
		return oneEdge.end;
	}
	EdgeType Weight(Edge<EdgeType> oneEdge) //返回边的权重
	{
		return oneEdge.weight;
	}
	virtual void setEdge(int start, int end, EdgeType weight) = 0; //设置边
	virtual void delEdge(int start, int end) = 0;				   //删除边
	virtual void editEdge(int start, int end,EdgeType weight) = 0;
	void visit(int v)											   //访问结点
	{
		cout << v << ' ';
	}
	void DFS(int v) //从某顶点开始递归深度优先搜索
	{
		visit(v);//输出
		Mark[v] = VISITED;
		for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))//从未访问结点继续调用深度搜索，否则不调用
		{
			if (Mark[EndVertex(e)] == UNVISITED)
				DFS(EndVertex(e));
		}
	}
	void DFStraverse() //图的递归深度优先搜索
	{
		int i;
		for (i = 0; i < VerticesNum(); i++)
			Mark[i] = UNVISITED;
		for (i = 0; i < VerticesNum(); i++)
		{
			if (Mark[i] == UNVISITED)
				DFS(i);
		}
	}
	void DFSNoReverse() //非递归法深度优先遍历，类似二叉树中序遍历
	{
		int i, v, u;//v为出发结点，u邻接点
		stack<int> s;
		for (i = 0; i < VerticesNum(); i++)
			Mark[i] = UNVISITED;
		for (i = 0; i < VerticesNum(); i++)
		{
			if (Mark[i] == UNVISITED)//未访问结点访问并入栈
			{
				s.push(i);
				visit(i);
				Mark[i] = VISITED;
				while (!s.empty())//直到栈空为止
				{
					v = s.top();
					Edge<EdgeType> e;
					for (e = FirstEdge(v); Isedge(e); e = NextEdge(e))//未访问的点访问并入栈
					{
						u = EndVertex(e);
						if (Mark[u] == UNVISITED)
						{
							s.push(u);
							visit(u);
							Mark[u] = VISITED;
							break;
						}
					}
					if (!Isedge(e))
						s.pop();
				}
			}
		}
	}
	void BFS(int v) //从某结点开始广度优先搜索
	{
		queue<int> Q;
		// 标记入队
		Mark[v] = VISITED;
		visit(v);
		Q.push(v);
		while (!Q.empty())//执行到队中无元素
		{
			v = Q.front();
			Q.pop();
			for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))//相邻的未访问点访问并入队
			{
				int u = Mark[EndVertex(e)];
				int m = EndVertex(e);
				if (u == UNVISITED)
				{
					visit(m);
					Mark[m] = VISITED;
					Q.push(m);
				}
			}
		}
	}
	void BFStraverse() //图的广度优先搜索
	{
		int v;
		for (v = 0; v < VerticesNum(); v++)
			Mark[v] = UNVISITED;//归位
		for (v = 0; v < VerticesNum(); v++)//从未访问的点开始搜索
		{
			if (Mark[v] == UNVISITED)
				BFS(v);
		}
	}

	void DFSI(int v)//深度搜索查找环，与常规DFS不同的是Mark的取值有三种，新增的值2代表正在处理中
	{
		if (Cflag)//Cflag为标记环位
			return;
		visit(v);
		Mark[v] = 2;//标记处理中的状态
		for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))
		{
			if (Mark[EndVertex(e)] == UNVISITED)
			{
				
				DFSI(EndVertex(e));
			}
			else if (Mark[EndVertex(e)] == 2)//如果路径返回到正在处理的路径点，即为找到环，标记并退出
			{
				Cflag = 1;
				//cout << "Have cycle!"<<endl;
				return;
			}
		}
		Mark[v] = VISITED;//退出处理状态，标记已处理状态
	}

	bool DCycle()//显示环辅助函数
	{
		if(Cflag==1) 
		{
			cout << "There is a cycle."<<endl;
			return 1;
		}
		else 
		{
			cout << "There is no cycle."<<endl;
			return 0;
		}
	}
};