#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define PB push_back
using namespace std;

struct comp{
    bool operator( )(pair<int,int> a , pair< int,int > b ){
        return a.first < b.first;
    }
} object;

int main() {
    int a;
    int b;
    cin >> a;
    vector< int > A(a);
    for( int i = 0 ; i < a ; ++i ) cin >> A[ i ];
    cin >> b;
    vector< pair<int,int> > B( b , make_pair(0,0) );
    for( int i = 0 ; i < b ; ++i ) cin >> B[ i ].first;
    
    vector< int > result;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), object );
    
    int ia = 0;
    int ib = 0;
    while( ia < A.size() ){
        int temp = A[ ia ];
        
        while( B[ib].first < temp ){
            if( result.size() == 0 or B[ ib ].first != result[ result.size() - 1] )
            result.PB( B[ib ].first );
            ib++;
        } 
        B[ib].second = 1;
        ib++;
        
        ia++;
    }
    while( ib < B.size() ){
        if( result.size() == 0 or B[ ib ].first != result[result.size() - 1 ])
            result.PB( B[ib].first);
        ib++;
    }
    for( auto i : result ){
        cout << i << " " ;
    }
    cout << endl;
    
    
    
    return 0;
}
