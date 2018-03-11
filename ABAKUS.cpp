#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set> 
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
#define VI vector<int>
#define L cout << "|"
#define STAR cout << "*"
#define SPACE cout << " "
#define ENDL cout << endl


using namespace std;

string getAbakus( ){
	string result = "";
	string temp;

	vector< int > help;

	getline( cin, temp );

	help = vector< int >( temp.length() - 2 );

	getline( cin, temp );
	getline( cin, temp );

	FOR( i, 1 , temp.length() - 1 ){
		if( temp[ i ] == '*' )
			help[ i - 1 ] = 0;
		else
			help[ i - 1 ] = 5;
	}

	getline( cin, temp );
	getline( cin, temp );

	FOR( i, 1, 11 ){
		getline( cin, temp );

		if( i <= 4 )
			FOR( k, 1, temp.length() - 1 )
				if( temp[ k ] == '*' ) help[ k-1 ]++;
		
	}

	int cond = false;

	for( int i = 0 ; i < help.size() ; ++i ){
		if( help[ i ] != 0 ) cond = true;
		if( cond )
			result += char( 48 + help[ i ] );
	}

	if( cond == false ) result = "0";
	return result;
}




void createAbakus( string & s ){

	string temp = "";
	bool cond = false;
	FOR( i, 0, s.length() ){
		if( s[ i ] != '0' ) cond = true;
		if( cond ) temp += s[ i ];
	}

	s = temp;
	if( cond == false ) s = "0";
	vector< int > arr;

	for( auto i : s ){
		arr.PB( int( i ) - 48 );
	}
	for( int i = 0 ; i < s.length()+2 ; ++i ){
		cout << "-" ;
	}
	ENDL;
	
	L;
	FOR( i, 0, s.length() ) STAR;
	L;
	ENDL;

	L;
	FOR( i, 0, s.length() )
		if( arr[ i ] <= 4 ) STAR;
		else SPACE;
 	L;
 	ENDL;

 	L;
 	FOR( i, 0, s.length() )
 		if( arr[ i ] > 4 ) STAR;
 		else SPACE;
 	L;
 	ENDL;

 	L;
 	FOR( i, 0, s.length() ) cout << "-";
 	L;
 	ENDL;
	
	FOR( i, 1, 10){
		L;
		FOR( j, 0, arr.size() ){
			if( i <= 4 ) {
				if( (i <= arr[ j ] and arr[ j ] <=4 ) or ( arr[ j ] > 4 and i <= arr[ j ] - 5 ))STAR;
				else SPACE;
			}
			else{
				if( (arr[ j ] > 4 and i >= arr[ j ] ) or ( arr[ j ] <=4  and i >  4 + arr[ j ] )) STAR;
				else SPACE;
			}
		}
		L;
		ENDL;
	}

	for( int i = 0 ; i < s.length()+2 ; ++i ){
		cout << "-" ;
	}


	ENDL;
}

int main(){

	string s;
	int x;
	vector< int > arr;

	while( getline( cin, s ) ){

		if( cin.eof() ) break;

		if( stoi( s ) ){
			getline( cin, s );
			createAbakus( s );
		}
		else{
			s = getAbakus( );
			cout << s << endl;
		}
	}

	return 0 ;
}
