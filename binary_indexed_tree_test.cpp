#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//Lowest Single Bit
#define LSB(i) ((i) & -(i))
struct FT
{
    std::vector<ll> data;
    FT(ll size)
    {
        data.resize(size+1);
    }
    void insert(ll idx, ll value)
    {
        while(idx < data.size())
        {
            data[idx] += value;
            idx += LSB(idx);
        }
    }
    ll rsq(ll from, ll to)
    {
        return getSum(to) - getSum(from-1);
    }
    ll getSum(ll elem)
    {
        ll value = 0;
        while(elem != 0)
        {
            value += data[elem];
            elem = elem & (elem - 1);
        }
        return value;
    }
    ll accessSingle(ll idx) 
    {
        ll sum = data[idx];
        if(idx > 0) 
        {
            ll z = idx - (idx & -idx);
            idx--; 
            while (idx != z) 
            { 
                sum -= data[idx];
                idx -= (idx & -idx);
            }
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    ll inp[n];
    struct FT tree(n);
    struct FT freq(100001);
    for(ll i = 0; i < n; i++) {
        cin >> inp[i];
        tree.insert(i+1,inp[i]);
        freq.insert(inp[i], 1);
    }
    // for(ll i = 0; i < n; i++) {
    //     cout << freq.accessSingle(i+1) << " ";
    // }
    // cout << endl;

    for(ll i = 0; i < m; i++) {
        char a; ll b,c;
        cin >> a;
        if(a == 'C') {
            cin >> b >> c;
            freq.insert(c,1);
            freq.insert(tree.accessSingle(b), -1);
            tree.insert(b, c - tree.accessSingle(b));
        } else if(a == 'S') {
            cin >> b >> c;
            cout << tree.rsq(b,c) << endl;
        } else if(a == 'Q') {
            cin >> b;
            cout << freq.getSum(b) << endl;
        }
        
    }


}