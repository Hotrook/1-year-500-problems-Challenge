#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define FORA(i,a,b) for(long long i = a ; i <= b ; ++i )
#define PB push_back
#define BIG 1000000000000000
typedef std::pair< int, int > element;
typedef unsigned long long int ulint;

using namespace std;

ulint help[ 201 ][ 201 ];


int countMatrix( element a, element b ){
	return a.first * b.second * a.second;
}
 
int findMin( vector < element > & tab , int start, int stop ){ 
	int n = stop;
	FORA( i , 1 , n )help[ i ][ i ] = 0 ;

	FORA( l, 2 , n )
		FORA( i , 1 , n-l+1 ){
			int j = i+l-1;
			help [ i ][ j ] = -1;
			FORA( k , i , j-1  ){
				int q = help[ i ][ k ] + help[ k + 1 ][ j ] + tab[ i ].first * tab[ k ].second * tab[ j ].second;
				if ( q < help[ i ][ j ] or help [ i ][ j ] == -1 ){
					help [ i ][ j ] = q;
				}
			}
		}
	return help[ 1 ][ stop ];
}



int main(){
	
	int n;
	int t;
	int a;
	int b; 
	int rodzaj;

	vector <element> tab(201); 

	element x;

	ios_base::sync_with_stdio( false );


	scanf( "%d",&t);

	FOR( i , 0 , t ){
		scanf( "%d",&n);

		FOR( i , 0 , n )
		FOR( j , 0 , n ) help[ i ][ j ] = 0;
		
		scanf("%d",&b);

		FOR( i , 1 , n+1 ){

			scanf( "%d",&a);
			x.first = b;
			x.second = a;

			tab[ i ] = x;

			b = a; 
		}

		printf("%d\n",findMin( tab, 0 , n ));


	}


	return 0 ;
}
