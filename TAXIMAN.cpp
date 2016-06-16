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

typedef pair< long long, long long > element;
typedef unsigned long long int ulint;



vector< element > tab; 

long long met( element a, element b ){
	return abs( a.first-b.first )+ abs( a.second-b.second );
}



element find( long long x, long long y ){
	element help;
	help.first = x;
	help.second = y;

	element result;

	long long max = 0;
	int temp;
	for( auto & i : tab ) {
		if( (temp = met(help , i ) ) > max ){
			max = temp;
			result = i ;
		}
	}

	return result;
}


int main(){
	
	long long n;
	long long t;
	long long b;
	long long minx = 20000000001LL;
	long long maxx = -20000000001LL;
	long long miny = 20000000001LL;
	long long maxy = -20000000001LL; 


	ios_base::sync_with_stdio( false );


	cin >> n;

	tab = vector< element >();

	FOR( i , 0 , n ){
		pair<long long, long long > x;
		cin >> x.first >> x.second ;

		tab.PB( x );

		maxx = max( maxx, x.first );
		minx = min( miny, x.first );
		maxy = max( maxy, x.second );
		miny = min( miny, x.second );
	}


	cout << max( met( find(minx,maxy), find( maxx, miny) ) , met(find(minx,miny),find(maxx,maxy))) << "\n";


	return 0 ;
}
