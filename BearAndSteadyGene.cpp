#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )
#define PB push_back
typedef unsigned long long int ulint;

using namespace std;


int transform( char c ){
	if( c == 'A' ) return 0;
	if( c == 'C' ) return 1;
	if( c == 'G' ) return 2;
	if( c == 'T' ) return 3;
    return -1; 
}

int main(){
	
	int n;
	int cnt = 0;
	int test = 0;
	int max;
	string s;

	char letters[ ] = { 'A', 'C', 'G', 'T' };
	vector< int > pos[ 4 ];
	vector< int > amount( 4 );
	vector< int > overflows;

	cin >> n;
	cin >> s;

	vector< int > help[ 4 ];

	
	FOR( i, 0 , 4 ) help[ i ] = vector< int >( n );

	
	FOR( i , 0 , s.length() ){

		pos[ transform(s[ i ]) ].PB( i );
		amount[ transform( s[ i ] ) ]++;
		FOR( k, 0, 4 )
			help[ k ][ i ] = amount[ k ];
	}



	FOR( i, 0, 4 ){
		if( amount[ i ] == n/4 ) test++;
		if( amount[ i ] > n/4 ){
			cnt += amount[ i ] - n/4 ;
			amount[ i ] = amount[ i ] - n / 4;
			overflows.PB( i );
		}
	}

    

	if( test == 4 ){
		cout << "0\n" ;
	}
	else{
		int scope = n - cnt;

		for( auto i : overflows ){
			int temp =  pos[ i ][pos[ i ].size() - amount[ i ] ];
			if( temp < scope ) scope = temp;
		}

		int temp = 0;
		int myMin = 0;
		int result = n;

		FOR( i, 0, scope+1 ){
			myMin = i;
			for( auto x : overflows ){
				if( s[ i ] == letters[ x ] ){
					temp = help[ x ][ i ] + amount[ x ] - 1  ;
				}
				else{
					temp = help[ x ][ i ] + amount[ x ]   ;
				}
				if( pos[ x ][ temp-1 ] > myMin ) myMin = pos[ x ][ temp-1 ];
			}
			result = min( result, myMin - i + 1);
		}
		cout << result << endl;
		
	}


	return 0 ;
}
