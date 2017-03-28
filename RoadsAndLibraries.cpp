#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void make( vector< pair< int , int > >& input, int size ){
    for( int i = 1; i <= size ; i++ ){
        input[ i ].first = i;
        input[ i ].second = 1; 
    }
}


int find( int i, vector< pair<int, int> > & input ){
    if( i == input[ i ].first ) return i;
    else return input[ i ].first = find( input[ i ].first, input );
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    int m;
    int q;
    int a;
    int b;
    int cm;
    int cd;
    long long sum;
    
    
    cin >> q ;
    
    vector< pair<int, int> > scc;
    vector< int > help;
    
    while( q-- ){
        cin >> n >> m >> cm >> cd ;
        
        
        scc = vector< pair< int, int > > ( n+1, make_pair(1,1));
        help = vector< int > ( n + 1, 0 );
        sum = 0 ;
        
        make( scc, n );
        
        for( int i = 0 ; i < m ; i++ ){
            
            cin >> a >> b;
            
            int fa = find( a, scc  );
            int fb = find( b, scc );
            
            if( fa != fb ){
                if( scc[ fa ].second > scc[ fb ].second ){
                    scc[ fa ].second += scc[ fb ].second; 
                    scc[ fb ].first = fa;
                }
                else{
                    scc[ fb ].second += scc[ fa ].second;
                    scc[ fa ].first = fb;
                }
            }
        }
            
        for( int i = 1 ; i <= n ; ++i ){
            int f = find( i, scc );
            int temp = 0;
            if( help[ f ] != 1 ){
                temp = cm;
                if( cm < cd ) temp += cm * (scc[ f ].second-1);
                else temp += cd * (scc[ f ].second-1);
                sum += temp;
                help[ f ] = 1;
            }   
        }
        
        cout << sum << endl;
            
    }
    return 0;
}
