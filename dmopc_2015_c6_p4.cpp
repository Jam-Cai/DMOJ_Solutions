#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstring>
#include <bitset>
#include <deque>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int,int> vii;
typedef vector<long long,long long> vll;
typedef unordered_set<int> uset;
int p[100001],r[100001];


int findU(int m) {
    if (p[m] != m){
         p[m] = findU(p[m]);
    }
    return p[m];
}

void link(int x, int y){
    if(r[x] > r[y]) {
        p[y] = x;
    }
    else{
        p[x] = y;
        if(r[x] == r[y]){
            r[x]++;
        }
    }
}

void un(int x, int y) {
    link(findU(x),findU(y));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        p[i] = i;
        r[i] = 0;
    }
    vector<vector<int>> graph;

    for(int i = 0; i < N - 1; i++) {
        int inp;
        cin >> inp;
        vector<int> input;
        input.push_back(inp); 
        input.push_back(i); 
        input.push_back(i+1); 
        graph.push_back(input);
    }
    for(int i = 0; i < N-K; i++) {
        vector<int> input;
        input.push_back(0); 
        input.push_back(i); 
        input.push_back(i+K); 
        graph.push_back(input);
    }
    sort(graph.begin(),graph.end());
    // for(auto i: graph) {
    //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
    // }
    int edges = 0,cnt = 0;
    for(auto i: graph) {
        if(cnt >= N - 1) break;
        if(findU(i[1]) != findU(i[2])) {
            un(i[1],i[2]);
            edges += i[0];
            cnt++;
            // cout << i[0] << " " << i[1] << " " << i[2] << endl;

        }
    }
    cout << edges;
}