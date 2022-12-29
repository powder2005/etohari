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
#define s fi
#define m se
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, q;
pii tree[MAXN * 4];

void update(int id, int l, int r, int p, int val){
    if (l == r){
        tree[id].s = val;
        tree[id].m = val;
        return;
    }
    int m = l + r >> 1;
    update(id << 1, l, m, p, val);
    update(id << 1 | 1, m + 1, r, p, val);
    tree[id].s = tree[id << 1].s + tree[id << 1 | 1].s;
    tree[id].m = min(tree[id << 1].m, tree[id << 1 | 1].m);
}
int getIndex(int id, int l, int r, int val){
    if (l == r)return l;
    int m = l + r >> 1;
}
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        int a; cin >> a;
        update(1, 1, n, i, a);
    }

    for (int i = 1; i <= q; i ++){
        int type; cin >> type;
        if (type == 1){

        }else if (type == 2){

        }else if (type == 3){

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

 (n - a - b, a, b)
 dp[i] là giá trị lớn nhất nếu xếp 
                        */
