#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set> 
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
#define VI vector<int>


using namespace std;



int main(){

	int t;
	int a;
	string s;

	cin >> s;
	cin >> t;

	while( t-- ){
		cin >> a;

		string temp = "";

		FOR( i , 0 , abs( a )-1 ) temp += ' ';

		if( a == 0 ){
			cout << s[ s.length() - 1 ] ;
		}
		else if( a < 0 ){
			for( int i = s.length() - 1 ; i >=0 ; --i ){
				cout << s[ i ] ;
				if( i != 0 ) cout << temp ;
			}
		}
		else{
			FOR( i , 0 , s.length() ){
				cout << s[ i ] ;
				if( i != ( s.length() - 1) ) cout << temp ;
			}
		}

		if( t != 0 ) cout << endl;
	}

	return 0 ;
}
