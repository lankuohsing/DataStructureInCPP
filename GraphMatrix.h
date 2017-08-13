#ifndef GRAPHMATRIX_H_
#define GRAPHMATRIX_H_
/*用邻接矩阵表示的图的类定义*/
#include<iostream>
#include "Graph.h"
template <class T, class E>
class GraphMatrix : public Graph<T, E>
{
	friend istream& operator >> ( istream& in, GraphMatrix<T, E>& G );			//输入
	//friend ostream& operator << ( ostream& out, GraphMatrix<T, E>& G );				//输出
private:
	T *VerticesList; 						//顶点表
	E **Edge;								//邻接矩阵
public:
	int getVertexPos(const T vertex) {
		//给出顶点vertex在图中的位置
		for (int i = 0; i < numVertices; i++)
		if (VerticesList[i] == vertex) return i;
		return -1;
	}
	GraphMatrix(int sz = DefaultVertices);    //构造函数

	~GraphMatrix()				      //析构函数
	{
		delete[]VerticesList;  delete[]Edge;
	}
	T getValue(int i) {
		//取顶点 i 的值, i 不合理返回0
		return i >= 0 && i <= numVertices ?
			VerticesList[i] : NULL;
	}
	E getWeight(int v1, int v2) {  //取边(v1,v2)上权值
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	//取顶点 v 的第一个邻接顶点
	int getNextNeighbor(int v, int w);
	//取 v 的邻接顶点 w 的下一邻接顶点
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1, int v2, E cost){
		//插入边(v1, v2),权值为cost
		//条件检查
		if (min(v1, v2) < 0 || max(v1, v2) >= numVertices || Edge[v1][v2] != maxWeight)
			return false;
		Edge[v1][v2] = cost;
		return true;
	}
	bool removeVertex(int v){
		//删去顶点 v 和所有与它相关联的边
		if (v < 0 || v >= numVertices)
			return false;
		VerticesList[v] = VerticesList[numVertices - 1];//把最后一个点拷贝过来
		memcpy(Edge[v], Edge[numVertices - 1], sizeof(E)*(numVertices));//把矩阵最后一个行拷贝过来
		for (int i = 0; i<numVertices; i++)//把最后一列拷贝过来
			Edge[i][v] = Edge[i][numVertices - 1];
		numVertices--;
		return true;
	}
	bool removeEdge(int v1, int v2){
		//在图中删去边(v1,v2)
		//条件检查
		if (min(v1, v2) < 0 || max(v1, v2) >= numVertices ||
			Edge[v1][v2] >= maxWeight || Edge[v1][v2] <= 0)
			return false;
		Edge[v1][v2] = maxWeight;
		return true;
	}
};


#endif