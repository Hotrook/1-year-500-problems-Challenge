#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR( i, a, b ) for( int i = a ; i < b ; i++ )
#define PII pair< int, int >

void make( vector< PII > & in, int size ){
    FOR( i, 0, size ){
        in[ i ].first  = i;
        in[ i ].second = 1;
    }
}


int find( vector< PII > & in , int toFind ){
    if( in[ toFind ].first == toFind ) return toFind;
    else return in[ toFind ].first = find( in, in[ toFind ].first );
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n; 
    int m;
    int a;
    int b;
    long long result = 0;
    
    cin >> n >> m ;
    
    vector< PII > in( n );
    vector< int > help ( n, 0 );
    
    make( in, n );
    
    FOR( i, 0, m ){
        cin >> a >> b;
        int fa = find( in, a );
        int fb = find( in, b );
    
        if( fa != fb ){
            in[ fa ].second += in[ fb ].second;
            in[ fb ].first = fa;
        }
    }
    
    FOR( i, 0, n ){
        int fa = find( in, i );
        if( help[ fa ] == 0 ){
            result += in[ fa ].second * ( n - in[ fa ].second );
            help[ fa ] = 1;
        }
    }
    
    cout << result/2 << endl;
    
    return 0;
}
