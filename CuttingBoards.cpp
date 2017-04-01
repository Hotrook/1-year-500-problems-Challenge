#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


#define VI vector< long long >
#define FOR( i , a, b ) for( long long i = a; i< b ;++i)
using namespace std;

long long const p = 1000000007;


long long checkSize( long long n, long long d ){
    if( d == 1 ) return n;
    long long temp = n / ( d - 1 );
    if( temp * ( d - 1 ) == n ) return temp -1;
    return temp;
}
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */   
    long long t;
    long long n; 
    long long m;

    VI h;
    VI v;

    auto cmp  = []( long long a, long long b){ return a > b ;} ;
    cin >> t;

    while( t-- ) {
    	cin >> m >> n ;

    	long long hcuts = 1;
    	long long vcuts = 1;
    	long long cost = 0;

    	h.clear();
    	v.clear();

    	h = VI( m-1 );
    	v = VI( n-1 );

    	FOR( i, 0, m-1 ) cin >> h[ i ];
    	FOR( i, 0, n-1 ) cin >> v[ i ];
    	sort( v.begin(), v.end(), cmp );

    	sort( h.begin(), h.end(), cmp );

    	long long ith = 0;
    	long long itv = 0;

    	while( itv < v.size() and ith < h.size()){
    		if( h[ ith ] * vcuts + v[ itv ] * (hcuts+1) < h[ ith ] * (vcuts + 1) + v[ itv ] * hcuts ){
    			cost = ( cost + (h[ ith ]* vcuts ) %p)%p;
    			++ith;
    			++hcuts;
    		}
    		else{
    			cost = ( cost + (v[ itv ]* hcuts ) %p)%p;
    			++itv;
    			++vcuts;
    		}
    	}

    	while( itv < v.size() ){
    		cost = (cost + (v[ itv ]*hcuts)%p)%p; 
    		++itv;
    	}
    	while( ith < h.size() ){
    		cost = (cost+  (h[ ith ]*vcuts)%p)%p;
    		++ith;
    	}
    	
    	cout << cost << endl;

    }

    return 0;
}