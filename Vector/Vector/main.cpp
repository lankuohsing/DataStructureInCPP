#include<iostream>
#include"vector.h"

using namespace std;
int main ( void ){

	int A [ ] = { 1, 2, 3, 4, 5 };
	
	Vector<int> vector1 ( A, 5 );
	cout << vector1<<endl;
	system ( "pause" );
	return 0;
}