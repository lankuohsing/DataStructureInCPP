#include"GraphMatrix.h"
#include<iostream>

GraphMatrix::GraphMatrix(int sz )
{/*���캯������ʼ��ͼ*/
	maxVertices = sz;					//��󶥵���
	numVertices = 0;					//��ǰ������
	numEdges = 0;						//��ǰ����
	VerticesList = new int[maxVertices];	//�������������
	Edge = (int**)new int *[maxVertices];	//�����ڽӾ���

	for (int i = 0; i < maxVertices; i++)
	{
		Edge[i] = new int[maxVertices];
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

int GraphMatrix::getFirstNeighbor(int v)
{//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1
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
{//��������v��ĳ�ڽӶ���w����һ���ڽӶ���


	return -1;
}

bool GraphMatrix::insertVertex(const int& vertex)
{//���붥��vertex
	if (numVertices == maxVertices)return false;//������󶥵���
	
	VerticesList[numVertices++] = vertex;		//����������1��Ԫ��
	return true;
}


bool GraphMatrix::insertEdge ( int v1, int v2, int cost )
{//����ߣ�v1,v2����ȨֵΪcost
	if ( v1 > -1 && v1<numVertices&&
		v2>-1 && v2 < numVertices&&
		Edge[v1][v2]==maxWeight)		//��������
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
	//ɾȥ���� v ����������������ı�
	if ( v < 0 || v >= numVertices )return false;
	if ( numVertices == 1 )return false;
	int i, j;
	VerticesList [ v ] = VerticesList [ numVertices - 1 ];//�����һ���㿽������
	for ( i = 0; i < numVertices; i++ )
	{//��ȥ��v���������
		if ( Edge[i][v]>0&& Edge[i][v]<maxWeight)
		{
			numEdges--;
		}
	}

	for ( i = 0; i<numVertices; i++ )//�����һ�����v��
		Edge [ i ][ v ] = Edge [ i ][ numVertices - 1 ];
	numVertices--;
	for ( j = 0; j < numVertices; j++ )
		Edge [ v ][ j ] = Edge [ numVertices [ j ] ];
	return true;
}
*/

bool GraphMatrix::removeEdge ( int v1, int v2 )
{
	//��ͼ��ɾȥ��(v1,v2)
	//�������
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
{//ͨ������������in����n��������Ϣ��e������ߵ���Ϣ�������ڽӾ����ʾ��ͼG
	//�ڽӾ����ʼ���Ĺ����Ѿ��ڹ��캯�������
	int i, j, k, n, m;
	int v1, v2;
	int weight;
	cout << "��˳�����붥�����ͱ�����";
	in >> n >> m;				//���붥����n�ͱ���m
	cout << "��˳�����붥�㣬ÿ��һ����" << endl;
	for ( i = 0; i < n; i++ )	//�������������
	{
		in >> v1;
		G.insertVertex ( v1 );
	}
	i = 0;
	cout << "��˳������ߵ���Ϣ��ÿ����������" << endl;
	while ( i<m )
	{
		in >> v1>>v2 >> weight;	//����˵���Ϣ
		//�鶥���
		j = G.getVertexPos ( v1 ); k = G.getVertexPos ( v2 );
		if ( j == -1 || k == -1 )
		{
			cout << "�����˶�����Ϣ�����������룡" << endl;
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
{//���ͼ�����ж���ͱߵ���Ϣ
	int i, j, n, m;
	int v1, v2;
	int weight;
	n = G.NumberOfVertices ( );		//������
	m = G.NumberOfEdges();			//����
	cout << "�������ͱ�����";
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