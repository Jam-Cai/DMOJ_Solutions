#include <iostream>
#include <climits>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<long long,long long> pii;
typedef vector<int> vi;
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int NJ,NL;
int J[1000001], L[1000001], table[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    scan(NJ);
    for(int i = 0; i < 1000001; i++) {
        L[i] = INT_MAX;
    }
    for(int i = 1; i <= NJ; i++) {
        scan(J[i]);
    }
    scan(NL);
    for(int i = 1,in; i <= NL; i++) {
        scan(in);
        L[in] = i;
    }
    int out = 0;
    for (int i = 1; i <= NJ; i++) {
        if(L[J[i]] == INT_MAX) continue;
        int j = lower_bound(table, table + out, L[J[i]]) - table;
        table[j] = L[J[i]];
        if(out==j) out++;
    }
    cout << out;
}