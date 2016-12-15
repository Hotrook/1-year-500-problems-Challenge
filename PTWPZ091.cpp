#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;



int main(){
	
	int t;
	int n;
	int x;
	int y;
	int h;
	int r;
	int maxh;
	int maxx;
	int maxy;
	int minx;
	int miny;
	int surf; //surface


	ios_base::sync_with_stdio(false);
	
	cin >> t;

	FOR( i , 0 , t ){
		cin >> n ;
		maxh=0;
		maxx=0;
		maxy=0;

		FOR( j , 0 , n ){
			cin >> x >> y >> h >> r ;
			if( j == 0 ){
				minx = x-r;
				miny = y-r;
			}			
			maxx = max( maxx, x+r );
			maxy = max( maxy, y+r );
			maxh = max( maxh, h+r );
			minx = min( minx, x-r );
			miny = min( miny, y-r );
		}

		cout << (maxx-minx)*maxh*2 + (maxy-miny)*maxh*2 + (maxx-minx)*(maxy-miny) << endl;
	}

	



	return 0 ;
}