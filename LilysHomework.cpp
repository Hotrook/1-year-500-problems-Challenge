#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define VI vector< int > 
#define MP make_pair
#define PII pair< int , int >

void makePositionsInh( VI& h,vector< PII >& in, int n ){
    for( int i = 0 ; i < n ; ++i ){
        h[ in[ i ].second ] = i;
    }
}


int checkHowMuchSwaps(VI& h,vector<bool>& h2,int n){
    int cnt = 0;
    int it = 0;
    while( it < n ){
        int inCnt = 0;
        int inIt = it;
        
        if( h2[ it ] == false ){
            while( h[ inIt ] != it ){
                h2[ inIt ] = true;
                inIt = h[ inIt ];
                inCnt++;
            }
            h2[ inIt ] = true;
        }
        
        cnt += ( inCnt ) ;
        
        it++;
    }
    return cnt;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n ; 
    int x ;
    int it = 0;
    int cnt = 0;
    
    auto cmp = [](PII a , PII b){ return a.first < b.first; }; 
    
    cin >> n;
    
    vector < PII > in(n);
    vector < int > h(n);
    vector < bool > h2( n, false );
    
    for( int i = 0 ; i < n ;++i  ){
        cin >> x;
        in[ i ] = MP( x, i );
    }
    
    sort( in.begin(), in.end(), cmp );
    makePositionsInh( h, in, n );
    int counter1 = checkHowMuchSwaps(h, h2, n);
    
    h2 = vector< bool >( n, false ); 
    reverse( in.begin(), in.end() );
    makePositionsInh( h, in, n );
    int counter2 = checkHowMuchSwaps(h, h2, n);
    
    cout << min( counter1, counter2 ) << endl;
    
    
    
    
    
    return 0;
}
