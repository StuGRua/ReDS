/*
��ʼ״̬��V={v1},TE={},V1Ϊĳһ����
�����е�vi�У�Ѱ�Ҳ���V�д�����С�ıߣ�����TE��
��V��ԭͼ�������ͬ�����
nearest[i]��ʾ�������е㵽i�����С��Ȩֵ
neighbor[j]��ʾ����������i������ĵ���
MST�洢��С��������
*/
#ifndef INCLUDE_PRIM
#define INCLUDE_PRIM
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include <iostream>
#include "Edge.h"
#include "Graph.h"
#include "AdjGraph.h"
using namespace std;
template <class EdgeType>
Edge<EdgeType> *Prim(Graph<EdgeType> &G, int s)
{ //Ӧ��Prim�㷨��s��������õ�����С������
	int i, j;
	Edge<EdgeType> *MST; //�洢��С�������ı�
	//�������㵽�������еĸ����������̵ı�
	EdgeType *nearest; //nearest[i]��ʾ�������е㵽i�����С��Ȩֵ
	int *neighbor;	 //neighbor[i]��ʾ����������i������ĵ��ţ�
	//-1��ʾi���Ѿ���������������
	int n = G.VerticesNum(); //ͼ�Ķ������

	nearest = new EdgeType[n];
	neighbor = new int[n];
	MST = new Edge<EdgeType>[n - 1];
	for (i = 0; i < n; i++) //��ʼ��neighor�����nearest����
	{
		neighbor[i] = s;
		nearest[i] = AFFINITY;
	}
	//��s���ڽӵĶ���ı�Ȩֵ ��Ϊ��Щ�� �������������ϵ���̱߳�
	for (Edge<EdgeType> e = G.FirstEdge(s); G.Isedge(e); e = G.NextEdge(e))
	{
		nearest[e.end] = e.weight;
	}

	neighbor[s] = -1; //���Ѽ��뵽�������ĵ�����������Ϊ-1

	for (i = 1; i < n; i++)//��ѭ�����������ж���
	{							 //i����Ѿ����뵽�������еĵ����
		EdgeType min = AFFINITY; //��¼��СȨֵ
		int v = -1;				 //��¼��һ����Ҫ���뵽�����еĵ�
		for (j = 0; j < n; j++)//�������ж����ҵ�Ȩֵ��С·����
		{ //ȷ��һ�����������������ϣ�һ�����㲻��������������Ȩֵ��С�ı��������Ķ���
			if (nearest[j] < min && neighbor[j] > -1)
			{
				min = nearest[j];
				v = j;
			}
		} //for(j)
		if (v >= 0)
		{ //��v���뵽������������,���µ���������ĸ�������СȨֵ�ı���Ϣ
			Edge<EdgeType> tempEdge(neighbor[v], v, nearest[v]);
			MST[i - 1] = tempEdge; //���߼��뵽������������
			neighbor[v] = -1;//�Ѽ���ı��-1�����жϻ�
			for (Edge<EdgeType> e = G.FirstEdge(v); G.Isedge(e); e = G.NextEdge(e))//�߸���ѭ����vΪ��ǰ����ĵ㣬eΪ��ǰ����ıߣ�uΪ����ıߵ�Ŀ���
			{
				int u = e.end;
				if (neighbor[u] != -1 && nearest[u] > e.weight)
				{ //����v�����ı߸���������֮�ⶥ�㵽���������ϵ���СȨֵ��
					neighbor[u] = v;
					nearest[u] = e.weight;
				}
			}		   //for(e)
		}			   //if(v>=0)
	}				   //for(i)
	delete[] neighbor;
	delete[] nearest;
	return MST;
}
#endif