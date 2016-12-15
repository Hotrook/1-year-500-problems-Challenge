#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	
	int d;
	int x = 0;
	std::ios_base::sync_with_stdio (false);
	while(cin>>d){
		x ^= d;
	}
	cout << x << endl;

	return 0;
}
}