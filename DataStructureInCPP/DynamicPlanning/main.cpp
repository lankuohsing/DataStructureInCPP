#include<iostream>
using namespace std;
void findMinNum ( int sum, int *coin, int coinKinds )
{

	int *dp = new int [ sum + 1 ] ( );//存储各种钱数的硬币数量的数组
	int *coinValue = new int [ sum + 1 ] ( );
	for ( int i = 0; i < sum + 1; i++ )
	{
		dp [ i ] = i;

	}

	for ( int i = 1; i <= sum; i++ )
	{
		for ( int j = 0; j < coinKinds; j++ )
		{
			if ( i >= coin [ j ] //为了保证数组下标非负
				&&
				dp [ i ] >= dp [ i - coin [ j ] ] + 1//满足状态转移方程 
				&& ( i == coin [ j ] || coinValue [ i - coin [ j ] ] != 0 ) )//避免子问题无解却又进行了状态更新
			{
				dp [ i ] = dp [ i - coin [ j ] ] + 1;
				coinValue [ i ] = coin [ j ];
				i = i;
			}
		}
	}
	if ( coinValue [ sum ] == 0 )
	{
		cout << "无解！" << endl;
		return;
	}
	cout << "凑成" << sum << "元钱需要最少的硬币个数为：" << dp [ sum ] << endl;
	cout << "每次加入的硬币为：";
	for ( int i = 0; i < sum + 1; i++ )
	{
		cout << coinValue [ i ] << " ";
	}
	cout << endl;
	cout << "组合情况为：";

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
	int coin [ ] = { 1, 3, 5 };//存储各种硬币价值的数组
	int coinKinds = sizeof( coin ) / sizeof( coin [ 0 ] );
	findMinNum ( sum, coin, coinKinds );
	system ( "pause" );
	return 0;
}