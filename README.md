# C++ʵ�ֵĳ������ݽṹ��DataStructureInCPP��
---------------------------------------------------------
[TOC]
## 0. ǰ��
DataStructureInCPP��һ����C++ʵ�ָ��ֳ��������ݽṹ���㷨����Ŀ��

## 1. ������Singly Linked List��
������Ļ����ṹʾ�����£�
![Alt text](./1504342905780.png)
ע�⣬Ϊ��ʵ�ֵķ��㣬����Ϊ�����������һ��������ͷ��㡱����First��
### ��ת������
��������ָ��p��q��pָ��p1��qָ��p2��ֻҪq�ǿգ���������ѭ����
1. pָ��q����Ľ��
2. qָ��first����Ľ��
3. firstָ��q
4. qָ��p����Ľ��

�������£�
```
void Linked_List::reverseLinkedList ( )
{//��ת������
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

