#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void printArray( vector< long long >& result ){
    int size = result.size();
    for( int i = 1; i < size; ++i ){
        cout << result[ i ] ;
        if( i != size-1 )
            cout << " ";
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long t;
    long long n; 
    long long k; 
    long long b;
    long long sum = 0;
    
    cin >> t ;
    
    while( t-- ){
        
        cin >> n >> k >> b;
        sum = 0;
        
        vector< long long > result = vector<long long>( b+1 );
        for( int i = 1; i <= b ; ++i ){
            result[ i ] = i; 
            sum += result[ i ];
        }
        
        
        if( sum > n ){
            cout << -1 << endl;
        }
        else{
            int it = b;
            while( it > 0 ){

                long long tempSum = sum - result[ it ];
                long long max = k - (b - it);

                if( tempSum + max >= n){
                    result[ it ] = n - tempSum;
                    it = -1 ;
                    printArray( result );
                }
                else{
                    result[ it ] = max;
                    sum = tempSum + result[ it ];
                    it--;
                }
            }
            if( it == 0 ){
                cout << -1 << endl;
            }
        }
        
    }
    return 0;
}
