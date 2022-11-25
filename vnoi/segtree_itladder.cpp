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
#define int ll
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct node{
    int val, lazyCnt, lazySum;
    node(){
        val = lazyCnt = lazySum = 0;
    }
} tree[MAXN];
int n, q;
void push(int id, int l, int r){
    int m = l + r >> 1;
    if(l <= m){
        (tree[id << 1].lazyCnt += tree[id].lazyCnt) %= MOD;
        (tree[id << 1].lazySum += tree[id].lazySum) %= MOD;
        (tree[id << 1].val += ((1ll * (l + m) * (m - l + 1) / 2 % MOD) * tree[id].lazyCnt)
            - 1ll * (m - l + 1) * tree[id].lazySum) %= MOD;
    }
    if(m + 1 <= r){
        (tree[id << 1 | 1].lazyCnt += tree[id].lazyCnt) %= MOD;
        (tree[id << 1 | 1].lazySum += tree[id].lazySum) %= MOD;
        (tree[id << 1 | 1].val += ((1ll * (m + 1 + r) * (r - m) / 2 % MOD) * tree[id].lazyCnt)
            - 1ll * (r - m) * tree[id].lazySum) %= MOD;
    }
    tree[id].lazyCnt = tree[id].lazySum = 0;
}
void update(int id, int l, int r, int u, int v, int a, int b){
    if(v < l || u > r)return ;
    if(u <= l && r <= v){
        (tree[id].lazyCnt += a) %= MOD;
        (tree[id].lazySum += a * u - b) %= MOD;
        (tree[id].val += ((1ll * (l + r) * (r - l + 1) / 2) % MOD) * a
            - 1ll * (r - l + 1) * ((a * u - b) % MOD)) %= MOD;
        // cout << l << " " << r << " " << tree[id].val << el;
        return ;
    }
    // i * a - (l * a - b)
    // 1 2 3 4 5
    push(id, l, r);
    int m = l + r >> 1;
    update(id << 1, l, m, u, v, a, b);
    update(id << 1 | 1, m + 1, r, u, v, a, b);
    tree[id].val = (tree[id << 1].val + tree[id << 1 | 1].val) % MOD;
    // cout << l << " " << r << " " << tree[id].val << el;

}
int get(int id, int l, int r, int u, int v){
    if(v < l || u > r)return 0;
    if(u <= l && r <= v){
        return tree[id].val;
    }
    push(id, l, r);
    int m = l + r >> 1;
    return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
}
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= q; i ++){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            update(1, 1, n, l, r, a, b);
        }else{
            int l, r;
            cin >> l >> r;
            cout << (get(1, 1, n, l, r) + MOD) % MOD<< el;
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
