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

int n, q, a[MAXN], l[MAXN], r[MAXN];
unordered_map < int, int > nxtL, nxtR;
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        r[i] = max(r[i - 1], nxtR[a[i]]);
        nxtR[a[i]] = i;
    }

    l[n + 1] = n + 1;
    for (int i = n; i >= 1; i --){
        l[i] = min(l[i + 1], (nxtL[a[i]] == 0 ? n + 1 : nxtL[a[i]]));
        nxtL[a[i]] = i;
    }

    for (int i = 1; i <= q; i ++){
        int u, v; cin >> u >> v;
        if (l[u] > v)cout << v - u << el;
        else cout << max(l[u] - r[v], 0) << el;
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
