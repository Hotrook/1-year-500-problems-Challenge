#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

typedef unsigned long long int uint64_t;

const uint64_t mod = 1000000007LL;


using namespace std;

vector<uint64_t> tab;

uint64_t** allocate ( uint64_t** temp ){
	temp = new uint64_t*[2];
	temp[ 0 ] = new uint64_t[2];
	temp[ 1 ] = new uint64_t[2];
	return temp;
}

uint64_t** multiply( uint64_t **tab1, uint64_t** tab2 ){
	uint64_t** temp;

	temp = allocate( temp );

	temp[ 0 ][ 0 ] = (((tab1[0][0]%mod)*(tab2[0][0]%mod))%mod+((tab1[0][1]%mod)*(tab2[1][0]%mod))%mod)%mod;
	temp[ 0 ][ 1 ] = (((tab1[0][0]%mod)*(tab2[0][1]%mod))%mod+((tab1[0][1]%mod)*(tab2[1][1]%mod))%mod)%mod;
	temp[ 1 ][ 1 ] = (((tab1[1][0]%mod)*(tab2[0][1]%mod))%mod+((tab1[1][1]%mod)*(tab2[1][1]%mod))%mod)%mod;
	temp[ 1 ][ 0 ] = (((tab1[1][0]%mod)*(tab2[0][0]%mod))%mod+((tab1[1][1]%mod)*(tab2[1][0]%mod))%mod)%mod;

	return temp;
}


uint64_t** powMatrix( uint64_t** tab, uint64_t n ){
	if( n == 1) return tab;

	if( n%2 == 0 ){
		uint64_t** temp;
		temp = powMatrix( tab, n/2 );
		return multiply( temp , temp );
	}
	else{
		uint64_t ** temp;
		temp = powMatrix(tab, n/2 );
		return multiply(multiply(temp,temp),tab);
	}
}


int main(){
	
	uint64_t n;
	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	uint64_t **tab;
	tab = allocate( tab );

	ios_base::sync_with_stdio( false );


	cin >> t;


	FOR( i , 0 , t ){

		tab[0][0] = 1;
		tab[0][1] = 1;
		tab[1][0] = 1;
		tab[1][1] = 0;
 
		cin >> n;

		tab = powMatrix( tab, n-1 );

		uint64_t temp = (( tab[1][0] % mod ) + ( tab[ 1 ][ 1 ] % mod )) % mod;

		cout << temp << endl;

	}


	return 0 ;
}
