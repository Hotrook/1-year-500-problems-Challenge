#include <iostream>
#include <cmath>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )

using namespace std;

int PHI( int n );

int main(){
	
	int t, n, k, a, b;

	ios_base::sync_with_stdio( false );

	cin >> t;

	FOR( i , 0 , t ){
		cin >> n ;
		cout << PHI( n ) << endl;
	}
	return 0 ;
}
//*****************************************************************************
int PHI( int n ){
	if( n == 1 )
		return 0;

	int dzielnik = 2, potega = 1, i = 3, s = sqrt( n );
	
	if( n % 2 != 0 ){
		dzielnik = -1; 
		while( i <= s and dzielnik == -1 ){
			if( n % i == 0 )
				dzielnik = i;
			i++;
		}
	}

	if (dzielnik == -1 ){
		return n-1 ;
	}

	int temp = dzielnik ;
	while( n % (dzielnik * temp) == 0){
		dzielnik *= temp;
		potega ++;
	}

	if( dzielnik == n )
		return (temp-1)*(n/temp);
	
	return PHI( dzielnik ) * PHI( n/dzielnik );
}
//*****************************************************************************