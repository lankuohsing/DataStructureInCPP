#ifndef GRAPHMATRIX_H_
#define GRAPHMATRIX_H_
/*���ڽӾ����ʾ��ͼ���ඨ��*/
static const int maxWeight = 2 ^ sizeof(int)-1;//������ֵ
static const int DefaultVertices = 30;	    //Ĭ����󶥵���(=n)
#include<iostream>


using namespace std;

class GraphMatrix 
{
	friend istream& operator >> ( istream& in, GraphMatrix& G );		//����
	friend ostream& operator << ( ostream& out, GraphMatrix& G );		//���

								
public:
	int maxVertices;				//ͼ����󶥵���
	int numEdges;					//��ǰ����
	int numVertices;				//��ǰ������
	int *VerticesList; 						//�����
	int **Edge;								//�ڽӾ���
	
	int getVertexPos(const int vertex) {
		//��������vertex��ͼ�е�λ��
		for (int i = 0; i < numVertices; i++)
		if (VerticesList[i] == vertex) return i;
		return -1;
	}
	GraphMatrix(int );  //���캯��
	int NumberOfVertices ( ) { return numVertices; }//���ص�ǰ������
	int NumberOfEdges ( ) { return numEdges; }//���ص�ǰ����
	~GraphMatrix()							//��������
	{
		delete[]VerticesList;  
		for ( int i = 0; i < maxVertices; i++ )
		{
			delete [ ] Edge [ i ];
		}
		delete [ ] Edge;
	}
	int getValue(int i) {//ȡ���� i ��ֵ, i ��������0
		return i >= 0 && i < numVertices ? VerticesList [ i ] : NULL;
	}
	int getWeight(int v1, int v2) {  //ȡ��(v1,v2)��Ȩֵ
		return v1 != -1 && v2 != -1 ? Edge [ v1 ][ v2 ] : 0;
	}
	int getFirstNeighbor(int v);//ȡ���� v �ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w);//ȡ v ���ڽӶ��� w ����һ�ڽӶ���
	
	bool insertVertex(const int& vertex);
	bool insertEdge ( int v1, int v2, int cost );
	bool removeVertex ( int v ){
		//ɾȥ���� v ����������������ı�
		if ( v < 0 || v >= numVertices )return false;
		if ( numVertices == 1 )return false;
		int i, j;
		VerticesList [ v ] = VerticesList [ numVertices - 1 ];//�����һ���㿽������
		for ( i = 0; i < numVertices; i++ )
		{//��ȥ��v���������
			if ( Edge [ i ][ v ]>0 && Edge [ i ][ v ]<maxWeight )
			{
				numEdges--;
			}
		}

		for ( i = 0; i<numVertices; i++ )//�����һ�����v��
			Edge [ i ][ v ] = Edge [ i ][ numVertices - 1 ];
		numVertices--;
		for ( j = 0; j < numVertices; j++ )
			Edge [ v ][ j ] = Edge [ numVertices ][ j ];
		return true;
	}
	bool removeEdge ( int v1, int v2 );
	
};


#endif