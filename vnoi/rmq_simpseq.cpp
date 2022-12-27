#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;
using ordered_set = tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update >;

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

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, a[MAXN], l[MAXN], r[MAXN], rmq[20][MAXN];
unordered_map < int, int > nxt;

int get(int l, int r){
    int k = log2(r - l + 1);
    return __gcd(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}
int getL(int l, int r, int val){
     int ans = r, p = r;
     while (l <= r){
        int m = l + r >> 1;

        if (get(m, p) == val){
            ans = m;
            r = m - 1;
        }else {
            l = m + 1;
        }
     }
     return ans;
}
int getR(int l, int r, int val){
    int ans = l, p = l;
     while (l <= r){
        int m = l + r >> 1;
        if (get(p, m) == val){
            ans = m;
            l = m + 1;
        }else {
            r = m - 1;
        }
     }
     return ans;
}
void solve(){
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i ++){
        rmq[0][i] = a[i];
    }

    for (int j = 1; j < 20; j ++){
        for (int i = 1; i + (1 << j) - 1 <= n; i ++){
            rmq[j][i] = __gcd(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }

    for (int i = 1; i <= n; i ++){
        l[i] = nxt[a[i]];
        nxt[a[i]] = i;
    }

    nxt.clear();

    for (int i = n; i >= 1; i --){
        r[i] = nxt[a[i]] == 0 ? n + 1 : nxt[a[i]];
        nxt[a[i]] = i;
    }

    ll res = 0;
    for (int i = 1; i <= n; i ++){
        res += 1ll * (i - getL(l[i] + 1, i, a[i]) + 1) * (getR(i, r[i] - 1, a[i]) - i + 1) - 1;
    }

    cout << res;
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
