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

typedef pair<int,pair<string,string> > pairIS;

string pattern[ 205 ];

void reverse( string& a );
bool operator<( string a, string b );
string operator*( string a, int number );
string operator-(string a, string b );
pairIS findPow( string& number );
void help( string& number , vector< int >& add , vector < int >& sub, int sign );
void find( string& number );

int main(){
	
	char s[100000];
	string n;
	int t;
	int b; 
	int start;
	int rodzaj;


	ios_base::sync_with_stdio( false );

	pattern[ 0 ] = "1";
 	for( int i = 1 ; i < 205 ; ++i ){
		pattern[ i ] = pattern[ i - 1 ] * 3;
	}

	cin >> t;

	FOR( i , 0 , t ){

	
		string n;
		cin >>n ;
		reverse(n);

		find( n );


	}


	return 0 ;
}




void reverse( string& a ){
	int length = a.length()-1;

	for ( int i = 0 ; 2*i < length ; ++i ){
		swap( a[ i ], a[ length - i ] );
	}
}

bool operator<( string a, string b ){
	if( a.length() < b.length() ) return true;
	if( a.length() > b.length() ) return false;

	for ( int  i = a.length()-1 ; i >= 0 ; --i){
		if( a[ i ] < b[ i ] ) return true;
		else if( b[ i ] < a[ i ] ) return false;
	}
	return false;
}

string operator*( string a, int number ){
	int c = 0;
	for ( int i = 0 ; i < a.length(); ++i ){
		int temp = a[ i ] - 48 ;
		temp *= number;
		temp += c;
		a[ i ] = char(temp%10+48);
		c = temp/10;
	}
	if(  c != 0 ){
		a += char( 48 + c );
	}
	return a;
}

string operator-(string a, string b ){
	int iterator = 0 ;
	bool c = false;
	string result;

	if( a == b )return "0";

	while ( iterator < b.length() ){
		int temp = a[ iterator ] - 48 ;
		if( c ) temp = temp == 0 ? 9 : temp - 1;

		int temp2 = b[ iterator ] - 48;

		if( temp < temp2 ){
			temp += 10;
			c = true;
		}
		else{
			if( c and temp == 9 ) c = true;
			else
			c = false;
		}

		temp = temp - temp2;
		result += char(temp+48);
		iterator++;
	}
	while( iterator < a.length() ){
		int temp = a[ iterator ] - 48 ;
		if( c ){
			if( temp == 0 ){
				a[ iterator ] = '9';
				temp = 9;
			}
			else{
				temp--;
				c = false;
				a[ iterator ] = char( temp + 48 );
			}
		}

		result += a[ iterator ];
		iterator++;
	}
	if( result == "" ) result = "0";
	int it = result.length()-1;

	while( result[ it ] == '0' ) it--;
	return result.substr(0,it+1);
}

pairIS findPow( string& number ){
	pairIS result;
	int pw = 0 ; 
	while ( pattern[pw] < number ) { pw++;}
	result.first = pw;
	result.second.first = pattern[ pw ];
	result.second.second = pw == 0 ? "0" : pattern[ pw -1 ];
	return result;
}



void help( string& number , vector< int >& add , vector < int >& sub, int sign ){
	if ( number == "0" ) return;


	pairIS res = findPow(number);
	int pw = res.first;
	string temp = res.second.first;
	string prev = res.second.second;

	if( (number*2) < temp  ){
		if( sign == -1 ) sub.PB( pw-1 ); 
		else add.PB( pw-1 );
		number = number - prev;
		help ( number , add, sub, sign );

	}
	else{
		if( sign == -1 ) sub.PB( pw ); 
		else add.PB( pw );
		number = temp - number;
		help( number, add, sub, -sign);
	}
}

void find( string& number ){
	vector< int > add;
	vector< int > sub;

	help ( number, add, sub, 1 );

	cout << add.size() << " ";
	for( int i = add.size() - 1 ; i >= 0 ; --i )
		cout << add[ i ] << " ";	
	cout << "\n";

	cout << sub.size() << " ";
	for(  int i = sub.size() - 1 ; i >= 0 ; --i ) 
		cout << sub[ i ] << " ";
	cout << "\n";
}
