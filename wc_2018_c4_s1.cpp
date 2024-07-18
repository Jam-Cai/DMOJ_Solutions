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

    int N,M,K;
    string plt;

    cin >> N >> M >> K >> plt;
    for(int i = 0; i < 100001; i++) {
        p[i] = i;
        r[i] = 0;
    }
    for(int i = 0; i < M; i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;

        if(plt[A] == plt[B]) {
            // cout << A << " ~ " << B << "\n";
            un(A,B);
        }
    }
    int cnt = 0;
    for(int i = 0; i < K; i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if(findU(x) == findU(y)) cnt++;
    }
    cout << cnt;
}