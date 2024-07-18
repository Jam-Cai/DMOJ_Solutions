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
int graph[2010][2010];
int t,n,m,g;
int dist[2010];
bool tSet[2010];
int fb[2010];

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
    for(int i = 0; i<2001; i++) {
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
    //      <<((dist[k] != INT_MAX) ? dist[k] : -1) << endl;
    // }
}
int main() {
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scan(t); scan(n); scan(m); scan(g);
    n++;
    for(int i = 0; i < g; i++) {
        scan(fb[i]);
    }
    for(int i = 0; i < m; i++) {
        int x,y;
        scan(x); scan(y);
        scan(graph[x][y]);
    }
    dijkstra(0);
    int cnt = 0;
    for(int i = 0; i < g; i++) {
        if(dist[fb[i]] < t) {
            cnt++;
        }
    }
    cout << cnt << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << dist[i] << endl;
    // }

}