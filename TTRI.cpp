#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )
typedef unsigned long long  ulint;

using namespace std;

ulint NWD(ulint a, ulint b){
	if( b == 0 ){
		return a;
	}
	else{
		if( a < b )swap(a,b);
		return NWD( b, a%b );
	}
}

ulint NWW(ulint a, ulint b){
	return a*(b/NWD(a,b));
}



int main(){
	
	ulint a,b,c,d,e,f,t;
	ulint a1,a2,a3,x;
	char w;

	scanf("%lld",&t);
	FOR(i,0,t){
		scanf("%lld%/%lld %lld/%lld %lld/%lld",&a,&b,&c,&d,&e,&f);
		x=NWD(a,b);
		a /= x;
		b /= x;
		x = NWD(c,d);
		c /= x;
		d /= x;
		x = NWD(e,f);
		e /= x;
		f /= x;
		x = NWW(b,NWW(d,f));
		a1 = a*(x/b);
		a2 = c*(x/d);
		a3 = e*(x/f);
		if( a1 > a2)
			swap( a1,a2 );
		if( a1 > a3) 
			swap( a1,a3 );
		if( a2 > a3)
			swap( a2, a3 );

		if( a1 > a3 - a2 )
			printf("TAK\n");
		else
			printf("NIE\n");


	}


	return 0 ;
}