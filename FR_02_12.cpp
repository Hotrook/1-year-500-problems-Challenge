#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR( i , a , b ) for( int i = a ; i < b ; ++i  )
#define PI pair< int , int >
#define VI vector< int  >
#define VPI vector< pair< int, int>  >
#define mp make_pair

long long int NWD( long long int a, long long int b ){
    if( b > a ) swap( a, b );
    if( b == 0 ) return a;
    return NWD( b, a%b );
}

long long int NWW( long long int a, long long int b ){
    return (a*b)/NWD( a, b );
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    long long int n ;
    long long int a;
    long long int b;
    long long int c;
    long long int d;

    cin >> a >>b >> c >> d;

    d *=100;

    long long int temp = NWW( a, NWW( b, c ) );


    cout << d/temp << endl;
    

    
    return 0;
}
