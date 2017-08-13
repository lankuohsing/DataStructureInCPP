#ifndef GRAPH_H_
#define GRAPH_H_
//图的模板基类
const int DefaultVertices = 30;	    //默认最大顶点数(=n)
template <class T, class E>
class Graph {						//图的类定义
protected:
	int maxVertices;				//图中最大顶点数
	int numEdges;					//当前边数
	int numVertices;				//当前顶点数
public:
	static const int maxWeight = 2^sizeof(int)-1;//无穷大的值
	Graph(int sz = DefaultVertices);//构造函数
	~Graph(){};						//析构函数
	bool GraphEmpty() const 		//判图空否
	{
		return numEdges == 0;
	}	
	int NumberOfVertices() { return numVertices; }//返回当前顶点数
	int NumberOfEdges() { return numEdges; }//返回当前边数
	virtual T getValue(int i) = 0;		//取顶点 i 的值
	virtual E getWeight(int v1, int v2) = 0;  //取边上权值
	virtual int getFirstNeighbor(int v) = 0;
	//取顶点 v 的第一个邻接顶点
	virtual int getNextNeighbor(int v, int w) = 0;
	//取邻接顶点 w 的下一邻接顶点
	virtual bool insertVertex(const T& vertex) = 0;
	//插入一个顶点vertex
	virtual bool insertEdge(int v1, int v2, E cost) = 0;
	//插入边(v1,v2), 权为cost
	virtual bool removeVertex(int v) = 0;
	//删去顶点 v 和所有与之相关联的边
	virtual bool removeEdge(int v1, int v2) = 0;
	//在图中删去边(v1,v2)
	virtual int getVertexPos(const T vertex) = 0;
	//给出顶点vertex在图中的位置（顶点在数组中的序号）
};

#endif
