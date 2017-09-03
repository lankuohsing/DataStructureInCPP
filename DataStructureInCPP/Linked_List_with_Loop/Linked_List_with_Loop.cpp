#include"Linked_List_with_Loop.h"
#include<iostream>
void Linked_List_with_Loop::inputFront ( int data [ ], int endTag, int cir_start )
{//edited(nothing to change)
	LinkNode *newNode;
	LinkNode *p=NULL;
	//int data;
	//makeEmpty;
	//cin >> data;
	
	int i = 0;
	bool last = false;
	while ( data [ i ] != endTag )
	{
		
		newNode = new LinkNode ( data [ i ] );
		if ( !last )
		{
			p = newNode;
			last = true;
		}
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
	cirStart = first;
	for ( int i = 0; i < cir_start; i++ )
	{
		if ( cirStart == NULL )
		{
			cerr << "环的入口点不合理！" << endl;
			exit ( 1 );
		}
		cirStart = cirStart->link;
	}
	p->link = cirStart;//获得环的入口结点
	lastNode = getLastNode ( );//获得最后一个节点
}
void Linked_List_with_Loop::inputRear ( int data [ ], int endTag, int cir_start )
{//edited
	LinkNode *newNode;
	LinkNode *p = first;
	//makeEmpty ( );
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
	cirStart = first;
	for ( int i = 0; i < cir_start; i++ )
	{
		if ( cirStart == NULL )
		{
			cerr << "环的入口点不合理！" << endl;
			exit ( 1 );
		}
		cirStart = cirStart->link;
	}
	p->link = cirStart;//获得环的入口结点
	lastNode = getLastNode ( );//获得最后一个节点

}
void Linked_List_with_Loop::output ( )
{//edited
	LinkNode *current;
	current = first;
	bool cirStartFlag = true;
	do
	{
		if ( current->link == cirStart )
		{
			cirStartFlag = false;
		}
		current = current->link;
		cout << current->data << ",";
		
	} while ( current->link != cirStart||cirStartFlag );
	cout << endl;
}
void Linked_List_with_Loop::makeEmpty ( )
{//edited
	LinkNode *q;
	//bool cirStartFlag = true;
	lastNode->link = NULL;//解开环
	while ( first->link != NULL )
	{
		
		q = first->link;
		first->link = q->link;
		delete q;
	}

}
int Linked_List_with_Loop::Length ( ) const
{//edited
	LinkNode *p = first->link;
	int count = 0;
	bool cirStartFlag = true;
	while ( p != cirStart||cirStartFlag )
	{
		if ( p == cirStart )
		{
			cirStartFlag = false;
		}
		count++;
		p = p->link;
	}
	return count;
}
LinkNode * Linked_List_with_Loop::Search ( int x )
{//edited
	LinkNode *current = first->link;
	bool cirStartFlag = true;
	while ( current != cirStart || cirStartFlag )
	{
		if ( current == cirStart )
		{
			cirStartFlag = false;
		}
		if ( current->data == x )
		{
			return current;
		}
		else
		{
			current = current->link;
		}
	}
	return NULL;

}
LinkNode *Linked_List_with_Loop::Locate ( int i )
{
	if ( i<0 )
	{
		return NULL;
	}
	int j = 0;
	LinkNode *current = first->link;
	for ( j = 0; j < i; j++ )
	{
		if ( current == first )break;
		else current = current->link;
	}
	return current;

}
bool Linked_List_with_Loop::getData ( int i, int& x )const
{
	if ( i < 0 ) return false;
	LinkNode * current = first->link;
	for ( int j = 0; j < i; j++ )
	{
		if ( current == first )break;
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
LinkNode * Linked_List_with_Loop::getLastNode ( )
{
	LinkNode *p = first;
	
	bool cirStartFlag = true;
	while ( p->link != cirStart || cirStartFlag )
	{
		if ( p->link == cirStart )
		{
			cirStartFlag = false;
		}
		
		p = p->link;
	}
	return p;
}
bool Linked_List_with_Loop::isLoop ( )
{
	LinkNode*slow, *fast;
	
	slow = fast = first->link;
	if ( fast==NULL )
	{
		return false;
	}
	while ( fast->link&&fast->link->link )
	{
		slow = slow->link;
		fast = fast->link->link;
		if ( slow==fast )
		{
			return true;
		}
	}
}
int Linked_List_with_Loop::getLoopLength ( )
{
	LinkNode*slow, *fast;
	slow = fast = first->link;
	int loopLength = 0;
	if ( fast == NULL )
	{
		return loopLength;
	}
	bool isMeet = false;
	while ( fast->link&&fast->link->link )
	{
		
		slow = slow->link;
		fast = fast->link->link;
		if ( slow == fast )
		{
			isMeet = true;
		}
		if ( isMeet )
		{
			loopLength++;
			if ( slow->link == fast->link->link )
			{
				break;
			}
		}
	}
	return loopLength;
}
LinkNode * Linked_List_with_Loop::getLoopStartNode ( )
{
	LinkNode*slow, *fast;
	LinkNode * loopStartNode = NULL;
	slow = fast = first->link;
	if ( fast == NULL )
	{
		return NULL;
	}
	bool isMeet = false;
	while ( fast->link&&fast->link->link )
	{

		slow = slow->link;
		fast = fast->link->link;
		if ( slow == fast )
		{
			isMeet = true;
			break;
		}
		
	}
	if ( isMeet )
	{
		fast = first->link;
		while ( true )
		{
			slow = slow->link;
			fast = fast->link;
			if ( slow == fast )
			{
				loopStartNode = slow;
				break;
			}
		}
	}
	return loopStartNode;
}