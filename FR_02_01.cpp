#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


double measure( int a, int b, int c, int d ){

	return hypot(  a - c , b - d);

}

double h( double a, double b, double c, double d, double e, double f ){

	// cout << a << " " << b << " " << c  << " "  << d << " " << e << " " << f << endl;
	double result;

	if( c == a ) {
		swap( c, e );
		swap( d, f );
	}

	double a1 = ( d - b ) / ( c - a );
	double a2 = b - a1 * a;

	// cout << a1 << " " << a2 << endl;




	double temp = measure( a, b, c, d );


	result = abs( a1 * e + (-1) * f + a2  )/ sqrt( a1 * a1 + 1);

	return 0.5 * result * temp;
}

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
	double xa;
	double ya;
	double xb;
	double yb;
	double xc;
	double yc;
	

	cin >> xa >> ya >> xb >> yb >> xc >> yc ;

	double a = measure( xa, ya, xb, yb );
	double b = measure( xc, yc, xb, yb );
	double c = measure( xc, yc, xa, ya );

	double up = a * b * c;

	if( c >= a and c >= b  ){
		swap( xc, xb );
		swap( yc, yb );
	}
	
	double P = h( xa, ya, xb, yb, xc, yc );

	double result = up / ( 4 * P );

	cout << fixed << setprecision( 2 ) << result << endl;
    return 0;
}
