#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;


int tab[500001];
int main(){
	
	int t;
	int n;
	int val;
	int k; 
	int lider = 0 ;
	int result;
	int sum = 0;
	char c;

	scanf("%d",&t);

	FOR( i, 0 , t ){
		scanf("%d",&n);
		lider = 0 ;
		FOR( i , 0 , n ){
			scanf("%d",&tab[ i ]);
			
			if( lider == 0 ){
				lider = 1;
				val = tab[ i ];
			}
			else if( tab[ i ] == val ){
				lider++;
			}
			else{
				lider--;
			}
		}
		lider = 0;
		FOR( i , 0 , n ){
			if( tab[ i ] == val ){
				lider++;
			}
		}
		if( lider > n/2 )
			printf("%d\n",val);
		else
			printf("-1\n");

	}




	return 0 ;
}