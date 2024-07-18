#include<bits/stdc++.h>
using namespace std;
#define LSB(i) ((i) & -(i))
typedef long long ll;


struct FT {
    std::vector<ll> data;
    FT(ll size) {
        data.resize(size+1);
    }
    void insert(ll idx, ll value) {
        while(idx < data.size()) {
            data[idx] += value;
            idx += LSB(idx);
        }
    }
    ll rsq(ll from, ll to) {
        return getSum(to) - getSum(from-1);
    }
    ll getSum(ll elem) {
        ll value = 0;
        while(elem != 0) {
            value += data[elem];
            elem = elem & (elem - 1);
        }
        return value;
    }
    ll accessSingle(ll idx) {
        ll sum = data[idx];
        if(idx > 0) {
            ll z = idx - (idx & -idx);
            idx--; 
            while (idx != z) { 
                sum -= data[idx];
                idx -= (idx & -idx);
            }
        }
        return sum;
    }
};
int old[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    struct FT flowers(100001);
    for(int i = 0; i < n; i++) {
        int l,r;
        cin >> l >> r;
        int vl = flowers.getSum(l), vr = flowers.getSum(r);
        cout << (vl + vr - old[l] - old[r]) << "\n";
        old[l] = vl;  old[r] = vr;
        flowers.insert(l+1, 1); flowers.insert(r, -1);
    }

}