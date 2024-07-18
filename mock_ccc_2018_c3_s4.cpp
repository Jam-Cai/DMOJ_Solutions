#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstring>
#include <bitset>
#include <deque>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main() {
    cin.sync_with_stdio();
    cin.tie();
    ll N;
    ll maxB = 0,total = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        ll inp;
        cin >> inp;
        total+=inp;
        maxB = max(inp,maxB);
    }   
    if(maxB > total - maxB || total % 2 == 1){
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}