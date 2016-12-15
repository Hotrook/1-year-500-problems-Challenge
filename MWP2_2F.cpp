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


typedef unsigned long long int uint64_t;

const uint64_t mod = 1000000007LL;

int * un;
int * size;

void makeUnion( int n ){
	un = new int[ n ];
	size = new int[ n ];
	FOR( i , 0 , n ){ 
		un[ i ] = i;
		size[ i ] = 1;
	}
}

int find( int x ){
	if( x == un[ x ] )
		return x;
	else 
		return x = find( un[ x ] );
}

int pairUnion( int a, int b ){
	int x = find( a );
	int y = find( b );

	if( x != y ){
		if( y > x ) swap( x, y );
		un[ y ] = x;
		size[ x ] += size[ y ];
		size[ y ] = 0;
	}
	return size[ x ];
} 

int main(){
	
	int n;
	int m;
	int k;
	
	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	string temp;

	ios_base::sync_with_stdio( false );

	cin >> t;

	FOR( i , 0 , t ) {
		 cin >> n >> m ;
		 int max = 0 ;
		 makeUnion( n );
		 FOR( j , 0 , m ){
		 	cin >> a >> b ;
		 	int temp = pairUnion( a, b );
		 	max = temp > max ? temp : max;
		 }
		 cout << max << "\n";
	}
	return 0 ;
}
