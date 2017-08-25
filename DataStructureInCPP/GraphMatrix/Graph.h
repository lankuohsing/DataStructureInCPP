#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
using namespace std;
//ͼ��ģ�����
const int DefaultVertices = 30;	    //Ĭ����󶥵���(=n)

class Graph {						//ͼ���ඨ��
	
protected:
	
public:
	int maxVertices;				//ͼ����󶥵���
	int numEdges;					//��ǰ����
	int numVertices;				//��ǰ������
	
	Graph(int sz = DefaultVertices);//���캯��
	~Graph(){};						//��������
	bool GraphEmpty() const 		//��ͼ�շ�
	{
		return numEdges == 0;
	}	
	int NumberOfVertices() { return numVertices; }//���ص�ǰ������
	int NumberOfEdges() { return numEdges; }//���ص�ǰ����
	virtual int getValue(int i) = 0;		//ȡ���� i ��ֵ
	virtual int getWeight(int v1, int v2) = 0;  //ȡ����Ȩֵ
	virtual int getFirstNeighbor(int v) = 0;
	//ȡ���� v �ĵ�һ���ڽӶ���
	virtual int getNextNeighbor(int v, int w) = 0;
	//ȡ�ڽӶ��� w ����һ�ڽӶ���
	virtual bool insertVertex(const int& vertex) = 0;
	//����һ������vertex
	virtual bool insertEdge(int v1, int v2, int cost) = 0;
	//�����(v1,v2), ȨΪcost
	virtual bool removeVertex(int v) = 0;
	//ɾȥ���� v ��������֮������ı�
	virtual bool removeEdge(int v1, int v2) = 0;
	//��ͼ��ɾȥ��(v1,v2)
	virtual int getVertexPos(const int vertex) = 0;
	//��������vertex��ͼ�е�λ�ã������������е���ţ�
};

#endif
