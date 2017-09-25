#include<iostream>
#include"Sorting.h"
using namespace std;

int main ( )
{
	
	int array [ ] = { 34, 65, 12, 43, 67, 5, 78, 10, 3, 70 }, k;
	int len = sizeof( array ) / sizeof( int );
	cout << "The orginal arrayare:" << endl;
	for ( k = 0; k<len; k++ )
		cout << array [ k ] << ",";
	cout << endl;
	quickSort ( array, 0, len - 1 );
	cout << "The sorted arrayare:" << endl;
	for ( k = 0; k<len; k++ )
		cout << array [ k ] << ",";
	cout << endl;
	/*
	int a [ ] = {1,2,3,4,5 };
	cout << sizeof( a ) / sizeof( int ) << endl;*/
	system ( "pause" );
	return 0;


}