#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )

const unsigned long long int  M = 1000000007LL;

using namespace std;

unsigned long long int pmod(unsigned long long int n, unsigned long long int k ){
	
	unsigned long long int x = n;
	unsigned long long int result = 1;
	while( k > 0 ){
		if( k & 1){
			result = (x*result) % M;
		}
		x = (x*x)%M;
		k>>=1;
	}
	return result;
}



int main(){
	
	int t;
	unsigned long long int  n;
	unsigned long long int  k; 
	unsigned long long int  result ;
	char c;

	cin >> t;

	FOR( i, 0 , t ){
		cin >> n  >> k;
		if( n == 1)
			result = k;
		else
			result = k*pmod(k-1,n-1);
		result %= M;
		cout <<  result << endl;
		
	}



	return 0 ;
}