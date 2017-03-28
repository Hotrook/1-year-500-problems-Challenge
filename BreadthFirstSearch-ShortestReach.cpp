#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define VI vector< int >

void bfs( int start, VI & d, vector< VI > & e ){
    queue< int > que;
    
    vector< int > v( d.size(), 0 );
    v[ start ] = 1;
    d[ start ] = 0;
    que.push( start );
    
    while( !que.empty() ){
        int tmp = que.front();
        que.pop();
        for( auto i : e[ tmp ] ){
            if( v[ i ] == 0 ){
                d[ i ] = d[ tmp ] + 6;  
                que.push( i );
                v[ i ] = 1;
            }
        }
    }
} 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;
    int n;
    int m;
    int a, b;
    
    ios_base::sync_with_stdio(false);
    VI d;
    vector< VI > e;
    
    cin >> t;
    
    while( t-- ){
        cin >> n >> m;
        
        e.clear();d.clear();
        e = vector< VI >( n+1, VI() );
        d = VI( n+1, -1 );
        
        for( int i = 0 ; i < m ; ++i ){
            cin >> a >> b;
            e[ a ].push_back( b );
            e[ b ].push_back( a );
        }
        
        cin >> a;
        
        bfs( a, d, e );
        for( int i = 1 ; i <= n ; ++i ){
            if( i != a ) cout <<d[ i ] << " ";
        }
        
        cout << endl;
    }
    return 0;
}
