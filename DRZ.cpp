#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )

using namespace std;


struct node{ 
	node* left;
	node* right; 
	node* parent; 
	int key; 
	int number;
	node(){
		number = 0 ;
		left = NULL;
		right = NULL;
		parent = NULL; 
	}
};

struct tree{ 
	node* root;
};

struct element{
	element* prev;
	node* that;
	element* next;
	element(){
		prev = NULL;
		next = NULL;
	}
};

struct list{
	element* first;
	element* last;
	list(){
		first = NULL;
		last = NULL;
	}
	void put(node* toPut ){
		if( first == NULL ){
			element* el= new element;
			el->that = toPut;
			first = el;
			last = el;
		}
		else{
			element* el = new element;
			el->that = toPut;
			el->prev = this->last;
			el->next = NULL;
			last->next = el;
			last = el;
		}

 	}
};

int result[10000];
string nawiasy = "";

void preOrder( node* start, int* counter ){
	if( (*counter) == 1 ){
		cout << "0 ";
		start->number = 1;
	}
	else{ 
		start->number = (*counter);
		cout << start->parent->number << " "; 
	}
	(*counter)++;
	nawiasy += "(";
	if( start->left  != NULL )
		preOrder( start->left, counter );
	if( start->right != NULL )
		preOrder( start->right, counter );
	nawiasy += ")";
}

int main(){
	
	int t;
	int n;
	int k, a, b;
	int size = 0;
	int counter;
	int max = 0;
	int numberOfMax = 0;
	list* list1 = new list;

	bool cond = true; 


	ios_base::sync_with_stdio(false);

	cin >> t;

	FOR( i , 0 , t ){
		node * temp = new node;
		cin >> temp->key;
		list1->put( temp );
	}

	element* temp = list1->first;
	while( temp != NULL ){
		size++;
		if( temp->that->key > max ){
			max = temp->that->key;
			numberOfMax = 1;
		}
		else if( temp->that->key == max ){
			numberOfMax++;
		}
		temp = temp->next;
	}


	if( numberOfMax % 2 != 0 ){
		cond = false;
	}

	if( size == 1 and max > 0){
		cond = false;
	}

	while( cond and size > 1 and max > 0 ){
		counter = 0;
		temp = list1->first;
		while( temp != NULL ){
			if( temp->next != NULL and temp->that->key == temp->next->that->key
				and temp->that->key == max ){
				counter += 2;

				node * x = new node ;
				x->left = temp->that;
				x->right = temp->next->that;
				x->left->parent = x;
				x->right->parent = x;
				x->key = max - 1;

				element* el = new element;
				el->that = x;
				el->prev = temp->prev;
				el->next = temp->next->next;

				if( temp->prev != NULL )
					temp->prev->next = el;
				if( temp->next->next != NULL )
					temp->next->next->prev = el;
				if( temp == list1->first )
					list1->first = el;
				
				delete temp;

				temp = el;
				size--;
			}
			else if ( temp->that-> key == max ){
				counter++;
			}
			temp = temp->next;
		}
		if ( counter %2 != 0 ){
			cond = false; 
		}
		max--;
	}

	if ( size > 1 ){
		cout << "NIE" << endl;
	}
	else if ( size == 1 and max > 0 ){
		cout << "NIE" << endl;
	}
	else{
		int counter = 1 ;
		preOrder( list1->first->that, &counter); 
		cout << endl;
		cout << nawiasy << endl;	
	}


	



	return 0 ;
}