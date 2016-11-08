#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define VI vector< int > 
#define push_back PB ;
#define FOR( i , a, b ) for( int i = a; i < b ; ++i )

using namespace std;

int partition( VI & vec , int l , int r ){
	if( l >= r ) return -1;
	int i = l;
	int elem = vec[ i ];
	FOR( j , l , r+1 ){
		if( vec[ j ] < elem ){
			i++; 
			swap( vec[ i ], vec[ j ] );
		}
	}
	swap( vec[ i ], vec[ l ] );
	return i ;
}

int findTheMedian( VI & vec , int pos , int l , int r ){
	cout << l << " " << r << endl;
	cout << " " << pos << endl;
	getchar();
	int part = partition ( vec, l, r );
	if( part == pos ) return vec[ part ];
	else if( pos > part ) return findTheMedian( vec, pos , part+1, r);
	else return findTheMedian( vec, pos , l , part+1 );
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin >> n;
    vector< int > arr ( n );

    FOR( i , 0 , n )
    cin >> arr[ i ];

    cout << ( n-1 ) /2 << endl;
    cout << findTheMedian( arr, (n-1)/2 , 0, n-1 ) << endl;
    return 0;
}
