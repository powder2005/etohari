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
#define int long long
const int MAXN = 5e5 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, res[MAXN];
vector < int > adj[MAXN];
vector < tuple < int, int, int, int > > query[MAXN];

int cnt, h[MAXN], inv[MAXN], out[MAXN];
void dfs(int u, int par = 0){
    inv[u] = ++ cnt;
    for (int v : adj[u]){
        if (v == par)continue;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
    out[u] = cnt + 1;
}

int fenwick[MAXN];
void update(int p, int val){
    for (int i = p; i <= n; i += (-i) & i){
        fenwick[i] += val;
    }
}
int get(int p){
    int ans = 0;
    for (int i = p; i > 0; i -= (-i) & i){
        ans += fenwick[i];
    }
    return ans;
}
void solve(){
    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(1);
    
    cin >> m;
    for (int i = 1; i <= m; i ++){
        int type; cin >> type;
        if (type == 1){
            int u, k, c; cin >> u >> k >> c;
            query[h[u] + k].emplace_back(type, u, c, i);
        }else{
            int u; cin >> u;
            query[h[u]].emplace_back(type, u, 0, i);
        }
    }

    fill(res + 1, res + m + 1, INF);
    for (int i = 0; i <= n; i ++){
        for(auto [type, u, c, id] : query[i]){
            if (type == 1){
                update(inv[u], c);
                update(out[u], -c);
            }else{
                res[id] = get(inv[u]);
            }
        }
        for(auto [type, u, c, id] : query[i]){
            if (type == 1){
                update(inv[u], -c);
                update(out[u], c); 
            }
        }
    }

    for (int i = 1; i <= m; i ++){
        if (res[i] != INF){
            cout << res[i] << el;
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
