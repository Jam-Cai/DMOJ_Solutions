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
int lenN,lenM;
int table[1001][1001];
string N,M;

int recur(int a,int b) {
    if(a > lenN || b > lenM) return 1000000;
    if(a==lenN && b==lenM) return 0;
    if(N[a] == M[b]) return recur(a+1,b+1);
    if(table[a][b] >= 0) return table[a][b];
    int out = 1000000;
    out = min(out,recur(a+1,b+1) + 1);
    for (int i = 1; i <= 3; i++) {
        out = min(out,recur(a,b+i)+1);
        out = min(out,recur(a+i,b)+1);
    }
    table[a][b] = out;
    return table[a][b];
}

int main() {
    scan(lenN); scan(lenM);
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            table[i][j] = -1;
        }
    }
    cin >> N >> M;
    cout << recur(0,0);
}