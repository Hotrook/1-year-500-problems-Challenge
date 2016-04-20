#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )

using namespace std;


int result[3];

int main(){
	
	int t;
	int n;
	int k; 
	int a, b, c;

	cin >> t;

	result[ 0 ] = 0;
	result[ 1 ] = 0 ;
	result[ 2 ] = 0;


	FOR( i, 0 , t ){
		cin >> a >> b >> c;

		a = a + min(result[ 1 ],result[ 2 ]);
		b = b + min(result[ 0 ],result[ 2 ]);
		c = c + min(result[ 0 ],result[ 1 ]);
		result[ 0 ] = a;
		result[ 1 ] = b;
		result[ 2 ] = c; 

	}
	cout << min(result[ 0 ], min( result[ 1 ], result[ 2 ])) << endl;




	return 0 ;
}