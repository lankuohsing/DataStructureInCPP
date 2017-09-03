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
	Linked_List_with_Loop ( ){ first = new LinkNode ( 0 ); }//���캯�������������ӱ�ͷ���
	~Linked_List_with_Loop ( ){ makeEmpty ( ); }
	void inputFront ( int data[],int endTag,int cir_start );//ǰ�巨��������
	void inputRear ( int data [ ], int endTag,int cir_start );//��巨��������
	void output ( );
	void makeEmpty ( );
	int Length ( ) const;
	LinkNode * Search ( int x );
	LinkNode * Locate ( int i );
	bool getData ( int i, int& x )const;
	LinkNode * getLastNode ( );//������һ�����

	//���º�������ʵ�ֳ��õ���������㷨
	bool isLoop ( );//�ж��Ƿ��л�
	int getLoopLength ( );//���㻷�ĳ���
	LinkNode * getLoopStartNode ( );//��û�����ڽڵ�
};
#endif