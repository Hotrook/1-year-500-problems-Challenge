#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

using namespace std;

typedef pair< long long, long long > element;
typedef unsigned long long int ulint;



vector< element > tab;

long long met( element a, element b ){
	return (abs(a.first-b.first )+ abs( a.second-b.second ));
}


element find( long long x, long long y ){
	element help;
	help.first = x;
	help.second = y;

	element result;

	long long min = 10000000000LL;
	long long temp;
	for( auto & i : tab ) {
		temp = met(help , i );
		if( temp < min ){
			min = temp;
			result = i ;
		}
	}

	return result;
}


int main(){
	
	long long n;
	long long t;
	long long a;
	long long b;
	long long minx = 2000000001LL;
	long long maxx = -2000000001LL;
	long long miny = 2000000001LL;
	long long maxy = -2000000001LL; 

	ios_base::sync_with_stdio( false );


	scanf("%lld",&n);

	tab = vector< element >();
	pair<long long, long long > x;



	FOR( i , 0 , n ){
		scanf("%lld %lld",&x.first,&x.second);

		tab.PB( x );

		if( x.first > maxx )
			maxx = x.first;
		if( x.first < minx )
			minx = x.first;
		if( x.second > maxy )
			maxy = x.second;
		if( x.second < miny )
			miny = x.second; 
	}

	long long temp = met( find(minx,maxy), find( maxx, miny) );
	long long temp2 = met(find(minx,miny),find(maxx,maxy) );
	long long result = temp > temp2 ? temp : temp2;

	if( tab.size() == 2 )
		printf("%lld\n",met( tab[ 0 ], tab[ 1 ] ));
	else
		printf("%lld\n",result );

	return 0 ;
}
