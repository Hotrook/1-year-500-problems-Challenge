#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set> 
#include <map> 
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

	map < string , int > index;

	index[ "Pn" ] = 0;
	index[ "Wt" ] = 1;
	index[ "Sr" ] = 2;
	index[ "Cz" ] = 3;
	index[ "Pt" ] = 4;
	index[ "So" ] = 5;
	index[ "Nd" ] = 6;


	string tab[ 7 ] = {  "Pn", "Wt", "Sr", "Cz", "Pt", "So", "Nd" };
	string s;

	ios_base::sync_with_stdio( 0 );
	cin >> t;

	while( t-- ){
		cin >> s >> a ;

		cout << tab[ (index[ s ] + a )%7 ] << endl;

	}
	return 0 ;
}
