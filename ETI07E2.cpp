#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
typedef unsigned long long int ulint;

using namespace std;


bool check( char a, char b ){
	if ( a == 'N' and b == 'E' ) return true;
	if ( a == 'E' and b == 'N' ) return true;
	if ( a == 'W' and b == 'S' ) return true;
	if ( a == 'S' and b == 'W' ) return true;
	return false;
}


int main(){
	
	int t;
	int sum = 0;

	char * tab;


	ios_base::sync_with_stdio( false );


	scanf("%d",&t);

	tab = new char [ t+1 ];

	scanf("%s",tab);
	FOR( i , 1 , t ){

		if( tab[ i ] == tab[ i-1 ] or check( tab[ i ], tab[ i-1 ] ) )
			sum++;
		if( i == t-1 )
			if( tab[ i ] == tab[ 0 ] or check( tab[ i ], tab[ 0 ] )) 
				sum++;
	}
	printf("%d\n", sum/2);

	delete[] tab;


	return 0 ;
}
