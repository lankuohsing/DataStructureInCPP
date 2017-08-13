#include"GraphMatrix.h"
#include<iostream>
template<class T, class E>
GraphMatrix<T, E>::GraphMatrix(int sz = DefaultVertices)
{/*���캯������ʼ��ͼ*/
	maxVertices = sz;					//��󶥵���
	numVertices = 0;					//��ǰ������
	numEdges = 0;						//��ǰ����
	VerticesList = new T[maxVertices];	//�������������
	Edge = (E**)new E *[maxVertices];	//�����ڽӾ���

	for (int i = 0; i < maxVertices; i++)
	{
		Edge[i] = new E[maxVertices];
	}
	//��ʼ���ڽӾ��󣬶Խ���Ϊ0������Ԫ��Ϊ������
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
{//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1
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
{/*��������v��ĳ�ڽӶ���w����һ���ڽӶ���*/


	return -1;
}
template<class T, class E>
bool GraphMatrix<T, E>::insertVertex(const T& vertex)
{/*���붥��vertex*/
	if (numVertices == maxVertices)return false;//������󶥵���
	
	VerticesList[numVertices++] = vertex;		//����������1��Ԫ��
	return true;
}
template<class T, class E>
bool GrapgMatrix<T, E>::removeVertex(int v)
{/*ɾȥ����v����������������ı�*/
	if(v < 0 || v >= numVertices)return false;		//v����ͼ�У���ɾ��
	//if (numVertices == 1)return false;			//ֻʣһ�����㣬��ɾ��
	VerticesList[v] == VerticesList[numVertices - 1];//�������ɾ���ý�㣨�滻Ϊ���һ����㣩
	

}



template<class T, class E>
istream& operator>>( istream& in, GraphMatrix < T, E > &G )
{//ͨ������������in����n��������Ϣ��e������ߵ���Ϣ�������ڽӾ����ʾ��ͼG��
//�ڽӾ����ʼ���Ĺ������ڹ��캯������ɡ�
int i, j, k, n, m; T e1, e2; E weight;
in >> n >> m;
for (  i = 0; i < n; i++ )
{
in >> e1;
G.insertVertex ( e );
}

}
