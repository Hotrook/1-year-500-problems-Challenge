#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

int t[1000];
int n;
int k;

void position(int x){
	int wsk = 0;
	int start;
	if(x>=k){ 
		for(int i = 0 ; i < k; ++i)
			printf("%d ",t[i]);
		printf("\n");
	}
	else{
		if (x==0){
			 start=1;
			 t[0]=1;
		}
		else{
			 start=t[x-1]+1;
		}
		for(int i=start; i<=n ; ++i){
			t[x]=i;
			position(x+1);
		}
	}
}

int main(){
	
	int t;
	int result;
	int sum = 0;
	char c;

	cin >> t;

	FOR( i , 0, t ){
		cin >> n >> k ;
		position(0);
	}

	return 0 ;
}