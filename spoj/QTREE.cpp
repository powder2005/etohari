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
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, u[MAXN], v[MAXN], c[MAXN], tree[MAXN];
void update(int p, int val){
    for(tree[p += n] = val; p > 1; p >>= 1){
        tree[p >> 1] = max(tree[p], tree[p ^ 1]);
    }
}
int get(int l, int r){
    int ans = -INF;
    for(l += n, r += n; l <= r; l >>= 1, r >>= 1){
        if(l & 1)ans = max(ans, tree[l ++]);
        if((r & 1) ^ 1)ans = max(ans, tree[r --]);
    }
    return ans;
}

int t, pos[MAXN], nxt[MAXN], par[MAXN], maxPar[MAXN], heavy[MAXN], depth[MAXN];
vector < pii > adj[MAXN];

void initDfs(int u){
    heavy[u] = 1;
    for(auto &[v, c] : adj[u]){
        if(v == par[u])continue;
        par[v] = u;
        maxPar[v] = c;
        depth[v] = depth[u] + 1;
        initDfs(v);        
        heavy[u] += heavy[v];
        if(heavy[v] > heavy[adj[u][0].fi]){
            swap(v, adj[u][0].fi);
            swap(c, adj[u][0].se);
        }
    }
}
void dfs(int u){
    pos[u] = ++ t;
    for(auto [v, c] : adj[u]){
        if(v == par[u])continue;
        nxt[v] = (v == adj[u][0].fi ? nxt[u] : v);
        dfs(v);
    }
}
int query(int u, int v){
    int ans = -INF;
    while(nxt[u] != nxt[v]){
        if(depth[nxt[u]] < depth[nxt[v]]){
            swap(u, v);
        }
        ans = max(ans, get(pos[nxt[u]] + 1, pos[u]));
        ans = max(ans, maxPar[nxt[u]]);
        u = par[nxt[u]];
    }
    return max(ans, get(min(pos[u], pos[v]) + 1, max(pos[u], pos[v])));
}
void solve(){
    cin >> n;

    for(int i = 1; i <= n; i ++){
        adj[i].clear();
    }

    for(int i = 1; i < n; i ++){
        cin >> u[i] >> v[i] >> c[i];
        adj[u[i]].emplace_back(v[i], c[i]);
        adj[v[i]].emplace_back(u[i], c[i]);
    }
    
    t = 0;
    initDfs(1);
    dfs(1);

    for(int i = 1; i < n; i ++){
        if(par[u[i]] == v[i])swap(u[i], v[i]);
        update(pos[v[i]], c[i]);      
    }
   
    string type;
    while(cin >> type){
        if(type == "DONE")break;

        int x, y;
        cin >> x >> y;
        if(type == "QUERY"){
            cout << query(x, y) << el;
        }else {
            c[x] = y;
            maxPar[v[x]] = y;
            update(pos[v[x]], y);
        }
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    int test = 1;
    cin >> test;

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
