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
using point = pair < ld, ld >;
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

const int d4x[4] = { 1, 0, -1, 0 };
const int d4y[4] = { 0, 1, 0, -1 };
const int d8x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int d8y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int n, q;
vector < int > adj[MAXN];

int h[MAXN], par[MAXN][20];
void dfs(int u) {
    for (int v : adj[u]) {
        if (v == par[u][0])continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        for (int i = 1; i < 20; i++) {
            par[v][i] = par[par[v][i - 1]][i - 1];
        }
        dfs(v);
    }
}
int lca(int u, int v) {
    if (h[u] < h[v])swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (bit(h[u] - h[v], i)) {
            u = par[u][i];
        }
    }
    if (u == v)return u;
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int rmq[MAXN][20];
int get(int u, int v) {
    int k = log2(v - u + 1);
    return lca(rmq[u][k], rmq[v - (1 << k) + 1][k]);
}
void init() {
    for (int i = 1; i <= n; i++) {
        rmq[i][0] = i;
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = lca(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(1);
    init();

    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        cout << get(u, v) << el;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int test = 1;
    // cin >> test;

    for (int i = 1; i <= test; i++) {
        solve();
    }

    return 0;
}
/*
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
