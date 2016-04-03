#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;



int main(){
	
	unsigned long long int t;
	unsigned long long int n;
	unsigned long long int m;
	unsigned long long int k; 
	unsigned long long int tab[ 3 ];
	unsigned long long int result ;
	char c;

	cin >> t;

	FOR( i, 0 , t ){
		cin >> n >> m ;
		if( ( n == 1 and m != 2 ) or ( m == 1 and n != 2 ))
			cout << "No" << endl;
		else if( n%2 == 0 or m%2 == 0 ){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}



	return 0 ;
}