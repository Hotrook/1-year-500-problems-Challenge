#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;



int main(){
	
	int t;
	int n;
	int tab[3];
	char c;

	cin >> t;

	FOR( i, 0 , t ){
		cin >> n ;
		FOR( i, 0, 3 ) tab[ i ] = 0;
		FOR( i, 0, n){
			cin >> c ;
			if( c == 'R' ){
				tab[ 1 ]++;
				tab[ 2 ]++;
			}
			else if( c == 'G' ){
				tab[ 0 ]++;
				tab[ 2 ]++;
			}
			else if( c == 'B' ){
				tab[ 0 ]++;
				tab[ 1 ]++;
			}
		}

		cout << min(  tab[ 0 ] , min ( tab[ 1 ], tab[ 2 ])) << endl;

	}



	return 0 ;
}