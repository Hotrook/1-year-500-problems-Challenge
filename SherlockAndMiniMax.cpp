#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    int n;
    int p;
    int q;
    int max = 0;
    int result;
    
    cin >> n;
    
    vector< int > in( n );
    
    for( int i = 0 ; i < n ; ++ i ){
        cin >> in[ i ];
    }
    
    cin >> p >> q;
    
    result = p;
    
    sort( in.begin(), in.end());
    
    if( p < in[ 0 ] ){
        if( in[ 0 ] - p > max ){
            max = in[ 0 ] - p ;
        }
    }
    if( q > in[ n-1 ] ){
        if( q - in[ n-1 ] > max ){
            max = q - in[ n-1 ] ;
            result = q;
        }
    }
    
    
    for ( int i = 0 ; i < n-1 ; ++i ){
        int middle = ( in [ i ]  + in[ i+1 ] )/2;
        
        if( middle < p and p <= in[ i + 1 ] ){
            int temp = in[ i + 1 ] - p;
            if( temp > max ){
                result = p;
                max = temp;
            }
        }
        else if( middle <= q and middle >= p ){
            int temp = middle - in [ i ];
            if( temp > max ){
                max = temp;
                result = middle;
            }
        }
        else if( q < middle and q >= in[ i ] ){
            int temp = q - in [ i ];
            if( temp > max ){
                result = q ;
                max = temp;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}
