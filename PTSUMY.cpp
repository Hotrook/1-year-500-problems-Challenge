#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

int tab[100];

void sumy( int n , int pozycja);


int main(){
	
	int t;
	int n;
	int k; 
	int result;
	int sum = 0;
	char c;

	int a = 1;
	int b = 1;

	cin >> t;

	FOR( i, 0 , t ){
		cin >> n ;
		sumy( n, 0  );
	}




	return 0 ;
}




void sumy( int n , int pozycja){
	if( n == 0 ){
		FOR( i , 0 , pozycja )
			printf("%d ",tab[i]);

		cout << endl;
	}
	else if( pozycja == 0 ) {
		FOR( i , 1 , n + 1){
			tab[ 0 ] = i;
			sumy( n-i , 1 );
		}
	}
	else{
		FOR( i , tab[pozycja-1], n+1){
			tab[ pozycja ] = i;
			sumy( n - i , pozycja+1);
		}
	}
}