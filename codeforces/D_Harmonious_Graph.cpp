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

int n, m, res, par[MAXN], maxx[MAXN];

int root(int u){
    return par[u] < 0 ? u : par[u] = root(par[u]);
}
bool merger(int u, int v){
    if ((u = root(u)) == (v = root(v)))return false;
    if (par[u] < par[v])swap(u, v);
    maxx[u] = max(maxx[u], maxx[v]);
    par[u] += par[v];
    par[v] = u;
    return true;
}
void solve(){
    cin >> n >> m;

    fill(par + 1, par + n + 1, -1);
    iota(maxx + 1, maxx + n + 1, 1);

    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        merger(u, v);
    }

    // for (int i = 1; i <= n; i ++){
    //     cout << maxx[root(i)] << el;
    // }
    for (int i = 1; i <= n; i = maxx[root(i)] + 1){
        for (int j = i; j <= maxx[root(i)]; j ++){
            res += merger(i, j);
        }
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
