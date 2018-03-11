#include <iostream>
#include <iomanip> 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set> 
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define FORD(i, a, b ) for( long long i = a ; i >  b ; --i )
#define PB push_back
#define VI vector<int>

using namespace std;

struct numbers{
	char nums[ 100 ][ 400 ];
	int size;
	numbers( )
	{
		size = 0;
	}
};

struct number{
	string f;
	string i;
	int sign;

	number()
	{
		f = string( 200, '0');
		i = string( 200, '0');
		sign = 1;
	}
};

void parse(string t, numbers * neg );
number sum( numbers nums );
number calculateDifference( number pos, number neg );
void printBigNum( number n );

int main(){
	
	int n;
	string t;

	numbers pos;
	numbers neg;

	cin >> n;

	for( int i = 0; i < n ; ++i ){
		cin >> t;

		if( t[ 0 ] == '-' )
		{
			parse( t , &neg );
		}
		else
		{
			parse( t, &pos );
		}
	}

	number positive = sum( pos );
	number negative = sum( neg );


	number result = calculateDifference( positive, negative );


	printBigNum( result );


	return 0 ;
}

void printBigNum( number n )
{
	if( n.sign == -1 )
	{
		cout << '-';
	} 
	int pos = 0 ;

	while( n.i[ pos ] == '0' && pos < 200 )
	{
		pos++;
	}

	if( pos == 200 )
	{
		cout << '0';
	}
	else
	{
		FOR( i, pos, 200 )
		{
			cout << n.i[ i ];
		}
	}

	pos = 199 ;
	while( n.f[ pos ] == '0'  && pos >= 0 )
	{
		pos--;
	}

	if( pos != -1 )
	{
		cout << ',';
		FOR( i, 0, pos + 1 ){
			cout << n.f[ i ];
		}
	}
	cout << endl;

}

void parse(string t, numbers * neg )
{
	if( t[ 0 ] == '+' || t[ 0 ] == '-' )
	{
		t = t.substr( 1, t.size() );
	}

	for( int i = 0 ; i < 400 ; ++i )
	{
		neg->nums[ neg->size ][ i ] = '0';
	}

	int colon = t.find(',');

	if( colon == string::npos )
	{
		int start = 199; 
		FORD( i , t.size() - 1, -1 )
		{
			neg->nums[ neg->size ][ start ] = t[ i ];
			start--;
		}
	}
	else
	{
		int start = 199; 
		FORD( i , colon - 1, -1 )
		{
			neg->nums[ neg->size ][ start ] = t[ i ];
			start--;
		}
		start = 200;
		FOR( i , colon + 1, t.size() )
		{
			neg->nums[ neg->size ][ start ] = t[ i ];
			start++;
		}
	}

	neg->size++;
}

number sum( numbers nums )
{
	number result;

	int shift = 0 ;

	FORD( i, 399, 199 ){
		int sum = 0;
		FOR( j, 0, nums.size )
		{
			int digit = int(nums.nums[ j ][ i ] - 48);
			sum += digit;
		}		
		sum += shift;
		result.f[ i - 200 ] =  sum % 10 + 48;
		shift = sum / 10;
	}

	int start = 199;
	while( start >= 0 )
	{
		int sum = 0 ;
		FOR( j, 0, nums.size )
		{
			sum += (nums.nums[ j ][ start ] - 48);
		}
		sum += shift;
		result.i[ start ] = sum % 10+48;
		shift = sum / 10;
		start--; 
	}

	return result;
}

int compare( string p, string n )
{
	for( int i = 0 ; i < 400 ; ++i )
	{
		if( p[ i ] != n[ i ] ){
			if( int(p[ i ]) < int(n[ i ]) )
			{
				return -1;
			}
			return 1;
		}
	}
	return 1;
}

number calculateDifference( number pos, number neg )
{
	number result;

	string positive = pos.i + pos.f;
	string negative = neg.i + neg.f;


	string r( 400, '0');

	int c = compare( positive, negative );
	result.sign = c;
	string bigger = positive, smaller = negative;

	if( c == -1 )
	{
		bigger = negative;
		smaller = positive;
	}

	FORD( i, 399 , -1 )
	{
		int up = bigger[ i ] - 48;
		int down = smaller[ i ] - 48 ;
		if( up < down )
		{
			int it = i; 
			while( bigger[ it - 1 ] == 0 )
			{
				it--;
				bigger[ it ] = '9';
			}
			bigger[ it-1 ] = (bigger[ it-1 ] - 1);
			up += 10;
		}
		r[ i ] = char(up - down + 48 );
	}

	result.i = r.substr( 0, 200 );
	result.f = r.substr( 200, 200 );


	return result;
}
