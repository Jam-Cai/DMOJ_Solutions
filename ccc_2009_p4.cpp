#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstring>
#include <bitset>
#include <deque>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int,int> vii;
typedef vector<long long,long long> vll;
typedef unordered_set<int> uset;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int graph[5001][5001];
int n,t,k,d;
int dist[5001];
bool tSet[5001];

int minDistance(int dist[], bool tSet[]) {
    int mini = INT_MAX, idx;
    for(int i = 0; i < n; i++) {
        if(tSet[i] == false && dist[i] <= mini) {
            mini = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int idx) {
    for(int i = 0; i<5001; i++) {
        dist[i] = INT_MAX;
        tSet[i] = false;    
    }
    dist[idx] = 0;
    for(int i = 0; i < n-1; i++) {
        int mini = minDistance(dist, tSet);
        tSet[mini] = true;
        for(int j = 0; j < n; j++) {
            if(!tSet[j] && graph[mini][j] && dist[mini]!=INT_MAX && dist[mini]+graph[mini][j]<dist[j]) {
                dist[j]=dist[mini]+graph[mini][j];
            }
        }
    }
    // for(int k = 0; k<n+1; k++)                      
    // { 
    //     cout<<((dist[k] != INT_MAX) ? dist[k] : -1) << endl;
    // }
}
int main() {
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scan(n); scan(t);
    for(int i = 0; i < t; i++) {
        int x,y;
        scan(x); scan(y);
        x--; y--;
        scan(graph[x][y]);
        graph[y][x] = graph[x][y];
    }
    scan(k);

    pii pencil[k];
    for(int i = 0; i < k; i++) {
        int a,b;
        cin >> a >> b;
        pencil[i] = make_pair(a,b);
    }
    scan(d);
    dijkstra(d-1);
    int minp = INT_MAX;
    for(int i = 0; i < k; i++) {
        int a = pencil[i].first, b = pencil[i].second;
        a--;
        dist[a]+=b;
        minp = ((dist[a] > 0) ? min(minp, dist[a]) : minp);
    }
    cout << minp;




}