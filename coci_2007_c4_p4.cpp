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
typedef vector<int> vi;
typedef vector<vector<pair<long long,long long>>> vvpii;
typedef unordered_set<int> uset;
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int P[1000];
int total[1000];
int table[501][5001];
int T,N;

void recur2() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= T; j++) {
            table[i][j] = table[i-1][j];
            if(j >= P[i-1]) table[i][j] = max(table[i-1][j], table[i-1][j - P[i-1]] + P[i-1]);
        }
    }
}

vi reconstruct(int i, int w) {
    if(i == 0) {
        return {};
    }
    if(table[i][w] > table[i-1][w]) {
        vi ve = reconstruct(i-1, w - P[i-1]);
        ve.push_back(i);
        return ve;
    } else {
        return reconstruct(i-1, w);
    }
}

int main() {
    scan(T); scan(N);
    for(int i = 0; i < N; i++) {
        scan(P[i]);
    }
    recur2();
    int cnt = 0;
    set<int> s;
    for(int i: reconstruct(N,T)) {
        total[i-1] = cnt;
        cnt+=P[i-1];
        s.insert(i);
        // cout << i << endl;

    }
    // for(int i = 0; i <= N; i++) {
    //     for(int  j = 0; j <= T; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cnt = 0;
    for(int i = 0; i < N; i++) {
        if(s.find(i+1) == s.end()){
            cout << cnt << " ";
            cnt+=P[i];
            continue;
        }
        cout << total[i] << " ";
    }

}