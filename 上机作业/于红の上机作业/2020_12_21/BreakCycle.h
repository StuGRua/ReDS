#include<iostream>
#include <assert.h>
#include"Edge.h"
#include"MaxHeap.h"
template<class EdgeType>
Edge<EdgeType> *BreakCircle(Graph<EdgeType>& G)
{
    int n, i, MSTNum = 0;
    Edge<EdgeType> *MST;
    n = G.VerticesNum();
    MST = new Edge<EdgeType>[n];
    Edge<EdgeType> e, temp;
    MaxHeap heap(MST,0,n);
    for (i = 0; i < G.VerticesNum(); i++)
    {
        for (e = G.FirstEdge(i); G.Isedge(e); e = G.NextEdge(e))
        {
            if (e.start < e.end)
            {
                heap.Insert(e);
            }
        }
    }
    while (heap.getCurrSize() > 0)
    {
        Edge<EdgeType> *tmp=heap.getMaxHeap();
        e=tmp[0];
        heap.RemoveMax();
        temp = e;
        G.editEdge(e.start,e.end,1000);
        G.editEdge(e.end,e.start,1000);
        //G.matrix[e.start][e.end] = 1000;
        //G.matrix[e.end][e.start] = 1000;
        if (!G.DCycle()) //如果图不连通,恢复
        {
            G.setEdge(e.start,e.end,e.weight);
            G.setEdge(e.start,e.end,e.weight);
            //matrix[e.start][e.end] = e.weight;
            //matrix[e.end][e.start] = e.weight;
            MST[MSTNum++] = e;
        }
    }
    return MST;
}