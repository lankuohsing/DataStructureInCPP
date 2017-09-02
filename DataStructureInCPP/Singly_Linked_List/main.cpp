#include<iostream>
#include"Linked_List.h"
using namespace std;

int main ( )
{
	int data1 [ ] = { 1, 2, 3, 4, 5, -1 };
	Linked_List link_list;
	cout << "Input List from front:" << endl;
	link_list.inputFront ( data1,- 1 );
	int x = 6;
	int i = -1;
	int y = 0;
	cout << "Output List:" << endl;
	link_list.output ( );
	cout << "Length of List:" << link_list.Length ( ) << endl;
	
	cout << "反转单链表：" << endl;
	link_list.reverseLinkedList ( );
	link_list.output ( );
	cout << "Make List empty:" << endl;
	link_list.makeEmpty ( );
	system ( "pause" );
	return 0;
}