#include <iostream>
#include <map>
#include <queue>
#include <stdint.h>



#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;


int main(){
	
	int t;
	int  n;
	int  k; 
	int result = 0;
	vector <int> que;
	map <int32_t,int32_t> towary;
	ios_base::sync_with_stdio();

	scanf("%d\n",&t);

	FOR( i, 0 , t ){
		scanf("%d%d",&n,&k);
		if ( towary[ n ] == 0 ){
			result ++;
			que.push_back(n);
			towary[ n ] = k;
		}
		else{
			towary[ n ] += k;
		}
	}
	printf("%d\n",result);
	for( vector<int>::iterator it = que.begin(); it != que.end() ; it++){
		printf("%d %d\n", *it ,towary[(*it)]);
	}

	return 0 ;
}