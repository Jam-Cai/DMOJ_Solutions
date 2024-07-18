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
ll table[1001][1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll D, I, R;
    string A, B;
    cin >> D >> I >> R;
    cin >> A >> B;
    ll lena = A.length(), lenb = B.length();

    for(ll i = 0; i <= lena; i++) {
        for(ll j = 0; j <= lenb; j++) {
            if (i == 0 && j == 0) {
                table[i][j] = 0;
            } else if (i == 0) {
                table[i][j] = j * I;
            } else if (j == 0) {
                table[i][j] = i * D;
            } else {
                    
                if (A[i - 1] == B[j - 1]) {
                    table[i][j] = table[i - 1][j - 1];
                } else {
                    table[i][j] = min(min(table[i - 1][j] + D, table[i][j - 1] + I), table[i - 1][j - 1] + R);
                }
            }
            // cout << table[i][j] << " ";
        }
        // cout << endl;
    }

    cout << table[lena][lenb];
}