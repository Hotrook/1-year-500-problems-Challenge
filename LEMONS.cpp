#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
using namespace std;


typedef unsigned long long int uint64_t;

struct point{ int number; int a; int b;};
struct edge{ int start; int stop; int dis; };

int dis[ 1000 ][ 1000 ];
int * UAF;
int * sizeUAF;



int makedis( point a, point b ){
	return sqrt( (a.a-b.a)*(a.a-b.a)+(a.b-b.b)*(a.b-b.b) ); 
}

class Comparator{ 
public:
	bool operator()( edge a, edge b){
		return a.dis > b.dis;
	}
};

int prim( vector< point > & input , int size ){

	int result = 0;
	int * odw = new int[ size ];
	FOR( i , 0 , size ) odw [ i ] = 0;
	priority_queue<edge, vector< edge > , Comparator > pq;

	edge temp;
	temp.start = temp.stop = temp.dis = 0;
	pq.push( temp );

	int counter = 0;
	while ( counter < size  ) {
		temp = pq.top();
		pq.pop();
		if( odw[ temp.stop ] == 0 ){
			counter++;
			odw[ temp.stop ] = 1;
			result += temp.dis;
			FOR ( i, 1 , size ){
				if( odw[ i ] == 0 ){
					edge temp2;
					temp2.start = temp.stop;
					temp2.stop = i ;
					temp2.dis = makedis( input[ temp.stop ] , input[ i ] );
					pq.push( temp2 );
				}
			}
		}
	}
	return result;
}

int main(){
	
	int n;
	int m;
	int k;
	
	int t;
	int a;
	int b; 
	int start;
	int rodzaj;
	string temp;

	ios_base::sync_with_stdio( false );

	vector< point > input;

	cin >> n ;

	FOR( i , 0 , n ){
		cin >> a >> b ;
		point temp;
		
		temp.number = i;
		temp.a = a ;
		temp.b = b ;

		input.PB( temp );

	}


	int result = prim( input, n );

	cout <<  result << "\n";



	return 0 ;
}
