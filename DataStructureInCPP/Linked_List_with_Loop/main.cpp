#include<iostream>
#include"Linked_List_with_Loop.h"
using namespace std;

int main ( )
{
	Linked_List_with_Loop link_list_with_loop;
	int data1 [ ] = { 1, 2, 3, 4, 5, 6, 7,8,9,10,11,12,13,14,15,-1 };
	cout << "Input List from rear:" << endl;
	link_list_with_loop.inputRear ( data1,-1,4 );
	int x = 7;
	int i = -1;
	int y = 0;
	cout << "Output List:" << endl;
	link_list_with_loop.output ( );
	cout << "最后一个节点：" << link_list_with_loop.getLastNode ( )->data << endl;
	cout <<"链表长度："<< link_list_with_loop.Length() << endl;
	if ( link_list_with_loop.isLoop() )
	{
		cout << "这是一个有环的链表！" << endl;
		cout << "环的长度为：" << link_list_with_loop.getLoopLength ( ) << endl;
		cout << "环的入口节点为：" << link_list_with_loop.getLoopStartNode ( )->data << endl;
	}
	else
	{
		cout << "这是一个无环的链表！" << endl;
	}
	/*
	cout << "Length of List:" << cir_link_list.Length ( ) << endl;
	cout << "Search " << x << ": " << cir_link_list.Search ( x ) << endl;
	cout << "Locate " << i << ": " << cir_link_list.Locate ( i ) << endl;

	if ( cir_link_list.getData ( i, y ) )
	{
		cout << i << "-th data: " << y << endl;
	}
	*/
	cout << "Make List empty:" << endl;
	link_list_with_loop.makeEmpty ( );
	system ( "pause" );
	return 0;
}