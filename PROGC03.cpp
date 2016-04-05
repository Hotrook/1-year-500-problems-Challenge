#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i = a ; i < b ; ++i )


using namespace std;

struct elemStack{
	elemStack* prev;
	elemStack* next;
	int value;
};

struct elemQueue{
	elemQueue* next;
	elemQueue* prev;
	int value;
};

class stack {

public:
	elemStack* root;
	elemStack* last;
	int size;	
	int numer;


	stack(int numer){
		last = nullptr;
		root = nullptr;
		size = 0 ; 
		this->numer = numer;
	}
	~stack(){
		while( root != nullptr ){
			elemStack *temp = root;
			root = root->prev;
			free(temp);
		}
		free(root);
	}

	void push( int elem ){
		if( this->size == 10 ){
			cout << "error: stack is full\n";
		}
		else if( this->size == 0 ){
			root = (elemStack*)malloc(sizeof(elemStack ));
			root->value = elem;
			root->prev = nullptr;
			root->next = nullptr;
			last = root;
			size++;
		}
		else{
			elemStack* temp = last;
			elemStack* toAdd = (elemStack*)malloc(sizeof(elemStack));
			toAdd->value = elem;
			toAdd->prev = last;
			toAdd->next = nullptr;
			temp->next = toAdd;
			last = toAdd;
			size++;
		}
	}

	void pop(){
		if( size > 0 ){
			elemStack* temp = last;
			if( last != nullptr ){
				temp = last->prev;
				size--;
				free(last);
				last = temp;
				if( last != nullptr )
				last -> next = nullptr;
			}
		}
		else{
			cout << "error: stack is empty\n";
		}
	}

	int top(){
		if( last != nullptr )
			return last->value;
		else
			return -1;
	}

	void print(){
		if( size != 0 ){
			elemStack* temp = root;
			while ( temp != nullptr ) { 
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		else{
			cout << "empty\n";
		}
	}

private: 


};

class queue { 
public: 



private:



};



int main(){
	
	int t;
	int numer;
	int i;
	int j;
	int e;
	int k; 
	vector<stack*> stacks;
	string command;
	int result;
	int sum = 0;
	char c;

	while( cin >> command ){
		if( command == "new_s"){
			cin >> numer;
			stack* temp = new stack(numer);
			stacks.push_back(temp);
		}
		else if( command == "push"){
			cin >> i >> e;
			for( auto& st : stacks ){
				if( st->numer == i ){
					st->push( e );
				}
			}
		}
		else if( command == "pop" ){
			cin >> i;
			for ( auto& st : stacks ){
				if ( st->numer == i ){
					st->pop();
				}
			}
		}
		else if( command == "stack->stack" ){
			cin >> i >> j;
			for( auto& st : stacks ){
				if (st->numer == i ){
					e = st->top();
					st->pop();
				}
			}
			for( auto& st : stacks ){
				if (st->numer == j ){
					if( e != -1 )
						st->push(e);
				}
			}
		}
		else if( command == "delete_s" ){
			cin >> j;
			// for ( auto& st : stacks ){
			// 	if ( st->numer == i ){
			// 		st->~stack();
			// 	}
			// }
			auto i = std::begin(stacks);

			while (i != std::end(stacks)) {
			    if( (*i)->numer == j){
			    	(*i)->~stack();
			        i = stacks.erase(i);
			    }
			    else
			        ++i;
			}

		}
		else if( command == "print_s" ){
			cin >> i; 
			for( auto& st : stacks ){
				if( st->numer == i ){
					st->print();
				}
			}
		}
	}




	return 0 ;
}