#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )
#define PB push_back

using namespace std;

string pattern;

vector <string> tab;
bool comparator( string a, string b );
void qsort(int start,int stop );
int partition(int start, int stop);

int main(){
	
	long long  t;
	long long  n;
	string temp;
	char c;

	ios_base::sync_with_stdio(false);
	
	cin >> t;

	FOR( i , 0 , t ){

		cin >> pattern;

		cin >> n ;

		tab.resize( n + 100 );

		FOR( j, 0, n ){
			cin >> tab[ j ];
		}
		
		cin.get( c );
		cin.get( c );


		//sort( tab.begin(), tab.end() , comparator);
		qsort(0,n-1);

		FOR( j , 0 , n ){
			cout << tab[ j ] << endl;
		}
		cout << endl;
		//tab.clear();
	}

	return 0 ;
}


int partition(int start, int stop){
	string pivot = tab[ start ];
	int p = start;

	FOR( i , start + 1, stop + 1 ){
		if( comparator( tab[ i ], pivot) ){
			p++;
			swap( tab[ i ], tab[ p ] );
		}
	}

	swap( tab[ p ], tab[ start ]);

	return p;
}


void qsort( int start, int stop ){

	if( start >= stop ) return;

	int r = partition( start, stop );
	qsort( start, r-1 );
	qsort( r+1, stop );
}

 

bool comparator( string a, string b ){
	int asize = a.length();
	int bsize = b.length();

	int iterator = 0 ; 

	if( a == b )
		return true;

	while ( iterator <= asize and iterator <= bsize ){
		if( iterator == asize ){
			return true;
		}
		else if( iterator == bsize ){
			return false;
		}
		else{
			int i = 0 ;
			while( i < pattern.size() ){
				if( pattern[ i ] == a[ iterator ] and pattern[ i ] != b[ iterator ] )
					return true;
				else if ( pattern [ i ] == b[ iterator ] and pattern [ i ] != a[ iterator ] )
					return false;
				i++;
			}
		}

		iterator++;
	}
	return true;
}
