#include"GraphMatrix.h"
#include<iostream>
template<class T, class E>
GraphMatrix<T, E>::GraphMatrix(int sz = DefaultVertices)
{/*构造函数，初始化图*/
	maxVertices = sz;					//最大顶点数
	numVertices = 0;					//当前顶点数
	numEdges = 0;						//当前边数
	VerticesList = new T[maxVertices];	//创建顶点表数组
	Edge = (E**)new E *[maxVertices];	//创建邻接矩阵

	for (int i = 0; i < maxVertices; i++)
	{
		Edge[i] = new E[maxVertices];
	}
	//初始化邻接矩阵，对角线为0，其余元素为正无穷
	for (int i = 0; i < maxVertices; i++)
	{
		for (int j = 0; j < maxVertices; j++)
		{
			Edge[i][j] = (i == j) ? 0 : maxWeight;
		}
	}
}
template<class T, class E>
int GraphMatrix<T, E>::getFirstNeighbor(int v)
{//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1
	if (v >=0&&v<numVertices)
	{
		for (int col = 0; col < numVertices; col++)
		{
			if (Edge[v][col]>0 && Edge[v][col] < maxWeight)
				return col;
			Edge[i][v] = Edge[i][numVertices - 1];
		}
	}
	return -1;
}
template<class T, class E>
int GraphMatrix<T, E>::getNextNeighbor(int v, int w)
{/*给出顶点v的某邻接顶点w的下一个邻接顶点*/


	return -1;
}
template<class T, class E>
bool GraphMatrix<T, E>::insertVertex(const T& vertex)
{/*插入顶点vertex*/
	if (numVertices == maxVertices)return false;//超出最大顶点数
	
	VerticesList[numVertices++] = vertex;		//顶点表数组加1个元素
	return true;
}
template<class T, class E>
bool GrapgMatrix<T, E>::removeVertex(int v)
{/*删去顶点v和所有与它相关联的边*/
	if(v < 0 || v >= numVertices)return false;		//v不在图中，不删除
	//if (numVertices == 1)return false;			//只剩一个顶点，不删除
	VerticesList[v] == VerticesList[numVertices - 1];//顶点表中删除该结点（替换为最后一个结点）
	

}



template<class T, class E>
istream& operator>>( istream& in, GraphMatrix < T, E > &G )
{//通过输入流对象in输入n个顶点信息和e条无向边的信息建立用邻接矩阵表示的图G。
//邻接矩阵初始化的工作已在构造函数中完成。
int i, j, k, n, m; T e1, e2; E weight;
in >> n >> m;
for (  i = 0; i < n; i++ )
{
in >> e1;
G.insertVertex ( e );
}

}
