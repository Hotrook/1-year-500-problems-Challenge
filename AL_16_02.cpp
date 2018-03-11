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

	vector< char > help ;

	while( getline( cin , s ) ){
		


		int it = 0 ;
		int it2 = 0 ;
		help.clear();
		help = vector< char >();

		while( it < s.length() ){
			if( s[ it ] != ' ' )
				help.PB( s[ it ] );
			else
				break;

			it++;
		}

		it++;
		if( help.size() > 0 ) cout << help[ it2 ];
		it2++;

		while( it < s.length() ){

			if( s[it] == ' ' ){
				cout << ' ';
				if( it2 < help.size() )cout << help[ it2++ ];
			}
			else{
				cout << s[ it ];
			}

			it++;
		}

		cout  << "\n";
	}

	
	return 0 ;
}

// BBBB   EKA EKA EKA EKA