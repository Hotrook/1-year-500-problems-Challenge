#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set> 
#include <string>
#include <algorithm>
#include <iomanip>    


#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
#define VI vector<int>


using namespace std;



int main(){

	int t;

	double a;
	double b;
	double x;
	double side;
	double side2;
	double h;
	double result;

	cin >> t;

	while( t-- ){
		cin >> a >> b; 

		if( b < a ) swap( a, b );

		side = ( a + b ) / 2.0 ;
		side2 = ( b - a ) / 2.0 ;

		h = sqrt( side * side - side2 * side2 ); 

		result = ( a + b ) * h / 2.0;

		cout <<  fixed << setprecision(2) << result << endl;
		
	}
	return 0 ;
}
