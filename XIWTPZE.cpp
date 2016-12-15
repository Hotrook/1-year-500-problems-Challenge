#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
typedef unsigned long long int ulint;

using namespace std;

int main(){
	
	ulint t;
	ulint a;
	ulint b;


	ios_base::sync_with_stdio( false );


	scanf("%lld",&t);	
	FOR( i , 0 , t ){
		scanf("%lld %lld",&a,&b);	
		if( a == 1 or a == 2 ) printf("NIE\n");
		else if( (a == 0 or a <= (pow( 3, b )-3)/2)  )printf("TAK\n");
		else printf("NIE\n");
	}


	return 0 ;
}
