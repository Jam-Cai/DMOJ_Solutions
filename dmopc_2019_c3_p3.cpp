#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, psa[200005], fen[300010];
ll out = 0;

void update(int pos, int val) {
    pos+= N + 1;
    for(int i = pos; i <= 2 * N + 1; i += i & -i) fen[i]+=val;
}

ll query(int pos) {
    pos += N + 1;
    ll tot = 0;
    for(int i = pos; i > 0; i -= i & -i)
        tot += fen[i];
    return tot;

}

int main() {
    cin >> N;
    for(int i = 1,inp; i <= N; i++) {
        cin >> inp;
        psa[i] = psa[i-1] + (inp == 1 ? 1 : -1);
    }
    update(0,1);
    for(int i = 1; i <= N; i++) {
        out += query(psa[i] - 1);
        update(psa[i], 1);
    }
    cout << out << endl;
}