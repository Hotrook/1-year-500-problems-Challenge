#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define FOR( i, a, b ) for( int i = a ; i < b; ++i )
#define PB push_back 
#define VVI vector< vector< int > > 
#define PII pair< int, int > 
#define MP make_pair
#define VVPII vector< vector< pair< int, int > > >

using namespace std;


int dijkstra(  int n, VVPII & dist, int start, int stop ){
	vector< int > starts( n + 1, -1 );
	vector< int > stops( n + 1, -1 );

	bfs( start, dist, )

	return shortest[ stop ];

}

int main(){

	int n;
	int m;

	int a;
	int b;
	int c;

	int start;
	int stop;

	cin >> n >> m;

	vector< vector< pair< int, int > > > dist( n+1 );

	FOR( i, 0, m ){
		cin >> a >> b >> c;

		dist[ a ].PB(MP( b, c ));
		dist[ b ].PB(MP( a, c ));
 	}

 	cin >> start >> stop;


 	int result = dijkstra( n, dist, start, stop );

 	cout << result << "\n";
	return 0;
}