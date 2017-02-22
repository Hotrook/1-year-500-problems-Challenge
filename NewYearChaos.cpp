#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int numOfTestCase;
    int n;
    int x;
    bool cond = false;
    
    vector< int > array; 
    vector< int > positions;
    
    cin >> numOfTestCase;
    
    while( numOfTestCase-- ){
        cin >> n;
        array = vector< int >();
        positions = vector< int >( n+1 );
        
        cond = false;
        for( int i = 0 ; i < n ; ++i ){
            cin >> x;
            positions[ x ] = array.size();
            array.push_back(x);
        }
        for( int i = 0 ; i < n ; ++i ){
            if( array[ i ] - i > 3 ){
                cond = true;
            }
        }
        
        if( cond ){
            cout << "Too chaotic" << endl;
        }
        else{
            int swaps = 0 ;
            for( int i = n ; i > 0 ; --i ){
                int j = positions[ i ];
                while( array[ j ] > array[ j + 1 ] and j + 1 < n ){
                    swap( array[ j ], array[ j + 1 ] );
                    positions[ array[ j ] ] = j;
                    positions[ array[ j+1 ] ] = j+1;
                    swaps++;
                    j++;
                }
            }
            cout << swaps << endl;
        }
    }
    return 0;
}
