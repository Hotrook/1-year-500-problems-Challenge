#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

int binSearch( vector< int >& tab, int start, int stop , int number ){

	if( start >= stop )
		return start;

	int middle = ( start + stop )/2;

	if( tab[ middle ] == number )
		return middle;
	else if( tab[ middle ] < number )
		return binSearch( tab, middle+1, stop , number  );
	else if( tab[ middle ] > number )
		return binSearch( tab, start, middle -1 , number  ); 
}


bool forbidden[1000];

bool checkSum( vector< int >& tab, int start, int stop , int sum ){

	int newSum = 0 ;
	for ( int i = stop ; i >= 0 ; i-- ){
		if( forbidden[ i ] == false ){
			forbidden[ i ] = true;
				newSum = sum - tab[ i ];
				if( newSum == 0 )
					return true;
				else if( newSum > 0 ){
					int pos = binSearch( tab, start, stop , newSum );
					if ( checkSum( tab, start, pos, newSum ) ){
						return true;
					}
				}
			forbidden[ i ] = false;
		}
	}

	return false;

}



int main(){
	
	int t;
	int n;
	int temp;
	int sum;

	vector<int> tab(1000);

	ios_base::sync_with_stdio(false);
	
	while( true ){
		cin >> sum;
		if( cin.eof() ) break;

		cin >> n;
		FOR( i , 0 , n ){
			cin >> tab[ i ];
			forbidden[ i ] = false;
		}

		if( sum == 0 )
			cout << "1\n";
		else{
			sort( tab.begin(), tab.begin()+n );

		 	if ( checkSum( tab, 0, n-1 , sum ) )
		 		cout << "1\n";
		 	else 
		 		cout << "0\n";
		}

	}

	return 0 ;
}