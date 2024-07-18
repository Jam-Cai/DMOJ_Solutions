#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
vector<vector<ll>> f;

ll getScore(ll p) {
    ll ans = 0;
    for(auto i: f) {
        ll walk = abs(p-i[0])-i[2];
        if(walk > 0) {
            ans += walk * i[1];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll N,low = INT_MAX, high = 0;
    cin >> N;
    for(ll i = 0; i < N; i++) {
        vector<ll> inp(3);   
        cin >> inp[0] >> inp[1] >> inp[2];
        f.push_back(inp);
        low = min(inp[0],low);
        high = max(inp[0],high);
    }

    ll mid = 0, S = 0;
    while(low <= high) {
        mid = (low+high)/2;
        S = getScore(mid);
        ll left = getScore(mid-1);
        ll right = getScore(mid+1);
        if(S < right && S < left) {
            break;
        }
        if(S == right || S == left) {
            break;
        }
        if(S < right) {
            high = mid - 1;
        } 
        else if(S < left) {
            low = mid+1;
        }
    }
    cout << S;
}