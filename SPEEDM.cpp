#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

using namespace std;


int main(){

	vector< int > tab( 5001 );
	
	int t;
	int n;
	int m;
	int a;
	int suma ;
	int minx;
	int szukana ;  

	ios_base::sync_with_stdio( false );


	scanf("%d",&t);	
	FOR( i , 0 , t ){
		scanf("%d",&n);	

		suma = 0 ;
		minx = 10000;

		FOR( i , 0 , n){
			scanf("%d",&tab[ i ]);	
			suma +=  tab[ i ];
		}

		szukana = suma/2;

		int* plecak = new int[ szukana +1];
		FOR( i , 0 , szukana+1) plecak [ i ] = 0 ;
		sort( tab.begin(),tab.begin()+n	);

		for( int k = 0 ; k < n ; k++ ){
			int i = tab[ k ];
		
			minx = k < n-1 ? tab[ k+1 ] : tab[ k ];
			plecak[ szukana ] =  max( i + plecak[ szukana - i ], plecak [ szukana ] );
			for( int j = szukana - minx ; j >= i ; --j ){
				plecak [ j ] = max( i + plecak[ j - i ], plecak[ j ]);
			}
		}

		printf("%d %d \n", abs( suma - 2 * plecak[ szukana ] ) , suma);

	}


	return 0 ;
}
