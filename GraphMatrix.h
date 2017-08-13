#ifndef GRAPHMATRIX_H_
#define GRAPHMATRIX_H_
/*���ڽӾ����ʾ��ͼ���ඨ��*/
#include<iostream>
#include "Graph.h"
template <class T, class E>
class GraphMatrix : public Graph<T, E>
{
	friend istream& operator >> ( istream& in, GraphMatrix<T, E>& G );			//����
	//friend ostream& operator << ( ostream& out, GraphMatrix<T, E>& G );				//���
private:
	T *VerticesList; 						//�����
	E **Edge;								//�ڽӾ���
public:
	int getVertexPos(const T vertex) {
		//��������vertex��ͼ�е�λ��
		for (int i = 0; i < numVertices; i++)
		if (VerticesList[i] == vertex) return i;
		return -1;
	}
	GraphMatrix(int sz = DefaultVertices);    //���캯��

	~GraphMatrix()				      //��������
	{
		delete[]VerticesList;  delete[]Edge;
	}
	T getValue(int i) {
		//ȡ���� i ��ֵ, i ��������0
		return i >= 0 && i <= numVertices ?
			VerticesList[i] : NULL;
	}
	E getWeight(int v1, int v2) {  //ȡ��(v1,v2)��Ȩֵ
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	//ȡ���� v �ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w);
	//ȡ v ���ڽӶ��� w ����һ�ڽӶ���
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1, int v2, E cost){
		//�����(v1, v2),ȨֵΪcost
		//�������
		if (min(v1, v2) < 0 || max(v1, v2) >= numVertices || Edge[v1][v2] != maxWeight)
			return false;
		Edge[v1][v2] = cost;
		return true;
	}
	bool removeVertex(int v){
		//ɾȥ���� v ����������������ı�
		if (v < 0 || v >= numVertices)
			return false;
		VerticesList[v] = VerticesList[numVertices - 1];//�����һ���㿽������
		memcpy(Edge[v], Edge[numVertices - 1], sizeof(E)*(numVertices));//�Ѿ������һ���п�������
		for (int i = 0; i<numVertices; i++)//�����һ�п�������
			Edge[i][v] = Edge[i][numVertices - 1];
		numVertices--;
		return true;
	}
	bool removeEdge(int v1, int v2){
		//��ͼ��ɾȥ��(v1,v2)
		//�������
		if (min(v1, v2) < 0 || max(v1, v2) >= numVertices ||
			Edge[v1][v2] >= maxWeight || Edge[v1][v2] <= 0)
			return false;
		Edge[v1][v2] = maxWeight;
		return true;
	}
};


#endif