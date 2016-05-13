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
	int szukana ;  

	ios_base::sync_with_stdio( false );

	scanf("%d",&t);	
	FOR( i , 0 , t ){
		scanf("%d",&n);	

		suma = 0 ;

		FOR( i , 0 , n){
			scanf("%d",&tab[ i ]);	
			suma +=  tab[ i ];

		}

		szukana = suma/2;

		int* plecak = new int[ szukana +1];
		int * temp = new int[ szukana+1 ];

		for( int k = 0 ; k < n ; k++ ){
			int i = tab[ k ];
			if( i > szukana and k != 0 ) continue;
			memcpy( temp, plecak, (i+1)*sizeof(int));
			// int pos = (k == 0 ? 0 : i ); \/
			FOR ( j , i , szukana+1 ){
				if( k == 0 ) plecak[ j ] = temp[ j ] = 0;				
				temp [ j ] = max( i + plecak[ j - i ], plecak[ j ]);
				
			}
			delete[] plecak;
			plecak = temp;
			temp = new int[szukana+1];
		}

		printf("%d %d \n", abs( suma - 2 * plecak[ szukana ] ) , suma);

	}


	return 0 ;
}
