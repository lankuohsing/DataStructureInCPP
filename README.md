# C++实现的常见数据结构（DataStructureInCPP）
---------------------------------------------------------
[TOC]
## 0. 前言
DataStructureInCPP是一个用C++实现各种常见的数据结构与算法的项目。

## 1. 单链表（Singly Linked List）
单链表的基本结构示例如下：
![Alt text](./1504342905780.png)
注意，为了实现的方便，我们为单链表加上了一个“附加头结点”——First。
### 反转单链表
声明两个指针p和q，p指向p1，q指向p2。只要q非空，进行如下循环：
1. p指向q后面的结点
2. q指向first后面的结点
3. first指向q
4. q指向p后面的结点

代码如下：
```
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
```

