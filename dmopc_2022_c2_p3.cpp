#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
const int MM = 5e5+5;
int N, a[MM], in[MM], last[MM]; 
vi adj[MM], primes[MM];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 2; i <= N; i++) {
        if(primes[i].empty()) {
            for(int j = i; j <= N; j+=i) primes[j].push_back(i);
        }
    }
    for(int i = 1,inp; i <= N; i++) {
        cin >> inp;
        for(int p: primes[inp]) {
            if(last[p] != 0) {
                adj[last[p]].push_back(inp); in[inp]++;
            }
            last[p] = inp;
        }
    }
    priority_queue<int> q; vi out;
    for(int i = 1; i <= N; i++) 
        if(in[i]==0) q.push(i);
    while(!q.empty()) {
        int node = q.top(); 
        q.pop(); out.push_back(node);
        for(int neigh: adj[node]) {
            if(--in[neigh] == 0) q.push(neigh);
        }
    }
    for(int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
}