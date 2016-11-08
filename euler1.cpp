#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

uint64_t sum( uint64_t start, uint64_t stop ){
    return (( start + stop )*( stop/start ))/2;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        uint64_t first = sum( 3, ((n-1)/3) * 3 );
        uint64_t second = sum( 5, ((n-1)/5) * 5 );
        uint64_t common = sum( 15, ((n-1)/15) * 15 );
        
        cout << (first+second) - common << endl;
         
    }
    return 0;
}
