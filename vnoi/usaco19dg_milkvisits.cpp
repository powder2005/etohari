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
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, q, ans[MAXN], t[MAXN];
vector < int > adj[MAXN], color[MAXN];
vector < tuple < int, int, int > > query[MAXN];


int h[MAXN], par[MAXN][20], in[MAXN], out[MAXN], rmq[MAXN][20];
vector < int > eulerTour(1);
void dfs(int u){
    in[u] = len(eulerTour);
    eulerTour.emplace_back(u);
    for (int v : adj[u]){
        if (v == par[u][0]) continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        for (int i = 1; i < 20; i ++){
            par[v][i] = par[par[v][i - 1]][i - 1];
        }
        dfs(v);
    }
    out[u] = len(eulerTour);
}
int lca(int u, int v){
    if (h[u] < h[v])swap(u, v);
    for (int i = 19; i >= 0; i --){
        if (bit(h[u] - h[v], i)){
            u = par[u][i];
        }
    }
    if (u == v)return u;
    for (int i = 19; i >= 0; i --){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}


int fenwick[MAXN];
void update(int p, int val){
    for (; p <= n; p += (-p) & p){
        fenwick[p] += val;
    }
}
int get(int p){
    int ans = 0;
    for (; p > 0; p -= (-p) & p){
        ans += fenwick[p];
    }
    return ans;
}


void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> t[i];
        color[t[i]].emplace_back(i);
    }
    
    for (int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 1; i <= q; i ++){
        int u, v, c; cin >> u >> v >> c;
        query[c].emplace_back(u, v, i);
    }

    dfs(1);

    for (int c = 1; c <= n; c ++){
        for (auto id : color[c]){
            update(in[id], 1);
            update(out[id], -1);
        }
        for (auto [u, v, id] : query[c]){
            int p = lca(u, v);
            int cnt = get(in[u]) + get(in[v]) - 2 * get(in[p]) + (t[p] == c);
            // cerr << p << " " << u << " " << v << el;
            ans[id] = cnt > 0;
        } 
        for (auto id : color[c]){
            update(in[id], -1);
            update(out[id], 1);
        }  
    }

    for (int i = 1; i <= q; i ++){
        cout << ans[i];
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
