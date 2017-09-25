#include<iostream>
using namespace std;
void findMinNum ( int sum, int *coin, int coinKinds )
{

	int *dp = new int [ sum + 1 ] ( );//�洢����Ǯ����Ӳ������������
	int *coinValue = new int [ sum + 1 ] ( );
	for ( int i = 0; i < sum + 1; i++ )
	{
		dp [ i ] = i;

	}

	for ( int i = 1; i <= sum; i++ )
	{
		for ( int j = 0; j < coinKinds; j++ )
		{
			if ( i >= coin [ j ] //Ϊ�˱�֤�����±�Ǹ�
				&&
				dp [ i ] >= dp [ i - coin [ j ] ] + 1//����״̬ת�Ʒ��� 
				&& ( i == coin [ j ] || coinValue [ i - coin [ j ] ] != 0 ) )//�����������޽�ȴ�ֽ�����״̬����
			{
				dp [ i ] = dp [ i - coin [ j ] ] + 1;
				coinValue [ i ] = coin [ j ];
				i = i;
			}
		}
	}
	if ( coinValue [ sum ] == 0 )
	{
		cout << "�޽⣡" << endl;
		return;
	}
	cout << "�ճ�" << sum << "ԪǮ��Ҫ���ٵ�Ӳ�Ҹ���Ϊ��" << dp [ sum ] << endl;
	cout << "ÿ�μ����Ӳ��Ϊ��";
	for ( int i = 0; i < sum + 1; i++ )
	{
		cout << coinValue [ i ] << " ";
	}
	cout << endl;
	cout << "������Ϊ��";

	while ( sum>0 )
	{
		cout << coinValue [ sum ] << " ";
		sum -= coinValue [ sum ];

	}
	cout << endl;
	delete [ ] dp;
	delete [ ] coinValue;
}
int main ( )
{
	int sum = 11;
	int coin [ ] = { 1, 3, 5 };//�洢����Ӳ�Ҽ�ֵ������
	int coinKinds = sizeof( coin ) / sizeof( coin [ 0 ] );
	findMinNum ( sum, coin, coinKinds );
	system ( "pause" );
	return 0;
}