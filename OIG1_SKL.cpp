// #include <iostream>
// #include <map>
// #include <queue>
// #include <stdint.h>



// #define FOR(i,a,b) for(int i = a ; i < b ; ++i )


// using namespace std;


// int main(){
	
// 	int t;
// 	int  n;
// 	int  k; 
// 	int result = 0;
// 	vector <int> que;
// 	map <int32_t,int32_t> towary;
// 	ios_base::sync_with_stdio();

// 	scanf("%d\n",&t);

// 	FOR( i, 0 , t ){
// 		scanf("%d%d",&n,&k);
// 		if ( towary[ n ] == 0 ){
// 			result ++;
// 			que.push_back(n);
// 			towary[ n ] = k;
// 		}
// 		else{
// 			towary[ n ] += k;
// 		}
// 	}
// 	printf("%d\n",result);
// 	for( vector<int>::iterator it = que.begin(); it != que.end() ; it++){
// 		printf("%d %d\n", *it ,towary[(*it)]);
// 	}

// 	return 0 ;
// }

// MAIN.EDU.PL Solution
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdio>
#include <stdint.h>



#define FOR(i,a,b) for(int i = a ; i < b ; ++i )

using namespace std;


struct temp{ int towar;  short int ilosc; int pozycja; };

void quicksort( temp tab[],int start, int stop);
int partition( temp tab[],int start, int stop);

temp tab[1000001];

int main(){
   
   srand(time(NULL));
   int t;
   int  n;
   short int  k;
   int result = 0;
   vector < pair<int,int> > que;
   
   ios_base::sync_with_stdio();
   
   scanf("%d\n",&t);
   
   FOR( i, 0 , t ){
       scanf("%d%hd",&n,&k);
       pair<int,int> elem;
       elem.first = n;
       elem.second = 0;
       que.push_back(elem);
       tab[i].pozycja = i ;
       tab[i].towar = n ;
       tab[i].ilosc = k ;
   }
   tab[t].towar = -1;
   tab[t].pozycja = -1;
   tab[t].ilosc = -1;
   
   quicksort(tab,0,t-1);
   
   int sum = 0;
   int min = 0;
   FOR(i,0, t+1){
       if( i == 0 ){
           sum = tab[i].ilosc;
           min = tab[ i ].pozycja;
       }
       else if( tab[ i ].towar == tab[ i - 1 ].towar){
           if( tab[ i ].pozycja < min )
               min = tab[ i ].pozycja;
           sum += tab[ i ].ilosc;
       }
       else{
           result++;
           que[ min ].second = sum;
           min = tab[ i ].pozycja;
           sum = tab[ i ].ilosc;
       }
   }
   
   printf("%d\n",result);
   
   FOR( i , 0 , t )
   if( que[ i ].second != 0 )
       printf("%d %d\n", que[i].first,que[i].second);
   
   
   
   return 0 ;
}


void quicksort( temp tab[],int start, int stop){
   if( start >= stop )
       return ;
   int r = rand()%(stop-start)+start;
   swap( tab[ r ],tab[ start ]);
   int first = tab[start].towar;
   
   
   int f = start;
   int s = stop;
   int i = start+1;
   
   while( i <= s){
       if( tab[ i ].towar < first ){
           f++;
           swap(tab[ i ],tab[ f ]);
           i++;
       }
       else if( tab[ i ].towar > first ){
           swap(tab[ i ], tab[ s ]);
           s--;
       }
       else{
           i++;
       }
   } 
   
   swap(tab[start],tab[ f ]);
   
   
   quicksort( tab , start, f-1);
   quicksort( tab, s+1, stop );
   
}




int partition( temp tab[],int start, int stop){
   int pos = 0;
   
   return pos;
}







