#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int min = -1;
    int min_number = 0;
    int counter = 0;
    int first = -1;
    
    int numbers[ 26 ];
    
    for( int i = 0; i < 26; ++i ){
        cin >> numbers[ i ];
        
        if( min == -1 and numbers[ i ] != 0 ){
            min = numbers[ i ];
            min_number = i;
            first = i;
        }
        
        if( numbers[ i ] < min and numbers[ i ] != 0 ){
            min = numbers[ i ];
            min_number = i;
        }
        
        if( numbers[ i ] != 0 ) counter++;
    }
    

    cout << char(97+ min_number ) ;
    numbers[ min_number ]--;
    
    
    if( min_number != first ){
        for( int i = 0 ; i < 26; ++i ){
            while( numbers[ i ] > 0  ){
                cout << char( 97+i );
                numbers[ i ]--;
            }
        }
    }
    else{
        
        if( numbers[ min_number ] > 0 ){
            cout << char( 97 + min_number );
            numbers[ min_number ]--;
        }
        
        int it = 0 ;
        if( counter != 1 ){
            while( it == first or numbers[ it ] == 0 ){
                it++;
            }
            cout << char( 97 + it );
            numbers[ it ]--;
        }
        
        
        for( int i = 0 ; i < 26 ; ++i ){
            if( i != min_number )
                while( numbers[ i ] > 0 ){
                    if( min_number < i and numbers[ min_number ] > 0 ){
                        cout << char( 97 + min_number );
                        numbers[ min_number ]--;
                    } 
                    cout << char( 97 + i );
                    numbers[ i ]--; 
                }
        }
        
        
        while( numbers[ min_number ] > 0 ){
            cout << char ( 97 + min_number );
            numbers[ min_number ]--;
        }
    
    
    }
    
    
    
    
    return 0;
}
