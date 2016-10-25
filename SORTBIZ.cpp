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




bool lesss( string* tab, int a, int b){
	int len = tab[a].length();
	if( tab[a].length() < tab[b].length())
		return true;
	else if( tab[ b ].length() < tab[a].length())
		return false;
	else{
		for( int i = 0 ; i < len ; ++i ){
			if(  tab[a][ i ] < tab[b][ i ] ) return true;
			else if ( tab[b][ i ] < tab[a][ i ]) return false;
		}
		return false;
	}
}


int movePivot( string* tab, int start, int stop ){
	string m = tab[ start ]; 
	int p = start ;
	for ( int i = start ; i <= stop ; ++i ) {
		if( lesss( tab, i , start )){
			p++;
			swap( tab[ p ] , tab[ i ]);
		}
	}
	swap( tab[ start ], tab[ p ]);
	return p;
}


void qsort( string* tab , int start, int stop){
	if( start >= stop ) return;
	else{
		int pivot = movePivot( tab, start, stop );

		qsort( tab, start , pivot - 1 ) ;
		qsort( tab, pivot + 1 , stop) ; 
	}
}


int main(){
	

	int n;
	string tab[200];

	ios_base::sync_with_stdio( false );
	

	cin >> n ;
	
	for( int i = 0 ; i < n ; ++i ){
		cin >> tab[ i ];
	}
	qsort( tab , 0 , n-1 ) ;

	for ( int i = 0 ; i < n ; ++i ){
		cout << tab[ i ] << endl;
	}
	return 0 ;
}
