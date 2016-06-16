#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <map>



#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
using namespace std;
typedef pair< int, int > element;
typedef unsigned long long int ulint;


bool comparator( pair<string,int> a, pair<string,int> b){
	if( a.second == b.second ) return a.first < b.first ;
	else return a.second > b.second;
}


int main(){
	
	int n;
	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	string y;
	string imie;


	map < string , int > myMap;

	ios_base::sync_with_stdio( false );



	while(true){
		cin >> y;
		if( cin.eof() ) break;
		cin >> y >> imie ;

		transform( imie.begin(), imie.end(), imie.begin(), ::toupper );

		myMap[imie]++;

	}
	vector< pair<string,int> > result;

	pair<string, int > temp;
	for( auto & i : myMap ){
		temp.first = i.first;
		temp.second = i.second;
		result.PB( temp );
	}
	
	sort( result.begin(), result.end(), comparator );

	for( auto & i : result ){
		cout << i.first << ' ' << i.second << "\n";
	}

	return 0 ;
}
