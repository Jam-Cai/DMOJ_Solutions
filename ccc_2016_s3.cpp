/*
    James Cai
    CCC '16 S3 - Phonomenal Reviews
    C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M,root,far,len,cnt;
bool phoRest[100001];
vector<int> adj[100001];


void dfs1(int u, int par) {
    for(int v: adj[u]) {
        if(v==par) continue;
        dfs1(v,u); 
        phoRest[u] |= phoRest[v];
    }
}

void dfs2(int u, int par, int dis) {
    if(dis > len) {
        len = dis;
        far = u;
    }
    for(int v: adj[u]) {
        if(v == par || !phoRest[v]) continue;
        dfs2(v,u,dis+1);
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0,x; i < M; i++) {
        cin >> x;
        phoRest[x] = true;
        root = x;
    }   
    for(int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(root, -1); 
    dfs2(root, -1, 0);
    dfs2(far, -1, 0);
    for(int i = 0; i < N; i++) {
        cnt += phoRest[i];
    }
    cout << 2*(cnt-1) - len << endl;
}