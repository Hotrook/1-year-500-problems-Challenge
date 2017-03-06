#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string a;
    string b;
    
    cin >> a;
    cin >> b;
    
    vector< int > tab[ b.size()+1 ];
    
    for( int i = 0 ; i < b.size()+1 ; ++i ){
        tab[ i ] = vector< int >( a.size()+1 );
    }
    
    for( int i = 1 ; i <= b.size() ; ++i ){
        for( int j = 1 ; j <= a.size() ; ++j ){
            if( b[ i-1 ] == a[ j-1 ] ){
                tab[ i ][ j ] = tab[ i - 1 ][ j -1 ] + 1; 
            }
            else{
                tab[ i ][ j ] = max( tab[ i - 1 ][ j ], tab[ i ][ j - 1 ]);
            }
        }
    }
    
    cout << tab[ b.size() ][ a.size() ] << endl;
    return 0;
}
