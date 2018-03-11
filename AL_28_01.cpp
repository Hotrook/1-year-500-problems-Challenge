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
	
	string s;
	int t;

	cin >> t;
	cin >> s;

	for( int i = s.length()/2 ; i >= 0 ; i-- ) {

		for( int k = 0 ; k < s.length() ; ++k ){

			if( k < i or s.length() - 1 - k < i ){
				cout << "." ;
			}
			else{
				cout << s[ k ];
			}
		}
		cout << endl;

	}


	return 0 ;
}
