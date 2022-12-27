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
const int MAXN = 2e2 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e6;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, p, res, root, parent, c[MAXN], dp[MAXN][MAXN], nxt[MAXN][MAXN];
vector < int > adj[MAXN];

void dfs(int u, int par = 0){
    for (int i = 1; i <= p; i ++){
        dp[u][i] = -INF;
    }

    dp[u][1] = c[u];
    for (int v : adj[u]){
        if (v == par)continue;
        dfs(v, u);
        for (int i = p; i >= 1; i --){
            for (int j = 1; j < i; j ++){
                if(maximum(dp[u][i], dp[u][i - j] + dp[v][j])){
                    nxt[v][i] = j;   
                }
            }
        }
    }

    if(maximum(res, dp[u][p])){
        root = u;
        parent = par;
    }
}
void trace(int u, int par, int cnt){
    cout << u << " ";
    for (int i = len(adj[u]) - 1; i >= 0; i --){
        int v = adj[u][i];
        if (v == par)continue;
        if (nxt[v][cnt]){
            trace(v, u, nxt[v][cnt]);
            cnt -= nxt[v][cnt];
        }
    }
}
void solve(){
    cin >> n >> p;  
    for (int i = 1; i <= n; i ++){
        cin >> c[i];
    }

    for (int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    res = -INF;
    dfs(1);
    trace(root, parent, p);
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
