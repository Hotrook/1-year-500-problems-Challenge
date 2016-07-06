#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

using namespace std;


bool check( int * tab, int start , int stop, int value , int max_value ){
	int max = -1 ;
	FOR( i , start , stop )
		max = tab[ i ] > max ? tab[ i ] : max ;
	return max + value <= max_value ? true  : false ;
}

void actualize( int * tab , int start, int stop ,int value ){
	FOR( i , start, stop )
		tab[ i ] += value; 
}

int main(){
	
	int n;
	int m;
	int z; 
	int a;
	int b;
	int c;
	int start;
	int stop;
	int rodzaj;
	int tab[ 60001 ];

	ios_base::sync_with_stdio( false );

	scanf( "%d %d %d",&n,&m,&z);


	FOR( i , 0 , n + 1 ) tab[ i ] = 0;

	FOR( i , 0 , z ){
		scanf( "%d %d %d",&a,&b,&c);
		if( check( tab, a, b, c, m) ){
			printf("T\n");
			actualize( tab, a, b, c);
		}
		else
			printf("N\n");
	}


	return 0 ;
}
