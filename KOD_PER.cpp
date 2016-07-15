#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
using namespace std;


typedef unsigned long long int uint64_t;

const uint64_t mod = 1000000007LL;



int main(){
	
	int n;
	int m;
	int k;
	
	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	int * temp;
	int * results;

	bool cond = true;

	ios_base::sync_with_stdio( false );
	vector< int > input;

	cin >> t;
	temp = new int[ t+1 ];
	results = new int[ t+1 ];



	FOR( i , 0 , t ) {
		cin >> a;
		input.PB( a );
		temp[ i ] = 1 ;
	}

	for( int i = t -1 ; i >= 0 ; --i ){
		int counter = 0;
		int it = t-1 ;
		while( true ){
			if( it == -1 ){
				cond = false;
				break;
			}
			if( counter == input[ i ] and temp[ it ] == 1 ){
				results[ i ] = it+1;
				temp[ it ] = 0;
				break;
			}
			else if( counter < input[ i ] and temp[ it ] == 1 ){
				counter++;
			}
			it--;
		}


	}

	if( cond ){
		FOR( i , 0 , t )
			cout << results[ i ] << "\n";
	}
	else{
		cout<< "NIE\n";
	}

	return 0 ;
}
