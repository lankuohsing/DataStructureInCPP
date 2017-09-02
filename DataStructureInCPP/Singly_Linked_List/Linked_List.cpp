#include"Linked_List.h"
#include<iostream>
void Linked_List::inputFront ( int data[],int endTag )
//前插法建立单链表
{
	LinkNode *newNode;
	//int data;
	//makeEmpty;
	//cin >> data;
	makeEmpty ( );
	int i = 0;
	while ( data [ i ] != endTag )
	{
		newNode = new LinkNode ( data [ i ] );
		if ( newNode == NULL )
		{
			cerr << "存储分配错误，新建链表结点失败！" << endl;
			exit ( 1 );
		}
		newNode->link = first->link;
		first->link = newNode;
		i++;
		//cin >> data;
	}
}
void Linked_List::inputRear ( int data[], int endTag )
{//后插法建立单链表
	LinkNode *newNode;
	LinkNode *p = first;
	makeEmpty ( );
	int i = 0;
	while ( data [ i ] != endTag )
	{
		newNode = new LinkNode ( data [ i ] );
		if ( newNode == NULL )
		{
			cerr << "存储分配错误，新建链表结点失败！" << endl;
			exit ( 1 );
		}
		p->link = newNode;
		p = p->link;
		i++;
	}

}
void Linked_List::output ( )
{//输出链表各结点的值
	LinkNode *current;
	current = first;
	while ( current->link != NULL )
	{
		current = current->link;
		cout << current->data << ",";

	}
	cout << endl;
}
void Linked_List::makeEmpty ( )
{//将链表置空
	LinkNode *q;
	while ( first->link != NULL )
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}
int Linked_List::Length ( ) const
{//获取链表长度
	LinkNode *p = first->link;
	int count = 0;
	while ( p != NULL )
	{
		count++;
		p = p->link;
	}
	return count;
}
LinkNode * Linked_List::Search ( int x )
{//查找值为x的链表结点
	LinkNode *current = first->link;
	while ( current != NULL )
	{
		if ( current->data == x )
		{
			return current;
		}
		else
		{
			current = current->link;
		}
	}
	return current;

}
LinkNode *Linked_List::Locate ( int i )
{//查找第i个链表结点
	if ( i<0 )
	{
		return NULL;
	}
	int j = 0;
	LinkNode *current = first->link;
	for ( j = 0; j < i; j++ )
	{
		if ( current == NULL )break;
		else current = current->link;
	}
	return current;

}
bool Linked_List::getData ( int i, int& x )const
{//获得第i个节点的值
	if ( i < 0 ) return false;
	LinkNode * current = first->link;
	for ( int j = 0; j < i; j++ )
	{
		if ( current == NULL )break;
		else current = current->link;

	}
	if ( current == NULL )
	{
		return false;
	}
	else
	{
		x = current->data;
		return true;
	}
}
void Linked_List::reverseLinkedList ( )
{//反转单链表
	LinkNode *p, *q;
	p = first->link;
	if ( p==NULL )return;
	q = p->link;
	while ( q!=NULL )
	{
		p->link = q->link;
		q->link = first->link;
		first->link = q;
		q = p->link;
	}
}
LinkNode * Linked_List::midNode ( )
{
	LinkNode *p, *q;
	p = q = first;
	while ( q->link&&q->link->link )
	{
		p = p->link;
		q = q->link->link;
	}
	if ( q->link )
	{
		p = p->link;
	}
	return p;
}