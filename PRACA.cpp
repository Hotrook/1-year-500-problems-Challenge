#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
typedef pair< int, int > element;
typedef unsigned long long int ulint;

int partia[ 1000001 ];
int tab[ 1000001 ];

void make ( int last , int b , int i ){
	for( int j = last ; j <= b ; ++j ) {
		if( partia[ j ] != i ) tab[ j ] = 0;
		tab[ j ] += tab[ j - 1 ];
	}
}
int main(){
	
	int n;
	int m;
	int t;
	int a;
	int b; 
	int last = 1;

	scanf( "%d",&t);

	FOR( i , 0 , t ){
		scanf( "%d %d",&m,&n);
		last = 1 ;
		FOR( j , 0 , m ){
			scanf( "%d",&a);
			if( partia[ a ] != i ) {
				tab[ a ] = 0 ;
				partia[ a ] = i;
			}
			tab[ a ]++;
		}

		if(partia[ 0 ] != i ) tab[ 0 ] = 0;
		

		scanf( "%d",&n);

		FOR( j , 0 , n ){
			scanf( "%d %d",&a,&b);
			if ( last-1 < b ){
				make( last , b , i);
				last = b+1;
			}
			int temp = tab[ b ];
			if( a!= 0 ) temp -= tab[ a-1 ];
			printf("%d\n",temp);
		}

	}

	return 0 ;
}



