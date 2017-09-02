#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/*单链表头文件*/
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
	Linked_List ( ){ first = new LinkNode ( 0 ); }//构造函数，可生产附加表头结点
	~Linked_List ( ){ makeEmpty ( ); }
	void inputFront ( int data[], int endTag );//前插法建立链表
	void inputRear ( int data[],int endTag );//后插法建立链表
	void output ( );
	void makeEmpty ( );
	int Length ( ) const;
	LinkNode * Search ( int x );
	LinkNode * Locate ( int i );
	bool getData ( int i, int& x )const;
	void reverseLinkedList ( );//反转单链表
};
#endif