#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

using namespace std;

inline void readINT(int *n) //ujemne i dodatnie
{
    register char c = 0, 
  znak_liczby=1;  //1 - liczba dodatnia, -1 - liczba ujemna
    while (c < 33) c=getc_unlocked(stdin);
 
    if(c==45) {znak_liczby=-1;  c=getc_unlocked(stdin);}//jesli napotkamy minus
    (*n) = 0;
 
  while (c>32) {(*n)=(*n)*10 + c-48; c=getc_unlocked(stdin);} 
 
    (*n)*=znak_liczby;
} 

inline void putUI(unsigned int n) {
 
     if(n==0) //ten przypadek rozpatrujemy oddzielnie
     {
       putc_unlocked(48,stdout); //wypisz 0
       return; //zakończ wypisywanie
     }
 
   char tab[12];//tablica będzie przechowywać cyfry
     int p = 0;
     while(n != 0) { //wyłuskanie kolejnych cyfr z liczby n
        tab[p++] = (n % 10) + 48;
         n /= 10;
     }
     while(p--) 
         putc_unlocked(tab[p], stdout); //wypisanie liczby
}

int main(){

	vector< int > tab( 5001 );
	
	int t;
	int n;
	int m;
	int a;q
	int suma ;
	int szukana ;  


	readINT(&t);
	FOR( i , 0 , t ){
		readINT(&n);
		suma = 0 ;

		FOR( i , 0 , n){
			readINT(&tab[i]);
			suma +=  tab[ i ];

		}

		szukana = suma/2;

		int* plecak = new int[ szukana +1];
		FOR( i, 0 , szukana + 1 ) plecak[ i ] = 0 ;

		for( int k = 0 ; k < n ; k++ ){
			int i = tab[ k ];
			for( int j = szukana ; j >= i ; --j ){
				plecak [ j ] = max( i + plecak[ j - i ], plecak[ j ]);
			}
		}
		putUI(abs( suma - 2 * plecak[ szukana ] ));
		putc_unlocked(32,stdout);
		putUI(suma);
		putc_unlocked(10,stdout);

	}


	return 0 ;
}
