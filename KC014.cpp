#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for( int i = a ; i < b ; ++i )

const unsigned long long int size = 100;
using namespace std;


int main(){
	
	unsigned long long int t;
	unsigned long long int n;
	unsigned long long int k; 
	unsigned long long int tab[ size ][ size ];
	unsigned long long int stab[ size ][ size ];
	unsigned long long int rtab[ size ][ size ];
	unsigned long long int result;
	unsigned long long int sum = 0;
	char c;

	

	while(cin >> n ){
		FOR( i, 0, n){
			FOR( j, 0 , n){
				cin >> tab[ i ][ j ];
				rtab[ i ][ j ] = 0;
			}
		}
		FOR( i, 0, n){
			FOR( j, 0 , n){
				cin >> stab[ i ][ j ];
			}
		} 


		FOR( i, 0, n )
		FOR( j, 0 ,n )
		FOR( k, 0 ,n )
			rtab[ i ][ j ] += tab[ i ][ k ] * stab[ k ][ j ];

		FOR( i, 0 , n )
		FOR( j, 0 , n )
			cout << rtab[ i ][ j ] << " ";
		cout << endl;
	}




	return 0 ;
}