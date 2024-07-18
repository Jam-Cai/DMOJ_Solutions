#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> out;
    for(ll i = 0; i < n; i++) {
        ll mem = n-i-1;
        ll cur = min(k-mem,m);
        if(cur <= 0) break;
        ll val;
        if(cur > i) {
            val = min(m, i+1);
            cur=val;
        } else {
            val = out[i-cur];
        }
        out.push_back(val);
        k-=cur;
    }
    if(k == 0 && (ll)out.size() == n) {
        for(auto i: out) {
            cout << i << " ";
        }
        cout << "\n";
    }
    else cout << -1 << "\n";
}