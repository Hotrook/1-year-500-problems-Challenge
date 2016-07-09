#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

typedef unsigned long long int uint64_t;

const uint64_t mod = 1000000007LL;

using namespace std;

int odp = -1;
	int * fromStart;
	int * fromEnd;

struct element{ int start; int stop; int length; };
struct vert{ int dis; element x; };

class Compare
{
public:
    bool operator() (vert a, vert b) 
    {
        return a.dis > b.dis ;
    }
};

int* dijkstra( vector< vector<element> >  edges, int start ){
	int size = edges.size()-1, res;
	int * dis = new int [ size+1 ];
	int * odw = new int [ size+1 ];
	vert ver;
	element temp;

	FOR( i, 1 , size+1 ){ 
		dis[ i ] = -1; odw[ i ] = 0;
	}
	dis[ start ] = 0 ;
	priority_queue< vert , vector<vert> , Compare> que; 

	ver.dis = 0 ;
	temp.start = start; temp.stop = start; temp.length = 0 ; 
	ver.x = temp;
	que.push( ver );

	int counter = 0;
	while( !que.empty() and counter <= size ) {
		vert tmp = que.top();
		que.pop();
		if( odw[ tmp.x.stop ] == 0){
			counter++;
			for( vector<element>::iterator it= edges[tmp.x.stop].begin();it!=edges[tmp.x.stop].end();++it){
				if( dis[ (*it).start ] + (*it).length < dis[ (*it).stop ] or dis[ (*it).stop ] == -1 ){
					dis[ (*it).stop ] = dis[ (*it).start ] + (*it).length; 
					ver.x = (*it) ;
					ver.dis = dis[ (*it).stop ];
					que.push( ver );
				}
			}

			odw[ tmp.x.stop ] = 1;
		}
	}


	delete[] odw;
	return dis;
}

void actualize(vector<vector<element> > edges,int * tab , int start, element x, int size, int min ){

	queue<int> que; 
	que.push( start );
	tab[ start ] -= min;
	while( !que.empty() ){ 
		int temp = que.front();
		que.pop();
		for( vector< element >::iterator it = edges[ temp ].begin() ; it!=edges[temp].end(); ++it){
			if( tab[ temp ] + (*it).length < tab[(*it).stop ] ){
				tab[(*it).stop ] = tab[ temp ] + (*it).length;
				que.push( (*it).stop );
			}
		}
	} 
}

int check(vector< vector<element> >  edges, element x ){
	bool result = false;
	int size = edges.size()-1, res;
	vert ver;
	element temp;

	priority_queue< vert , vector<vert> , Compare> que; 

	if( fromStart[ x.stop] < fromStart[ x.start ] ) swap( x.start, x.stop );
	if( fromStart[x.start] + x.length + fromEnd[ x.stop ] < fromStart[ size ] and fromStart[x.start] != - 1 and fromStart[ x.stop ] != -1  ){
		int min = fromStart[ x.stop ] - fromStart[ x.start ] - x.length;
		actualize( edges,fromStart , x.stop , x , size+1,min );
		swap( x.start , x.stop );
		min = fromEnd[ x.stop ] - fromEnd[ x.start ] - x.length;
		actualize(edges, fromEnd , x.stop , x, size+1, min);
		return 1;
	}

		return 0;

}


int main(){
	int n;
	int k;
	int m;
	int length;

	int t;
	int a;
	int b; 
	int start;
	int rodzaj;

	int * takiDinks;
	element x;
	element temp;


	ios_base::sync_with_stdio( false );


	scanf("%d %d %d",&n,&k,&m);

	vector< vector< element > > edges( n+1 );

	FOR( i , 0 , k ){

		scanf("%d %d %d",&a,&b,&length);
		temp.start = a;
		temp.stop = b;
		temp.length = length;

		edges[ a ].PB( temp );

		swap ( temp.start, temp.stop );

		edges[ b ].PB( temp );

	}

	fromStart = dijkstra( edges, 1 );
	fromEnd = dijkstra( edges, n );

	FOR( i , 0 , m ){
		scanf("%d %d %d",&a,&b,&length);
		x.start = a ;
		x.stop = b ; 
		x.length = length;

		
		edges[ a ].PB ( x );

		swap( x.start, x.stop );

		edges[ b ].PB( x );

		swap( x.start, x.stop );

		if( check(edges, x) ){
			printf("1\n");	
		}
		else {
			edges[ a ].erase( edges[ a ].end()-1 ); 
			edges[ b ].erase( edges[ b ].end()-1 ); 
			printf("0\n");	
		}


	}


	return 0 ;
}
