#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <bitset>
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <climits>
#include <math.h>  
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pii;
typedef vector<long long> vi;
typedef vector<vector<pair<long long,long long>>> vvpii;
typedef unordered_set<int> uset;
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int LIS(vi a) {
    int lena = a.size();
    vector<int> table(lena+1, INT_MAX);
    table[0] = INT_MIN;

    for (int i = 0; i < lena; i++) {
        int j = upper_bound(table.begin(), table.end(), a[i]) - table.begin();
        if (table[j-1] < a[i] && a[i] < table[j])
            table[j] = a[i];
    }

    int out = 0;
    for (int i = 0; i <= lena; i++) {
        if (table[i] < INT_MAX)
            out = i;
    }
    return out;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    scan(N);
    vi A(N);

    for(int i = 0; i < N; i++) {
        scan(A[i]);
    }
    
    cout << LIS(A);
}