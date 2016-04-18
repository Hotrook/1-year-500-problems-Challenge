#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

int tab[61];

int main(){
	
	int t;
	int n;
	int k; 
	int result;
	int sum = 0;
	int c;

	int a = 1;
	int b = 1;

	tab[ 0 ] = 1;
	tab[ 1 ] = 1;

	FOR( i ,3 , 61){
		c = (a + b)%10;
		a = b % 10;
		b = c;
		tab[ i - 1 ] = b;
	}

	scanf("%d",&t);

	FOR( i, 0 , t ){
		scanf("%d%d%d",&n,&a,&b);
		if( n == 1 ){
			printf("%d\n",a);
		}
		else if( n == 2 ){
			printf("%d\n",b);
		}
		else{
			result = (tab[ (n-3)%60 ] * (a%10) + tab[ (n-2)%60 ] *(b%10))%10 ;
			printf("%d\n",result);
		}
	}




	return 0 ;
}