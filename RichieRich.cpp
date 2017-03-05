#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string s;
    int n;
    int k;
    int len;
    int cnt = 0;
    bool cond ;
    
    cin >> n >> k;
    cin >> s;
    
    len = s.length();
    for( int i = 0 ; i < s.length()/2 ; ++i ){
        if( s[ i ] != s[ len - 1 - i ] ) cnt++;
    }
    
    
    if( cnt > k ) cout << -1 << endl;
    else{
        if( k > cnt+1 ) cond = true;
        else cond = false ;

        for( int i = 0 ; i < s.length()/2; ++i ){
            
            if( k <= cnt+1 ) cond = false;
            
            if( s[ i ] == s[ len - 1 - i ] ){
                if( cond )
                    if( s[ i ] != '9' ){
                        s[ i ] = '9';
                        s[ len - 1 - i ] = '9';
                        k -= 2;
                    }
            }   
            else{
                if( k >= cnt+1 ){
                    if( max( int( s[ i ] ) - 48 , int( s[ len - 1 - i ] ) - 48 ) != 9 ){
                        s[ i ] = '9';
                        s[ len - 1 - i ] = '9';
                        cnt--;
                        k -= 2;
                    }
                    else{
                        s[ i ] = '9';
                        s[ len - 1 - i ] = '9';    
                        k--;
                        cnt--;
                    }
                }
                else{
                    s[ i ] = int( max( int( s[ i ]) , int(s[ len - i -1 ] ) ) );
                    s[ len - 1 - i ] = int( max( int( s[ i ]) , int(s[ len - i -1 ] ) ) );
                    k--;
                    cnt--;
                }
            }
        }
        if( len % 2 == 1 and k > 0 ) s[ len/2 ] = '9';
        cout << s << endl;
    }
    return 0;
}
