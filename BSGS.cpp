#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;  
    int a;
    int b;
    int d;

    cin >> n;

    for( int i = 0 ; i < n ;  ++i ){
    	cin >> a >> b >> d;
    	int con = d / max( a , b);
    	if( d == 0 ){
    		con = 0 ;
    	}
    	else if( d < min( a, b ) ){
    		con = 2;
    	}
    	else if( d > min(a, b ) and d < max( a , b ) ){
    		con = 2;
    	}
    	else if( con * max( a, b ) != d ){
    		con ++;
    	}

    	cout << con << endl;
    }
    return 0;
}
