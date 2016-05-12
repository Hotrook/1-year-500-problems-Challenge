#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

using namespace std;

int tab[1000000];
int ilosc[1000000];

struct edge{
	int start;
	int stop;
	int waga;
};

bool comparator( edge a, edge b );
void makeSet( int n );
int find( int n );
bool unionn( int a, int  b, int n);

vector < edge > edges ;

int main(){
	
	int t;
	int n;
	int m;
	int suma ;
	edge x;

	scanf("%d ",&t);	
	FOR( i , 0 , t){
		suma = 0 ; 

		scanf("n=%d,m=%d ", &n, &m); 

		edges = vector< edge >();
		FOR( j, 0 , m ){
			scanf("{%d,%d}%d ",&x.start,&x.stop,&x.waga);
			edges.PB(x);
		}
		
		sort( edges.begin(), edges.end(), comparator);

		makeSet( n );

		FOR ( j , 0 , m ){
			if( find( edges[j].start ) != find( edges[j].stop ) ){
				suma += edges[ j ].waga;
				if (unionn( edges[ j ].start , edges[ j ].stop , n ) )break;
			}
		}
		printf( "%d\n",suma );
	}
	return 0 ;
}




//******************************************************************************
bool comparator( edge a, edge b ){
	return a.waga < b.waga ;
}
//******************************************************************************




//******************************************************************************
void makeSet( int n ){
	FOR( i , 0 , n +1 ){
		tab[ i ] = i ;
		ilosc[ i ] = 1; 
	}
}
//******************************************************************************




//******************************************************************************
int find( int n ){
	if( tab [ n ] == n )
		return n ;
	else return tab[ n ] = find( tab[ n ] );
}
//******************************************************************************




//******************************************************************************
bool unionn( int a, int  b, int n){
	int fa = find ( a );
	int fb = find ( b );

	if( fa == fb )
		return false ;

	if( ilosc[ fb ] > ilosc[ fa ] ) swap( fa , fb );

	tab[ fb ] = fa;
	ilosc[ fa ] += ilosc[ fb ];

	if( ilosc[ fa ] == n )
		return true;
	else 
		return false;
}
//******************************************************************************