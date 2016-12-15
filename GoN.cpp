#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string check( int l , int r , int k ){
    if( k > 0  and k <= r ) return "Alice";
    else if( k <= 0 ) return "Bob";
    else return check( l, r , k - r - l);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n ;
    int l ;
    int r ;
    int k ;
    
    cin >> n;
    for( int i = 0 ; i < n ; ++i ){
        cin >> l >> r >> k ;
        cout << check( l , r  , k ) << endl;
    }
    return 0;
}
