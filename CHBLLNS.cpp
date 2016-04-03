#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;



int main(){
	
	long long int t;
	long long int n;
	long long int k; 
	long long int l = 0;
	long long int tab[ 3 ];
	long long int result ;
	char c;

	cin >> t;

	FOR( i, 0 , t ){

		FOR( i, 0, 3){
			 l += 1000000000;
			cin >> tab[ i ];
		}

		FOR( i , 0 , 3 )
		FOR( j , i+1 , 3 )
			if( tab[ j ] < tab[ i ] )
				swap( tab[ j ], tab[ i ]);

		cin >> k;

		if( k <= tab[ 0 ] )
			result = (k-1) * 3 + 1;
		else {
			result = tab[ 0 ] * 3 ;
		
			if ( k  > tab[ 0 ] and k <= tab[ 1 ]){
				result += ( k - tab[0] -1 )*2 + 1;
			}
			if( k > tab[ 1 ] and k <= tab[ 2 ]){
				result += ( tab[ 1 ] - tab[ 0 ] ) * 2;
				result += k - tab[ 1 ];
			}

		}
		cout << result << endl;	
	}
}