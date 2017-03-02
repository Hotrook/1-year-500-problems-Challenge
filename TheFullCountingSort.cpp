#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector< int > counts( 107 );
    vector< pair<int, string> > input;
    vector< string > output;
    int n;
    int x;
    string s;
    
    cin >> n;
    output = vector<string>(n+1);
    
    for( int i = 0 ; i < n ; ++i ){
        cin >> x >> s;
        if( i < n/2 ) s = "-";
        input.push_back( make_pair( x, s ) );
        counts[ x ]++;
    }
    
    for( int i = 1 ; i <= 100; ++i ) 
        counts[ i ] += counts[ i - 1 ];
    
    for( int i = n-1 ; i >= 0 ; --i ){
        output[ counts[input[ i ].first] ] = input[ i ].second;
        counts[input[ i ].first]--;
    }
    
    
    for( int i = 1; i <= n ; ++i ){
        cout << output[ i ] << " ";
    }
    cout << "\n";
    
    return 0;
}
