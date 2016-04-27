#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

void buildHeap(int * tab,int size );
void heapify( int * tab, int pos, int size );

int main(){
	
	int t;
	int n;
	int size;
	int k, a, b;
	int *tab;
	char p;


	ios_base::sync_with_stdio(false);
	
	cin >> t;

	FOR( i , 0 , t ){

		cin >> size;
		tab = new int[ size ];

		FOR( j , 1 , size+1 ){
			cin >> tab[ j ];
		}

		buildHeap( tab, size );

		cin >> n;

		FOR( j , 0 , n ){
			cin >> p;
			if( p == 'P'){
				FOR( j , 1, size+1){
					cout << tab[ j ] << " ";
 				}
 				cout << endl;
			}
			else if( p == 'E' ){
				cout << tab[ 1 ] << endl;
				tab[ 1 ] = tab[ size ];
				size--;
				heapify( tab, 1, size );
			}
		}
	}

	



	return 0 ;
}

//*****************************************************************************
void buildHeap(int * tab,int size ){
	for( int i = size/2 ; i >= 1 ; i-- ){
		heapify(tab, i, size);
	}
}
//*****************************************************************************




//*****************************************************************************
void heapify( int * tab, int pos, int size ){
	int left = 2*pos;
	int right = 2*pos + 1;
	int toChange = pos;

	if( left <= size and tab[ left ] < tab[ pos ] ){
		toChange = left;
	}
	if( right <= size and tab[ right ] < tab[ toChange ] ){
		toChange = right;
	}

	swap(tab[ toChange ], tab[ pos ] );

	if( toChange != pos ){
		heapify( tab, toChange, size );
	}

}
//*****************************************************************************




