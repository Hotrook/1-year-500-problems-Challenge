#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(long long i = a ; i < b ; ++i )
#define PB push_back

using namespace std;

struct Element{ 
	int a;
	int b;
	int max;
	Element* parent;
	Element* right;
	Element* left;
};

Element * buildTree(Element* parent, int a , int b ){
	Element * v= new Element;
	v->a = a;
	v->b = b;
	v->parent = parent;
	v->max = 0 ;
	if( a != b ){
		int middle = (a+b)/2;
		v->left = buildTree( v, a, middle );
		v->right = buildTree( v, middle + 1, b );
	}
	else
		v->right = v->left = nullptr;

	return v;
}


void check( Element * e ){
	if( e->max != max( e->right->max , e->left->max ) ){
		int rmax = e->right != nullptr ? e->right->max : 0;
		int lmax = e->left != nullptr ? e->left->max : 0;
		e->max = max( rmax, lmax );
		if( e-> parent != nullptr )
			check( e->parent );
	}
}



void actualize( Element * element , int start,  int value ){
	if( element->a == start and element-> b == start ){
		element->max = value;
		check( element->parent );
	}
	else{
		if( start <= element->left->b )
			actualize( element->left, start, value );
		else
			actualize( element->right , start, value );
	}
}


int findMax( Element * e , int a, int b ){
	int maxl = 0 ;
	int maxr = 0;
	int middle = ( e->a + e->b )/2;

	if(( e->a == a and e->b == b ) or ( e->a == e->b ) )
		return e->max;
	if( b <= middle )
		return findMax( e->left ,a , b);
	if( a > middle )
		return findMax( e->right, a, b);
	maxl = findMax( e->left, a , middle );
	maxr = findMax( e->right, middle+1 , b );
	return max(maxl, maxr);
}


int main(){
	
	int n;
	int m;
	int start;
	int stop;
	int rodzaj;

	ios_base::sync_with_stdio( false );

	scanf( "%d %d",&n,&m);

	Element* tree = buildTree( nullptr, 0, n );

	FOR( i , 0 , m ){
		scanf( "%d %d %d",&rodzaj,&start,&stop);

		if( rodzaj == 1 ){
			actualize( tree, start, stop );
		}
		else{
			printf("%d\n" findMax( tree, start, stop ));
		}


	}


	return 0 ;
}
