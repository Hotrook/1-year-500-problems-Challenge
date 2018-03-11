#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>


using namespace std;
struct edge{
    int a;
    int b;
    int c;
};

bool comparator( edge a, edge b ){
    return a.c < b.c; 
}

int tab[ 3008 ];

void make( int n ){
    for( int i = 1 ; i <= n ; ++i ){
       tab[ i ] = i ;
    }
}

int find(int x ){
    if( x == tab[ x ] ) return x;
    else return x = find( tab[ x ] ) ;
}

void un( int x , int y ){
    int fx = find ( x );
    int fy = find ( y );
    
    tab[ fx ] = fy;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n; 
    int m ;
    
    vector< edge > edges;
    
    edge e;
    
    cin >> n >> m;
    
    for ( int i = 0 ; i < m ; ++i ){
        cin >> e.a >> e.b >> e.c;
        
        edges.push_back( e );       
    }
    
    sort( edges.begin(), edges.end() , comparator);
    
    int result = 0;
    int it = 0;
    int counter = 0;
    vector< int > visited( n+1 , 0 );
    
    make( n );
    
    while( counter < n-1 ){
        edge temp = edges[ it ];
        if( find( temp.a ) != find( temp.b ) ){
            result += temp.c;
            un( temp.a, temp.b );
            counter++;
        }
        it++;
    }
    
    cout << result << endl;
    return 0;
}
