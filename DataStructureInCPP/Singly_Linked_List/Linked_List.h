#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*������ͷ�ļ�*/
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
class Linked_List{
protected:
	LinkNode *first;
public:
	Linked_List ( ){ first = new LinkNode ( 0 ); }//���캯�������������ӱ�ͷ���
	~Linked_List ( ){ makeEmpty ( ); }
	void inputFront ( int data[], int endTag );//ǰ�巨��������
	void inputRear ( int data[],int endTag );//��巨��������
	void output ( );
	void makeEmpty ( );
	int Length ( ) const;
	LinkNode * Search ( int x );
	LinkNode * Locate ( int i );
	bool getData ( int i, int& x )const;
	void reverseLinkedList ( );//��ת������
};
#endif