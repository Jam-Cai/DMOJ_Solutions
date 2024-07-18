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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<pair<int,int>>> vvpii;
typedef unordered_set<int> uset;
#define pb push_back
int N,M;
pii S;
char grid[101][101];
int valid[101][101];
int dmax[101][101];


void CC(int x, int y){
    for(int i = x; i >= 0; i--) {
        if(grid[i][y] == 'W') break;
        if(grid[i][y] == '.' || grid[i][y] == 'S') valid[i][y] = 1;
    }
    for(int i = x; i < N; i++) {
        if(grid[i][y] == 'W') break;
        if(grid[i][y] == '.'  || grid[i][y] == 'S') valid[i][y] = 1;
    }
    for(int i = y; i >= 0; i--) {
        if(grid[x][i] == 'W') break;
        if(grid[x][i] == '.' || grid[x][i] == 'S') valid[x][i] = 1;
    }
    for(int i = y; i < M; i++) {
        if(grid[x][i] == 'W') break;
        if(grid[x][i] == '.' || grid[x][i] == 'S') valid[x][i] = 1;

    }
}
void bfs(int x,int y) {
    if(valid[x][y] == 1) return;
    deque<pair<pii,int>> q;
    q.push_back(make_pair(make_pair(x,y),0));
    set<pii> v;
    while(!q.empty()) {
        pair<pii,int> node = q.front();
        q.pop_front();
        int x1 = node.first.first, y1 = node.first.second;
        int dist = node.second;
        dmax[x1][y1] = min(dmax[x1][y1], dist);
        if(v.find(node.first) == v.end()) {
            // cout << x1 << " " << y1 << endl;
            v.insert(node.first);
            if(grid[x1][y1] == '.' || grid[x1][y1] == 'S'){
                if(valid[x1-1][y1] == 0) {
                    q.push_back(make_pair(make_pair(x1-1,y1),dist+1));
                }
                if(valid[x1][y1-1] == 0) {
                    q.push_back(make_pair(make_pair(x1,y1-1),dist+1));
                }
                if(valid[x1][y1+1] == 0) {
                    q.push_back(make_pair(make_pair(x1,y1+1),dist+1));
                }
                if(valid[x1+1][y1] == 0) {
                    q.push_back(make_pair(make_pair(x1+1,y1),dist+1));
                }
            } else if(grid[x1][y1] == 'L'&& valid[x1][y1-1] == 0){
                q.push_front(make_pair(make_pair(x1,y1-1),dist));    
            } else if(grid[x1][y1] == 'R'&& valid[x1][y1+1] == 0) {
                q.push_front(make_pair(make_pair(x1,y1+1),dist));    
            } else if(grid[x1][y1] == 'D'&& valid[x1+1][y1] == 0) {
                q.push_front(make_pair(make_pair(x1+1,y1),dist));    
            } else if(grid[x1][y1] == 'U'&& valid[x1-1][y1] == 0) {
                q.push_front(make_pair(make_pair(x1-1,y1),dist));    
            }
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dmax[i][j] = INT_MAX;
            cin >> grid[i][j];
            if(grid[i][j] == 'W') valid[i][j] = 1;
            else if(grid[i][j] == 'S') S = make_pair(i,j);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(grid[i][j] == 'C') {
                CC(i,j);
                valid[i][j] = 1;
            }
            
        }
    }
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << valid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bfs(S.first,S.second);
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << dmax[i][j] << " ";

    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(grid[i][j] == '.') cout << ((dmax[i][j] != INT_MAX) ? dmax[i][j] : -1) << endl;
        }
    }
}