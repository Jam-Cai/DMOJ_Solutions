
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;

int T;

bool out(int m, int x, int y) {
    int xm = (int)(x / pow(5, m - 1));
    int ym = (int)(y / pow(5,m-1));
    if(!xm && !ym) return false;
    if(xm > 0 && xm < 4 && ym == 0) return true;
    if(xm == 2 && ym == 1) return true;
    if (((xm ==1 || xm == 3) && ym == 1) || (xm == 2 && ym == 2))
        return out(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    int m,x,y;
    for(int i = 0; i < T; i++) {
        cin >> m >> x >> y;
        if(out(m,x,y)) cout << "crystal" << endl;
        else cout << "empty" << endl;
    }
}