#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
using namespace std;


typedef unsigned long long int uint64_t;

const uint64_t mod = 1000000007LL;


bool comparator( string a, string b ){ 
	int it = 0 ;
	while ( it < a.length() and it < b.length() ){
		if( a[ it ] < b[ it ] ) return true;
		if( b[ it ] < a[ it ] ) return false;
		it++;
	}
	if( it == a.length() and b.length() > a.length() ) return true;
	return false;

}

int main(){
	
	int n;
	int m;
	int k;
	
	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	string temp;

	ios_base::sync_with_stdio( false );
	vector< string > result;
	result.clear();


	while( true ){
		cin >> temp;
		if( cin.eof() )break;
		result.PB( temp );
	}
	sort( result.begin(),result.end() , comparator );

	for( vector<string>::iterator it = result.begin() ; it != result.end() ; ++it ){
		cout << (*it) << "\n";
	}

	return 0 ;
}
