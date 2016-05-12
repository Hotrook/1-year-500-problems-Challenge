#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back


using namespace std;

const int size = 45009;

struct input{ 
	int x;
	int y;
	int numer;
};

bool malejacoYcomp( input a , input b ){
	return a.y > b.y;
}

bool malejacoXcomp( input a , input b ){
	return a.x > b.x;
}

bool forbidden[ size ];

vector <int> test;
int main(){
	
	long long t;
	long long n;

	vector<int> help(4);


	vector <input> malejacoX(size);
	vector <input> malejacoY(size);
	ios_base::sync_with_stdio(false);
	
	scanf("%lld",&t);
	//cin >> t;
	FOR( i , 0 , t){
		scanf("%lld",&n);

		// cin >> n;

		FOR( j, 0 , n ){
			forbidden[ j+1 ] = false;
			input in; 
			scanf("%d %d",&in.x,&in.y);

			in.numer = j+1;

			malejacoX[ j ] =  malejacoY[ j ] = in ;
		}

		
		sort( malejacoY.begin(),malejacoY.begin() + n ,malejacoYcomp );
		sort( malejacoX.begin(),malejacoX.begin() + n ,malejacoXcomp );


		vector< input >::iterator mxk = malejacoX.begin() + n-1;
		vector< input >::iterator mxp = malejacoX.begin();
		vector< input >::iterator myp = malejacoY.begin();
		vector< input >::iterator myk = malejacoY.begin() + n-1;

		FOR( j , 0 , n/3 ){
			while ( forbidden[(help[ 0 ] = (*mxp).numer)] ){
				mxp++ ;
			}
			while ( forbidden[(help[ 1 ] = (*myp).numer)] ){
				myp++;
			}
			while ( forbidden[(help[ 2 ] = (*mxk).numer)] ) 
				mxk--;
			while ( forbidden[(help[ 3 ] = (*myk).numer)] )
				myk--;

			forbidden[ help[ 0 ] ] = true;
			forbidden[ help[ 1 ] ] = true;
			forbidden[ help[ 2 ] ] = true;
			forbidden[ help[ 3 ] ] = true;
	
			sort( help.begin(), help.end() );

			printf( "%d ",help[0]);
			// cout << help[ 0 ] << " ";
			FOR( k , 1 , 4){
				if( help[ k ] != help[ k -1 ]){
					printf( "%d ",help[k]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0 ;
}