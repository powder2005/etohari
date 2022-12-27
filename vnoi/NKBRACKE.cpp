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
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct node {
    int openL, closeR;
    node (int l = 0, int r = 0){
        openL = l;
        closeR = r;
    }
    node operator + (node p){
        node ans;
        ans.openL = openL - min(openL, p.closeR) + p.openL;
        ans.closeR = closeR - min(openL, p.closeR) + p.closeR;
        return ans;
    }
} tree[MAXN * 4];

int n, q;
string s;
void update(int id, int l, int r, int p){
    if (l == r){
        tree[id] = node(s[p] == '(', s[p] == ')');
        return ;
    }
    int m = l + r >> 1;
    if (p <= m)update(id << 1, l, m, p);
    else update(id << 1 | 1, m + 1, r, p);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
node get(int id, int l, int r, int u, int v){
    if (v < l || u > r)return node();
    if (u <= l && r <= v){
        return tree[id];
    }
    int m = l + r >> 1;
    return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
}
void solve(){
    cin >> n >> q >> s;

    s = '$' + s;    

    for (int i = 1; i <= n; i ++){
        update(1, 1, n, i);
    }

    for (int i = 1; i <= q; i ++){
        int type; cin >> type;
        if (type){
            int l, r; cin >> l >> r;
            node tmp = get(1, 1, n, l, r);
            cout << (tmp.openL == 0 && tmp.closeR == 0);
        }else {
            int id; cin >> id;
            char ch; cin >> ch;
            s[id] = ch;
            update(1, 1, n, id);
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
