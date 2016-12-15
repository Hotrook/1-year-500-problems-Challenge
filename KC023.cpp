#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

void dfs( int start );

int visited[ 101 ];
vector< vector<int> > graph(100);

int main(){
	
	int help;
	string s;

	while( cin >> s ) {

		FOR ( i , 0 , 100 )
			graph[ i ].clear();

		FOR ( i , 0 , 10 ){
			FOR ( j, 0 , 10 ){
				visited[ i*10 + j ] = 0;
	
				if( j > 0)
					if ( s[ i*10 + j ] != 'X' and s[ i*10 + j -1  ] != 'X'  ){
						graph[ i*10 + j ].push_back( i*10 + j -1 );
						graph[ i*10 + j -1 ].push_back( i*10 + j  );
					}
				if( i > 0)
					if( s[ i*10 +j ] != 'X' and s[(i-1)*10 +j ] != 'X' ){
						graph[i*10 +j].push_back((i-1)*10 +j );
						graph[(i-1)*10 +j].push_back(i*10 +j);
					}

			}
		}
		
		dfs(0);

		cout << visited[99] << endl;

	}


	return 0 ;
}

 
void dfs( int start ){
	visited[ start ] = 1;
	for( vector<int>::iterator it = graph[start].begin(); it != graph[start].end() ; it++){
		if ( visited[ (*it) ] == 0  )
			dfs( (*it) );
	}
}