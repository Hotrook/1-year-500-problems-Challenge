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
	int b;

	ios_base::sync_with_stdio( 0 );
	cin >> t;

	while( t-- ){
		cin >> a >> b; 

		if( a % 2 == 1 ){
			cout << "BRAK\n";
		}
		else{
			if( b + a/2 >  a )
				cout << ( b + a / 2 ) % ( a ) << endl;
			else
				cout << ( b + a / 2 ) << endl;
		}
	}
	return 0 ;
}
