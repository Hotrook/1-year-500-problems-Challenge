#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
typedef unsigned long long int ulint;

using namespace std;




int main(){
	
	int n;
	int t;

	char  input[ 1000001 ];
	string output ="";


	ios_base::sync_with_stdio( false );


	scanf("%d",&t);

	FOR( j , 0 , t ){
		scanf("%s",input);	
		output = "";

		int length = strlen(input);

		int temp = input[ length - 1 ];
		output += input[ length - 1 ];

		for( int i = length - 2 ; i >= 0 ; --i){
			if( (int)input[i] >= temp ){
				output += input[ i ];
				temp = (int)input[i];
			}
		}

		for (int  i = output.length() -1  ; i >= 0 ; --i  ) {
			printf( "%c",output[i] );
		}
		printf("\n");

	}


	return 0 ;
}
