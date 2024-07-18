#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <bitset>
#include <deque>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pii;
typedef vector<long long> vi;
typedef vector<vector<pair<long long,long long>>> vvpii;
typedef unordered_set<int> uset;
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int arr[2000001],up=1, d=1;

int main() {
    int N;
    scan(N);
    scan(arr[0]);
    for(int i = 1; i < N; i++) {
        scan(arr[i]);
        if(arr[i] > arr[i-1]){
            up=max(up,d+1);
        }
        if(arr[i] < arr[i-1]){
            d=max(up+1,d);
        }
    }
    cout << max(up,d);


}