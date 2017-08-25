#ifndef GRAPHMATRIX_H_
#define GRAPHMATRIX_H_
/*用邻接矩阵表示的图的类定义*/
static const int maxWeight = 2 ^ sizeof(int)-1;//无穷大的值
static const int DefaultVertices = 30;	    //默认最大顶点数(=n)
#include<iostream>


using namespace std;

class GraphMatrix 
{
	friend istream& operator >> ( istream& in, GraphMatrix& G );		//输入
	friend ostream& operator << ( ostream& out, GraphMatrix& G );		//输出

								
public:
	int maxVertices;				//图中最大顶点数
	int numEdges;					//当前边数
	int numVertices;				//当前顶点数
	int *VerticesList; 						//顶点表
	int **Edge;								//邻接矩阵
	
	int getVertexPos(const int vertex) {
		//给出顶点vertex在图中的位置
		for (int i = 0; i < numVertices; i++)
		if (VerticesList[i] == vertex) return i;
		return -1;
	}
	GraphMatrix(int );  //构造函数
	int NumberOfVertices ( ) { return numVertices; }//返回当前顶点数
	int NumberOfEdges ( ) { return numEdges; }//返回当前边数
	~GraphMatrix()							//析构函数
	{
		delete[]VerticesList;  
		for ( int i = 0; i < maxVertices; i++ )
		{
			delete [ ] Edge [ i ];
		}
		delete [ ] Edge;
	}
	int getValue(int i) {//取顶点 i 的值, i 不合理返回0
		return i >= 0 && i < numVertices ? VerticesList [ i ] : NULL;
	}
	int getWeight(int v1, int v2) {  //取边(v1,v2)上权值
		return v1 != -1 && v2 != -1 ? Edge [ v1 ][ v2 ] : 0;
	}
	int getFirstNeighbor(int v);//取顶点 v 的第一个邻接顶点
	int getNextNeighbor(int v, int w);//取 v 的邻接顶点 w 的下一邻接顶点
	
	bool insertVertex(const int& vertex);
	bool insertEdge ( int v1, int v2, int cost );
	bool removeVertex ( int v ){
		//删去顶点 v 和所有与它相关联的边
		if ( v < 0 || v >= numVertices )return false;
		if ( numVertices == 1 )return false;
		int i, j;
		VerticesList [ v ] = VerticesList [ numVertices - 1 ];//把最后一个点拷贝过来
		for ( i = 0; i < numVertices; i++ )
		{//减去与v相关联边数
			if ( Edge [ i ][ v ]>0 && Edge [ i ][ v ]<maxWeight )
			{
				numEdges--;
			}
		}

		for ( i = 0; i<numVertices; i++ )//用最后一列填补第v列
			Edge [ i ][ v ] = Edge [ i ][ numVertices - 1 ];
		numVertices--;
		for ( j = 0; j < numVertices; j++ )
			Edge [ v ][ j ] = Edge [ numVertices ][ j ];
		return true;
	}
	bool removeEdge ( int v1, int v2 );
	
};


#endif