#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool myfunc( pair<int, int > a, pair<int ,int> b ){
	return a.first < b.first;
}

bool myfunc2( pair<int, int > a, pair<int ,int> b ){
	return a.first > b.first;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    int x;
    pair< int ,  int > shit;
    int checked[ 100007 ];
    
    vector< int > arr;
    vector< pair<int,int> > help ;
    
    cin >> n ;
    for( int i = 0  ; i < n ; ++i ){
        cin >> x;
        shit.first = x;
        shit.second = i;
        arr.push_back( x );
        help.push_back( shit );
    }
    
    sort( help.begin() , help.end() , myfunc );
    int sum = 0 ;


    for( int i = 0 ; i < arr.size() ; ++i ){
        if( checked[ i ] != 1 ){

        	int length = 0; 
        	int start = arr[ i ] ;
        	int next = 0;
        	int nextPos = i;

        	if( arr[ i ] != help[ i ].first ){
        		checked[ i ] = 1;
        		next = help[ i ].first ;
        		nextPos = help[ i ].second;
        		checked[ nextPos ] = 1;
        		while( next != start ){
        			length++;
        			next = help[ nextPos ].first;
        			nextPos = help[ nextPos ].second;
        			checked[ nextPos ] = 1;
        		}
        		sum += length;
        	}

        }

    }

for( int i = 0 ; i <= n ; ++i )checked[ i ] = 0;

    reverse( arr.begin(), arr.end() );
    for( int i = 0 ; i < arr.size() ; ++i ){
    	help[ i ].first = arr[ i ];
    	help[ i ].second = i ;
    }
    sort( help.begin(), help.end() , myfunc );
    int sum2 = 0 ;


    for( int i = 0 ; i < arr.size() ; ++i ){
        if( checked[ i ] != 1 ){
        	int length = 0; 
        	int start = arr[ i ] ;
        	int next = 0;
        	int nextPos = i;

        	if( arr[ i ] != help[ i ].first ){
        		checked[ i ] = 1;
        		next = help[ i ].first ;
        		nextPos = help[ i ].second;
        		checked[ nextPos ] = 1;
        		while( next != start ){
        			length++;
        			next = help[ nextPos ].first;
        			nextPos = help[ nextPos ].second;
        			checked[ nextPos ] = 1;
        		}
        		sum2 += length;
        	}

        }

    }



    cout << min( sum ,sum2) << endl;
    return 0;
}
