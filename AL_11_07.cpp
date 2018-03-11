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
	bool cond = false;
	vector< char > help ;

	while( getline( cin , s ) ){

		int len = s.length()%2 == 0 ? s.length() : s.length() - 1 ;
		int it = 0 ;

		while( it < len ){
			cout << s[ it+1 ] << s[ it ];
			it += 2;

		}

		if( s.length() % 2 == 1 ){
			cout << s[ it ];
		}

		cout << "\n";
	}

	
	return 0 ;
}

