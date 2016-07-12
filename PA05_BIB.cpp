#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#define FOREACH( it , result ) for( auto & it : result )
#define FOR(i,a,b) for(int i = a ; i < b ; ++i )
#define PB push_back
#define MP make_pair
using namespace std;


typedef pair<int,int> PRII;


class Compare{

public:
	bool operator()(PRII a, PRII b){
		return a.second > b.second;
	}
};



int main(){
	
	int n;
	int m;
	int k;
	int t;
	
	int a;
	int b; 
	int start;
	int rodzaj;

	long long result = 0 ;

	priority_queue< PRII, vector<PRII> , Compare > que;
	vector<PRII> results;
	ios_base::sync_with_stdio( false );

	results.clear();

	// cin >> t;

	// FOR( i, 0, t ){
		results = 	vector<PRII>();
		result = 0;

		cin >> n ;
		FOR( j, 1, n+1){
			
			cin >> a;
			que.push(MP( j , a ) );
			
		}	

		while( !que.empty() ){
			PRII temp = que.top();
			que.pop();
			PRII temp2 = que.top();
			que.pop();
			int help = min( temp.first, temp2.first );
			int help2 = temp.second + temp2.second ;
			results.PB( MP( help, max( temp.first, temp2.first ) ));
			if( !que.empty() ){
				que.push(MP( help , help2));
			}
			result += help2; 
		}
		cout << result << "\n";
		for( vector< PRII >::iterator it = results.begin(); it!= results.end() ; ++it){
					cout << (*it).first << " "<< (*it).second << "\n";
		}
	// }

	return 0 ;
}
