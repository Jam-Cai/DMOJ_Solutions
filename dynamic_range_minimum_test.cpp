#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
int n,m;
struct node { 
    int l,r;
    int Min;
} seg[300001];

void pushup(int num) {
    seg[num].Min = min(seg[2*num].Min,seg[2*num+1].Min);
}

void build(int num, int l, int r) {
    seg[num].l = l; seg[num].r = r;
    if(l==r){
        cin >> seg[num].Min;
        return;
    }
    int mid = (l+r)/2;
    build(2*num,l,mid);
    build(2*num+1,mid+1,r);
    pushup(num);
}

void update(int pos, int val, int num) {
    if(seg[num].l == pos && seg[num].r == pos) {
        seg[num].Min = val;
        return;
    }
    int mid = (seg[num].l+seg[num].r)/2;
    if(pos <= mid) update(pos,val,num*2);
    else update(pos,val,num*2+1);
    pushup(num);
}

int query(int l, int r, int num) {
    if(seg[num].l == l && seg[num].r == r) 
        return seg[num].Min;
    int mid = (seg[num].l+seg[num].r)/2;
    if(r <= mid) return query(l,r,2*num);
    if(l > mid) return query(l,r,num*2+1);
    return min(query(l,mid,2*num), query(mid+1,r,2*num+1));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    build(1,0,n-1);
    for(int i = 0; i < m; i++) {
        char a; int b,c;
        cin >> a >> b >> c;
        if(a=='Q') cout << query(b,c,1) << endl;
        else if(a=='M') update(b,c,1);
    }
}