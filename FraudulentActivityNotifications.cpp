#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define FOR( i , a , b ) for( int i = a ; i < b ; ++i  )
#define PI pair< int , int >
#define VI vector< int  >
#define VPI vector< pair< int, int>  >
#define mp make_pair
#define MSET multiset< PI, classcomp >

bool cmp( PI a, PI b ) { return a.first <  b.first; }
struct classcomp{
    bool operator()( const PI & a , const PI & b ) const{
        return a.first < b.first;
    }
};

double getMedian( multiset< PI, classcomp > & h1, multiset< PI, classcomp > & h2, int k){
    if( k % 2 == 1 ){
        auto result = h2.begin();
        return double( (*result).first );
    }
    else{
        auto result1 = h1.end();
        auto result2 = h2.begin();
        result1--;
        return ( double( (*result1).first ) + double( (*result2).first ))/2.0;
    }
}


void sort( MSET& h1, MSET& h2, VI& t, PI a, int k){
    int toFind = a.second - k ;
    int value = t[ toFind ];
    int helper = 0;
    PI x = mp( value, toFind );

    
    auto it = h1.find( x );
    if( it != h1.end() ){
        h1.erase( it );
        helper = 0;
    }
    else{
        it = h2.find( x );
        h2.erase( it );
        helper = 1;
    }

    auto h1Top = h1.end();
    auto h2Bottom = h2.begin();
    h1Top--;

    // cout << (*h1Top).first << " " << (*h2Bottom).first << endl;
    if( a.first <= (*h1Top).first ){
        if( helper == 1 ){
            h2.insert( *h1Top);
            h1.erase( h1Top );
        }
        h1.insert( a );
    }
    else if( a.first >= (*h2Bottom).first ){
        if( helper == 0 ){
            h1.insert( *h2Bottom );
            h2.erase( h2Bottom );
        }
        h2.insert( a );
    }
    else{
        if( helper == 0 ){
            h1.insert( a );
        }
        else{
            h2.insert( a );
        }
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n ;
    int k ;
    int cnt = 0;
    int lastPos;
    int last = 0;
    
    cin >> n >> k;
    
    vector< int > t( n );
    vector< pair< int , int > > h;

    multiset< PI, classcomp> h1;
    multiset< PI, classcomp> h2;



    FOR( i, 0, n ){
        cin >> t[ i ] ;
    }
    
   
    
    FOR( i, 0, k ){
        h.push_back(make_pair( t[ i ], i ));
    }
    
    

    sort( h.begin() , h.end(), cmp );
    


    FOR( i, 0, h.size() ){
        if( i < h.size()/2 )
            h1.insert( h[ i ] );
        else
            h2.insert( h[ i ] );
    }
    
    


    FOR( i, k, t.size() ){

        double median = getMedian( h1, h2, k);
        
        if( double( t[ i ] ) >= 2.0*median ) cnt++;

        sort( h1, h2, t, mp( t[ i ], i ), k );
    }


    
    cout << cnt << endl;
    


    return 0;
}
