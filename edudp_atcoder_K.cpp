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

int N, K;
int A[101];
int dp[100010];
int recur(int n) {
    if (n == 0) return 0;
    if (dp[n] > -1) return dp[n];
    int sq = 0;
    for (int i = 0; i < N; i++) {
        if (n >= A[i]){
            sq |= (recur(n - A[i]) ^ 1);
        }
    }
    return dp[n] = sq;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i <= K; i++){
        dp[i] = -1;
    }
    cout << (recur(K) ? "First" : "Second");
}