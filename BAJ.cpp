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

struct edge{ long long p; long long k; long long w; int pos;};

long long fau[7001];
long long ilosc[7001];
int result[ 300001 ];

void makeset( long long n ){
	FOR( i, 1 , n+1 ){
		fau[ i ] = i;
		ilosc[ i ] = 1;
	}
}
long long find( long long a ){
		return fau[ a ] == a ? a : fau[ a ] = find( fau[ a ] );
}

bool unionn( long long a , long long b){
	long long fa = find(a);
	long long fb = find(b);

	if( fa == fb ) return false;

	if(min( ilosc[fa], ilosc[ fb ] ) == ilosc[ fa ]) swap( fa, fb );

	ilosc[ fa ] += ilosc[ fb ];
	fau[ fb ] = fa;

	return true;

}



bool comparator( edge a, edge b){
	return a.w < b.w ;
}

vector < edge > ms;


int main(){
	
	long long t;
	long long n;
	long long m;

	long long surf; //surface


	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;

	FOR( i , 0 , m ){
		edge x;
		cin >> x.p >> x.k >> x.w ;
		x.pos = i; 
		ms.PB( x );
	}

	makeset( n );
	sort( ms.begin(), ms.end() , comparator );


	long long prev = -1;
	for( long long i = 0 ; i < m ; ++i ){
		if( ms[ i ].w != prev ){
			long long j = i ;
			while( j < m and ms[ j ].w == ms[ i ].w ){
				if( find( ms[ j ].p) != find( ms[ j ].k ) ){
					result[ ms[ j ].pos ] = 1;	
				}
				j++;
			}
		}
		if( find( ms[ i ].p ) != find( ms[ i ].k ) ){
			unionn( ms[ i ].p, ms[ i ].k );
		}
		prev = ms[ i ].w;
	}


	for( int i = 0 ; i < m ; ++i ){
		if( result[ i ] == 1 ){
			cout << "TAK\n";
		}
		else
			cout << "NIE\n";
	}


	return 0 ;
}