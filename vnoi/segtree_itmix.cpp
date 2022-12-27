#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define NAME "ETOHARI"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct node {
    ll valueSum, lazyAdd, lazyAssign, lazyVolume;
    node (ll a = 0, ll b = 0, ll c = 0, ll d = 1) : 
        valueSum(a), lazyAdd(b), lazyAssign(c), lazyVolume(d) {};
} tree[MAXN];

int n, q, a[MAXN];

void updatePush(int id, int l, int r, int a, int b, int c){
    
   
}
void push(int id, int l, int r){
    int m = l + r >> 1;
    if(l <= m){
        updatePush(id << 1, l, m, tree[id].lazyAssign, tree[id].lazyAdd, tree[id].lazyVolume);
    }
    if(m + 1 <= r){
        updatePush(id << 1 | 1, m + 1, r, tree[id].lazyAssign, tree[id].lazyAdd, tree[id].lazyVolume);
    }
    tree[id].lazyAdd = tree[id].lazyAssign = 0;
    tree[id].lazyVolume = 1;
}
void update(int id, int l, int r, int u, int v, int a, int b, int c){
    if(v < l || u > r)return ;
    if(u <= l && r <= v){
        updatePush(id, l, r, a, b, c);
        return ;
    }
    push(id, l, r);
    int m = l + r >> 1;
    update(id << 1, l, m, u, v, a, b, c);
    update(id << 1 | 1, m + 1, r, u, v, a, b, c);
    tree[id].valueSum = tree[id << 1].valueSum + tree[id << 1 | 1].valueSum;
    tree[id].valueSum %= MOD;
}
ll get(int id, int l, int r, int u, int v){
    if(v < l || u > r)return 0ll;
    if(u <= l && r <= v)return tree[id].valueSum;
    push(id, l, r);
    int m = l + r >> 1;
    return (get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v)) % MOD;
}
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        update(1, 1, n, i, i, a[i], 0, 1);
    }

    for(int i = 1; i <= q; i ++){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, b;
            cin >> l >> r >> b;
            update(1, 1, n, l, r, 0, b, 1);
        }else if(type == 2){
            int l, r, c;
            cin >> l >> r >> c;
            update(1, 1, n, l, r, 0, 0, c);
        }else if(type == 3){
            int l, r, a;
            cin >> l >> r >> a;
            update(1, 1, n, l, r, a, 0, 1);
        }else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) % MOD << el;
        }
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    int test = 1;
    // cin >> test;

    for(int i = 1; i <= test; i ++){
        solve();
    }
    
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */

// (a[i] = x + y) * z 
// (a[i] = (x ? x : a[i]) + y) * z