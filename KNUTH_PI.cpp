#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;



int vec[1000001];

int main(){
	
	int test;
	int n;
	int k; 
	string s;

	ios_base::sync_with_stdio();

	cin >> test;
	cin.ignore();
	FOR( i, 0 , test ){ 
		getline( cin, s );
		int size = s.size();
		vec[ 1 ] = 0;
		printf("0 ");
		int t = vec[ 1 ];
		FOR(j,2,size+1){
				while( t > 0  and s[t] != s[j-1]) t = vec[t];
				
				if( s[t] == s[j-1])t++;
				
				vec[ j ] = t;
				printf("%d ",t);
		}
		printf("\n");

	}




	return 0 ;
}