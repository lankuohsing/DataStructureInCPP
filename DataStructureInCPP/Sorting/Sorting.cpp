#include"Sorting.h"

void BubbleSort ( int array [ ], int n )
{//ð�ݷ�
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
	int pivotPos = left;//��׼Ԫ����ʼ�±�
	int pivot = array [ left ];//��׼Ԫ��
	for ( int i = left + 1; i <= right; i++ )
	{
		if ( array [ i ]<pivot )//���ֱȻ�׼Ԫ��С��Ԫ��
		{

			pivotPos++;
			if ( pivotPos != i )//��ζ����һ��С�ڻ�׼Ԫ�ص�Ԫ��array [ i ]
				//��һ�����ڻ�׼Ԫ�ص�Ԫ��array [ pivotPos ]�ұ�
			{
				//��array [ pivotPos ]��array [ i ]����
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