#ifndef GRAPH_H_
#define GRAPH_H_
//ͼ��ģ�����
const int DefaultVertices = 30;	    //Ĭ����󶥵���(=n)
template <class T, class E>
class Graph {						//ͼ���ඨ��
protected:
	int maxVertices;				//ͼ����󶥵���
	int numEdges;					//��ǰ����
	int numVertices;				//��ǰ������
public:
	static const int maxWeight = 2^sizeof(int)-1;//������ֵ
	Graph(int sz = DefaultVertices);//���캯��
	~Graph(){};						//��������
	bool GraphEmpty() const 		//��ͼ�շ�
	{
		return numEdges == 0;
	}	
	int NumberOfVertices() { return numVertices; }//���ص�ǰ������
	int NumberOfEdges() { return numEdges; }//���ص�ǰ����
	virtual T getValue(int i) = 0;		//ȡ���� i ��ֵ
	virtual E getWeight(int v1, int v2) = 0;  //ȡ����Ȩֵ
	virtual int getFirstNeighbor(int v) = 0;
	//ȡ���� v �ĵ�һ���ڽӶ���
	virtual int getNextNeighbor(int v, int w) = 0;
	//ȡ�ڽӶ��� w ����һ�ڽӶ���
	virtual bool insertVertex(const T& vertex) = 0;
	//����һ������vertex
	virtual bool insertEdge(int v1, int v2, E cost) = 0;
	//�����(v1,v2), ȨΪcost
	virtual bool removeVertex(int v) = 0;
	//ɾȥ���� v ��������֮������ı�
	virtual bool removeEdge(int v1, int v2) = 0;
	//��ͼ��ɾȥ��(v1,v2)
	virtual int getVertexPos(const T vertex) = 0;
	//��������vertex��ͼ�е�λ�ã������������е���ţ�
};

#endif
