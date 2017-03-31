#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int sum;
    int max = 0;
    int result = 0;
    
    
    cin >> n;
    
    vector< int > in(n);
    
    for( int i = 0 ; i < n ; ++i ){
        cin >> in[ i ];
    }
    
    for( int i = n-1 ; i >= 0 ; --i ){
        result = ( result  + in[ i ] + 1 )/2;    
    }
    
    cout << result << endl;
    return 0;
}
