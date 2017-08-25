#include <iostream>  
#include <algorithm>  
#include <stack>  
using namespace std;

char *v;//�������飬�±�Ϊ����ţ�ֵΪ�������ƣ����ڴ��������޻�ͼ�У�  
int **e;//�ߵĶ�ά�������ڴ��������޻�ͼ�У�  

int *indegree;//���涥������������飨����������  
int *topo;//�������������������飨����������  

int *maxPath;//���浽�˵���·�������·����  

//���������޻�ͼ  
void creatGraph ( int vSize, int eSize )
{
	//��ʼ��  
	int i, j, k, c;
	char a, b;
	indegree = new int [ vSize ];
	topo = new int [ vSize ];
	v = new char [ vSize ];
	e = new int* [ vSize ];
	for ( i = 0; i<vSize; i++ )
		e [ i ] = new int [ vSize ];
	for ( i = 0; i<vSize; i++ )
	for ( j = 0; j<vSize; j++ )
		e [ i ][ j ] = 0;
	for ( i = 0; i<vSize; i++ )
	{
		indegree [ i ] = 0;
		topo [ i ] = 0;
	}

	//��ͼ  
	cout << endl << "��������������ƣ�";
	for ( i = 0; i<vSize; i++ )
		cin >> v [ i ];
	cout << endl << "���Ⱥ����붥��V1��V2����ʾV1->V2���Լ�Ȩֵ�������м�����" << endl;
	for ( i = 0; i<eSize; i++ )
	{
		cin >> a >> b >> c;
		for ( j = 0; j<vSize; j++ )
		if ( v [ j ] == a ) break;
		for ( k = 0; k<vSize; k++ )
		if ( v [ k ] == b ) break;
		e [ j ][ k ] = c;
		indegree [ k ]++;//���+1  

	}
}

//��������  
void topologicalSort ( int vSize )
{
	int i, j, k;
	for ( i = 0; i<vSize; i++ ) //vSize��ѭ��  
	{
		j = 0;
		while ( j<vSize&&indegree [ j ] != 0 ) j++;//�ҵ����Ϊ0�Ķ���  
		topo [ i ] = j;//����  
		indegree [ j ] = -1;// ����jΪ���Ϊ-1�������ٴ����j  

		for ( k = 0; k<vSize; k++ )//����������ȵ�  
		if ( e [ j ][ k ] != 0 )
			indegree [ k ]--;
	}
}

//�·��  
void getMaxPath ( int vSize )
{
	//��ʼ��  
	int i, j, k, v1, v2, max = 0, **path, *p;
	maxPath = new int [ vSize ];            //�����·������ʾ������N���·��  
	p = new int [ vSize ];                  //���������·�ߵ�ѡ�񶥵�  
	path = new int* [ vSize ];              //��������㵽����·������  
	for ( i = 0; i<vSize; i++ )
		path [ i ] = new int [ vSize ];
	for ( i = 0; i<vSize; i++ )
	for ( j = 0; j<vSize; j++ )
		path [ i ][ j ] = 0;
	for ( i = 0; i<vSize; i++ )
	{
		maxPath [ i ] = 0;
		p [ i ] = 0;
	}

	//�ؼ����룬���·��  
	for ( j = 0; j<vSize; j++ )
	{
		v2 = topo [ j ];
		for ( k = 0; k<j; k++ )
		{
			v1 = topo [ k ];
			if ( e [ v1 ][ v2 ] != 0 )                     //��ʾ��·  
			{
				if ( maxPath [ v1 ] + e [ v1 ][ v2 ]>maxPath [ v2 ] )
					maxPath [ v2 ] = maxPath [ v1 ] + e [ v1 ][ v2 ];

				if ( maxPath [ v2 ]>max )
				{
					max = maxPath [ v2 ];//���泤��  
					path [ v1 ][ v2 ] = max;
				}
			}
		}
	}

	//���·��  
	stack<int> s;//������·  
	for ( i = vSize - 1; i>0; )
	{
		for ( j = 0; j<vSize; j++ )
		{
			p [ j ] = path [ j ][ i ];
		}
		sort ( p, p + vSize );
		int maxValue = p [ j - 1 ];
		if ( maxValue != 0 )
		{
			for ( j = 0; j<vSize; j++ )
			{
				if ( path [ j ][ i ] == maxValue )
				{
					s.push ( i );
					i = j;
					if ( i == 0 )
						s.push ( i );
					break;
				}
			}
		}
	}

	//������  
	cout << endl << "�·���ĳ����ǣ�" << max << endl << "�·��Ϊ��";
	int len = s.size ( );
	for ( i = 0; i<len; i++ )
	{
		if ( i != 0 ) cout << " -> ";
		cout << v [ s.top ( ) ];
		s.pop ( );
	}
	cout << endl << endl;
}

int main ( )
{
	int vSize, eSize, i;
	while ( 1 )
	{
		cout << "����ֱ����������޻�ͼ�Ķ������ͱ�����";
		cin >> vSize >> eSize;

		creatGraph ( vSize, eSize );//����ͼ  
		topologicalSort ( vSize );//��������  
		getMaxPath ( vSize );//�·��  

	}
	return 0;
}