#include"GraphMatrix.h"
#include<iostream>

GraphMatrix::GraphMatrix(int sz )
{/*构造函数，初始化图*/
	maxVertices = sz;					//最大顶点数
	numVertices = 0;					//当前顶点数
	numEdges = 0;						//当前边数
	VerticesList = new int[maxVertices];	//创建顶点表数组
	Edge = (int**)new int *[maxVertices];	//创建邻接矩阵

	for (int i = 0; i < maxVertices; i++)
	{
		Edge[i] = new int[maxVertices];
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

int GraphMatrix::getFirstNeighbor(int v)
{//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1
	if (v >=0&&v<numVertices)
	{
		for (int col = 0; col < numVertices; col++)
		{
			if (Edge[v][col]>0 && Edge[v][col] < maxWeight)
				return col;
			
		}
	}
	return -1;
}

int GraphMatrix::getNextNeighbor(int v, int w)
{//给出顶点v的某邻接顶点w的下一个邻接顶点


	return -1;
}

bool GraphMatrix::insertVertex(const int& vertex)
{//插入顶点vertex
	if (numVertices == maxVertices)return false;//超出最大顶点数
	
	VerticesList[numVertices++] = vertex;		//顶点表数组加1个元素
	return true;
}


bool GraphMatrix::insertEdge ( int v1, int v2, int cost )
{//插入边（v1,v2），权值为cost
	if ( v1 > -1 && v1<numVertices&&
		v2>-1 && v2 < numVertices&&
		Edge[v1][v2]==maxWeight)		//插入条件
	{
		Edge [ v1 ][ v2 ] = Edge [ v2 ][ v1 ] = cost;
		numEdges++;
		return true;
	}
	else
	{
		return false;
	}

}
/*

bool GrapgMatrix<int, int>::removeVertex ( int v )
{
	//删去顶点 v 和所有与它相关联的边
	if ( v < 0 || v >= numVertices )return false;
	if ( numVertices == 1 )return false;
	int i, j;
	VerticesList [ v ] = VerticesList [ numVertices - 1 ];//把最后一个点拷贝过来
	for ( i = 0; i < numVertices; i++ )
	{//减去与v相关联边数
		if ( Edge[i][v]>0&& Edge[i][v]<maxWeight)
		{
			numEdges--;
		}
	}

	for ( i = 0; i<numVertices; i++ )//用最后一列填补第v列
		Edge [ i ][ v ] = Edge [ i ][ numVertices - 1 ];
	numVertices--;
	for ( j = 0; j < numVertices; j++ )
		Edge [ v ][ j ] = Edge [ numVertices [ j ] ];
	return true;
}
*/

bool GraphMatrix::removeEdge ( int v1, int v2 )
{
	//在图中删去边(v1,v2)
	//条件检查
	if ( v1>-1 && v1<numVertices&&
		v2>-1 && v2<numVertices&&
		Edge [ v1 ][ v2 ]>0 &&Edge [ v1 ][ v2 ] < maxWeight&&
		Edge [ v2 ][ v1 ]>0 && Edge [ v2 ][ v1 ] < maxWeight )
	{
		Edge [ v1 ][ v2 ] = Edge [ v2 ][ v1 ] = maxWeight;
		numEdges--;
		return true;
	}
	else
	{
		return false;
	}
	
}

istream& operator>>( istream& in, GraphMatrix&G )
{//通过输入流对象in输入n个顶点信息和e条无向边的信息建立用邻接矩阵表示的图G
	//邻接矩阵初始化的工作已经在构造函数中完成
	int i, j, k, n, m;
	int v1, v2;
	int weight;
	cout << "按顺序输入顶点数和边数：";
	in >> n >> m;				//输入顶点数n和边数m
	cout << "按顺序输入顶点，每行一个：" << endl;
	for ( i = 0; i < n; i++ )	//建立顶点表数据
	{
		in >> v1;
		G.insertVertex ( v1 );
	}
	i = 0;
	cout << "按顺序输入边的信息，每行三个数：" << endl;
	while ( i<m )
	{
		in >> v1>>v2 >> weight;	//输入端点信息
		//查顶点号
		j = G.getVertexPos ( v1 ); k = G.getVertexPos ( v2 );
		if ( j == -1 || k == -1 )
		{
			cout << "边两端顶点信息有误，重新输入！" << endl;
		}
		else
		{
			G.insertEdge ( i, j, weight );
			i++;
		}
	}
	return in;
}

ostream& operator<<( ostream& out, GraphMatrix& G )
{//输出图的所有顶点和边的信息
	int i, j, n, m;
	int v1, v2;
	int weight;
	n = G.NumberOfVertices ( );		//顶点数
	m = G.NumberOfEdges();			//边数
	cout << "顶点数和边数：";
	out << n << "," << m << endl;
	for (  i = 0; i < n; i++ )
	{
		for ( j = i + 1; j < n; j++ )
		{
			weight = G.getWeight ( i, j );
			if ( weight>0 && weight < maxWeight )
			{
				v1 = G.getValue ( i);
				v2 = G.getValue ( j );
				out << "(" << v1 << "," << v2 << "," << weight << ")" << endl;
			}
			{

			}
		}

	}
	return out;
}