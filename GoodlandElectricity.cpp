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
    int last = -1;
    int next = 0;
    int result = 0;
    bool possible = true;
    
    cin >> n >> k ;
    
    last = -k;
    
    vector< int > input( n );
    vector< int > ones;

    
    for ( int i = 0 ; i < n ; ++i ){
        cin >> input[ i ]; 
        if( input[ i ] == 1 ) ones.push_back( i );
    }
    
    for( int i = 0; i < n; ++i ){
        if( input[ i ] == 0 ){
            if( abs( i - last ) >= k and abs( i - ones[ next ] ) >= k ){
                possible = false;
            }
        }
        else{
            if( next == ones.size() - 1 ){
                if( last + k - 1 >= n-1 ) result++;
                else last = i;
            }
            else{
                next++;
                int firstScope = last + k - 1;
                int nextScope = ones[ next ] - k +1;
                
                if( firstScope >= nextScope - 1 ){
                    result++;
                }
                else 
                    last = i;
            }
        }
     }
    
    if( possible ) cout << ones.size() - result << "\n";
    else cout << "-1\n";
    return 0;
}
