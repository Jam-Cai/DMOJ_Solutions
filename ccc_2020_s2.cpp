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
using namespace std;
typedef long long ll;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int M, N;
vector<int> factors[1000005];
int grid[1005][1005];


void getFac(int num) {
    for(int i = 1; i * i <= num; i++) {
        if((num % i == 0 && i <= max(M, N)) && (num / i <= max(M, N))) {
            factors[num].push_back(i);
        }
    }
}

bool dfs(int x, int y) {
    if(x == M - 1 && y == N - 1) {
        return true;
    }
    if(x >= M || y >= N || !factors[grid[x][y]].empty()) {
        return false;
    }
    int num = grid[x][y];
    getFac(num);

    for(int i : factors[num]) {
        int x1 = i - 1, y1 = num / i - 1;
        if (dfs(x1, y1) || dfs(y1, x1)) {
            return true;
        }
    }
    return false;
}

int main() {
    scan(M); scan(N);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scan(grid[i][j]);
        }
    }

    bool ans = dfs(0, 0);
    if(ans == true){
        cout << "yes" << "\n";
    } else{
        cout << "no" << "\n";
    }
}