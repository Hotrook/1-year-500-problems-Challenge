#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
typedef unsigned long long int uint64_t;

using namespace std;

void mergeSort( vector<uint64_t> & tab , int start, int stop, uint64_t * inv ){
	if( start >= stop ) return;
	
	vector <uint64_t> temp;

	int partition = (start+stop)/2;
	mergeSort( tab, start , partition , inv );
	mergeSort( tab, partition+1 , stop , inv );

	int it1 = start;
	int it2 = partition+1; 

	while( it1 <= partition and it2 <= stop){
		if( tab[ it2 ] < tab[ it1 ] ){
			temp.PB( tab[ it2 ] );
			(*inv) += ( partition - it1 + 1);
			it2++;
		}
		else{
			temp.PB( tab[ it1 ] );
			it1++;
		}
	}

	while( it1 <= partition ){ temp.PB( tab[ it1 ] ); it1++; }
	while( it2 <= stop ){ temp.PB( tab[ it2 ] ); it2++; }

	for( int i = 0 ; i < temp.size() ; ++i )
		tab[ start + i ] = temp[ i ];

}


int main(){

	uint64_t n;
	uint64_t t;
	uint64_t a;
	uint64_t b;
	uint64_t start;
	uint64_t rodzaj;
	uint64_t *result = new uint64_t;

	vector  < uint64_t > tab;

	ios_base::sync_with_stdio( false );


	cin >> t;


	FOR( i , 0 , t ){
		cin >> n ;
		tab = vector< uint64_t >();

		*result = (uint64_t)0;
		FOR( i , 0 , n ){
			cin >> a; 
			tab.PB( a );	
		}

		mergeSort( tab, 0 , tab.size()-1 , result );

		cout << *result << endl;
		tab.clear();
	}


	return 0 ;
}
