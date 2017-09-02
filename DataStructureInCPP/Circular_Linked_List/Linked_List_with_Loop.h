#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H
#include<iostream>
using namespace std;
struct LinkNode{
	int data;
	LinkNode * link;
	LinkNode ( LinkNode *ptr = NULL ){ link = ptr; }
	LinkNode ( const int& item, LinkNode *ptr = NULL )
	{
		data = item; link = ptr;
	}
};
class Linked_List_with_Loop{
protected:
	LinkNode *first;
	LinkNode *cirStart;
	LinkNode *lastNode;
public:
	Linked_List_with_Loop ( ){ first = new LinkNode ( 0 ); }//构造函数，可生产附加表头结点
	~Linked_List_with_Loop ( ){ makeEmpty ( ); }
	void inputFront ( int data[],int endTag,int cir_start );//前插法建立链表
	void inputRear ( int data [ ], int endTag,int cir_start );//后插法建立链表
	void output ( );
	void makeEmpty ( );
	int Length ( ) const;
	LinkNode * Search ( int x );
	LinkNode * Locate ( int i );
	bool getData ( int i, int& x )const;
	LinkNode * getLastNode ( );//获得最后一个结点

	//以下函数用来实现常用的链表操作算法
	bool isLoop ( );//判断是否有环
	int getLoopLength ( );//计算环的长度
	LinkNode * getLoopStartNode ( );//获得环的入口节点
};
#endif