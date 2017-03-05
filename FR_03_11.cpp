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
	int temp;


	string s;

	cin >> t;

	while( t-- ){
		cin >> s;

		temp = 0 ;

		for( auto i :  s ){
			temp = (temp * 2 + int( i ) - 48 )%10;
		}
		if( temp == 0 ) cout << "Tak\n" ;
		else cout << "Nie\n";
		
	}
	return 0 ;
}
