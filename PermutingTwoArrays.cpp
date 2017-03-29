#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;
    int n;
    int k;
    bool result;
    
    auto cmp = [](int a, int b ){
        return a > b ;
    };
    vector< int > a;
    vector< int > b;
    
    cin >> t;
    while( t-- ){
        cin >> n >> k;
        
        a.clear();
        b.clear();
        result = true;
        
        a = vector< int >( n );
        b = vector< int >( n );
        
        for( int i = 0 ; i < n ; ++i ){
            cin >> a[ i ];
        }
        for( int i = 0 ; i < n ; ++i ){
            cin >> b[ i ];
        }
        sort( a.begin(), a.end() );
        sort( b.begin(), b.end(), cmp );
        
        for( int i = 0 ; i < n ; ++i ){
            if( a[ i ] + b[ i ] < k ) result = false;
        }
        
        if( result ) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
