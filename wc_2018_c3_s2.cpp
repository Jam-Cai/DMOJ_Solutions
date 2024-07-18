#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int N,K,F,len,far,cntG;
vi tree[100001];
bool G[100001];

void dfsG(int u, int par) {
    for(int v: tree[u]) {
        if(v==par) continue;
        dfsG(v,u); 
        G[u] |= G[v];
    }
}


void dfsD(int u, int par, int dis) {
    if(dis > len) {
        len = dis;
        far = u;
    }
    for(int v: tree[u]) {
        if(v == par || !G[v]) continue;
        dfsD(v,u,dis+1);
    }
}

int main() {
    scan(N); scan(K); scan(F);
    for(int i = 0,inp; i < K; i++) {
        scan(inp);
        G[inp] = true;
    }
    
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // cout << 1;
    dfsG(1,-1);
    dfsD(1, -1, 0);
    for(bool i: G) {
        cntG+=i;
    }
    int normalTime = len + (cntG-1-len) * 2;
    cntG=0;
    G[F] = true;
    dfsG(1,-1);
    for(bool i: G) {
        cntG+=i;
    }
    cout << min(cntG-1,normalTime) << "\n";
}