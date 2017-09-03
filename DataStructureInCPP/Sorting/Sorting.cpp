#include"Sorting.h"

void BubbleSort ( int array [ ], int n )
{//冒泡法
	for ( int i = 1; i < n; i++ )
	{
		for ( int j = n - 1; j >= i; j-- )
		{
			if ( array [ j - 1 ]>array [ j ] )
			{
				array [ j - 1 ] = array [ j - 1 ] + array [ j ];
				array [ j ] = array [ j - 1 ] - array [ j ];
				array [ j - 1 ] = array [ j - 1 ] - array [ j ];
			}
		}

	}
}

int partition ( int array [ ], const int left, const int right )
{
	int pivotPos = left;//基准元素起始下标
	int pivot = array [ left ];//基准元素
	for ( int i = left + 1; i <= right; i++ )
	{
		if ( array [ i ]<pivot )//出现比基准元素小的元素
		{

			pivotPos++;
			if ( pivotPos != i )//意味着有一个小于基准元素的元素array [ i ]
				//在一个大于基准元素的元素array [ pivotPos ]右边
			{
				//将array [ pivotPos ]与array [ i ]互换
				array [ i ] = array [ pivotPos ] + array [ i ];
				array [ pivotPos ] = array [ i ] - array [ pivotPos ];
				array [ i ] = array [ i ] - array [ pivotPos ];

			}
		}
	}
	array [ left ] = array [ pivotPos ];
	array [ pivotPos ] = pivot;
	return pivotPos;
}
void quickSort ( int array [ ], int left, int right )
{
	int pivotPos;
	if ( left<right )
	{
		pivotPos = partition ( array, left, right );
		quickSort ( array, left, pivotPos - 1 );
		quickSort ( array, pivotPos + 1, right );
	}

}