#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
#define FOREACH(it,struct) for( auto & it : struct )
#define MP make_pair

using namespace std;

typedef unsigned long long int uint64_t;
typedef pair<int,int> pr;

const uint64_t mod = 1000000007LL;

int * d;
int * low; 
int s; 

bool comparator( pr a, pr b ){
	if( a.first < b.first ) return true;
	if( a.first == b.first and a.second < b.second ) return true;
	return false;
}

void dfsSearch( vector< vector < int > > &edges, vector< pr >& results , int i,  int u ){
	d[ i ] = low [ i ] = s++;

	FOREACH( it , edges[ i ] ){

		if( d[ it ] == -1 ){
			dfsSearch( edges, results, it , i  );
			if( low[ it ] > d[ i ] ){
				results.PB(MP( min( it , i ), max( it , i ) ));
			}
			else{
				low[ i ]= min( low [ i ], low[ it ] );
			}
		}
		else if( it != u ){
			low[ i ] = min( low[ i ], d[ it ] );
		}
	}
}

void checkBridges( vector< vector < int > > & edges, vector< pr >& results, int size  ){
	FOR( i , 1, size + 1 )
		if( d[ i ] == -1 ){
			dfsSearch( edges , results, i, -1 );
		}
}




int main(){
	
	int n;
	int m;
	int k;

	int t;
	int a;
	int b; 
	int start;
	int rodzaj;


	vector < vector< int > > edges; 
	vector < pr > results;

	ios_base::sync_with_stdio( false );


	cin >> n >> m ;

	s = 0 ;

	edges = vector< vector < int > >( n + 1 );

	d = new int[ n + 1 ];
	low = new int[ n + 1 ];

	FOR( i , 1 , n+1 ) d[ i ] = -1;

	FOR( i , 0 , m ){
		cin >> a >> b ;

		edges[ a ].PB( b );
		edges[ b ].PB( a ); 

	}

	checkBridges( edges , results , n ) ;

	FOREACH( it , results )
		if ( it.first > it.second ) swap ( it.first , it.second );

	sort( results.begin() , results.end() , comparator );

	FOREACH( it ,results )
		cout << it.first << " " << it.second << "\n";

	delete[] d;
	delete[] low;
	return 0 ;
}
