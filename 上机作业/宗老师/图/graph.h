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
class Graph //ͼ����
{
public:
	int vertexNum;  //ͼ�Ķ�����Ŀ
	int edgeNum;	//ͼ�ı���Ŀ
	int *Mark;		//���ĳ�����Ƿ񱻷��ʹ�,���ʹ�Ϊ1��û����Ϊ0
	bool Cflag; //�����
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
	virtual Edge<EdgeType> FirstEdge(int onevertex) = 0;		 //�����붥��������ĵ�һ����
	virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge) = 0; //������oneedge����ͬ������һ����
	int VerticesNum()											 //����ͼ�Ķ������
	{
		return vertexNum;
	}
	int edgesnum() //���ر߸���
	{
		return edgeNum;
	}
	bool Isedge(Edge<EdgeType> oneEdge) //�ж��Ƿ�Ϊ��
	{
		if (oneEdge.weight > 0 && oneEdge.weight < INFINITY && oneEdge.end >= 0)
			return true;
		else
			return false;
	}
	int StartVertex(Edge<EdgeType> oneEdge) //���رߵ�ʼ��
	{
		return oneEdge.start;
	}
	int EndVertex(Edge<EdgeType> oneEdge) //���رߵ��յ�
	{
		return oneEdge.end;
	}
	EdgeType Weight(Edge<EdgeType> oneEdge) //���رߵ�Ȩ��
	{
		return oneEdge.weight;
	}
	virtual void setEdge(int start, int end, EdgeType weight) = 0; //���ñ�
	virtual void delEdge(int start, int end) = 0;				   //ɾ����
	virtual void editEdge(int start, int end,EdgeType weight) = 0;
	void visit(int v)											   //���ʽ��
	{
		cout << v << ' ';
	}
	void DFS(int v) //��ĳ���㿪ʼ�ݹ������������
	{
		visit(v);//���
		Mark[v] = VISITED;
		for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))//��δ���ʽ���������������������򲻵���
		{
			if (Mark[EndVertex(e)] == UNVISITED)
				DFS(EndVertex(e));
		}
	}
	void DFStraverse() //ͼ�ĵݹ������������
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
	void DFSNoReverse() //�ǵݹ鷨������ȱ��������ƶ������������
	{
		int i, v, u;//vΪ������㣬u�ڽӵ�
		stack<int> s;
		for (i = 0; i < VerticesNum(); i++)
			Mark[i] = UNVISITED;
		for (i = 0; i < VerticesNum(); i++)
		{
			if (Mark[i] == UNVISITED)//δ���ʽ����ʲ���ջ
			{
				s.push(i);
				visit(i);
				Mark[i] = VISITED;
				while (!s.empty())//ֱ��ջ��Ϊֹ
				{
					v = s.top();
					Edge<EdgeType> e;
					for (e = FirstEdge(v); Isedge(e); e = NextEdge(e))//δ���ʵĵ���ʲ���ջ
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
	void BFS(int v) //��ĳ��㿪ʼ�����������
	{
		queue<int> Q;
		// ������
		Mark[v] = VISITED;
		visit(v);
		Q.push(v);
		while (!Q.empty())//ִ�е�������Ԫ��
		{
			v = Q.front();
			Q.pop();
			for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))//���ڵ�δ���ʵ���ʲ����
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
	void BFStraverse() //ͼ�Ĺ����������
	{
		int v;
		for (v = 0; v < VerticesNum(); v++)
			Mark[v] = UNVISITED;//��λ
		for (v = 0; v < VerticesNum(); v++)//��δ���ʵĵ㿪ʼ����
		{
			if (Mark[v] == UNVISITED)
				BFS(v);
		}
	}

	void DFSI(int v)//����������һ����볣��DFS��ͬ����Mark��ȡֵ�����֣�������ֵ2�������ڴ�����
	{
		if (Cflag)//CflagΪ��ǻ�λ
			return;
		visit(v);
		Mark[v] = 2;//��Ǵ����е�״̬
		for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))
		{
			if (Mark[EndVertex(e)] == UNVISITED)
			{
				
				DFSI(EndVertex(e));
			}
			else if (Mark[EndVertex(e)] == 2)//���·�����ص����ڴ����·���㣬��Ϊ�ҵ�������ǲ��˳�
			{
				Cflag = 1;
				//cout << "Have cycle!"<<endl;
				return;
			}
		}
		Mark[v] = VISITED;//�˳�����״̬������Ѵ���״̬
	}

	bool DCycle()//��ʾ����������
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