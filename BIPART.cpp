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

typedef unsigned long long int uint64_t;


using namespace std;

int * kolor;
bool bfsCheck( vector< vector<int> > & edges, int size , int t ){

	queue< int > que; 

	FOR( i , 1 , size+1 ){
		if( kolor[ i ] != t and kolor[ i ] != t+1 ){
			que.push( i );
			kolor[ i ] = t;

			while( !que.empty() ){
				int temp = que.front();
				que.pop();

				for( auto & i : edges[ temp ] ){
					if( kolor[ i ] != t and kolor[ i ] != t+1 ){
						kolor[ i ] = kolor[ temp ] == t ? t+1 : t; 
						que.push( i );
					}
					else if( kolor[ i ] == kolor[ temp ] ){
						return false;
					}
						
				}
			}
		}	
	}

	return true;
}


int main(){
	
	int n;
	int m;

	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	vector < vector< int > > edges;

	kolor = new int[ 1000001 ];
	FOR ( i, 1, 1000001 ) kolor[ i ] = -1;
	ios_base::sync_with_stdio( false );


	scanf("%d",&t);

	FOR( i , 0 , t ){
		scanf("%d %d",&n,&m);
		edges = vector < vector< int > > ( n+1 );

		FOR( j , 0 , m ){
			scanf("%d %d",&a,&b);
			edges[ a ].PB( b );
			edges[ b ].PB( a );
		}

		if( n == 1 and m == 0 ) cout << "NIE\n";
		else if( bfsCheck( edges, n, 2*t ) ) cout << "TAK\n";
		else cout << "NIE\n";

	}

	delete[] kolor;

	return 0 ;
}
