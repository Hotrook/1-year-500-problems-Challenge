#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define DOWN( i, a, b ) for( int i = a; i >= b ; i-- )
#define VI vector< int >
using namespace std;

int findTheSmallestBetweenAllCrucial(VI& crucial, VI& now, VI& a, vector< VI >& p ){
    int result;
    FOR( i, 0 , 26){
        if( a[ i ] > 0 ){
            bool cond = true;
            FOR( j, 0, 26 ){
                if( a[ j ] != 0 )
                if( !( p[ i ][ now[ i ] ] <= p[ j ][ crucial[ j ]] ) ) cond = false;
            }
            if( cond  ){
                result = i;
                break;
            }
        }
    }
    a[ result ]--;
    if( a[ result ] > 0 )
        crucial[ result ]++;
    else
        crucial[ result ] = 10000;
    return p[ result ][ now[ result ] ];
}


void actcualizeNow(VI& now, vector< VI > & positions, VI & a, int smallest ){
    FOR( i, 0, 26 ){
        if( a[ i ] != 0 ){
            while( positions[ i ][ now[ i ] ] <= smallest ) now[ i ]++;
        }
    }    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string s;
    string result = "";
    int last = 0;
    
    cin >> s;
    
    vector< int > a( 26, 0 );
    vector< int > crucial( 26 );
    vector< int > now( 26, 0 );
    vector< vector< int > > positions( 26, vector< int > ()  );
    
    FOR( i, 0, s.length() ){
        a[ int(s[ i ]) - 97 ]++;
    }
    
    reverse( s.begin(), s.end() );
    
    FOR( i, 0, s.length() ){
        int tmp = int( s[ i ] ) - 97;
        positions[ tmp ].push_back( i );
    }
    
    DOWN( i, 25, 0 ){
        a[ i ] /= 2;
        crucial[ i ] = a[ i ];
    }
    
    FOR( i, 0, s.length()/2){
        int smallest = findTheSmallestBetweenAllCrucial( crucial, now, a, positions );
        result += s[ smallest ];
        actcualizeNow( now, positions, a, smallest);
    }
    

    
    
    cout << result << "\n";
    
    return 0;
}
