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
#define MP make_pair
#define VI vector<int>
#define VPI vector< triple >
#define PII pair<int, int> 
#define CERR cerr<<"CERR " 
using namespace std;


struct triple{
	int first;
	int second; 
	int third;
};

bool cmp( triple& a, triple& b ){
	return a.first < b.first ;
}


int findLayer( vector< VPI > & l, int start, int stop, triple a){
	if( start == stop-1 ){
		if( l[ start ][ l[ start ].size() -1  ].second < a.second  )
			return start;
		else 
			return stop;
	}
	if( start == stop ){
		int len = l[ start ].size();
		if( start > 0 and l[ start-1 ][ l[start-1].size() - 1 ].second < a.second  ){
		 start--;
		}
		return start; 
	}
	else{
		int mid = (start + stop )/2;
		int len = l[ mid ].size()-1;
		if( a.second > l[ mid ][ len ].second ){
			// if( mid > start ) mid--;
			return findLayer( l, start, mid, a );
		}
		else{
			// if( mid < stop ) mid++;
			return findLayer( l, mid, stop, a );
		}
	}
}

void add( triple a, vector< VPI > & l ){
	int layer;
	int lsize = l.size();
	int lastSize = l[ lsize - 1 ].size();

	if( a.second < l[ l.size()-1 ][lastSize - 1 ].second ){
		
		VPI toAdd = VPI();
		toAdd.PB( a );
		l.PB( toAdd );
	}
	else{
		layer = findLayer( l, 0, lsize-1, a );
		l[ layer ].PB( a );
	}
}

int main(){
	
	string s;
	int t;
	int n;
	int x;
	int cnt;

	VPI a;
	VPI a2;
	vector< VPI > l;
	vector< VPI > l2;

	cin >> t;

	while( t-- ){
		cin >>n;

		a = VPI( n );
		a2 = VPI( n );
		cnt = 0;

		FOR( i, 0, n ){
			cin >> x;
			a[ x-1 ].first = i+1;
		}
		FOR( i, 0, n ){
			cin >> x;
			a[ x-1 ].second = i+1;
		}

		FOR( i, 0, n ) a[ i ].third = i+1;
		FOR( i, 0, n ) a2[ i ] = a[ i ];
		FOR( i, 0, n ) swap( a2[ i ].first, a2[ i ].second );

		sort( a.begin(), a.end(), cmp );
		sort( a2.begin(), a2.end(), cmp );


		l = vector< VPI >( 1 );
		l[ 0 ].PB( a[ 0 ] ); 

		l2 = vector< VPI >( 1 );
		l2[ 0 ].PB( a2[ 0 ] ); 

		FOR( i, 1, n ){

			add( a[ i ], l );
		}
		FOR( i, 1, n ){
			add( a2[ i ], l2 );
		}
		CERR << l.size() << " " << l2.size() << endl;
		if( l.size() <= l2.size() ){

			cout << l.size() << endl;
			for( auto i : l ){
				cout << i.size() ;
				for( auto x : i ){
					cout << " " << x.third;
				}
				cout << endl;

			}
		}
		else{
			cout << l2.size() << endl;
			for( auto i : l2 ){
				cout << i.size() ;
				for( auto x : i ){
					cout << " " << x.third;
				}
				cout << endl;

			}	
		}


	}

	
	return 0 ;
}


/*


2
6 
1 2 3 4 5 6
2 3 6 1 4 5
5
3 4 1 5 2
4 5 3 2 1
*/
