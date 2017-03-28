#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int k;
    
    cin >> n >> k ;
    
    vector< int > input( n+1 );
    vector< int > p( n+1 ); //positions
    
    for( int i = 1 ; i <= n ; ++i) {
        cin >> input[ i ];
        p[ input[ i ] ] = i ;
    }
    
    for( int i = 1; i <= n ; ++i ){
        if( k > 0 ){
            if( input[ i ] != n+1-i ){
                swap( input[ i ], input[ p[ n+1-i ] ] );
                p[ input[ p[n + 1 - i ]] ] = p[n + 1 - i ];
                p[ input[ i ] ] = i;
                --k;
            }
        }
        else{
            i = n+1;
        }
    }
    
    for ( int i = 1 ; i <= n ; ++i ){
        cout << input[ i ] << " ";
    }
    cout << "\n";
    return 0;
}
