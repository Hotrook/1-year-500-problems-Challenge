#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )


using namespace std;

long long NWD( long long a, long long b ){
	if( b > a ) swap ( a, b );

	if( b == 0 )
		return a;

	return NWD( a%b, b );
}

long long NWW( long long a, long long b ){
	return (a/NWD( a, b ))*b;
}
pair < long long , long long > input[ 1000001 ];

int main(){
	

	long long t;
	long long n;
	long long start;
	long long a;
	long long b;
	long long bprev;
	long long temp;
	long long mult; // multiplication;


	ios_base::sync_with_stdio(false);
	
	cin >> t;
	FOR( i , 0 , t){
		cin >> n;
		FOR( i, 0 , n ){
			if( i == 0 ){
				cin >> start >> bprev;
				temp = NWD( start, bprev );
				start /= temp;
				bprev /= temp;
			}
			else{
				cin >> a >> b;
				temp = NWD( a, b );
				a /= temp;
				b /= temp;
				if( bprev % a != 0 ){
					mult = NWW( bprev , a ) / bprev;
					bprev *= mult;
					start *= mult;
				}
				bprev /= a;
				bprev *= b;
			}
		}
		temp = NWD( start, bprev );
		cout << start/temp << " " << bprev/temp << endl;
	}
	return 0 ;
}