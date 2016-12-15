#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set> 
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
#define VI vector<int>
#define PII pair<int , int>
#define mp make_pair

using namespace std;

struct Compare{
	bool operator()( PII a , PII b ){
		return a.second < b.second ;
	}
};

void dijkstra( int start, vector<vector<PII>> &edges, VI & results ){
	priority_queue< PII, vector<PII> , Compare > pq ;

	pq.push( mp(start, 0) );
	results[ start ] = 0;

	while( !pq.empty() ){
		PII temp = pq.top();
		pq.pop();

		for( auto dest : edges[ temp.first ] ){
			 int hp = results[ dest.first ];
			 
			 if( hp == -1 or temp.second + dest.second < hp ){
			 	results[ dest.first ] = temp.second + dest.second; 
			 	pq.push( mp(dest.first, results[ dest.first ]) );
			 }
		}
	}
}



int main(){
	

	int n;
	int m;
	
	int t;
	int a;
	int b;
	int c;
	int start;

	ios_base::sync_with_stdio( false );

	vector< vector<PII> > input;
	VI results;

	cin >> t;

	for( int l = 0 ; l < t ; ++l ){
		cin >> n >> m ;

		input.clear();
		input = vector<vector<PII>>(n+1, vector<PII>());


		FOR( i , 0 , m ){
			cin >> a >> b >> c;
			input[ a ].PB( mp( b, c ) );
			input[ b ].PB( mp( a, c ) );
		}
		cin >> start;

		results = VI( n+1, -1 );

		dijkstra( start, input , results );

		FOR( i, 1, n+1 ){
			if( i != start )
			cout << results[ i ] << " ";
		}
		cout << endl;
	}
	return 0 ;
}
