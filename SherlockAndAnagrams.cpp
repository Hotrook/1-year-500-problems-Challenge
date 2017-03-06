#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check( string &s , int first , int second , int i ){
    
    vector< int > a( 26 );
    vector< int > b( 26 );
    
    for( int k = first ; k < first+i ; ++k ){
        a[ int( s[ k ] ) - 97 ]++;
    }
    
    for( int k = second ; k < second+i ; ++k ){
        b[ int( s[ k ] ) - 97 ]++;
    }
    
    
    bool cond = true;
    
    for( int k = 0 ; k < 26 ; k++ ){
        if( a[ k ] != b[ k ] ) cond = false;
    }
    
    return cond;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    int t; 
    int cnt;
    string s;
    
    cin >> t;
    
    
    while( t-- ){
        cin >> s;
        cnt = 0 ;
        
        for( int i = 1 ; i < s.length() ; ++i ){
            for( int j = 0 ; j < s.length() - i ; j++ ){
                for( int k = j + 1 ; k <= s.length() - i ; k++ ){
                    if( check( s, j, k, i ) ) cnt++;
                }
            }
        }
        
        cout << cnt << endl;
    }
    return 0;
}
