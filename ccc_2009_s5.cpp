#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
int M,N,K;
int ch[30001][1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> K;
    for(int i = 0,x,y,R,B; i < K; i++) {
        cin >> y >> x >> R >> B;
        for(int ry = max(1,x-R); ry <= min(M,x+R); ry++) {
            double a1 = y - sqrt(R*R - (ry-x)*(ry-x));
            double b1 = y + sqrt(R*R - (ry-x)*(ry-x));
            int a2 = max(1, (int)ceil(a1));
            int b2 = min(N, (int)floor(b1));
            ch[ry][a2] += B;
            ch[ry][b2+1] -= B;
        }
    }
    int bigwifi = -1, cnt = 0;
    for(int i = 1; i <= M; i++) {
        int total = 0;
        for(int j = 1; j <= N; j++) {
            total += ch[i][j];
            if(total == bigwifi) {
                cnt ++;
            } else if(total > bigwifi) {
                bigwifi = total;
                cnt = 1;
            }
        }
    }
    cout << bigwifi << endl << cnt << endl;
}