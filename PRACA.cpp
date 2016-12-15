#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back
typedef pair< int, int > element;
typedef unsigned long long int ulint;

int partia[ 1000001 ];
int tab[ 1000001 ];


inline void readINT(int *n) //ujemne i dodatnie
{
    register char c = 0, 
  znak_liczby=1;  //1 - liczba dodatnia, -1 - liczba ujemna
    while (c < 33) c=getc(stdin);
 
    if(c==45) {znak_liczby=-1;  c=getc(stdin);}//jesli napotkamy minus
    (*n) = 0;
 
  while (c>32) {(*n)=(*n)*10 + c-48; c=getc(stdin);} 
 
    (*n)*=znak_liczby;
} 

inline void putUI(unsigned int n) {
 
     if(n==0) //ten przypadek rozpatrujemy oddzielnie
     {
       putc(48,stdout); //wypisz 0
       return; //zakończ wypisywanie
     }
 
   char tab[12];//tablica będzie przechowywać cyfry
     int p = 0;
     while(n != 0) { //wyłuskanie kolejnych cyfr z liczby n
        tab[p++] = (n % 10) + 48;
         n /= 10;
     }
     while(p--) 
         putc(tab[p], stdout); //wypisanie liczby
     putc(10,stdout);
}

void make ( int last , int b , int i ){
	for( int j = last ; j <= b ; ++j ) {
		if( partia[ j ] != i ) tab[ j ] = 0;
		tab[ j ] += tab[ j - 1 ];
	}
}
int main(){
	
	int n;
	int m;
	int t;
	int a;
	int b; 
	int last = 1;

	readINT( &t );

	FOR( i , 0 , t ){
		readINT( &m );
		readINT( &n );
		last = 1 ;
		FOR( j , 0 , m ){
			readINT( &a );
			if( partia[ a ] != i ) {
				tab[ a ] = 0 ;
				partia[ a ] = i;
			}
			tab[ a ]++;
		}

		if(partia[ 0 ] != i ) tab[ 0 ] = 0;
		


		readINT( &n );

		FOR( j , 0 , n ){
			readINT( &a );
			readINT( &b );
			if ( last-1 < b ){
				make( last , b , i);
				last = b+1;
			}
			int temp = tab[ b ];
			if( a!= 0 ) temp -= tab[ a-1 ];
			putUI( temp );
		}

	}

	return 0 ;
}



